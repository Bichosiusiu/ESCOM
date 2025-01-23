#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define TAM_MEM_INT (N * N * sizeof(int))
#define TAM_MEM_DOUBLE (N * N * sizeof(double))
void ImprimirMatriz(int matriz[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n"); 
    }
}
void ImprimirInversa(double matriz[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
            printf("%lf  ", matriz[i][j]); 
        printf("\n"); 
    }
}
void EsperarMemoriaCompartida(const char* nombre, HANDLE* hMemCom){
    while ((*hMemCom = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE,nombre)) == NULL) {
        Sleep(100); 
    }
}
void LeerMemoriaCompartida(int matriz[N][N], int* punteroDatos){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = *punteroDatos++;
        }
    }
}
void LeerMemoriaCompartidaD(double matriz[N][N], double* punteroDatos){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = *punteroDatos++;
        }
    }
}
int* MapearMemoriaCompartida(const char* nombre, HANDLE hMemCom){
    int* apDatos;
    if ((apDatos = (int *)MapViewOfFile(hMemCom,FILE_MAP_ALL_ACCESS, 0,0,TAM_MEM_INT)) == NULL) {
        printf("No se enlazó la memoria compartida: (%i)\n", GetLastError());
        CloseHandle(hMemCom);
        exit(-1);
    }
    return apDatos;
}
double* MapearMemoriaCompartidaD(const char* nombre, HANDLE hMemCom){
    double* apDatos;
    if ((apDatos = (double *)MapViewOfFile(hMemCom,FILE_MAP_ALL_ACCESS, 0,0,TAM_MEM_DOUBLE)) == NULL) {
        printf("No se enlazó la memoria compartida: (%i)\n", GetLastError());
        CloseHandle(hMemCom);
        exit(-1);
    }
    return apDatos;
}
int main(int argc, char *argv[]){
    HANDLE hMemComResum;
    int* apDatosResum;
    EsperarMemoriaCompartida("Memoria_Compartida_Res_Sum", &hMemComResum);
    apDatosResum = MapearMemoriaCompartida("Memoria_Compartida_Res_Sum", hMemComResum);
    int Resultado_sum[N][N];
    LeerMemoriaCompartida(Resultado_sum, apDatosResum);
    printf("\nResultado suma: \n");
    ImprimirMatriz(Resultado_sum);
    apDatosResum[0] = -1;
    UnmapViewOfFile(apDatosResum);
    CloseHandle(hMemComResum);
    HANDLE hMemComResrest;
    int* apDatosResrest;
    EsperarMemoriaCompartida("Memoria_Compartida_Res_Rest", &hMemComResrest);
    apDatosResrest = MapearMemoriaCompartida("Memoria_Compartida_Res_Rest", hMemComResrest);
    int Resultado_rest[N][N];
    LeerMemoriaCompartida(Resultado_rest, apDatosResrest);
    printf("\nResultado resta: \n");
    ImprimirMatriz(Resultado_rest);
    apDatosResrest[0] = -1;
    UnmapViewOfFile(apDatosResrest);
    CloseHandle(hMemComResrest);
    HANDLE hMemComResmul;
    int* apDatosResmul;
    EsperarMemoriaCompartida("Memoria_Compartida_Res_Mul", &hMemComResmul);
    apDatosResmul = MapearMemoriaCompartida("Memoria_Compartida_Res_Mul", hMemComResmul);
    int Resultado_multi[N][N];
    LeerMemoriaCompartida(Resultado_multi, apDatosResmul);
    printf("\nResultado multiplicacion: \n");
    ImprimirMatriz(Resultado_multi);
    apDatosResmul[0] = -1;
    UnmapViewOfFile(apDatosResmul);
    CloseHandle(hMemComResmul);
    HANDLE hMemComRestrasu;
    int* apDatosRestrasu;
    EsperarMemoriaCompartida("Memoria_Compartida_Res_TrasU", &hMemComRestrasu);
    apDatosRestrasu = MapearMemoriaCompartida("Memoria_Compartida_Res_TrasU", hMemComRestrasu);
    int Resultado_traspuestau[N][N];
    LeerMemoriaCompartida(Resultado_traspuestau, apDatosRestrasu);
    printf("\nResultado traspuesta uno: \n");
    ImprimirMatriz(Resultado_traspuestau);
    apDatosRestrasu[0] = -1;
    UnmapViewOfFile(apDatosRestrasu);
    CloseHandle(hMemComRestrasu);
    HANDLE hMemComRestrasd;
    int* apDatosRestrasd;
    EsperarMemoriaCompartida("Memoria_Compartida_Res_TrasD", &hMemComRestrasd);
    apDatosRestrasd = MapearMemoriaCompartida("Memoria_Compartida_Res_TrasD", hMemComRestrasd);
    int Resultado_traspuestad[N][N];
    printf("\nResultado traspuesta dos: \n");
    LeerMemoriaCompartida(Resultado_traspuestad, apDatosRestrasd);
    ImprimirMatriz(Resultado_traspuestad);
    apDatosRestrasd[0] = -1;
    UnmapViewOfFile(apDatosRestrasd);
    CloseHandle(hMemComRestrasd);
    HANDLE hMemComResinvu;
    double* apDatosResinvu;
    EsperarMemoriaCompartida("Memoria_Compartida_Res_InvU", &hMemComResinvu);
    apDatosResinvu = MapearMemoriaCompartidaD("Memoria_Compartida_Res_InvU", hMemComResinvu);
    double Resultado_inversau[N][N];
    printf("\nResultado inversa uno: \n");
    LeerMemoriaCompartidaD(Resultado_inversau, apDatosResinvu);
    ImprimirInversa(Resultado_inversau);
    apDatosResinvu[0] = -1;
    UnmapViewOfFile(apDatosResinvu);
    CloseHandle(hMemComResinvu);
    HANDLE hMemComResinvd;
    double* apDatosResinvd;
    EsperarMemoriaCompartida("Memoria_Compartida_Res_InvD", &hMemComResinvd);
    apDatosResinvd = MapearMemoriaCompartidaD("Memoria_Compartida_Res_InvD", hMemComResinvd);
    double Resultado_inversad[N][N];
    printf("\nResultado inversa dos: \n");
    LeerMemoriaCompartidaD(Resultado_inversad, apDatosResinvd);
    ImprimirInversa(Resultado_inversad);
    apDatosResinvd[0] = -1;
    UnmapViewOfFile(apDatosResinvd);
    CloseHandle(hMemComResinvd);
    return 0;
}