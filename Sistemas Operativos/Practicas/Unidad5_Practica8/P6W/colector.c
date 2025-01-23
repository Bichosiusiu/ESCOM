#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define TAM_MEM (5 * N * N * sizeof(int))
#define TAM_MEM2 (2 * N * N * sizeof(double))
void ImprimirMatriz(int matriz[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
            printf("%d\t", matriz[i][j]);
        printf("\n");
    }
}
void ImprimirInversa(double matriz[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
            printf("%lf  ", matriz[i][j]);
        printf("\n");
    }
}
int* abrir(const char* nombre, HANDLE hMemCom){
    int* apDatos;
    if ((hMemCom = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE,nombre)) == NULL) {
        printf("No se accedió a la memoria compartida para %s: (%i)\n", nombre, GetLastError());
        exit(-1);
    }
    if ((apDatos = (int *)MapViewOfFile(hMemCom, FILE_MAP_ALL_ACCESS, 0, 0, TAM_MEM)) == NULL) {
        printf("No se enlazó la memoria compartida: (%i)\n", GetLastError());
        CloseHandle(hMemCom);
        exit(-1);
    }
    return apDatos;
}
int* abrir2(const char* nombre, HANDLE hMemCom){
    int* apDatos;
    if ((hMemCom = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE,nombre)) == NULL) {
        printf("No se accedió a la memoria compartida para %s: (%i)\n", nombre, GetLastError());
        exit(-1);
    }
    if ((apDatos = (int *)MapViewOfFile(hMemCom,FILE_MAP_ALL_ACCESS, 0,0,TAM_MEM2)) == NULL) {
        printf("No se enlazó la memoria compartida: (%i)\n", GetLastError());
        CloseHandle(hMemCom);
        exit(-1);
    }
    return apDatos;
}
void leer(int matriz[N][N], int* punteroDatos){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = *punteroDatos++;
        }
    }
}
void leer2(int matrizuno[N][N], int matrizdos[N][N], int matriztres[N][N], int matrizcuatro[N][N], int matrizcinco[N][N], int* punteroDatos){
    leer(matrizuno, punteroDatos);
    leer(matrizdos, punteroDatos + (N * N));
    leer(matriztres, punteroDatos + (2 * N * N));
    leer(matrizcuatro, punteroDatos + (3 * N * N));
    leer(matrizcinco, punteroDatos + (4 * N * N));
}
void leerD(double matriz[N][N], double* punteroDatos){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = *punteroDatos++;
        }
    }
}
void leerD2(double matrizuno[N][N], double matrizdos[N][N], double* punteroDatos){
    leerD(matrizuno, punteroDatos);
    leerD(matrizdos, punteroDatos + (N * N));
}
int main(void){
    int sum[N][N];
    int res[N][N];
    int mul[N][N];
    int ta[N][N];
    int tb[N][N];
    HANDLE memcom1;
    int* apDatos1;
    abrir("memComRes", memcom1);
    leer2(sum, res, mul, ta, tb, apDatos1);
    double ia[N][N];
    double ib[N][N];
    HANDLE memcom2;
    double* apDatos2;
    abrir2("memComInv", memcom2);
    leerD2(ia, ib, apDatos2);
    printf("\nResultado suma: \n");
    ImprimirMatriz(sum);
    printf("\nResultado resta: \n");
    ImprimirMatriz(res);
    printf("\nResultado multiplicacion: \n");
    ImprimirMatriz(mul);
    printf("\nResultado traspuesta uno: \n");
    ImprimirMatriz(ta);
    printf("\nResultado traspuesta dos: \n");
    ImprimirMatriz(tb);
    printf("\nResultado inversa uno: \n");
    ImprimirInversa(ia);
    printf("\nResultado inversa dos: \n");
    ImprimirInversa(ib);
    HANDLE semres;
    if ((semres = OpenSemaphore(SEMAPHORE_ALL_ACCESS , FALSE, "semRes1")) == NULL) {
        printf("Falla al invocar OpenSemaphore: %d\n", GetLastError());
        return -1;
    }
    if (!ReleaseSemaphore(semres, 1, NULL)) {
        printf("Falla al invocar ReleaseSemaphore: %d\n", GetLastError());
    }
    if ((semres = OpenSemaphore(SEMAPHORE_ALL_ACCESS , FALSE, "semRes2")) == NULL) {
        printf("Falla al invocar OpenSemaphore: %d\n", GetLastError());
        return -1;
    }
    if (!ReleaseSemaphore(semres, 1, NULL)) {
        printf("Falla al invocar ReleaseSemaphore: %d\n", GetLastError());
    }
    if ((semres = OpenSemaphore(SEMAPHORE_ALL_ACCESS , FALSE, "semRes3")) == NULL) {
        printf("Falla al invocar OpenSemaphore: %d\n", GetLastError());
        return -1;
    }
    if (!ReleaseSemaphore(semres, 1, NULL)) {
        printf("Falla al invocar ReleaseSemaphore: %d\n", GetLastError());
    }
    if ((semres = OpenSemaphore(SEMAPHORE_ALL_ACCESS , FALSE, "semRes4")) == NULL) {
        printf("Falla al invocar OpenSemaphore: %d\n", GetLastError());
        return -1;
    }
    if (!ReleaseSemaphore(semres, 1, NULL)) {
        printf("Falla al invocar ReleaseSemaphore: %d\n", GetLastError());
    }
    if ((semres = OpenSemaphore(SEMAPHORE_ALL_ACCESS , FALSE, "semRes5")) == NULL) {
        printf("Falla al invocar OpenSemaphore: %d\n", GetLastError());
        return -1;
    }
    if (!ReleaseSemaphore(semres, 1, NULL)) {
        printf("Falla al invocar ReleaseSemaphore: %d\n", GetLastError());
    }
    UnmapViewOfFile(apDatos1);
    CloseHandle(memcom1);
    UnmapViewOfFile(apDatos2);
    CloseHandle(memcom2);
    return 0;
}