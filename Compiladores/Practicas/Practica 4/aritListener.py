# Generated from arit.g4 by ANTLR 4.13.2
from antlr4 import *
if "." in __name__:
    from .aritParser import aritParser
else:
    from aritParser import aritParser

# This class defines a complete listener for a parse tree produced by aritParser.
class aritListener(ParseTreeListener):

    # Enter a parse tree produced by aritParser#Float.
    def enterFloat(self, ctx:aritParser.FloatContext):
        pass

    # Exit a parse tree produced by aritParser#Float.
    def exitFloat(self, ctx:aritParser.FloatContext):
        pass


    # Enter a parse tree produced by aritParser#Parenthesis.
    def enterParenthesis(self, ctx:aritParser.ParenthesisContext):
        pass

    # Exit a parse tree produced by aritParser#Parenthesis.
    def exitParenthesis(self, ctx:aritParser.ParenthesisContext):
        pass


    # Enter a parse tree produced by aritParser#MulDivMod.
    def enterMulDivMod(self, ctx:aritParser.MulDivModContext):
        pass

    # Exit a parse tree produced by aritParser#MulDivMod.
    def exitMulDivMod(self, ctx:aritParser.MulDivModContext):
        pass


    # Enter a parse tree produced by aritParser#AddSub.
    def enterAddSub(self, ctx:aritParser.AddSubContext):
        pass

    # Exit a parse tree produced by aritParser#AddSub.
    def exitAddSub(self, ctx:aritParser.AddSubContext):
        pass


    # Enter a parse tree produced by aritParser#Int.
    def enterInt(self, ctx:aritParser.IntContext):
        pass

    # Exit a parse tree produced by aritParser#Int.
    def exitInt(self, ctx:aritParser.IntContext):
        pass



del aritParser