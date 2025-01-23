#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10
void Cofactor(int matriz[N][N], int temp[N][N], int p, int q, int n) {
    int i = 0, j = 0;
    for (int fila = 0; fila < n; fila++){
        for (int col = 0; col < n; col++){
            if (fila != p && col != q) {
                temp[i][j++] = matriz[fila][col]; 
                if (j == n - 1) {
                    j = 0; 
                    i++; 
                }
            }
        }
    }
}
int DeterminanteMatriz(int matriz[N][N], int n){
    int determinante = 0;
    if (n == 1)
        return matriz[0][0];
    int temp[N][N];
    int signo = 1; 
    for (int f = 0; f < n; f++){
        Cofactor(matriz, temp, 0, f, n); 
        determinante += signo * matriz[0][f] * DeterminanteMatriz(temp, n - 1); 
        signo = -signo; 
    }
    return determinante; 
}
void AdjuntaMatriz(int matriz[N][N], double adjunta[N][N], int n) {
    if (n == 1){
        adjunta[0][0] = 1;
        return;
    }
    int temp[N][N];
    int signo = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            Cofactor(matriz, temp, i, j, n);
            signo = ((i + j) % 2 == 0) ? 1 : -1;
            adjunta[j][i] = (signo) * (DeterminanteMatriz(temp, n - 1)); 
        }
    }
}
void inversa(int matriz[N][N], double inversa[N][N]){
    double determinante = (double)DeterminanteMatriz(matriz, N);
    if (determinante == 0){
        printf("La matriz es singular, no se puede calcular la inversa.\n");
        return;
    }
    double adjunta[N][N];
    AdjuntaMatriz(matriz, adjunta, N); 
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            inversa[i][j] = adjunta[i][j] / determinante; 
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
    double invA[N][N];
    inversa(matrizA,invA);
    double invB[N][N];
    inversa(matrizB,invB);
    WriteFile(tubEscritura, invA, sizeof(invA), &escritura, NULL);
    WriteFile(tubEscritura, invB, sizeof(invB), &escritura, NULL);
    CloseHandle(tubLectura);
    CloseHandle(tubEscritura);
    return 0;
}