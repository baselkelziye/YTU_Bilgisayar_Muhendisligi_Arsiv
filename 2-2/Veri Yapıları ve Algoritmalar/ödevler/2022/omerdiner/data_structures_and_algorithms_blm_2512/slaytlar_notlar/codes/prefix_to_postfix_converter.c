#include<stdio.h>
#include<stdlib.h>
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
	char string[20];
	head=(NODE*)malloc(sizeof(NODE));
	end_of_stack=(NODE*)malloc(sizeof(NODE));
	
	int i=0;
	for(stackinit(head,end_of_stack); scanf("%c",&c) != EOF; ) {
		while(c>='0' && c<='9') {
			string[i]=c;
			i++;
			scanf("%c",&c);
		}
		if(c==')') {
			string[i]=(char)pop(head);
			i++;
		}
		else if(c=='+') {
			push(head,(int) c);
		}
		else if(c=='*') {
			push(head,(int) c);
		}
		else if(c=='/') {
			push(head,(int) c);
		}
		
	}
	printf("\n\n\n\npostfix: ");
	for(i=0; string[i]!='\0'; i++) {
		printf("%c",string[i]);
	}
	return 0;
	
	
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

