#include<stdio.h>
typedef union {
    int x;
    float y;
    char z;
}u1;
typedef struct {
    int x;
    float y;
    char z;
}s1;

int main(){
    u1 a;
    s1 b;
    printf("%d\n",sizeof(a));
    printf("%d\n",sizeof(b));

    return 0;
}
