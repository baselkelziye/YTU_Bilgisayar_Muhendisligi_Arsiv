#include<stdio.h>
int main()
{
	int a[10][10];
	int trp[10][10];
	int i,j,n,m;

	printf("matrisin satir ve sutun sayisini veriniz\n");
	scanf("%d %d",&n,&m);

	printf("matrisin elemanlarini veriniz\n");
	for (i=0;i<n;i++)
		for (j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	
	for (i=0;i<n;i++)
		for (j=0;j<m;j++)
			trp[j][i]=a[i][j];
	
	printf("ilk matrisin transpozesi\n");
	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
			printf("mat[%d][%d]:%d ",i,j,trp[i][j]);
		printf("\n");
	}
	return 0;
}
