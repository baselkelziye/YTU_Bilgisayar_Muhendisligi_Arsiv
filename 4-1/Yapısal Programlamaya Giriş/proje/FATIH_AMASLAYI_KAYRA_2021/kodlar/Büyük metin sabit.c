#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

void tekrarhesap(char *kucukMetin, int t, int *tekrar);
void KMP(char *kucukMetin, char *buyukMetin,int q,int t);

int main()
{
	int i;
	char buyukMetin[5*SIZE]={'a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a'};
	char a,b,c;
	char kucukMetin[SIZE]={'a','a','a'};
	for(i=2;i<22;i++){
		printf("\nBuyuk metin = 22 \t Kucuk Metin = %d\t",i+1);
		if(i%2==0)
		kucukMetin[i]='a';
		else{
			if(i%3==0){
				kucukMetin[i]='b';
			}
			else
			kucukMetin[i]='c';
		}
		
		KMP(kucukMetin, buyukMetin,21,i);
		
	}
	

	return 0;
}
void tekrarhesap(char *kucukMetin, int t, int *tekrar)
{
	int len = 0;
	int i ;
	
	tekrar[0] = 0 ;
	i = 1;

	while(i <  t)
	{
		if(kucukMetin[i] == kucukMetin[len])
		{
			len++;
			tekrar[i] = len;
			i++;
			printf("*");
		}
		else
		{
			if(len != 0)
			{

				len = tekrar[len - 1];
				printf("*");
			}
			else
			{
				tekrar[i] = 0;
				i++;
				printf("*");
			}
		}
	}
}
void KMP(char *kucukMetin, char *buyukMetin,int q, int t)
{

	int tekrar[100];
	int j = 0;

	tekrarhesap(kucukMetin, t, tekrar);
	
	int i = 0;
	while(i < q)
	{
		if(kucukMetin[j] == buyukMetin[i])
		{
			j++;
			i++;
			printf("*");
		}
		if(j == t)
		{
			printf("*");
			j = tekrar[j-1];
		}
		else if(kucukMetin[j] != buyukMetin[i])
		{
			if(j != 0){
			
				j = tekrar[j-1];
				printf("*");}
			else{
			printf("*");
				i++;}
		}
	}
}









