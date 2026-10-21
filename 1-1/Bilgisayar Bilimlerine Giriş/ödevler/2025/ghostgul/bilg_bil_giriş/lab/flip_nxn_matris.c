#include<stdio.h>  
#define N 4

int main(){
	
	int i, j, d;
	unsigned char image[N][N] = {
		{10, 20, 30, 40},
    	{50, 60, 70, 80},
   		{90, 100, 110, 120},
    	{130, 140, 150, 160}	
	};
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d ", image[i][j]);
		}
		printf("\n");
	}
	unsigned char rotated_image[N][N];
	printf("\n");
	printf("Enter for which side you want to rotate for 90 degrees 1 for left, 2 for right: ");
	scanf("%d", &d);
	switch(d){
		case 1:
			for(i=0;i<N;i++){
				for(j=0;j<N;j++){
					rotated_image[i][j] = image[j][N - i - 1];
				}
			}			
			break;
		case 2:
			for(i=0;i<N;i++){
				for(j=0;j<N;j++){
					rotated_image[i][j] = image[N - j - 1][i];
				}
			}
			break;
	}
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d ", rotated_image[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
