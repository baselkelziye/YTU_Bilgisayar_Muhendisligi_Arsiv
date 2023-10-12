#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int rear;
	int front;
	int **item;
}queue;

int initQueue(queue *q){
	q->front=-1;
	q->rear=-1;
}

int isEmpty(queue *q){
	if(q->front==-1)
	return 1;
	return 0;
}

int isFull(queue *q,int n){
	if(q->rear+1==q->front || (q->front==0 && q->rear==n-1))
	return 1;
	return 0;
}

int deQueue(queue *q, int *c,int *d,int *p,int n){
	if(isEmpty(q))
	return 0;
	else{
		*c=q->item[q->front][0];
		*d=q->item[(q->front+1)%n][1];
		*p=q->front;
		if(q->front==q->rear){
			q->front=-1;
			q->rear=-1;
		}else{
			q->front=(q->front+1)%n;
			return 1;
		}
	}
}

int enQueue(queue *q,int c,int d,int n){
	if(isFull(q,n))
	return 0;
	else if(q->front==-1){
		q->front=0;
	}
	q->rear=(q->rear+1)%n;
	q->item[q->rear][0]=c;
	q->item[q->rear][1]=d;
	return 1;
}

void pushTheQueue(queue *q,int n){
	int i,c,d;
	for(i=0;i<n;i++){
		printf("Enter The Petrol Capacity: "); scanf("%d",&c);
		printf("Enter The Another Petrol Pump Distance: "); scanf("%d",&d);
		enQueue(q,c,d,n);
	}
}

int checkWhichPumpBegin(queue *q,int n){
	int c,d,i,p;
	
	while(deQueue(q,&c,&d,&p,n)){
		if(c>=d){
			return p;
		}
	}
	return -1;
}

int main(){
	queue *q=(queue*)malloc(sizeof(queue));
	initQueue(q);
	int n,i,sit;
	printf("Enter The Number Of Petrol Pump: "); scanf("%d",&n);
	q->item=(int **)malloc(n*sizeof(int*));
	for(i=0;i<n;i++){
		q->item[i]=(int*)malloc(2*sizeof(int));
	}
	pushTheQueue(q,n);
	sit=checkWhichPumpBegin(q,n);
	if(sit!=-1){
		printf("Begin At %d.Pump",sit);
	}else{
		printf("You Can't Begin Any Pump");
	}
	return 0;
}
