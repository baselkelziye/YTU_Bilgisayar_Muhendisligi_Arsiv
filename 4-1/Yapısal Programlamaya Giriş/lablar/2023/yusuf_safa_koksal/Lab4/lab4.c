#include<stdio.h>
#define MAX 50

void printChart(int matrix[][3],int len,int head);
void getInfo(int matrix[][3],int len);

int main()
{
	int i, j;
	int matrix[MAX][3];
	int N, head, control=0;
	
	printf("Matris boyutu girin: ");
	scanf("%d",&N);
	
	getInfo(matrix,N);
	
	while(!control)
	{
		control=1;
		printf("\nHead degerini girin: ");
		scanf(" %d",&head);
		
		if(!(head>=0 && head<=N-1))
		{
			control=0;
			printf("Head degeri 0 ile %d arasinda olmalidir!",N-1);
		}	
	}
	
	
	printf("\nSirasiyla her bir islemin linkini giriniz:\n");
	for(i=0;i<N;i++)
	{
		printf("%d birim suren %c isleminin linki:  ",matrix[i][1],(char)matrix[i][0]);
		scanf("%d",&matrix[i][2]);
	}
	
	printf("\n");
	printChart(matrix,N,head);
	
	return 0;
}

void printChart(int matrix[][3],int len,int head)
{
	int i;
	
	while(head!=-1)
	{
		for(i=0;i<matrix[head][1];i++)
		{
			printf("%c ",(char)matrix[head][0]);
		}
		head=matrix[head][2];
	}
}

void getInfo(int matrix[][3],int len)
{
	int i, j, tmpInt, control;
	char tmpChar;
	
	printf("\nHarf kodlarini giriniz: ");
	for(i=0;i<len;i++)
	{
		control=0;
		while(!control)
		{
			control=1;
			scanf(" %c",&tmpChar);
			
			j=0;
			while(j<i)
			{
				if((int)tmpChar==matrix[j][0])
				{
					printf("\nGirilen bir harf tekrar girilemez!\n");
					control=0;
				}
				j++;
			}
		}
		
		matrix[i][0]=(int)tmpChar;
	}
	
	printf("\nYapilacak olan islerin harf kodlari asagidaki gibidir:\n");
	for(i=0;i<len;i++)
	{		
		printf("%c ",(char)matrix[i][0]);
	}
	
	printf("\n\nSirasiyla is surelerini giriniz:\n");
	for(i=0;i<len;i++)
	{		
		control=0;
		while(!control)
		{
			printf("'%c' islemi: ",(char)matrix[i][0]);
			control=1;
			scanf("%d",&tmpInt);
		
			if(tmpInt<1)
			{
				printf("\nSure en az 1 birim olmalidir!\n");
				control=0;
			}
		}
		matrix[i][1]=(int)tmpInt;
	}
}
