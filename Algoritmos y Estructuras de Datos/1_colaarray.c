#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5
typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initialize(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(Queue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

int isFull(Queue* queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

void enqueue(Queue* queue, int data) {
    if (isFull(queue)) {
        printf("La cola está llena. No se puede insertar el elemento.\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }

    queue->data[queue->rear] = data;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("La cola está vacía. No se puede eliminar.\n");
        return -1;
    }

    int data = queue->data[queue->front];

    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    return data;
}

int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("La cola está vacía. No se puede obtener el elemento frontal.\n");
        return -1;
    }
    return queue->data[queue->front];
}

int main() {
    Queue queue;
    initialize(&queue);
    int i, e;
    if(isEmpty){
        printf("Inicializa una cola.\n La cola esta vacia\n");
    }
    else{
        printf("Inicializa una cola. \nLa cola no esta vacia\n");
    }
        printf("Ingresa los valores de la cola: \n");
    for(i=0;i<3;i++){
        scanf("%d",&e);
        enqueue(&queue,e);
    }
    printf("Ingresa otro valor a la cola: \n");
        scanf("%d",&e);
        enqueue(&queue,e);
    if(!isEmpty)
        printf("\n La cola esta vacia\n");
    else{
        printf("\nLa cola no esta vacia\n");
    }
    return 0;
}