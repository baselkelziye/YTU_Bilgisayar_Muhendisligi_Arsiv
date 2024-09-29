#include <stdio.h>
int main(){
	int N,i,j;
	printf("lutfen satir sayisini giriniz\n");
	scanf("%d",&N);
	
	for(i=N;i>=1;i--){
		for(j=1;j<=i;j++){
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}
//Example 4: Inverted half pyramid of *
/*
* * * * *
* * * *
* * * 
* *
*
C Program*/
