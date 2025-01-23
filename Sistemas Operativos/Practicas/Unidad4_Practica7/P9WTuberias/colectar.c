#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#define N 10
#define OPERACIONES 5
void imprimir(int matriz[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++){
            printf("%d\t", matriz[i][j]); 
        }
        printf("\n"); 
    }
}
void ImprimirInversa(double matriz[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
            printf("%lf  ", matriz[i][j]); 
        printf("\n"); 
    }
}
int main(int argc, char *argv[]){
    int i;
    int resultado[N][N];
    double inversa[N][N];
    DWORD lectura;
    char *nombres_operaciones[7] = {
        "suma","resta","multiplicacion","traspuestaA","traspuestaB","inversaA","inversaB"
    };
    for (i = 0; i < OPERACIONES; i++){
        ReadFile(GetStdHandle(STD_INPUT_HANDLE), resultado, sizeof(resultado), &lectura, NULL);
        printf("\n\nResultado de %s:\n", nombres_operaciones[i]);
        imprimir(resultado);
    }
    for (i = 5; i <= 6; i++){
        ReadFile(GetStdHandle(STD_INPUT_HANDLE), inversa, sizeof(inversa), &lectura, NULL);
        printf("\n\nResultado de %s:\n", nombres_operaciones[i]);
        ImprimirInversa(inversa);
    }
    return 0;
}
