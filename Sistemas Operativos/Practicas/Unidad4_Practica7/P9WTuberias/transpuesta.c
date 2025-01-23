#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#define N 10
void transponer(int matriz[N][N], int resultado[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            resultado[j][i] = matriz[i][j]; 
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
    int traA[N][N];
    transponer(matrizA,traA);
    int traB[N][N];
    transponer(matrizB,traB);
    WriteFile(tubEscritura, traA, sizeof(traA), &escritura, NULL);
    WriteFile(tubEscritura, traB, sizeof(traB), &escritura, NULL);
    CloseHandle(tubLectura);
    CloseHandle(tubEscritura);
    return 0;
}
