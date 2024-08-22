#include<stdio.h>

int main(){
    int i, j, k, n=4;

    for(i=0;i<n;i++)
       for(j=0;j<n;j++)
          for(k=0;k<n;k++){
              printf("i=%d\tj=%d\tk=%d\n",i,j,k);
              getchar();
          }

    return 0;
}
