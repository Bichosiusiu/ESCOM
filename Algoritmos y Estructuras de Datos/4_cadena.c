#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void init(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return (stack->top == -1);
}

int isFull(Stack* stack) {
    return (stack->top == MAX_SIZE - 1);
}

void push(Stack* stack, char ch) {
    if (isFull(stack)) {
        printf("Error: la pila está llena\n");
        return;
    }
    stack->data[++stack->top] = ch;
}

char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: la pila está vacía\n");
        return '\0';
    }
    return stack->data[stack->top--];
}

void reverso(char* str) {
    int len = strlen(str);
    Stack stack;
    init(&stack);

    for (int i = 0; i < len; i++) {
        push(&stack, str[i]);
    }


    for (int i = 0; i < len; i++) {
        str[i] = pop(&stack);
    }
}

int main() {
    char str[MAX_SIZE];

    printf("Ingresa una cadena: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';


    reverso(str);

    printf("Cadena invertida: %s\n", str);

    return 0;
}