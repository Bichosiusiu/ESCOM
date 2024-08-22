#include<stdio.h>
#include<string.h>
int TamCad(char[]);
void CopiaCads(char[],char[]);
void IzquierdaCad(char[],char[],int);
void DerechaCad(char[],char[],int);
void EnMediocad(char[],char[],int,int);
void borrame(char[],char[]);

int main(){
    char pal[80]="Escuela Superior de Computo";
    char pal2[80];
		
		IzquierdaCad(pal2,pal,7);
    printf("%s\n",pal2);
    EnMediocad(pal2,pal,8,8);
    printf("%s\n",pal2);
    DerechaCad(pal2,pal,7);
    printf("%s\n",pal2);

    return 0;
}
void borrame(char x[],char y[]){
   printf("%p\n%p\n",x,y);
}

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
     int i=0, pi=0;
		 EnMediocad(dest, orig, pi, n);
};
void EnMediocad(char d[],char o[],int pi,int n){
   int i;
   for(i=0;i<n;i++)
       d[i]=o[pi+i];
   d[i]='\0';
};

void DerechaCad(char d[], char o[], int n){
      
    int i, a, j=TamCad(o); 
		for(i=n-1;i>=0;i--)
		j--; 
		EnMediocad(d, o, j, n);	
}
