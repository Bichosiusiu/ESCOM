#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#define MAX_SIZE 100
typedef struct {
    int top;
    char items[MAX_SIZE];
} Stack;
void initialize(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}
int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack* stack, char item) {
    if (isFull(stack)) {
        printf("Error: Desbordamiento de pila\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++(stack->top)] = item;
}
char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Pila vacía\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[(stack->top)--];
}
int obtener(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}
int operador(char character) {
    return (character == '+' || character == '-' || character == '*' || character == '/' || character == '^');
}
void conversion(const char* in, char* p) {
    Stack stack;
    initialize(&stack);

    int i = 0;
    int j = 0;

    while (in[i] != '\0') {
        char c = in[i];

        if (isalnum(c)) {
            p[j++] = c;
        } else if (c == '(') {
            push(&stack, c);
        } else if (c == ')') {
            while (!isEmpty(&stack) && stack.items[stack.top] != '(') {
                p[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && stack.items[stack.top] != '(') {
                printf("Error: Expresión inválida\n");
                exit(EXIT_FAILURE);
            } else {
                pop(&stack); // Eliminar '(' de la pila
            }
        } else if (operador(c)) {
            while (!isEmpty(&stack) && obtener(c) <= obtener(stack.items[stack.top])) {
                p[j++] = pop(&stack);
            }
            push(&stack, c);
        }

        i++;
    }

    while (!isEmpty(&stack)) {
        p[j++] = pop(&stack);
    }

    p[j] = '\0';
}

int main() {
    char in[MAX_SIZE];
    char p[MAX_SIZE];

    printf("Ingrese una expresión en notación infija: ");
    fgets(in, sizeof(in), stdin);

    conversion(in, p);

    printf("La expresión en notación postfija es: %s\n", p);

    return 0;
}