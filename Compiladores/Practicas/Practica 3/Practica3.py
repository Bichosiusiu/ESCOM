class Automata:
    def __init__(self):
        self.estado = 'inicio'
        self.lexema = ''
        self.tokens = []
        self.reservadas = {'if', 'then', 'else'}
    def agregar(self, token):
        if self.lexema:
            if token == 'id' and self.lexema in self.reservadas:
                token = self.lexema  
            self.tokens.append((token, self.lexema))
            self.lexema = ''
    def tokenizar(self, c):
        if self.estado == 'inicio':
            if c.isalpha() or c == '_': 
                self.estado = 'id'
                self.lexema += c
            elif c.isdigit():  
                self.estado = 'numero'
                self.lexema += c
            elif c == '=':  
                self.estado = '='
                self.lexema += c
            elif c == '<':
                self.estado = '<'
                self.lexema += c
            elif c == '>':
                self.estado = '>'
                self.lexema += c
            elif c.isspace():  
                self.estado = 'inicio'
            else:
                self.estado = 'error'

        elif self.estado == 'id':
            if c.isalnum() or c == '_': 
                self.lexema += c
            else:
                self.agregar('id')
                self.estado = 'inicio'
                self.tokenizar(c)  

        elif self.estado == 'numero':
            if c.isdigit():  
                self.lexema += c
            elif c == '.': 
                self.lexema += c
                self.estado = 'decimalIncompleto'
            elif c == 'e' or c == 'E':  
                self.lexema += c
                self.estado = 'exponente'
            else:
                self.agregar('numero')
                self.estado = 'inicio'
                self.tokenizar(c)
        elif self.estado == 'decimalIncompleto':
            if c.isdigit():
                self.lexema += c
                self.estado = 'decimal'
            else:
                self.estado = 'error'

        elif self.estado == 'decimal':
            if c.isdigit(): 
                self.lexema += c
            elif c == 'e' or c == 'E':  
                self.lexema += c
                self.estado = 'exponente'
            else:
                self.agregar('numero')
                self.estado = 'inicio'
                self.tokenizar(c)

        elif self.estado == 'exponente':
            if c.isdigit():  
                self.lexema += c
                self.estado = 'numero_exp'
            elif c == '+' or c == '-': 
                self.lexema += c
            else:
                self.estado = 'error'

        elif self.estado == 'numero_exp':
            if c.isdigit(): 
                self.lexema += c
            else:
                self.agregar('numero')
                self.estado = 'inicio'
                self.tokenizar(c)

        elif self.estado == '=':
            self.agregar('oprel')
            self.estado = 'inicio'
            self.tokenizar(c)

        elif self.estado == '<':
            if c == '=':
                self.lexema += c
            elif c == '>':
                self.lexema += c
            else:
                self.agregar('oprel')
                self.estado = 'inicio'
                self.tokenizar(c)

        elif self.estado == '>':
            if c == '=':
                self.lexema += c
            self.agregar('oprel')
            self.estado = 'inicio'
            self.tokenizar(c)

        elif self.estado == 'error':
            raise SyntaxError(f'Carácter inesperado: {c}')
    def procesar(self, cadena):
        for c in cadena:
            self.tokenizar(c)
        if self.lexema:
            if self.estado == 'id':
                self.agregar('id')
            elif self.estado == 'numero' or self.estado == 'decimal' or self.estado == 'numero_exp':
                self.agregar('numero')
            elif self.estado == '<' or self.estado == '>' or self.estado == '=':
                self.agregar('oprel')
        return self.tokens
def leer(nomarchivo):
    with open(nomarchivo, 'r') as archivo:
        return archivo.read()
def procesar(nomarchivo):
    automata = Automata()
    contenido = leer(nomarchivo)
    tokens = automata.procesar(contenido)
    return tokens
nomarchivo = 'ejemplo.txt'
tokens = procesar(nomarchivo)
print('-' * 57)
print(f"|{' ':<10}{'lexema':<17}| {'':<5}{'Nombre del Token':<21} |")
print('-' * 57)
for token in tokens:
    tipoToken, lexema = token
    print(f"|         {lexema:<10}        |       {tipoToken:<20} |")
    print("-" * 57)
