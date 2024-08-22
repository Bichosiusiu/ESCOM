#include<stdio.h>

float Pago(int,float);

int main(){
    int cliente;
    float kilos;

    printf("Es preferente (1=si, 0=no)");
    scanf("%d",&cliente);
    printf("Cuantos kilos compro?");
    scanf("%f",&kilos);
    printf("El monto a pagar por %.2f kilos es %.2f.\n",
            kilos,Pago(cliente,kilos));

    return 0;
}

float Pago(int cliente,float kilos){
    if(cliente)
       if(kilos>100)
           return 10*kilos*.9*.95;
       else
           return 10*kilos*.95;
    else if(kilos>100)
             return 10*kilos*.9;
         else
             return 10*kilos;
}

