#include <stdio.h>
#include <conio.h>


int main() {
	//*********************************************KARMA�IKLIK yakla��k N^2********************************************************
	
	/*int T = 0;
	for(int i = 1; i <= 1000; i++){
		
		for(int j = 1; j <= i; j++){
			T = T+1;printf("% d",T);
		}
		printf("\n");
	}*/
	
	//******************************************KARMA�IKLIK 3 :)*******************************************************************
	
	int N;//
	printf("Kacinci satirin son elemani");scanf("%d",&N);
	printf("%d",N*(N+1)/2);	
	
	
	
	getch();
	return 0;
}
