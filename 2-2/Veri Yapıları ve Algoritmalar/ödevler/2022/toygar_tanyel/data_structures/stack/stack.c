#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct n{
    int item[MAX];
    int top;
};
typedef struct n STACK;

int isFull(STACK*);
int isEmpty(STACK*);
void push(STACK*, int);
void pop(STACK*);
void top(STACK*, int*);
void initStack(STACK*);
void print(STACK*);

int main(){

    STACK *s = (STACK*)malloc(sizeof(STACK));
    initStack(s);
    pop(s);
    push(s, 50);
    push(s, 60);
    push(s, 85);
    push(s, 70);
    push(s, 90);
    push(s, 92);
    print(s);

    pop(s);
    printf("We can hold %d until next pop.\n", s->item[s->top]);
    pop(s);
    printf("We can hold %d until next pop.\n", s->item[s->top]);
    push(s, 15);
    push(s, 20);
    pop(s);
    printf("We can hold %d until next pop.\n", s->item[s->top]);
    push(s, 15);
    push(s, 30);
    push(s, 45);
    push(s, 20);
    push(s, 15);
    push(s, 80);


    print(s);
}

void print(STACK* s){
    printf("STACK:\n");
    for(int i = s->top-1; i >= 0; i--){
        printf("|%d|\n", s->item[i]);
    }
}

void initStack(STACK* s){
    s->top = 0;
}

int isFull(STACK* s){
    if(s->top == MAX)
        return 1;
    else
        return 0;
}

int isEmpty(STACK* s){
    if(s->top == 0)
        return 1;
    else
        return 0;
}

void push(STACK* s, int x){
    if(isFull(s))
        printf("The stack is full. You cannot add '%d' to the stack\n", x);
    else{
        s->item[s->top++] = x;
        printf("Value: %d is pushed to the stack.\n", s->item[s->top-1]);
    }
}

void pop(STACK* s){
    if(isEmpty(s))
        printf("The stack is empty.\n");
    else
        printf("The popped value: %d\n", s->item[--s->top]);
}

void top(STACK* s, int *x){
    int adr;
    if (isEmpty(s))
        printf("The stack is empty.");
    else{
        adr = s->top-1;
        *x = s->item[adr];
    }

}