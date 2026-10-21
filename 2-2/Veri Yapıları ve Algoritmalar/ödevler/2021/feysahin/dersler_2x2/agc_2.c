#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

//CIRCULAR LINKED LIST

typedef struct node{
	int data;
	struct node *next;
}NODE;

NODE *newNode();
void traverse(NODE **);
void josephus(NODE **, int, int);

int main(){
	
	NODE *head = newNode();
	NODE *tmp = head, *tmp2;
	int i, n, k, start;
	
	printf("n: ");
	scanf("%d", &n);
	
	tmp->data=1;
	
	for(i=1; i<n; i++){
		tmp2 = newNode();
		tmp2->data = i+1;
		
		tmp->next = tmp2;
		tmp = tmp2;
	}
	tmp->next = head;
	
	printf("\nk: ", &k);
	scanf("%d", &k);
	printf("\nstart: ", &start);
	scanf("%d", &start);
	
	josephus(&head,k,start);
		
	//traverse(&head);
	
	return 0;
}

void josephus(NODE **phead, int k, int start){
	NODE *tmp=*phead;
	int i;
	
	//start'ý bulma
	while(tmp->data!=start){
		tmp=tmp->next;
	}
	
	//elenme
	while(tmp->next!=tmp){
		for(i=1; i<k; i++){
			tmp=tmp->next;
		}
		printf("\nsilinen: %d", tmp->next->data);
		tmp->next = tmp->next->next;
	}
	printf("\nsona kalan: %d", tmp->data);
}

void traverse(NODE **phead){
	NODE *tmp = *phead;
	
	while(tmp != NULL){
		printf("%d ", tmp->data);
		tmp = tmp->next;
		sleep(1);
	}
}

NODE *newNode(){
	return (NODE*)malloc(sizeof(NODE));
}
