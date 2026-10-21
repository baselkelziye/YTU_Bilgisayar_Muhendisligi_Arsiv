#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
    int *data;
    int front;
    int rear;
    int size;
}Queue;

Queue* createQueue(int size) {
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    queue->data = (int*) malloc(size * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    return queue;
}

int isEmpty(Queue *queue) {
    return queue->front == -1;
}

int isFull(Queue *queue) {
    return queue->rear == queue->size - 1;
}

void enqueue(Queue *queue, int item) {
    if (isFull(queue)) {
        printf("\n Queue is full!\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear++;
    queue->data[queue->rear] = item;
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("\n Queue is empty!\n");
        return -1;
    }
    int item = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }
    return item;
}

int main() {
    Queue *queue = createQueue(5);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    printf("\n %d", dequeue(queue));
    enqueue(queue, 4);
    enqueue(queue, 5);
    printf("\n %d", dequeue(queue));
    printf("\n %d", dequeue(queue));
    printf("\n %d", dequeue(queue));
	
    return 0;
}
