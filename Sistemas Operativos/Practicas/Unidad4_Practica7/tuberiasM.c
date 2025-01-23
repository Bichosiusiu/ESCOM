#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#define N 10
void imprimirMatriz(double A[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%.2lf\t",A[i][j]);
        }
        printf("\n");
    } }
void imprimirMatrizI(int A[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d\t",A[i][j]);
        }
        printf("\n");
    } }
void escribirMatriz(char *nombre_archivo, double matriz[N][N]) {
    FILE *archivo = fopen(nombre_archivo, "w");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        exit(1);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fprintf(archivo, "%.2f ", matriz[i][j]); 
        }
        fprintf(archivo, "\n");
    }
    fclose(archivo);
}
void sumarMatrices(int A[N][N], int B[N][N], double resultado[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            resultado[i][j] = A[i][j] + B[i][j];
        }
    }
}
void restarMatrices(int A[N][N], int B[N][N], double resultado[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            resultado[i][j] = A[i][j] - B[i][j];
        }
    }
}
void multiplicarMatrices(int A[N][N], int B[N][N], double resultado[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            resultado[i][j] = 0; 
            for (int k = 0; k < N; k++) {
                resultado[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
void transponerMatriz(int matriz[N][N], double resultado[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            resultado[j][i] = matriz[i][j]; 
        }
    }
}
void Cofactor(int matriz[N][N], int temp[N][N], int p, int q, int n) {
    int i = 0, j = 0;
    for (int fila = 0; fila < n; fila++) {
        for (int col = 0; col < n; col++) {
            if (fila != p && col != q) {
                temp[i][j++] = matriz[fila][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}
int DeterminanteMatriz(int matriz[N][N], int n) {
    int determinante = 0;
    if (n == 1) 
        return matriz[0][0];

    int temp[N][N];
    int signo = 1;
    for (int f = 0; f < n; f++) {
        Cofactor(matriz, temp, 0, f, n);
        determinante += signo * matriz[0][f] * DeterminanteMatriz(temp, n - 1);
        signo = -signo;
    }
    return determinante;
}
void AdjuntaMatriz(int matriz[N][N], double adjunta[N][N], int n) {
    if (n == 1) {
        adjunta[0][0] = 1; 
        return;
    }

    int temp[N][N];
    int signo = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Cofactor(matriz, temp, i, j, n); 
            signo = ((i + j) % 2 == 0) ? 1 : -1; 
            adjunta[j][i] = (signo) * (DeterminanteMatriz(temp, n - 1)); 
        }
    }
}
void InversaMatriz(int matriz[N][N], double inversa[N][N]) {
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
int main(){
    srand(time(NULL));
    int tubSum[2];
    int tubRes[2];
    int tubMul[2];
    int tubTras[2];
    int tubInv[2];
    if (pipe(tubSum) != 0 || pipe(tubRes) != 0 || pipe(tubMul) != 0 || pipe(tubTras) != 0 || pipe(tubInv) != 0){
        exit(1);
    }
    int A[N][N], B[N][N];
    double resultado[N][N];  
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 101; 
            B[i][j] = rand() % 101; 
        }
    }
    printf("\nMatriz A:\n");
    imprimirMatrizI(A);
    printf("\nMatriz B:\n");
    imprimirMatrizI(B);
    pid_t pid;
    for (int i = 1; i <= 6; i++) {
        pid = fork();
        if (pid == 0) { 
            switch (i) {
                case 1: 
                    sumarMatrices(A, B, resultado);
                    escribirMatriz("suma.txt", resultado);
                    write(tubSum[1], resultado, sizeof(resultado));
                    break;
                case 2: 
                    restarMatrices(A, B, resultado);
                    escribirMatriz("resta.txt", resultado);
                    write(tubRes[1], resultado, sizeof(resultado));
                    break;
                case 3: 
                    multiplicarMatrices(A, B, resultado);
                    escribirMatriz("multiplicacion.txt", resultado);
                    write(tubMul[1], resultado, sizeof(resultado));
                    break;
                case 4: 
                    transponerMatriz(A, resultado);
                    escribirMatriz("transpuesta_A.txt", resultado);
                    write(tubTras[1], resultado, sizeof(resultado));
                    transponerMatriz(B, resultado);
                    escribirMatriz("transpuesta_B.txt", resultado);
                    write(tubTras[1], resultado, sizeof(resultado));
                    break;
                case 5: 
                    double Inversauno[N][N];
                    double Inversados[N][N];
                    InversaMatriz(A, Inversauno);
                    InversaMatriz(B, Inversados);
                    escribirMatriz("inversa_A.txt", Inversauno); 
                    escribirMatriz("inversa_B.txt", Inversados); 
                    write(tubInv[1], Inversauno, sizeof(Inversauno));
                    write(tubInv[1], Inversados, sizeof(Inversados));
                    break;
                case 6:
                    printf("\nResultados de la suma:\n");
                    read(tubSum[0], resultado, sizeof(resultado));
                    imprimirMatriz(resultado);
                    printf("\nResultados de la resta:\n");
                    read(tubRes[0], resultado, sizeof(resultado));
                    imprimirMatriz(resultado);
                    printf("\nResultados de la multiplicación:\n");
                    read(tubMul[0], resultado, sizeof(resultado));
                    imprimirMatriz(resultado);
                    printf("\nTranspuesta de la matriz A:\n");
                    read(tubTras[0], resultado, sizeof(resultado));
                    imprimirMatriz(resultado);
                    printf("\nTranspuesta de la matriz B:\n");
                    read(tubTras[0], resultado, sizeof(resultado));
                    imprimirMatriz(resultado);
                    printf("\nInversa de la matriz A:\n");
                    read(tubInv[0], resultado, sizeof(resultado));
                    imprimirMatriz(resultado);
                    printf("\nInversa de la matriz B:\n");
                    read(tubInv[0], resultado, sizeof(resultado));
                    imprimirMatriz(resultado);
                    break;
            }
            exit(0); 
        }
        else{
            wait(NULL);
        }
    }
    for (int i = 1; i <= 6; i++) {
        wait(NULL);
    }
    return 0;
} 