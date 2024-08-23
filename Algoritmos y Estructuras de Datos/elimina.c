#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void Llena(int[],int);
void Imprime(int[],int);
void seleccion(int[],int);
void elimina(int[], int);
int main()
{

int a[100];
int n;
srand(time(NULL));
printf("Escribe el numero de datos que quieres que se ordenen: \t");
scanf("%d",&n);
Llena(a,n);
printf("Tus datos son:\n");
Imprime(a,n);
seleccion(a,n);
printf("\nTus datos ordenados son: \n");
Imprime(a,n);
printf("\nTus datos ordenados y sin repetir son:\n ");
elimina(a,n);

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
void seleccion(int a[], int n){
    int j,i,k,t;
    for(i=0;i<n-1;i++){
    for (j=i+1; j<n; j++){
        if (a[i] > a[j]){
            t= a[i];
            a[i]= a[j];
        a[j]= t; 
        }
        
}
}
}

void elimina(int a[], int n){
    int i;
    for(i=0;i<=n-1;i++){
        if(a[i]!=a[i+1]){
            printf("%d\t",a[i]);
        }
    }
    
   
}

