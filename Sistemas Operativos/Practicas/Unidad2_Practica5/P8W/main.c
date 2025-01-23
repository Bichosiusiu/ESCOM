#include <windows.h> 
#include <stdio.h> 
#include <time.h>
#define N 10
void imprimirMatriz(int A[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d\t",A[i][j]);
        }
        printf("\n");
    }
}
void StringMatriz(int Matrizuno[N][N], char str[N*N*10]){
    str[0] = '\0'; 
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            sprintf(str + strlen(str), " %d", Matrizuno[i][j]); 
        }
    }
}
int main() {
    STARTUPINFO si; 
    PROCESS_INFORMATION pi;
    srand(time(NULL));
    int A[N][N], B[N][N];
    double resultado[N][N];  
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 101; 
            B[i][j] = rand() % 101; 
        }
    }
    printf("\nMatriz A:\n");
    imprimirMatriz(A);
    printf("\nMatriz B:\n");
    imprimirMatriz(B);
    char Matriz1[N*N*10];
    char Matriz2[N*N*10];
    char comando[N*N*10];
    StringMatriz(A, Matriz1);
    StringMatriz(B, Matriz2);
    for (int i = 0; i <= 5; i++) {
        ZeroMemory(&si, sizeof(si)); 
        si.cb = sizeof(si); 
        ZeroMemory(&pi, sizeof(pi));
            switch (i) {
                case 0: 
                    sprintf(comando, "%s \"%s\" \"%s\"", "suma", Matriz1, Matriz2); 
                    if (!CreateProcess(NULL, comando, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
                        printf("Fallo al invocar CreateProcess (%d)\n", GetLastError()); 
                        return 1; 
                    }
                    break;
                case 1: 
                    sprintf(comando, "%s \"%s\" \"%s\"", "resta", Matriz1, Matriz2); 
                    if (!CreateProcess(NULL, comando, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
                        printf("Fallo al invocar CreateProcess (%d)\n", GetLastError()); 
                        return 1; 
                    }
                    break;
                case 2: 
                    sprintf(comando, "%s \"%s\" \"%s\"", "multiplicacion", Matriz1, Matriz2); 
                    if (!CreateProcess(NULL, comando, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
                        printf("Fallo al invocar CreateProcess (%d)\n", GetLastError()); 
                        return 1; 
                    }
                    break;
                case 3: 
                    sprintf(comando, "%s \"%s\" \"%s\"", "transpuesta", Matriz1, Matriz2); 
                    if (!CreateProcess(NULL, comando, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
                        printf("Fallo al invocar CreateProcess (%d)\n", GetLastError()); 
                        return 1; 
                    }
                    break;
                case 4: 
                    sprintf(comando, "%s \"%s\" \"%s\"", "inversa", Matriz1, Matriz2); 
                    if (!CreateProcess(NULL, comando, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
                        printf("Fallo al invocar CreateProcess (%d)\n", GetLastError()); 
                        return 1; 
                    }
                    break;
                case 5:
                    sprintf(comando, "archivo"); 
                    if (!CreateProcess(NULL, comando, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
                        printf("Fallo al invocar CreateProcess (%d)\n", GetLastError()); 
                        return 1; 
                    }
                    break;
            }
        WaitForSingleObject(pi.hProcess, INFINITE); 
        CloseHandle(pi.hProcess); 
        CloseHandle(pi.hThread); 
        }
    return 0;
}
