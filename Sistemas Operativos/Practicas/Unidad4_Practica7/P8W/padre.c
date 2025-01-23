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
HANDLE CrearMemoriaCompartida(const char* nombre, int** punteroDatos){
    HANDLE hMemoria;
    if ((hMemoria = CreateFileMapping(
            INVALID_HANDLE_VALUE,
            NULL,
            PAGE_READWRITE,
            0,
            TAM_MEM,
            nombre
        )) == NULL) {
        printf("No se creó la memoria compartida: (%i)\n", GetLastError());
        exit(-1);
    }
    if ((*punteroDatos = (int*)MapViewOfFile(
            hMemoria,
            FILE_MAP_ALL_ACCESS,
            0,
            0,
            TAM_MEM
        )) == NULL) {
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
void EsperarMemoriaCompartida(const char* nombre, HANDLE* hMemCom){
    while ((*hMemCom = OpenFileMapping(
            FILE_MAP_ALL_ACCESS, 
            FALSE,               
            nombre
        )) == NULL) {
        Sleep(100); }
}
void LeerMemoriaCompartida(int matriz[N][N], int* punteroDatos){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = *punteroDatos++; 
        }
    }
}
int* MapearMemoriaCompartida(const char* nombre, HANDLE hMemCom){
    int* apDatos;
    if ((apDatos = (int *)MapViewOfFile(
            hMemCom,             
            FILE_MAP_ALL_ACCESS, 
            0,
            0,
            TAM_MEM
        )) == NULL) {
        printf("No se enlazó la memoria compartida: (%i)\n", GetLastError());
        CloseHandle(hMemCom);
        exit(-1);
    }
    return apDatos;
}
int main(int argc, char* argv[]){
    srand(time(NULL));
    int Matrizuno[N][N];
    int Matrizdos[N][N];
    LlenarMatriz(Matrizuno);
    LlenarMatriz(Matrizdos);
    printf("Matriz A:\n");
    ImprimirMatriz(Matrizuno);
    printf("\nMatriz B:\n");
    ImprimirMatriz(Matrizdos);
    int* apDatosUno;
    int* apDatosDos;
    HANDLE hMemComUno = CrearMemoriaCompartida("Memoria_Compartida_MU_PH", &apDatosUno);
    HANDLE hMemComDos = CrearMemoriaCompartida("Memoria_Compartida_MD_PH", &apDatosDos);
    EscribirMemoriaCompartida(Matrizuno, apDatosUno);
    EscribirMemoriaCompartida(Matrizdos, apDatosDos);
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    if (!CreateProcess(NULL, argv[1], NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)){
        printf("Fallo al invocar CreateProcess (%d)\n", GetLastError());
        return 1;
    }
    while (apDatosUno[0] != -1 && apDatosDos[0] != -1){
        Sleep(1);
    }
    UnmapViewOfFile(apDatosUno);
    UnmapViewOfFile(apDatosDos);
    CloseHandle(hMemComUno);
    CloseHandle(hMemComDos);
    HANDLE hMemComResmulti;
    int* apDatosResmulti;
    EsperarMemoriaCompartida("Memoria_Compartida_Res_Multi", &hMemComResmulti);
    apDatosResmulti = MapearMemoriaCompartida("Memoria_Compartida_Res_Multi", hMemComResmulti);
    int Resultado_multi[N][N];
    LeerMemoriaCompartida(Resultado_multi, apDatosResmulti);
    apDatosResmulti[0] = -1;
    UnmapViewOfFile(apDatosResmulti);
    CloseHandle(hMemComResmulti);
    HANDLE hMemComResum;
    int* apDatosResum;
    EsperarMemoriaCompartida("Memoria_Compartida_Res_Sum", &hMemComResum);
    apDatosResum = MapearMemoriaCompartida("Memoria_Compartida_Res_Sum", hMemComResum);
    int Resultado_sum[N][N];
    LeerMemoriaCompartida(Resultado_sum, apDatosResum);
    apDatosResum[0] = -1;
    UnmapViewOfFile(apDatosResum);
    CloseHandle(hMemComResum);
    double InversaMul[N][N],InversaS[N][N];
    printf("\n\nInversa de la multiplicacion:\n");    
    InversaMatriz(Resultado_multi,InversaMul);
    ImprimirInversa(InversaMul);
    printf("\n\nInversa de la suma:\n");
    InversaMatriz(Resultado_sum,InversaS);
    ImprimirInversa(InversaS);
    FILE *archivo;
    archivo = fopen("inversaMul.txt", "w");
    if (!archivo) {
        printf("Error abriendo archivo para multiplicación.\n");
        return 1;
    }
    impInversaArchivo(InversaMul, archivo);
    fclose(archivo);
    archivo = fopen("inversaSum.txt", "w");
    if (!archivo) {
        printf("Error abriendo archivo para suma.\n");
        return 1;
    }
    impInversaArchivo(InversaS, archivo);
    fclose(archivo);
    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    return 0;
}

