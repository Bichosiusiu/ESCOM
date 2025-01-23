# Generated from Expr3.g4 by ANTLR 4.13.2
from antlr4 import *
if "." in __name__:
    from .Expr3Parser import Expr3Parser
else:
    from Expr3Parser import Expr3Parser

# This class defines a complete listener for a parse tree produced by Expr3Parser.
class Expr3Listener(ParseTreeListener):

    # Enter a parse tree produced by Expr3Parser#root.
    def enterRoot(self, ctx:Expr3Parser.RootContext):
        pass

    # Exit a parse tree produced by Expr3Parser#root.
    def exitRoot(self, ctx:Expr3Parser.RootContext):
        pass


    # Enter a parse tree produced by Expr3Parser#Assign.
    def enterAssign(self, ctx:Expr3Parser.AssignContext):
        pass

    # Exit a parse tree produced by Expr3Parser#Assign.
    def exitAssign(self, ctx:Expr3Parser.AssignContext):
        pass


    # Enter a parse tree produced by Expr3Parser#Write.
    def enterWrite(self, ctx:Expr3Parser.WriteContext):
        pass

    # Exit a parse tree produced by Expr3Parser#Write.
    def exitWrite(self, ctx:Expr3Parser.WriteContext):
        pass


    # Enter a parse tree produced by Expr3Parser#Increment.
    def enterIncrement(self, ctx:Expr3Parser.IncrementContext):
        pass

    # Exit a parse tree produced by Expr3Parser#Increment.
    def exitIncrement(self, ctx:Expr3Parser.IncrementContext):
        pass


    # Enter a parse tree produced by Expr3Parser#Decrement.
    def enterDecrement(self, ctx:Expr3Parser.DecrementContext):
        pass

    # Exit a parse tree produced by Expr3Parser#Decrement.
    def exitDecrement(self, ctx:Expr3Parser.DecrementContext):
        pass


    # Enter a parse tree produced by Expr3Parser#Variable.
    def enterVariable(self, ctx:Expr3Parser.VariableContext):
        pass

    # Exit a parse tree produced by Expr3Parser#Variable.
    def exitVariable(self, ctx:Expr3Parser.VariableContext):
        pass


    # Enter a parse tree produced by Expr3Parser#Number.
    def enterNumber(self, ctx:Expr3Parser.NumberContext):
        pass

    # Exit a parse tree produced by Expr3Parser#Number.
    def exitNumber(self, ctx:Expr3Parser.NumberContext):
        pass


    # Enter a parse tree produced by Expr3Parser#MulDiv.
    def enterMulDiv(self, ctx:Expr3Parser.MulDivContext):
        pass

    # Exit a parse tree produced by Expr3Parser#MulDiv.
    def exitMulDiv(self, ctx:Expr3Parser.MulDivContext):
        pass


    # Enter a parse tree produced by Expr3Parser#AddSub.
    def enterAddSub(self, ctx:Expr3Parser.AddSubContext):
        pass

    # Exit a parse tree produced by Expr3Parser#AddSub.
    def exitAddSub(self, ctx:Expr3Parser.AddSubContext):
        pass


    # Enter a parse tree produced by Expr3Parser#Power.
    def enterPower(self, ctx:Expr3Parser.PowerContext):
        pass

    # Exit a parse tree produced by Expr3Parser#Power.
    def exitPower(self, ctx:Expr3Parser.PowerContext):
        pass



del Expr3Parser