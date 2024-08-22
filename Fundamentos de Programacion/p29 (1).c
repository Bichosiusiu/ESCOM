#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int LeeArreglo(int[]);
void LlenaRandArreglo(int[],int);
void ImpArreglo(int[],int);
void Burbuja(int[],int);
int BusqBin(int, int[],int);
int InsOrd(int[],int,int);
int InsOrd2(int[],int,int);
void Intercambia(int*,int*);
int EsIgual(int,int);
int EsMenor(int,int);
int EstaEn(int, int[], int);

int main(){
   int f,n=10,e,a[50];
   srand(time(NULL));
   LlenaRandArreglo(a,n);
   Burbuja(a,n);
 while(1){
   ImpArreglo(a,n);
   printf("\nCual elemento quieres insertar?");
   scanf("%d",&e);
   n=InsOrd2(a,e,n);
   puts("--------");
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

int InsOrd(int a[], int x, int n){
      int i=0,j;
      if(n==0)
         a[0]=x;
      else
        while((i<n)&&(x>a[i]))
            i++;
      if(i<n)
        for(j=n;j>i;j--)
           a[j]=a[j-1];
      a[i]=x;
      return n+1;
};
int InsOrd2(int a[], int x, int n){
    int i=n-1;
    while((i>=0)&&(x<a[i])){
        a[i+1]=a[i];
        i--;
    }
    a[i+1]=x;
    return n+1;

};
void LlenaRandArreglo(int a[], int n){
   int i;
   for(i=0;i<n;i++)
        a[i]=1+rand()%100;
};
void Intercambia(int *a, int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
int EsIgual(int a, int b){return a==b;};
int EsMenor(int a, int b){ return a<b;};
