#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

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
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d\t",A[i][j]);
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
void *sumarMatrices(void *arg) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            resultadoSuma[i][j] = A[i][j] + B[i][j];
        }
    }
    escribirMatrizInt("suma.txt", resultadoSuma);
    return NULL;
}
void *restarMatrices(void *arg) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            resultadoResta[i][j] = A[i][j] - B[i][j];
        }
    }
    escribirMatrizInt("resta.txt", resultadoResta);
    return NULL;
}
void *multiplicarMatrices(void *arg) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            resultadoMultiplicacion[i][j] = 0;
            for (int k = 0; k < N; k++) {
                resultadoMultiplicacion[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    escribirMatrizInt("multiplicacion.txt", resultadoMultiplicacion);
    return NULL;
}
void *transponerMatriz(void *arg) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            resultadoT1[j][i] = A[i][j];
            resultadoT2[j][i] = B[i][j];
        }
    }
    escribirMatrizInt("transpuesta_A.txt", resultadoT1);
    escribirMatrizInt("transpuesta_B.txt", resultadoT2);
    return NULL;
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
void *calcularInversa(void *arg) {
    Inversa *datos = (Inversa *)arg;
    double determinante = (double)DeterminanteMatriz(datos->matriz, N);
    datos->determinante = determinante;
    if (determinante == 0) {
        printf("La matriz es singular, no se puede calcular la inversa.\n");
        return NULL;
    }
    double adjunta[N][N];
    AdjuntaMatriz(datos->matriz, adjunta, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            datos->inversa[i][j] = adjunta[i][j] / determinante;
        }
    }
    return NULL;
}
void *InversaMatriz(void *arg) {
    Inversa datosA = {.matriz = {0}, .inversa = {0}, .determinante = 0};
    Inversa datosB = {.matriz = {0}, .inversa = {0}, .determinante = 0};
    memcpy(datosA.matriz, A, sizeof(A));
    memcpy(datosB.matriz, B, sizeof(B));
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, calcularInversa, &datosA);
    pthread_create(&thread2, NULL, calcularInversa, &datosB);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    if (datosA.determinante != 0) {
        escribirMatrizDouble("inversa_A.txt", datosA.inversa);
    }
    if (datosB.determinante != 0) {
        escribirMatrizDouble("inversa_B.txt", datosB.inversa);
    }
    return NULL;
}
void *leerArchivos(void *arg) {
    leerYMostrarMatriz("Suma de matrices", "suma.txt");
    leerYMostrarMatriz("Resta de matrices", "resta.txt");
    leerYMostrarMatriz("Multiplicación de matrices", "multiplicacion.txt");
    leerYMostrarMatriz("Transpuesta de A", "transpuesta_A.txt");
    leerYMostrarMatriz("Transpuesta de B", "transpuesta_B.txt");
    leerYMostrarMatriz("Inversa de A", "inversa_A.txt");
    leerYMostrarMatriz("Inversa de B", "inversa_B.txt");
    return NULL;
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
    pthread_t sumaHilo, restaHilo, multiplicacionHilo, transpuestaHilo, inversaHilo, lecturaHilo;
    pthread_create(&sumaHilo, NULL, sumarMatrices, NULL);
    pthread_create(&restaHilo, NULL, restarMatrices, NULL);
    pthread_create(&multiplicacionHilo, NULL, multiplicarMatrices, NULL);
    pthread_create(&transpuestaHilo, NULL, transponerMatriz, NULL);
    pthread_create(&inversaHilo, NULL, InversaMatriz, NULL);
    pthread_join(sumaHilo, NULL);
    pthread_join(restaHilo, NULL);
    pthread_join(multiplicacionHilo, NULL);
    pthread_join(transpuestaHilo, NULL);
    pthread_join(inversaHilo, NULL);
    pthread_create(&lecturaHilo, NULL, leerArchivos, NULL);
    pthread_join(lecturaHilo, NULL);
    return 0;
}

