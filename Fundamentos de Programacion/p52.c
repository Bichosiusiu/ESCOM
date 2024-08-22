#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    int num;
    char *nom;
    char *ofi;
    float sal;
 } Emp;

int main(int argc, char *argv[]){
    FILE *ent=fopen(*++argv,"r");
    Emp p[20];
    char p1[20], p2[20];
    int i;

    for(i=0;i<4;i++){
       fscanf(ent,"%d%s%s%f",&p[i].num,p1,p2,&p[i].sal);
          p[i].nom=(char*)malloc(sizeof(char)*20);
          strcpy(p[i].nom,p1);
          p[i].ofi=(char*)malloc(sizeof(char)*20);
          strcpy(p[i].ofi,p2);
    }
    for(i=0;i<4;i++)
       printf("%d\t%s\t%s\t%.2f\n",p[i].num,p[i].nom,p[i].ofi,p[i].sal);
    return 0;
}
