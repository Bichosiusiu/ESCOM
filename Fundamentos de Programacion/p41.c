#include<stdio.h>

int main(int argc, char *argv[]){
    int i=1;
    printf("%d\n",argc);
    while(--argc)
        printf("%s\n",argv[i++]);

    printf("%d\n",argc);
    return 0;
}
