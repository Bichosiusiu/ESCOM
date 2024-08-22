#include<stdio.h>

void intercambia1(int,int);
void intercambia2(int*,int*);

int main(){
   int a=1, b=0;
   printf("a=%d\tb=%d\n",a,b);
   intercambia1(a,b);
   printf("a=%d\tb=%d\n",a,b);
   intercambia2(&a,&b);
   printf("a=%d\tb=%d\n",a,b);

   return 0;
}

void intercambia1(int x, int y){
   int t=x;
   x=y;
   y=t;
};

void intercambia2(int *x, int *y){
   int t=*x;
   *x=*y;
   *y=t;
};
