#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
	int data;
	struct tree *left;
	struct tree *right; 
}TREE;

TREE* newNode(int data) {
  TREE *node = (TREE*)malloc(sizeof(TREE));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void inOrderTraversal(TREE *root){
	if(root==NULL)
	return ;
	inOrderTraversal(root->left);
	printf(" %d -->",root->data);
	inOrderTraversal(root->right);	
}

void preOrderTraversal(TREE *root){
	if(root==NULL)
	return ;
	printf(" %d -->",root->data);
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

void postOrderTraversal(TREE *root){
	if(root==NULL)
	return ;
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	printf(" %d -->",root->data);
}

int main(){
	TREE *root=NULL;
	root=newNode(5);
	root->left=newNode(15);
	root->left->left=newNode(7);
	root->left->right=newNode(9);
	root->right=newNode(8);
	printf("Inorder: ");
	inOrderTraversal(root);
	printf("\nPreorder: ");
	preOrderTraversal(root);
	printf("\nPostOrder: ");
	postOrderTraversal(root);
	return 0;
}

