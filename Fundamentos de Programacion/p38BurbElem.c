#include<stdio.h>
#include"C:\Users\user00\Music\ESCOM\Programacion\Programas en Clase\Librerias\ElemInt.h"
#include"C:\Users\user00\Music\ESCOM\Programacion\Programas en Clase\Librerias\Ordenamiento.h"

int main(){
    Elem a[20];
    int i;

    for(i=0;i<10;i++)
       a[i]=LeeElem();
    Burbuja(a,10);
    puts("El arreglo ordenado es:");
    for(i=0;i<10;i++){
       ImpElem(a[i]);
       putchar('\n');
    }
    return 0;

}
