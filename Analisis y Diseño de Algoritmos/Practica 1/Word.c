//Montealegre Rosales David Uriel
//Vázquez Blancas César Said
#include <stdio.h>
int mayuscula(char c[]){//funcion para contar mayusculas
    int j=0; 
    for(int i=0;c[i]!='\0';i++){ //iteramos hasta que se acabe la cadena
        if(c[i]>=65 && c[i]<=90){//comparamos si la letra esta en el rango de las mayusculas
            j++;//si esta en el rango aumentamos j
        }
    }
    return j;//cuando acabe de comparar la cadena se retorna el valor de las mayusculas
}    
int minuscula(char c[]){ //funcion para contar minusculas
    int j=0;
    for(int i=0;c[i]!='\0';i++){//iteramos hasta el final de la cadena
        if(c[i]>=97 && c[i]<=122){//si esta en el rango de minusculas 
            j++;//aumentamos j
        }
    }
    return j;//retornamos el valor de las minusculas
}     
void convmayus(char c[]){//funcion para convertir en mayusculas
    char*p;//declaramos un apuntador
    p=&c[0];//lo inicializamos al inicio de la cadena
    while(*p!='\0'){//mientras el apuntador sea diferente del fin de cadena se itera
        if(*p>=97 && *p<=122){//si la letra esta en el rango de las minusculas entra en el if
            *p-=32;//si es minuscula reduce en 32 por lo que ahora sera la misma letra pero en mayuscula
        }
        p++;//aumenta p 
    }
}
void convminus(char c[]){//funcion para convertir en minusculas
    char*p;//declaramos un apuntador
    p=&c[0];//el apuntador se inicializa en la primer letra
    while(*p!='\0'){//mientras p sea difernete al fin de cadena se va a iterar
        if(*p>=65 && *p<=90){//si la letra a la que apunta p esta en el rango de las mayusculas
            *p+=32;//si entra en el if aumenta en 32 la letra, osea va a aumentar a una minuscula
        }
        p++;//aumenta la posicion
    }
}
int main()
{
    char c[100];//declaramos la cadena
    printf("Escribe la cadena con mayusculas y minusculas: \n");//pedimos una palabra con mayusculas y minusculas
    scanf("%s",c);//leemos la cadena
    if((minuscula(c))<(mayuscula(c))){//si hay mas myusculas en la cadena
        convmayus(c);//convertimos toda la cadena a mayusculas
    }
    else{// si hay mas minusculas
        convminus(c);//convertimos la cadena a minusculas
    }
    printf("%s",c);//imprimimos la cadena modificada
    return 0;
}