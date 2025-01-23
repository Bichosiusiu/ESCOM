#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <time.h>
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
void escribir2Memoria(int (*matrizA)[TAMANIO], int (*matrizB)[TAMANIO], int (*shm)[TAMANIO]){
    escribirMemoria(matrizA, (int *)shm);
    escribirMemoria(matrizB, (int *)shm + (TAMANIO * TAMANIO));
}
void leerMemoria(int (*matriz)[TAMANIO], int *shm){
    for (int fila = 0; fila < TAMANIO; fila++){
        for (int columna = 0; columna < TAMANIO; columna++){
            matriz[fila][columna] = *shm;
            shm++;
        }
    }
}
void leer2Memoria(int (*matrizA)[TAMANIO], int (*matrizB)[TAMANIO], int (*shm)[TAMANIO]){
    leerMemoria(matrizA, (int *)shm);
    leerMemoria(matrizB, (int *)shm + (TAMANIO * TAMANIO));
}
void semaforo(int semid){
    struct sembuf sops[2];
    sops[0].sem_num = 0;
    sops[0].sem_op = 0;    
    sops[0].sem_flg = SEM_UNDO;
    sops[1].sem_num = 0;
    sops[1].sem_op = 1;    
    sops[1].sem_flg = SEM_UNDO | IPC_NOWAIT;
    if (semop(semid, sops, 2) == -1){
        perror("Error en operacion del semaforo");
        exit(1);
    }
}
void liberar(int semid){
    struct sembuf sop;
    sop.sem_num = 0;
    sop.sem_op = -1;
    sop.sem_flg = SEM_UNDO | IPC_NOWAIT;
    if (semop(semid, &sop, 1) == -1){
        perror("Error en operacion del semaforo");
        exit(1);
    }
}
int main(){
    srand(time(NULL));
    int semid1, semid2, semid3;
    int matrizA[TAMANIO][TAMANIO], matrizB[TAMANIO][TAMANIO];
    int matrizMultiplicacion[TAMANIO][TAMANIO], matrizSuma[TAMANIO][TAMANIO];
    key_t llaveA = 1000, llaveB = 1001, llaveR = 1002, llaveSemId1 = 1003, llaveSemId2 = 1004, llaveSemId3 = 1005;
    int shmIdA = shmget(llaveA, sizeof(int)*TAMANIO*TAMANIO*2, IPC_CREAT | 0666);
    int shmIdB = shmget(llaveB, sizeof(int)*TAMANIO*TAMANIO*2, IPC_CREAT | 0666);
    int shmIdR = shmget(llaveR, sizeof(int)*TAMANIO*TAMANIO*2, IPC_CREAT | 0666);
    int(*shmA)[TAMANIO] = shmat(shmIdA, NULL, 0);
    int(*shmB)[TAMANIO] = shmat(shmIdB, NULL, 0);
    int(*shmR)[TAMANIO] = shmat(shmIdR, NULL, 0);
    if (shmIdA < 0) {
        perror("Error al obtener memoria compartida");
        exit(1);
    }
    if (shmA == (int (*)[TAMANIO]) -1) {
        perror("Error al enlazar la memoria compartida para la matriz uno y dos: shmat");
        exit(1);
    }
    if (shmIdB < 0) {
        perror("Error al obtener memoria compartida");
        exit(1);
    }
     if (shmB == (int (*)[TAMANIO]) -1) {
        perror("Error al enlazar la memoria compartida para la matriz uno y dos: shmat");
        exit(1);
    }
    if (shmIdR < 0) {
        perror("Error al obtener memoria compartida");
        exit(1);
    }
     if (shmR == (int (*)[TAMANIO]) -1) {
        perror("Error al enlazar la memoria compartida para la matriz uno y dos: shmat");
        exit(1);
    }
    if ((semid1 = semget(llaveSemId1, 1, IPC_CREAT | 0666)) == -1){
        perror("error al crear semaforo de comunicacion entre padre e hijo");
        exit(1);
    }
    if ((semid2 = semget(llaveSemId2, 1, IPC_CREAT | 0666)) == -1){
        perror("error al crear semaforo de comunicacion entre hijo y nieto");
        exit(1);
    }
    if ((semid3 = semget(llaveSemId3, 1, IPC_CREAT | 0666)) == -1){
        perror("error al crear semaforo resultados");
        exit(1);
    }
    if (fork() == 0){
        semaforo(semid1);
        leer2Memoria(matrizA,matrizB,shmA);
        multiplicarMatrices(matrizA, matrizB, matrizMultiplicacion);
        escribirMemoria(matrizMultiplicacion,(int *)shmR);
        liberar(semid1);
        semaforo(semid2);
        escribir2Memoria(matrizA,matrizB,shmB);
        liberar(semid2);
        if (fork() == 0){
            semaforo(semid2);
            leer2Memoria(matrizA,matrizB,shmB);
            sumarMatrices(matrizA, matrizB, matrizSuma);
            escribirMemoria(matrizSuma,(int*)shmR+ (TAMANIO*TAMANIO));
            liberar(semid2);
            liberar(semid3);
            exit(0);
        }
        exit(0);
    }
    else{
        semaforo(semid1);
        llenarMatriz(matrizA);
        llenarMatriz(matrizB);
        printf("Matriz A:\n");
        imprimirMatrizEnteros(matrizA);
        printf("\nMatriz B:\n");
        imprimirMatrizEnteros(matrizB);
        escribir2Memoria(matrizA,matrizB,shmA);
        liberar(semid1);
        semaforo(semid3);
        semaforo(semid3);
        leer2Memoria(matrizMultiplicacion,matrizSuma,shmR);
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
        liberar(semid3);
    }
    shmdt(shmA);
    shmdt(shmB);
    shmdt(shmR);
    semctl(semid1, 0, IPC_RMID);
    semctl(semid2, 0, IPC_RMID);
    semctl(semid3, 0, IPC_RMID);
    return 0;
}

