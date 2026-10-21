#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHAR 50

typedef struct stack{
	char word[MAXCHAR];
	unsigned int isVisited : 1; //to know whether an instance of this struct is proccessed or not
	struct stack* next;
}STACK;

typedef struct node{
	STACK* stack;
	struct node* next;
}NODE;

typedef struct queue{
    NODE* head;
    NODE* tail;
}QUEUE;

void freeStack(STACK* stack);
void copyStack(QUEUE* queue, STACK* stack, char* word);
void push(STACK **head, char* word);
int pop(STACK **head);
void enqueue(QUEUE* queue, STACK* stack);
STACK* dequeue(QUEUE* queue);
int isEmpty(QUEUE* queue);
int isOneDifference(char* word1, char* word2);
void printLadder(STACK* ladder);
void printQueue(QUEUE* queue);
void findWordLadder(STACK* dict, char* src, char* dest);

int main(){
	char *src, *dest, *temp, filename[20];
	STACK* dict = NULL; //dictionary is stored as a stack

	src = (char*) malloc(MAXCHAR * sizeof(char));
	dest = (char*) malloc(MAXCHAR * sizeof(char));
	temp = (char*) malloc(MAXCHAR * sizeof(char));
	
	printf("\nsource word: ");
	scanf("%s", src);
	
	printf("\ndestination word: ");
	scanf("%s", dest);
	
	if(strlen(src) != strlen(dest)){ //if src and dest are not the same length, program is ended
		printf("\nsource and destination words are not the same length...");
		return 1;
	}
	
	printf("\nfilename: ");
	scanf("%s", filename);
	
	FILE* file = fopen(filename, "r");
	
	if(file == NULL){
		printf("\nfile could not be opened...");
		return 1;
	}
	
	while(fscanf(file, "%s", temp) == 1){
		if(strlen(src) == strlen(temp)){ //only the words with same length as src are added to dict 
			push(&dict, temp);
		}
	}
	
	fclose(file);
	
	findWordLadder(dict, src, dest);
	
	free(src);
	free(dest);
	free(temp);
	freeStack(dict);
	
	return 0;
}

/*
@brief it actually applies a BFS implementation to find the word ladder

@param dict: pointer to the stack that stores the words read from input file.
@param src: pointer to the source word.
@param dest: pointer to the destination word.

@return
*/

void findWordLadder(STACK* dict, char* src, char* dest){
	QUEUE* queue = (QUEUE*) calloc(1, sizeof(QUEUE));
	int control = 0; //to know whether the ladder is found or not 
	STACK* currentStack = NULL, *temp = dict;
	
	while(temp != NULL && strcmp(temp->word, src)){ //this looks for src word in dict
		temp = temp->next;
	}
	
	if(temp == NULL){ //if src word is not in the dict then function is ended
		printf("\nsource word %s is not in the dictionary...", src);
		return;
	}
	
	temp->isVisited = 1; //if src is found on the dict then isVisited field of its node is set to 1
	push(&currentStack, src); //src is pushed to currentStack which is currently empty
	enqueue(queue, currentStack); //currentStack is pushed to the queue which is also currently empty
	
	do{
		currentStack = dequeue(queue); //queue is dequeued and currentStack gets the head of the dequeued stack
		
		if(strcmp(currentStack->word, dest)){//if the word of the head of the currentStack is not same with the destination word
			temp = dict; //temp is set to the head of the dict to iterate through the whole dictionary 
			while(temp != NULL){
				if(temp->isVisited != 1 && isOneDifference(currentStack->word, temp->word)){//if the current node is not proccessed before and the difference is 1
					copyStack(queue, currentStack, temp->word); //copyStack is called to copy currentStack and push the current word to the copied stack 
					temp->isVisited = 1; //isVisited field of current node is set to 1
				}
				temp = temp->next;
			}
			freeStack(currentStack); //freeing the currentStack after traversing the dict
		}
		else control = 1; //if they are same then control is set to 1
		
		//printQueue(queue); //to print the queue in every iteration (her adýmda yazdýrmak süreyi uzattýðý için yorum satýrýna aldým)
	
	} while(!isEmpty(queue) && !control); //it iterates until the queue becomes empty or the ladder is found
	
	if(control == 1) printLadder(currentStack);
	else printf("\nno ladder is found for %s and %s...", src, dest);
}

/*
@brief it visits every node in the queue and for each node it calls printLadder function to print the stack that node stores.

@param queue: pointer to the queue where the stacks are stored.

@return
*/

void printQueue(QUEUE* queue){
	NODE* temp = queue->head;
	printf("\n\n----------------\n");
	while(temp != NULL){
		printLadder(temp->stack);
		temp = temp->next;
	}
	printf("\n----------------\n\n");
}


/*
@brief at first it reverse the stack to print the words in the order they are added to the stack and after that it visits every node of the reverseStack and prints the word it stores.

@param stack: pointer to the head of the stack.

@return
*/

void printLadder(STACK* stack){
	STACK *temp = stack, *reverseStack = NULL;
	
	while(temp != NULL){
		push(&reverseStack, temp->word);
		temp = temp->next;
	}
	
	temp = reverseStack;
	while(temp->next != NULL){
		printf("%s -> ",temp->word);
		temp = temp->next;
	}
	
	printf("%s\n\n", temp->word);
	
	freeStack(reverseStack); //freeing the reverseStack
}

/*
@brief it looks for whether the char difference is 1 between word1 and word2 or not.

@param word1: pointer to char array.
@param word2: pointer to char array.

@return 1 if difference is 1 otherwise 0.
*/

int isOneDifference(char* word1, char* word2){
	int count = 0, i = 0;
	
	if(strlen(word1) != strlen(word2)) return 0; //if the lengths are not same then return 0
	
	while(count < 2 && word1[i] != '\0'){//it iterates while the number of different chars is less than 2 and it is not the end of the words 
		if(word1[i] != word2[i]) count++;
		i++;
	}
	
	return (count == 1); //returns 1 if count is 1 otherwise 0
}

/*
@brief it frees the stack by calling the pop function until it returns 0.

@param stack: pointer to the head of the stack.

@return
*/

void freeStack(STACK* stack){
	while(pop(&stack));
}

/*
@brief it reverse the stack we will copy because we should preserve the order of the nodes and after that it pushes the nodes of the reverseStack to the newStack and then pushes the word.

@param queue: pointer to the queue.
@param stack: pointer to the head of the stack which we wants a copy of.
@param word: pointer to the char array that we will add it to the new stack.

@return
*/

void copyStack(QUEUE* queue, STACK* stack, char* word){
	STACK* newStack = NULL, *temp = stack, *reverseStack = NULL;
	
	while(temp != NULL){
		push(&reverseStack, temp->word);
		temp = temp->next;
	}
	
	temp = reverseStack;
	while(temp != NULL){
		push(&newStack, temp->word);
		temp = temp->next;
	}
	
	push(&newStack, word); //pushing the word to the newStack
	enqueue(queue, newStack); //enqueue the newStack
	freeStack(reverseStack); //freeing the reverseStack
}

/*
@brief it creates a node and adds it to the head of the stack.

@param head: pointer to the pointer to the head of the stack.
@param word: pointer to the char array that we will add it to the stack.

@return
*/

void push(STACK **head, char* word){
	STACK *temp = (STACK*) malloc(sizeof(STACK));
	strcpy(temp->word, word);
	temp->isVisited = 0;
	temp -> next = *head;
	*head = temp;
}

/*
@brief it frees the head of the stack if it is not empty.

@param head: pointer to the pointer to the head of the stack.

@return 0 if it is empty otherwise 1
*/

int pop(STACK **head){
	if(*head == NULL) return 0;
	else{
		STACK *temp = *head;
		*head = (*head) -> next;
		free(temp);
		return 1;
	}
}

/*
@brief it creates a new node and adds it to the tail of the queue.

@param queue: pointer to the queue.
@param stack: pointer to the head of the stack that we will add it to the queue.

@return
*/

void enqueue(QUEUE* queue, STACK* stack){
	NODE *temp = (NODE*) malloc(sizeof(NODE));
	temp->stack = stack;
	temp->next = NULL;
	if(queue->tail == NULL){
		queue->tail = temp;
		queue->head = temp;
	}
	else{
		queue->tail->next = temp;
		queue->tail = temp;
	}
}

/*
@brief it dequeues the tail node of the queue if queue is not empty.

@param queue: pointer to the queue.

@return pointer to the stack that is dequeued from queue if queue is not empty otherwise NULL.
*/

STACK* dequeue(QUEUE* queue){
	if(!isEmpty(queue)){
        STACK* result = queue->head->stack;
        NODE *temp = queue->head;
        queue->head = queue->head->next;
        if(queue->head == NULL) queue->tail = NULL;
        free(temp);
        return result;
    }
    else return NULL;
}

/*
@brief it looks for whether the queue is empty or not.

@param queue: pointer to the queue.

@return 1 if queue is empty otherwise 0.
*/

int isEmpty(QUEUE* queue){
	return (queue->head == NULL && queue->tail == NULL);
}
