#include <windows.h>
#include <stdio.h>
#include <time.h>
#define N 10
#define OPERACIONES 5
void llenar(int matriz[N][N]) {
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            matriz[i][j] = rand() % 101; 
        }
    }
}
void imprimir(int matriz[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            printf("%d\t", matriz[i][j]); 
        }
        printf("\n");
    }
}
void imprimirInversa(double matriz[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
            printf("%lf  ", matriz[i][j]); 
        printf("\n");
    }
}
int main(int argc, char *argv[]){
    int i, j;
    srand(time(NULL));
    int matrizA[N][N];
    int matrizB[N][N];
    llenar(matrizA);
    llenar(matrizB);
    printf("\nMatriz A: \n");
    imprimir(matrizA);
    printf("\nMatriz B: \n");
    imprimir(matrizB);
    HANDLE lecturaI, escrituraI;
    SECURITY_ATTRIBUTES pipeSeg = { sizeof(SECURITY_ATTRIBUTES), NULL, TRUE };
    DWORD escritos;
    STARTUPINFO sHijo;
    PROCESS_INFORMATION pHijo;
    GetStartupInfo(&sHijo);
    HANDLE lecturaO, escrituraO;
    DWORD lectura;
    sHijo.hStdError = GetStdHandle(STD_ERROR_HANDLE);
    sHijo.dwFlags = STARTF_USESTDHANDLES;
    int resultados[OPERACIONES][N][N];
    double resultadosInv[2][N][N]; 
    int indiceResultado = 0;
    for (j = 1; j <= 6; j++){
        int resultado1[N][N], resultado2[N][N];
        double inversa1[N][N], inversa2[N][N];
        CreatePipe(&lecturaI, &escrituraI, &pipeSeg, 0);
        CreatePipe(&lecturaO, &escrituraO, &pipeSeg, 0);
        sHijo.hStdInput = lecturaI;
        sHijo.hStdOutput = escrituraO;
        switch (j){
            case 1:
                CreateProcess(NULL, "sum.exe", NULL, NULL, TRUE, 0, NULL, NULL, &sHijo, &pHijo);
                WriteFile(escrituraI, matrizA, sizeof(matrizA), &escritos, NULL);
                WriteFile(escrituraI, matrizB, sizeof(matrizB), &escritos, NULL);
                ReadFile(lecturaO, resultado1, sizeof(resultado1), &lectura, NULL);
                memcpy(resultados[indiceResultado++], resultado1, sizeof(resultado1));
                break;
            case 2:
                CreateProcess(NULL, "res.exe", NULL, NULL, TRUE, 0, NULL, NULL, &sHijo, &pHijo);
                WriteFile(escrituraI, matrizA, sizeof(matrizA), &escritos, NULL);
                WriteFile(escrituraI, matrizB, sizeof(matrizB), &escritos, NULL);
                ReadFile(lecturaO, resultado1, sizeof(resultado1), &lectura, NULL);
                memcpy(resultados[indiceResultado++], resultado1, sizeof(resultado1));
                break;
            case 3:
                CreateProcess(NULL, "mul.exe", NULL, NULL, TRUE, 0, NULL, NULL, &sHijo, &pHijo);
                WriteFile(escrituraI, matrizA, sizeof(matrizA), &escritos, NULL);
                WriteFile(escrituraI, matrizB, sizeof(matrizB), &escritos, NULL);
                ReadFile(lecturaO, resultado1, sizeof(resultado1), &lectura, NULL);
                memcpy(resultados[indiceResultado++], resultado1, sizeof(resultado1));
                break;
            case 4:
                CreateProcess(NULL, "tra.exe", NULL, NULL, TRUE, 0, NULL, NULL, &sHijo, &pHijo);
                WriteFile(escrituraI, matrizA, sizeof(matrizA), &escritos, NULL);
                WriteFile(escrituraI, matrizB, sizeof(matrizB), &escritos, NULL);
                ReadFile(lecturaO, resultado1, sizeof(resultado1), &lectura, NULL);
                ReadFile(lecturaO, resultado2, sizeof(resultado2), &lectura, NULL);
                memcpy(resultados[indiceResultado++], resultado1, sizeof(resultado1));
                memcpy(resultados[indiceResultado++], resultado2, sizeof(resultado2));
                break;
            case 5:
                CreateProcess(NULL, "inv.exe", NULL, NULL, TRUE, 0, NULL, NULL, &sHijo, &pHijo);
                WriteFile(escrituraI, matrizA, sizeof(matrizA), &escritos, NULL);
                WriteFile(escrituraI, matrizB, sizeof(matrizB), &escritos, NULL);
                ReadFile(lecturaO, inversa1, sizeof(inversa1), &lectura, NULL);
                ReadFile(lecturaO, inversa2, sizeof(inversa2), &lectura, NULL);
                memcpy(resultadosInv[0], inversa1, sizeof(inversa1));
                memcpy(resultadosInv[1], inversa2, sizeof(inversa2));
            case 6:
                sHijo.hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
                CreateProcess(NULL, "col.exe", NULL, NULL, TRUE, 0, NULL, NULL, &sHijo, &pHijo);
                for(i = 0; i < indiceResultado; i++){
                    WriteFile(escrituraI, resultados[i], sizeof(resultados[i]), &escritos, NULL);
                }
                WriteFile(escrituraI, resultadosInv[0], sizeof(resultadosInv[0]), &escritos, NULL);
                WriteFile(escrituraI, resultadosInv[1], sizeof(resultadosInv[1]), &escritos, NULL);
                WaitForSingleObject(pHijo.hProcess, INFINITE);
                break;
        }
    }
    CloseHandle(pHijo.hProcess);
    CloseHandle(pHijo.hThread);
    CloseHandle(lecturaI);
    CloseHandle(escrituraI);
    CloseHandle(lecturaO);
    CloseHandle(escrituraO);
    return 0;
}