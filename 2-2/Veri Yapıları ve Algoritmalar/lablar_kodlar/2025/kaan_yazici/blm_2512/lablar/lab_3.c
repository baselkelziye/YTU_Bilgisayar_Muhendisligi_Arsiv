#include<stdio.h>
#include<stdlib.h>

/*
 * Write the code of the program that performs the operations mentioned and prints the TOTAL value in the related STACK to the screen in order, step by step, in C language.
 * It is desired to use a STACK to calculate the sum of two numbers read as input to two different QUEUEs from outside.
 *
 * Print the final version of the data structure you used in each Stack and Queue operation to the user.
 *
 * Note: It is recommended that both numbers be read from the outside from the least significant digit to the most significant digit. STACK and QUEUE functions are provided as is. Do not rewrite.
 *
 * Input: Number 1: 5 4 7 8 9
 * Number 2: 1 2 3
 *
 * Output: 5 4 9 1 2 
 */

typedef struct QUEUE{
	int *arr;
	int size;
	int queueEnd;
	int currItem;
} queue;

typedef struct STACK{
	int *arr;
	int size;
	int currP;
} stack;


stack* createStack(int size) {
	stack* newStack=(stack*)malloc(sizeof(stack));
	newStack->arr=(int*)malloc(size*sizeof(int));
	newStack->size=size;
	newStack->currP=0;
	return newStack;
}

void reSizeStack(stack *Stack) {
	printf("Resizing Stack from %d to %d\n",Stack->size,Stack->size*2);
	Stack->size*=2;
	Stack->arr=realloc(Stack->arr,Stack->size*sizeof(int));
}


void push(stack* Stack,int newItem) {
	Stack->arr[Stack->currP++]=newItem;
	if(Stack->currP==Stack->size)
		reSizeStack(Stack);
}

int pop(stack* Stack) {
	if(Stack->currP<=0)
		return NULL;
	return Stack->arr[--Stack->currP];
}


void printStack(stack* Stack) {
	int i;
	printf("Current Stack: ");
	for(i=0;i<Stack->currP;i++)
		printf("%d ",Stack->arr[i]);

	printf("\n");

}


queue* createQueue(int size) {
	queue* newQueue=(queue*)malloc(sizeof(queue));
	newQueue->arr=(int*)malloc(size*sizeof(int));
	newQueue->size=size;
	newQueue->queueEnd=0;
	newQueue->currItem=0;
	return newQueue;
}

void reSizeQueue(queue *Queue) {
	printf("Resizing Queue from %d to %d\n",Queue->size,Queue->size*2);
	Queue->size*=2;
	Queue->arr=realloc(Queue->arr,Queue->size*sizeof(int));
}


void enq(queue* Queue,int newItem) {
	Queue->arr[Queue->queueEnd++]=newItem;
	if(Queue->queueEnd==Queue->size)
		reSizeQueue(Queue);
}

int deq(queue* Queue) {
	if((Queue->currItem>=Queue->queueEnd)||(Queue->queueEnd==0))
		return NULL;
	return Queue->arr[Queue->currItem++];
}


void printQueue(queue* Queue) {
	int i;
	printf("Current Queue: ");
	for(i=Queue->currItem;i<Queue->queueEnd;i++)
		printf("%d ",Queue->arr[i]);

	printf("\n");

}

void freeQueue(queue* Queue) {
	free(Queue->arr);
	free(Queue);
}

void freeStack(stack* Stack) {
	free(Stack->arr);
	free(Stack);
}


int main() {
  fputs("Enter queue size: ", stdout);
  int n;
  fscanf(stdin, "%d", &n);

  if (n <= 0) {
    fputs("Illegal size!\n", stderr);
    exit(-1);
  }

  queue *q1 = createQueue(n);
  queue *q2 = createQueue(n);

  size_t i = 0;

  fputs("\nEnter queue 1: ", stdout);
  for (i = 0; i < n; ++i) {
    int temp;
    fscanf(stdin, "%d", &temp);
    enq(q1, temp);
  }

  fputs("\nEnter queue 2: ", stdout);
  for (i = 0; i < n; ++i) {
    int temp;
    fscanf(stdin, "%d", &temp);
    enq(q2, temp);
  }


  stack *s = createStack(n);

  size_t carry = 0;

  for (i = 0; i < n; ++i) {
    int digit_sum = deq(q1) + deq(q2);
    push(s, (digit_sum + carry) % 10);

    carry = (digit_sum+carry >= 10) ? 1 : 0;
  }

  fputs("\nSum: ", stdout);
  for (i = 0; i < n; ++i) {
    fprintf(stdout, "%d ", pop(s));
  }

	return 0;
}
