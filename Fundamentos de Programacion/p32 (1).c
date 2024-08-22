#include<stdio.h>
void ImpMat(int[][15],int,int);
void LeeMat(int[][15],int,int);
void Magico(int[][15],int);
void MultMat(int[][15],int[][15],int[][15],int,int,int);

int main(){
   int a[15][15]={0},b[15][15]={0},c[15][15]={0};
   int i ,j, k, m=3,n=3,q=3;

/*
   Magico(a,m);
   Magico(b,m);
   ImpMat(a,m,m);
   puts("-------");
   ImpMat(b,m,m);
   MultMat(a,b,c,m,m,m);
   puts("-------");
   ImpMat(c,m,m);
*/


   printf("Introduce la mat a[%d][%d]\n",m,n);
   LeeMat(a,m,n);
   printf("Introduce la mat b[%d][%d]\n",n,q);
   LeeMat(b,n,q);
   MultMat(a,b,c,m,n,q);
   printf("c[%d][%d]=a[%d][%d]*b[%d][%d]\n",m,q,m,n,n,q);
   ImpMat(c,m,q);
/*
   for(i=0;i<3;i++){
      //printf("Tabla del %d:\n",i+1);
      for(j=0;j<3;j++)
          printf("%d*%d=%d\n",i+1,j+1,a[i][j]);
      getchar();
   }
/*
   for(i=0;i<3;i++){
      for(j=0;j<3;j++)
         for(k=0;k<3;k++)
            printf("i=%d, j=%d, k=%d\n",i,j,k);
      getchar();
   }
*/
   return 0;
}

void ImpMat(int a[][15], int r, int c){
   int i, j;

   for(i=0;i<r;i++){
      for(j=0;j<c;j++)
         printf("%d\t",a[i][j]);
      putchar('\n');
   }
};

void LeeMat(int a[][15], int r, int c){
    int i, j;

   for(i=0;i<r;i++)
      for(j=0;j<c;j++)
         scanf("%d",&a[i][j]);
};
void Magico(int m[][15], int n){
   int r=0, c=n/2, i;
   m[r][c]=1;
   for(i=2;i<=n*n;i++){
       r--;c++;
       if(r<0)
          if(c<n)
             r=n-1;
          else{
            r+=2;c--;}
       else if(c>=n)
               c=0;
            else if(m[r][c]!=0){
                      r+=2; c--;}
      m[r][c]=i;
   }
};

void MultMat(int a[][15],int b[][15],int c[][15],int m,int n,int q){
    int i,j,k;
    for(i=0;i<m;i++)
        for(j=0;j<q;j++)
           for(k=0;k<n;k++)
              c[i][j]=c[i][j]+a[i][k]*b[k][j];
};
