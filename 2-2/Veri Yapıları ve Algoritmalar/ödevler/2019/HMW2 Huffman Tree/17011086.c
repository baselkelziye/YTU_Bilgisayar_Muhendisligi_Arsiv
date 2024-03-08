#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//
struct node{
	char letter;
	int freq;
	struct node *left, *right, *next;
};

typedef struct node NODE;
void insertLinkedList(NODE**,char); // creating and inserting linked list
void printLinkedList(NODE**); // printing linked list
void insertionSortToLinkedList(NODE**); // sorting linked list
void readFromFile(NODE**,char*); // read from file
void readFromStdin(NODE**); // read from standart input
void insertButSorted(NODE**,NODE*); // inserting nodes to linked list but sorted
void doThatTree(NODE**); // making linked list to huffman tree
void printSpecificLevel(NODE*,int); // printing specific level
void printThatTree(NODE*); // printing whole tree
int getLevelCount(NODE*); // counting levels

int main(int argc, char** argv) {

	NODE* head = NULL;
	int input_control;
	printf("If you read the text from file PRESS 1, if you read the text from stdin PRESS 0:  ");
	scanf("%d",&input_control);
	if(input_control == 1) {
		char* filename;
		printf("What is your file name?: ");
		scanf("%s",filename);
		readFromFile(&head,filename);
	}
	else if(input_control == 0) {
		readFromStdin(&head);
	}
	insertionSortToLinkedList(&head);
	doThatTree(&head);
	printThatTree(head);
	return 0;
}

void insertLinkedList(NODE** head, char letter) {

	NODE* newnode = (NODE*)malloc(sizeof(NODE));
	if(*head == NULL) { // if only the head exists but NULL, we create.
		newnode->letter = letter;
		newnode->freq = 1;
		newnode->next = NULL;
		(*head) = newnode;
	}
	else{
		NODE* current = *head;
		while(current->next != NULL && current->letter != letter) {
			current = current->next;
		}
		if(current->next == NULL){
			if(current->letter == letter) {
/* if we stop at the last element of the linked list
	 either the next is can be NULL or the last node's letter is
	 equal to new input.
	 if the last one is true:
*/
				current->freq++;
			}
			else if(current->letter != letter){
				// if the first one is true:
				newnode->next = NULL;
				newnode->letter = letter;
				newnode->freq = 1;
				current->next = newnode;
			}
		}
		else{
			current->freq++;
		}
	}
}

void printLinkedList(NODE** head) {

	NODE* current = *head;
	while(current->next != NULL) {
		printf("(%c,%d) - ",current->letter,current->freq);
		current = current->next;
	}
	printf("(%c,%d)",current->letter,current->freq);
	printf("\n");

}

void insertionSortToLinkedList(NODE** head) {

	char temp_of_the_temps; // this fellow is for storaging the letter information
													// of the node.

	if((*head) == NULL) {
		fprintf(stderr,"First initialize the linked list!\n");
	}
	else if((*head)->next == NULL) {
		fprintf(stderr,"Your linked list has only one member!\n");
	}
	else{
		NODE* start1 = (*head)->next;

		while(start1 != NULL ) {
			int freq = start1->freq;
			temp_of_the_temps = start1->letter;
			int ctrl = 0;
			NODE* start2 = *head;
			while(start2 != start1) {
				if((start2->freq > start1->freq) && ctrl==0) {
					freq = start2->freq;
					temp_of_the_temps = start2->letter;
					start2->freq = start1->freq;
					start2->letter = start1->letter;
					ctrl = 1;
					start2 = start2->next;
				}
				else{
					if(ctrl == 1) {
						int temp1 = freq;
						char temp2 = temp_of_the_temps;
						freq = start2->freq;
						temp_of_the_temps = start2->letter;
						start2->freq = temp1;
						start2->letter = temp2;
					}
					start2 = start2->next;
				}
			}
			start2->freq = freq;
			start2->letter = temp_of_the_temps;
			start1 = start1->next;
		}
	}
}

void readFromFile(NODE** head,char* filename) {

	FILE* fp = fopen(filename,"r");
	if(fp == NULL) {
		fprintf(stderr,"File cannot be opened!\n");
		exit(0);
	}
	else{
		char buffer;
		while((buffer = fgetc(fp)) != EOF) {
			if(buffer != '\n'){ // it reads a new line at the end of the file. This is
													// for get rid of it.
			insertLinkedList(head,buffer);
			}
		}
	}
}

void readFromStdin(NODE** head) {

	char buffer;
	while(scanf(" %c",&buffer) != EOF) { // EOF signal is Ctrl+d in POSIX.
		if(buffer != '\r'){
			insertLinkedList(head,buffer);
		}
	}
}

void doThatTree(NODE** head) {

	NODE* current1 = *head;
	NODE* current2 = *head;
	while(current1->next != NULL){
		NODE* newnode = (NODE*)malloc(sizeof(NODE));
		newnode->left = NULL;
		newnode->right = NULL;
		newnode->next = NULL;
		current2 = current1;
		newnode->freq = current2->freq + current2->next->freq;
		insertButSorted(head,newnode);
		newnode->right = current2->next;
		newnode->left = current2;
		newnode->letter = '*';// it has no letter and you want to see has a spaces.
													// to show the spaces, I assign this.
		current1 = current1->next->next;
		*head = current1; //(note: try to delete not assign)
	}
}

void insertButSorted(NODE** head, NODE* newnode) {

		NODE* current = *head;
		if(newnode->freq <= (*head)->freq) {
			newnode->next = *head;
			*head = newnode;
		}
		else{
			while(current->next != NULL && current->next->freq <= newnode->freq) {
				current= current->next;
			}
			newnode->next = current->next;
			current->next = newnode;
		}
}

int getLevelCount(NODE* head){
    if (head == NULL){
        return 0;
    }
    int leftMaxLevel = 1 + getLevelCount(head->left);
    int rightMaxLevel = 1 + getLevelCount(head->right);
    if (leftMaxLevel > rightMaxLevel){
        return leftMaxLevel;
    }
    else{
        return rightMaxLevel;
    }
}

void printSpecificLevel(NODE *head, int slevel){
    if (head != NULL && slevel == 0){
        printf("%d%c ", head->freq,head->letter);
  	}
    else if (head != NULL){
        printSpecificLevel(head->left, slevel - 1);
        printSpecificLevel(head->right, slevel - 1);
    }
}

void printThatTree(NODE *head){
    int i;
    int glc = getLevelCount(head);
    for (i = 0; i<glc; i++){
        printSpecificLevel(head, i);
				printf("\n");
    }
}
