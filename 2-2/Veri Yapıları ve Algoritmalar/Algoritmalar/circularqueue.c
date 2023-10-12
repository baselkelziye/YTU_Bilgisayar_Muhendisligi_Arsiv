#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct {
	int rear;
	int front;
	int item[MAX];
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

int isFull(queue *q){
	if(q->rear+1==q->front || (q->front==0 && q->rear==MAX-1))
	return 1;
	return 0;
}

int deQueue(queue *q, int *x){
	if(isEmpty(q))
	return 0;
	else{
		*x=q->item[q->front];
		if(q->front==q->rear){
			q->front=-1;
			q->rear=-1;
		}else{
			q->front=(q->front+1)%MAX;
			return 1;
		}
	}
}

int enQueue(queue *q,int x){
	if(isFull(q))
	return 0;
	else if(q->front==-1){
		q->front=0;
	}
	q->rear=(q->rear+1)%MAX;
	q->item[q->rear]=x;
	return 1;
}

int main(){
	
	queue *q;
	q=(queue*)malloc(sizeof(queue));
	initQueue(q);
	int opt=1;
	
	while(opt!=0){
		int val,sit;
		printf("Press 1 To Add Element To Queue\nPress 2 To Remove Element To Queue\nPress 0 To Shut The Program\nWhich One: ");
		scanf("%d",&opt);
		if(opt==1){
			printf("Enter The Element To Add: "); scanf("%d",&val);
			sit=enQueue(q,val);
			if(sit==0){
				printf("Queue Is Full!\n");
			}else{
				printf("%d Has Added Succesfully\n",val);
			}
		}else if(opt==2){
			sit=deQueue(q,&val);
			if(sit==0){
				printf("Queue Is Empty!\n");
			}else{
				printf("%d Has Removed From Queue\n",val);
			}
		}else{
			opt=0;
		}
	}
	
	return 0;
}
