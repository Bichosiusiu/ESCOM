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

int balancear(const char *cadena) {
    Stack stack;
    init(&stack);
    int i;
    
    for (i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] == '(' || cadena[i] == '{' || cadena[i] == '[') {
            push(&stack, cadena[i]);
        } else if (cadena[i] == ')' || cadena[i] == '}' || cadena[i] == ']') {
            if (isEmpty(&stack)) {
                return 0;
            }
            char e = (char)pop(&stack);
            if ((cadena[i] == ')' && e != '(') ||
                (cadena[i] == ']' && e != '[') ||
                (cadena[i] == '}' && e != '{')) {
                return 0;
            }
        }
    }
    return isEmpty(&stack);
}

double evaluateExpression(const char *cadena) {
    Stack values;
    Stack operators;
    init(&values);
    init(&operators);
    int i = 0;

    if(!balancear(cadena)){
        printf("Error: la expresión está desbalanceada\n");
        return -1;
    }

    while (cadena[i] != '\0') {
        if (isdigit(cadena[i])) {
            double operando = 0;
            while (isdigit(cadena[i])) {
                operando = (operando * 10) + (cadena[i] - '0');
                i++;
            }
            push(&values, operando);
        } else if (cadena[i] == '+' || cadena[i] == '-' || cadena[i] == '*' || cadena[i] == '/') {
            while (!isEmpty(&operators) && (cadena[i] == '+' || cadena[i] == '-') &&
                   (operators.top->value == '*' || operators.top->value == '/')) {
                double operand2 = pop(&values);
                double operand1 = pop(&values);
                char op = (char)pop(&operators);
                push(&values, evaluate(op, operand1, operand2));
            }
            push(&operators, cadena[i]);
            i++;
        } else if (cadena[i] == '(') {
            push(&operators, cadena[i]);
            i++;
        } else if (cadena[i] == ')') {
            while (!isEmpty(&operators) && (char)operators.top->value != '(') {
                double operand2 = pop(&values);
                double operand1 = pop(&values);
                char op = (char)pop(&operators);
                push(&values, evaluate(op, operand1, operand2));
            }
            pop(&operators);  // Remover '(' de la pila
            i++;
        } else {
            i++;
        }
    }

    while (!isEmpty(&operators)) {
        double operand2 = pop(&values);
        double operand1 = pop(&values);
        char op = (char)pop(&operators);
        push(&values, evaluate(op, operand1, operand2));
    }

    return pop(&values);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: proporciona una expresión para evaluar\n");
        return 1;
    }
    char *expression = argv[1];

    if ((strlen(expression) > 0) && (expression[strlen(expression) - 1] == '\n'))
        expression[strlen(expression) - 1] = '\0';

    double resultado = evaluateExpression(expression);
    if (resultado != -1) {
        printf("El resultado de la expresión es: %lf\n", resultado);
    }
    
    return 0;
}
