#include<stdio.h>

int main(){
   FILE *in=fopen("borrame.c","r");
   FILE *out=fopen("Borrame2.c","w");

   int a,b,c,d,e,f,g,h,i,j;
   fscanf(in,"%d,%d,%d,%d;%d,%d,%d,%d,%d,%d\n",
             &a,&b,&c,&d,&e,&f,&g,&h,&i,&j);

   fprintf(out,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
             a*2,b*2,c*2,d*2,e*2,f*2,g*2,h*2,i*2,j*2);

   fclose(in);
   fclose(out);

   return 0;

}
