from aritVisitor import aritVisitor
class EvalVisitor(aritVisitor):
    def visitMulDivMod(self, ctx):
        left = self.visit(ctx.expr(0))
        right = self.visit(ctx.expr(1))
        if ctx.op.text == '*':
            return left * right
        elif ctx.op.text == '/':
            if right == 0:
                raise ZeroDivisionError("Division by zero")
            return left / right
        elif ctx.op.text == '%':
            return left % right
    def visitAddSub(self, ctx):
        left = self.visit(ctx.expr(0))
        right = self.visit(ctx.expr(1))
        if ctx.op.text == '+':
            return left + right
        elif ctx.op.text == '-':
            return left - right
    def visitInt(self, ctx):
        return int(ctx.INT().getText())
    def visitFloat(self, ctx):
        return float(ctx.FLOAT().getText())
    def visitParenthesis(self, ctx):
        return self.visit(ctx.expr())
