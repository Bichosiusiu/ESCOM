#include<stdio.h>
#include<string.h>
int TamCad(char[]);
void CopiaCads(char[],char[]);
void IzquierdaCad(char[],char[],int);
void DerechaCad(char[],char[],int);
void EnMedioCad(char[],char[],int,int);
void borrame(char[],char[]);
void ConcatenaCadsV1(char[],char[],char[]);
void ConcatenaNCad(char[],char[],int);
int ComparaCads(char[],char[]);
int ComparaCadsRec(char[],char[]);
int ComparaCaracter(char[], char);
int posicion(char[], char);

int main(){
    char pal1[80]="Escuela Superior de Computo";
    char pal2[80]="Instituto Politecnico Nacional";
    char pal3[80];
    char cadena[90]="hola amigos";
		char n;
/*	
    IzquierdaCad(pal2,pal,7);
    printf("%s\n",pal2);
    EnMedioCad(pal2,pal,8,8);
    printf("%s\n",pal2);
    DerechaCad(pal2,pal,7);

    ConcatenaCadsV1(pal3,pal1,pal2);
    printf("%s\n",pal3);
*/
    ConcatenaNCad(pal1,pal2,8);
    printf("%s\n",pal1);
    printf("%d\n",ComparaCadsRec("babosa","papa"));
    printf("%d\n",ComparaCaracter("anime",'z'));
		printf("\n---------------\n");
		scanf("%c",&n);
		(posicion(cadena,n)==-1)? printf("la letra no se encuentra en el arreglo") : printf("el caracter esta en la posicion: %i",posicion(cadena,n));
    return 0;
}
int ComparaCaracter(char c[], char z){
		int i, n=TamCad(c), s=0;               

		 if(c[0]!=z){
      for(i=0;i<=n;i++){
				if((c[i]==z)){
            s=i;
          return s;}
        else 
        	s=-1;
			}
				return s;}			
    else 
      return 0;
			
};

int ComparaCadsRec(char p1[], char p2[]){
    if((!p1[0])&&(!p2[0]))
        return 0;
    else if(p1[0]==p2[0])
              return ComparaCadsRec(p1+1,p2+1);
         else if(p1[0]>p2[0])
                 return 1;
              else
                return -1;
};

int TamCad(char pal[]){
    int i=0;
    while(pal[i]!='\0')
         i++;
    return i;
}
void CopiaCads(char dest[], char orig[]){
   int i=0;
   while(orig[i]!='\0'){
        dest[i]=orig[i];
        i++;
   }
   dest[i]='\0';
};
void IzquierdaCad(char dest[], char orig[],int n){
     EnMedioCad(dest,orig,0,n);
};
void EnMedioCad(char d[],char o[],int pi,int n){
   int i;
   for(i=0;i<n;i++)
       d[i]=o[pi+i];
   d[i]='\0';

};

void DerechaCad(char d[], char o[], int n){
     EnMedioCad(d,o,TamCad(o)-n,n);
}

void ConcatenaCadsV1(char d[],char o1[],char o2[]){
     IzquierdaCad(d,o1,TamCad(o1));
     IzquierdaCad(d+TamCad(o1),o2,TamCad(o2));
};
void ConcatenaNCad(char d[], char o[], int n){
     IzquierdaCad(d+TamCad(d),o,n);
};

int ComparaCads(char p1[], char p2[]){
    int i,n;
    if(TamCad(p1)> TamCad(p2))
        n=TamCad(p1);
    else
        n=TamCad(p2);
    for(i=0;i<n;i++){
        if(p1[i]>p2[i])
            return 1;
        else if(p1[i]<p2[i])
            return -1;
    }
    return 0;

};

int posicion(char cadena[], char n){
	int contador=0,i=0;
	while(contador == 0){
	if(cadena[i] == n){
	contador++;	
	}
		
	i++;
	
	}
	if(contador == 0){
	return -1;	
	}
	if(contador !=0){
	return i;
	}
	
}


