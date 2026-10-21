#include<stdio.h>
#include<stdlib.h>

typedef struct Q{
	int val;
	struct Q* next;
}QUEUE;

int isEmpty(QUEUE*);
void enqueue(QUEUE**,int);
void dequeue(QUEUE**,int*);
int main(int argc, char** argv) {


	QUEUE* q = NULL;
	int x;
	enqueue(&q,1);
	enqueue(&q,2);
	enqueue(&q,3);
	dequeue(&q,&x);
	printf("%d\n",x);

	return 0;
}

int isEmpty(QUEUE* front) {
	if(front == NULL) {
		return 1;
	}
	else{
		return 0;
	}
}

void enqueue(QUEUE** q, int val) {


	QUEUE* newnode = (QUEUE*)malloc(sizeof(QUEUE));
	newnode->val = val;
	if((*q) == NULL) {
		newnode->next = NULL;
		*q = newnode;
	}
	else{
		newnode->next = *q;
		*q = newnode;
	}

}

void dequeue(QUEUE** q, int* x) {


	if((*q) == NULL) {
		printf("Queue is empty");
	}
	else{
		QUEUE* current = *q;
		QUEUE* before = current;
		while(current->next != NULL) {
			before = current;
			current= current->next;
		}
		*x = current->val;
		before->next = NULL;
		free(current);
	}

}
