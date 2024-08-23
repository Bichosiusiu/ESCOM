def enteroslargos(x, y):
    if x < 10 or y < 10:  # Caso base: Si los números son pequeños, simplemente multiplicarlos
        return x * y

    n = max(len(str(x)), len(str(y))) #calcula el numero de digitos y el mayor de los 2 numeros
    n2 = n // 2 #divide entre 2 el maximo numero

   
    xi = x // 10 ** n2 #divide entre la potencia de los tamaños de los numeros y el resultado lo pone, ejemplo si es 1234 pondria 12
    xd = x % (10 ** n2)#hace lo mismo pero saca el residuo por lo que quedaria 34
    yi = y // 10 ** n2
    yd = y % (10 ** n2)

    # parte recursiva 
    xiyi = enteroslargos(xi, yi)
    xdyd = enteroslargos(xd, yd)
    aux = enteroslargos(xi + xd, yi + yd) - xiyi - xdyd

    # combinacion 
    return (xiyi * 10 ** (2 * n2)) + (aux * 10 ** n2) + xdyd

x = int(input("Escribe el primer numero: "))
y =int(input("Escribe el segundo numero: "))
z = enteroslargos(x, y)
print("El resultado de la multiplicación es:", z)
