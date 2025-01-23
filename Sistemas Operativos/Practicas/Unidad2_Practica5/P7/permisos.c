#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>
int main(int argc, char *argv[]){
    if(argc!=3){
         printf("Uso: %s <archivo> <permisos>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *nombre = argv[1];
    mode_t permiso = strtol(argv[2],NULL,8);
    if(chmod(nombre,permiso)==-1){
        perror("Error cambiar permisos");
        exit(EXIT_FAILURE);
    }
    
    printf("Permisos cambiados del archivo: %s\n", nombre);

    return 0;
}
