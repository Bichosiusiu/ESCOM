#include<stdio.h>
#include<string.h>

int main(){
    char pal[80]="012345678901234567890123456789";
    char pal2[80]="Casa";
    int i=0;

    strcpy(pal2,pal);

   // printf("%s\n",pal2);
   pal2[25]='X';

    strcmp(pal2,pal)==0?puts("Son iguales.\n"):puts("Son diferentes.\n");
/*
    printf("%s\n",pal);
    printf("%s\n",pal+8);
    printf("%s\n",pal+20);

    while(pal[i]!='\0')
        i++;
    printf("La cadena %s tiene %d caracteres.\n",pal,i);

   // printf("%c%c%c%c\n",pal[0],pal[8],pal[20],pal[5]);

*/
    return 0;
}
