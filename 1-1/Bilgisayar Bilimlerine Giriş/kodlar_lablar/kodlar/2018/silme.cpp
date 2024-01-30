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
	printf("\n");
}

void sonaEkle(node * kutu, int data){
	while( kutu -> next != NULL ){
		kutu = kutu -> next;
	}
	kutu -> next = (node *)malloc(sizeof(node));
	kutu -> next -> data = data;
	kutu -> next -> next = NULL; 
}

node * sil(node * root,int data){
	node * temp;
	node * iter = root;
	if(root->data == data){
		temp = root;
		root = root->next;
		free(temp);
		return root;
	}
	while(iter->next != NULL && iter->next->data != data){
		iter = iter->next;
	}
	if(iter->next == NULL){
		printf("sayi yok\n");
		return root;
	}
	temp = iter->next;
	iter->next = temp->next;
	free(temp);
	return root;
}

int main(){
	node * root;
	root = (node *)malloc(sizeof(node));
	root -> next = NULL;
	root -> data = 500;
	int i;
	for( i = 0; i < 6; i++ )
		sonaEkle(root,i*-10);
	yazdir(root);
	root = sil(root,-10);yazdir(root);//sil root'u döndürdüðünden her çaðýrdýðýnda root'a ata
	root = sil(root,-50);yazdir(root);
	root = sil(root,10);yazdir(root);
	root = sil(root,500);yazdir(root);
	
	return 0;
}
