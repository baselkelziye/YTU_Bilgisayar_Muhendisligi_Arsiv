#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Stack
{
    int item[MAX];
    int top;
} Stack;

void initialize(Stack *s)
{
    s->top = -1;
}

int isEmpty(Stack *s)
{
    return (s->top == -1);
}

int isFull(Stack *s)
{
    return (s->top == (MAX - 1));
}

void push(Stack *s, int data)
{
    if (isFull(s))
    {
        printf("Stack Overflow !!\n");
    }
    else
    {
        s->item[++s->top] = data;
    }
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow !!\n");
    }
    else
    {
        return (s->item[s->top--]);
    }
}

int peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is Empty\n");
        return -1;
    }
    else
    {
        return (s->item[s->top]);
    }
}

void display(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack (top to bottom): ");
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d ", s->item[i]);
    }
    printf("\n");
}

int size(Stack *s)
{
    return s->top + 1;
}

int main()
{
    Stack myStack;
    initialize(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);
    display(&myStack);

    printf("Popped: %d\n", pop(&myStack));
    printf("Top element: %d\n", peek(&myStack));
    display(&myStack);
}