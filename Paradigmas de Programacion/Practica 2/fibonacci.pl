%Titulo:Fibonacci

%descripcion:haz la serie de fibonacci en prolog, la posicion y el numero debe de arrojarse en pantalla

%fecha:28/09/2023

%version:1.5

%autor: Vazquez Blancas Cesar Said, Segundo Cruz Daniel

fibonacci(0,0).%iniciamos un hecho para cuando sea 0

fibonacci(1,1).%iniciamos otro hecho para cuando sea 1

fibonacci(X,Y):-%regla para determinar el nesimo numero

X>1,%x debe de ser mayor a 1

X1 is X-1,%x1 se actualiza como x-1

X2 is X-2,%x2 se actualiza como x-2

fibonacci(X1,Y1),%llamamos recursivamente a fibonacci dandole el x1 y el y1 como valores

fibonacci(X2,Y2),%llamamos recursivamente a fibonacci dandole el x2 y el y2 como valores

Y is Y1+Y2. %actualizamos y que es el resultado sumandole los resultados de y1 y y2 que se dan recursivamente
