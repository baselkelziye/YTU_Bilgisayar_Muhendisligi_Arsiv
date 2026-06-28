#include <stdio.h>

#define MAX_LENGTH 1000

int main()
{
	int n = 0, m = 0, i = 0, j = 0, k = 0, A[MAX_LENGTH] = {0}, B[MAX_LENGTH] = {0}, C[MAX_LENGTH+1] = {0}, overflow = 0, sum = 0, max_length = 0;
	do
	{
		printf("Birinci dizinin uzunluğunu giriniz: ");
		scanf("%d", &n);
	}while(n <= 0 || n >= MAX_LENGTH);
	do
	{
		printf("İkinci dizinin uzunluğunu giriniz: ");
		scanf("%d", &m);
	}while(m <= 0 || m >= MAX_LENGTH);
	
	for(i = 0; i < n; i++)
	{
		printf("Birinci dizinin %d. elemanını giriniz: ", i+1);
		scanf("%d", &A[i]);
	}
	for(j = 0; j < m; j++)
	{
		printf("İkinci dizinin %d. elemanını giriniz: ", j+1);
		scanf("%d", &B[j]);
	}
	
	max_length = (n > m ? n : m);
	i = n-1, j = m-1, k = max_length; // k = max(n,m);
	
	while(i >= 0 || j >= 0)
	{
		sum = overflow;
		if(i >= 0)
		{
			sum += A[i];
			i--;
		}
		if(j >= 0)
		{
			sum += B[j];
			j--;
		}
		
		if(sum >= 10)
		{
			overflow = 1;
			sum -= 10;
		}
		else
		{
			overflow = 0;
		}
		C[k] = sum;
		k--;
	}
	if(overflow == 1)
	{
		C[k] = 1; // C[0] = 0, C[0] = overflow, these are same
		max_length++;
	}
	else
	{
		for(k = 0; k < max_length; k++)
		{
			C[k] = C[k+1];
		}
	}
	
	// print
	printf("Toplamları:\n");
	for(k = 0; k < max_length; k++)
	{
		printf("%d ", C[k]);
	}
	
	return 0;
}
