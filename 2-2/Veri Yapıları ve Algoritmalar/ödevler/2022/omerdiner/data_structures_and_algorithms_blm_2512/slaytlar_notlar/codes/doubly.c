#include<stdio.h>
#include<stdlib.h>

struct node{

	int val;
	struct node* next;
	struct node* prev;
};

typedef struct node NODE;
void push(NODE**,int);
void print(NODE**);
void insert(NODE**,int);
void del(NODE**,int);
int main(int argc, char** argv) {

	NODE* head = NULL;
	push(&head,15);
	push(&head,20);
	push(&head,25);
	insert(&head,30);
	push(&head,500);
	del(&head,1);
	print(&head);

}

void push(NODE** head, int val) {

	NODE* newnode = (NODE*)malloc(sizeof(NODE));
	if((*head)==NULL){
		newnode->next = NULL;
		newnode->prev = NULL;
		newnode->val = val;
		(*head)=newnode;
	}

	else{
		newnode->val = val;
		newnode->next=(*head);
		newnode->prev = NULL;
		(*head)->prev = newnode;
		(*head)=newnode;
	}
}

void print(NODE** head) {

	NODE* current = *head;
	while(current->next != NULL){
		printf("%p,%d - ",current,(current)->val);
		current=current->next;
	}
	printf("%p,%d\n",current,(current)->val);
}

void insert(NODE** head, int val) {


	NODE* current = *head;
	NODE* newnode = (NODE*)malloc(sizeof(NODE));
	while(current->next != NULL) {
		current= current->next;
	}
	newnode->val = val;
	newnode->next = NULL;
	newnode->prev = current;
	current->next = newnode;
}

void del(NODE** head, int position) {

	NODE* current = *head;
	if(*head==NULL) {
		printf("ERROR: Non-initialized head");
		exit(0);
	}
	else{
		while(current->next != NULL && position != 0) {
			current=current->next;
			position--;
		}
		if(current->next == NULL) {
			if(current == *head) {
				printf("does it even work?");
				current->next->prev = NULL;
				(*head)=current->next;
			}
			else{
				current->prev->next = NULL;
				free(current);
			}
		}
		else{
			current->prev->next = current->next;
			current->next->prev = current->prev;
		}
	}
}
