// Bir dizinin sýralý olup olmadýðýný bulan program
// Ardýþýk kontrol O(n) 
#include <stdio.h>
int main()
{
	int dizi[10];
	int n,i;
	scanf ("%d",&n);
	for (i=0;i<n;i++)
		scanf("%d",&dizi[i]);
	i=0;
	while ((i<n-1) && (dizi[i]<=dizi[i+1]))
		i++;
	if (i==(n-1))
		printf("sirali\n");
	else
		printf("sirasiz\n");
	
	return 0;	
}
