#include <stdio.h>
#include <stdlib.h>

struct n {//typedef struct
	int data;
	n * next;
};

typedef n node;

int main(){
	node * root;
	root = (node *)malloc(sizeof(node));//ilk kutucu�u(komple veri �nitesini) g�steriyor(node * tipinde bir pointer)
	root -> data = 10;//root'un g�sterdi�i kutucu�un data k�sm�na 10 koy
	root -> next = (node *)malloc(sizeof(node));//ilk kutucu�un pointer'�na bir kutucuk daha ba�lad�m
	root -> next -> data = 20;//root'un next'inin data de�erine 20 koy
	root -> next -> next = (node *)malloc(sizeof(node));
	root -> next -> next -> data = 30;
	node * iter;// node * tipinde pointer ile linked list �zerinde gezinece�iz
	iter = root; 
	printf("%d",iter -> data);
	iter = iter -> next;
	printf("%d",iter -> data);
	
	
	
	
	/*for(int i = 1; i<= 3; i++){
		
	}*/
	
	
}
