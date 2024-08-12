#include <stdio.h> 
#include <time.h>
#include <stdlib.h>
#define k 8

int main()
{
	srand(time(NULL)); 
	static int M[k][k];
	int N,i,j,s,r;
	int x,y;
	printf("Adim sayisini giriniz:");
	scanf("%d",&N);
	int step[8][2]={{-1,2},{1,2},{-1,-2},{1,-2},{-2,1},{-2,-1},{2,1},{2,-1}}; //yonler	
	
	x=0;
	y=0;	
	for (s=0;s<N;s++)
	{	
		do{
			r=rand()%k;	
		}while(x+step[r][0] < 0 || x+step[r][0] >= 8 || y+step[r][1] < 0 || y+step[r][1] >= 8); //uygun random sayi uretilene kadar devam eder.
		
		
		x+=step[r][0];
		y+=step[r][1];
		M[x][y]=s+1;//++;
		
		printf("%d. adim \n\n",s+1);
		for (i=0;i<8;i++)	//print matrix
		{
		for (j=0;j<8;j++)
			printf("%2d ",M[i][j]);
		printf("\n");
		}
		
	}
	
}
