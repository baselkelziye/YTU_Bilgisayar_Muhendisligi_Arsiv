#include <stdio.h>
#include <stdlib.h>

int topla(int x, int y)
{
	return (x + y);
}

int cikar(int x, int y)
{
	return (x - y);
}

int carp(int x, int y)
{
	return (x * y);
}

int bol(int x, int y)
{
	return (x / y);
}

void faktoriyel(int x)
{
	int result = 1;
	int i = x;
	
	while(x > 1){
		result *= x--;
	} 
	
	if(i == 0){
		printf("-> 0! = 1\n\n");
	}
	else if(i == 1){
		printf("-> 1! = 1\n\n");
	}
	else if(i > 1){
		printf("-> %d! = ", i);
	
		for(i; i>0; i--){					
			
			if(i == 1){
				printf("%d = %d\n\n", i, result);
			}
			else if(i > 1){
				printf("%d x ", i);	
			}
		}
	}
	else{
		printf("-> Yanlis giris yaptiniz. Lutfen bir dogal sayi giriniz!\n\n");
	}
}

