#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}NODE;

NODE *createNode();

void traverse();
void enterArray(NODE **, int);
void reverse(NODE **);

int main(){
	
	NODE *root = (NODE*)malloc(sizeof(NODE));
	int n;
	
	printf("How many numbers do you want to create an array: ");
	scanf("%d", &n);
	
	enterArray(&root,n);
	traverse(&root);

	reverse(&root);
	traverse(&root);
	
	free(root);
	return 0;
}

void reverse(NODE **proot)
{
	NODE *tmp, *tmp2, *newList;
	
	tmp = *proot;
	tmp2 = tmp->next;
	newList = (NODE*)malloc(sizeof(NODE));
	
	//ilk elemaný alarak yeni listenin son elemanýný oluþturma
	newList = tmp;
	newList->next = NULL;
	tmp = tmp2;
	tmp2 = tmp2->next;
	
	while(tmp2->next != NULL){
		tmp->next = newList;
		newList = tmp;
		
		tmp = tmp2;
		tmp2 = tmp2->next;
	}
	//kalan son 2 elemaný da yeni listenin baþýna ekleme
	tmp->next = newList;
	newList = tmp;
	tmp2->next = newList;
	newList = tmp2;
	*proot = newList;
}

void enterArray(NODE **proot, int n)
{
	NODE *node = createNode();
	*proot = node;
	
	int i;
	while(i<n-1){
		node->next = createNode();
		node = node->next;
		i++;
	}
}

void traverse(NODE **proot)
{
	NODE *node = *proot;
	while(node != NULL){
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

NODE *createNode()
{
	NODE *node = (NODE*)malloc(sizeof(NODE));
	int d;
	printf("num: ");
	scanf("%d", &d);	
	node->data = d;
	node->next = NULL;
	return node;
}
