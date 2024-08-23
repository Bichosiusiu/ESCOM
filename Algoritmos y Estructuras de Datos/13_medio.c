#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
    int size;
} Stack;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error al asignar memoria para el nodo.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void initialize(Stack* stack) {
    stack->top = NULL;
    stack->size = 0;
}

int isEmpty(Stack* stack) {
    return (stack->top == NULL);
}

void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("La pila est� vac�a. No se puede eliminar.\n");
        return -1;
    }
    Node* temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return data;
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("La pila est� vac�a.\n");
        return -1;
    }
    return stack->top->data;
}

int medio(Stack* stack) {
    if (isEmpty(stack)) {
        printf("La pila est� vac�a.\n");
        return -1;
    }

    int m = stack->size / 2;
    Node* c = stack->top;
    for (int i = 0; i < m; i++) {
        c = c->next;
    }

    return c->data;
}

int main() {
    Stack stack;
    initialize(&stack);
    int t, n;

    printf("Ingrese el tama�o de la pila: ");
    scanf("%d", &t);

    printf("Ingrese los elementos de la pila:\n");
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        push(&stack, n);
    }

    if (medio(&stack) != -1) {
        printf("El elemento del medio de la pila es: %d\n", medio(&stack));
    }

    return 0;
}



