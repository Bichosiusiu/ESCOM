#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void initialize(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error al asignar memoria para el nodo.\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("La cola está vacía. No se puede eliminar.\n");
        return -1;
    }

    Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return data;
}
int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("La cola está vacía. No se puede obtener el elemento frontal.\n");
        return -1;
    }
    return queue->front->data;
}
int count(Queue* queue){
    Node* c = queue->front;
    int co = 0;

    while (c != NULL) {
        co++;
        c = c->next;
    }

    return co;
}


int main() {
    Queue queue;
    initialize(&queue);
     if (!isEmpty(&queue)) {
        printf("Inicializa la cola.\nLa cola no esta vacia");
    } else {
        printf("Inicializa la cola,\nLa cola está vacía.\n");
    }

    printf("Numero de elementos de la cola: %d",count(&queue));
    printf("\nIngrese valores a la cola (ingrese 0 para terminar):\n");
    int v;
    while (1) {
        scanf("%d", &v);
        if (v == 0) {
            break;
        }
        enqueue(&queue, v);
    }
    printf("Numero de elementos de la cola: %d",count(&queue));
    return 0;
}