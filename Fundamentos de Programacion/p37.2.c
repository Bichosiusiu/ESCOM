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
int LeeCadena(char*);
int MiGrepExactRec(char*,char*);
int MiGrepRec(char*,char*);
int EsLetra(char);
int EsDigito(char);
int EsCharEsp(char);
void ImpCadInversa(char[]);
int NumPalabrasCad(char[]);
int ContLetrasCad(char[]);
int ContDigCad(char[]);
int ContEspCad(char[]);

int main(){
    int n;
    char pal1[80]="Hola";
    char pal2[80]="xHolanda";
    char pal3[100];
		
		LeeCadena(pal3);
		//printf("%s\n",pal3);
		//ImpCadInversa(pal3);
		printf("El texto contiene %d palabra(s).\n",NumPalabrasCad(pal3));
		printf("El texto contiene %d letras.\n",ContLetrasCad(pal3));
		return 0; 
			
/*	
    printf("%d\n",MiGrepExactRec(pal1,pal2));

    while(1){
       puts("Introduce dos textos.");
       LeeCadena(pal1);
       LeeCadena(pal2);
       printf("%s\n",pal1);
       printf("%s\n",pal2);
       printf("--------\n");
       printf("%d\n",MiGrepRec(pal1,pal2));
       fflush(stdin);
      // getchar();
    }
    return 0;

    IzquierdaCad(pal2,pal1,7);
    printf("%s\n",pal2);
    EnMedioCad(pal2,pal1,8,8);
    printf("%s\n",pal2);
    DerechaCad(pal2,pal1,7);

    ConcatenaCadsV1(pal3,pal1,pal2);
    printf("%s\n",pal3);

    ConcatenaNCad(pal1,pal2,8);
    printf("%s\n",pal1);
    printf("%d\n",ComparaCadsRec("Holanda","Hola"));

    return 0; */
}
void borrame(char x[],char y[]){
   printf("%p\n%p\n",x,y);
}
int MiGrepExactRec(char *s1, char *s2){
    if(s1[0]=='\0')
         return 1;
    else if(s2[0]=='\0')
            return 0;
         else if(s1[0]==s2[0])
                 return MiGrepExactRec(s1+1,s2+1);
              else
                 return 0;
};

int MiGrepRec(char *s1, char *s2){
    if(s1[0]=='\0')
         return 1;
    else if(s2[0]=='\0')
            return 0;
         else if(s1[0]==s2[0])
                 if(MiGrepExactRec(s1+1,s2+1))
                    return 1;
                 else
                    return MiGrepRec(s1,s2+1);
              else
                  return MiGrepRec(s1,s2+1);
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
int LeeCadena(char *pal){
     int i=0;
     char c;
     while((c=getchar())!='#')
        pal[i++]=c;
     pal[i]='\0';

     return i;
};


void ImpCadInversa(char c[]){
   int i, n=TamCad(c);
   for(i=n;i>=0;i--){
  	printf("%c",c[i-1]);
	}
};


int NumPalabrasCad(char c[]){
	int i, n=TamCad(c), e=0;
	for(i=0;i<=n;i++){
  	if(c[i]==' '){
			e=e+1;}
	}
	if(c[0]==' '){
		return e;
	}
	else
		return e+1;
};


int ContLetrasCad(char c[]){
	int l=0, n=TamCad(c);
	if(c[0]==' '){
		return l=n-NumPalabrasCad(c);
	}
	else
		l=n-NumPalabrasCad(c)+1;
	return l;
};

int ContDigCad(char c[]){
	
};

int ContEspCad(char c[]){
	 
};

int EsLetra(char c){return ((c>='A')&&(c<='Z'))||((c>='a')&&(c<='z'));};
int EsDigito(char c){return ((c>='0')&&(c<='9'));};
int EsCharEsp(char c){return ((!EsLetra(c))&&(!EsDigito(c)));};
