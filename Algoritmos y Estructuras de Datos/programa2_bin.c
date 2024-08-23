#include <stdio.h>
#include <math.h>

int bin(int n, int *R){ //funcion para hacer el calculo de conversion a binario

    *R = n%2;   //almacenamos el modulo en R
    return n/2; //eliminamos el valor del bit menos significativo al devolverlo
}

int main(){
    int A[100];  //arreglo de enteros para guardar el valor binario
    char B[100]; //arreglo de caracteres para guardar el valor binario
    int x;//valor para pedir al usuario
    int R;//valor para guardar el modulo de 2 mas pequeño
    printf("Ingrese un entero: ");//pedimos un entero
    scanf("%i", &x);//leemos y guardamos el entero en x

    int i;//declaramos el primer iterador
   for( i=0; x!=0; i++ )//bucle hasta que x sea diferente de 0
{
    x= bin( x,&A[i] );//llamamos funcion para obtener los valores binarios y guardarlos en el arreglo de enteros
}
   
    int j;//declaramos el segundo iterador
   for( int j = i-1; j>=0; j-- ){//condicion para imprimir el arreglo justo como esta guardado
    sprintf(B, "%d", A[j]); //convertimos la cadena de enteros a una de caracteres,uno por uno, hasta que se acabe lo que guardamos en el arreglo A, damos el formato de entero porque ese es el original y guardamos en una cadena de caracteres
    printf("%s", B);//imprimimos solo la cadena de caracteres
}
    return 0;
}
