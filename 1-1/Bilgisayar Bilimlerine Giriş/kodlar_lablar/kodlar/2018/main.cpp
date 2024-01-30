#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//*************************************ROBOTU ENGELLERE ÇARPMADAN RASTGELE GEZDÝRME*************************************
int main() {
	srand(time(NULL));
	
	int N,M;
	printf("Satir ve sutun : ");scanf("%d%d",&N,&M);
	
	int A[N][M];
	for(int i = 0;i < N; i++){
		for(int j = 0; j < M; j++){
			printf("%d. satir %d. sutun bilgisi : ",i+1,j+1);
			scanf("%d",&A[i][j]);
		}
	}
	
	for(int i = 0;i < N; i++){
		for(int j = 0; j < M; j++){
			printf("%2d",A[i][j]);
		}
		printf("\n");
	}
	int RX, RY;
	printf("Robotun konum bilgisi : ");scanf("%d%d",&RX,&RY);
	A[RX-1][RY-1] =9;
	
	for(int i = 0;i < N; i++){
		for(int j = 0; j < M; j++){
			printf("%2d",A[i][j]);
		}
		printf("\n");
	}
	
	int B[2][4] = { {0,-1,0,1} , {1,0,-1,0} };
	
	
	for(int i = 0; i < 10; i++){
		int T = rand()%4;
		
		int TX = RX + B[0][T];
		int TY = RY + B[1][T];
		
		if(A[TX][TY] == 0){
			RX = TX;
			RY = TY;
			A[RX][RY] = 9;
		}
		for(int i = 0;i < N; i++){
			for(int j = 0; j < M; j++){
				printf("%2d",A[i][j]);
			}
			printf("\n");
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
