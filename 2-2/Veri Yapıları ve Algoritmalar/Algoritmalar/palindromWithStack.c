#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct stack{	
	char item[MAX];
	int top;
}STACK;


void initStack(STACK *s){
	s->top=0;
}
	
int isEmpty(STACK *s){
	if(s->top==0)
	return 1;
	else
	return 0;
}

int isFull(STACK *s){
	
	if(s->top==MAX)
	return 1;
	else return 0;
						
}

int push(char x, STACK *s){

	if(isFull(s))
	return 0;
	else{
	s->item[s->top++]=x;
	return 1;	
	}			
}

int pop(char *x, STACK *s){
	if(isEmpty(s))
	return 0;
	else{
	*x=s->item[--s->top];
	return 1;			
	}						
}

int peek(char *x,STACK *s){
	int tmp;
	
	if(isEmpty(s))
	return 0;
	else{
	tmp=s->top-1;
	*x=s->item[tmp];
	return 1;
	}				
}

void pushTheStack(char *letter,STACK *s){
	int i=0;
	while(letter[i]!='\0'){
		push(letter[i], s);
		i++;
	}
}

int checkIfPalindrom(char *letter,STACK *s,int i){
	char x;
	pop(&x,s);
	if(letter[i]!=x && letter[i]!='\0')
	return 0;
	else if(letter[i]==x && letter[i]!='\0')
	return checkIfPalindrom(letter,s,++i);
	else
	return 1;
}

int main(){
	
	STACK *s;
	s=(STACK*)malloc(sizeof(STACK));
	initStack(s);
	char letter[100];
	
	printf("Enter A Letter: "); scanf("%[^\n]",letter);
	pushTheStack(letter,s);
	if(checkIfPalindrom(letter,s,0)){
		printf("%s Is A Palindrom Letter",letter);
	}else{
		printf("%s Is Not A Palindrom Letter",letter);
	}
	
	return 0;
}
