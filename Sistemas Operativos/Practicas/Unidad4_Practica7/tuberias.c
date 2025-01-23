#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <time.h>
#define N 10
void llenar(int matriz[N][N]){
    int i, j;
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            matriz[i][j] = rand() % 101; 
        }
    }}
void guardarMatriz(double matriz[N][N], int archivo) {
    char buffer[256];
    for (int i = 0; i < N; i++) {
        int len = 0;
        for (int j = 0; j < N; j++) {
            len += sprintf(buffer + len, "%lf\t", matriz[i][j]);
        }
        buffer[len++] = '\n';
        write(archivo, buffer, len);
    }
    write(archivo, "\n", 1); 
}
void impMatriz(int matriz[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
            printf("%d\t", matriz[i][j]);
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
void multiplicacion(int matrizuno[N][N], int matrizdos[N][N], int resultado[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            resultado[i][j] = 0;
            for (int k = 0; k < N; k++){
                resultado[i][j] += matrizuno[i][k] * matrizdos[k][j]; 
            }
        }
    }
}
void suma(int matrizuno[N][N], int matrizdos[N][N], int resultado[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            resultado[i][j] = matrizuno[i][j] + matrizdos[i][j]; 
        }
    }
}
void Cofactor(int matriz[N][N], int temp[N][N], int p, int q, int n) {
    int i = 0, j = 0;
    for (int fila = 0; fila < n; fila++){
        for (int col = 0; col < n; col++){
            if (fila != p && col != q){
                temp[i][j++] = matriz[fila][col]; 
                if (j == n - 1){
                    j = 0; 
                    i++;
                }
            }
        }
    }
}
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
    int tub1[2]; 
    int tub2[2];
    int matrizA[N][N];
    int matrizB[N][N];
    if (pipe(tub1) != 0 || pipe(tub2) != 0){
        exit(1); 
    }
    if (fork() == 0){
        read(tub1[0], matrizA, sizeof(matrizA)); 
        read(tub1[0], matrizB, sizeof(matrizB)); 
        int resultado[N][N];
        multiplicacion(matrizA, matrizB, resultado); 
        write(tub1[1], resultado, sizeof(resultado)); 
        write(tub2[1], matrizA, sizeof(matrizA));
        write(tub2[1], matrizB, sizeof(matrizB)); 
        if (fork() == 0) {
            read(tub2[0], matrizA, sizeof(matrizA));
            read(tub2[0], matrizB, sizeof(matrizB)); 
            int resultado[N][N];
            suma(matrizA, matrizB, resultado); 
            write(tub2[1], resultado, sizeof(resultado)); 
            exit(0);
        }
        else{
            wait(NULL); 
        }
    } 
    else{
        llenar(matrizA); 
        llenar(matrizB);
        printf("Matriz A:\n");
        impMatriz(matrizA);
        printf("\nMatriz B:\n");
        impMatriz(matrizB); 
        write(tub1[1], matrizA, sizeof(matrizA)); 
        write(tub1[1], matrizB, sizeof(matrizB)); 
        wait(NULL); 
        int resMul[N][N];
        int resSum[N][N];
        printf("\nMultiplicacion:\n");
        read(tub1[0], resMul, sizeof(resMul)); 
        impMatriz(resMul); 
        read(tub2[0], resSum, sizeof(resSum)); 
        printf("\nSuma:\n");
        impMatriz(resSum); 
        double invMul[N][N];
        double invSum[N][N];
        inversa(resMul, invMul); 
        inversa(resSum, invSum);
        printf("\nInversa de la multiplicacion\n");
        impInversa(invMul); 
        printf("\nInversa de la suma\n");
        impInversa(invSum); 
        int archivo = open("inversaMul.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
        if (archivo < 0) {
            perror("Error al abrir el archivo");
            exit(1);
        }
        write(archivo, "Inversa de la multiplicacion:\n", 30);
        guardarMatriz(invMul, archivo);
        close(archivo);
        int archivo2 = open("inversaSum.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
        if (archivo < 0) {
            perror("Error al abrir el archivo");
            exit(1);
        }
        write(archivo, "Inversa de la suma:\n", 21);
        guardarMatriz(invSum, archivo);
        close(archivo);
        exit(0);
    }

    return 0;
}