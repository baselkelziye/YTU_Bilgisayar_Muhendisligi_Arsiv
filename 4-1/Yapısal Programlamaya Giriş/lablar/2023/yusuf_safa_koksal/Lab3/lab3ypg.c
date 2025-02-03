#include<stdio.h>
#define MAX 20

void clean(int matrix[][MAX],int len,int x,int y,int roads[MAX][2],int currIndex, int *totalRoad);
void printCleanedRoom(int roads[MAX][2],int currIndex,int len);
void takeMatrix(int matrix[][MAX],int len);
void printMatrix(int matrix[][MAX],int len);

int main()
{
	int x, y;
	int len, totalRoad=0;
	int matrix[MAX][MAX];
	int roads[MAX][2];
	
	printf("Enter matrix size: ");
	scanf("%d",&len);
	takeMatrix(matrix,len);
	printMatrix(matrix,len);
	
	clean(matrix, len, 0, 0, roads, 0, &totalRoad);
	
	printf("\nTotal Road: %d",totalRoad);
	return 0;
}

void clean(int matrix[][MAX],int len,int x,int y,int roads[MAX][2],int currIndex, int *totalRoad)
{
	if(x==len-1 && y==len-1)
	{
		printCleanedRoom(roads, currIndex, len);
		*totalRoad=*totalRoad+1;
	}
	else if(matrix[y][x]==1)
	{
		roads[currIndex][0]=y;
		roads[currIndex][1]=x;
		
		currIndex++;
		
		clean(matrix, len, x, y+1, roads, currIndex, totalRoad);
		clean(matrix, len, x+1, y, roads, currIndex, totalRoad);
	}
}

void printCleanedRoom(int roads[MAX][2],int currIndex,int len)
{
	int i;
	
	printf("\n");
	for(i=0;i<currIndex;i++)
	{
		printf("(%d, %d) ",roads[i][0],roads[i][1]);
	}
	printf("(%d, %d) ",len-1,len-1);
}

void takeMatrix(int matrix[][MAX],int len)
{
	int i, j;
	
	for(i=0;i<len;i++)
	{
		for(j=0;j<len;j++)
		{
			printf("[%d][%d]: ",i,j);
			scanf("%d",&matrix[i][j]);
		}
	}
}

void printMatrix(int matrix[][MAX],int len)
{
	int i, j;
	
	printf("\nMatrix:\n");
	for(i=0;i<len;i++)
	{
		for(j=0;j<len;j++)
		{
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}





