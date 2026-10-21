#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct node{
	int counter;
	char* address;
	struct node* prev;
	struct node* next;
}NODE;

typedef struct buffer{
	int T;
	int capacity; 
	int size;
	NODE* head;
	NODE* tail;
}BUFFER;

NODE* createNode(char* address);
void printBuffer(BUFFER* buffer);
NODE* search(BUFFER* buffer, char* address);
void readInput(BUFFER* buffer, char* address);
BUFFER* createBuffer(int capacity, int T);
void deleteBuffer(BUFFER* buffer);

int main(){
	int T, capacity, choice, done; //choice is used to ask whether input is from file or not whereas done is used to ask whether to delete buffer or finish etc.
	char* address = (char*) malloc(MAX * sizeof(char)); //address is used to take each address from input
	char* filename = (char*) malloc(MAX * sizeof(char)); //filename is used in case user wants to give input from file
	BUFFER* buffer = NULL;
	printf("threshold value for each node: ");
	scanf("%d", &T);
	printf("buffer capacity: ");
	scanf("%d", &capacity);
	buffer = createBuffer(capacity, T);
	printf("\nenter 1 to give addresses from file... \nenter 0 to give them on console...");
	printf("\nchoice: ");
	scanf("%d", &choice);
	
	if(choice){
		printf("filename: ");
		scanf("%s", filename);
		FILE* file = fopen(filename, "r");
		if(file == NULL){
			printf("file not found...");
			return 1;
		}
		while(fscanf(file, " %[^\n]s", address) == 1){
			readInput(buffer, address);
			printBuffer(buffer);
		}
	}
	else{
		do{
			printf("\naddress: ");
			scanf(" %[^\n]s", address);
			readInput(buffer, address);
			printBuffer(buffer);
			printf("\nenter 1 to continue...\nenter 2 to delete buffer...\nenter 0 to finish...");
			printf("\nchoice: ");
			scanf("%d", &done);
			if(done == 2){
				deleteBuffer(buffer);
				buffer = createBuffer(capacity, T);
			}
		} while(done);
	}
	
	deleteBuffer(buffer);
	
	return 0;
}

/*
@brief creates a node for a given address if that node is not already created

@param address: address that will be the address of the new node

@return pointer that stores the address of the created node
*/

NODE* createNode(char* address){
	NODE* node = (NODE*) malloc(sizeof(NODE));
	node->address = (char*) malloc((strlen(address) + 1) * sizeof(char));
	strcpy(node->address, address);
	node->counter = 1;
	node->next = node->prev = NULL;
	return node;
}

/*
@brief prints the buffer

@param buffer: pointer to the buffer

@return
*/

void printBuffer(BUFFER* buffer){
	NODE* head = buffer->head;
	if(head == NULL) return;
	while(head -> next != NULL){
		printf("%s - %d <-> ", head->address, head->counter);
		head = head -> next;
	}
	printf("%s - %d\n", head->address, head->counter);
}

/*
@brief searches for a node whose address is the given address

@param buffer: pointer to the buffer
@param address: address to search for in the buffer

@return pointer to the node with given address if found, otherwise null
*/

NODE* search(BUFFER* buffer, char* address){
	NODE* head = buffer->head;
	
	while(head != NULL && strcmp(address, head->address)){//repeats when we dont arrive in the end of the buffer and current node's address is not the one we are looking for
		head = head->next;
	}
	
	return head;
}

/*
@brief updates the buffer according to given address 

@param buffer: pointer to the buffer
@param address: address that buffer will be updated according to 

@return
*/

void readInput(BUFFER* buffer, char* address){
	NODE* node = search(buffer, address); //calling search function for the param address
	
	if(node == NULL){//if node became null after search function, then there is not a node with that address so we should add a new node
		if(buffer->capacity == buffer->size){//if buffer is full, then we should drop the tail to be able to add a new node
			NODE* temp = buffer->tail;
			buffer->tail = buffer->tail->prev;
			if(buffer->tail == NULL) buffer->head = NULL;//this is done in case buffer's capacity is 1 and it is full so when we drop the tail buffer becomes empty
			else buffer->tail->next = NULL; //always this else block will run if buffer's capacity is not 1
			free(temp); //freeing the old tail
			buffer->size--;//decrements the size of the buffer after operation
		}
		node = createNode(address); //creating a node with given address
		node->next = buffer->head;
		if(buffer->head == NULL) buffer->tail = node; //if buffer was empty before this node then tail should be this node as well
		else buffer->head->prev = node;
		buffer->head = node; //making the new node the head of the buffer
		buffer->size++; //increments the size of the buffer after operation
	}
	else{//if node is found then we should increment the counter of that node
		node->counter++; 
		if(node->counter > buffer->T && node != buffer->head){//if counter of the node becomes bigger than threshold value and it is not already head then we should make him head
			node->prev->next = node->next;
			if(node->next == NULL) buffer->tail = node->prev; //if this node is the tail of the buffer then we should update the tail of the buffer as well
			else node->next->prev = node->prev;
			node->next = buffer->head;
			node->prev = NULL;
			buffer->head->prev = node;
			buffer->head = node;
		}
	}
}

/*
@brief creates a buffer with a given capacity and threshold value

@param capacity: capacity of the buffer
@param T: threshold value for the each node in the buffer

@return pointer to the created buffer
*/

BUFFER* createBuffer(int capacity, int T){
	BUFFER* buffer = (BUFFER*) malloc(sizeof(BUFFER));
	buffer->capacity = capacity;
	buffer->T = T;
	buffer->size = 0;
	buffer->head = buffer->tail = NULL;
	return buffer;
}

/*
@brief deletes the buffer

@param buffer: pointer to the buffer

@return
*/

void deleteBuffer(BUFFER* buffer){
	if(buffer == NULL) return;
	
	NODE* head = buffer->head, *temp;
	
	while(head != NULL){
		temp = head;
		head = head->next;
		free(temp);
	}
	
	free(buffer);
}
