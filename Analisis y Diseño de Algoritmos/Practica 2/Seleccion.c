#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void llenarand(int *a, int n){
        for (int i = 0; i < n; i++) {
        a[i] = 1+rand() % 99;
    }
}
void seleccion(int *a, int n) {
    int i, j, aux,k;
    for (i = 0; i < n-1; i++) {
        aux=a[i];
        k=i;
        for (j = i+1; j < n; j++) {
            if (a[j] < aux) {
                aux=a[j];
                k=j;
            }
        }
        a[k]=a[i];
        a[i]=aux;
    }
}
void imprime(int *a, int n){
    for(int i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
}
void impresion(int *a,int n){
     if(n<50){
        imprime(a,n);
    }
}
int main() {
    int n;
    printf("Escribe los valores con los que quieres trabajar: ");
    scanf("%d",&n);
    int *a=(int *)malloc(n*sizeof(int));
    srand(time(NULL));
    llenarand(a,n);
    impresion(a,n);
    clock_t inicio = clock();
    seleccion(a, n);
    clock_t fin = clock();
    printf("\n");
    impresion(a,n);
    double tiempo = ((double)(fin - inicio)) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecucion de seleccion: %f segundos\n", tiempo);
    free(a);
    return 0;
}
