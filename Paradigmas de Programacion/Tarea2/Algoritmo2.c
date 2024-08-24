#include<stdio.h>
#include<stdlib.h>
int main(){
    char *p;
    char c[11]="hOla MunDo";
    p=&c[0];
    while(*p!='\0'){
        if(*p>=97 && *p<=122){
            *p-=32;
        }
        p++;
    }
    printf("%s",c);
}