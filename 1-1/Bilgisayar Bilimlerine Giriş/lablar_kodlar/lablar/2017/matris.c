#include<stdio.h>
int main()
{
	int matris[20][20];
	int i,j,N;
	scanf("%d",&N);
	matris[1][0]=matris[1][1]=matris[0][0]=1;
	for(i=2;i<=N;i++){
		matris[i][0]=1;
		for(j=1;j<i;j++){
			matris[i][j]=matris[i-1][j-1]+matris[i-1][j];
		}
		matris[i][i]=1;
	}
	
	for(i=0;i<=N;i++){
		for(j=0;j<=i;j++){
			printf("%3d",matris[i][j]);
		}
		printf("\n");
	}
}
