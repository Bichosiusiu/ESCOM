# Generated from Examen.g4 by ANTLR 4.13.2
from antlr4 import *
if "." in __name__:
    from .ExamenParser import ExamenParser
else:
    from ExamenParser import ExamenParser

# This class defines a complete listener for a parse tree produced by ExamenParser.
class ExamenListener(ParseTreeListener):

    # Enter a parse tree produced by ExamenParser#prog.
    def enterProg(self, ctx:ExamenParser.ProgContext):
        pass

    # Exit a parse tree produced by ExamenParser#prog.
    def exitProg(self, ctx:ExamenParser.ProgContext):
        pass


    # Enter a parse tree produced by ExamenParser#PAR.
    def enterPAR(self, ctx:ExamenParser.PARContext):
        pass

    # Exit a parse tree produced by ExamenParser#PAR.
    def exitPAR(self, ctx:ExamenParser.PARContext):
        pass


    # Enter a parse tree produced by ExamenParser#NEG.
    def enterNEG(self, ctx:ExamenParser.NEGContext):
        pass

    # Exit a parse tree produced by ExamenParser#NEG.
    def exitNEG(self, ctx:ExamenParser.NEGContext):
        pass


    # Enter a parse tree produced by ExamenParser#SUMRES.
    def enterSUMRES(self, ctx:ExamenParser.SUMRESContext):
        pass

    # Exit a parse tree produced by ExamenParser#SUMRES.
    def exitSUMRES(self, ctx:ExamenParser.SUMRESContext):
        pass


    # Enter a parse tree produced by ExamenParser#OR.
    def enterOR(self, ctx:ExamenParser.ORContext):
        pass

    # Exit a parse tree produced by ExamenParser#OR.
    def exitOR(self, ctx:ExamenParser.ORContext):
        pass


    # Enter a parse tree produced by ExamenParser#POT.
    def enterPOT(self, ctx:ExamenParser.POTContext):
        pass

    # Exit a parse tree produced by ExamenParser#POT.
    def exitPOT(self, ctx:ExamenParser.POTContext):
        pass


    # Enter a parse tree produced by ExamenParser#NEGPAR.
    def enterNEGPAR(self, ctx:ExamenParser.NEGPARContext):
        pass

    # Exit a parse tree produced by ExamenParser#NEGPAR.
    def exitNEGPAR(self, ctx:ExamenParser.NEGPARContext):
        pass


    # Enter a parse tree produced by ExamenParser#AND.
    def enterAND(self, ctx:ExamenParser.ANDContext):
        pass

    # Exit a parse tree produced by ExamenParser#AND.
    def exitAND(self, ctx:ExamenParser.ANDContext):
        pass


    # Enter a parse tree produced by ExamenParser#NEGATOM.
    def enterNEGATOM(self, ctx:ExamenParser.NEGATOMContext):
        pass

    # Exit a parse tree produced by ExamenParser#NEGATOM.
    def exitNEGATOM(self, ctx:ExamenParser.NEGATOMContext):
        pass


    # Enter a parse tree produced by ExamenParser#MULDIV.
    def enterMULDIV(self, ctx:ExamenParser.MULDIVContext):
        pass

    # Exit a parse tree produced by ExamenParser#MULDIV.
    def exitMULDIV(self, ctx:ExamenParser.MULDIVContext):
        pass


    # Enter a parse tree produced by ExamenParser#ATOM.
    def enterATOM(self, ctx:ExamenParser.ATOMContext):
        pass

    # Exit a parse tree produced by ExamenParser#ATOM.
    def exitATOM(self, ctx:ExamenParser.ATOMContext):
        pass


    # Enter a parse tree produced by ExamenParser#VAR.
    def enterVAR(self, ctx:ExamenParser.VARContext):
        pass

    # Exit a parse tree produced by ExamenParser#VAR.
    def exitVAR(self, ctx:ExamenParser.VARContext):
        pass


    # Enter a parse tree produced by ExamenParser#NUM.
    def enterNUM(self, ctx:ExamenParser.NUMContext):
        pass

    # Exit a parse tree produced by ExamenParser#NUM.
    def exitNUM(self, ctx:ExamenParser.NUMContext):
        pass



del ExamenParser