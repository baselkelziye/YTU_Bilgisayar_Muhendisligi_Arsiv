#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define RED   "\x1B[31m"


void delay(int number_of_seconds)
{

    int milli_seconds = 1000 * number_of_seconds;
  
    clock_t start_time = clock();
  
    while (clock() < start_time + milli_seconds);
}
  

void yol_bul(int row,int col, char **maze, int **matris, int *puan)
{
	int i, j;
	int time=1;
	for (i = 0; i < row; ++i) {
		for (j = 0; j < col; ++j) {
			if (maze[i][j] != 's' && matris[i][j] == 4) {
				if(maze[i][j] == '#'){
					*puan = *puan+10;
					maze[i][j]='#';
					time++;
				}else{
					maze[i][j] ='.';
					time++;
				}
			}
			/*if(time%100==0){
				printf("\n");
				print_maze(row,col,maze);
				printf("puan:%d\n",*puan);
			}*/	
		}
	}
	
}



int dfs(int row, int col, int **matris)
{	
	delay(0.1);
	
	int* current = &matris[row][col];

	if (*current == 3) {
		return 1;
	}

	if (*current == 1) {
		*current = 4;
		
		if (dfs(row - 1, col, matris)){
			*current = 4;
			return 1;
		}
		if (dfs(row, col + 1, matris)){
			*current = 4;
			return 1;		
		} 
		if (dfs(row + 1, col, matris)){
			*current = 4;
			return 1;
		} 
				if (dfs(row, col - 1, matris)){
			*current = 4;
			return 1;
		} 
	}

	return 0;
}
void print_matris(int row, int col, int **matris)
{
	int i, j;
	for (i = 0; i < row; ++i) {
		for (j = 0; j < col; ++j) {
			//printf("\033[1;31m");
			printf("%d", matris[i][j]);
		}
		printf("\n");
	}	
	printf("\n");
}



void print_maze(int row, int col, char **maze)
{
	int i, j;
	for (i = 0; i < row; ++i) {
		for (j = 0; j < col; ++j) {
			//printf("\033[1;31m");
			printf("%c", maze[i][j]);
		}
		printf("\n");
	}	
	printf("\n");
}

int main(){
	srand(time(NULL));
	int i,j,k;
	int **matris;
	char **maze;
	FILE *f = fopen("maze.txt","r");
	char buffer[10000];
	int col;
	int row = 1;
	int start_col;
	int start_row;
	int **randomList = (int **)malloc(0*sizeof(int*));
	int m=0;
	int randomNum;
	int puan = 0;
	
	do {
		buffer[i] = fgetc(f);

	} while (buffer[i++] != '\n');
	col = --i;
	
	i=0;
	
	do {
		buffer[i] = fgetc(f);

		if(buffer[i] == '\n'){
			row++;
		}
	} while (buffer[i++] != EOF);
	printf("sutun sayisi %d\n satirsayisi: %d\n",col,row);

	matris = (int **)calloc((row), sizeof(int*));
	maze = (char **)malloc((row)*sizeof(char*));
	for(i=0;i<(row);i++){
		matris[i] = (int *)calloc((col), sizeof(int));
		maze[i] = (char *)malloc(col*sizeof(char));
	}
	i=0;
	j=0;
	k=0;
	rewind(f);
	do {
		buffer[i] = fgetc(f);
		printf("%c",buffer[i]);
		if(buffer[i] == '\n'){
			j++;
			k=0;
		}
		if(buffer[i] == 'b'){
			matris[j][k] = 1;
			maze[j][k] = 's';
			start_col=k;
			start_row=j;
			k++;
		}else if(buffer[i] == 'c'){
			matris[j][k] = 3;
			maze[j][k] = 'f';
			k++;
		}
		else if(buffer[i] == ' '){
			matris[j][k] = 1;
			maze[j][k] = '\0';
				randomList = (int **)realloc(randomList, sizeof(int*)*++m);
				randomList[m-1] = (int *)malloc(3*sizeof(int));
				randomList[m-1][0] = m-1;
				randomList[m-1][1] = j;
				randomList[m-1][2] = k;
				
			k++;
		}else if(buffer[i] == '+' || buffer[i] == '-' || buffer[i] == '|'){
			maze[j][k] = buffer[i];
			k++;
		}
	} while (buffer[i++] != EOF);

		for(i=0;i<20;i++){
		randomNum= rand() % m+1;

		j=	randomList[randomNum][1];
		k= 	randomList[randomNum][2];
		maze[j][k] = '#';
		}	
		maze[29][4] = '#';
		

	printf("\n\n\n\n");
	
	if (!dfs(start_row, start_col, matris)) {
		printf("\nYOL YOK\n");
	} else {
		yol_bul(row, col, maze, matris, &puan);
		print_maze(row, col, maze);
	}
	

	printf("\n puan : %d\n\n", puan);

	



//print_matris(row,col,matris);
//print_maze(row,col,maze);


	for(i =0; i<row;i++){
		free(matris[i]);
		free(maze[i]);
	}free(matris);
	free(maze);
	
	fclose(f);
	
	return 0;
	
}
