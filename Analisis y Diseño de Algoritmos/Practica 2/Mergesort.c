#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void llenaRand(int *a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = 1+rand() % 99; 
    }
}

void merge(int *a, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) {
        L[i] = a[p + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = a[q + j + 1];
    }

    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int *a, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(a, p, q);
        mergeSort(a, q + 1, r);
        merge(a, p, q, r);
    }
}

void imprimir(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Escribe los numeros con los que quieres trabajar: ");
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));

    srand(time(NULL));
    llenaRand(a, n);
    if(n<50){
    imprimir(a, n);
    }
    clock_t inicio = clock();
    mergeSort(a, 0, n - 1);
    clock_t fin = clock();
    if(n<50){
    imprimir(a, n);
    }
    double tiempo = ((double)(fin - inicio)) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecucion de merge: %f segundos\n", tiempo);
    free(a);

    return 0;
}
