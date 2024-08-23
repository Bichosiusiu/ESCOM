#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void llena(int *a, int n);
void imprimir(int *a, int n);
void quicksort(int *a, int p, int r);
int particion(int *a, int p, int r);
void intercambiar(int *a, int i, int j);


int main() {
    int n;

    printf("Escribe los numeros con los que quieres trabajar: ");
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));

    srand(time(NULL));
    llena(a, n);
    if(n<100){
    imprimir(a, n);
    }
    clock_t inicio = clock();
    quicksort(a, 0, n - 1);
    clock_t fin = clock();
    if(n<100){
    imprimir(a, n);
    }
    double tiempo = ((double)(fin - inicio)) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecucion de quicksort: %f segundos\n", tiempo);
    clock_t inicio2 = clock();
    quicksort(a, 0, n - 1);
    clock_t fin2 = clock();
    double tiempo2 = ((double)(fin2 - inicio2)) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecucion de quicksort en el peor de los casos es: %f segundos\n", tiempo2);
    free(a);

    return 0;
}

void imprimir(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void llena(int *a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = 1+rand()%99; 
    }
}

void quicksort(int *a, int p, int r) {
    if (p < r) 
    {
        int q = particion(a, p, r);
        quicksort(a, p, q-1);
        quicksort(a, q+1, r);
    }
}
void intercambiar(int *a, int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
int particion(int *a, int p, int r) {
    int x = a[r];
    int i = p - 1;
    int j;
    for (j = p; j < r; j++) {
        if (a[j] <= x) {
            i++;
            intercambiar(a,i,j);
        }
    }
    intercambiar(a,i+1,r);
    return i + 1;
}
