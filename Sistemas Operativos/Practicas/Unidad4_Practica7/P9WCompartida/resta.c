#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#define N 10
#define TAM_MEM (N * N * sizeof(int))
void RestarMatrices(int matrizuno[N][N], int matrizdos[N][N], int resultado[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++) {
            resultado[i][j] = matrizuno[i][j] - matrizdos[i][j]; 
        }
    }
}
HANDLE CrearMemoriaCompartida(const char* nombre, int** punteroDatos){
    HANDLE hMemoria;
    if ((hMemoria = CreateFileMapping(INVALID_HANDLE_VALUE,NULL,PAGE_READWRITE,0,TAM_MEM,nombre)) == NULL) {
        printf("No se creó la memoria compartida: (%i)\n", GetLastError());
        exit(-1);
    }
    if ((*punteroDatos = (int*)MapViewOfFile(hMemoria,FILE_MAP_ALL_ACCESS,0,0,TAM_MEM)) == NULL) {
        printf("No se enlazó la memoria compartida: (%i)\n", GetLastError());
        CloseHandle(hMemoria);
        exit(-1);
    }
    return hMemoria;
}
void EscribirMemoriaCompartida(int matriz[N][N], int* punteroDatos){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *punteroDatos++ = matriz[i][j]; 
        }
    }}
void ErrorMemoriaCompartida(const char* nombre, HANDLE* hMemCom){
    if ((*hMemCom = OpenFileMapping(
            FILE_MAP_ALL_ACCESS, 
            FALSE,               
            nombre     
        )) == NULL) {
        printf("No se accedió a la memoria compartida para %s: (%i)\n", nombre, GetLastError());
        exit(-1);
    }
}
int* MapearMemoriaCompartida(const char* nombre, HANDLE hMemCom){
    int* apDatos;
    if ((apDatos = (int *)MapViewOfFile(
            hMemCom,            
            FILE_MAP_ALL_ACCESS,
            0,
            0,
            TAM_MEM
        )) == NULL) {
        printf("No se enlazó la memoria compartida: (%i)\n", GetLastError());
        CloseHandle(hMemCom);
        exit(-1);
    }
    return apDatos;
}
void LeerMemoriaCompartida(int matriz[N][N], int* punteroDatos){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = *punteroDatos++;
        }
    }
}
int main(void){
    int Matrizuno[N][N];
    int Matrizdos[N][N];
    HANDLE hMemComMatrizUno;
    int* apDatosMatrizUno;
    ErrorMemoriaCompartida("Memoria_Compartida_MU_PH", &hMemComMatrizUno);
    apDatosMatrizUno = MapearMemoriaCompartida("Memoria_Compartida_MU_PH", hMemComMatrizUno);
    LeerMemoriaCompartida(Matrizuno, apDatosMatrizUno);
    apDatosMatrizUno[0] = -1;
    UnmapViewOfFile(apDatosMatrizUno);
    CloseHandle(hMemComMatrizUno);
    HANDLE hMemComMatrizDos;
    int* apDatosMatrizDos;
    ErrorMemoriaCompartida("Memoria_Compartida_MD_PH", &hMemComMatrizDos);
    apDatosMatrizDos = MapearMemoriaCompartida("Memoria_Compartida_MD_PH", hMemComMatrizDos);
    LeerMemoriaCompartida(Matrizdos, apDatosMatrizDos);
    apDatosMatrizDos[0] = -1;
    UnmapViewOfFile(apDatosMatrizDos);
    CloseHandle(hMemComMatrizDos);
    int Resultado[N][N];
    RestarMatrices(Matrizuno, Matrizdos,Resultado);
    int* apDatosResrest;
    HANDLE hMemComResrest = CrearMemoriaCompartida("Memoria_Compartida_Res_Rest", &apDatosResrest);
    EscribirMemoriaCompartida(Resultado, apDatosResrest);
    while (apDatosResrest[0] != -1) {
        Sleep(1);
    }
    UnmapViewOfFile(apDatosResrest);
    CloseHandle(hMemComResrest);
    return 0;
}