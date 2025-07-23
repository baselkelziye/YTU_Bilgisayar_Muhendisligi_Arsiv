#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Queue
{
    int data[MAX];
    int front;
    int rear;
} Queue;

void initialize(Queue *q)
{
    q->front = 0;
    q->rear = 0;
}

int isEmpty(Queue *q)
{
    return (q->front == q->rear);
}

int isFull(Queue *q)
{
    return (q->rear >= MAX - 1);
}

// int isFull_circular(Queue *q)
// {
//     return ((q->rear + 1) % MAX == q->front);
// }

int enqueue(Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Overflow !! \n");
        return 0;
    }

    q->data[q->rear++] = value;

    return 1;
}

int dequeue(Queue *q, int *value)
{
    if (isEmpty(q))
    {
        printf("Queue Empty!! \n");
        return 0;
    }

    *value = q->data[q->front++];
    return 0;
}

int size(Queue *q)
{
    return (q->rear - q->front);
}

void display(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue (front to rear): ");
    for (int i = q->front; i < q->rear; i++)
    {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main()
{
    Queue myQueue;
    initialize(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);
    display(&myQueue);
    int val;

    dequeue(&myQueue, &val);

    printf("Dequeued: %d\n", val);
    // printf("Front element: %d\n", peek(&myQueue));
    display(&myQueue);

    return 0;
}