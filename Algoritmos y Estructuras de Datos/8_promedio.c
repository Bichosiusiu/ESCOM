#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
} Queue;

void initialize(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->size=0;
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
    queue->size++;
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
    queue->size--;
    return data;
}
int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("La cola está vacía. No se puede obtener el elemento frontal.\n");
        return -1;
    }
    return queue->front->data;
}
int medio(Queue* queue) {
    if (isEmpty(queue)) {
        printf("La cola está vacía. No se puede invertir.\n");
        return -1;
    }
    Node* c = queue->front;
    int d=0;
    while (c != NULL) {
        d += c->data;
        c = c->next;
    }
    return d;
}
void imprimir(Queue* queue) {
    if (isEmpty(queue)) {
        printf("La cola está vacía.\n");
        return;
    }
    Node* c = queue->front;

    while (c != NULL) {
        printf("%d ", c->data);
        c = c->next;
    }

    printf("\n");
}
int main() {
    Queue queue;
    initialize(&queue);
    int  n;
    float t;

    printf("Ingrese el tamaño de la cola: ");
    scanf("%f", &t);

    printf("Ingrese los elementos de la cola:\n");
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        enqueue(&queue,n);
    }

    imprimir(&queue);
    printf("\nEl elemento medio de la cola es: %.2f",medio(&queue)/t);
    dequeue(&queue);
    dequeue(&queue);
    printf("\n");
    imprimir(&queue);
    printf("\nEl promedio de la cola es: %.2f",medio(&queue)/(t-2));
    printf("\nIngrese 3 elementos de la pila:\n");
    for (int i = 0; i < 3; i++) {
        scanf("%d", &n);
        enqueue(&queue,n);
    }

    imprimir(&queue);
    printf("\nEl elemento medio de la cola es: %.2f",medio(&queue)/(t+1));

    return 0;
}