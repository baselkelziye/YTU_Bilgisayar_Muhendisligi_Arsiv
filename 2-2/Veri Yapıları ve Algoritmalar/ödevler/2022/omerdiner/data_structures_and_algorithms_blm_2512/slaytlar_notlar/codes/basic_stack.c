
#include<stdio.h>
#include<stdlib.h>
#define MODE 1 // 1: postfix calculation , 0: convert prefix to postfix
struct node{
	
	int val;
	struct node* next;
};
typedef struct node NODE;

void stackinit(NODE*,NODE*);
void push(NODE*,int);
int pop(NODE*);

int main() {
	
	NODE* head,*end_of_stack;
	char c;
	int x;
	char string[20];
	head=(NODE*)malloc(sizeof(NODE));
	end_of_stack=(NODE*)malloc(sizeof(NODE));
	stackinit(head,end_of_stack);
	push(head,6);
	push(head,8);
	printf("%d\n",head->next->val);
	printf("%d\n",head->next->next->val);
	int k= pop(head);
	printf("LIFO pop: %d",k);
	
}

void stackinit(NODE* head, NODE* end_of_stack) {
	
	head->next=end_of_stack;
	head->val=0;
	end_of_stack->next=end_of_stack;
}

void push(NODE* head,int num) {
	
	NODE* current = (NODE*)malloc(sizeof(NODE));
	
	current->val=num;
	current->next=head->next;
	head->next=current;
}

int pop(NODE* head) {
	
	int pop;
	NODE* current = (NODE*)malloc(sizeof(NODE));
	current= head->next;
	head->next=current->next;
	pop=current->val;
	free(current);
	return pop;
}

