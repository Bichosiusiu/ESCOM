#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define BUF 1024
void copiar(const char *s, const char *d) {
    HANDLE hs, hd;
    DWORD br, bw;
    char bufer[BUF];
    hs = CreateFile(s, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hs == INVALID_HANDLE_VALUE) {
        printf("Error al abrir el archivo fuente: %s\n", s);
        return;
    }
    hd = CreateFile(d, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hd == INVALID_HANDLE_VALUE) {
        printf("Error al crear el archivo destino: %s\n", d);
        CloseHandle(hs);
        return;
    }
    while (ReadFile(hs, bufer, BUF, &br, NULL) && br > 0) {
        if (!WriteFile(hd, bufer, br, &bw, NULL) || bw != br) {
            printf("Error al escribir en el archivo destino.\n");
            CloseHandle(hs);
            CloseHandle(hd);
            return;
        }
    }
    CloseHandle(hs);
    CloseHandle(hd);
    printf("Archivo %s copiado a %s exitosamente.\n", s, d);
}

int main(int argc, char *argv[]) {
    DWORD br;
    char bufer[BUF];
    if (argc != 4) {
        printf("Uso: %s <ruta-del-directorio> <nombre-del-archivo> <directorio-destino>\n", argv[0]);
        return EXIT_FAILURE;
    }
    const char *dir = argv[1];
    const char *file = argv[2];
    const char *destdir = argv[3];
    if (!CreateDirectory(destdir, NULL)) {
        if (GetLastError() != ERROR_ALREADY_EXISTS) {
            printf("Error al crear el directorio destino.\n");
            return EXIT_FAILURE;
        }
    }
    if (!SetCurrentDirectory(dir)) {
        printf("Error al cambiar de directorio a: %s\n", dir);
        return EXIT_FAILURE;
    }
    HANDLE hf = CreateFile(file, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hf == INVALID_HANDLE_VALUE) {
        printf("Error al abrir el archivo: %s\n", file);
        return EXIT_FAILURE;
    }
    printf("Contenido del archivo %s:\n", file);
    while (ReadFile(hf, bufer, BUF, &br, NULL) && br > 0) {
        fwrite(bufer, 1, br, stdout);
    }
    if (GetLastError() != ERROR_HANDLE_EOF) {
        printf("\nExito al leer el archivo.\n");
    }
    CloseHandle(hf);
    char dest_path[MAX_PATH];
    snprintf(dest_path, sizeof(dest_path), "%s\\%s", destdir, file);
    copiar(file, dest_path);
    return 0;
}
