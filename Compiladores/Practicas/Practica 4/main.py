import sys
from antlr4 import *
from aritLexer import aritLexer
from aritParser import aritParser
from aritMainVisitor import EvalVisitor
def main():
    expresiones = [
    "(8 + 6) * 2 - 3 % 2 / 4",
    "(15 - 3) * (4 + 8) / 6",
    "(20 % 6 + 4) * 3 - 5 / 2",
    "(12 + 18) / (3 * 2) % 5 - 7",
    "(45 / 5 + 10) * (8 - 3) % 4",
    "((3 + 7) * 4) % 6 - (8 / 2)",
    "(18 - 4) % (5 * 3) / 2 + 7",
    "(20 / (4 + 1)) * 3 % 7 + 6",
    "((6 + 2) * (3 - 1)) / 5 % 2",
    "(2/7-8)",
    "3+5*2",
    "(3+5)*2"
]
    for expr in expresiones:
        input_stream = InputStream(expr)  
        lexer = aritLexer(input_stream)
        stream = CommonTokenStream(lexer)
        parser = aritParser(stream)
        tree = parser.expr()  
        visitor = EvalVisitor()
        result = visitor.visit(tree)
        print(f"Resultado: {result}")

if __name__ == '__main__':
    main()
