#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
    int size;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;
void initialize(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->size=0;
}
void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}
int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("La cola está vacía.\n");
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
int t(Queue* queue) {
    Node* current = queue->front;
    int size = 0;

    while (current != NULL) {
        size++;
        current = current->next;
    }

    return size;
}
void cambiar(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}
void burbuja(Queue* queue) {
    int size = t(queue);
    Node* current = queue->front;
    int i, j;

    for (i = 0; i < size - 1; i++) {
        current = queue->front;

        for (j = 0; j < size - i - 1; j++) {
            if (current->data > current->next->data) {
                cambiar(current, current->next);
            }

            current = current->next;
        }
    }
}
void imprimir(Queue* queue) {
    Node* temp = queue->front;
    printf("Cola: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue queue;
    initialize(&queue);
    int  n,j,k;
    int t;

    printf("Ingrese el tamaño de la cola: ");
    scanf("%d", &t);

    printf("Ingrese los elementos de la cola:\n");
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        enqueue(&queue,n);
    }
    imprimir(&queue);
    printf("\nElementos ordenados : ");
    burbuja(&queue);
    imprimir(&queue);
     printf("Ingrese 2 elementos en la cola:\n");
    for (int i = 0; i < 2; i++) {
        scanf("%d", &n);
        enqueue(&queue,n);
    }
    printf("\nElementos ordenados : ");
    burbuja(&queue);
    imprimir(&queue);

    return 0;
}