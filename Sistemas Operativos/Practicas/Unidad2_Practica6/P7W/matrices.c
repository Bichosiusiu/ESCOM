#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h> 

#define N 10
int A[N][N];
int B[N][N];
int resultadoSuma[N][N];
int resultadoResta[N][N];
int resultadoMultiplicacion[N][N];
int resultadoT1[N][N];
int resultadoT2[N][N];
typedef struct {
    int matriz[N][N];
    double inversa[N][N];
    double determinante;
} Inversa;
void imprimirMatriz(int A[N][N]){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
}
void escribirMatrizInt(const char *nombre_archivo, int matriz[N][N]) {
    FILE *archivo = fopen(nombre_archivo, "w");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        exit(1);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fprintf(archivo, "%d ", matriz[i][j]);
        }
        fprintf(archivo, "\n");
    }
    fclose(archivo);
}
void escribirMatrizDouble(const char *nombre_archivo, double matriz[N][N]) {
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
void leerYMostrarMatriz(const char *titulo, const char *nombre_archivo) {
    FILE *archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return;
    }
    printf("\n%s:\n", titulo);
    char linea[256];
    while (fgets(linea, sizeof(linea), archivo)) {
        printf("%s", linea);
    }
    fclose(archivo);
}
DWORD WINAPI sumarMatrices(LPVOID arg) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            resultadoSuma[i][j] = A[i][j] + B[i][j];
        }
    }
    escribirMatrizInt("suma.txt", resultadoSuma);
    return 0;
}
DWORD WINAPI restarMatrices(LPVOID arg) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            resultadoResta[i][j] = A[i][j] - B[i][j];
        }
    }
    escribirMatrizInt("resta.txt", resultadoResta);
    return 0;
}
DWORD WINAPI multiplicarMatrices(LPVOID arg) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            resultadoMultiplicacion[i][j] = 0;
            for (int k = 0; k < N; k++) {
                resultadoMultiplicacion[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    escribirMatrizInt("multiplicacion.txt", resultadoMultiplicacion);
    return 0;
}
DWORD WINAPI transponerMatriz(LPVOID arg) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            resultadoT1[j][i] = A[i][j];
            resultadoT2[j][i] = B[i][j];
        }
    }
    escribirMatrizInt("transpuesta_A.txt", resultadoT1);
    escribirMatrizInt("transpuesta_B.txt", resultadoT2);
    return 0;
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
    int temp[N][N];
    int signo = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Cofactor(matriz, temp, i, j, n);
            signo = ((i + j) % 2 == 0) ? 1 : -1;
            adjunta[j][i] = signo * DeterminanteMatriz(temp, n - 1);
        }
    }
}
DWORD WINAPI calcularInversa(LPVOID arg) {
    Inversa *datos = (Inversa *)arg;
    double determinante = (double)DeterminanteMatriz(datos->matriz, N);
    datos->determinante = determinante;
    if (determinante == 0) {
        printf("La matriz es singular, no se puede calcular la inversa.\n");
        return 0;
    }
    double adjunta[N][N];
    AdjuntaMatriz(datos->matriz, adjunta, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            datos->inversa[i][j] = adjunta[i][j] / determinante;
        }
    }
    return 0;
}
DWORD WINAPI InversaMatriz(LPVOID arg) {
    Inversa datosA = {.matriz = {0}, .inversa = {0}, .determinante = 0};
    Inversa datosB = {.matriz = {0}, .inversa = {0}, .determinante = 0};
    memcpy(datosA.matriz, A, sizeof(A));
    memcpy(datosB.matriz, B, sizeof(B));
    HANDLE thread1, thread2;
    thread1 = CreateThread(NULL, 0, calcularInversa, &datosA, 0, NULL);
    thread2 = CreateThread(NULL, 0, calcularInversa, &datosB, 0, NULL);
    WaitForSingleObject(thread1, INFINITE);
    WaitForSingleObject(thread2, INFINITE);

    if (datosA.determinante != 0) {
        escribirMatrizDouble("inversa_A.txt", datosA.inversa);
    }
    if (datosB.determinante != 0) {
        escribirMatrizDouble("inversa_B.txt", datosB.inversa);
    }
    return 0;
}
DWORD WINAPI leerArchivos(LPVOID arg) {
    leerYMostrarMatriz("Suma de matrices", "suma.txt");
    leerYMostrarMatriz("Resta de matrices", "resta.txt");
    leerYMostrarMatriz("Multiplicacion de matrices", "multiplicacion.txt");
    leerYMostrarMatriz("Transpuesta de A", "transpuesta_A.txt");
    leerYMostrarMatriz("Transpuesta de B", "transpuesta_B.txt");
    leerYMostrarMatriz("Inversa de A", "inversa_A.txt");
    leerYMostrarMatriz("Inversa de B", "inversa_B.txt");
    return 0;
}
int main() {
    srand(time(NULL));
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
    HANDLE h1, h2, h3, h4, h5;
    h1 = CreateThread(NULL, 0, sumarMatrices, NULL, 0, NULL);
    h2 = CreateThread(NULL, 0, restarMatrices, NULL, 0, NULL);
    h3 = CreateThread(NULL, 0, multiplicarMatrices, NULL, 0, NULL);
    h4 = CreateThread(NULL, 0, transponerMatriz, NULL, 0, NULL);
    h5 = CreateThread(NULL, 0, InversaMatriz, NULL, 0, NULL);
    WaitForSingleObject(h1, INFINITE);
    WaitForSingleObject(h2, INFINITE);
    WaitForSingleObject(h3, INFINITE);
    WaitForSingleObject(h4, INFINITE);
    WaitForSingleObject(h5, INFINITE);
    HANDLE h6 = CreateThread(NULL, 0, leerArchivos, NULL, 0, NULL);
    WaitForSingleObject(h6, INFINITE);
    return 0;
}
