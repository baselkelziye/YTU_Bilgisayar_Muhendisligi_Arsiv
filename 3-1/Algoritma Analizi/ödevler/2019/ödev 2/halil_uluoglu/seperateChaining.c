#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int key;
	char name[40];
	struct node *next;
}List;

typedef struct node2
{
	struct node2 *head;
	int count;
}HASH;

HASH *hashTable=NULL;


void insert(int key,char name[],int m);
List *createNode(int key,char name[]);

int main()
{
	int m,key;
	char name[40];
	
	printf("Enter respectively table size and key value, please.\n");
	scanf("%d %d", &m, &key);
	
	printf("Enter the name, please.\n");
	scanf("%s", name);
	
	hashTable=(HASH *)calloc(sizeof(HASH),m);
	if(hashTable==NULL)
	{
		printf("[ERROR!]Hash table could not created.\n");
		exit(-1);
	}
	
	insert(key,name,m);
	printf("[INFO!]Your inputs inserted.\n");
	
	
	return 0;
}

void insert(int key,char name[],int m)
{
	int addr=key%m;
	List *newNode=createNode(key,name);
	if(newNode==NULL)
	{
		printf("[ERROR!]Your new node could not created.\n");
		exit(-2);
	}
	
	if(!hashTable[addr].head)
	{
		hashTable[addr].head=newNode;
		hashTable[addr].count=1;
	}
	else
	{
		newNode->next=hashTable[addr].head;
		hashTable[addr].head=newNode;
		hashTable[addr].count++;
	}
}

List *createNode(int key,char name[])
{
	List *node=(List *)calloc(sizeof(List),1);
	if(node==NULL)
	{
		printf("[ERROR!]Your new node could not created.\n");
		exit(-3);
	}
	node->key=key;
	strcpy(node->name,name);
	node->next=NULL;
	
	return node;
}
