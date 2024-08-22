#include<stdio.h>

void for_De_1_a_N(int);
void while_De_1_a_N(int);
void for_TablaMult(int,int);
void while_TablaMult(int,int);
int rFib(int);
int iFib(int);
int iFib2(int);


int main(){

    int t,n;
    printf("n?");
    scanf("%d",&n);

    printf("Fib(%d)=%d\n",n,rFib(n));
    printf("Serie de Fibbonacci.\n");
    iFib2(n);
   // for_TablaMult(t,n);
   // for_De_1_a_N(n);
   // while_De_1_a_N(n);


    return 0;
}

void for_De_1_a_N(int n){
    int i;
    for(i=1;i<=n;i++)
      printf("%d\t",i);
    printf("\nAfuera del for i=%d\t",++i);
    putchar('\n');
};

void while_De_1_a_N(int n){
    int i=1;
    while(i<=n)
      printf("%d\t",i++);
    putchar('\n');
};

void for_TablaMult(int tabla,int n){
   int i;
   for(i=1;i<=n;i++)
      printf("%d*%d=%d\n",tabla,i,tabla*i);
};

void while_TablaMult(int tabla,int n){

};

int rFib(int n){
   if(n==0)
      return 0;
   else if(n==1)
          return 1;
        else
            return rFib(n-1)+rFib(n-2);
};
int iFib(int n){
   int i, fib0=0, fib1=1, fibn=0;

   printf("%d+%d",fib0,fib1);
   for(i=2;i<=n;i++){
        fibn=fib0+fib1;
        printf("+%d",fibn);
        fib0=fib1;fib1=fibn;
   }
};

int iFib2(int n){
   int i=0;
   while(i<=n){
      printf("%d",rFib(i++));
      if(i<=n)
          printf("+");
   }
   printf("\n");
};

