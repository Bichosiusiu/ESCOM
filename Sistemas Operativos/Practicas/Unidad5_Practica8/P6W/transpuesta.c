#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#define N 10
#define TAM_MEM (2 * N * N * sizeof(int))
void TransponerMatriz(int matriz[N][N], int resultado[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            resultado[j][i] = matriz[i][j];
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
    punteroDatos += 3 * (N * N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *punteroDatos++ = matriz[i][j];
        }
    }
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
int main(void){
    int Matrizuno[N][N];
    int Matrizdos[N][N];
    HANDLE memcom1;
    int* apDatos1;
    apDatos1 = abrir("MemCom1", memcom1);
    LeerMemoriaCompartida2(Matrizuno, Matrizdos, apDatos1);
    UnmapViewOfFile(apDatos1);
    CloseHandle(memcom1);
    HANDLE semmat;
    if ((semmat = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, "semMat")) == NULL) {
        printf("Falla al invocar OpenSemaphore: %d\n", GetLastError());
        return -1;
    }
    if (!ReleaseSemaphore(semmat, 1, NULL)) {
        printf("Falla al invocar ReleaseSemaphore: %d\n", GetLastError());
    }
    int TraspuestaUno[N][N];
    int TraspuestaDos[N][N];
    TransponerMatriz(Matrizuno, TraspuestaUno);
    TransponerMatriz(Matrizdos, TraspuestaDos);
    HANDLE memcom2;
    int* apDatos2;
    apDatos2 = abrir("memComRes", memcom2);
    EscribirMemoriaCompartida(TraspuestaUno, apDatos2);
    EscribirMemoriaCompartida(TraspuestaDos, apDatos2 + (N * N));
    HANDLE sem1;
    if ((sem1 = CreateSemaphore(NULL, 0, 1, "semRes4")) == NULL) {
        printf("Falla al invocar CreateSemaphore: %d\n", GetLastError());
        return -1;
    }
    WaitForSingleObject(sem1, INFINITE);
    UnmapViewOfFile(apDatos2);
    CloseHandle(memcom2);
    return 0;
}