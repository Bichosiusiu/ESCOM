#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
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
void escribirMemoriaD(double (*matriz)[N], double *shm){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++){
            *shm = matriz[i][j];
            shm++;
        }
    }
}
void leerMemoriaD(double (*matriz)[N], double *shm) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = *shm;
            shm++;
        }
    }
}
int main(){
    srand(time(NULL));
    int A[N][N], B[N][N];
    double resultado[N][N];  
    key_t key1 = 1001;
    key_t key2 = 1002;
    key_t key3 = 1003;
    key_t key4 = 1004;
    key_t key5 = 1005;
    key_t key6 = 1006;
    key_t key7 = 1007;
    int shmid1 = shmget(key1, sizeof(int[N][N]), IPC_CREAT | 0666);
    int shmid2 = shmget(key2, sizeof(int[N][N]), IPC_CREAT | 0666);
    int shmid3 = shmget(key3, sizeof(int[N][N]), IPC_CREAT | 0666);
    int shmid4 = shmget(key4, sizeof(int[N][N]), IPC_CREAT | 0666);
    int shmid5 = shmget(key5, sizeof(int[N][N]), IPC_CREAT | 0666);
    int shmid6 = shmget(key6, sizeof(int[N][N]), IPC_CREAT | 0666);
    int shmid7 = shmget(key7, sizeof(int[N][N]), IPC_CREAT | 0666);
    double (*shmSum)[N]   = shmat(shmid1, NULL, 0);
    double (*shmRes)[N]  = shmat(shmid2, NULL, 0);
    double (*shmMul)[N]  = shmat(shmid3, NULL, 0);
    double (*shmTraA)[N] = shmat(shmid4, NULL, 0);
    double (*shmTraB)[N] = shmat(shmid5, NULL, 0);
    double (*shmInvA)[N] = shmat(shmid6, NULL, 0);
    double (*shmInvB)[N] = shmat(shmid7, NULL, 0);
    if (shmid1 < 0) {
        perror("Error al obtener memoria compartida para la matriz resultado de suma: shmget");
        exit(1);
    }
    if (shmid2 < 0) {
        perror("Error al obtener memoria compartida para la matriz resultado de resta: shmget");
        exit(1);
    }
    if (shmid3 < 0) {
        perror("Error al obtener memoria compartida para la matriz resultado de multiplicación: shmget");
        exit(1);
    }
    if (shmid4 < 0) {
        perror("Error al obtener memoria compartida para la matriz resultado de traspuesta uno: shmget");
        exit(1);
    }
    if (shmid5 < 0) {
        perror("Error al obtener memoria compartida para la matriz resultado de traspuesta dos: shmget");
        exit(1);
    }
    if (shmid6 < 0) {
        perror("Error al obtener memoria compartida para la matriz resultado de inversa uno: shmget");
        exit(1);
    }
    if (shmid7 < 0) {
        perror("Error al obtener memoria compartida para la matriz resultado de inversa dos: shmget");
        exit(1);
    }
    if (shmSum == (void *)-1) {
        perror("Error al enlazar la memoria compartida para la matriz resultado de suma: shmat");
        exit(1);
    }
    if (shmRes == (void *)-1) {
        perror("Error al enlazar la memoria compartida para la matriz resultado de resta: shmat");
        exit(1);
    }
    if (shmMul == (void *)-1) {
        perror("Error al enlazar la memoria compartida para la matriz resultado de multiplicación: shmat");
        exit(1);
    }
    if (shmTraA == (void *)-1) {
        perror("Error al enlazar la memoria compartida para la matriz resultado de traspuesta uno: shmat");
        exit(1);
    }
    if (shmTraB == (void *)-1) {
        perror("Error al enlazar la memoria compartida para la matriz resultado de traspuesta dos: shmat");
        exit(1);
    }
    if (shmInvA == (void *)-1) {
        perror("Error al enlazar la memoria compartida para la matriz resultado de inversa uno: shmat");
        exit(1);
    }
    if (shmInvB == (void *)-1) {
        perror("Error al enlazar la memoria compartida para la matriz resultado de inversa dos: shmat");
        exit(1);
    }
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
                    escribirMemoriaD(resultado, (double *)shmSum);
                    break;
                case 2: 
                    restarMatrices(A, B, resultado);
                    escribirMatriz("resta.txt", resultado);
                    escribirMemoriaD(resultado, (double *)shmRes);
                    break;
                case 3: 
                    multiplicarMatrices(A, B, resultado);
                    escribirMatriz("multiplicacion.txt", resultado);
                    escribirMemoriaD(resultado, (double *)shmMul);
                    break;
                case 4: 
                    transponerMatriz(A, resultado);
                    escribirMatriz("transpuesta_A.txt", resultado);
                    escribirMemoriaD(resultado, (double *)shmTraA);
                    transponerMatriz(B, resultado);
                    escribirMatriz("transpuesta_B.txt", resultado);
                    escribirMemoriaD(resultado, (double *)shmTraB);
                    break;
                case 5: 
                    double Inversauno[N][N];
                    double Inversados[N][N];
                    InversaMatriz(A, Inversauno);
                    InversaMatriz(B, Inversados);
                    escribirMatriz("inversa_A.txt", Inversauno); 
                    escribirMatriz("inversa_B.txt", Inversados); 
                    escribirMemoriaD(Inversauno, (double *)shmInvA);
                    escribirMemoriaD(Inversados, (double *)shmInvB);
                    break;
                case 6:
                    printf("\nResultados de la suma:\n");
                    leerMemoriaD(resultado,(double *)shmSum);
                    imprimirMatriz(resultado);
                    printf("\nResultados de la resta:\n");
                    leerMemoriaD(resultado,(double *)shmRes);
                    imprimirMatriz(resultado);
                    printf("\nResultados de la multiplicación:\n");
                    leerMemoriaD(resultado,(double *)shmMul);
                    imprimirMatriz(resultado);
                    printf("\nTranspuesta de la matriz A:\n");
                    leerMemoriaD(resultado,(double *)shmTraA);
                    imprimirMatriz(resultado);
                    printf("\nTranspuesta de la matriz B:\n");
                    leerMemoriaD(resultado,(double *)shmTraB);
                    imprimirMatriz(resultado);
                    printf("\nInversa de la matriz A:\n");
                    leerMemoriaD(resultado,(double *)shmInvA);
                    imprimirMatriz(resultado);
                    printf("\nInversa de la matriz B:\n");
                    leerMemoriaD(resultado,(double *)shmInvB);
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