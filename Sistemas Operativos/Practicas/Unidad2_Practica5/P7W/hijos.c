#include <windows.h>
#include <stdio.h>
int main() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    printf("\tProceso hijo con PID: %d\n", GetCurrentProcessId());
    for (int i = 0; i < 5; i++) {
        ZeroMemory(&si, sizeof(si));
        si.cb = sizeof(si);
        ZeroMemory(&pi, sizeof(pi));
            if (!CreateProcess(NULL, "nietos", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
                printf("Fallo al invocar CreateProcess en nivel (%d)\n",GetLastError());
            } else {
                WaitForSingleObject(pi.hProcess, INFINITE);
                CloseHandle(pi.hProcess);
                CloseHandle(pi.hThread);
            }
        }
    return 0;
}

