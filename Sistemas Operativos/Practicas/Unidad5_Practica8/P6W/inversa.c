#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#define N 10
#define TAM_MEM (2 * N * N * sizeof(int))
#define TAM_MEM2 (2 * N * N * sizeof(double))
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
HANDLE crearMemoriaD(const char* nombre, double** punteroDatos){
    HANDLE hMemoria;
    if ((hMemoria = CreateFileMapping(INVALID_HANDLE_VALUE,NULL,PAGE_READWRITE,0,TAM_MEM2,nombre)) == NULL) {
        printf("No se creó la memoria compartida: (%i)\n", GetLastError());
        exit(-1);
    }
    if ((*punteroDatos = (double*)MapViewOfFile(hMemoria,FILE_MAP_ALL_ACCESS,0,0,TAM_MEM2)) == NULL) {
        printf("No se enlazó la memoria compartida: (%i)\n", GetLastError());
        CloseHandle(hMemoria);
        exit(-1);
    }
    return hMemoria;
}
void escribirMemoria(double matriz[N][N], double* punteroDatos){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *punteroDatos++ = matriz[i][j]; 
        }
    }
}
void escribirMemoria2(double matrizuno[N][N], double matrizdos[N][N], double* punteroDatos){
    escribirMemoria(matrizuno, punteroDatos);
    escribirMemoria(matrizdos, punteroDatos + (N * N));
}
void leerMemoria(int matriz[N][N], int* punteroDatos){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = *punteroDatos++;
        }
    }
}
void leerMemoria2(int matrizuno[N][N], int matrizdos[N][N], int* punteroDatos){
    leerMemoria(matrizuno, punteroDatos);
    leerMemoria(matrizdos, punteroDatos + (N * N));
}
int main(void){
    int Matrizuno[N][N];
    int Matrizdos[N][N];
    HANDLE memcom1;
    int* apDatos1;
    apDatos1 = abrir("MemCom1", memcom1);
    leerMemoria2(Matrizuno, Matrizdos, apDatos1);
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
    double Inversa_uno[N][N];
    double Inversa_dos[N][N];
    InversaMatriz(Matrizuno, Inversa_uno);
    InversaMatriz(Matrizdos, Inversa_dos);
    double* apDatos2;
    HANDLE hMemComResInversas = crearMemoriaD("memComInv", &apDatos2);
    escribirMemoria2(Inversa_uno, Inversa_dos, apDatos2);
    HANDLE semres;
    if ((semres = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, "semRes")) == NULL) {
        printf("Falla al invocar OpenSemaphore: %d\n", GetLastError());
        return -1;
    }
    if (!ReleaseSemaphore(semres, 1, NULL)) {
        printf("Falla al invocar ReleaseSemaphore: %d\n", GetLastError());
    }
    HANDLE seminv;
    if ((seminv = CreateSemaphore(NULL, 0, 1, "semInv")) == NULL) {
        printf("Falla al invocar CreateSemaphore: %d\n", GetLastError());
        return -1;}
    WaitForSingleObject(seminv, INFINITE);
    UnmapViewOfFile(hMemComResInversas);
    CloseHandle(apDatos2);
    return 0;
}