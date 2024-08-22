#include<stdio.h>

int main(){
    FILE *salida=fopen("random.txt","w");
    int c, i;
    printf("Hasta donde quieres la tabla?");
    scanf("%d",&c);
    fprintf(salida,"C\tF\tK\n");
    for(i=1;i<=c;i++){
    printf("%d\t%.2f\t%.2f\n",i,(float)i*1.8+32,(float)i+273.15);
    fprintf(salida,"%d\t%.2f\t%.2f\n",i,(float)i*1.8+32,(float)i+273.15);
}

    fclose(salida);
    return 0;
}
