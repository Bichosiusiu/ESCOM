#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define TAM_MEM (N * N * sizeof(int))
void LlenarMatriz(int matriz[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = rand() % 101; 
        }
    } }
void ImprimirMatriz(int matriz[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", matriz[i][j]); 
        }
        printf("\n"); 
    }
}
void impInversaArchivo(double matriz[N][N], FILE *archivo){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            fprintf(archivo, "%lf\t", matriz[i][j]);
        }
        fprintf(archivo, "\n");
    }
    fprintf(archivo, "\n");
}
void ImprimirInversa(double matriz[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
            printf("%lf  ", matriz[i][j]); 
        printf("\n"); 
    }
}
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
    } }
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
void EscribirMemoriaCompartida(int matriz[N][N], int* punteroDatos){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *punteroDatos++ = matriz[i][j];
        }
    }
}
void EscribirMemoriaCompartida2(int matrizA[N][N], int matrizB[N][N], int* punteroDatos){
    EscribirMemoriaCompartida(matrizA, punteroDatos);
    EscribirMemoriaCompartida(matrizB, punteroDatos + (N * N));
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
void LeerMemoriaCompartida2(int matrizA[N][N], int matrizB[N][N], int* punteroDatos){
    LeerMemoriaCompartida(matrizA, punteroDatos);
    LeerMemoriaCompartida(matrizB, punteroDatos + (N * N));
}
int main(int argc, char* argv[]){
    srand(time(NULL));
    int matrizA[N][N];
    int matrizB[N][N];
    LlenarMatriz(matrizA);
    LlenarMatriz(matrizB);
    printf("Matriz A:\n");
    ImprimirMatriz(matrizA);
    printf("\nMatriz B:\n");
    ImprimirMatriz(matrizB);
    int* apDatos;
    HANDLE MemCom1 = CrearMemoriaCompartidaDoble("MemCom1", &apDatos);
    EscribirMemoriaCompartida2(matrizA, matrizB, apDatos);
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    if (!CreateProcess(NULL, argv[1], NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)){
        printf("Fallo al invocar CreateProcess (%d)\n", GetLastError());
        return 1;
    }
    HANDLE semaforomat;
    if ((semaforomat = CreateSemaphore(NULL, 0, 1, "semaforomat")) == NULL) {
        printf("Falla al invocar CreateSemaphore: %d\n", GetLastError());
        return -1;
    }
    WaitForSingleObject(semaforomat, INFINITE);
    UnmapViewOfFile(apDatos);
    CloseHandle(MemCom1);
    HANDLE semaforores;
    if ((semaforores = CreateSemaphore(NULL, 0, 1, "semaforores")) == NULL) {
        printf("Falla al invocar CreateSemaphore: %d\n", GetLastError());
        return -1;
    }
    WaitForSingleObject(semaforores, INFINITE);
    int Resultado_multi[N][N];
    int Resultado_sum[N][N];
    HANDLE MemCom2;
    int* apDatos2;
    apDatos2 = AbrirMemoriaCompartida("MemCom2", MemCom2);
    LeerMemoriaCompartida2(Resultado_multi,Resultado_sum, apDatos2);
    UnmapViewOfFile(apDatos2);
    CloseHandle(MemCom2);
    printf("\nResultado de la suma:\n\n");
    ImprimirMatriz(Resultado_sum);
    printf("\nResultado de la multiplicacion:\n\n");
    ImprimirMatriz(Resultado_multi);
    HANDLE semaforores2;
    if ((semaforores2 = OpenSemaphore(SEMAPHORE_ALL_ACCESS , FALSE, "semaforores2")) == NULL) {
        printf("Falla al invocar OpenSemaphore: %d\n", GetLastError());
        return -1;
    }
    if (!ReleaseSemaphore(semaforores2, 1, NULL)) {
        printf("Falla al invocar ReleaseSemaphore: %d\n", GetLastError());
    }
    double Inversa_multi[N][N];
    double Inversa_sum[N][N];
    InversaMatriz(Resultado_multi, Inversa_multi);
    InversaMatriz(Resultado_sum, Inversa_sum);
    printf("\nInversa del resultado de la multiplicacion:\n\n");
    ImprimirInversa(Inversa_multi);
    FILE *archivo;
    archivo = fopen("inversaMul.txt", "w");
    if (!archivo) {
        printf("Error abriendo archivo para multiplicación.\n");
        return 1;
    }
    impInversaArchivo(Inversa_multi, archivo);
    fclose(archivo);
    printf("\nInversa del resultado de la suma:\n\n");
    ImprimirInversa(Inversa_sum);
    archivo = fopen("inversaSum.txt", "w");
    if (!archivo) {
        printf("Error abriendo archivo para suma.\n");
        return 1;
    }
    impInversaArchivo(Inversa_sum, archivo);
    fclose(archivo);
    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    return 0;
}

