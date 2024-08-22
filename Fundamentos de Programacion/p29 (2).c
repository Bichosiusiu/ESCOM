#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int LeeArreglo(int[]);
void ImpArreglo(int[],int);
void Burbuja(int[],int);
int BusqBin(int, int[],int);
void Intercambia(int*,int*);
int EsIgual(int,int);
int EsMenor(int,int);
int EstaEn(int, int[], int);

int main(){
   int f,n=10000,e,a[10000];
   srand(time(NULL));

   for(f=0;f<n;f++)
        a[f]=1+rand()%500;
   Burbuja(a,n);
 while(1){
   printf("Cual elemento buscas?");
   scanf("%d",&e);
   printf("El elemento esta en %d.\n",BusqBin(e,a,n));
 }
   return 0;
}

int EstaEn(int x, int a[], int n){
    int i=0;

    while(i<n){
        if(EsIgual(x,a[i]))
          return i;
        i++;
    }
    return -1;
};

int LeeArreglo(int a[]){
     int i=0;
     do{
        scanf("%d",&a[i]);
        i++;
     }while(a[i-1]);
     return i-1;
};
void ImpArreglo(int a[], int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}
void Burbuja(int a[], int n){
    int j,i;
    for(j=1;j<n;j++)
       for(i=n-1;i>=j;i--)
          if(EsMenor(a[i],a[i-1]))
              Intercambia(&a[i],&a[i-1]);
}

int BusqBin(int x, int a[], int n){
   int l=0,r=n-1,m=r/2;
   while(l<=r){
      if(EsIgual(x,a[m]))
          return m;
      else if(EsMenor(x,a[m])){
               r=m-1;
               m=(r+l)/2;
           }else{
               l=m+1;
               m=(r+l)/2;
           }
      }
    return -1;
}

void Intercambia(int *a, int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
int EsIgual(int a, int b){return a==b;};
int EsMenor(int a, int b){ return a<b;}

