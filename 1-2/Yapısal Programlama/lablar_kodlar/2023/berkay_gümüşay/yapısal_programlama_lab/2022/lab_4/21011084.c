#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct Node{
	int key;
	int v1;
	struct Node *next;
}Node;
void printList(Node* n);// Verilen linkli listeyi yazdýrýr 10 +
void insert(struct Node** head_ref, int key, int v1);// verilern degerlere sahip node u linked listin sonuna ekler 10 +
Node* reduce(Node* start1, Node* start2, int (*reduce_f)(Node*, Node* ) ); // key deðerlerine göre sýralý iki linki listenin-
// keylerinin verilen fonksiyon þartýna göre birleþimini bulur, yeni bir likli liste olarak döndürür 60

int reduce_sum(Node* Node1, Node* Node2);// keyleri ayný olan 2 node un v1 deðerlerinin toplamýný döner 10
int reduce_max(Node* Node1, Node* Node2);// keyleri ayný olan 2 node un v1 deðerlerinden max olanýný döner 10
int main() {
	Node *start = NULL;
	insert(&start, 1, 10); insert(&start, 2, 20); insert(&start, 4, 20); insert(&start, 7, 30);
	printList(start);printf("\n");
	Node *start2 = NULL;
	insert(&start2, 1, 10); insert(&start2, 4, 25); insert(&start2, 7, 25);
	printList(start2);
	
	Node* node3 = reduce(start, start2, reduce_sum);
	printList(node3);
	Node* node4 = reduce(start, start2, reduce_max);
	printList(node4);
	
	
	
	return 0;
}

void printList(Node* n){
	Node *tmp = n;
	while(tmp != NULL){
		printf("key  : %d - v1 : %d -->",tmp->key,tmp->v1);
		tmp = tmp->next;
	}
}
void insert(struct Node **head_ref, int key, int v1){
	Node *tmp;
	tmp = *head_ref;
	while(tmp != NULL){
		tmp = tmp->next;
	}
	tmp = (Node*)malloc(sizeof(Node));
	tmp->v1 = v1;
	tmp->key = key;
	tmp->next = NULL;
	*head_ref = tmp;
	
}
Node* reduce(Node* start1,Node* start2,int (*reduce_f)(Node* n1, Node* n2)){
	Node *Node3;
	Node *tmp1 = start1;
	Node *tmp2 = start2;
}
int reduce_sum(Node* Node1, Node* Node2){
	int tmp;
	tmp = (Node1->v1 + Node2->v1);
	return tmp;
}
int reduce_max(Node* Node1, Node* Node2){
	if((Node1->v1) >= (Node2->v1)){
		return Node1->v1;
	}
	else{
		return Node2->v1;
	}
}
