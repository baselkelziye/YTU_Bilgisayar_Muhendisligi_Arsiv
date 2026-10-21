#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct word {
	char *data;
	int isUsed;
	struct word *next;
} WORD;

typedef struct stack {
	WORD *head;
	struct stack *next;
} STACK;

typedef struct queue {
	STACK *head;
	STACK *tail;
} QUEUE;

STACK* readDictionaryFromFile(STACK *stack, char *sourceWord);
STACK* pushStack(STACK *stack, char *data, int isUsed);
int isOneLetterDifferent(char *word1, char *word2);
QUEUE* enqueue(QUEUE *queue, STACK *stack);
STACK* dequeue(QUEUE **queue);
STACK* copyStack(STACK *stack);
STACK* findMinimumWordPath(QUEUE *queue, STACK *dictionary, char *sourceWord, char *destinationWord);
void displayStack(STACK *stack);
void displayQueue(QUEUE *queue);

int main() {
	STACK *dictionary = (STACK*)malloc(sizeof(STACK)); // all words which have same number of letters with source word
	dictionary->head = NULL;
	dictionary->next = NULL;
	QUEUE *queue = (QUEUE*)malloc(sizeof(QUEUE)); // queue that has stacks
	queue->head = NULL;
	queue->tail = NULL;
	char *sourceWord; // source word
	char *destinationWord; //destination word
	char temp[30]; 
	int wordLength; // length of source word
	STACK *minimumPath; // word stack which has the minimum word path
	
	printf("source word: ");
	scanf("%s", temp);
	sourceWord = (char*)malloc((strlen(temp) + 1) * sizeof(char));
	strcpy(sourceWord, temp);
	
	wordLength = strlen(sourceWord);
	
	printf("destination word: ");
	scanf("%s", temp);
	destinationWord = (char*)malloc((strlen(temp) + 1) * sizeof(char));
	strcpy(destinationWord, temp);
	
	dictionary = readDictionaryFromFile(dictionary, sourceWord);
	
	printf("\n");
	
	minimumPath = findMinimumWordPath(queue, dictionary, sourceWord, destinationWord);
	
	if (minimumPath != NULL) { // if minimumPath is not NULL, it has minimum path
		printf("\nMINIMUM PATH\n");
		displayStack(minimumPath);
	}
	else { // if minimumPath is NULL, it doesnt have minimum path
		printf("There is no path from \"%s\" to \"%s\".", sourceWord, destinationWord);
	}
	
	return 0;
}

/*
@brief reads a txt file which has words and saves the words which has same number of letters with the source word to stack.

@param stack the stack which has words.
@param sourceWord source word.

@return return the stack that filled with words.
*/
STACK* readDictionaryFromFile(STACK *stack, char *sourceWord) {
	char fileName[30] = "dictionary.txt"; 
	FILE *file; 
	file = fopen(fileName, "r");
	int wordLength = strlen(sourceWord);
	char temp[40], *word;
	int isSourceWordFound = 0;
	
	while (!feof(file)) { // while it is not end of the file
        fscanf(file, "%s", temp);
        if (strlen(temp) == wordLength) { // if length of source word same as the current word we push the current word to dictionary.
        	word = (char*)malloc((wordLength + 1) * sizeof(char));
        	strcpy(word, temp);
        	if (strcmp(sourceWord, temp) == 0) { // if current word in file is source word, we set isUsed field of current word to 1.
        		stack = pushStack(stack, word, 1);
        		isSourceWordFound = 1;
			}
			else { // if current word in file is not sourceWord, we set isUsed field of current word to 0.
				stack = pushStack(stack, word, 0);
			}
		}
        
    }
    if (isSourceWordFound == 0) { // if source word is not a valid word
    	printf("source word is not a valid word!");
		exit(0);
	}
    
    return stack;
}

/*
@brief a function that allocates a WORD and initializes it with function parameters.

@param stack a pointer of a stack that has words.
@param data a word that to be data field of new WORD struct.
@param isUsed the integer that determines the word is used or not, if 1 used, if 0 not used.

@return return the extended stack.
*/
STACK* pushStack(STACK *stack, char *data, int isUsed) {
	WORD *newWord = (WORD*)malloc(sizeof(WORD));
	newWord->data = (char*)malloc((strlen(data) + 1) * sizeof(char));
	strcpy(newWord->data, data);
	newWord->isUsed = isUsed;
	newWord->next = stack->head;
	stack->head = newWord;
	return stack;
}

/*
@brief a function that determines the number of different letters between two words.

@param word1 first word to compare.
@param word2 second word to compare.

@return if differenece is 1, returns 1, else returns 0.
*/
int isOneLetterDifferent(char *word1, char *word2) {
	int i = 0, j = 0;
	
	while (word1[i] != '\0') { // while it is not last character of string
		if (word1[i] != word2[i]) { // if characters of words differentat at index i
			j++;
		}
		i++;
	}
	
	if (j == 1) return 1; // if the number of different letters 1, return 1
	return 0;
}

/*
@brief a function that adds a stack to queue.

@param queue a pointer of a queue that has stacks.
@param stack a pointer of a stack that has words.

@return return the extended queue.
*/
QUEUE* enqueue(QUEUE *queue, STACK *stack) {
	if (queue->head == NULL) { // if queue is empty, it makes head of queue stack
		queue->head = stack;
	}
	else { // if queue is not empty, it makes next element of tail of queue stack
		queue->tail->next = stack;
	}
	queue->tail = stack;
	queue->tail->next = NULL;
	return queue;
}

/*
@brief a function that adds a stack to queue.

@param queue an address of a pointer of queue that has stacks.

@return return the extended queue.
*/
STACK* dequeue(QUEUE **queue) {
	if ((*queue)->head == NULL) { // if queue is empty, returns NULL
		return NULL;
	}
	if ((*queue)->head == (*queue)->tail) { // if there is only one stack in queue, it makes tail NULL
		(*queue)->tail = NULL;
	}
	STACK *stack = (*queue)->head;
    (*queue)->head = (*queue)->head->next;
    return stack;
}

/*
@brief a function that takes a stack and copies this stack to another new stack and it uses an extra third stack to save the order of new stack.

@param stack a pointer of a stack that has words to copy.

@return return the new stack that is copied from another stack.
*/
STACK* copyStack(STACK *stack) {
	STACK *newStack = (STACK*)malloc(sizeof(STACK));
	STACK *tempStack = (STACK*)malloc(sizeof(STACK));
	newStack->head = NULL;
	tempStack->head = NULL;
	WORD *iter;
	iter = stack->head;
	while (iter != NULL) { // while it is not end of the stack 
		tempStack = pushStack(tempStack, iter->data, iter->isUsed);
		iter = iter->next;
	}
	iter = tempStack->head;
	while (iter != NULL) { // while it is not end of the stack
		newStack = pushStack(newStack, iter->data, iter->isUsed);
		iter = iter->next;
	}
	return newStack;
}

/*
@brief a function that finds the minimum word path from source word to destination word.

@param queue a pointer of queue that has the stacks.
@param dictionary a pointer of stack which is dictionary and has words which have same number of letter with source word.
@param sourceWord source word.
@param destinationWord destination word.

@return if there is a path returns the stack that has the minimum path, else returns NULL.
*/
STACK* findMinimumWordPath(QUEUE *queue, STACK *dictionary, char *sourceWord, char *destinationWord) {
	WORD *iter;
	STACK *tempStack;
	STACK *newStack;
	char *currentWord = (char*)malloc((strlen(sourceWord) + 1) * sizeof(char));
	
	if (strcmp(sourceWord, destinationWord) == 0) { // if source word equals to destination word
		tempStack = (STACK*)malloc(sizeof(STACK));
		tempStack->head = NULL;
		tempStack->next = NULL;
		tempStack = pushStack(tempStack, sourceWord, -1);
		return tempStack;
	}

	iter = dictionary->head;
	while (iter != NULL) { // while it is not end of the dictionary stack
		if (isOneLetterDifferent(iter->data, sourceWord)) { // if number of different letters is 1 between the word which iter points and sourceWord
			iter->isUsed = 1;
			tempStack = (STACK*)malloc(sizeof(STACK));
			tempStack->head = NULL;
			tempStack->next = NULL;
			tempStack = pushStack(tempStack, sourceWord, -1);
			tempStack = pushStack(tempStack, iter->data, -1);
			queue = enqueue(queue, tempStack);
		}
		iter = iter->next;
	}
	//displayQueue(queue);
	
	while (queue->head != NULL) { // while queue is not empty
		tempStack = dequeue(&queue);	
		strcpy(currentWord, tempStack->head->data);
		if  (strcmp(currentWord, destinationWord) == 0) { // if current word equals destination word
			displayQueue(queue);
			return tempStack;
		}
		iter = dictionary->head;
		while (iter != NULL) { // while it is not end of the dictionary stack
			if (iter->isUsed == 0 && isOneLetterDifferent(iter->data, currentWord)) { // if the word which iter points is not used and if the difference of letters is 1.
				iter->isUsed = 1;
				newStack = copyStack(tempStack);
				newStack = pushStack(newStack, iter->data, -1);
				queue = enqueue(queue, newStack);
			}
			iter = iter->next;
		}
		//it takes too long time to display queue in every iteration, if you want to display remove comment form displayQueue() function
		//displayQueue(queue);
		free(tempStack);
	}  
	
	return NULL;
}

/*
@brief a function that prints the stack.

@param stack pointer of a stack that has words.

@return 
*/
void displayStack(STACK *stack) {
	WORD *wordIterator = stack->head;
	while (wordIterator != NULL) { // while it is not end of the stack
		printf(" -> %s", wordIterator->data);
		wordIterator = wordIterator->next;
	}
}

/*
@brief a function that prints the queue.

@param queue pointer of a queue that has words.

@return 
*/
void displayQueue(QUEUE *queue) {
	STACK *stackIterator = queue->head;
	while (stackIterator != NULL) { // while it is not end of the queue
		displayStack(stackIterator);
		printf("\n-----------------------------------------------------\n");
		stackIterator = stackIterator->next;
	}
	printf("\n********************************************\n");
	printf("********************************************\n\n");
}










