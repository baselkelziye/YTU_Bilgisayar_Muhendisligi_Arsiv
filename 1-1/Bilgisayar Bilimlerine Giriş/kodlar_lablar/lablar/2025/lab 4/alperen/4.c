#include <stdio.h>

#define MAX_SIZE 100

int main()
{
	int n = 0, i = 0, k = 0, square_count = 0, square_size = 0, offset = 0;
	char M[MAX_SIZE][MAX_SIZE] = {'\0'};
	do
	{
		printf("Matrisin boyutunu giriniz: ");
		scanf("%d", &n);
	}while(n <= 0 || n >= MAX_SIZE);
	
	square_count = n/4 + 1;
	square_size = n;
	offset = 0;
	
	for(k = 0; k < square_count; k++)
	{

		for(i = 0; i < square_size; i++)
		{
			M[offset][offset+i] = '*'; // top
			M[n-1-offset][offset+i] = '*'; // bottom
			M[offset+i][offset] = '*'; // left
			M[offset+i][n-1-offset] = '*'; // right
		}
		square_size -= 4;
		offset += 2;
	}
	
	for(k = 0; k < n; k++)
	{
		for(i = 0; i < n; i++)
		{
			printf("%c", M[k][i] == '*' ? '*' : ' ');
		}
		printf("\n");
	}
	
	
	return 0;
}
