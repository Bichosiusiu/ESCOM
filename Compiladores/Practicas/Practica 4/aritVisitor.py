# Generated from arit.g4 by ANTLR 4.13.2
from antlr4 import *
if "." in __name__:
    from .aritParser import aritParser
else:
    from aritParser import aritParser

# This class defines a complete generic visitor for a parse tree produced by aritParser.

class aritVisitor(ParseTreeVisitor):

    # Visit a parse tree produced by aritParser#Float.
    def visitFloat(self, ctx:aritParser.FloatContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by aritParser#Parenthesis.
    def visitParenthesis(self, ctx:aritParser.ParenthesisContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by aritParser#MulDivMod.
    def visitMulDivMod(self, ctx:aritParser.MulDivModContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by aritParser#AddSub.
    def visitAddSub(self, ctx:aritParser.AddSubContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by aritParser#Int.
    def visitInt(self, ctx:aritParser.IntContext):
        return self.visitChildren(ctx)



del aritParser