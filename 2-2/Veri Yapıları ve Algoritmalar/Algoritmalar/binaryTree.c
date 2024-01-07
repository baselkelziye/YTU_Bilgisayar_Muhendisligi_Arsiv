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

TREE* insertBinaryTree(TREE *root,int tmp){
	if(root==NULL)
	return newNode(tmp);
	
	if(tmp< root->data)
	root->left=insertBinaryTree(root->left,tmp);
	else if(tmp>root->data)
	root->right=insertBinaryTree(root->right,tmp);
	return root;
}

TREE* searchAtBinaryTree(TREE *root,int tmp){
	if(root==NULL || root->data==tmp)
	return root;
	
	if(tmp<root->data)
	return searchAtBinaryTree(root->left,tmp);
	
	return searchAtBinaryTree(root->right,tmp);
}

TREE *minValueNode(TREE *node){
	TREE *current=node;
	while(current && current->left!=NULL)
	current=current->left;
	
	return current;
}

TREE* deleteNode(TREE *root,int key){
	if(root==NULL)
		return root;
	
	if(key<root->data)
		root->left=deleteNode(root->left,key);
	
	else if(key>root->data)
		root->right=deleteNode(root->right,key);
	
	else{
		if(root->left==NULL){
			TREE *tmp=root->right;
			free(root);
			return tmp;
		}else if(root->right==NULL){
			TREE *tmp=root->left;
			free(root);
			return tmp;
		}
		TREE *tmp=minValueNode(root->right);
		root->data=tmp->data;
		root->right=deleteNode(root->right,tmp->data);
	}
	return root;
}

int main(){
	TREE *root=NULL;
	int i,n,tmp,opt=1;
	printf("Enter The Number Of Element: "); scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("%d.Number: ",i+1); scanf("%d",&tmp);
		root=insertBinaryTree(root,tmp);
	}
	while(opt!=0){
		printf("\nAdd Element 1\nSearch Element 2\nOrder Tree 3\nDelete A Node 4\nClose The Program 0\nWhich One: "); scanf("%d",&opt);
		if(opt==1){
			printf("Enter A Number: "); scanf("%d",&tmp);
			root=insertBinaryTree(root,tmp);
		}else if(opt==2){
			printf("Enter A Number To Wanted: "); scanf("%d",&tmp);
			TREE *found=NULL;
			found=searchAtBinaryTree(root,tmp);
			if(found==NULL){
				printf("Element Has Not Found\n");
			}else{
				printf("%d Has Found\n",found->data);
			}
		}else if(opt==3){
			printf("Inorder: ");
			inOrderTraversal(root);
			printf("\nPreorder: ");
			preOrderTraversal(root);
			printf("\nPostOrder: ");
			postOrderTraversal(root);
		}else if(opt==4){
			printf("Enter A Number To Delete: "); scanf("%d",&tmp);
			root=deleteNode(root,tmp);
		}else{
			opt=0;
		}
	}
	
	return 0;
}
