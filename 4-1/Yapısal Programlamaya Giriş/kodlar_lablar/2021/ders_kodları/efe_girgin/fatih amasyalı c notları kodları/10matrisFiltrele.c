// Verilen bir matrisi baska bir matris ile filtreleyen programý yazalým
#include <stdio.h>
int main()
{
		int i,j,n,m,k,l,p,r,top;				
		int mat[20][20],mat2[20][20];
		int filtre[11][11];
		printf("Filtrelenecek matrisin boyutlarini veriniz\n");
		scanf("%d %d",&m,&n);
		printf("Filtrelenecek matrisi veriniz\n");
		for (i=0;i<m;i++)
			for (j=0;j<n;j++)
			{
				scanf("%d",&mat[i][j]);
				mat2[i][j]=mat[i][j];
			}
		
		printf("Filtrenin boyutlarini veriniz\n");
		scanf("%d %d",&k,&l);
		for (i=0;i<k;i++)
			for (j=0;j<l;j++)
				scanf("%d",&filtre[i][j]);
				
		for (i=k/2;i<n-k/2;i++)//for (i=1;i<n-1;i++) //
			for (j=l/2;j<m-l/2;j++)//for (j=1;j<m-1;j++)
			{
				top=0;
				for (p=-k/2;p<=k/2;p++) //for (p=-1;p<=1;p++)
					for (r=-l/2;r<=l/2;r++) //for (r=-1;r<=1;r++)
					{
							top=top+mat[i+p][j+r]*filtre[p+k/2][r+l/2];
							//printf("%d %d",i+p)
					}
					
				mat2[i][j]=top;
			}
		printf("Filtrelenmis matris:\n");
		for (i=0;i<n;i++)
		{
			for (j=0;j<m;j++)
				printf("%d ",mat2[i][j]);
			printf("\n");
		}		
		return 0;
}
