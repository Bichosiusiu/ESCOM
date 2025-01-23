#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <tchar.h>
void imprimirFecha(FILETIME ft) {
    SYSTEMTIME st;
    FileTimeToSystemTime(&ft, &st);
    printf("%02d/%02d/%d %02d:%02d:%02d\n", st.wDay, st.wMonth, st.wYear, st.wHour, st.wMinute, st.wSecond);
}
int main(int argc, char *argv[]) {
    WIN32_FIND_DATA fd;
    HANDLE h;
    char s[MAX_PATH];
    if (argc != 2) {
        printf("Uso: %s <ruta-del-directorio>\n", argv[0]);
        return EXIT_FAILURE;
    }
    snprintf(s, sizeof(s), "%s\\*", argv[1]);
    h = FindFirstFile(s, &fd);
    if (h == INVALID_HANDLE_VALUE) {
        printf("No se pudo abrir el directorio %s\n", argv[1]);
        return EXIT_FAILURE;
    }
    printf("Archivos en el directorio '%s':\n\n", argv[1]);
    printf("%-25s %-10s %-20s\n", "Nombre del archivo", "Tam", "Fecha y hora de ultimo acceso");
    printf("--------------------------------------------------------------\n");
    do {
        if (strcmp(fd.cFileName, ".") != 0 && strcmp(fd.cFileName, "..") != 0) {
            printf("%-25s ", fd.cFileName);
            LARGE_INTEGER fs;
            fs.LowPart = fd.nFileSizeLow;
            fs.HighPart = fd.nFileSizeHigh;
            printf("%-10lld ", fs.QuadPart);
            imprimirFecha(fd.ftLastAccessTime);
        }
    } while (FindNextFile(h, &fd) != 0);
    FindClose(h);
    return 0;
}
