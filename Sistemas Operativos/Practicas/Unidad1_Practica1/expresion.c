#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct Node {
    double value;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

void init(Stack* stack) {
    stack->top = NULL;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, double value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->next = stack->top;
    stack->top = node;
}

double pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: pila vacía\n");
        exit(1);
    }
    Node* node = stack->top;
    double value = node->value;
    stack->top = node->next;
    free(node);
    return value;
}

double evaluate(char operator, double operand1, double operand2) {
    switch (operator) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': 
            if (operand2 == 0) {
                printf("Error: división por cero\n");
                exit(1);
            }
            return operand1 / operand2;
        default: 
            printf("Error: operador no válido\n");
            exit(1);
    }
}
int balancear(Stack* stack, char *cadena) {
    int i;
    char e;
    for (i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] == '(' || cadena[i] == '{' || cadena[i] == '[') {
            push(stack, cadena[i]);
        } else if (cadena[i] == ')' || cadena[i] == '}' || cadena[i] == ']') {
            if (isEmpty(stack)) {
                return 0;
            }
            e = pop(stack);
            if ((cadena[i] == ')' && e != '(') ||
                (cadena[i] == ']' && e != '[') ||
                (cadena[i] == '}' && e != '{')) {
                return 0;
            }
        }
    }
    return isEmpty(stack);
}

double evaluateExpression(const char *cadena) {
    Stack stack;
    init(&stack);
    char operador = 0;
    double operando = 0;
    int i = 0;
    if(balancear(&stack,cadena)){
    while (cadena[i] != '\0') {
        if (isdigit(cadena[i])) {
            operando = 0;
            while (isdigit( cadena[i])) {
                operando = (operando * 10) + (cadena[i] - '0');
                i++;}
            push(&stack, operando);
        } else if (cadena[i] == '+' || cadena[i] == '-' ||
                   cadena[i] == '*' || cadena[i] == '/') {
            operador = cadena[i];
            i++;
        } else if (cadena[i] == ')') {
            double operand2 = pop(&stack);
            double operand1 = pop(&stack);
            double result = evaluate(operador, operand1, operand2);
            push(&stack, result);
            i++;
        } else {
            i++; 
        }
    }
    }else{
        return -1;
    }
    return pop(&stack);
}

int main() {
    char expression[100];
    printf("Ingrese una expresión aritmética con paréntesis balanceados: ");
    fflush(stdout);
    if (fgets(expression, sizeof(expression), stdin) == NULL) {
        printf("Error al leer la expresión.\n");
        return 1;
    }
    expression[strcspn(expression, "\n")] = '\0';
    
    double resultado = evaluateExpression(expression);
    if(resultado!=-1){
    printf("El resultado de la expresión es: %lf\n", resultado);
    }else{
        printf("Esta desbalanceado");
    }
    
    return 0;
}