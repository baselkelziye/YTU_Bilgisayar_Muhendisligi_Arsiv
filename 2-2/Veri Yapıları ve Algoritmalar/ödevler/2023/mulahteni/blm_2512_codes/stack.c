#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int top;
    int size;
} Stack;

Stack* createStack(int size) {
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    stack->data = (int*) malloc(size * sizeof(int));
    stack->top = -1;
    stack->size = size;
    return stack;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == stack->size - 1;
}

void push(Stack *stack, int item) {
    if (isFull(stack)) {
        printf("\n Stack is full!");
        return;
    }
    stack->top++;
    stack->data[stack->top] = item;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("\n Stack is empty!");
        return -1;
    }
    int item = stack->data[stack->top];
    stack->top--;
    return item;
}

void peekTop(Stack *s/*, int *val*/){
	if(isEmpty(s)){
		printf("\n Stack is empty!");
		return;
	}
	printf("\n Top value : %d",s->data[s->top-1]);
}

int main() {
    Stack *stack = createStack(5);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    printf("\n %d", pop(stack));
    push(stack, 5);
    push(stack, 6);
    printf("\n %d", pop(stack));
    printf("\n %d", pop(stack));
    printf("\n %d", pop(stack));
	
    return 0;
}
