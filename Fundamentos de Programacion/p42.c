#include<stdio.h>

int main(){
    FILE *salida=fopen("random.txt","w");
    char pal[80];
    printf("Como te llamas?");
    scanf("%s",pal);
    fprintf(salida,"Hola %s.\n",pal);

    fclose(salida);
    return 0;
}
