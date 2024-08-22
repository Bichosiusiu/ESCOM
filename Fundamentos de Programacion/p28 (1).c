#include<stdio.h>

int LeeArreglo(int[]);
void ImpArreglo(int[],int);
void Burbuja(int[],int);
int BusqBin(int, int[],int);
void Intercambia(int*,int*);
int EsIgual(int,int);
int EsMenor(int,int);
int EstaEn(int, int[], int);

int main(){
   int f,n,e,a[100];

   n=LeeArreglo(a);
   scanf("%d",&e);
   (f=EstaEn(e,a,n))!=-1?printf("%d esta en %d.\n",e,f):printf("%d no esta en a.\n",e);
   /*
   puts("--------");
   ImpArreglo(a,n);
   Burbuja(a,n);
   puts("--------");
   ImpArreglo(a,n);
   */
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
   while(l<r){
      if(EsIgual(x,a[m]))
          return 1;
      else if(EsMenor(x,a[m])){
               r=m;
               m=(r+l)/2;
           }else{
               l=m;
               m=(r+l)/2;
           }
      }
    return 0;
}

void Intercambia(int *a, int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
int EsIgual(int a, int b){return a==b;};
int EsMenor(int a, int b){ return a<b;}

