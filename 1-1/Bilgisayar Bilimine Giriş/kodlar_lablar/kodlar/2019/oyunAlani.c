#include <stdio.h>
int main()
{
	int n=6,m=6,i,j,a,puan,engel=0,yon,adimSay;
	int mat[6][6]={	{5,6,2,7,1,0},
					{4,-1,-1,-1,1,2},
					{2,1,3,-1,2,4},
					{5,6,1,-1,5,3},
					{2,2,4,-1,-1,-1}};
	scanf("%d",&adimSay);
	i=0;
	j=0;
	a=0;
	puan=mat[0][0];
	while ((a<adimSay) && (engel==0))
	{
		scanf("%d",&yon);
		if (yon==1)
			j++;
		else
			i++;
		
		if (mat[i][j]==-1)
		{
			puan=0;
			engel=1;
		}
		else
			puan=puan+mat[i][j];
		
		a++;
	}
	printf("%d",puan);
}
