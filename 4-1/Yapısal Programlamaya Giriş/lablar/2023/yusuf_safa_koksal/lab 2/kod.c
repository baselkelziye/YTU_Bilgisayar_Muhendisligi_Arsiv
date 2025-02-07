#include<stdio.h>
#include<time.h>
#define MAX 100

int main(){
	
	int i, j;
	int number, len, step=0;
	int firstUserScore=0, secondUserScore=0, currentScore=0;
	char input='e';
	
	int matrix[MAX][MAX];
	int tempMatrix[MAX][MAX];
	
	srand(time(NULL));
	
	printf("Please, enter size of matrix: ");
	scanf("%d",&len);
	
	for(i=0;i<len;i++)
	{
		for(j=0;j<len;j++)
		{
			number=rand() % (len*len) + 1;     
			matrix[i][j]=number;
		}
	}
	
	while(input=='e' || input=='E')
	{
		step++;
		currentScore=0;
		
		for(i=0;i<len;i++)
		{
			for(j=0;j<len;j++)
			{
				tempMatrix[j][len-i-1]=matrix[i][j];
			}
		}
		
		for(i=0;i<len;i++)
		{
			printf("\n");
			for(j=0;j<len;j++)
			{
				matrix[i][j]=tempMatrix[i][j];
				printf("%d ",matrix[i][j]);
			}
		}
		
		for(i=0;i<len;i++)
		{
			currentScore+=matrix[len-1][i];
		}
		
		if(step%2==1)
		{
			firstUserScore+=currentScore;
		}
		
		else
		{
			secondUserScore+=currentScore;
		}
		
		printf("\nAyse: %d      Betul: %d\n",firstUserScore,secondUserScore);
		
		if(step==6)
		{
			step=0;
			
			if(firstUserScore>secondUserScore){
				printf("Ayse won!");
			}
			else if(firstUserScore<secondUserScore){
				printf("Betul won!");
			}
			else{
				printf("Draw!");
			}
			
			firstUserScore=0;
			secondUserScore=0;
				
			printf("\n\nPlease, enter 'e' or 'E' to play again: ");
			scanf(" %c",&input);
			
			if(input=='e' || input=='E'){
				
				printf("\nPlease, enter size of matrix: ");
				scanf("%d",&len);
				
				for(i=0;i<len;i++)
				{
					for(j=0;j<len;j++)
					{
						number=rand() % (len*len) + 1;
						matrix[i][j]=number;
					}
				}
			}
		}
	}
	
	return 0;
}
