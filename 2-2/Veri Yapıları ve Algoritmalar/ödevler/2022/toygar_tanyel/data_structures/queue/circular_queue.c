#include <stdio.h>
#include <stdlib.h>

#define MAX 6

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

    printf("\n ________________________________________________________\n");
    printf("\n Imagine front and rear's indexes like [0, 1 ... MAX-1]\n");
    printf("\n We print elements like front is starting from beginning,\n but real index in static array will be as given below.\n");
    printf("\n ________________________________________________________\n");

    enqueue(q, 5);
    print(q);
    enqueue(q, 15);
    print(q);
    enqueue(q, 25);
    enqueue(q, 35);
    enqueue(q, 45);
    print(q);
    enqueue(q, 55);
    enqueue(q, 65);
    print(q);
    dequeue(q);
    dequeue(q);
    print(q);
    dequeue(q);
    enqueue(q, 13);
    enqueue(q, 14);
    enqueue(q, 99);
    print(q);

    return 0;
}

void initQueue(queue *q){
    q->front = -1;
    q->rear = -1;
}

void print(queue* q){
    int i;
    if (q->front == -1)
        printf(" \n Empty Queue\n");
    else {
        printf("\n Front index and element -> [%d]: %d", q->front, q->item[q->front]);
        printf("\n Items -> ");
        for (i = q->front; i != q->rear; i = (i + 1) % MAX) {
            printf("%d ", q->item[i]);
        }
        printf("%d ", q->item[i]);
        printf("\n Rear index and element -> [%d]: %d \n", q->rear, q->item[q->rear]);
    }
}

int isEmpty(queue *q){
    if(q->front == -1)
        return 1;
    else
        return 0;
}

int isFull(queue *q){
    if( (q->rear+1 == q->front) || (q->front == 0) && q->rear == MAX -1 )
        return 1;
    else
        return 0;
}

void enqueue(queue *q, int value){
    if(isFull(q))
        printf("\n** The queue is full. You cannot add '%d' to the queue **\n", value);
    else{
        if(q->front == -1)
            q->front = 0;
        
        q->rear = (q->rear+1) % MAX;
        q->item[q->rear] = value;
        printf("\n** Value '%d' is added to the queue. **\n", value);
    }
}

void dequeue(queue *q){
    if(isEmpty(q))
        printf("\n** The queue is empty. **\n");
    else{
        if( q->front == q->rear){
            printf("\n** Element '%d' is removed from the queue. **\n", q->item[q->front]);
            q->front = -1;
            q->rear = -1;
            printf("\n** You have no other element to remove from queue. **\n");
        }
        else{
        printf("\n** Element '%d' is removed from the queue. **\n", q->item[q->front]);
        q->front = (q->front+1) % MAX;
        }
    }
}