#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main(int argc, char *argv[]){
    if(argc!=3){
         printf("Uso: %s <archivo> <permisos>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *nombre = argv[1];
    DWORD permisos = atoi(argv[2]);  
    if(!SetFileAttributes(nombre, permisos)){
        perror("Error cambiar permisos");
        exit(EXIT_FAILURE);
    }
    
    printf("Permisos cambiados del archivo: %s\n", nombre);

    return 0;
}
