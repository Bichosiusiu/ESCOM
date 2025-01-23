from antlr4 import FileStream, CommonTokenStream, ParseTreeWalker
from Expr3Lexer import Expr3Lexer
from Expr3Parser import Expr3Parser
from NewVisitor import MyExpr3Visitor
def main():
    input_file = "input.txt"  
    input_stream = FileStream(input_file)
    lexer = Expr3Lexer(input_stream)
    token_stream = CommonTokenStream(lexer)
    parser = Expr3Parser(token_stream)
    tree = parser.root()
    visitor = MyExpr3Visitor()
    visitor.visit(tree)
if __name__ == "__main__":
    main()
