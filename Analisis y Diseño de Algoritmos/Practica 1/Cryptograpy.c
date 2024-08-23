//Montealegre Rosales David Uriel
//Vázquez Blancas César Said
#include<stdio.h>
#include<stdlib.h>
void LlenaArreglo(unsigned long long int *a, int n){//funcion para llenar el arreglo
   int i;
   for(i=0;i<n;i++){//iteramos la posicion desde 0 hasta la que nos dio el usuario
       scanf("%llu",&a[i]);//pedimos los valores, como pueden ser grandes se ocupa un long long int
   }
}
void ImpArreglo(unsigned long long int *a, int n){//funcion para imprimir el arreglo
    int i;
    for(i=0;i<n;i++)//iteramos la posicion de 0 hasta la que nos dio el usuario
        printf("%llu\n",a[i]);//imprimimos los valores
}
int esPrimo(int num) {//funcion para verificar si es primo un numero
    if (num == 2) {//si el numero es 2 
        return 1;//retornamos el 1, que es el verdadero o es decir, que el numero es primo
    } else {//si no es 2
        for (int i = 2; i*i <= num; i++) {//iteramos la posicion de 2 hasta i*i sea menor o igual al numero esto porque i*i se utiliza como condición porque si un número no es primo, entonces debe tener un factor menor o igual que su raíz cuadrada. Por eso, solo necesitamos verificar hasta la raíz cuadrada de num.
            if (num % i == 0) {//si en la iteracion el modulo de num e i es 0, entonces no es primo porque encontro un numero divisible que es diferente a el mismo y al 1
                return 0;//retorna un valor de falso
            }
        }
        return 1;//si no encuentra nada entonces quiere decir que es primo y por lo tanto retorna un verdadero
    }
}
void primo(unsigned long long int *a,unsigned long long int *b,int n){//b esta funcion convierte el numero del arreglo en la poscion del primo de ese numero
    int j=0;
    for(int i=0;i<n;i++){//iteramos desde la posicion uno del arreglo hasta la final
    unsigned long long int cont = 0;//este contador contara el numero de primos que llevamos 
    int num = 2;//iniciamos un num en 2 que sera el primer primo en ser considerado
        while(1){//bucle que se iterara hasta que haya un break, ya que no sabemos cuando acabaremos 
        if (esPrimo(num)) {//si el num es un primo entra en el if
            cont++;//cuando entra el contador se aumenta indicando que es el n primo en ser considerado primo
            if(cont==a[i]){//si el contador es igual al numero del arreglo, es decir si los numero primos que llevamos es igual al numero del arreglo que nos indica las posiciones de numeros primos que quiere 
            b[j]=num;//el numero primo que fue el ultimo se guaradara en la posicion j del arreglo
            j++;//aumentamos j por lo que se aumenta la posicion
            break;//rompemos el ciclo pues se encontro el numero primo en la posicion requerida
            }
        }
        num++;//en caso de que no sea primo se aumenta al siguiente numero natural y se comprueba constantemente por el while
}
}
}
int main(){
int n;
printf("Escribe el tamano de tu contrasena en numeros enteros: \t");
scanf("%d",&n);//leemos el tamaño del arreglo
unsigned long long int *a=(unsigned long long int *)malloc(n*sizeof(unsigned long long int)) ;//guardamos las posiciones en un arreglo dianmico para no desperdiciar memoria
unsigned long long int *b=(unsigned long long int *)malloc((n)*sizeof(unsigned long long int));//guardamos las posiciones en otro arreglo que sera el que tiene las respuestas encriptadas
printf("Escribe los numeros de tu contrasena uno por uno: \n");
LlenaArreglo(a,n);//pedimos los valores al usuario
primo(a,b,n);//llamamos primo para convertir a primo las posiciones del arreglo original
printf("\n");//salto de linea para visualizar el arreglo original del encriptado
ImpArreglo(b,n);//imprimimos arreglo de primos
free(a);//liberamos el arreglo dinamico a
free(b);//liberamos el arreglo dinamico b
return 0;
}