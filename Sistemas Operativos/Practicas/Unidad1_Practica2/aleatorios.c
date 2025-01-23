#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>
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
    if(mkdir(directory_path,0700)==-1){
        perror("Error al crear directorio");
        exit(EXIT_FAILURE);
    }
    if(chdir(directory_path)==-1){
        perror("Error al cambiar de directorio");
        exit(EXIT_FAILURE);
    }
    for(int i=0;i<5;i++){
        char nombre[20];
        snprintf(nombre, sizeof(nombre), "archivo_%d.txt", i);
        int fd =open(nombre,O_CREAT | O_WRONLY, 0644);
        char*  con =contenido();
        if(write(fd,con,strlen(con))==-1){
        perror("Error al escribir en archivo");
        exit(EXIT_FAILURE);
    }
    free(con);
    }
    printf("Archivos aleatorios creados en el directorio: %s\n", directory_path);

    return 0;
}
