
#include<stdio.h>
#include<stdlib.h>

struct node{
	
	int val;
	struct node* next;
};
typedef struct node NODE;
void allocate(NODE*,int);
void list(NODE*);
int main() {
	
	NODE* head;
	int n=9;
	head=(NODE*)malloc(sizeof(NODE));
	allocate(head,n);
	list(head);
	
	return 0;
}
void allocate(NODE* head,int n) {
	
	NODE* current=head;
	current->val=1;
	current->next=NULL;
	for(int i=2; i<=n; i++) {
		while(current->next!=NULL) {
			current=current->next;
		}
		current->next=(NODE*)malloc(sizeof(NODE));
		current->next->val=i;
		current->next->next=NULL;
	}
	current->next->next=(NODE*)malloc(sizeof(NODE));
	current->next->next=head;
}

void list(NODE* head) {
	
	NODE* current=head;
	printf("\n");
	int i;
	
	for(i=0; i<81; i++) {
		printf("%d\n",current->val);
		current=current->next;
	}		
}
	
	
