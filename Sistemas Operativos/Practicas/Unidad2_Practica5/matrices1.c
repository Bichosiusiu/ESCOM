#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

#define N 10
void imprimirMatriz(int A[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d\t",A[i][j]);
        }
        printf("\n");
    }
}
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
void leerYMostrarMatriz(char *nombre_archivo) {
    FILE *archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        exit(1);
    }
    double valor;  
    int cont=0;
    while (fscanf(archivo, "%lf", &valor) != EOF) {  
        if(cont == 10){
            printf("\n");
            cont=0;
        }
        printf("%.2f ", valor);  
        cont ++;
    }
    printf("\n");
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

int main() {
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
        sumarMatrices(A, B, resultado);
        escribirMatriz("suma.txt", resultado);
        restarMatrices(A, B, resultado);
        escribirMatriz("resta.txt", resultado);
        multiplicarMatrices(A, B, resultado);
        escribirMatriz("multiplicacion.txt", resultado);
        transponerMatriz(A, resultado);
        escribirMatriz("transpuesta_A.txt", resultado);
        transponerMatriz(B, resultado);
        escribirMatriz("transpuesta_B.txt", resultado);
        double Inversauno[N][N];
        double Inversados[N][N];
        InversaMatriz(A, Inversauno);
        InversaMatriz(B, Inversados);
        escribirMatriz("inversa_A.txt", Inversauno); 
        escribirMatriz("inversa_B.txt", Inversados); 
        printf("\nResultados de la suma:\n");
        leerYMostrarMatriz("suma.txt");
        printf("\nResultados de la resta:\n");
        leerYMostrarMatriz("resta.txt");
        printf("\nResultados de la multiplicación:\n");
        leerYMostrarMatriz("multiplicacion.txt");
        printf("\nTranspuesta de la matriz A:\n");
        leerYMostrarMatriz("transpuesta_A.txt");
        printf("\nTranspuesta de la matriz B:\n");
        leerYMostrarMatriz("transpuesta_B.txt");
        printf("\nInversa de la matriz A:\n");
        leerYMostrarMatriz("inversa_A.txt");
        printf("\nInversa de la matriz B:\n");
        leerYMostrarMatriz("inversa_B.txt");
    return 0;
}
