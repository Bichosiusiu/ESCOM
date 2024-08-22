#include<stdio.h>

void A_a_Z1(int);
void A_a_Z2(int);
void A_a_Z3(int);
void A_a_Z4(int);

int main(){

    int l;
    l=getchar();
    A_a_Z1(l);
    puts("\n---------");
    A_a_Z2(l);
    puts("\n---------");
    A_a_Z3(l);
    puts("\n---------");
    A_a_Z4(l);

    return 0;
}
/* l .. 'Z' de izq a der E*/
void A_a_Z1(int l){
     if(l<='Z'){
          putchar(l);
          A_a_Z1(l+1);
     }
};

/* 'A' .. l de der a izq X*/
void A_a_Z2(int l){
     if(l>='A'){
          A_a_Z2(l-1);
          putchar(l);
     }
};

/* 'Z' .. l de izq a der X*/
void A_a_Z3(int l){
     if(l<='Z'){
          A_a_Z3(l+1);
          putchar(l);
     }
};
/* E*/
void A_a_Z4(int l){
     if(l>='A'){
        putchar(l);
        A_a_Z4(l-1);
     }
};
