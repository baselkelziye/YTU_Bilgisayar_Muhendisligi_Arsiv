#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}NODE;

NODE *newNode();
void traverseRight(NODE **);
void traverseLeft(NODE **);

int main(){
	
	NODE *head = newNode();
	NODE *tmp = head, *tmp2;
	int i;
	
	printf("\ndata of new node: ");
	scanf("%d", &tmp->data);
	
	for(i=0; i<5; i++){
		tmp2 = newNode();
		printf("\ndata of new node: ");
		scanf("%d", &tmp2->data);
		
		tmp->right = tmp2;
		tmp2->left = tmp;
		tmp = tmp2;
	}
	//traverseRight(&head);
	traverseLeft(&head);
	
	return 0;
}

void traverseRight(NODE **phead){
	NODE *tmp = *phead;
	
	while(tmp != NULL){
		printf("%d ", tmp->data);
		tmp = tmp->right;
	}
}

void traverseLeft(NODE **phead){
	NODE *tmp = *phead;
	
	while(tmp->right != NULL){
		tmp = tmp->right;
	}
	while(tmp != *phead){
		printf("%d ", tmp->data);
		tmp = tmp->left;
	}
	printf("%d ", tmp->data);
}

NODE *newNode(){
	return (NODE*)malloc(sizeof(NODE));
}
