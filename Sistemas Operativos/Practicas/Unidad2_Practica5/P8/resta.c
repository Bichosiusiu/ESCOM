#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

#define N 10 
void extraer(int matriz[N][N], char *str){
    char *token = strtok(str, " "); 
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            matriz[i][j] = atoi(token); 
            token = strtok(NULL, " "); 
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