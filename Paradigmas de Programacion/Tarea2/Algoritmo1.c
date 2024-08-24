#include<stdio.h>
#include<stdlib.h>
int main(){
    int n=684, x=2;
    while(n>x){
        while(n%x==0){
            printf("%d\n",x);
            n/=x;
        }
        x++;
    }
    return 0;
}