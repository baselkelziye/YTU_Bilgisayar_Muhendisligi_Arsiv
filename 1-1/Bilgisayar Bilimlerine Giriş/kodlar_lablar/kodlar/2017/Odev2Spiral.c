#include <stdio.h>
int main()
{
	int i,j,N,M,control=1;
	char mat[30][30];
	
	scanf("%d %d",&N,&M);
	// en dýþ çerçeve
	for (i=0;i<N;i++)
		for (j=0;j<M;j++)
			mat[i][j]=' ';	
			
	for (j=0;j<M;j++)
	{
		mat[0][j]='x';	
		mat[N-1][j]='x';
	}
				
	for (i=1;i<N-1;i++)
	{
		mat[i][0]='x';	
		mat[i][M-1]='x';
	}
	mat[1][0]=' ';
	i=2; j=1;
	
	while (control==1)
	{
		if (mat[i][j]=='x' || mat[i+1][j]=='x')
			control = 0;
		
		//saða gidiþ
		while(control==1 && mat[i][j+1]==' ')
		{
			mat[i][j]='x';
			j=j+1;
		}
		j=j-1;
		i=i+1;

		if (mat[i][j]=='x'||mat[i][j-1]=='x')
			control = 0;
			
		//aþaðý gidiþ
		while(control==1 && mat[i+1][j]==' ')
		{
			mat[i][j]='x';
			i=i+1;
		}
		i=i-1;
		j=j-1;
		
		if (mat[i][j]=='x'||mat[i-1][j]=='x')
			control = 0;
			
		//sola gidiþ
		while(control==1 && mat[i][j-1]==' ')
		{
			mat[i][j]='x';
			j=j-1;
		}
		i=i-1;
		j=j+1;
		
		if (mat[i][j]=='x'||mat[i][j+1]=='x')
			control = 0;
			
		//yukarý gidiþ
		while(control==1 && mat[i-1][j]==' ')
		{
			mat[i][j]='x';
			i=i-1;
		}
		i=i+1;
		j=j+1;
	}

	//ekrana yazma
	for (i=0;i<N;i++)
	{
		for (j=0;j<M;j++)
			printf("%c ",mat[i][j]);
		printf("\n");
	}
	return 0;
}
