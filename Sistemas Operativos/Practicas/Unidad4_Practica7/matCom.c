#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <fcntl.h>
#define TAMANIO 10
void llenarMatriz(int matriz[TAMANIO][TAMANIO]){
    for (int fila = 0; fila < TAMANIO; fila++){
        for (int columna = 0; columna < TAMANIO; columna++){
            matriz[fila][columna] = rand() % 101;
        }
    }
}
void guardarMatriz(double matriz[TAMANIO][TAMANIO], int archivo) {
    char buffer[256];
    for (int i = 0; i < TAMANIO; i++) {
        int len = 0;
        for (int j = 0; j < TAMANIO; j++) {
            len += sprintf(buffer + len, "%lf\t", matriz[i][j]);
        }
        buffer[len++] = '\n';
        write(archivo, buffer, len);
    }
    write(archivo, "\n", 1); 
}
void imprimirMatrizEnteros(int matriz[TAMANIO][TAMANIO]){
    for (int fila = 0; fila < TAMANIO; fila++){
        for (int columna = 0; columna < TAMANIO; columna++)
            printf("%d\t", matriz[fila][columna]);
        printf("\n");
    }
}
void imprimirMatrizReales(double matriz[TAMANIO][TAMANIO]){
    for (int fila = 0; fila < TAMANIO; fila++){
        for (int columna = 0; columna < TAMANIO; columna++)
            printf("%lf  ", matriz[fila][columna]);
        printf("\n");
    }
}
void multiplicarMatrices(int matrizA[TAMANIO][TAMANIO], int matrizB[TAMANIO][TAMANIO], int resultado[TAMANIO][TAMANIO]){
    for (int fila = 0; fila < TAMANIO; fila++){
        for (int columna = 0; columna < TAMANIO; columna++){
            resultado[fila][columna] = 0;
            for (int k = 0; k < TAMANIO; k++){
                resultado[fila][columna] += matrizA[fila][k] * matrizB[k][columna];
            }
        }
    }
}
void sumarMatrices(int matrizA[TAMANIO][TAMANIO], int matrizB[TAMANIO][TAMANIO], int resultado[TAMANIO][TAMANIO]){
    for (int fila = 0; fila < TAMANIO; fila++){
        for (int columna = 0; columna < TAMANIO; columna++){
            resultado[fila][columna] = matrizA[fila][columna] + matrizB[fila][columna];
        }
    }
}
void calcularCofactor(int matriz[TAMANIO][TAMANIO], int temporal[TAMANIO][TAMANIO], int filaOmitida, int columnaOmitida, int tamActual){
    int filaTemp = 0, columnaTemp = 0;
    for (int fila = 0; fila < tamActual; fila++){
        for (int columna = 0; columna < tamActual; columna++){
            if (fila != filaOmitida && columna != columnaOmitida){
                temporal[filaTemp][columnaTemp++] = matriz[fila][columna];
                if (columnaTemp == tamActual - 1){
                    columnaTemp = 0;
                    filaTemp++;
                }
            }
        }
    }
}
int calcularDeterminante(int matriz[TAMANIO][TAMANIO], int tamActual){
    int determinante = 0;
    if (tamActual == 1)
        return matriz[0][0];
    int cofactor[TAMANIO][TAMANIO];
    int signo = 1;
    for (int columna = 0; columna < tamActual; columna++){
        calcularCofactor(matriz, cofactor, 0, columna, tamActual);
        determinante += signo * matriz[0][columna] * calcularDeterminante(cofactor, tamActual - 1);
        signo = -signo;
    }
    return determinante;
}
void calcularAdjunta(int matriz[TAMANIO][TAMANIO], double adjunta[TAMANIO][TAMANIO], int tamActual){
    if (tamActual == 1){
        adjunta[0][0] = 1;
        return;
    }
    int cofactor[TAMANIO][TAMANIO];
    int signo;
    for (int fila = 0; fila < tamActual; fila++){
        for (int columna = 0; columna < tamActual; columna++){
            calcularCofactor(matriz, cofactor, fila, columna, tamActual);
            signo = ((fila + columna) % 2 == 0) ? 1 : -1;
            adjunta[columna][fila] = signo * calcularDeterminante(cofactor, tamActual - 1);
        }
    }
}
void calcularInversa(int matriz[TAMANIO][TAMANIO], double inversa[TAMANIO][TAMANIO]){
    double determinante = (double)calcularDeterminante(matriz, TAMANIO);
    if (determinante == 0){
        printf("La matriz es singular, no tiene inversa.\n");
        return;
    }
    double adjunta[TAMANIO][TAMANIO];
    calcularAdjunta(matriz, adjunta, TAMANIO);
    for (int fila = 0; fila < TAMANIO; fila++)
        for (int columna = 0; columna < TAMANIO; columna++)
            inversa[fila][columna] = adjunta[fila][columna] / determinante;
}
void escribirMemoria(int (*matriz)[TAMANIO], int *shm){
    for (int fila = 0; fila < TAMANIO; fila++){
        for (int columna = 0; columna < TAMANIO; columna++){
            *shm = matriz[fila][columna];
            shm++;
        }
    }
}
void leerMemoria(int (*matriz)[TAMANIO], int *shm){
    for (int fila = 0; fila < TAMANIO; fila++){
        for (int columna = 0; columna < TAMANIO; columna++){
            matriz[fila][columna] = *shm;
            shm++;
        }
    }
}
int main(){
    srand(time(NULL));
    int matrizA[TAMANIO][TAMANIO], matrizB[TAMANIO][TAMANIO];
    int matrizMultiplicacion[TAMANIO][TAMANIO], matrizSuma[TAMANIO][TAMANIO];
    key_t llaveA = 1000, llaveB = 1001, llaveMulti = 1002, llaveSuma = 1003;
    int shmIdA = shmget(llaveA, sizeof(int[TAMANIO][TAMANIO]), IPC_CREAT | 0666);
    int shmIdB = shmget(llaveB, sizeof(int[TAMANIO][TAMANIO]), IPC_CREAT | 0666);
    int shmIdMulti = shmget(llaveMulti, sizeof(int[TAMANIO][TAMANIO]), IPC_CREAT | 0666);
    int shmIdSuma = shmget(llaveSuma, sizeof(int[TAMANIO][TAMANIO]), IPC_CREAT | 0666);
    int(*shmA)[TAMANIO] = shmat(shmIdA, NULL, 0);
    int(*shmB)[TAMANIO] = shmat(shmIdB, NULL, 0);
    int(*shmMulti)[TAMANIO] = shmat(shmIdMulti, NULL, 0);
    int(*shmSuma)[TAMANIO] = shmat(shmIdSuma, NULL, 0);
    if (fork() == 0){
        leerMemoria(matrizA, (int *)shmA);
        leerMemoria(matrizB, (int *)shmB);
        multiplicarMatrices(matrizA, matrizB, matrizMultiplicacion);
        escribirMemoria(matrizMultiplicacion, (int *)shmMulti);
        escribirMemoria(matrizA, (int *)shmA);
        escribirMemoria(matrizB, (int *)shmB);
        if (fork() == 0){
            leerMemoria(matrizA, (int *)shmA);
            leerMemoria(matrizB, (int *)shmB);
            sumarMatrices(matrizA, matrizB, matrizSuma);
            escribirMemoria(matrizSuma, (int *)shmSuma);
            exit(0);
        }
        wait(NULL);
        exit(0);
    }
    else{
        llenarMatriz(matrizA);
        llenarMatriz(matrizB);
        printf("Matriz A:\n");
        imprimirMatrizEnteros(matrizA);
        printf("\nMatriz B:\n");
        imprimirMatrizEnteros(matrizB);
        if (shmIdA < 0) {
            perror("Error al obtener memoria compartida para la primera matriz: shmget");
            exit(1);
        }
        if (shmIdB < 0) {
            perror("Error al obtener memoria compartida para la segunda matriz: shmget");
            exit(1);
        }
        if (shmIdMulti < 0) {
            perror("Error al obtener memoria compartida para el resultado de la multiplicación: shmget");
            exit(1);
        }
        if (shmIdSuma < 0) {
            perror("Error al obtener memoria compartida para el resultado de la suma: shmget");
            exit(1);
        }
        if (shmA == (void *)-1) {
            perror("Error al enlazar la memoria compartida para la primera matriz: shmat");
            exit(1);
        }
        if (shmB == (void *)-1) {
            perror("Error al enlazar la memoria compartida para la segunda matriz: shmat");
            exit(1);
        }
        if (shmMulti == (void *)-1) {
            perror("Error al enlazar la memoria compartida para el resultado de la multiplicación: shmat");
            exit(1);
        }
        if (shmSuma == (void *)-1) {
            perror("Error al enlazar la memoria compartida para el resultado de la suma: shmat");
            exit(1);
        }
        escribirMemoria(matrizA, (int *)shmA);
        escribirMemoria(matrizB, (int *)shmB);
        wait(NULL);
        leerMemoria(matrizMultiplicacion, (int *)shmMulti);
        leerMemoria(matrizSuma, (int *)shmSuma);
        printf("\nResultado de la multiplicación:\n");
        imprimirMatrizEnteros(matrizMultiplicacion);
        printf("\nResultado de la suma:\n");
        imprimirMatrizEnteros(matrizSuma);
        double inversa_multi[TAMANIO][TAMANIO];
        double inversa_sum[TAMANIO][TAMANIO];
        calcularInversa(matrizMultiplicacion, inversa_multi);
        calcularInversa(matrizSuma, inversa_sum);
        printf("\nInversa de la multiplicación:\n");
        imprimirMatrizReales(inversa_multi);
        printf("\nInversa de la suma:\n");
        imprimirMatrizReales(inversa_sum);
        int archivo = open("inversaMul.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
        if (archivo < 0) {
            perror("Error al abrir el archivo");
            exit(1);
        }
        write(archivo, "Inversa de la multiplicacion:\n", 30);
        guardarMatriz(inversa_multi, archivo);
        close(archivo);
        int archivo2 = open("inversaSum.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
        if (archivo2 < 0) {
            perror("Error al abrir el archivo");
            exit(1);
        }
        write(archivo2, "Inversa de la suma:\n", 21);
        guardarMatriz(inversa_sum, archivo2);
        close(archivo2);
    }
    return 0;
}
