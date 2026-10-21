#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char *address;
	int requestCount;
	struct node *prev;
	struct node *next;
};

typedef struct node NODE;

NODE* addNode(NODE* head, char* address);
NODE* updateHead(NODE* head, NODE* currentNode);
NODE* updateBuffer(NODE* head, char* address, int bufferCapacity, int requestTreshold);
NODE* clearBuffer(NODE* head);
void printList(NODE* head);

int main() {
	
	NODE *head = NULL; // pointer that points to head of linked list node
	char address[100]; // website address that is got from user
	char fileName[20]; // file name
	FILE *file; // file that contains web adress requests
	int choice; // user choice
	int requestTreshold; // request treshold
	int bufferCapacity; // maximum size of linked list
	
	printf("Request treshold: ");
	scanf("%d", &requestTreshold);
	
	printf("Buffer capacity: ");
	scanf("%d", &bufferCapacity);
	
	printf("\n");
	
	do {	
		printf("Enter address: 1\n");
		printf("Read from file: 2\n");
		printf("choice: ");
		scanf("%d", &choice);
			
		if (choice == 1) { // if user choose to enter an address
			do {
				printf("\nAdress: ");
				scanf(" %[^\n]s", address);
				head = updateBuffer(head, address, bufferCapacity, requestTreshold); // updates buffer depends on the address which is read from file 
				printList(head); // prints the linked list
				printf("\nNew request: 1\n");
				printf("Clear cache buffer: 2\n");
				printf("Return menu: 3\n");
				printf("choice: ");
				scanf("%d", &choice);
				if (choice == 2) { // if user choose to clear buffer
					head = clearBuffer(head); // cleans the buffer and makes head NULL
					printf("\nNew request: 1\n");
					printf("Return menu: 2\n");
					printf("choice: ");
					scanf("%d", &choice);
				}
			} while(choice == 1); // if user doesn't want to return menu, it continues to get input from user
		}
		else if (choice == 2) { // if user choose to read addresses from file
			do {
		    	printf("File name: ");
	    		scanf("%s", fileName);
	    		file = fopen(fileName, "r");
				if (!file) { // if file cannot be opened
					printf("File could not be opened!, ");
				}
			} while (!file); // it will ask for file name until user input is a valid file name
			
			printf("\n");
			
	    	while (fscanf(file, " %[^\n]s", address) == 1) { // loop until end of the file
	        	head = updateBuffer(head, address, bufferCapacity, requestTreshold); // updates buffer depends on the address which is read from file 
				printList(head); // prints the linked list
	    	}
	    	printf("\nClear cache buffer: 1\n");
	    	printf("Return menu: 2\n");
	    	printf("choice: ");
			scanf("%d", &choice);
	    	if (choice == 1) { // if the user choose to clear buffer
				head = clearBuffer(head);  // cleans the buffer and makes head NULL
			}
		}
		
		printf("\nExit: 1\n");
		printf("Continue: 2\n");
		printf("choice: ");
		scanf("%d", &choice);
			
		printf("\n");
	} while(choice == 2); //  if the user wants to continue using the program, program doesn't close
	
	return 0;
}

/*
@brief a function that creates a new linked list node, initializes it and makes this node the first node of linked list.

@param head pointer that points the first node of linked list.
@param address address value of the new linked list node that we create.

@return return pointer of first node of linked list.
*/
NODE* addNode(NODE* head, char* address) {
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->address = (char*)malloc((strlen(address) + 1) * sizeof(char));
	strcpy(newNode->address, address);
	newNode->requestCount = 1;
	
	if (head != NULL) { // if list is not empty
		head->prev = newNode;	
	}
	newNode->next = head;
	head = newNode;
	head->prev = NULL;
	return head;
}

/*
@brief a function that takes a pointer of a linked list node and makes this node the first node of linked list.

@param head pointer that points the first node of linked list.
@param currentNode pointer that points a node of linked list that is going to be new head of linked list.

@return return pointer of first node of linked list.
*/
NODE* updateHead(NODE* head, NODE* currentNode) {
	if (currentNode->prev == NULL) { // if there is only one node in the list it returns the head
		return head;
	}
	if (currentNode->next != NULL) { // if current node is not at the end of the list
		currentNode->next->prev = currentNode->prev; // the new prev of next of current node
	}
	currentNode->prev->next = currentNode->next;
	currentNode->prev = NULL;
	currentNode->next = head;
	head->prev = currentNode;
	head = currentNode;
	return head;
}

/*
@brief a function that takes an address. If the linked list includes this address, increases request number of this address 
and If request number of this address bigger than requestTreshold, makes this linked list node the first element of linked list.
If the linked list doesn't include this address. Creates a new node and makes it first node of linked list. 
If linked list exceed the bufferCapacity, removes the last node of linked list.

@param head pointer that points the first node of linked list.
@param address address value of the new linked list node that we create.
@param bufferCapacity the maximum size of linked list.
@param requestTreshold the treshold of number of requests.

@return return pointer of first node of linked list.
*/
NODE* updateBuffer(NODE* head, char* address, int bufferCapacity, int requestTreshold) {
	NODE *current;
	NODE *prev;
	current = head;
	int nodeCount;
	
	nodeCount = 0;
	while (current != NULL && strcmp(address, current->address) != 0) { // it will stop if it reaches end of the list or if address is matches with another address
		prev = current;	
		current = current->next;
		nodeCount++;
	}
	if (current == NULL) { // if it reached the end of the list
		if (nodeCount == bufferCapacity) { // if the list capacity is full, it removes the last element of list
			prev->prev->next = NULL;
			free(prev);
		}
		head = addNode(head, address); // adds new node to front of the list
	}
	else {
		(current->requestCount)++;
		if (current->requestCount > requestTreshold) { // if request number of current node bigger than request treshold, the new head of list will be current node
			head = updateHead(head, current);
		}
	}
	return head;
}

/*
@brief a function frees all of the linked list nodes.

@param head pointer that points the first node of linked list.

@return return NULL.
*/
NODE* clearBuffer(NODE* head) {
	NODE* current = head;
	NODE* next;
	while (current != NULL) { // until iterator reaches the end of the list
		next = current->next;
		free(current->address); // frees the address field of NODE
		free(current); // frees the node
		current = next;
	}
	return NULL;
}

/*
@brief a function that prints values of all linked list elements.

@param head pointer that points the first node of linked list.

@return
*/
void printList(NODE* head) {
	if (head != NULL) { // it will print first element without "<->"
		printf("%s,%d", head->address, head->requestCount);
		head = head->next;
	}
	while (head != NULL) { // until iterator reaches the end of the list, it will print values of nodes
		printf(" <-> %s,%d", head->address, head->requestCount);
		head = head->next; //
	}
	printf("\n");
}
