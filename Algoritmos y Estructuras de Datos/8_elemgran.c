#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

// Estructura de la pila
typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

// Función para inicializar una pila
void initialize(Stack* stack) {
    stack->top = -1;
}

// Función para verificar si la pila está vacía
int isEmpty(Stack* stack) {
    return (stack->top == -1);
}

// Función para verificar si la pila está llena
int isFull(Stack* stack) {
    return (stack->top == MAX_SIZE - 1);
}

// Función para insertar un elemento en la pila
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("La pila está llena. No se puede insertar.\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

// Función para eliminar y obtener el elemento superior de la pila
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("La pila está vacía. No se puede eliminar.\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Función para obtener el elemento superior de la pila sin eliminarlo
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("La pila está vacía.\n");
        return -1;
    }
    return stack->arr[stack->top];
}

void elem(int a[], int size) {
    Stack stack;
    initialize(&stack);

    for (int i = 0; i < size; i++) {
        int c = a[i];
        int n = -1;

        while (!isEmpty(&stack) && c > peek(&stack)) {
            printf("%d --> %d\n", pop(&stack), c);
        }

        push(&stack, c);
    }

    while (!isEmpty(&stack)) {

        printf("%d --> -1\n", pop(&stack));
    }
}

int main() {
    int size;
    int a[MAX_SIZE];

    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &size);

    printf("Ingrese los elementos del arreglo:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }
    elem(a, size);

    return 0;
}
