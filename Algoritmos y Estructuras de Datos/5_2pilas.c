#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct
{
    int data[MAX_SIZE];
    int top1;
    int top2;
} dospilas;

void inicializar(dospilas *stacks)
{
    stacks->top1 = -1;
    stacks->top2 = MAX_SIZE;
}

int isEmpty1(dospilas *stacks)
{
    return (stacks->top1 == -1);
}

int isEmpty2(dospilas *stacks)
{
    return (stacks->top2 == MAX_SIZE);
}


int isFull1(dospilas *stacks)
{
    return (stacks->top1 == stacks->top2 - 1);
}

int isFull2(dospilas *stacks)
{
    return (stacks->top2 == stacks->top1 + 1);
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

void push2(dospilas *stacks, int p)
{
    if (isFull2(stacks))
    {
        printf("Error: Pila 2 llena.\n");
        return;
    }

    stacks->data[--stacks->top2] = p;

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

int pop2(dospilas *stacks)
{
    if (isEmpty2(stacks))
    {
        printf("Error: Pila 2 vacía.\n");
        return -1;
    }

    int p = stacks->data[stacks->top2++];
    return p;
}

void imprime1(dospilas *stacks)
{
    if (isEmpty1(stacks))
    {
        printf("Pila 1 vacía.\n");
        return;
    }

    printf("Elementos de la Pila 1:\n");
    for (int i = stacks->top1; i >= 0; i--)
    {
        printf("%d\t", stacks->data[i]);
    }
}

void imprime2(dospilas *stacks)
{
    if (isEmpty2(stacks))
    {
        printf("Pila 2 vacía.\n");
        return;
    }

    printf("\nElementos de la Pila 2:\n");
 for (int i = stacks->top2; i < MAX_SIZE; i++) {
        printf("%d\t ", stacks->data[i]);
    }
}



int main()
{
    dospilas stacks;
    inicializar(&stacks);
    push1(&stacks,10);
    push1(&stacks,30);
    push1(&stacks,40);
    push1(&stacks,50);
    push2(&stacks,20);
    push2(&stacks,40);
    push2(&stacks,50);
    push2(&stacks,60);
    push2(&stacks,70);
    imprime1(&stacks);
    imprime2(&stacks);
    return 0;
}
