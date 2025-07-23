#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Queue
{
    int data[MAX];
    int front;
    int rear;
} Queue;

void init(Queue *q)
{
    q->rear = -1;
    q->front = -1;
}

int isEmpty(Queue *q)
{
    return (q->front == -1 || q->rear == q->front);
}

void isFull(Queue *q)
{
    return (q->rear);
}

int main()
{
}