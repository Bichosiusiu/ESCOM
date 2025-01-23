#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>    
#include <sys/stat.h>  
#include <time.h>      
#include <string.h>   
#include <limits.h>
int main(int argc, char *argv[]) {
    struct dirent *d;  
    DIR *dir;            
    struct stat stati; 
    char path[PATH_MAX];  
    struct tm *tm;  
    char time[100]; 
    if(argc!=2){
         printf("Uso: %s <ruta-del-directorio>\n", argv[0]);
        exit(EXIT_FAILURE);}  
    dir = opendir(argv[1]);
    printf("Archivos en el directorio '%s':\n\n", argv[1]);
    printf("%-25s %-10s %-20s\n", "Nombre del archivo", "Tamaño", "Fecha y hora de último acceso");
    printf("--------------------------------------------------------------\n");
     while ((d = readdir(dir)) != NULL) {
        if (strcmp(d->d_name, ".") == 0 || strcmp(d->d_name, "..") == 0) {
            continue; }
        snprintf(path, sizeof(path), "%s/%s", argv[1], d->d_name);
        if (stat(path, &stati) == -1)
    {
        perror("stat fallido");
        return 1;
    }
    printf("Nombre: %s\n", path);
    printf("Tamaño: %ld bytes\n", stati.st_size);
    printf("Fecha y hora de acceso: %s", ctime(&stati.st_atime));
    printf("\n");
}
closedir(dir);
return 0;
}
