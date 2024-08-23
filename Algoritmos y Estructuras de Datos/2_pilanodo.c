#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Definición de la estructura de la pila
typedef struct {
    Node* top;
} Stack;

// Inicializar la pila
void init(Stack* stack) {
    stack->top = NULL;
}

// Verificar si la pila está vacía
int isEmpty(Stack* stack) {
    return (stack->top == NULL);
}

// Insertar un elemento en la pila
void push(Stack* stack, int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Eliminar un elemento de la pila
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: la pila está vacía\n");
        return -1;
    }
    Node* temp = stack->top;
    int item = temp->data;
    stack->top = temp->next;
    free(temp);
    return item;
}

// Obtener el elemento en la parte superior de la pila sin eliminarlo
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: la pila está vacía\n");
        return -1;
    }
    return stack->top->data;
}

int main() {
    Stack stack;
    init(&stack);

        printf("Push data 1\n"); 
        push(&stack, 1);
      printf("Push data 2\n"); 
      push(&stack, 2);
      printf("Push data 3\n"); 
      push(&stack, 3);
      printf("Push data 4\n"); 
      push(&stack, 4);
 if(isEmpty(&stack)){
        printf("la pila esta vacia\n");
    }
    else {
        printf("La pila tiene elementos\n");
    }

    while (!isEmpty(&stack)) {

        printf("Pop data: %d \n", pop(&stack));
    }
    if(isEmpty(&stack)){
        printf("la pila esta vacia");
    }
    else {
        printf("La pila tiene elementos");
    }
    return 0;
}