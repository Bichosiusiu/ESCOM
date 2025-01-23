#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#define N 10
#define TAM_MEM_INT (N * N * sizeof(int))
#define TAM_MEM_DOUBLE (N * N * sizeof(double))
void Cofactor(int matriz[N][N], int temp[N][N], int p, int q, int n) {
    int i = 0, j = 0;
    for (int fila = 0; fila < n; fila++){
        for (int col = 0; col < n; col++){
            if (fila != p && col != q) {
                temp[i][j++] = matriz[fila][col]; 
                if (j == n - 1){
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
void InversaMatriz(int matriz[N][N], double inversa[N][N]){
    double determinante = (double)DeterminanteMatriz(matriz, N); 
    if (determinante == 0) {
        printf("La matriz es singular, no se puede calcular la inversa.\n");
        return;
    }
    double adjunta[N][N];
    AdjuntaMatriz(matriz, adjunta, N); 
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            inversa[i][j] = adjunta[i][j] / determinante;
}
HANDLE crearMemoria(const char* nombre, int** punteroDatos){
    HANDLE hMemoria;
    if ((hMemoria = CreateFileMapping(INVALID_HANDLE_VALUE,NULL,PAGE_READWRITE,0,TAM_MEM_INT,nombre)) == NULL) {
        printf("No se creó la memoria compartida: (%i)\n", GetLastError());
        exit(-1);
    }
    if ((*punteroDatos = (int*)MapViewOfFile(hMemoria,FILE_MAP_ALL_ACCESS,0,0,TAM_MEM_INT)) == NULL) {
        printf("No se enlazó la memoria compartida: (%i)\n", GetLastError());
        CloseHandle(hMemoria);
        exit(-1);
    }
    return hMemoria;
}
HANDLE crearMemoriaD(const char* nombre, double** punteroDatos){
    HANDLE hMemoria;
    if ((hMemoria = CreateFileMapping(INVALID_HANDLE_VALUE,NULL,PAGE_READWRITE,0,TAM_MEM_DOUBLE,nombre)) == NULL) {
        printf("No se creó la memoria compartida: (%i)\n", GetLastError());
        exit(-1);
    }
    if ((*punteroDatos = (double*)MapViewOfFile(hMemoria,FILE_MAP_ALL_ACCESS,0,0,TAM_MEM_DOUBLE)) == NULL) {
        printf("No se enlazó la memoria compartida: (%i)\n", GetLastError());
        CloseHandle(hMemoria);
        exit(-1);
    }
    return hMemoria;
}
void escribirMemoria(int matriz[N][N], int* punteroDatos){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *punteroDatos++ = matriz[i][j]; 
        }
    }
}
void escribirMemoriaD(double matriz[N][N], double* punteroDatos){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *punteroDatos++ = matriz[i][j];
        }
    }
}
void errorMem(const char* nombre, HANDLE* hMemCom){
    if ((*hMemCom = OpenFileMapping(
            FILE_MAP_ALL_ACCESS, 
            FALSE,               
            nombre     
        )) == NULL) {
        printf("No se accedió a la memoria compartida para %s: (%i)\n", nombre, GetLastError());
        exit(-1);
    }
}
int* mapearMemoria(const char* nombre, HANDLE hMemCom){
    int* apDatos;
    if ((apDatos = (int *)MapViewOfFile(hMemCom,FILE_MAP_ALL_ACCESS, 0,0,TAM_MEM_INT)) == NULL) {
        printf("No se enlazó la memoria compartida: (%i)\n", GetLastError());
        CloseHandle(hMemCom);
        exit(-1);
    }
    return apDatos;
}
void leerMemoria(int matriz[N][N], int* punteroDatos){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = *punteroDatos++;
        }
    }
}
int main(void){
    int matrizA[N][N];
    int matrizB[N][N];
    HANDLE memMatA;
    int* apDatosMatA;
    errorMem("Memoria_Compartida_MU_PH", &memMatA);
    apDatosMatA = mapearMemoria("Memoria_Compartida_MU_PH", memMatA);
    leerMemoria(matrizA, apDatosMatA);
    apDatosMatA[0] = -1;
    UnmapViewOfFile(apDatosMatA);
    CloseHandle(memMatA);
    HANDLE memMatB;
    int* apDatosMatB;
    errorMem("Memoria_Compartida_MD_PH", &memMatB);
    apDatosMatB = mapearMemoria("Memoria_Compartida_MD_PH", memMatB);
    leerMemoria(matrizB, apDatosMatB);
    apDatosMatB[0] = -1;
    UnmapViewOfFile(apDatosMatB);
    CloseHandle(memMatB);
    double inversaA[N][N];
    InversaMatriz(matrizA,inversaA);
    double* apDatosResinvu;
    HANDLE memResinvu = crearMemoriaD("Memoria_Compartida_Res_InvU", &apDatosResinvu);
    escribirMemoriaD(inversaA, apDatosResinvu);
    while (apDatosResinvu[0] != -1) {
        Sleep(1);
    }
    UnmapViewOfFile(apDatosResinvu);
    CloseHandle(memResinvu);
    double inversaB[N][N];
    InversaMatriz(matrizB,inversaB);
    double* apDatosResinvd;
    HANDLE hMemComResinvd = crearMemoriaD("Memoria_Compartida_Res_InvD", &apDatosResinvd);
    escribirMemoriaD(inversaB, apDatosResinvd);
    while (apDatosResinvd[0] != -1) {
        Sleep(1);
    }
    UnmapViewOfFile(apDatosResinvd);
    CloseHandle(hMemComResinvd);
    return 0;
}