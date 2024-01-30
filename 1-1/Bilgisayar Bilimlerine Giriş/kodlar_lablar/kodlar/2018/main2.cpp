#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
	int A[201];
	
	for( int i = 1; i <= 200; i++ ){
		int T1 = rand()%101;
		int T2 = rand()%101;
		
		int T = int((T1 + T2)/2);
		
		A[i] = T;
	}	
	int Counter[101] = {0};
	
	for( int i = 1; i <= 200; i++){
		Counter[A[i]]++;
	}
	
	for(int i = 1; i <= 100; i++){
		for(int j = 1; j <= Counter[i]; j++)
			printf("%s","*");
		printf("\n");
	}
	
	
	
	
	
	
	
	
	
	return 0;
}
