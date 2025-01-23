#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <time.h>
#define N 10
void imprimirMatriz(double A[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%.2lf\t",A[i][j]);
        }
        printf("\n");
    } 
}
void imprimirMatrizI(int A[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d\t",A[i][j]);
        }
        printf("\n");
    } 
}
void sumarMatrices(int A[N][N], int B[N][N], int resultado[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            resultado[i][j] = A[i][j] + B[i][j];
        }
    }
}
void restarMatrices(int A[N][N], int B[N][N], int resultado[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            resultado[i][j] = A[i][j] - B[i][j];
        }
    }
}
void multiplicarMatrices(int A[N][N], int B[N][N], int resultado[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            resultado[i][j] = 0; 
            for (int k = 0; k < N; k++) {
                resultado[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
void transponerMatriz(int matriz[N][N], int resultado[N][N]) {
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
void escribirMatriz(int (*matriz)[N], int *shm){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            *shm = matriz[i][j];
            shm++;
        }
    }
}
void escribirMatriz2(int (*matrizuno)[N], int (*matrizdos)[N], int (*shm)[N]){
    escribirMatriz(matrizuno, (int *)shm);
    escribirMatriz(matrizdos, (int *)shm + (N * N));
}
void escribirMemoriaD(double (*matriz)[N], double *shm){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++){
            *shm = matriz[i][j];
            shm++;
        }
    }
}
void leerMatriz(int (*matriz)[N], int *shm){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            matriz[i][j] = *shm;
            shm++;
        }
    }
}
void leerMatriz2(int (*matrizuno)[N], int (*matrizdos)[N], int (*shm)[N]){
    leerMatriz(matrizuno, (int *)shm);
    leerMatriz(matrizdos, (int *)shm + (N * N));
}
void leerMemoriaD(double (*matriz)[N], double *shm) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = *shm;
            shm++;
        }
    }
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
        perror("error en operacion del semaforo");
        exit(1);
    }
}
void liberar(int semid){
    struct sembuf sop;
    sop.sem_num = 0;
    sop.sem_op = -1;
    sop.sem_flg = SEM_UNDO | IPC_NOWAIT;
    if (semop(semid, &sop, 1) == -1){
        perror("error en operacion del semaforo");
        exit(1);
    }
}
int main(){
    srand(time(NULL));
    int semid1, semid2, semid3;
    int A[N][N], B[N][N],TA[N][N],TB[N][N],R[N][N];
    double IA[N][N], IB[N][N];
    double resultado[N][N];  
    key_t keysem1 = 1001, keysem2 = 1002, keysem3 = 1003, key1 = 1004, key2 = 1005, key3 = 1006;
    if ((semid1 = semget(keysem1, 1,  IPC_CREAT | 0666)) == -1){
        perror("semget: error al crear semaforo de comunicacion 1");
        exit(1);
    }
    if ((semid2 = semget(keysem2, 1,  IPC_CREAT | 0666)) == -1){
        perror("semget: error al crear semaforo de comunicacion 2");
        exit(1);
    }
    if ((semid3 = semget(keysem3, 1,  IPC_CREAT | 0666)) == -1){
        perror("semget: error al crear semaforo de comunicacion 3");
        exit(1);
    }
    int shmid1 = shmget(key1, sizeof(int[N][N]), IPC_CREAT | 0666);
    int shmid2 = shmget(key2, sizeof(int[N][N]), IPC_CREAT | 0666);
    int shmid3 = shmget(key3, sizeof(int[N][N]), IPC_CREAT | 0666);
    int (*shmMat)[N]   = shmat(shmid1, NULL, 0);
    int (*shmRes)[N]  = shmat(shmid2, NULL, 0);
    int (*shmResD)[N]  = shmat(shmid3, NULL, 0);
    if (shmid1 < 0) {
        perror("Error al obtener memoria compartida para la matriz uno y dos: shmget");
        exit(1);
    }
    if (shmMat == (void *)-1) {
        perror("Error al adjuntar memoria compartida para la matriz uno y dos: shmat");
        exit(1);
    }
    if (shmid2 < 0) {
        perror("Error al obtener memoria compartida para los resultados enteros: shmget");
        exit(1);
    }
    if (shmRes == (void *)-1) {
        perror("Error al adjuntar memoria compartida para los resultados enteros: shmat");
        exit(1);
    }
     if (shmid3 < 0) {
        perror("Error al obtener memoria compartida para los resultados doubles: shmget");
        exit(1);
    }
    if (shmResD == (void *)-1) {
        perror("Error al adjuntar memoria compartida para los resultados doubles: shmat");
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
    escribirMatriz2(A,B,shmMat);
    semaforo(semid2);
    semaforo(semid3);
    pid_t pid;
    for (int i = 1; i <= 6; i++) {
        pid = fork();
        if (pid == 0) { 
            switch (i) {
                case 1: 
                    semaforo(semid1);
                    leerMatriz2(A,B,shmMat);
                    sumarMatrices(A, B, R);
                    escribirMatriz(R, (int *)shmRes);
                    liberar(semid1);
                    break;
                case 2: 
                    semaforo(semid1);
                    leerMatriz2(A,B,shmMat);
                    restarMatrices(A, B, R);
                    escribirMatriz(R, (int *)shmRes+(N*N));
                    liberar(semid1);
                    break;
                case 3: 
                    semaforo(semid1);
                    leerMatriz2(A,B,shmMat);
                    multiplicarMatrices(A, B, R);
                    escribirMatriz(R, (int *)shmRes+(2*(N*N)));
                    liberar(semid1);
                    break;
                case 4: 
                    semaforo(semid1);
                    leerMatriz2(A, B, shmMat);
                    transponerMatriz(A, TA);
                    transponerMatriz(B, TB);
                    escribirMatriz(TA, (int *)shmRes + (3 * (N * N)));
                    escribirMatriz(TB, (int *)shmRes + (4 * (N * N)));
                    liberar(semid1);
                    break;
                case 5: 
                    semaforo(semid1);
                    leerMatriz2(A, B, shmMat);
                    InversaMatriz(A, IA);
                    InversaMatriz(B, IB);
                    escribirMemoriaD(IA, (double *)shmResD);
                    escribirMemoriaD(IB, (double *)shmResD + (N * N));
                    liberar(semid1);
                    liberar(semid2);
                    break;
                case 6:
                    semaforo(semid2);
                    printf("\nSuma:\n");
                    leerMatriz(R, (int *)shmRes);
                    imprimirMatrizI(R);
                    printf("\nResta:\n");
                    leerMatriz(R, (int *)shmRes + (N * N));
                    imprimirMatrizI(R);
                    printf("\nMultiplicacion:\n");
                    leerMatriz(R, (int *)shmRes + (2 * (N * N)));
                    imprimirMatrizI(R);
                    printf("\nTraspuesta A:\n");
                    leerMatriz(TA, (int *)shmRes + (3 * (N * N)));
                    imprimirMatrizI(TA);
                    printf("\nTraspuesta B:\n");
                    leerMatriz(TB, (int *)shmRes + (4 * (N * N)));
                    imprimirMatrizI(TB);
                    printf("\nInversa A:\n");
                    leerMemoriaD(IA, (double *)shmResD);
                    imprimirMatriz(IA);
                    printf("\nInversa B:\n");
                    leerMemoriaD(IB, (double *)shmResD + (N * N));
                    imprimirMatriz(IB);
                    liberar(semid2);
                    liberar(semid3);
                    break;
            }
            exit(0); } }
    semaforo(semid3);
    shmdt(shmMat);
    shmdt(shmRes);
    shmdt(shmResD);
    semctl(semid1, 0, IPC_RMID);
    semctl(semid2, 0, IPC_RMID);
    semctl(semid3, 0, IPC_RMID);
    return 0;
} 
