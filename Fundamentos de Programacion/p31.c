#include<stdio.h>
void ImpMat(int[][15],int,int);
void LlenaMatI(int[][15],int,int);
void InitMatN(int[][15],int,int,int);
void InitMatIdent1(int[][15],int);
void InitMatIdent2(int[][15],int);
void Magico(int[][15],int);

int main(){
    int i, j, k, r=10, c=8, m[15][15]={0};

    printf("Cual es el tamano del cuadrado?");
    scanf("%d",&k);
    //ImpMat(m,5,7);
    Magico(m,k);
    ImpMat(m,k,k);

    return 0;
}

void ImpMat(int m[][15], int r, int c){
    int i, j;
    for(i=0;i<r;i++){
       for(j=0;j<c;j++)
          printf("%d\t",m[i][j]);
       putchar('\n');
    }
};

void LlenaMatI(int m[][15], int r, int c){
   int i, j;
   for(i=0;i<r;i++)
      for(j=0;j<c;j++)
          m[i][j]=i;
}
void InitMatN(int m[][15], int r, int c, int n){
   int i, j;
   for(i=0;i<r;i++)
      for(j=0;j<c;j++)
          m[i][j]=n;


};

void InitMatIdent1(int m[][15],int n){
   int i, j;
   for(i=0;i<n;i++)
      for(j=0;j<n;j++)
         if(i==j)
            m[i][j]=1;
         else
            m[i][j]=0;
};
void InitMatIdent2(int m[][15],int n){
   int i;
   InitMatN(m,n,n,0);
   for(i=0;i<n;i++)
       m[i][i]=1;
};

void Magico(int m[][15], int n){
    int i, r=0, c=n/2;
    m[r][c]=1;
    for(i=2;i<=n*n;i++){
        r--;c++;
        if(r<0)
           if(c<n)
             r=n-1;
           else{
              r+=2;
              c--;
           }
        else if(c>=n)
                c=0;
             else if(m[r][c]){
                     r+=2;
                     c--;
                  }
        m[r][c]=i;
    }
};
