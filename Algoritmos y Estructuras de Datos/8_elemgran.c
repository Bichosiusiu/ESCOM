#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

// Estructura de la pila
typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

// Funci�n para inicializar una pila
void initialize(Stack* stack) {
    stack->top = -1;
}

// Funci�n para verificar si la pila est� vac�a
int isEmpty(Stack* stack) {
    return (stack->top == -1);
}

// Funci�n para verificar si la pila est� llena
int isFull(Stack* stack) {
    return (stack->top == MAX_SIZE - 1);
}

// Funci�n para insertar un elemento en la pila
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("La pila est� llena. No se puede insertar.\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

// Funci�n para eliminar y obtener el elemento superior de la pila
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("La pila est� vac�a. No se puede eliminar.\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Funci�n para obtener el elemento superior de la pila sin eliminarlo
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("La pila est� vac�a.\n");
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

    printf("Ingrese el tama�o del arreglo: ");
    scanf("%d", &size);

    printf("Ingrese los elementos del arreglo:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }
    elem(a, size);

    return 0;
}
