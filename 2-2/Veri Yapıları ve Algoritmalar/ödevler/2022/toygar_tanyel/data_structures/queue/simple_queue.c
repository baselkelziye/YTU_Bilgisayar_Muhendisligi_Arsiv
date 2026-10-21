#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct n{
    int item[MAX];
    int front;
    int rear;
};
typedef struct n queue;

int isFull(queue*);
int isEmpty(queue*);
void enqueue(queue*, int);
void dequeue(queue*);
void initQueue(queue*);
void print(queue*);

int main(){

    queue *q = (queue*)malloc(sizeof(queue));
    initQueue(q);

    enqueue(q, 5);
    print(q);
    enqueue(q, 15);
    print(q);
    enqueue(q, 25);
    enqueue(q, 35);
    enqueue(q, 45);
    enqueue(q, 55);
    enqueue(q, 65);
    enqueue(q, 12);
    enqueue(q, 13);
    enqueue(q, 14);
    enqueue(q, 99);
    print(q);
    dequeue(q);
    dequeue(q);
    print(q);
    dequeue(q);
    print(q);

    return 0;
}

void initQueue(queue *q){
    q->front = -1;
    q->rear = -1;
}

void print(queue* q){
    printf("QUEUE: ");
    int i;
    for(i = q->front-1; i < q->rear; i++){
        printf("|%d| ", q->item[i]);
    }
    printf("\n\n");
}

int isEmpty(queue *q){
    if(q->front == -1)
        return 1;
    else
        return 0;
}

int isFull(queue *q){
    if(q->rear == MAX-1)
        return 1;
    else
        return 0;
}

void enqueue(queue *q, int value){
    if(isFull(q))
        printf("\nThe queue is full. You cannot add '%d' to the queue\n", value);
    else{
        if(isEmpty(q))
            q->front++;
        q->item[q->rear++] = value;
        printf("\nElement '%d' is added to the queue.\n", value);
        }
}

void dequeue(queue *q){
    if(isEmpty(q))
        printf("\nThe queue is empty.\n");
    else
        printf("\nElement '%d' is removed from the queue.\n", q->item[(q->front++)-1]);
}