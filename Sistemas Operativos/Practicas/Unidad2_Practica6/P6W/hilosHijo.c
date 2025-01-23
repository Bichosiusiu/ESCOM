#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
DWORD id;
HANDLE hilo;
DWORD WINAPI thread3(LPVOID arg) {
    printf("\t\tPractica 6 Hilo Terminal\n");
    return 0;
}
DWORD WINAPI thread2(LPVOID arg) {
    printf("\t2. ID: %d\n", GetCurrentThreadId());
    for (int i = 0; i < 10; i++) {
        hilo = CreateThread(NULL, 0, thread3, NULL, 0, &id);
    }
    return 0;
}
DWORD WINAPI thread1(LPVOID arg) {
    printf("1. ID: %d\n", GetCurrentThreadId());
    for (int i = 0; i < 15; i++) {
        hilo = CreateThread(NULL, 0, thread2, NULL, 0, &id);
    }
    return 0;
}
int main() {
    for (int i = 0; i < 20; i++) {
        hilo = CreateThread(NULL, 0, thread1, NULL, 0, &id);
    }
    WaitForSingleObject(hilo, INFINITE);
    CloseHandle(hilo);
    return 0;
}

