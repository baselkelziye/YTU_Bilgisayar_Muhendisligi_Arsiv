#include <stdio.h>
#include <stdlib.h>

struct n {//typedef struct
	int data;
	n * next;
};

typedef n node;

int main(){
	node * root;
	root = (node *)malloc(sizeof(node));//ilk kutucuðu(komple veri ünitesini) gösteriyor(node * tipinde bir pointer)
	root -> data = 10;//root'un gösterdiði kutucuðun data kýsmýna 10 koy
	root -> next = (node *)malloc(sizeof(node));//ilk kutucuðun pointer'ýna bir kutucuk daha baðladým
	root -> next -> data = 20;//root'un next'inin data deðerine 20 koy
	root -> next -> next = (node *)malloc(sizeof(node));
	root -> next -> next -> data = 30;
	node * iter;// node * tipinde pointer ile linked list üzerinde gezineceðiz
	iter = root; 
	printf("%d",iter -> data);
	iter = iter -> next;
	printf("%d",iter -> data);
	
	
	
	
	/*for(int i = 1; i<= 3; i++){
		
	}*/
	
	
}
