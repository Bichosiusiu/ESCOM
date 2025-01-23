from antlr4 import *
from antlr4.InputStream import InputStream
from ExamenLexer import ExamenLexer
from ExamenParser import ExamenParser
from ExamenVisitor import ExamenVisitor
def esta_balanceada(expresion: str) -> bool:
    pares = {')': '(', '}': '{', ']': '['}
    pila = []
    for char in expresion:
        if char in pares.values():  
            pila.append(char)
        elif char in pares.keys(): 
            if pila == [] or pila.pop() != pares[char]:
                return False
    return pila == []
def main():
    expresiones = [
        "(3 + 5) * 2",
    "(2 * 5 + 10) / 0",
    "-((5 ^ 2) + (3 * 4) - (8 / 2)) + (2 ^ 3)",
    "(3 * (2 + 5)) - (4 ^ 2) + (12 / 3) * -1",
    "-((6 / 2) * (3 + 5) - (2 + 4)) + 10",
    "(-x ^ 2) * 3",
    "x || (y && -z)",
    "-((3 || 5) && (0 && 1)) || 4",
    "-(10 || (6 && 2)) && (1 + 1) || 8",
    "-((5 && 0) || (4 || 1) && (3 + 2))",
    "1 && 0",
    "0 && 1",
    "1 && 1",
    "0 && 0",
    "1 || 0",
    "0 || 1",
    "1 || 1",
    "0 || 0"
    ]

    for expr in expresiones:
        print(f"\nEvaluando expresión: {expr}")
        if esta_balanceada(expr):
            input_stream = InputStream(expr)
            lexer = ExamenLexer(input_stream)
            token_stream = CommonTokenStream(lexer)
            parser = ExamenParser(token_stream)
            try:
                tree = parser.prog()  
                print(f"Árbol de sintaxis para '{expr}':")
                print(tree.toStringTree(recog=parser)) 

                evaluator = ExamenVisitor()
                evaluator.visit(tree)  
                if evaluator.is_valid_expression():
                    result = evaluator.visit(tree)  
                    print(f"Resultado: {result}")
            except Exception as e:
                print(f"Error en la evaluación: {str(e)}")
        else:
            print("No esta balanceda")

if __name__ == '__main__':
    main()