#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#define N 10
#define TAM_MEM (N * N * sizeof(int))
void MultiplicarMatrices(int matrizuno[N][N], int matrizdos[N][N], int resultado[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            resultado[i][j] = 0;
            for (int k = 0; k < N; k++){
                resultado[i][j] += matrizuno[i][k] * matrizdos[k][j];
            }
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
void EscribirMemoriaCompartida(int matriz[N][N], int* punteroDatos){
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
    } }
void LeerMemoriaCompartida2(int matrizuno[N][N], int matrizdos[N][N], int* punteroDatos){
    LeerMemoriaCompartida(matrizuno, punteroDatos);
    LeerMemoriaCompartida(matrizdos, punteroDatos + (N * N));
}
HANDLE CrearMemoriaCompartidaDoble(const char* nombre, int** punteroDatos){
    HANDLE hMemoria;
    if ((hMemoria = CreateFileMapping(INVALID_HANDLE_VALUE,NULL,PAGE_READWRITE,0,(2 * N * N * sizeof(int)),nombre)) == NULL) {
        printf("No se creó la memoria compartida: (%i)\n", GetLastError());
        exit(-1);
    }
    if ((*punteroDatos = (int*)MapViewOfFile(hMemoria,FILE_MAP_ALL_ACCESS,0,0,(2 * N * N * sizeof(int)))) == NULL) {
        printf("No se enlazó la memoria compartida: (%i)\n", GetLastError());
        CloseHandle(hMemoria);
        exit(-1);
    }
    return hMemoria;
}
void EscribirMemoriaCompartida2(int matrizuno[N][N], int matrizdos[N][N], int* punteroDatos)
{
    EscribirMemoriaCompartida(matrizuno, punteroDatos);
    EscribirMemoriaCompartida(matrizdos, punteroDatos + (N * N));
}
int main(void){
    int Matrizuno[N][N];
    int Matrizdos[N][N];
    HANDLE memComMat;
    int* apDatos1;
    apDatos1 = AbrirMemoriaCompartida("MemCom1", memComMat);
    LeerMemoriaCompartida2(Matrizuno, Matrizdos, apDatos1);
    UnmapViewOfFile(apDatos1);
    CloseHandle(memComMat);
    HANDLE semaforo1;
    if ((semaforo1 = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, "semaforomat")) == NULL) {
        printf("Falla al invocar OpenSemaphore: %d\n", GetLastError());
        return -1;
    }
    if (!ReleaseSemaphore(semaforo1, 1, NULL)) {
        printf("Falla al invocar ReleaseSemaphore: %d\n", GetLastError());
    }
    int Resultado[N][N];
    MultiplicarMatrices(Matrizuno, Matrizdos,Resultado);
    int* apDatos2;
    HANDLE memCom2 = CrearMemoriaCompartidaDoble("MemCom2", &apDatos2);
    EscribirMemoriaCompartida(Resultado, apDatos2);
    int* apDatos;
    HANDLE hMemCom = CrearMemoriaCompartidaDoble("MemCom3", &apDatos);
    EscribirMemoriaCompartida2(Matrizuno, Matrizdos, apDatos);
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    if (!CreateProcess(NULL,"nieto", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)){
        printf("Fallo al invocar CreateProcess (%d)\n", GetLastError());
        return 1;
    }
    HANDLE semaforo2;
    if ((semaforo2 = CreateSemaphore(NULL, 0, 1, "semaforo2")) == NULL) {
        printf("Falla al invocar CreateSemaphore: %d\n", GetLastError());
        return -1;
    }
    WaitForSingleObject(semaforo2, INFINITE);
    UnmapViewOfFile(apDatos);
    CloseHandle(hMemCom);
    WaitForSingleObject(pi.hProcess, INFINITE);
    UnmapViewOfFile(apDatos2);
    CloseHandle(memCom2);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    return 0;
}

