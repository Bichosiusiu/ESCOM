#include <windows.h> 
#include <stdio.h> 
#include <time.h>
#define N 10
#define TAM_MEM (N * N * sizeof(int))
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
    STARTUPINFO si[6]; 
    PROCESS_INFORMATION pi[6]; 
    HANDLE handles[6];
    for (int j = 1; j <= 6; j++){
        ZeroMemory(&si[j-1], sizeof(si[j-1]));
        si[j-1].cb = sizeof(si[j-1]);
        ZeroMemory(&pi[j-1], sizeof(pi[j-1]));
        int* apDatosUno;
        int* apDatosDos;
        HANDLE hMemComUno = CrearMemoriaCompartida("Memoria_Compartida_MU_PH", &apDatosUno);
        HANDLE hMemComDos = CrearMemoriaCompartida("Memoria_Compartida_MD_PH", &apDatosDos);
        EscribirMemoriaCompartida(Matrizuno, apDatosUno);
        EscribirMemoriaCompartida(Matrizdos, apDatosDos);
        switch (j){
            case 1:
                if(!CreateProcess(NULL, "sum", NULL, NULL, FALSE, 0, NULL, NULL, &si[j-1], &pi[j-1])) { 
                    printf("Fallo al invocar CreateProcess (%d)\n", GetLastError()); 
                    return 1; 
                }
                while (apDatosUno[0] != -1 && apDatosDos[0] != -1){
                    Sleep(1);
                }
                break;
            case 2:
                if(!CreateProcess(NULL, "res", NULL, NULL, FALSE, 0, NULL, NULL, &si[j-1], &pi[j-1])) { 
                    printf("Fallo al invocar CreateProcess (%d)\n", GetLastError()); 
                    return 1; 
                }
                while (apDatosUno[0] != -1 && apDatosDos[0] != -1){
                    Sleep(1);
                }
                break;
            case 3:
                if(!CreateProcess(NULL, "mul", NULL, NULL, FALSE, 0, NULL, NULL, &si[j-1], &pi[j-1])) { 
                    printf("Fallo al invocar CreateProcess (%d)\n", GetLastError()); 
                    return 1; 
                }
                while (apDatosUno[0] != -1 && apDatosDos[0] != -1){
                    Sleep(1);
                }
                break;
            case 4:
                if(!CreateProcess(NULL, "tra", NULL, NULL, FALSE, 0, NULL, NULL, &si[j-1], &pi[j-1])) { 
                    printf("Fallo al invocar CreateProcess (%d)\n", GetLastError()); 
                    return 1; 
                }
                while (apDatosUno[0] != -1 && apDatosDos[0] != -1){
                    Sleep(1);
                }
                break;
            case 5:
                if(!CreateProcess(NULL, "inv", NULL, NULL, FALSE, 0, NULL, NULL, &si[j-1], &pi[j-1])) { 
                    printf("Fallo al invocar CreateProcess (%d)\n", GetLastError()); 
                    return 1; 
                }
                while (apDatosUno[0] != -1 && apDatosDos[0] != -1){
                    Sleep(1);
                }
                break;
            case 6:
                if(!CreateProcess(NULL, "col", NULL, NULL, FALSE, 0, NULL, NULL, &si[j-1], &pi[j-1])) { 
                    printf("Fallo al invocar CreateProcess (%d)\n", GetLastError()); 
                    return 1; 
                }
                break;
        }
        handles[j-1] = pi[j-1].hProcess;
        UnmapViewOfFile(apDatosUno);
        UnmapViewOfFile(apDatosDos);
        CloseHandle(hMemComUno);
        CloseHandle(hMemComDos);
    }
    WaitForMultipleObjects(6, handles, TRUE, INFINITE);
    for (int j = 0; j < 6; j++) {
        CloseHandle(pi[j].hProcess);
        CloseHandle(pi[j].hThread);
    }
    return 0; 
}
