import re

class Tabla:
    def __init__(self, nombre, descripcion, lista_elementos):
        self.nombre = nombre
        self.descripcion = descripcion
        self.lista_elementos = lista_elementos
    
    def mostrar_elementos(self):
        return f"Lista de elementos: {', '.join(self.lista_elementos)}"

palabras = r'\b(if|else)\b'  
comparadores = r'==|!=|>=|<=|>|<'  
id = r'\b[a-zA-Z_][a-zA-Z0-9_]*\b'
num = r'\b\d+(\.\d+)?([eE][+-]?\d+)?\b'  
literal = r'"[^"]*"'  

pattern = re.compile(f'({palabras})|({comparadores})|({id})|({num})|({literal})')

def analizar_archivo(ruta):
    lista=[]
    if_else = Tabla(
    nombre="if-else",
    descripcion="Caracteres i,f,e,l,s,e",
    lista_elementos=[]
    )
    comparacion=Tabla(
    nombre="Comparacion",
    descripcion="< o > o <= o >= o == o !=",
    lista_elementos=[]
    )
    ids=Tabla(
    nombre="Id",
    descripcion="Letra seguida por letras y digitos",
    lista_elementos=[]
    )
    numero =Tabla(
    nombre="Numero",
    descripcion="Cualquier constante numerica",
    lista_elementos=[]
    )
    literales = Tabla(
    nombre="Literal",
    descripcion="Cualquier cosa rodeada por "" ",
    lista_elementos=[]
    )

    try:
        with open(ruta, 'r') as file:
            contenido = file.read()
            tokens = pattern.findall(contenido)

            for token_tupla in tokens:
                token = next(t for t in token_tupla if t)
                if re.fullmatch(palabras, token):
                    if_else.lista_elementos.append(token)
                elif re.fullmatch(comparadores, token):
                    comparacion.lista_elementos.append(token)
                elif re.fullmatch(id, token):
                    ids.lista_elementos.append(token)
                elif re.fullmatch(num, token):
                    numero.lista_elementos.append(token)
                elif re.fullmatch(literal, token):
                    literales.lista_elementos.append(token)
            lista.append(if_else)
            lista.append(comparacion)
            lista.append(ids)
            lista.append(numero)
            lista.append(literales)
            imprimirTabla(lista)
    except FileNotFoundError:
        print(f"Error: No se pudo encontrar el archivo '{ruta}'.")

def imprimirTabla(lista):
    print(f"{'Nombre':<15} | {'Descripción':<40} | {'Elementos'}")
    print('-' * 70)
    for columna in lista:
        nombre = columna.nombre
        descripcion = columna.descripcion
        elementos = ', '.join(columna.lista_elementos) if columna.lista_elementos else "Ninguno"
        print(f"{nombre:<15} | {descripcion:<40} | {elementos}")


ruta = 'archivo.txt'
analizar_archivo(ruta)
