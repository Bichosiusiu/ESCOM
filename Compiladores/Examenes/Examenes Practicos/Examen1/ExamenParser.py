# Generated from Examen.g4 by ANTLR 4.13.2
# encoding: utf-8
from antlr4 import *
from io import StringIO
import sys
if sys.version_info[1] > 5:
	from typing import TextIO
else:
	from typing.io import TextIO

def serializedATN():
    return [
        4,1,12,53,2,0,7,0,2,1,7,1,2,2,7,2,1,0,4,0,8,8,0,11,0,12,0,9,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,27,8,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,
        1,44,8,1,10,1,12,1,47,9,1,1,2,1,2,3,2,51,8,2,1,2,0,1,2,3,0,2,4,0,
        2,1,0,5,6,2,0,3,3,7,7,60,0,7,1,0,0,0,2,26,1,0,0,0,4,50,1,0,0,0,6,
        8,3,2,1,0,7,6,1,0,0,0,8,9,1,0,0,0,9,7,1,0,0,0,9,10,1,0,0,0,10,1,
        1,0,0,0,11,12,6,1,-1,0,12,13,5,1,0,0,13,14,3,2,1,0,14,15,5,2,0,0,
        15,27,1,0,0,0,16,17,5,3,0,0,17,18,5,1,0,0,18,19,3,2,1,0,19,20,5,
        2,0,0,20,27,1,0,0,0,21,22,5,3,0,0,22,27,3,4,2,0,23,24,5,3,0,0,24,
        27,3,2,1,2,25,27,3,4,2,0,26,11,1,0,0,0,26,16,1,0,0,0,26,21,1,0,0,
        0,26,23,1,0,0,0,26,25,1,0,0,0,27,45,1,0,0,0,28,29,10,8,0,0,29,30,
        5,4,0,0,30,44,3,2,1,9,31,32,10,7,0,0,32,33,7,0,0,0,33,44,3,2,1,8,
        34,35,10,6,0,0,35,36,7,1,0,0,36,44,3,2,1,7,37,38,10,5,0,0,38,39,
        5,8,0,0,39,44,3,2,1,6,40,41,10,4,0,0,41,42,5,9,0,0,42,44,3,2,1,5,
        43,28,1,0,0,0,43,31,1,0,0,0,43,34,1,0,0,0,43,37,1,0,0,0,43,40,1,
        0,0,0,44,47,1,0,0,0,45,43,1,0,0,0,45,46,1,0,0,0,46,3,1,0,0,0,47,
        45,1,0,0,0,48,51,5,10,0,0,49,51,5,11,0,0,50,48,1,0,0,0,50,49,1,0,
        0,0,51,5,1,0,0,0,5,9,26,43,45,50
    ]

class ExamenParser ( Parser ):

    grammarFileName = "Examen.g4"

    atn = ATNDeserializer().deserialize(serializedATN())

    decisionsToDFA = [ DFA(ds, i) for i, ds in enumerate(atn.decisionToState) ]

    sharedContextCache = PredictionContextCache()

    literalNames = [ "<INVALID>", "'('", "')'", "'-'", "'^'", "'*'", "'/'", 
                     "'+'", "'&&'", "'||'" ]

    symbolicNames = [ "<INVALID>", "<INVALID>", "<INVALID>", "<INVALID>", 
                      "<INVALID>", "<INVALID>", "<INVALID>", "<INVALID>", 
                      "<INVALID>", "<INVALID>", "ID", "NUMBER", "WS" ]

    RULE_prog = 0
    RULE_expr = 1
    RULE_atom = 2

    ruleNames =  [ "prog", "expr", "atom" ]

    EOF = Token.EOF
    T__0=1
    T__1=2
    T__2=3
    T__3=4
    T__4=5
    T__5=6
    T__6=7
    T__7=8
    T__8=9
    ID=10
    NUMBER=11
    WS=12

    def __init__(self, input:TokenStream, output:TextIO = sys.stdout):
        super().__init__(input, output)
        self.checkVersion("4.13.2")
        self._interp = ParserATNSimulator(self, self.atn, self.decisionsToDFA, self.sharedContextCache)
        self._predicates = None




    class ProgContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def expr(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(ExamenParser.ExprContext)
            else:
                return self.getTypedRuleContext(ExamenParser.ExprContext,i)


        def getRuleIndex(self):
            return ExamenParser.RULE_prog

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterProg" ):
                listener.enterProg(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitProg" ):
                listener.exitProg(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitProg" ):
                return visitor.visitProg(self)
            else:
                return visitor.visitChildren(self)




    def prog(self):

        localctx = ExamenParser.ProgContext(self, self._ctx, self.state)
        self.enterRule(localctx, 0, self.RULE_prog)
        self._la = 0 # Token type
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 7 
            self._errHandler.sync(self)
            _la = self._input.LA(1)
            while True:
                self.state = 6
                self.expr(0)
                self.state = 9 
                self._errHandler.sync(self)
                _la = self._input.LA(1)
                if not ((((_la) & ~0x3f) == 0 and ((1 << _la) & 3082) != 0)):
                    break

        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx


    class ExprContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser


        def getRuleIndex(self):
            return ExamenParser.RULE_expr

     
        def copyFrom(self, ctx:ParserRuleContext):
            super().copyFrom(ctx)


    class PARContext(ExprContext):

        def __init__(self, parser, ctx:ParserRuleContext): # actually a ExamenParser.ExprContext
            super().__init__(parser)
            self.copyFrom(ctx)

        def expr(self):
            return self.getTypedRuleContext(ExamenParser.ExprContext,0)


        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterPAR" ):
                listener.enterPAR(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitPAR" ):
                listener.exitPAR(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitPAR" ):
                return visitor.visitPAR(self)
            else:
                return visitor.visitChildren(self)


    class NEGContext(ExprContext):

        def __init__(self, parser, ctx:ParserRuleContext): # actually a ExamenParser.ExprContext
            super().__init__(parser)
            self.copyFrom(ctx)

        def expr(self):
            return self.getTypedRuleContext(ExamenParser.ExprContext,0)


        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterNEG" ):
                listener.enterNEG(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitNEG" ):
                listener.exitNEG(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitNEG" ):
                return visitor.visitNEG(self)
            else:
                return visitor.visitChildren(self)


    class SUMRESContext(ExprContext):

        def __init__(self, parser, ctx:ParserRuleContext): # actually a ExamenParser.ExprContext
            super().__init__(parser)
            self.copyFrom(ctx)

        def expr(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(ExamenParser.ExprContext)
            else:
                return self.getTypedRuleContext(ExamenParser.ExprContext,i)


        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterSUMRES" ):
                listener.enterSUMRES(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitSUMRES" ):
                listener.exitSUMRES(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitSUMRES" ):
                return visitor.visitSUMRES(self)
            else:
                return visitor.visitChildren(self)


    class ORContext(ExprContext):

        def __init__(self, parser, ctx:ParserRuleContext): # actually a ExamenParser.ExprContext
            super().__init__(parser)
            self.copyFrom(ctx)

        def expr(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(ExamenParser.ExprContext)
            else:
                return self.getTypedRuleContext(ExamenParser.ExprContext,i)


        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterOR" ):
                listener.enterOR(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitOR" ):
                listener.exitOR(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitOR" ):
                return visitor.visitOR(self)
            else:
                return visitor.visitChildren(self)


    class POTContext(ExprContext):

        def __init__(self, parser, ctx:ParserRuleContext): # actually a ExamenParser.ExprContext
            super().__init__(parser)
            self.copyFrom(ctx)

        def expr(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(ExamenParser.ExprContext)
            else:
                return self.getTypedRuleContext(ExamenParser.ExprContext,i)


        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterPOT" ):
                listener.enterPOT(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitPOT" ):
                listener.exitPOT(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitPOT" ):
                return visitor.visitPOT(self)
            else:
                return visitor.visitChildren(self)


    class NEGPARContext(ExprContext):

        def __init__(self, parser, ctx:ParserRuleContext): # actually a ExamenParser.ExprContext
            super().__init__(parser)
            self.copyFrom(ctx)

        def expr(self):
            return self.getTypedRuleContext(ExamenParser.ExprContext,0)


        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterNEGPAR" ):
                listener.enterNEGPAR(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitNEGPAR" ):
                listener.exitNEGPAR(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitNEGPAR" ):
                return visitor.visitNEGPAR(self)
            else:
                return visitor.visitChildren(self)


    class ANDContext(ExprContext):

        def __init__(self, parser, ctx:ParserRuleContext): # actually a ExamenParser.ExprContext
            super().__init__(parser)
            self.copyFrom(ctx)

        def expr(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(ExamenParser.ExprContext)
            else:
                return self.getTypedRuleContext(ExamenParser.ExprContext,i)


        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterAND" ):
                listener.enterAND(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitAND" ):
                listener.exitAND(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitAND" ):
                return visitor.visitAND(self)
            else:
                return visitor.visitChildren(self)


    class NEGATOMContext(ExprContext):

        def __init__(self, parser, ctx:ParserRuleContext): # actually a ExamenParser.ExprContext
            super().__init__(parser)
            self.copyFrom(ctx)

        def atom(self):
            return self.getTypedRuleContext(ExamenParser.AtomContext,0)


        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterNEGATOM" ):
                listener.enterNEGATOM(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitNEGATOM" ):
                listener.exitNEGATOM(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitNEGATOM" ):
                return visitor.visitNEGATOM(self)
            else:
                return visitor.visitChildren(self)


    class MULDIVContext(ExprContext):

        def __init__(self, parser, ctx:ParserRuleContext): # actually a ExamenParser.ExprContext
            super().__init__(parser)
            self.copyFrom(ctx)

        def expr(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(ExamenParser.ExprContext)
            else:
                return self.getTypedRuleContext(ExamenParser.ExprContext,i)


        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterMULDIV" ):
                listener.enterMULDIV(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitMULDIV" ):
                listener.exitMULDIV(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitMULDIV" ):
                return visitor.visitMULDIV(self)
            else:
                return visitor.visitChildren(self)


    class ATOMContext(ExprContext):

        def __init__(self, parser, ctx:ParserRuleContext): # actually a ExamenParser.ExprContext
            super().__init__(parser)
            self.copyFrom(ctx)

        def atom(self):
            return self.getTypedRuleContext(ExamenParser.AtomContext,0)


        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterATOM" ):
                listener.enterATOM(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitATOM" ):
                listener.exitATOM(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitATOM" ):
                return visitor.visitATOM(self)
            else:
                return visitor.visitChildren(self)



    def expr(self, _p:int=0):
        _parentctx = self._ctx
        _parentState = self.state
        localctx = ExamenParser.ExprContext(self, self._ctx, _parentState)
        _prevctx = localctx
        _startState = 2
        self.enterRecursionRule(localctx, 2, self.RULE_expr, _p)
        self._la = 0 # Token type
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 26
            self._errHandler.sync(self)
            la_ = self._interp.adaptivePredict(self._input,1,self._ctx)
            if la_ == 1:
                localctx = ExamenParser.PARContext(self, localctx)
                self._ctx = localctx
                _prevctx = localctx

                self.state = 12
                self.match(ExamenParser.T__0)
                self.state = 13
                self.expr(0)
                self.state = 14
                self.match(ExamenParser.T__1)
                pass

            elif la_ == 2:
                localctx = ExamenParser.NEGPARContext(self, localctx)
                self._ctx = localctx
                _prevctx = localctx
                self.state = 16
                self.match(ExamenParser.T__2)
                self.state = 17
                self.match(ExamenParser.T__0)
                self.state = 18
                self.expr(0)
                self.state = 19
                self.match(ExamenParser.T__1)
                pass

            elif la_ == 3:
                localctx = ExamenParser.NEGATOMContext(self, localctx)
                self._ctx = localctx
                _prevctx = localctx
                self.state = 21
                self.match(ExamenParser.T__2)
                self.state = 22
                self.atom()
                pass

            elif la_ == 4:
                localctx = ExamenParser.NEGContext(self, localctx)
                self._ctx = localctx
                _prevctx = localctx
                self.state = 23
                self.match(ExamenParser.T__2)
                self.state = 24
                self.expr(2)
                pass

            elif la_ == 5:
                localctx = ExamenParser.ATOMContext(self, localctx)
                self._ctx = localctx
                _prevctx = localctx
                self.state = 25
                self.atom()
                pass


            self._ctx.stop = self._input.LT(-1)
            self.state = 45
            self._errHandler.sync(self)
            _alt = self._interp.adaptivePredict(self._input,3,self._ctx)
            while _alt!=2 and _alt!=ATN.INVALID_ALT_NUMBER:
                if _alt==1:
                    if self._parseListeners is not None:
                        self.triggerExitRuleEvent()
                    _prevctx = localctx
                    self.state = 43
                    self._errHandler.sync(self)
                    la_ = self._interp.adaptivePredict(self._input,2,self._ctx)
                    if la_ == 1:
                        localctx = ExamenParser.POTContext(self, ExamenParser.ExprContext(self, _parentctx, _parentState))
                        self.pushNewRecursionContext(localctx, _startState, self.RULE_expr)
                        self.state = 28
                        if not self.precpred(self._ctx, 8):
                            from antlr4.error.Errors import FailedPredicateException
                            raise FailedPredicateException(self, "self.precpred(self._ctx, 8)")
                        self.state = 29
                        self.match(ExamenParser.T__3)
                        self.state = 30
                        self.expr(9)
                        pass

                    elif la_ == 2:
                        localctx = ExamenParser.MULDIVContext(self, ExamenParser.ExprContext(self, _parentctx, _parentState))
                        self.pushNewRecursionContext(localctx, _startState, self.RULE_expr)
                        self.state = 31
                        if not self.precpred(self._ctx, 7):
                            from antlr4.error.Errors import FailedPredicateException
                            raise FailedPredicateException(self, "self.precpred(self._ctx, 7)")
                        self.state = 32
                        _la = self._input.LA(1)
                        if not(_la==5 or _la==6):
                            self._errHandler.recoverInline(self)
                        else:
                            self._errHandler.reportMatch(self)
                            self.consume()
                        self.state = 33
                        self.expr(8)
                        pass

                    elif la_ == 3:
                        localctx = ExamenParser.SUMRESContext(self, ExamenParser.ExprContext(self, _parentctx, _parentState))
                        self.pushNewRecursionContext(localctx, _startState, self.RULE_expr)
                        self.state = 34
                        if not self.precpred(self._ctx, 6):
                            from antlr4.error.Errors import FailedPredicateException
                            raise FailedPredicateException(self, "self.precpred(self._ctx, 6)")
                        self.state = 35
                        _la = self._input.LA(1)
                        if not(_la==3 or _la==7):
                            self._errHandler.recoverInline(self)
                        else:
                            self._errHandler.reportMatch(self)
                            self.consume()
                        self.state = 36
                        self.expr(7)
                        pass

                    elif la_ == 4:
                        localctx = ExamenParser.ANDContext(self, ExamenParser.ExprContext(self, _parentctx, _parentState))
                        self.pushNewRecursionContext(localctx, _startState, self.RULE_expr)
                        self.state = 37
                        if not self.precpred(self._ctx, 5):
                            from antlr4.error.Errors import FailedPredicateException
                            raise FailedPredicateException(self, "self.precpred(self._ctx, 5)")
                        self.state = 38
                        self.match(ExamenParser.T__7)
                        self.state = 39
                        self.expr(6)
                        pass

                    elif la_ == 5:
                        localctx = ExamenParser.ORContext(self, ExamenParser.ExprContext(self, _parentctx, _parentState))
                        self.pushNewRecursionContext(localctx, _startState, self.RULE_expr)
                        self.state = 40
                        if not self.precpred(self._ctx, 4):
                            from antlr4.error.Errors import FailedPredicateException
                            raise FailedPredicateException(self, "self.precpred(self._ctx, 4)")
                        self.state = 41
                        self.match(ExamenParser.T__8)
                        self.state = 42
                        self.expr(5)
                        pass

             
                self.state = 47
                self._errHandler.sync(self)
                _alt = self._interp.adaptivePredict(self._input,3,self._ctx)

        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.unrollRecursionContexts(_parentctx)
        return localctx


    class AtomContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser


        def getRuleIndex(self):
            return ExamenParser.RULE_atom

     
        def copyFrom(self, ctx:ParserRuleContext):
            super().copyFrom(ctx)



    class VARContext(AtomContext):

        def __init__(self, parser, ctx:ParserRuleContext): # actually a ExamenParser.AtomContext
            super().__init__(parser)
            self.copyFrom(ctx)

        def ID(self):
            return self.getToken(ExamenParser.ID, 0)

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterVAR" ):
                listener.enterVAR(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitVAR" ):
                listener.exitVAR(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitVAR" ):
                return visitor.visitVAR(self)
            else:
                return visitor.visitChildren(self)


    class NUMContext(AtomContext):

        def __init__(self, parser, ctx:ParserRuleContext): # actually a ExamenParser.AtomContext
            super().__init__(parser)
            self.copyFrom(ctx)

        def NUMBER(self):
            return self.getToken(ExamenParser.NUMBER, 0)

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterNUM" ):
                listener.enterNUM(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitNUM" ):
                listener.exitNUM(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitNUM" ):
                return visitor.visitNUM(self)
            else:
                return visitor.visitChildren(self)



    def atom(self):

        localctx = ExamenParser.AtomContext(self, self._ctx, self.state)
        self.enterRule(localctx, 4, self.RULE_atom)
        try:
            self.state = 50
            self._errHandler.sync(self)
            token = self._input.LA(1)
            if token in [10]:
                localctx = ExamenParser.VARContext(self, localctx)
                self.enterOuterAlt(localctx, 1)
                self.state = 48
                self.match(ExamenParser.ID)
                pass
            elif token in [11]:
                localctx = ExamenParser.NUMContext(self, localctx)
                self.enterOuterAlt(localctx, 2)
                self.state = 49
                self.match(ExamenParser.NUMBER)
                pass
            else:
                raise NoViableAltException(self)

        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx



    def sempred(self, localctx:RuleContext, ruleIndex:int, predIndex:int):
        if self._predicates == None:
            self._predicates = dict()
        self._predicates[1] = self.expr_sempred
        pred = self._predicates.get(ruleIndex, None)
        if pred is None:
            raise Exception("No predicate with index:" + str(ruleIndex))
        else:
            return pred(localctx, predIndex)

    def expr_sempred(self, localctx:ExprContext, predIndex:int):
            if predIndex == 0:
                return self.precpred(self._ctx, 8)
         

            if predIndex == 1:
                return self.precpred(self._ctx, 7)
         

            if predIndex == 2:
                return self.precpred(self._ctx, 6)
         

            if predIndex == 3:
                return self.precpred(self._ctx, 5)
         

            if predIndex == 4:
                return self.precpred(self._ctx, 4)
         




