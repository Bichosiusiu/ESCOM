#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
void mostrar(char *archivo){
    int i = 0, j = 0;
    char num;
    FILE *file = fopen(archivo, "r"); 
    if (file == NULL){
        printf("Error al abrir el archivo %s\n", archivo);
        return;
    }
    while ((num = fgetc(file)) != EOF && j < 10) {
        printf("%c", num);
        if (num == '\n') {
            j++;
            printf("\n"); 
        }
        i++;
    }
    fclose(file); 
}
int main(int argc, char *argv[]){
    printf("\nSoy el proceso hijo 6 con PID: %d \n", GetCurrentProcessId());
    mostrar("suma.txt");
    mostrar("resta.txt");
    mostrar("multiplicacion.txt");
    mostrar("transpuesta_A.txt");
    mostrar("transpuesta_B.txt");
    mostrar("inversa_A.txt");
    mostrar("inversa_B.txt");
    return 0;
}