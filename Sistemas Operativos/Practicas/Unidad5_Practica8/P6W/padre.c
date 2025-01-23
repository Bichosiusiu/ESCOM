#include <windows.h> 
#include <stdio.h> 
#include <time.h>
#define N 10
#define TAM_MEM (2 * N * N * sizeof(int))
void LlenarMatriz(int matriz[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = rand() % 101;
        }
    }
}
void ImprimirMatriz(int matriz[N][N]){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", matriz[i][j]); 
        }
        printf("\n");
    }
}
HANDLE CrearMemoriaCompartida(const char* nombre, int** punteroDatos){
    HANDLE hMemoria;
    if ((hMemoria = CreateFileMapping(INVALID_HANDLE_VALUE,NULL,PAGE_READWRITE,0,TAM_MEM,nombre)) == NULL) {
        printf("No se creó la memoria compartida: (%i)\n", GetLastError());
        exit(-1);
    }
    if ((*punteroDatos = (int*)MapViewOfFile(hMemoria,FILE_MAP_ALL_ACCESS,0,0,TAM_MEM)) == NULL) {
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
void escribirMemoria2(int matrizuno[N][N], int matrizdos[N][N], int* punteroDatos){
    EscribirMemoriaCompartida(matrizuno, punteroDatos);
    EscribirMemoriaCompartida(matrizdos, punteroDatos + (N * N));
}
int main(int argc, char *argv[]) { 
    srand(time(NULL));
    int Matrizuno[N][N];
    int Matrizdos[N][N];
    LlenarMatriz(Matrizuno);
    LlenarMatriz(Matrizdos);
    printf("Matriz A:\n");
    ImprimirMatriz(Matrizuno);
    printf("\nMatriz B:\n");
    ImprimirMatriz(Matrizdos);
    int* apDatos1;
    HANDLE memCom1 = CrearMemoriaCompartida("MemCom1", &apDatos1);
    escribirMemoria2(Matrizuno, Matrizdos, apDatos1);
    HANDLE semRes;
    if ((semRes = CreateSemaphore(NULL, 0, 1 , "semRes")) == NULL) {
        printf("Falla al invocar CreateSemaphore: %d\n", GetLastError());
        return -1;
    }
    STARTUPINFO si[6]; 
    PROCESS_INFORMATION pi[6]; 
    HANDLE handles[6];
    for (int j = 1; j <= 6; j++){
        ZeroMemory(&si[j-1], sizeof(si[j-1]));
        si[j-1].cb = sizeof(si[j-1]);
        ZeroMemory(&pi[j-1], sizeof(pi[j-1]));
        escribirMemoria2(Matrizuno, Matrizdos, apDatos1);
        switch (j){
            case 1:
                if(!CreateProcess(NULL, "sum", NULL, NULL, FALSE, 0, NULL, NULL, &si[j-1], &pi[j-1])) { 
                    printf("Fallo al invocar CreateProcess (%d)\n", GetLastError()); 
                    return 1; 
                }
                break;
            case 2:
                if(!CreateProcess(NULL, "res", NULL, NULL, FALSE, 0, NULL, NULL, &si[j-1], &pi[j-1])) { 
                    printf("Fallo al invocar CreateProcess (%d)\n", GetLastError()); 
                    return 1; 
                }
                break;
            case 3:
                if(!CreateProcess(NULL, "mul", NULL, NULL, FALSE, 0, NULL, NULL, &si[j-1], &pi[j-1])) { 
                    printf("Fallo al invocar CreateProcess (%d)\n", GetLastError()); 
                    return 1; 
                }
                break;
            case 4:
                if(!CreateProcess(NULL, "tra", NULL, NULL, FALSE, 0, NULL, NULL, &si[j-1], &pi[j-1])) { 
                    printf("Fallo al invocar CreateProcess (%d)\n", GetLastError()); 
                    return 1; 
                }
                break;
            case 5:
                if(!CreateProcess(NULL, "inv", NULL, NULL, FALSE, 0, NULL, NULL, &si[j-1], &pi[j-1])) { 
                    printf("Fallo al invocar CreateProcess (%d)\n", GetLastError()); 
                    return 1; 
                }
                break;
            case 6:
                WaitForSingleObject(semRes, INFINITE);
                if(!CreateProcess(NULL, "col", NULL, NULL, FALSE, 0, NULL, NULL, &si[j-1], &pi[j-1])) { 
                    printf("Fallo al invocar CreateProcess (%d)\n", GetLastError()); 
                    return 1; 
                }
                break;
        }
        if (j < 6){
            HANDLE semMat;
            if ((semMat = CreateSemaphore(NULL, 0, 1, "semMat")) == NULL) {
                printf("Falla al invocar CreateSemaphore: %d\n", GetLastError());
                return -1;
            }
            WaitForSingleObject(semMat, INFINITE);
            CloseHandle(semMat);
        }
        handles[j-1] = pi[j-1].hProcess;
    }
    UnmapViewOfFile(apDatos1);
    CloseHandle(memCom1);
    WaitForMultipleObjects(6, handles, TRUE, INFINITE);
    for (int j = 0; j < 6; j++) {
        CloseHandle(pi[j].hProcess);
        CloseHandle(pi[j].hThread);
    }
    return 0; 
}
