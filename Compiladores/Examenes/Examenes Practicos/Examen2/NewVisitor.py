from Expr3Parser import Expr3Parser
from Expr3Visitor import Expr3Visitor

class MyExpr3Visitor(Expr3Visitor):
    def __init__(self):
        self.memory = {}  

    def visitAssign(self, ctx: Expr3Parser.AssignContext):
        name = ctx.NAME().getText()
        value = self.visit(ctx.expr())
        self.memory[name] = value
        print(f"{name} = {value}")
        return value

    def visitWrite(self, ctx: Expr3Parser.WriteContext):
        name = ctx.NAME().getText()
        value = self.memory.get(name, 0)
        print(f"{name} = {value}")
        return value

    def visitIncrement(self, ctx: Expr3Parser.IncrementContext):
        name = ctx.NAME().getText()
        self.memory[name] = self.memory.get(name, 0) + 1
        return self.memory[name]

    def visitDecrement(self, ctx: Expr3Parser.DecrementContext):
        name = ctx.NAME().getText()
        self.memory[name] = self.memory.get(name, 0) - 1
        return self.memory[name]

    def visitPower(self, ctx: Expr3Parser.PowerContext):
        left = self.visit(ctx.expr(0))
        right = self.visit(ctx.expr(1))
        return left ** right

    def visitMulDiv(self, ctx: Expr3Parser.MulDivContext):
        left = self.visit(ctx.expr(0))
        right = self.visit(ctx.expr(1))
        if ctx.getChild(1).getText() == '*':
            return left * right
        elif ctx.getChild(1).getText() == '/':
            if right == 0:
                print("Error: División entre cero")
                return float('inf')  
            return left / right
            

    def visitAddSub(self, ctx: Expr3Parser.AddSubContext):
        left = self.visit(ctx.expr(0))
        right = self.visit(ctx.expr(1))
        if ctx.getChild(1).getText() == '+':
            return left + right
        else:
            return left - right

    def visitNumber(self, ctx: Expr3Parser.NumberContext):
        return float(ctx.NUM().getText())

    def visitVariable(self, ctx: Expr3Parser.VariableContext):
        name = ctx.NAME().getText()
        return self.memory.get(name, 0)
