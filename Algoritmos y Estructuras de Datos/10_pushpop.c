#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct
{
    int data[MAX_SIZE];
    int top1;

} dospilas;

void inicializar(dospilas *stacks)
{
    stacks->top1 = -1;

}

int isEmpty1(dospilas *stacks)
{
    return (stacks->top1 == -1);
}


int isFull1(dospilas *stacks)
{
    return (stacks->top1 == MAX_SIZE- 1);
}

void push1(dospilas *stacks, int n)
{
    if (isFull1(stacks))
    {
        printf("Error: Pila 1 llena.\n");
        return;
    }

    stacks->data[++stacks->top1] = n;

}

int pop1(dospilas *stacks)
{
    if (isEmpty1(stacks))
    {
        printf("Error: Pila 1 vacía.\n");
        return -1;
    }

    int n = stacks->data[stacks->top1--];
    return n;
}

void imprime1(dospilas *stacks)
{
    if (isEmpty1(stacks))
    {
        printf("Pila 1 vacía.\n");
        return;
    }


    for (int i = stacks->top1; i >= 0; i--)
    {
        printf("%d\t", stacks->data[i]);
    }
}
int main()
{
    int i;
    dospilas stacks;
    inicializar(&stacks);
    push1(&stacks,50);
    push1(&stacks,40);
    push1(&stacks,30);
    push1(&stacks,20);
    push1(&stacks,10);
    for(i=0;i<5;i++){
        printf("%d\t",pop1(&stacks));
    }
    printf("\n");
    push1(&stacks,10);
    push1(&stacks,20);
    push1(&stacks,30);
    push1(&stacks,40);
    push1(&stacks,50);
    for(i=0;i<5;i++){
        printf("%d\t",pop1(&stacks));
    }
    return 0;
}
