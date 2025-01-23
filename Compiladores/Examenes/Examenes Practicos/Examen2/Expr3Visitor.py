# Generated from Expr3.g4 by ANTLR 4.13.2
from antlr4 import *
if "." in __name__:
    from .Expr3Parser import Expr3Parser
else:
    from Expr3Parser import Expr3Parser

# This class defines a complete generic visitor for a parse tree produced by Expr3Parser.

class Expr3Visitor(ParseTreeVisitor):

    # Visit a parse tree produced by Expr3Parser#root.
    def visitRoot(self, ctx:Expr3Parser.RootContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by Expr3Parser#Assign.
    def visitAssign(self, ctx:Expr3Parser.AssignContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by Expr3Parser#Write.
    def visitWrite(self, ctx:Expr3Parser.WriteContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by Expr3Parser#Increment.
    def visitIncrement(self, ctx:Expr3Parser.IncrementContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by Expr3Parser#Decrement.
    def visitDecrement(self, ctx:Expr3Parser.DecrementContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by Expr3Parser#Variable.
    def visitVariable(self, ctx:Expr3Parser.VariableContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by Expr3Parser#Number.
    def visitNumber(self, ctx:Expr3Parser.NumberContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by Expr3Parser#MulDiv.
    def visitMulDiv(self, ctx:Expr3Parser.MulDivContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by Expr3Parser#AddSub.
    def visitAddSub(self, ctx:Expr3Parser.AddSubContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by Expr3Parser#Power.
    def visitPower(self, ctx:Expr3Parser.PowerContext):
        return self.visitChildren(ctx)



del Expr3Parser