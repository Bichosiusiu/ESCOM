#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define N 10 
void extraer(int matriz[N][N], char str[]){
    int fila = 0, columna = -1;
    int i = 0;
    int num = 0;
    char num_str[10] = {'\0'};
    while (str[i] != '\0'){
        if (str[i] == ' '){
            matriz[fila][columna++] = atoi(num_str);
            num = 0;
            memset(num_str, '\0', sizeof(num_str));
        }
        else if (str[i] >= '0' && str[i] <= '9'){
            num_str[num++] = str[i];
        }
        else if (str[i] == '\n'){
            matriz[fila][columna++] = atoi(num_str);
            fila++;
            columna = 0;
            num = 0;
            memset(num_str, '\0', sizeof(num_str));
        }
        i++;
    }
    matriz[fila][columna] = atoi(num_str);
}
void restarMatrices(int A[N][N], int B[N][N], double resultado[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            resultado[i][j] = A[i][j] - B[i][j];
        }
    }
}
void escribirMatriz(char *nombre_archivo, double matriz[N][N]) {
    FILE *archivo = fopen(nombre_archivo, "w");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        exit(1);
    }
    fprintf(archivo,"\tResultado Resta\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fprintf(archivo, "%.2f ", matriz[i][j]); 
        }
        fprintf(archivo, "\n");
    }
    fclose(archivo);
}
int main(int argc, char *argv[]){
    printf("\nSoy el proceso hijo 2 con PID: %d \n", GetCurrentProcessId());
    printf("\tRealizo la resta de matrices\n");
    int Matriz1[N][N]; 
    int Matriz2[N][N]; 
    double resultado[N][N]; 
    extraer(Matriz1, argv[1]);
    extraer(Matriz2, argv[2]);
    restarMatrices(Matriz1, Matriz2, resultado);
    escribirMatriz("resta.txt", resultado); 
    return 0; 
}