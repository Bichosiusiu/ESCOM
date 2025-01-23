#include <windows.h>
#include <stdio.h>
#include <string.h>
#define N 10
void multiplicacion(int matrizuno[N][N], int matrizdos[N][N], int resultado[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            resultado[i][j] = 0; 
            for (int k = 0; k < N; k++){
                resultado[i][j] += matrizuno[i][k] * matrizdos[k][j]; 
            }
        }
    }
}
int main(){
    HANDLE lecturaPipe = GetStdHandle(STD_INPUT_HANDLE);
    DWORD lectura;
    HANDLE escrituraPipe = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD escritura;
    HANDLE lectura1, escritura1;
    HANDLE lecturaO, escrituraO;
    SECURITY_ATTRIBUTES pipeSeg = { sizeof(SECURITY_ATTRIBUTES), NULL, TRUE };
    STARTUPINFO sHijo;
    PROCESS_INFORMATION pHijo;
    CreatePipe(&lectura1, &escritura1, &pipeSeg, 0);
    CreatePipe(&lecturaO, &escrituraO, &pipeSeg, 0);
    int MatrizA[N][N];
    int MatrizB[N][N];
    ReadFile(lecturaPipe, MatrizA, sizeof(MatrizA), &lectura, NULL);
    ReadFile(lecturaPipe, MatrizB, sizeof(MatrizB), &lectura, NULL);
    int Resultado[N][N];
    multiplicacion(MatrizA, MatrizB, Resultado);
    WriteFile(escrituraPipe, Resultado, sizeof(Resultado), &escritura, NULL);
    GetStartupInfo(&sHijo);
    WriteFile(escritura1, MatrizA, sizeof(MatrizA), &escritura, NULL);
    WriteFile(escritura1, MatrizB, sizeof(MatrizB), &escritura, NULL);
    sHijo.hStdInput = lectura1;
    sHijo.hStdError = GetStdHandle(STD_ERROR_HANDLE);
    sHijo.hStdOutput = escrituraO;
    sHijo.dwFlags = STARTF_USESTDHANDLES;
    CreateProcess(NULL, "nieto", NULL, NULL, TRUE, 0, NULL, NULL, &sHijo, &pHijo);
    WaitForSingleObject(pHijo.hProcess, INFINITE);
    ReadFile(lecturaO, Resultado, sizeof(Resultado), &lectura, NULL);
    WriteFile(escrituraPipe, Resultado, sizeof(Resultado), &escritura, NULL);
    CloseHandle(lecturaPipe); 
    CloseHandle(escrituraPipe);
    CloseHandle(lectura1);
    CloseHandle(lecturaO);
    CloseHandle(escritura1);
    CloseHandle(escrituraO);
    return 0;
}
