#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void imprimir(int* a, int n) {//funcion que imprime los valores de los arreglos enteros
    for (int i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void imprimir2(float* a, int n) {//funcion que imprime el valor del arreglo flotante
    for (int i = 0; i < n; i++) {
        printf("%.2f\t", a[i]);
    }
    printf("\n");
}

void swap(int* xp, int* yp) {//funcion para hacer un cambio en un arreglo
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void swap2(float* xp, float* yp) {//funcion para hacer un cambio en un arreglo flotante o el de v/w
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selection(float* a, int* b, int* c, int n) {//funcion para ordenar de mayor a menor
    int i, j, m;
    for (i = 0; i < n - 1; i++) {
        m = i;
        for (j = i + 1; j < n; j++)//recorre el arreglo de v/w para ordenar en base a el 
            if (a[j] > a[m])
                m = j;
        swap2(&a[m], &a[i]);//hacemos el cambio del v/w para tener todo ordenado en el arreglo
        swap(&b[m], &b[i]);//hacemos el cambio en los pesos
        swap(&c[m], &c[i]);//hacemos el cambio en los valores
    }
}

float* valorxpeso(int* a, int* b, int n) {
    float* vw = (float*)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++) {//recorre el arreglo para llenarlo
        vw[i] = (float)a[i] / (float)b[i];//asigna los valores dandolos por v/w
    }
    return vw;
}

void datos(int* w, int* v, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        w[i]= rand()%30+1;//asigna los valores random de 1 a 30 en los pesos
        v[i]= rand()%50+1;//asigna los valores random de 1 a 50 en los valores
    }
}

int max(int a, int b) {
    return (a > b) ? a : b;//retorna el maximo entre 2 variables
}

int** mochila(int* w, int* v, int p, int n) {
    int** a = (int**)malloc((n + 1) * sizeof(int*));//reservamos memoria para la tabla
    for (int i = 0; i < (n + 1); i++) {
        a[i] = (int*)malloc((p + 1) * sizeof(int));//reservamos el valor de la tabla por columna
    }

    for (int i = 0; i <= n; i++) {//primer que va a ir para llenar la tabla, recorre a las columnas
        for (int j = 0; j <= p; j++) {//segundo for para llenar la tabla, recorre las filas
            if (i == 0 || j == 0) {// si estas en la primera fila y columa
                a[i][j] = 0;//asigna ceros
            } else if (w[i - 1] <= j) {//si no y el valor de w en i menos 1 es menor o igual a j
                a[i][j] = max(v[i - 1] + a[i - 1][j - w[i - 1]], a[i - 1][j]);//asigna el valor de la posicion de la tabla entre el valor de arriba de la posicion bien dada y el de la formula dad que da un valor de una posicion y le asigna el mayor de estos
            } else {//si no pasa ninguna 
                a[i][j] = a[i - 1][j];//asigna el valor de arriba de la posicion en la que estamos 
            }
        }
    }

    return a;//retorna la tabla
}

void imptabla(int** a, int n, int p) {//funcion que imprime la tabla
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= p; j++) {
            printf("%d\t ", a[i][j]);
        }
        printf("\n");
    }
}
void solucion(int** a, int* w, int* v, int p, int n) {//funcionnque te da la solucion con los pesos de los objetos
    int i = n, j = p;//iniciamos el recorrido desde el final

    while (i > 0 && j > 0) {//mientras i sea mayor a 0 y j lo mismo, esto para recorrer la tabla
        if (a[i][j] == a[i - 1][j]) {//si la posion en la que estamos es igual al de arriba 
            i--;//decrementamos i
        } else {//si no
            printf("Objeto %d - Peso: %d - Valor: %d\n", i, w[i - 1], v[i - 1]);//imprimimos los valores de los objetos
            j = j - w[i - 1];// j sera el valor del mismo menos el peso de i menos 1
            i--;//decrementamos i
        }
    }
}
int  sumatotal(int* w,int n){
    int p=0;//variable para sumar y retornar la suma total
    for(int i=0;i<n;i++){//recorremos el arreglo de pesos
        p+=w[i];//a p se le suma el valor que hay en la posicion del peso
    }
    return p;//retornamos p
}
int main() {
    int n, p;
    printf("Dame el numero de objetos que quieres en la mochila: ");
    scanf("%d", &n);//guarda el numero de objetos

    int* w = (int*)malloc(n * sizeof(int));//reserva memoria para el arreglo de pesos
    int* v = (int*)malloc(n * sizeof(int));//reserva memoria para el arreglo de valores

    datos(w, v, n);//llena los arreglos

    float* vw = valorxpeso(v, w, n);//crea y le da valores al arreglo de v/w
    selection(vw, v, w, n);//ordena por el v/w

    printf("Pesos:\t");
    imprimir(w, n);//imprime pesos
    printf("Valores:\t");
    imprimir(v, n);//imprime valores
    printf("Valores por Peso:\t");
    imprimir2(vw, n);//imprime v/w

    printf("Ingresa la capacidad de la mochila: ");
    scanf("%d", &p);//guarda la capacidad de la mochila
    if(sumatotal(w,n)<p){//si la suma de pesos es menor a la capacidad
        printf("La capacidad de la mochila arrebasa el peso de los objetos");//mensaje de error 
    }
    else{//si no
    int** a = mochila(w, v, p, n);//guarda la tabal en a

    printf("\nTabla de Programacion Dinamica:\n");
    imptabla(a, n, p);//imprime la tabla

    printf("\nEl valor maximo que se puede obtener en la mochila es: %d\n", a[n][p]);//da el resultado de lo maximo de valor en la mochila que es la ultima posicion de la tabla
    solucion(a,w,v,p,n);//te da los objetos
    free(w);//libera a pesos
    free(v);//libera a valores
    free(vw);//libera a v/w

    for (int i = 0; i <= n; i++) {
        free(a[i]);
    }
    free(a);//libera a la tabla

    return 0;
}
}
