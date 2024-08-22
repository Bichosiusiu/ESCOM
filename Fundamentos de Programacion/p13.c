#include<stdio.h>

int Pago(int);

int main(){
   int pares;

   printf("Cuantos pares fabrico?");
   scanf("%d",&pares);
   printf("Por %d pares, se pagan $%d.\n",pares,Pago(pares));

   return 0;

}

int Pago(int n){
    if(n<=4)
        return n*70;
    else
        return 280+(n-4)*75;
}
