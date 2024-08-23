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
        printf("La pila está vacía. No se puede eliminar.\n");
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
        printf("La pila está vacía.\n");
        return -1;
    }
    return stack->top->data;
}

float suma(Stack* stack) {
    if (isEmpty(stack)) {
        printf("La pila está vacía. No se puede obtener el elemento del medio.\n");
        return -1;
    }

    int sum=0;
    Node* c = stack->top;
    while (c!=NULL) {
        sum += c->data;
        c = c->next;
    }

    return sum;
}

int main() {
    Stack stack;
    initialize(&stack);
    int t, n;
    float p;

    printf("Ingrese el tamaño de la pila: ");
    scanf("%d", &t);

    printf("Ingrese los elementos de la pila:\n");
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        push(&stack, n);
    }

    p=suma(&stack)/t;

        printf("El promedio de la pila es: %.2f\n", p);
    }






