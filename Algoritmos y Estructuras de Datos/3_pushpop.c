#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 3

// Definici�n de la estructura de la pila
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// Inicializar la pila
void init(Stack *stack) {
    stack->top = -1;
}

// Verificar si la pila est� vac�a
int isEmpty(Stack *stack) {
    return (stack->top == -1);
}

// Verificar si la pila est� llena
int isFull(Stack *stack) {
    return (stack->top == MAX_SIZE - 1);
}

// Insertar un elemento en la pila
void push(Stack *stack, int item) {
    if (isFull(stack)) {
        printf("\nError: la pila est� llena\n");
        return;
    }
    stack->data[++stack->top] = item;
    
}

// Eliminar un elemento de la pila
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("\nError: la pila est� vac�a\n");
        return -1;
    }
    return stack->data[stack->top--];
}

// Obtener el elemento en la parte superior de la pila sin eliminarlo
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Error: la pila est� vac�a\n");
        return -1;
    }
    return stack->data[stack->top];
}

int main() {
    Stack stack;
    init(&stack);
    printf("tama�o de la pila %d\n ", MAX_SIZE);
    printf("pila original: ");
    
for (int i = 1; i <= MAX_SIZE; i++) {
        push(&stack, i);
        printf(" %d", i);
}

push(&stack,4);
pop(&stack);
printf("Tama�o de la pila %d\n ", MAX_SIZE);
while (!isEmpty(&stack)) {

        printf("%d ", pop(&stack));
    }
pop(&stack);
    return 0;
}