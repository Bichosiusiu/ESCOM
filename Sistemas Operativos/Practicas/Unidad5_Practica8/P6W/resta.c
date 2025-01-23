#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#define N 10
#define TAM_MEM (2 * N * N * sizeof(int))
void RestarMatrices(int matrizuno[N][N], int matrizdos[N][N], int resultado[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++) {
            resultado[i][j] = matrizuno[i][j] - matrizdos[i][j]; 
        }
    }
}
int* abrir(const char* nombre, HANDLE hMemCom){
    int* apDatos;
    if ((hMemCom = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE,nombre)) == NULL) {
        printf("No se accedió a la memoria compartida para %s: (%i)\n", nombre, GetLastError());
        exit(-1);
    }
    if ((apDatos = (int *)MapViewOfFile( hMemCom,FILE_MAP_ALL_ACCESS, 0,0,TAM_MEM)) == NULL) {
        printf("No se enlazó la memoria compartida: (%i)\n", GetLastError());
        CloseHandle(hMemCom);
        exit(-1);
    }
    return apDatos;
}
void EscribirMemoriaCompartida(int matriz[N][N], int* punteroDatos){
    punteroDatos += N * N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *punteroDatos++ = matriz[i][j]; 
        }
    }}
void LeerMemoriaCompartida(int matriz[N][N], int* punteroDatos){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = *punteroDatos++;
        }
    }
}
void LeerMemoriaCompartida2(int matrizuno[N][N], int matrizdos[N][N], int* punteroDatos){
    LeerMemoriaCompartida(matrizuno, punteroDatos);
    LeerMemoriaCompartida(matrizdos, punteroDatos + (N * N));
}
int main(void){
    int Matrizuno[N][N];
    int Matrizdos[N][N];
    HANDLE memCom1;
    int* apDatos1;
    apDatos1 = abrir("MemCom1", memCom1);
    LeerMemoriaCompartida2(Matrizuno, Matrizdos, apDatos1);
    UnmapViewOfFile(apDatos1);
    CloseHandle(memCom1);
    HANDLE semMat;
    if ((semMat = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, "semMat")) == NULL) {
        printf("Falla al invocar OpenSemaphore: %d\n", GetLastError());
        return -1;
    }
    if (!ReleaseSemaphore(semMat, 1, NULL)) {
        printf("Falla al invocar ReleaseSemaphore: %d\n", GetLastError());
    }
    int R[N][N];
    RestarMatrices(Matrizuno, Matrizdos, R);
    HANDLE memCom2;
    int* apDatos2;
    apDatos2 = abrir("memComRes", memCom2);
    EscribirMemoriaCompartida(R, apDatos2);
    HANDLE semRes;
    if ((semRes = CreateSemaphore(NULL, 0, 1, "semRes2")) == NULL) {
        printf("Falla al invocar CreateSemaphore: %d\n", GetLastError());
        return -1;
    }
    WaitForSingleObject(semRes, INFINITE);
    UnmapViewOfFile(apDatos2);
    CloseHandle(memCom2);
    return 0;
}
