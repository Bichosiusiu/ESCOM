#include<stdio.h>

int main(){
    char pal[80];
    FILE *ent, *sal ;

    ent=fopen("nums.txt","r");
    sal=fopen("borrame.txt","w");

    fscanf(ent,"%s",pal);
    fprintf(sal,"Tu cadena es:\n%s.\n",pal);
    fscanf(ent,"%s",pal);
    fprintf(sal,"Tu cadena es:\n%s.\n",pal);

    fclose(ent);
    fclose(sal);
    return 0;
}
