#include<stdio.h>
int Sum(int);
int Suma(int,int);
int Multiplica(int,int);
int rfact(int);
int nCr(int,int);

int main(){
    int n,m;
/*
    printf("Cuanto vale n?");
    scanf("%d",&n);
    printf("Sum(%d)=%d.\n",n,Sum(n));
    printf("%d!=%d.\n",n,rfact(n));

    printf("Cuanto valen n y m?");
    scanf("%d%d",&n,&m);
    printf("%d+%d=%d.\n",n,m,Suma(n,m));
    printf("%dx%d=%d.\n",n,m,Multiplica(n,m));
*/
    fprintf(stdout,"Cuanto valen n y r?(nCr)");
    fscanf(stdin,"%d,%d",&n,&m);
    printf("%dC%d=%d.\n",n,m,nCr(n,m));


    return 0;
}

int Sum(int n){
    if(n<1)
       return 0;
    else
       return n+Sum(n-1);
};

int Suma(int a, int b){
    if(a==0)
        return b;
    else
        return Suma(a-1,b+1);
};

int Multiplica(int n, int m){
   if(n==1)
      return m;
   else
      return Suma(m,Multiplica(n-1,m));
}

int rfact(int n){
    if((n>=0)&&(n<=1))
         return 1;
    else
        return n*rfact(n-1);
}

int nCr(int n, int r){
     return rfact(n)/(rfact(n-r)*rfact(r));
};


