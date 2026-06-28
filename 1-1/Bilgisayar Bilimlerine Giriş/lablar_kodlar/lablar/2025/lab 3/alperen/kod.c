#include <stdio.h>

#define MAX_SIZE 100
#define MAP_SIZE 256

int main()
{
	int n = 0, m = 0, i = 0, j = 0, M[MAX_SIZE][MAX_SIZE], input = 0, A[MAP_SIZE] = {0};
	do
	{
		printf("Satır sayısını giriniz: ");
		scanf("%d", &n);
	}while(n <= 0 || n >= MAX_SIZE);
	do
	{
		printf("Sütun sayısını giriniz: ");
		scanf("%d", &m);
	}while(m <= 0 || m >= MAX_SIZE);
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			do
			{
				printf("%d. satır, %d. sütun değerini giriniz (0-255): ", i+1, j+1);
				scanf("%d", &input);
			}while(input < 0 || input > 255); // valid range: 0-255
			M[i][j] = input;
			A[M[i][j]]++;
		}
	}
	
	for(i = 0; i < MAP_SIZE; i++)
	{
		if(A[i] > 1)
			printf("%d ", i);
	}
	printf("\n");
	
	
	
	
	return 0;
}
