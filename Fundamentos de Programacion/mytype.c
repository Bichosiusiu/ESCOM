#include<stdio.h>
void mytype(FILE *ent){
     int n=0;
     char c;
     while((c=fgetc(ent))!=EOF)
        fputc(c,stdout);

}

int main(){
    char pal[80], c;
    FILE *ent;

    ent=fopen("examen.txt","r");
    mytype(ent);

    return 0;
}
