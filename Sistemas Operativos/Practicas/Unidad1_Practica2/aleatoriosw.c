#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include<time.h>
char* contenido()
{
    static const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    char* contenido = (char*)malloc((50 + 1) * sizeof(char));

    for (int i = 0; i < 50; ++i)
    {
        contenido[i] = charset[rand() % (sizeof(charset) - 1)];
    }

    contenido[50] = '\0';
    return contenido;
}
int main(int argc, char *argv[]){
    if(argc!=2){
         printf("Uso: %s <ruta-del-directorio>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    const char *directory_path = argv[1];
    srand(time(NULL)); 
    if(CreateDirectory(directory_path,NULL)==0){
        perror("Error al crear directorio");
        exit(EXIT_FAILURE);
    }
    if(SetCurrentDirectory(directory_path)==0){
        perror("Error al cambiar de directorio");
        exit(EXIT_FAILURE);
    }
    for(int i=0;i<5;i++){
        char nombre[20];
        snprintf(nombre, sizeof(nombre), "archivo_%d.txt", i);
        HANDLE fd = CreateFile(nombre, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        char*  con =contenido();
        DWORD bytes;
        if(WriteFile(fd,con,strlen(con),&bytes,NULL)==-1){
        perror("Error al escribir en archivo");
        exit(EXIT_FAILURE);
        }
        if (CloseHandle(fd) == 0)
        {
            perror("Fallo al cerrar el archivo");
            exit(EXIT_FAILURE);
        }
        free(con);
    }
    printf("Archivos aleatorios creados en el directorio: %s\n", directory_path);

    return 0;
}
