#include<stdio.h>
int mycopy(FILE *ent, FILE *sal){
     int n=0;
     char c;
     while((c=fgetc(ent))!=EOF){
        fputc(c,sal);
        n++;
     }
     return n;
}

int main(int argc, char *argv[]){
    char pal[80], c;
    FILE *ent, *sal ;

    ent=fopen(argv[1],"r");
    sal=fopen(argv[2],"w");

    printf("Caracteres copiados %d.\n",mycopy(ent,sal));

    return 0;
}
