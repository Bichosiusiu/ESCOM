#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return (stack->top == -1);
}

int isFull(Stack* stack) {
    return (stack->top == MAX_SIZE - 1);
}

void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("La pila está llena. No se puede insertar.\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("La pila está vacía. No se puede eliminar.\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("La pila está vacía.\n");
        return -1;
    }
    return stack->arr[stack->top];
}

void ordenar(Stack* stack) {
    Stack tempStack;
    initialize(&tempStack);

    while (!isEmpty(stack)) {
        int temp = pop(stack);

        while (!isEmpty(&tempStack) && peek(&tempStack) > temp) {
            push(stack, pop(&tempStack));
        }

        push(&tempStack, temp);
    }

    while (!isEmpty(&tempStack)) {
        push(stack, pop(&tempStack));
    }
}

void imprimir(Stack* stack) {
    if (isEmpty(stack)) {
        printf("La pila está vacía.\n");
        return;
    }

    for (int i = stack->top; i >= 0; i--) {
        printf("%d\t", stack->arr[i]);
    }
}

int main() {
    Stack stack;
    int i;
    initialize(&stack);
    push(&stack,8);
    push(&stack,3);
    push(&stack,2);
    push(&stack,5);
    push(&stack,5);
    push(&stack,1);
    printf("Pila original: \n");
    imprimir(&stack);
    printf("\nPila ordenada: \n");
    ordenar(&stack);
    imprimir(&stack);
    }
