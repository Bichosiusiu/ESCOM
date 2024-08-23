#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void Llena(int[],int);
void Imprime(int[],int);
void Burbuja(int[],int);
int main()
{
int a[100];
int n;
srand(time(NULL));
printf("Escribe el numero de datos que quieres ordenar: \t");
scanf("%d",&n);
Llena(a,n);
printf("Tus datos son:\n");
Imprime(a,n);
Burbuja(a,n);
printf("\nTus datos ordenados son: \n");
Imprime(a,n);

}
void Llena(int a[], int n){
   int i;
   for(i=0;i<n;i++)
        a[i]=1+rand()%100;
}
void Imprime(int a[], int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}
void Burbuja(int a[], int n){
    int j,i,t;
    for(j=1;j<n;j++)
       for(i=n-1;i>=j;i--)
          if(a[i]<a[i-1])
      {
        t = a[i];
        a[i] = a[i-1];
        a[i-1] = t;

}
}

