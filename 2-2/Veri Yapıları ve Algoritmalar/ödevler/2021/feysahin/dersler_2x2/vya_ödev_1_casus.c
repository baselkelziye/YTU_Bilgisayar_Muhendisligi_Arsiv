#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 40
char stack[MAXSIZE];
char stack2[MAXSIZE];

char kod[40];
char kod1[40];
char kod2[40];

int count = -1;
int count2 = -1;

int isFull(int);
int isEmpty(int);

void push(char, int);
char pop(int);

void createCode(char *, int);

void printStack(int);

int main(){
	
	
	char mesaj1[40] = "cabc2ssss3uvxyz4sab2kabak4odun1";
	char mesaj2[40] = "ama3cam1ses2usta2kopuk3yok3damla4ufuk3";                   //stacke at, pop() edip char 47-58 aralýðýnda mý diye bak, öyleyse 
	
	createCode(mesaj2, 2);
	printf("\n");
	createCode(mesaj1, 1);
	
	if(strcmp(kod1,kod2) == 0) printf("\n\nCASUSLAR ILETISIME GECEBILIR!\n");
	else printf("\nCasuslar iletisime gecemez!\n");
	
	return 0;
}

void createCode(char *word, int codeNum){
	
	int i, j=0, len = strlen(word), x;
	char c;
	for(i=0; i<len; i++){
		push(word[i], codeNum);
	}
	//kod1 için
	if(codeNum == 1){
		while(count>=0){
			x = (int) pop(codeNum);
			if(x>47 && x<58){
				x -= 48;
				
				//char'larý silme
				i = 0;
				while(i<x && count>=0){
					pop(codeNum);
					i++;
				}
				if(count<-1) printf("\n\nERROR");
			}
			else{
				kod[j] = (char) x;
				j++;
			}
		}
	}
	//kod2 için
	else if(codeNum == 2){
		while(count2>=0){
			x = (int) pop(codeNum);
			if(x>47 && x<58){
				x -= 48;
				
				//char'larý silme
				i = 0;
				while(i<x && count2>=0){
					pop(codeNum);
					i++;
				}
				if(count2<-1) printf("\n\nERROR");
			}
			else{
				kod[j] = (char) x;
				j++;
			}
		}
	}
	//kodlarý ters çevirme	
	len = strlen(kod);
	for(i=0; i<len/2; i++){
		c = kod[i];
		kod[i] = kod[len-1-i];
		kod[len-1-i] = c;
	}
	
	if(codeNum == 1){
		strcpy(kod1,kod);
		printf("\nkod1: %s", kod1);
	} 
	else if(codeNum == 2){
		strcpy(kod2,kod);
		printf("\nkod2: %s", kod2);
	}
}

void push(char c, int codeNum){
	if(codeNum == 1){
		if(!isFull(codeNum)){
			count++;
			stack[count] = c;
		}
		else printf("Stack is full! Nowhere to add.\n");
	}
	else{
		if(!isFull(codeNum)){
			count2++;
			stack2[count2] = c;
		}
		else printf("Stack is full! Nowhere to add.\n");
	}
}

int isFull(int codeNum){
	if(codeNum == 1){
		if(count==MAXSIZE){
			return 1;
		}
		else return 0;
	}
	else{
		if(count2==MAXSIZE){
			return 1;
		}
		else return 0;
	}
}

char pop(int codeNum){
	char popc;
	if(codeNum == 1){
		if(!isEmpty(codeNum)){
			popc = stack[count];
			count--;
		}
		else printf("Stack is empty! Nothing to take.\n");
	}
	else{
		if(!isEmpty(codeNum)){
			popc = stack2[count2];
			count2--;
		}
		else printf("Stack is empty! Nothing to take.\n");
	}
	return popc;
}

int isEmpty(int codeNum){
	if(codeNum == 1){
		if(count==-1){
			return 1;
		}
		else return 0;
	}
	else{
		if(count2==-1){
			return 1;
		}
		else return 0;
	}
}

void printStack(int codeNum){
	int i;
	printf("\n");
	if(codeNum == 1){
		for(i=0; i<=count; i++){
			printf("%c ", *(stack+i));
		}
	}
	else{
		for(i=0; i<=count2; i++){
			printf("%c ", *(stack2+i));
		}
	}
}
