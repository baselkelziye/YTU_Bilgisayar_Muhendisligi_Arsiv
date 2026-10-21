#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}NODE;

NODE *createNode();

void traverse();
void enterArray(NODE **, int);
void oddEven(NODE **, NODE **);

int main(){
	
	NODE *root = (NODE*)malloc(sizeof(NODE));
	NODE *even = (NODE*)malloc(sizeof(NODE));
	int n;
	
	printf("How many numbers do you want to create an array: ");
	scanf("%d", &n);
	
	enterArray(&root,n);
	traverse(&root);

	oddEven(&root,&even);
	traverse(&even); //çift sayýlar
	traverse(&root); //tek sayýlar
			
	free(root);
	return 0;
}

void oddEven(NODE **proot, NODE **pEven){
	NODE *tmp = *proot, *node, *prev;
	NODE *tmpE = (NODE*)malloc(sizeof(NODE));
	tmpE = *pEven;
	int flag = 0;
	
	while(tmp != NULL){
		if(tmp->data % 2 == 0){
			if(flag == 0){
				tmpE->data = tmp->data;
				flag = 1;
			}
			else{
				node = (NODE*)malloc(sizeof(NODE));
				node->data = tmp->data;
				tmpE->next = node;
				tmpE = node;
			}
		}
		tmp = tmp->next;
	}
	tmpE->next = NULL;
	
	//asýl diziden çiftleri çýkartma
	tmp = *proot;
	prev = tmp;
	while(tmp != NULL){
		if(tmp->data % 2 == 0){
			if(tmp == *proot){
				*proot = tmp->next;
				prev = tmp->next;
				free(tmp);
				tmp = prev;
			}
			else if(tmp->next != NULL){
				prev->next = tmp->next;
				free(tmp);
				tmp = prev->next;
			}
			else{
				prev->next = NULL;
				free(tmp);
				tmp = prev->next;
			}
		}
		else{
			prev = tmp;
			tmp = tmp->next;
		}
	}
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
