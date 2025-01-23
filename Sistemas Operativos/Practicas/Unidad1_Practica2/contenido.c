#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <time.h>
#define BUF 1024
void copiar(const char *s, const char *d) {
    int sfd, dfd;
    ssize_t br, bw;
    char bufer[BUF];
    sfd = open(s, O_RDONLY);
    if (sfd == -1) {
        perror("Error al abrir el archivo fuente");
        exit(EXIT_FAILURE);
    }
    dfd = open(d, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dfd == -1) {
        perror("Error al crear el archivo destino");
        close(sfd);
        exit(EXIT_FAILURE);
    }

    while ((br = read(sfd, bufer, BUF)) > 0) {
        bw = write(dfd, bufer, br);
        if (bw == -1) {
            perror("Error al escribir en el archivo destino");
            close(sfd);
            close(dfd);
            exit(EXIT_FAILURE);
        }
    }
    close(sfd);
    close(dfd);
    printf("Archivo %s copiado a %s exitosamente.\n", s, d);
}
int main(int argc, char *argv[]) {
    ssize_t br;
    char bufer[BUF];
    if (argc != 4) {
        printf("Uso: %s <ruta-del-directorio> <nombre-del-archivo> <directorio-destino>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    const char *dir = argv[1];
    const char *file = argv[2];
    const char *destdir = argv[3];
    if (mkdir(destdir, 0755) == -1) {
        if (errno != EEXIST) {
            perror("Error al crear el directorio destino");
            exit(EXIT_FAILURE);
        }
    }
    if (chdir(dir) == -1) {
        perror("Error al cambiar de directorio");
        exit(EXIT_FAILURE);
    }
    int fd = open(file, O_RDONLY);
    if (fd == -1) {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }
    printf("Contenido del archivo %s:\n", file);
    while ((br = read(fd, bufer, BUF)) > 0) {
        write(STDOUT_FILENO, bufer, br);
    }
    if (br == -1) {
        perror("Error al leer el archivo");
    }
    close(fd);
    char dest_path[256];
    snprintf(dest_path, sizeof(dest_path), "%s/%s", destdir, file);
    copiar(file, dest_path);
    return 0;
}