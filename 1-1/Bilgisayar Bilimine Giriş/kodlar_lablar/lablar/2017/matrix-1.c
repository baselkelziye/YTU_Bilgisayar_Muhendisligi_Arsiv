#include<stdio.h>
/*
Matrix
*/
int main(){
	int arr[3][4] = {{1,2,3,4},{1,2,3},{0}};
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<3;i++)
		printf("%d ", arr[i][i]); //kosegenleri yazdirir
	return 0;
}
