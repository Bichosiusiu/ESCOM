from antlr4 import *
if "." in __name__:
    from .ExamenParser import ExamenParser
else:
    from ExamenParser import ExamenParser
class ExamenVisitor(ParseTreeVisitor):
    def __init__(self):
        self.valid_expression = True
        self.error_messages = []
        self.syntax_error = False  
    def visit_with_error_handling(self, visit_func, *args):
        try:
            return visit_func(*args)
        except Exception as e:
            self.valid_expression = False
            self.error_messages.append(f"Error en la evaluación de la expresión: {str(e)}")
            return None 
    def syntaxError(self, recognizer, offendingSymbol, line, column, msg, e):
        self.syntax_error = True
        self.error_messages.append(f"Error de sintaxis en la línea {line}:{column} - {msg}")
        self.valid_expression = False  
    def visitProg(self, ctx: ExamenParser.ProgContext):
        if self.syntax_error:  
            return None
        results = []
        for expr in ctx.expr():
            result = self.visit_with_error_handling(self.visit, expr)
            results.append(result)
        return results
    def visitPAR(self, ctx: ExamenParser.PARContext):
        return self.visit_with_error_handling(self.visit, ctx.expr())
    def visitNEG(self, ctx: ExamenParser.NEGContext):
        return -self.visit_with_error_handling(self.visit, ctx.expr())
    def visitNEGATOM(self, ctx: ExamenParser.NEGATOMContext):
        return -self.visit_with_error_handling(self.visit, ctx.atom())
    def visitNEGPAR(self, ctx: ExamenParser.NEGPARContext):
        return -self.visit_with_error_handling(self.visit, ctx.expr())
    def visitSUMRES(self, ctx: ExamenParser.SUMRESContext):
        left = self.visit_with_error_handling(self.visit, ctx.expr(0))
        right = self.visit_with_error_handling(self.visit, ctx.expr(1))
        operator = ctx.getChild(1).getText()
        if operator == '+':
            return left + right
        else:  
            return left - right
    def visitOR(self, ctx: ExamenParser.ORContext):
        left = self.visit_with_error_handling(self.visit, ctx.expr(0))
        right = self.visit_with_error_handling(self.visit, ctx.expr(1))
        return left or right
    def visitPOT(self, ctx: ExamenParser.POTContext):
        left = self.visit_with_error_handling(self.visit, ctx.expr(0))
        right = self.visit_with_error_handling(self.visit, ctx.expr(1))
        return left ** right
    def visitAND(self, ctx: ExamenParser.ANDContext):
        left = self.visit_with_error_handling(self.visit, ctx.expr(0))
        right = self.visit_with_error_handling(self.visit, ctx.expr(1))
        return left and right
    def visitMULDIV(self, ctx: ExamenParser.MULDIVContext):
        left = self.visit_with_error_handling(self.visit, ctx.expr(0))
        right = self.visit_with_error_handling(self.visit, ctx.expr(1))
        operator = ctx.getChild(1).getText()
        try:
            if operator == '*':
                return left * right
            elif operator == '/':
                if right == 0:
                    raise ZeroDivisionError("División por cero!")
                return left / right
        except ZeroDivisionError as e:
            print(f"Error: {e}")
            return None
    def visitATOM(self, ctx: ExamenParser.ATOMContext):
        return self.visitChildren(ctx)
    def visitVAR(self, ctx: ExamenParser.VARContext):
        self.valid_expression = False
        return 0
    def visitNUM(self, ctx: ExamenParser.NUMContext):
        return float(ctx.getText())
    def is_valid_expression(self):
        return self.valid_expression and not self.syntax_error 
del ExamenParser