#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Definición de la estructura de la pila
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// Inicializar la pila
void init(Stack *stack) {
    stack->top = -1;
}

// Verificar si la pila está vacía
int isEmpty(Stack *stack) {
    return (stack->top == -1);
}

// Verificar si la pila está llena
int isFull(Stack *stack) {
    return (stack->top == MAX_SIZE - 1);
}

// Insertar un elemento en la pila
void push(Stack *stack, int item) {
    if (isFull(stack)) {
        printf("Error: la pila está llena\n");
        return;
    }
    stack->data[++stack->top] = item;
}

// Eliminar un elemento de la pila
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Error: la pila está vacía\n");
        return -1;
    }
    return stack->data[stack->top--];
}

// Obtener el elemento en la parte superior de la pila sin eliminarlo
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Error: la pila está vacía\n");
        return -1;
    }
    return stack->data[stack->top];
}

int main() {
    Stack stack;
    init(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);
    push(&stack, 3);

    printf("Elementos en la pila: ");
    while (!isEmpty(&stack)) {
        printf("%d ", pop(&stack));
    }
    printf("\n");

    return 0;
}