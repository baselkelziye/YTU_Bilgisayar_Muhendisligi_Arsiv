#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 50

void drawBoard(int matrix[max][max], int n);
void readFromFile(int matrix[max][max], int location[4][max], char *fileName);
void randomMatrix(int matrix[max][max], int location[4][max], int n);
int manualGameFunction(int matrix[max][max], int move[2][max], int label[max][max], int location[4][max], int n, int* p);
int undoFunction(int matrix[max][max], int move[2][max], int n, int i );
void automatic(int matrix[max][max], int location[4][max], int label[max][max], int routeMatrix[max][max][2], int n, int row_location, int column_location, int index, int j, int* p, int* f);
int controlFunction(int matrix[max][max], int location[4][max], int label[max][max], int n, int* p);
void recursiveControl(int matrix[max][max], int location[4][max], int label[max][max], int n, int row_location, int column_location, int index, int* p);
void clearMatrix(int matrix[max][max], int label[max][max], int n);
void printScoreTable(int pointTable[max], char playerNames[max][20], int playerCounter[max], int players);

int main(){
	int i, j, n, matrix[max][max] = {{0}}, location[4][max] = {{0}}, label[max][max] = {{0}}, move[2][max], pointTable[max] = {0};
	int players, playerCounter[max] = {0}, currentPlayer, routeMatrix[max][max][2], dx[4] = {1,-1,0,0}, dy[4] = {0,0,-1,1}, undo, answer, mod, point=0, finish=0, *p = &point, *f = &finish;
    char fileName[20], playerNames[max][20];
	srand(time(0));
	do{
		printf("\nthe number of people to play the game: ");
		scanf("%d", &players);
	} while(players <= 0);
	for(i=0;i<players;i++){
		printf("\nname of the player %d: ", i+1);
		scanf(" %[^\n]s", playerNames[i]);
	}
	do{
		printf("\nif you want to use an existing matrix from files: 1\nif you want to use a random matrix: 2\nif you want to see the score " 
		"table: 3\nif you want to exit: 0\nchoice: ");
    	scanf("%d", &answer);
    	if(answer == 1 || answer == 2){
    		do{
				printf("\nwhich player wants to play (enter as a number -->(1, 2, 3.....)): ");
				scanf("%d", &currentPlayer);
			} while(currentPlayer>players);
			do{
				printf("\nManuel Mode: 1\nAutomatic Mode: 2\nReturn to the Main Menu: 3\nChoice: "); 
    			scanf("%d", &mod);
    			
				if(mod == 1){
					playerCounter[currentPlayer-1] += 1;
					printf("\nenter the matrix dimension (n): ");
    				scanf("%d", &n);
    				
       				if(answer == 1){
    					printf("\nenter the file name: ");
  						scanf("%s", fileName);
  						readFromFile(matrix, location, fileName);
  					}
  					else randomMatrix(matrix, location, n);
  					
					undo = manualGameFunction(matrix, move, label, location, n, p);
					
					if(controlFunction(matrix, location, label, n, p)){
						pointTable[currentPlayer-1] += ((answer * n) - undo); //random ise n'in iki katý kadar puan eksi undo deðilse n puan eksi undo
						printf("\n\nCongrats, You have successfully completed the game...\n\n");
					}
					else printf("\n\nUnfortunately you have not completed the game...\n\n");
					
					*p = 0; 
					clearMatrix(matrix, label, n);
				}
				if(mod == 2){
					playerCounter[currentPlayer-1] += 1;
					printf("\nenter the matrix dimension (n): ");
    				scanf("%d", &n);
    				
       				if(answer == 1){
    					printf("\nenter the file name: ");
  						scanf("%s", fileName);
  						readFromFile(matrix, location, fileName);
  					}
  					else randomMatrix(matrix, location, n);
  					
  					printf("\n\nGame Board...\n\n");
					drawBoard(matrix, n);
					
					for(i=0;i<4;i++){
						automatic(matrix, location, label, routeMatrix, n, location[0][0] + dx[i], location[1][0] + dy[i], 0, 0, p, f);
					}
					
					if(*f == 0) printf("\n\nThere is no solution....\n\n");
					else pointTable[currentPlayer-1] += ((answer * n)/2);
					
					*f = 0;
					clearMatrix(matrix, label, n);
				}
				
			} while(mod != 3);
		}
		else if(answer == 3) printScoreTable(pointTable, playerNames, playerCounter, players);
	} while(answer != 0);
	return 0;
}

/*Manuel oyun için bu fonksiyon çalýþýr. parametre olarak oyun tahtasý olan matrix'i, kullanýcýlarýn yaptýðý hamleleri tutan move matrisini,
  kontrol için gerekli label matrisini, oyun tahtasýndaki ilk deðerlerin koordinatlarýný tutan location matrisini tahta boyutunu ve yine kontrol
  için gerekli bir pointerý alýr.
 */
int manualGameFunction(int matrix[max][max], int move[2][max], int label[max][max], int location[4][max], int n, int* p){
	int i=0, j, k, row, column, answer, undo=0, temp, row_s, row_d, column_s, column_d, control; 
	
	do{
		printf("\n\nGame Board...\n\n");
		drawBoard(matrix, n);
		do{
			control=0;
			printf("\n\nrow of source: ");
			scanf("%d", &row_s);
			printf("\ncolumn of source: ");
			scanf("%d", &column_s);
			printf("\nrow of destination: ");
			scanf("%d", &row_d);
			printf("\ncolumn of destination: ");
			scanf("%d", &column_d);
			
			if((row_s != row_d) && (column_s != column_d)){
				printf("\nInvalid move...\n");
				control = 1;
			}
			else if(row_s < 0 || row_s >=n || row_d < 0 || row_d >=n){
				printf("\nInvalid move...\n");
				control = 1;
			}
			else if(column_s < 0 || column_s >=n || column_d < 0 || column_d >=n){
				printf("\nInvalid move...\n");
				control = 1;
			}
			else if(matrix[row_s][column_s] == 0){
				printf("\nInvalid move...\n");
				control = 1;
			}
		} while(control == 1);
		
		temp = matrix[row_s][column_s];
		if(row_s == row_d){
			row=row_s;
			move[0][i]=move[0][i+1]=row_s;
			move[1][i]=column_s;
			if(column_s > column_d){
				column = column_s - 1;
				while(matrix[row][column] == 0 && column>=column_d){
					matrix[row][column] = temp;
					column--;
				}
				move[1][i+1]=column+1;
			}
			else{
				column= column_s + 1;
				while(matrix[row][column] == 0 && column<=column_d){
					matrix[row][column] = temp;
					column++;
				}
				move[1][i+1]=column-1;
			}
		}
		else if(column_s == column_d){
			column=column_s;
			move[1][i]=move[1][i+1]=column_s;
			move[0][i]=row_s;
			if(row_s > row_d){
				row = row_s - 1;
				while(matrix[row][column] == 0 && row>=row_d){
					matrix[row][column] = temp;
					row--;
				}
				move[0][i+1]=row+1;
			}
			else{
				row = row_s + 1;
				while(matrix[row][column] == 0 && row<=row_d){
					matrix[row][column] = temp;
					row++;
				}
				move[0][i+1]=row-1;
			}
		}
		printf("\n\n%d. move...\n\n", i/2 + 1);
		drawBoard(matrix, n);
		
    	do{
			printf("\nenter 1 to make an undo otherwise enter 0: ");
			scanf("%d", &answer);
			if(answer == 1){
				i = undoFunction(matrix, move, n, i);
				undo++;
				printf("\n\n%d. move...\n\n", i/2 + 1);
				drawBoard(matrix, n);
			}
		} while(i >= 0 && answer == 1);
		i+=2;
		if(controlFunction(matrix, location, label, n, p)) answer = 0;
		else{
			printf("\nenter 1 to continue, enter 0 to end the game: ");
			scanf("%d", &answer);
		}
	} while(answer == 1);
	return undo;
}

int undoFunction(int matrix[max][max], int move[2][max], int n, int i ){
	int row, column, row_s, row_d, column_s, column_d; 
	
	row_s = move[0][i+1];
	column_s = move[1][i+1];
	row_d = move[0][i];
	column_d = move[1][i];
	
	if(row_s == row_d){
		row=row_s;
		if(column_s > column_d){
			for(column = column_s; column>column_d; column--){
				matrix[row][column] = 0;
			}
		}
		else{
			for(column = column_s; column<column_d; column++){
				matrix[row][column] = 0;
			}
		}
	}
	else if(column_s == column_d){
		column=column_s;
		if(row_s > row_d){
			row = row_s;
			for(row = row_s; row>row_d; row--){
				matrix[row][column] = 0;
			}
		}
		else{
			row = row_s;
			for(row = row_s; row<row_d; row++){
				matrix[row][column] = 0;
			}
		}
	}
	return i-2;
}

void automatic(int matrix[max][max], int location[4][max], int label[max][max], int routeMatrix[max][max][2], int n, int row_location, int column_location, int index, int k, int* p, int* f){
	int i, j, dx[4] = {1,-1,0,0}, dy[4] = {0,0,-1,1}, yedek_matrix[max][max]={{0}};
	if((*f) == 1) return;
	//drawBoard(matrix, n); //undolarý görmemek için yorum satýrýna alýn.
	if(row_location < 0 || row_location >= n || column_location < 0 || column_location >= n ) return;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			yedek_matrix[i][j] = matrix[i][j];
		}
	}
	if((row_location == location[2][index]) && (column_location == location[3][index])){
		if(index == n-1){
			*f = controlFunction(yedek_matrix, location, label, n, p);
			*p = 0;
			if((*f)){
				printf("\n\nThe Solution...\n\n");				
				drawBoard(yedek_matrix, n);
				return;
			}
		}
		if(index<n-1){
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					if(yedek_matrix[i][j] == index+1) yedek_matrix[i][j] = 0;
				}
			}
			yedek_matrix[location[0][index]][location[1][index]] = index+1;
			yedek_matrix[location[2][index]][location[3][index]] = index+1;
			for(i=0;i<k;i++){
				yedek_matrix[routeMatrix[index][i][0]][routeMatrix[index][i][1]] = index+1;
			}
			index++;
			for(i=0;i<4;i++){
				automatic(yedek_matrix, location, label, routeMatrix, n, location[0][index] + dx[i], location[1][index] + dy[i], index, 0, p, f);
			}
			return;
		}
		return;
	}
	if(yedek_matrix[row_location][column_location] != 0) return;
	yedek_matrix[row_location][column_location] = index+1;
	routeMatrix[index][k][0] = row_location;
	routeMatrix[index][k][1] = column_location;
	k++;
	for(i=0;i<4;i++){
		automatic(yedek_matrix, location, label, routeMatrix, n, row_location + dx[i], column_location + dy[i], index, k, p, f);
	}
}

int controlFunction(int matrix[max][max], int location[4][max], int label[max][max], int n, int* p){
	int i=0, j, control=0;
	
	while(control == 0 && i < n){
		j=0;
		while(control == 0 && j < n){
			if(matrix[i][j] == 0) control = 1;
			j++;
		}
		i++;
	}

	if(control == 0){
		for(i=0;i<n;i++){
			recursiveControl(matrix, location, label, n, location[0][i], location[1][i], i, p);
		}
		if(*p == 0) return 1;
		else{
			*p = 0;
			return 0;
		}
	}
	else return 0;
}

void recursiveControl(int matrix[max][max], int location[4][max], int label[max][max], int n, int row_location, int column_location, int index, int* p){
	int i, dx[4] = {1,-1,0,0}, dy[4] = {0,0,-1,1}, sum = 0;
	if(row_location < 0 || row_location >= n || column_location < 0 || column_location >= n ) return;
	if((label[row_location][column_location] == index+1) || (matrix[row_location][column_location] != index+1)) return; //labelda zaten etiketlenmiþse yani önceki çaðrýlarda kontrol etmiþsek veya matrix te istediðimiz sayý deðilse return oluyor
	
	if((row_location == location[0][index]) && (column_location == location[1][index])){
		for(i=0;i<4;i++){
			if(matrix[row_location+dx[i]][column_location+dy[i]] == index+1) sum++;
		}
		if(sum < 1){
			*p = 1;
			return;
		}
	}
	else if((row_location == location[2][index]) && (column_location == location[3][index])){
		for(i=0;i<4;i++){
			if(matrix[row_location+dx[i]][column_location+dy[i]] == index+1) sum++;
		}
		if(sum < 1){
			*p = 1;
			return;
		}
	}
	else{
		for(i=0;i<4;i++){
			if(matrix[row_location+dx[i]][column_location+dy[i]] == index+1) sum++;
		}
		if(sum < 2){
			*p = 1;
			return;
		}
	}
	label[row_location][column_location] = index+1;
	for(i=0;i<4;i++){
		recursiveControl(matrix, location, label, n, row_location + dx[i], column_location + dy[i], index, p);
	}
}

void randomMatrix(int matrix[max][max], int location[4][max], int n){
	int i, j, row, column, answer;
	do{
		clearMatrix(matrix, location, n);
		for(i=0;i<n;i++){
		 	j=0;
  			while(j<2){
    			row = rand()%(n);
   				column = rand()%(n);
    			if(matrix[row][column] == 0){
    				location[2*j][i] = row;
   			 		location[2*j+1][i] = column;
					matrix[row][column] = i+1;
    				j++;
				}
			}
		}
		printf("\n\nThe Game Board you are going to play with...\n\n");
		drawBoard(matrix, n);
		printf("\n\nenter 1 if you want to play with this board, enter 0 to make a new random board: ");
		scanf("%d", &answer);
	} while(answer == 0);
}

void clearMatrix(int matrix[max][max], int label[max][max], int n){
	int i, j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			matrix[i][j] = 0;
			label[i][j] = 0;
		}
	}
}

void printScoreTable(int pointTable[max], char playerNames[max][20], int playerCounter[max], int players){
	int i;
	printf("\n\nScore Table...\n\n");
	for(i=0;i<players;i++){
		if(!pointTable[i]) printf("\n\n%s: %d\n\n", playerNames[i] , 0);
		else printf("\n\n%s: %d\n\n", playerNames[i], pointTable[i] / playerCounter[i]);
	}
}

void readFromFile(int matrix[max][max], int location[4][max], char *fileName){
	int i,j,k=0, temp;
	FILE *data = fopen(fileName,"r");
	if(!data){
        printf("The file couldn't be opened!");
		return;
    }
    while(!feof(data)){
        fscanf(data,"%d %d %d\n",&i,&j,&temp);
        matrix[i][j]=temp;
		location[2*(k%2)][temp-1] = i;
		location[2*(k%2)+1][temp-1] = j;
		k++;
    }
  	fclose(data);
}

void drawBoard(int matrix[max][max], int n) {
    int i, j, k;
    printf("\n   ");
    for (k = 0; k < n; k++)
        printf("  %d    ", k);
    for (i = 0; i < n; i++) {
        printf("\n   ");
        for (k = 0; k < n; k++)
            printf("-------");
        printf("\n%d |", i);

        for (j = 0; j < n; j++) {
            if (matrix[i][j] != 0)
                printf("  %d   |", matrix[i][j]);
            else
                printf("      |", matrix[i][j]);
        }
    }
    printf("\n   ");
    for (k = 0; k < n; k++)
        printf("-------");
}
