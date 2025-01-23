#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#define N 10
void sumar(int A[N][N], int B[N][N], int resultado[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            resultado[i][j] = A[i][j] + B[i][j];
        }
    }
}
int main(int argc, char *argv[]){
    HANDLE tubLectura = GetStdHandle(STD_INPUT_HANDLE);
    DWORD lectura;
    HANDLE tubEscritura = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD escritura;
    int matrizA[N][N];
    int matrizB[N][N];
    ReadFile(tubLectura, matrizA, sizeof(matrizA), &lectura, NULL);
    ReadFile(tubLectura, matrizB, sizeof(matrizB), &lectura, NULL);
    int resultado[N][N];
    sumar(matrizA,matrizB,resultado);
    WriteFile(tubEscritura, resultado, sizeof(resultado), &escritura, NULL);
    CloseHandle(tubLectura);
    CloseHandle(tubEscritura);
    return 0;
}