#include <stdio.h>
#include <stdlib.h>
typedef struct term{
	int derece;
	int katsayi;
}TERM;

typedef struct node{
	TERM data;
	struct node *next;
}PNODE;
void printList(PNODE *node);
PNODE* addNode(PNODE *head);
int main(){
	int flag;
	PNODE *head=NULL;
    do{	
    	head = addNode(head);
		printf("Devam etmek ister misiniz? "); 
    	scanf("%d",&flag);
	}while(flag!=0);
	
	printList(head);
	return 0;
}

PNODE* addNode(PNODE *head){
	TERM t;
	PNODE *node, *tmp;
	printf("Katsayi giriniz"); scanf("%d",&t.katsayi);
	printf("Derece giriniz"); scanf("%d",&t.derece);
	
	node = (PNODE*) malloc(sizeof(PNODE));
	node->data = t;
	node->next = NULL;
	
	if(head==NULL){
		head = node;
	}
	else{
		tmp = head;
		while(tmp->next!=NULL){
			tmp = tmp->next;
		}
		tmp->next = node;
	}
	
	return head;
}

void printList(PNODE *node){
	if(node == NULL) printf("Dizi boþ");
	else{
		while(node->next!=NULL){
			printf("[%p]>>%d^%d + \n",node,node->data.katsayi,node->data.derece);
			
			node = node->next;
		}
		printf("[%p]>>%d^%d",node,node->data.katsayi,node->data.derece);
	}
} 


