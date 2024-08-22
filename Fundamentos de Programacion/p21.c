#include<stdio.h>

void AaZ(char a){
      if(a<='Z'){
          putchar(a);
          AaZ(a-1);
      }
}

void ZaA(char a){
      if(a>='A'){
          ZaA(a-1);
          putchar(a);
      }
}

int main(){
    AaZ('A');
    putchar('\n');
    ZaA('Z');
    return 0;
}
