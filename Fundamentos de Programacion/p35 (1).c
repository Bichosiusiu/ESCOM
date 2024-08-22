#include<stdio.h>
#include<string.h>
int TamCad(char[]);
void CopiaCads(char[],char[]);
void IzquierdaCad(char[],char[], int);
void DerechaCad(char[],char[],int);
void DerechaCad2(char[], int);
void EnMediocad(char[],char[],int,int);

int main(){
    char pal[80]="Escuela Superior de Computo";
    char pal2[80];
    
    IzquierdaCad(pal2,pal,7);
    printf("%s\n",pal2);
    EnMediocad(pal2,pal,8,8);
    printf("%s\n",pal2);
    DerechaCad(pal2,pal,7);
    printf("%s\n",pal2);

    //printf("%s tiene %d caracteres.\n",pal,TamCad(pal));

   return 0;
}
void DerechaCad(char dest[], char orig[], int n){
		
		int i, j=TamCad(orig);
    for(i=n;i>=0;i--)
        dest[i]=orig[j--];
};

int TamCad(char pal[]){
    int i=0;
    while(pal[i]!='\0')
         i++;
    return i;
};

void DerechaCad2(char orig[], int n){
	 int i;
     for(i=n;orig[i]!='\0';i++)
			printf("%c", orig[i]);
};

void EnMediocad(char d[],char o[], int pi, int n){
	 int i;
   for(i=0;i<n;i++)
       d[i]=o[pi+i];
   d[i]='\0';
};



void CopiaCads(char dest[], char orig[]){
   int i=0;
   while(orig[i]!='\0'){
        dest[i]=orig[i];
        i++;
   }
   dest[i]='\0';
};
void IzquierdaCad(char dest[], char orig[],int n){
      int i;
     for(i=0;i<n;i++)
        dest[i]=orig[i];
     dest[i]='\0';
};

