#include<stdio.h>
#include<stdlib.h>

struct node{
	int val;
	struct node* next;
};
typedef struct node NODE;


int main(int argc, char** arv) {

	NODE* head=NULL;














return 0;
}

void insert(NODE** head, int val) {

		NODE* newnode = (NODE*)malloc(sizeof(NODE));
		NODE* current = *head;
		if(*head == NULL ) {
			newnode->val = val;
			newnode->next = NULL;

		while(current->next != (*head)) {
			current=current->next;
		}
		newnode->val = val;
		newnode->next = *head;
		current->next = newnode;
}

void print(NODE** head) {

	NODE* current = *head;
	while(current->next != (*head)) {
		printf("%p,%d - ",current,current->val);
		current = current->next;
	}
	printf("%p,%d\n",current,current->val;
}
