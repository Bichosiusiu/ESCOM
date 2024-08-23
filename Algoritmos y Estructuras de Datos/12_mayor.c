#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
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
}

int isEmpty(Stack* stack) {
    return (stack->top == NULL);
}

void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("La pila está vacía. No se puede eliminar.\n");
        return -1;
    }
    Node* temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("La pila está vacía.\n");
        return -1;
    }
    return stack->top->data;
}
int mayor(Stack* stack) {
    if (isEmpty(stack)) {
        printf("La pila está vacía. No se puede encontrar el elemento más pequeño.\n");
        return -1;
    }


int p = peek(stack);
    Node* c = stack->top;

    while (c != NULL) {
        if (c->data > p) {
            p = c->data;
        }
        c = c->next;
    }

    return p;
}

int main() {
    Stack stack;
    initialize(&stack);
    int t, n;

    printf("Ingrese el tamaño de la pila: ");
    scanf("%d", &t);

    printf("Ingrese los elementos de la pila:\n");
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        push(&stack, n);
    }

    
    if (mayor(&stack) != -1) {
        printf("El elemento más grande en la pila es: %d\n", mayor(&stack));
    }

    return 0;
}
