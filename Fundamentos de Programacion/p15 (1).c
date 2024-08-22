#include<stdio.h>
void Unidades(int);
void Decenas(int);
void Centenas(int);
void Num_a_Letra(int);
void De_11_a_15(int);
void De_101_a_199(int);

int main(){
   int num;

   printf("Numero (1-999)?");
   scanf("%d",&num);
   Num_a_Letra(num);

   return 0;

}

void Unidades(int n){
   if(n>0)
        printf(" y ");
   switch(n){
      case 1: printf("uno"); break;
      case 2: printf("dos"); break;
      case 3: printf("tres"); break;
      case 4: printf("cuatro"); break;
      case 5: printf("cinco"); break;
      case 6: printf("seis"); break;
      case 7: printf("siete"); break;
      case 8: printf("ocho"); break;
      case 9: printf("nueve"); break;
   //   default: printf("Valor invalido.\n");
   }
}

void De_11_a_15(int n){
   switch(n){
      case 11: printf("once "); break;
      case 12: printf("doce "); break;
      case 13: printf("trece "); break;
      case 14: printf("catorce "); break;
      case 15: printf("quince "); break;
   }
}

void Decenas(int n){
   switch(n){
      case 1: printf("diez "); break;
      case 2: printf("veinte "); break;
      case 3: printf("treinta "); break;
      case 4: printf("cuarenta "); break;
      case 5: printf("cincuenta "); break;
      case 6: printf("sesenta "); break;
      case 7: printf("setenta "); break;
      case 8: printf("ochenta "); break;
      case 9: printf("noventa "); break;
     // default: printf("Valor invalido.\n");
   }
}

void Centenas(int n){
   switch(n){
      case 1: printf("cien "); break;
      case 2: printf("doscientos "); break;
      case 3: printf("trecientos "); break;
      case 4: printf("cuatrocientos "); break;
      case 5: printf("quinietos "); break;
      case 6: printf("seiscientos "); break;
      case 7: printf("setecientos "); break;
      case 8: printf("ochocientos "); break;
      case 9: printf("novecientos "); break;
     // default: printf("Valor invalido.\n");
   }
}

void De_101_a_199(int n){
  switch(n){
      case 1: printf("ciento "); break;
      case 2: printf("doscientos "); break;
      case 3: printf("trecientos "); break;
      case 4: printf("cuatrocientos "); break;
      case 5: printf("quinietos "); break;
      case 6: printf("seiscientos "); break;
      case 7: printf("setecientos "); break;
      case 8: printf("ochocientos "); break;
      case 9: printf("novecientos "); break;
     // default: printf("Valor invalido.\n");
   }
}

void Num_a_Letra(int n){
	if((n>100)&&(n<200)){
	  De_101_a_199(n/100);
    n=n%100;
    if((n>=11)&&(n<=15))
        De_11_a_15(n);
    else{ 
       Decenas(n/10);
       Unidades(n%10);
    }
	}
	else{
		 Centenas(n/100);
    n=n%100;
    if((n>=11)&&(n<=15))
        De_11_a_15(n);
    else{ 
       Decenas(n/10);
       Unidades(n%10);
    }
	}
}
