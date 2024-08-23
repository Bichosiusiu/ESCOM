#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void Llena(int[],int);
void Imprime(int[],int);
void insercion(int[],int);
int main()
{
int a[100];
int n;
srand(time(NULL));
printf("Escribe cuantos datos quieres que se ordenen en este programa: \t");
scanf("%d",&n);
Llena(a,n);
printf("Tus datos son:\n");
Imprime(a,n);
insercion(a,n);
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
void insercion(int a[], int n){
int i,j,t;
for (i=1; i<n; i++)
{
j=i-1;
t = a[i];
while(j>=0 && t<a[j]){
a[j+1] = a[j];
    j=j-1;
}
a[j+1] = t;
}
}

