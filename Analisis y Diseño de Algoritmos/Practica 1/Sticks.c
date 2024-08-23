//Montealegre Rosales David Uriel
//Vázquez Blancas César Said
#include <stdio.h>
#include <stdlib.h>

void rapido(int arr[], int inicio, int fin) { //metodo de ordenamiento para los palos dados por el usuario
    int izquierda, derecha, pivote, auxiliar;

    izquierda = inicio;
    derecha = fin;
    pivote = arr[(inicio + fin) / 2];

    do {
        while (arr[izquierda] < pivote) {
            izquierda++;
        }
        while (arr[derecha] > pivote) {
            derecha--;
        }
        if (izquierda <= derecha) {
            auxiliar = arr[izquierda];
            arr[izquierda] = arr[derecha];
            arr[derecha] = auxiliar;
            izquierda++;
            derecha--;
        }
    } while (izquierda <= derecha);

    if (inicio < derecha) {
        rapido(arr, inicio, derecha);
    }
    if (izquierda < fin) {
        rapido(arr, izquierda, fin);
    }
}

void invertir(int arreglo[], int longitud){
    int inicio=0, fin=longitud-1;
    while(inicio < fin){
        int temp = arreglo[inicio];
        arreglo[inicio] = arreglo[fin];
        arreglo[fin] = temp;
        inicio++;
        fin--;
    }
}

int main()
{
    int longitud;
    int *palos;
    int max_area = 0;
    int base = 0;
    int altura = 0;
    int area_actual = 0; //variables a utilizar para la resolución del problema

    printf("Indique el numero de palos que tiene a su disposicion: ");
    scanf("%d", &longitud); //lectura del numero de palos que tiene el usuario

    if (longitud < 4)
    {
        printf("No es posible formar un rectangulo con menos de 4 palos");
        return 1; //restriccion del programa, si no se tienen minimo cuatro palos es imposible formar un rectangulo
    }

    palos = (int *)malloc(longitud * sizeof(int)); //uso de memoria dinamica

    for (int n = 0; n < longitud; n++)
    {
        printf("\nIndique la longitud del palo %d: ", n + 1);
        scanf("%d", &palos[n]); //lectura de la longitud de cada palo guardadoz en un arreglo
    }

    rapido(palos, 0, longitud - 1); //llamada a funcion de ordenamiento rapido
    invertir(palos, longitud);

    for (int i = 0; i < longitud - 1; i++) 
    {
        if (palos[i] == palos[i + 1]) //comparacion entre si de los palos, esto para ir formando parejas, ya que un rectangulo siempre tiene dos parejas de dos lados diferentes
        {
            if (base == 0)
            {
                base = palos[i]; //si se encuentra una pareja de palos con longitud igual se guarda en la variable base
            }
            else if (altura == 0)
            {
                altura = palos[i]; //si la variable base ya se habia utilizado pero si se vuelve a encontrar una pareja de palos con igual longitud se guarda en la variable altura
            }

            if (base > 0 && altura > 0) //si fueron encontradas dos parejas de palos se entra a la condicion if
            {
                area_actual = base * altura; //se obtiene el area que se puede formar con los cuatro palos que se tiene
                if (area_actual > max_area) //comparacion para saber si se esta encontrando el area maxima
                {
                    max_area = area_actual; //si fue encontrada, se guardara el area maxima en la variable max_area
                }
                //base = 0;
                //altura = 0; //reset de variables base y altura para ser utilizadas nuevamente
            }

            i++;
        }
    }

    if (max_area > 0)
    {
        printf("\nEl area maxima posible del rectangulo es: %d\n", max_area); //esto pasa si fue encontrada la posibilidad de formar un rectangulo
    }
    else
    {
        printf("\nNo es posible formar un rectangulo con los palos dados.\n"); //si no existe la psoibilidad de formar el rectangulo
    }

    free(palos); //libera memoria dinamica
    return 0; //fin del programa
}
