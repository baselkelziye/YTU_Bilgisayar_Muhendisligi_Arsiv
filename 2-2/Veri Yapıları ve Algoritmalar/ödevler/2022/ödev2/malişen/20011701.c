/*  C Program to convert decimal to binary using stack  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int isEmpty(int *top);
int isFull(int *top, int max);
void push(char x, int *top, char stack_arr[],int max);
char pop(int *top, char stack_arr[]);
char peek(int *top, char stack_arr[]);
void DecToBin(int num,int max);
void DecToBinv2(int num,int max);
int findMax(int x);


int main()
{
        int num;
        int max;
        printf("Enter an integer : ");
        scanf("%d",&num);
        if(num>=0){
        	max = findMax(2*num);	
       // printf("\nmax:%d\n",max);
       	//	printf("Binary Equivalent is : ");
        //	DecToBin(num,max);
        	DecToBinv2(num,max);
		}
        else{
        	max = findMax(2*num);	
        	
        	num = pow(2,max) + num;
        //	max = findMax(num);	
        // printf("\n num: %d \n",num);
        //	printf("Binary Equivalent is : ");
        //	DecToBin(num,max); //binary sayiyi ekrana yazdirir.
        	DecToBinv2(num,max);
        	
		}
		
		

        return 0;

}/*End of main()*/

void DecToBinv2(int num,int max)
{
        int top=-1, rem,cnt=0;
        char stack[max], crem;
        while(num!=0)
        {
        	rem = num%2;
        	crem = rem+'0';
        	
        		if(isEmpty(&top)){
        			push(crem, &top, stack, max);
					num/=2;
					cnt++;			
				}else{
						//console.log()
					if(crem != peek(&top,stack) ){
						pop(&top, stack);
						num/=2;
						cnt++;
					}else{
						push(crem, &top, stack, max);
                		num/=2;
                		cnt++;
					}

				}           
        }
        while(cnt < max){
						//console.log()
					if( '0' != peek(&top,stack) && !isEmpty(&top)){
						pop(&top, stack);
						cnt++;
						//num/=2;
					}else{
						push('0', &top, stack, max);
						cnt++;
                	//	num/=2;
					}
  	   }
  	   if(top == -1){
  	   		printf("0 ve 1 ler esit sayidadir ");
		 }else{
		 	printf("%c ler fazladir. Ek %d adet %d gereklidir. ", peek(&top,stack),top+1,!(peek(&top,stack)-'0'));
        	printf("\n");
		 	
		 }

		
}

void DecToBin(int num,int max)
{
        int stack[max], top=-1, rem;
        while(num!=0)
        {
                rem = num%2;
                push(rem, &top, stack, max);
                num/=2;
        }
        while(!isFull(&top,max)){
        	push(0,&top,stack,max);
		}
        while(top!=-1)
                printf("%d", pop(&top, stack));
        printf("\n");
}

char peek(int *top, char stack_arr[]){
	return stack_arr[*top];
}

void push(char x, int *top, char stack_arr[], int max)
{
        if(*top == (max-1))
                printf("Stack Overflow\n");
        else
        {
                *top=*top+1;
                stack_arr[*top] = x;
        }
}/*End of push()*/

char pop(int *top, char stack_arr[])
{
        char x;
        if(*top == -1)
        {
                printf("Stack Underflow\n");
                exit(1);
        }
        else
        {
                x = stack_arr[*top];
                *top=*top-1;
        }
        return x;
}/*End of pop()*/

int isEmpty(int *top){
	if(*top == -1){
		return 1;	
	}else{
		return 0;
	}
}

int isFull(int *top, int max){
	if(*top >= (max-1)){
		return 1;
	}else{
		return 0;
	}
}

int findMax(int x){
	int max =8 ;
	if(abs(x) != 1){
		max =ceil( log(abs(x))/log(2));
	}
	while(max%8 != 0){
        	max++;
	}
	return max;
	
}
