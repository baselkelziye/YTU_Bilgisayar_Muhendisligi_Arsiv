#include <stdio.h>
#include <time.h>
int main(){
	int seed=time(NULL);
	char BOARD[20][20];
	char SYMBOLS[]={'*','/','+','%','O'};
	int r, c, i, j, k, l, mode1, mode2, index, halfr, x1, y1, x2, y2, temp, second, value, rawcounter, columncounter, totalmove, totalexplode, dedector;
	printf("Enter the dimensions of the playing area.: \n");
	scanf("%d %d", &r, &c);
	halfr=r/2-1;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			BOARD[i][j]='\0';
		}
	}
	do{
	printf("Enter 1 for Game Mode, and 2 for Control Mode: \n");
	scanf("%d", &mode1);
	} while(mode1!=1 && mode1!=2);
	if(mode1==1){
		printf("Game Mode is starting... \n");
		second=time(NULL);
		while(time(NULL)<second+2){
			//empty
		}
		for(i=halfr+1;i<r;i++){
			for(j=0;j<c;j++){
				seed=(1103515245*seed+12345)%2147483648U;
				index=seed%5;
				BOARD[i][j]=SYMBOLS[index];
			}
		}
	}
	else{
		printf("Control Mode is starting... \n");
		printf("Give the game board.... \n");
		for(i=halfr+1;i<r;i++){
			for(j=0;j<c;j++){
				scanf(" %c", &BOARD[i][j]);
				printf("\033[H\033[J");
				for(k=0;k<r;k++){
					for(l=0;l<c;l++){
						printf("%c \t", BOARD[k][l]);
					}
					printf("\n\n");
				}
			}
		}
	}
	totalmove=0;
	totalexplode=0;
	if(mode1==1){
		printf("\033[H\033[J");
	}
	printf("Total Displacement: %d \nTotal Elements Exploded: %d \n", totalmove, totalexplode);
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("%c \t", BOARD[i][j]);
		}
		printf("\n\n");
	}
	dedector=0;
	while(dedector==0){
		do{
			printf("Enter 1 for relocation, 2 for detonation: \n");
			scanf("%d", &mode2);
		}while(mode2!=1 && mode2!=2);
		if(mode2==1){
			printf("Enter the coordinates... \n");
			scanf("%d, %d", &x1, &y1);
			scanf("%d, %d", &x2, &y2);
			if(x1==x2){
				temp=BOARD[x1-1][y1-1];
				BOARD[x1-1][y1-1]=BOARD[x2-1][y2-1];
				BOARD[x2-1][y2-1]=temp;
				if(mode1==1){
					printf("\033[H\033[J");
				}
				for(i=0;i<r;i++){
					for(j=0;j<c;j++){
						printf("%c \t", BOARD[i][j]);
					}
					printf("\n\n");
				}
				second=time(NULL);
				while(time(NULL)<second+3){
					//empty
				}
				for(i=0;i<r-1;i++){
					for(j=0;j<c;j++){
						BOARD[i][j]=BOARD[i+1][j];
					}
				}
				for(i=0;i<c;i++){
					seed=(1103515245*seed+12345)%2147483648U;
					index=seed%5;
					BOARD[r-1][i]=SYMBOLS[index];
				}
				totalmove++;
				if(mode1==1){
					printf("\033[H\033[J");
				}
				printf("Total Displacement: %d \nTotal Elements Exploded: %d \n", totalmove, totalexplode);
				for(i=0;i<r;i++){
					for(j=0;j<c;j++){
						printf("%c \t", BOARD[i][j]);
					}
					printf("\n\n");
				}
			}
			else{
				printf("The elements you entered are not on the same row! \n");
			}
		}
		else{
			printf("Enter the coordinates... \n");
			scanf(" %d, %d", &x1, &y1);
			x2=x1;
			y2=y1;
			value=BOARD[x1-1][y1-1];
			rawcounter=0;
			while(value==BOARD[x1-1][y1-1] && y1<=c){
				rawcounter++;
				y1++;
			}
			columncounter=0;
			while(value==BOARD[x1-1][y2-1] && x1<=r){
				columncounter++;
				x1++;
			}
			if(rawcounter<3 && columncounter<3){
				printf("Invalid coordinates were provided! \n");
			}
			else{
				if(rawcounter>columncounter){
					for(i=y2-1;i<y2-1+rawcounter;i++){
						BOARD[x2-1][i]='\0';
						totalexplode++;
					}
					for(i=x2-1;i>=0;i--){
						for(j=y2-1;j<y2-1+rawcounter;j++){
							BOARD[i][j]=BOARD[i-1][j];
						}
					}
					for(i=y2-1;i<y2-1-rawcounter;i++){
						BOARD[0][i]='\0';
					}
				}
				else{
					for(i=x2-1;i<x2-1+columncounter;i++){
						BOARD[i][y2-1]='\0';
						totalexplode++;
					}
					for(i=x2-1+columncounter-1;i>=0;i--){
						BOARD[i][y2-1]=BOARD[i-columncounter][y2-1];
					}
					for(i=0;i<=columncounter;i++){
						BOARD[i][y2-1]='\0';
					}
				}
				if(mode1==1){
					printf("\033[H\033[J");
				}
				printf("Total Displacement: %d \nTotal Elements Exploded: %d \n", totalmove, totalexplode);
				for(i=0;i<r;i++){
					for(j=0;j<c;j++){
						printf("%c \t", BOARD[i][j]);
					}
					printf("\n\n");
				}
			}
		}
		for(i=0;i<c;i++){
			if(BOARD[0][i]!='\0'){
				dedector=1;
			}
		}
	}
	printf("The game is over.");
	return 0;
}
