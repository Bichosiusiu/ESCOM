#include <windows.h>
#include <stdio.h>
#define N 10
void sumar(int matrizuno[N][N], int matrizdos[N][N], int resultado[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            resultado[i][j] = matrizuno[i][j] + matrizdos[i][j];
        }
    }
}
int main(){
    HANDLE lectura1 = GetStdHandle(STD_INPUT_HANDLE);
    DWORD lectura;
    HANDLE escritura1 = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD escritura;
    int MatrizA[N][N];
    int MatrizB[N][N];
    ReadFile(lectura1, MatrizA, sizeof(MatrizA), &lectura, NULL);
    ReadFile(lectura1, MatrizB, sizeof(MatrizB), &lectura, NULL);
    int Resultado[N][N];
    sumar(MatrizA, MatrizB, Resultado);
    WriteFile(escritura1, Resultado, sizeof(Resultado), &escritura, NULL);
    CloseHandle(lectura1);
    CloseHandle(escritura1);
    return 0;
}