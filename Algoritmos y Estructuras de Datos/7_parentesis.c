#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return (stack->top == -1);
}

int isFull(Stack* stack) {
    return (stack->top == MAX_SIZE - 1);
}

void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("La pila está llena. No se puede insertar.\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("La pila está vacía. No se puede eliminar.\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("La pila está vacía.\n");
        return -1;
    }
    return stack->arr[stack->top];
}

int balanceada(char* parentesis) {
    Stack stack;
    initialize(&stack);
    int length = strlen(parentesis);

    for (int i = 0; i < length; i++) {
        if (parentesis[i] == '(' || parentesis[i] == '[' || parentesis[i] == '{') {
            push(&stack, parentesis[i]);
        } else if (parentesis[i] == ')' || parentesis[i] == ']' || parentesis[i] == '}') {
            if (isEmpty(&stack)) {
                return 0;
            } else {
                char top = pop(&stack);
                if ((parentesis[i] == ')' && top != '(') || (parentesis[i] == ']' && top != '[') || (parentesis[i] == '}' && top != '{')) {
                    return 0; 
                }
            }
        }
    }

    return isEmpty(&stack); 
}

int main() {
    char parentesis[MAX_SIZE];

    printf("Ingrese una cadena de parentesis: ");
    fgets(parentesis, sizeof(parentesis), stdin);
    parentesis[strcspn(parentesis, "\n")] = '\0'; 

    if (balanceada(parentesis)) {
        printf("La cadena de paréntesis esta equilibrada.\n");
    } else {
        printf("La cadena de paréntesis no esta equilibrada.\n");
    }

    return 0;
}






