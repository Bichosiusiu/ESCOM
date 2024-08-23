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
void Bin(Stack* stack, int d) {
    if (d == 0) {
        push(stack, 0);
        return;
    }

    while (d > 0) {
        int r = d % 2;
        push(stack, r);
        d /= 2;
    }
}

int main() {
    Stack stack;
    initialize(&stack);

    int d;
    printf("Ingrese un número decimal: ");
    scanf("%d", &d);

    Bin(&stack, d);

    printf("La representación binaria de %d es: ", d);
    while (!isEmpty(&stack)) {
        printf("%d", pop(&stack));
    }
    printf("\n");

    return 0;
}



