#include<stdio.h>
#include<stdlib.h>


struct btree{
	int val;
	struct btree* right, *left;
};

typedef struct btree TREE;

TREE* insert(TREE*,int);
void printInorder(TREE*);

int main(int argc, char** argv) {


	TREE* root = NULL;
	root = insert(root,100);
	root = insert(root,60);
	root = insert(root,30);
	root = insert(root,20);
	root = insert(root,10);
	root = insert(root,25);
	root = insert(root,120);
	root = insert(root,110);
	root = insert(root,140);
	root = insert(root,-5);
	printInorder(root);


	return 0;
}

TREE* insert(TREE* root,int val) {


	if(root == NULL) {
		TREE* newnode = (TREE*)malloc(sizeof(TREE));
		newnode->val = val;
		newnode->left=NULL;
		newnode->right=NULL;
		return newnode;
	}
	if(val < root->val) {
		root->left = insert(root->left,val);
	}
	else{
		if(val > root->val) {
			root->right = insert(root->right,val);
		}
	}
	return root;

}

void printInorder(TREE* root){

	if(root == NULL) {
		return;
	}
	else{
		printInorder(root->left);
		printf("%d\n",root->val);
		printInorder(root->right);
	}
}
