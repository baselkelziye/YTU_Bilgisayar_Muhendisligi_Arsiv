#include <stdio.h>
int main()
{
	int i=0,temp,n=11;
	int array[11]={1,3,14,5,3,7,3,5,14,3,2};
	// bir diziyi ters çevirme
	for (i=0;i<n/2;i++)  
	{
		temp=array[i];
		array[i]=array[n-i-1];
		array[n-i-1]=temp;
	}
	for (i=0;i<n;i++)
		printf("%d ",array[i]);
	
	// bir dizi palendrom mu?
	i=0;
	while ((i<n/2) && (array[i]==array[n-i-1]))
		i++;
	
	if (i>=n/2)
		printf("palendrom\n");
	else
		printf("palendrom degil\n");
	
	
	return 0;
}
