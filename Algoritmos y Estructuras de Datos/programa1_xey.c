#include <stdio.h>

int main() {
   
    float x,y; //declaramos las variables x y y
    printf("Escribe un valor para x: ");//pedimos valor para x
    scanf("%f",&x);//guardamos en x
    printf("Escribe un valor para y: ");//pedimos valor para y
    scanf("%f",&y);//guardamos en y
    if(x<=1 && x>=0 && y<=1 && y>=0) //ponemos de condicion que x e y estan estrictamente entre 0 y 1, con los operadores logicos y comparacionales
    printf("Verdadero");//imprimimos verdadero si las condiciones se cumplen
    else{
        printf("Falso");//imprimimos falso si no se cumple
    }
    return 0;
}

