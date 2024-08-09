#include<stdio.h>
#include<time.h>
#include<string.h>
#define MAX 15
#define MOVE_LIMIT 150


void mainMenu(void);
void gameMenu(int matrix[][MAX], int N);
void drawBoard(int matris[][MAX], int N);
void readFromFile(int matris[][MAX], char *fileName);
void generRandomMatrix(int matrix[][MAX], int N);
void showScores(void);
int calcScore(void);
void playManuel(int matrix[][MAX], int N);
int finishControl(int matrix[][MAX], int N);
void connectDot(int matrix[][MAX]);
void pushMove(int matrix[][MAX], int records[][MAX*MAX], int N, int *top);
void popMove(int matrix[][MAX], int records[][MAX*MAX], int N, int *top);

int main(){
	//int matrix[MAX][MAX] = {{0}};
	//int N  = 5;
    mainMenu();
	//gameMenu();
	//drawBoard(matrix, N);
	//readFromFile(matrix, fileName);
	//generRandomMatrix(matrix, N);
	//drawBoard(matrix, N);
	//showScores(void);
	//calcScore(void);
	
	return 0;
}


void mainMenu(void) {
	
	int choice;
	int i,j,matrix[MAX][MAX]={{0}};
	int N;
    char fileName[20];
  	
	
	do{
		printf("\n********* Main Menu *********\n\n");
		printf("1-Generate random matrix\n");
		printf("2-Generate matrix from file\n");
		printf("3-Show users scores\n");
		printf("0-Exit\n");
		printf("\npress any key from the menu to select option or press zero to exit\n");
		printf("choice: ");
		
		do{
			scanf("%d",&choice);
			if(choice<0)
				printf("\nenter the valid option: ");
		}while(choice<0);
		
		if(choice== 1 || choice==2){
			printf("enter N, which is the size of the matrix: ");
			scanf("%d",&N);
		}
		
		switch(choice){
			
			case 1:
				
				generRandomMatrix(matrix, N);
				drawBoard(matrix, N);
				gameMenu(matrix, N);
				break;
			
			case 2:
				
				printf("Dosya Adini Giriniz: ");
  				scanf("%s",fileName);
				readFromFile(matrix,fileName);
				drawBoard(matrix, N);
				gameMenu(matrix, N);
				break;
			
			case 3:
				
				showScores();
				break;
				
		}
	}while(choice!=0);
}

void gameMenu(int matrix[][MAX], int N) {
	int choice;
	
	do{
		printf("\n********* Game Menu *********\n\n\n");
		printf("1-Play in manuel mode\n");
		printf("2-Play in auto mode\n");
		printf("3-Back to Main Menu\n");
		printf("\npress any key from the menu to select game mode or press 3 back to main menu\n");
		printf("choice: ");
		
		do{
			scanf("%d",&choice);
			if(choice<0)
				printf("\nenter the valid option: ");
		}while(choice<0);
		
		switch(choice){
			
			case 1:
				playManuel(matrix, N);
				break;
				
			
			case 2:
				
				
				break;
			
			
			case 3:
				
				mainMenu();
				break;
			
		}
		
	}while(choice!=3);
}

void readFromFile(int matrix[][MAX], char *fileName){
	int i,j, temp;
	FILE *data = fopen(fileName,"r");
	if(!data){
        printf("Dosya Acilamadi!");
		return;
    }
    while(!feof(data)){
        fscanf(data,"%d %d %d\n",&i,&j,&temp);  
		matrix[i][j]=temp; 
    }  
  	fclose(data); 
   // Buraya kadar olan bolumde dosyadan okuma yapiliyor. Kodu degistirmeyiniz.
}

void drawBoard(int matrix[][MAX], int N){
    int i,j,k;
    printf("\n   ");
    for (k=0;k<N;k++)
        printf("  %d    ",k);
    for(i=0;i<N;i++){
        printf("\n   ");
        for (k=0;k<N;k++)
            printf("-------");
        printf("\n%d |",i);

        for(j=0;j<N;j++){
            if (matrix[i][j]!=0)
                printf("  %d   |",matrix[i][j]);
            else
                 printf("      |",matrix[i][j]);
        }
    }
    printf("\n   ");
    for (k=0;k<N;k++)
        printf("-------");
}

void generRandomMatrix(int matrix[][MAX], int N){
	srand(time(NULL));
	int i, j, rand1, rand2, doublePoint = 0, counter = 0;
	
	while(counter<N){
		
		rand1 = rand()%N;
		rand2 = rand()%N;
		
		if(matrix[rand1][rand2] == 0){
			matrix[rand1][rand2] = counter +1;
			doublePoint++;
		}
		
		if(doublePoint == 2){
			counter++;
			doublePoint = 0;
		}		
	}
}

void playManuel(int matrix[][MAX], int N) {
	
	int i, j, top, finish=0, score=0, undo_counter;
	int records[MOVE_LIMIT][MAX*MAX];
	int *p_top = &top, *p_undo = &undo_counter;
	char c;
	top = -1;
	
	*p_undo = 0;
	while(!finish){
		connectDot(matrix);
		pushMove(matrix, records, N, p_top);
		drawBoard(matrix, N);
		printf("\n'u' for undo or 'c' for continue: ");
		scanf(" %c",&c);		
		if(c=='u'){
			popMove(matrix, records, N, p_top);
			drawBoard(matrix, N);
			*p_undo++;
		}
		finish = finishControl(matrix, N);
	}
	
	score = calcScore();
	if(finish)
		printf("\nCongrats, finished game\n");

		printf("\nYour score is :%d\n",score);;
		mainMenu();
	
}

void showScores(void) {
	
	
	
	
}

int calcScore(void){
	
	
	
}

int finishControl(int matrix[][MAX], int N) {
	int finish = 1, i, j;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(!matrix[i][j])
				finish=0;
		}
	}
	
	return finish;
}

void connectDot(int matrix[][MAX]){
	int i, j, m, n, k, l;
	
	printf("\nenter the coordinates of the points");
	printf("\n(enter at the same time with space) first points i j :");
	scanf("%d %d",&m ,&n);
	
	printf("\n(enter at the same time with space) second points i j :");
	scanf("%d %d",&k ,&l);
	
	if(!(m-k)){
		if((l-n)>0){
			for(i=n+1;i<=l;i++){
				matrix[m][i] = matrix[m][n];
			}
		}else{
			for(i=l;i>=n;i--){
				matrix[m][i] = matrix[m][n];
			}
		}
	}else if(!(l-n)){
		if((k-m)>0){
			for(i=m+1;i<=k;i++){
				matrix[i][l] = matrix[m][n];
			}
		}else{
			for(i=k;i>=m;i--){
				matrix[i][l] = matrix[m][n];
			}
		}
	}
}

void pushMove(int matrix[][MAX], int records[][MAX*MAX], int N, int *top){
	
	int i, j;
	
	if((*top+1) == MOVE_LIMIT){
		printf("move limit exceeded");
	}else{
		*top+=1;
		printf("%d",*top);
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				records[(*top)][(i*N)+j] = matrix[i][j];
			}
		}
	}
}

void popMove(int matrix[][MAX], int records[][(MAX*MAX)], int N, int *top){
	int i, j;
	
	if(*top==-1){
		printf("you haven't made a move yet");
	}else{
		printf("%d",*top);
		*top-=1;
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				matrix[i][j] = records[(*top)][(i*N)+j];
			}
		}
	}
}



