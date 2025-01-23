#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#define N 10
#define TAM_MEM (N * N * sizeof(int))
void SumarMatrices(int matrizuno[N][N], int matrizdos[N][N], int resultado[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            resultado[i][j] = matrizuno[i][j] + matrizdos[i][j];
        }
    }
}
int* AbrirMemoriaCompartida(const char* nombre, HANDLE hMemCom){
    int* apDatos;
    if ((hMemCom = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE,nombre)) == NULL) {
        printf("No se accedió a la memoria compartida para %s: (%i)\n", nombre, GetLastError());
        exit(-1);
    }
    if ((apDatos = (int *)MapViewOfFile(hMemCom,FILE_MAP_ALL_ACCESS, 0,0,(2 * N * N * sizeof(int)))) == NULL) {
        printf("No se enlazó la memoria compartida: (%i)\n", GetLastError());
        CloseHandle(hMemCom);
        exit(-1);
    }
    return apDatos;
}
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
void EscribirMemoriaCompartida(int matriz[N][N], int* punteroDatos){
    punteroDatos += N * N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *punteroDatos++ = matriz[i][j];
        }
    }
}
int main(void){
    int matrizA[N][N];
    int matrizB[N][N];
    HANDLE memCom1;
    int* apDatos1;
    apDatos1 = AbrirMemoriaCompartida("MemCom3", memCom1);
    LeerMemoriaCompartida2(matrizA, matrizB, apDatos1);
    UnmapViewOfFile(apDatos1);
    CloseHandle(memCom1);
    HANDLE semaforo1;
    if ((semaforo1 = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, "semaforo2")) == NULL) {
        printf("Falla al invocar OpenSemaphore: %d\n", GetLastError());
        return -1;
    }
    if (!ReleaseSemaphore(semaforo1, 1, NULL)) {
        printf("Falla al invocar ReleaseSemaphore: %d\n", GetLastError());
    }
     int Resultado[N][N];
    SumarMatrices(matrizA, matrizB,Resultado);
    HANDLE memCom2;
    int* apDatos2;
    apDatos2 = AbrirMemoriaCompartida("MemCom2",memCom2);
    EscribirMemoriaCompartida(Resultado, apDatos2);
    UnmapViewOfFile(apDatos2);
    CloseHandle(memCom2);
    HANDLE semaforo2;
    if ((semaforo2 = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, "semaforores")) == NULL) {
        printf("Falla al invocar OpenSemaphore: %d\n", GetLastError());
        return -1;
    }
    if (!ReleaseSemaphore(semaforo2, 1, NULL)) {
        printf("Falla al invocar ReleaseSemaphore: %d\n", GetLastError());
    }
    HANDLE semaforo3;
    if ((semaforo3 = CreateSemaphore(NULL, 0, 1, "semaforores2")) == NULL) {
        printf("Falla al invocar CreateSemaphore: %d\n", GetLastError());
        return -1;
    }
    WaitForSingleObject(semaforo3, INFINITE);
    return 0;
}

