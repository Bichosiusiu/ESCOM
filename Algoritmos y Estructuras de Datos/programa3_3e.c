#include <stdio.h>
#include <math.h>
int main(){
    int x;//valor para pedir al usuario
    int y;//valor para pedir al usuario
    int z;//valor para pedir al usuario
    printf("Ingrese un 3 enteros: ");//pedimos los 3 enteros
    scanf("%d%d%d",&x, &y, &z);//leemos y guardamos los 3 enteros

  if(x==y && y==z)//condicion si x e y son iguales e y e z son iguales
  printf("Igual"); //imprimimos igual si se cumple la condicion
  else{
      printf("No igual");//imprimimos no igual si no se cumple
  }
    return 0;
}
