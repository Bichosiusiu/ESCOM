#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node
{
    char data;
    struct Node* next;
    
} Node;
typedef struct Stack
{
    Node* top;
} Stack;

void init(Stack* stack){
    stack->top=NULL;
}
int isEmpty(Stack* stack){
    if(stack->top==NULL){
        return 1;
    }else{
        return 0;
    }
}

void push(Stack* stack, char item){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data=item;
    node->next=stack->top;
    stack->top=node;
}
char pop(Stack* stack){
    if(isEmpty(stack)){
        printf("La pila esta vacia");
        return -1;
    }
    Node* node = stack->top;
    char item= stack->top->data;
    stack->top= node->next;
    free(node);
    return item;
}
int peek(Stack* stack){
    if(isEmpty(stack)){
        printf("La pila esta vacia");
        return -1;
    }
        return stack->top->data;
}
void imprimir(Stack* stack){
    if(isEmpty(stack)){
        printf("La pila esta vacia");
    }else{
        Node* node=stack->top;
        while(node!=NULL){
            printf("%d",node->data);
            node = node->next;
        }
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
int main(){
    Stack stack;
    char cadena[100];
    init(&stack);
    printf("Ingrese una expresion con parentesis, corchetes o llaves: ");
    fflush(stdout);
    if (fgets(cadena, sizeof(cadena), stdin) == NULL)
    {
        printf("Error al leer cadena.\n");
        return 1;
    }
    cadena[strcspn(cadena, "\n")] = '\0';

    if(balancear(&stack,cadena)){
        printf("estan balanceados");
    }else{
        printf("esta desbalanceados");
    }
}
