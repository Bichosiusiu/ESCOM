#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#define N 10
void multiplicar(int matrizuno[N][N], int matrizdos[N][N], int resultado[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            resultado[i][j] = 0; 
            for (int k = 0; k < N; k++){
                resultado[i][j] += matrizuno[i][k] * matrizdos[k][j]; 
            }
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
    multiplicar(matrizA,matrizB,resultado);
    WriteFile(tubEscritura, resultado, sizeof(resultado), &escritura, NULL);
    CloseHandle(tubLectura);
    CloseHandle(tubEscritura);
    return 0;
}
