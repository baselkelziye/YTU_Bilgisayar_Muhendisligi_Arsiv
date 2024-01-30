#include <stdio.h>
#include <stdlib.h>

struct n{
	int data;
	n * next;
};

typedef n node;

void yazdir(node * box){
	while(box != NULL){
		printf("%d ", box -> data);
		box = box -> next;
	}
}

void sonaEkle(node * kutu, int data){
	while( kutu -> next != NULL ){
		kutu = kutu -> next;
	}
	kutu -> next = (node *)malloc(sizeof(node));
	kutu -> next -> data = data;
	kutu -> next -> next = NULL; 
}

node * siraliEkle(node * kutu, int data){
	if(kutu == NULL){
		kutu = (node *)malloc(sizeof(node));
		kutu -> next = NULL;
		kutu -> data = data;
		return kutu;
	}
	else if(kutu -> next == NULL){
		if(kutu -> data > data){
			node *temp = (node *)malloc(sizeof(node));
			temp -> data = data;
			temp -> next = kutu;
			kutu = temp;+-
		}
	}
	
}

int main(){
	node * root;
	root = NULL;
	siraliEkle(root,450);
	siraliEkle(root,4);
	siraliEkle(root,45);
	siraliEkle(root,400);
	siraliEkle(root,-4);
	//root = (node *)malloc(sizeof(node));
	//root -> next = NULL;
	//root -> data = 500;
	int i;
	//for( i = 0; i < 6; i++ )
	//	sonaEkle(root,i*-10);
	yazdir(root);printf("\n");
	node *iter = root;
	for(i=0;i<3;i++){
		iter = iter -> next;
	}
	node * temp = (node *)malloc(sizeof(node));
	temp -> next = iter -> next;//sýrasý
	iter -> next = temp;//önemli
	temp -> data = -25;
	yazdir(root);
	
	return 0;
}
