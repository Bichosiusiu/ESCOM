#include<stdio.h>


int mayor(int, int, int);


int main(){

    printf("%d\n",mayor(1,2,3));
    printf("%d\n",mayor(1,3,2));
    printf("%d\n",mayor(2,1,3));
    printf("%d\n",mayor(2,3,1));
    printf("%d\n",mayor(3,1,2));
    printf("%d\n",mayor(1,2,1));

    return 0;
}

int mayor(int a, int b, int c){
    if((a>b)&&(a>c))
       return a;
    else if((b>a)&&(b>c))
            return b;
         else
            return c;
};
