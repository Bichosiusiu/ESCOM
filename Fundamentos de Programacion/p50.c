#include<stdio.h>
typedef int entero;
entero suma(entero, entero);
void ImpEntero(entero);
entero LeeEntero();

int main(){
   entero a, b, c;

   a=LeeEntero();
   b=LeeEntero();
   c=suma(a,b);
   ImpEntero(c);

   return 0;
}

entero suma(entero s1, entero s2){return s1+s2;};
void ImpEntero(entero e){printf("%d\n",e);};
entero LeeEntero(){
   entero e;
   scanf("%d",&e);
   return e;
};
