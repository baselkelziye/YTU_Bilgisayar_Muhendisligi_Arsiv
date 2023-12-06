#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#include <math.h>

typedef struct Stack {
	char s[MAX_STACK_SIZE];
	int Top;
}stack;
int IsEmpty(stack myStack)
{	
	if(myStack.Top==-1)
    return  1;
    return 0;
}
int IsFull(stack myStack)
{
    return myStack.Top == MAX_STACK_SIZE ? 1 : 0;
}
char Pop(stack * myStack)
{
	if (!IsEmpty(*myStack)) {
		return myStack->s[(myStack->Top)--];
	}
}
stack Push(stack myStack,char data)
{
	if (!IsFull(myStack)) {
          myStack.s[++myStack.Top]=data;}
		  
	return myStack;
		  }
char Top(stack myStack)
{
	return myStack.s[myStack.Top];
}
int main(){
	stack myStack;
	myStack.Top=-1;
	long int number,i;
	unsigned int bits=256,bitSize=8;
	int Bits=256;
	unsigned int mask;
	printf("Please enter a number\n");
	scanf("%ld",&number);
	while(abs(number)>bits-1 || number<-Bits/2){
		bits=bits*bits;
		Bits=Bits*Bits;
		bitSize=bitSize*2;
	}
	char otherString[bitSize+1];
	for(i=0; i<bitSize; i++)
	{
  		 mask = 1u << (bitSize - 1 - i);
 		 otherString[i] = (number & mask) ? '1' : '0';
	}
	otherString[bitSize]='\0';
	printf("This is %d's 2's complement ----->%s\n",number,otherString);
	for(i=0;i<bitSize;i++){
		if(!IsEmpty(myStack) && Top(myStack)!=otherString[i] ){
			Pop(&myStack);
		}
		else{
			myStack=Push(myStack,otherString[i]);
			
		}
	}
	if(IsEmpty(myStack)){
		printf("1 and 0 numbers are equal.\n");
	}
	else{
		printf("%c is more %d times.\n",Top(myStack),myStack.Top+1);
	}
	
	return 0;
}
