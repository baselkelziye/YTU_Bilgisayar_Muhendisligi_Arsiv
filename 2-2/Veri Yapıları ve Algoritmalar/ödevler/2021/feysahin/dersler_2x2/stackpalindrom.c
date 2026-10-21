#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 8
char stack[MAXSIZE];
int count = -1;

int isFull();
int isEmpty();

void push(char);
char pop();

void checkPalindrom(char *);

void printStack();

int main(){
	
	char word[8]
	printf("Word: ");
	scanf("%s", word);
	checkPalindrom(word); //wordü stacke at, sýrayla pop ederek ayný diye bak (while)
	
	return 0;
}

void checkPalindrom(char *word){
	int i, len = strlen(word);
	for(i=0; i<len; i++){
		push(word[i]);
		printf("\n");
		printStack();
	}
	i = 0;
	while(count>=0 && pop()==word[i]){
		i++;
	}
	if(count<0) printf("\n %s is a palindrom word.", word);
	else printf("\n %s is not a palindrom word.", word);
}

void push(char c){
	if(!isFull()){
		count++;
		stack[count] = c;
	}
	else printf("Stack is full! Nowhere to add.\n");
}

int isFull(){
	if(count==MAXSIZE){
		return 1;
	}
	else return 0;
}

char pop(){
	char popc;
	if(!isEmpty()){
		popc = stack[count];
		count--;
	}
	else printf("Stack is empty! Nothing to take.\n");
	return popc;
}

int isEmpty(){
	if(count==-1){
		return 1;
	}
	else return 0;
}

void printStack(){
	int i;
	printf("\n");
	for(i=0; i<=count; i++){
		printf("%c ", *(stack+i));
	}
}
