// Verilen bir A dizisini bir B dizisi ile filtreleyen programý yazalým
#include <stdio.h>
int main()
{
	static int i,j,M,N,A[30],B[30],C[30],top;
	printf("A nin ve B nin eleman sayisi? \n");
	scanf("%d %d",&N,&M);
	printf("A?\n");
	for (i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		C[i]=A[i];
	}
	for (i=0;i<M;i++)
		scanf("%d",&B[i]);
	for (i=0;i<N-M+1;i++)
	{
		top=0;
		for (j=0;j<M;j++)
		{
			top=top+B[j]*A[i+j];
		}
		C[i+M/2]=top;
	}
	for (i=0;i<N;i++)
		printf("%d ",C[i]);
	
	getch();
	return 0;	
}
