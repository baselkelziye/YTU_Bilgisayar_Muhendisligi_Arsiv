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
int main(){
	PNODE *head;
	TERM t1={1,1};
	TERM t2={2,2};
	TERM t3={3,3};
	PNODE n1;
	PNODE n2;
	PNODE n3;
	n1.data=t1;
	n2.data=t2;
	n3.data=t3;
	
	n1.next = &n2;
	n2.next = &n3;
	n3.next = NULL;
	head = &n1;
	printList(head);
}

void printList(PNODE *node){
	if(node == NULL) printf("Dizi boþ");
	else{
		while(node->next!=NULL){
			printf("%d^%d+",node->data.katsayi,node->data.derece);
			node = node->next;
		}
		printf("%d^%d",node->data.katsayi,node->data.derece);
	}
} 
