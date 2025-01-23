#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <string.h>
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
    char *argv[4];
    StringMatriz(A, Matriz1);
    StringMatriz(B, Matriz2);
    printf("Soy el proceso Padre. PID: %d\n", getpid());
    int pidPadre=getpid();
    pid_t pid;
    for (int i = 0; i <= 5; i++) {
        pid = fork();
        sleep(1); 
        if (pid == 0) { 
             printf("Soy el proceso hijo %d con PID: %d, mi padre es el proceso raíz con PID: %d\n", i, getpid(), pidPadre);
            switch (i) {
                case 0: 
                    argv[0] = "suma"; 
                    argv[1] = Matriz1;
                    argv[2] = Matriz2;
                    argv[3] = NULL;
                    execv(argv[0], argv); 
                    break;
                case 1: 
                    argv[0] = "resta"; 
                    argv[1] = Matriz1;
                    argv[2] = Matriz2;
                    argv[3] = NULL;
                    execv(argv[0], argv);
                    break;
                case 2: 
                    argv[0] = "multiplicacion";
                    argv[1] = Matriz1;
                    argv[2] = Matriz2;
                    argv[3] = NULL;
                    execv(argv[0], argv);
                    break;
                case 3: 
                    argv[0] = "transpuesta"; 
                    argv[1] = Matriz1;
                    argv[2] = Matriz2;
                    argv[3] = NULL;
                    execv(argv[0], argv);
                    break;
                case 4: 
                    argv[0] = "inversa"; 
                    argv[1] = Matriz1;
                    argv[2] = Matriz2;
                    argv[3] = NULL;
                    execv(argv[0], argv);
                    break;
                case 5:
                    argv[0] = "archivo";
                    argv[1] = NULL;
                    execv(argv[0], argv);  
                    break;
            }
            exit(0); 
        }
    else{
        wait(0);
    }
    }
    return 0;
}
