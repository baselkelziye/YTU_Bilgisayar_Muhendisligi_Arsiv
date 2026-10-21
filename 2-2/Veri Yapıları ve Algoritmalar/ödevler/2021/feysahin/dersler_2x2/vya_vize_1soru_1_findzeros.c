#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int deger, satir, sutun;
	struct node *next;
}NODE;

void findZeros(NODE *, int, int);

int main(){
	int i, j, n=6, m=7, d;
	
	NODE *head = (NODE*)malloc(sizeof(NODE)), *tmp;
	printf("\n1-1: ");
	scanf("%d", &d);
	head->deger = d;
	head->satir = 0;
	head->sutun = 0;
	tmp = head;
	
	for(j=0; j<m; j++){
		for(i=0; i<n; i++){
			if(i!=0 || j!=0){
				printf("\n%d-%d: ", i+1, j+1);
				scanf("%d", &d);
				
				NODE *n = (NODE*)malloc(sizeof(NODE));
				n->deger = d;
				n->satir = i;
				n->sutun = j;
				tmp->next = n;
				tmp = n;
			}
		}
	}
	findZeros(head, n, m);
	
	return 0;
}

void findZeros(NODE *head, int n, int m){
	NODE *tmp = head;
	int i, j, sayac;
	
	for(j=0; j<m; j++){
		sayac=0;
		for(i=0; i<n; i++){
			if(tmp->deger==0){
				sayac++;
			}
			tmp = tmp->next;
		}
		if(sayac==n){
			printf("\n%d. sutun", j);
		}
	}
}
