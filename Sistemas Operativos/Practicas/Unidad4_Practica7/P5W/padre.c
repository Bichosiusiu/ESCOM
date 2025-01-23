#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define N 10
void llenar(int matriz[N][N]){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = rand() % 101;
        }
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
void imprimir(int matriz[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            printf("%d\t", matriz[i][j]); 
        }
        printf("\n"); 
    }
}
void impInversa(double matriz[N][N]){
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
                if (j == n - 1) {
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
void inversa(int matriz[N][N], double inversa[N][N]){
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
int main(int argc, char *argv[]) {
    srand(time(NULL));
    int MatrizA[N][N], MatrizB[N][N];
    llenar(MatrizA);
    llenar(MatrizB);
    printf("Matriz A:\n");
    imprimir(MatrizA);
    printf("\nMatriz B:\n");
    imprimir(MatrizB);
    HANDLE lectura1, escritura1;
    HANDLE lecturaO, escrituraO;
    SECURITY_ATTRIBUTES pipeSeg = {sizeof(SECURITY_ATTRIBUTES), NULL, TRUE};
    DWORD bytesEscritos, bytesLeidos;
    if (!CreatePipe(&lectura1, &escritura1, &pipeSeg, 0)) {
        printf("Error creando pipe para entrada.\n");
        return 1;
    }
    if (!CreatePipe(&lecturaO, &escrituraO, &pipeSeg, 0)) {
        printf("Error creando pipe para salida.\n");
        return 1;
    }
    STARTUPINFO sHijo = {0};
    PROCESS_INFORMATION pHijo = {0};
    sHijo.cb = sizeof(STARTUPINFO);
    sHijo.hStdInput = lectura1;
    sHijo.hStdOutput = escrituraO;
    sHijo.hStdError = GetStdHandle(STD_ERROR_HANDLE);
    sHijo.dwFlags = STARTF_USESTDHANDLES;
    if (!WriteFile(escritura1, MatrizA, sizeof(MatrizA), &bytesEscritos, NULL)) {
        printf("Error escribiendo matriz A.\n");
        return 1;
    }
    if (!WriteFile(escritura1, MatrizB, sizeof(MatrizB), &bytesEscritos, NULL)) {
        printf("Error escribiendo matriz B.\n");
        return 1;
    }
    if (!CreateProcess(NULL, argv[1], NULL, NULL, TRUE, 0, NULL, NULL, &sHijo, &pHijo)) {
        printf("Error creando proceso hijo.\n");
        return 1;
    }
    WaitForSingleObject(pHijo.hProcess, INFINITE);
    int resultado[N][N];
    double inversa1[N][N];
    FILE *archivo;
    if (!ReadFile(lecturaO, resultado, sizeof(resultado), &bytesLeidos, NULL)) {
        printf("Error leyendo resultado de la multiplicación.\n");
        return 1;
    }
    inversa(resultado, inversa1);
    printf("\nInversa de la Multiplicacion:\n");
    impInversa(inversa1);
    archivo = fopen("inversaMul.txt", "w");
    if (!archivo) {
        printf("Error abriendo archivo para multiplicación.\n");
        return 1;
    }
    impInversaArchivo(inversa1, archivo);
    fclose(archivo);
    if (!ReadFile(lecturaO, resultado, sizeof(resultado), &bytesLeidos, NULL)) {
        printf("Error leyendo resultado de la suma.\n");
        return 1;
    }
    inversa(resultado, inversa1);
    printf("Inversa de la Suma:\n");
    impInversa(inversa1);
    archivo = fopen("inversaSum.txt", "w");
    if (!archivo) {
        printf("Error abriendo archivo para suma.\n");
        return 1;
    }
    impInversaArchivo(inversa1, archivo);
    fclose(archivo);
    CloseHandle(lectura1);
    CloseHandle(escritura1);
    CloseHandle(lecturaO);
    CloseHandle(escrituraO);
    CloseHandle(pHijo.hThread);
    CloseHandle(pHijo.hProcess);
    return 0;
}
