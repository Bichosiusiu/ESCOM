#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]){
    FILE *ent=fopen(argv[1],"r");
    char pal1[80], pal2[80], pal3[80];
    int calif=0, i=0;
    do{
       fscanf(ent,"%s\t%s\n",pal1,pal2);
       i++;
       printf("Como se escribe \"%s\" en ingles?",pal1);
       scanf("%s",pal3);
       if(strcmp(pal2,pal3)==0)
           printf("Correcto, %d aciertos.\n",++calif);
       else
           printf("Incorrecto, %d aciertos.\n",calif);

    }while((strcmp(pal3,"#")!=0)&&(i<15));

    printf("Calificacion: %d.\n",calif);

    return 0;
}
