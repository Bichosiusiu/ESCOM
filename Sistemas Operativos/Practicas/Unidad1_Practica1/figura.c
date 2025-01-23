#include<stdio.h>
void imprimirFigura(int n){
    int e,a,i,j;
    for(i=0;i<n;i++){
        e = n - i -1;
        a = 2 * i + 1;
        for(j=0;j<e;j++){
            printf(" ");
        }
        if (e > 0){
        for(j=0;j<a;j++){
            printf("*");
        }
        for(j=0;j<e+ (n - 1);j++){
            printf(" ");
        }
        printf("*");
        }
        else{
        for(j=0;j<a*2;j++){
            printf("*");
        }
        }
        printf("\n");
    }
    for(i=n-1;i>0;i--){
        e = n - i;
        a = 2 * i - 1;
        for(j=0;j<n-1;j++){
            printf(" ");
        }
        printf("*");
        for(j=0;j<n-1+e;j++){
            printf(" ");
        }
        for(j=0;j<a;j++){
            printf("*");
        }
        printf("\n");
    }
}
int main(){
    int n=0,b,i;
    printf("Ingrese el numero de niveles de su piramide: ");
    scanf("%d",&b);
    if (b % 2 == 0)
    {
        b++;
    }

    for (i = 0; i < (b / 2); i++)
    {
        b -= 2;

        if (b>= 0)
        {
            n++;
        }
    }

    imprimirFigura(n);
    return 0;
}