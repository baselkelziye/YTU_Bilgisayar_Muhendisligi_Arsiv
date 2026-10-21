#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

typedef struct player{
	char username[20];
	char name[20];
	char password[20];
}PLAYER;

void menu();
void drawBoard(char** matrix, int row, int column, int* x);
char** readBoardFromFile(int row, int column, int* x);
int manuelMod(char** matrix, int row, int column, int* x);
int autoMod(char** matrix, int row, int column, int* x);
int findPath(char** matrix, int row, int column, int i, int j, int** label);
void autoModHelper(char** matrix, int row, int column, int* x, int* particleCount, int** reserveMatrix);
void freeBoard(char** board, int row);
void clearConsole();
void readPointTable(int* points, char** usernames);
void printPointTable(int* points, char** usernames);
void updatePointTable(int* points, char** usernames, int point, char* username);
void writePointTable(int* points, char** usernames);

int main(){
	menu();
	return 0;
}

void menu(){
	int i, j, row, column, answer, signedIn = 0, result;
	char **board;
	int *x = (int*) malloc(2 * sizeof(int));
	PLAYER player;
	int* points = (int*) malloc(6 * sizeof(int));
	char** usernames = (char**) calloc(6, sizeof(char*));
	
	for(i=0;i<6;i++){
		usernames[i] = (char*) calloc(20, sizeof(char));
		points[i] = -1;
	}
	
	readPointTable(points, usernames);
	
	do{
		printf("Quit: 0\n");
		if(!signedIn) {
            printf("Sign In: 1\n");
            printf("Sign Up: 2\n");
        }else {
            printf("Manual Game: 3\n");
            printf("Automatic Game: 4\n");
            printf("Point Table: 5\n");
            printf("Sign Out: 6\n");
        }
        
        printf("\nanswer: ");
        scanf("%d", &answer);
        
        switch(answer){
        	case 0:
        		printf("Goodbye...\n");
        		sleep(2);
        		break;
        	case 1:
        		if(signedIn) printf("You already signed in...\n");
				else signedIn = signIn(&player);
				break;
			case 2:
				if(signedIn) printf("You did not sign out...\n");
				else signUp();
				break;
			case 3:
				if(signedIn){
					printf("\nnumber of rows: ");
					scanf("%d", &row);
					printf("\nnumber of columns: ");
					scanf("%d", &column);
					board = readBoardFromFile(row, column, x);
					result = manuelMod(board, row, column, x);
					freeBoard(board, row);
					printf("\n\n%s made %d particles...\n\n", player.username, result);
					updatePointTable(points, usernames, result, player.username);
					sleep(3);
				}
				else{
					printf("you should sign in first...\n");
				}
				break;
			case 4:
				if(signedIn){
					printf("\nnumber of rows: ");
					scanf("%d", &row);
					printf("\nnumber of columns: ");
					scanf("%d", &column);
					board = readBoardFromFile(row, column, x);
					result = autoMod(board, row, column, x);
					freeBoard(board, row);
					printf("\n\ncomputer made %d particles...\n\n", result);
					updatePointTable(points, usernames, result, "computer");
					sleep(3);
				}
				else{
					printf("you should sign in first...\n");
				}
				break;
			case 5:
				printPointTable(points, usernames);
				sleep(4);
				break;
			case 6:
				signedIn = 0;
				break;
			default:
				printf("\nInvalid choice. Please enter again...\n");				
		}
		clearConsole();
	} while(answer);
	
	writePointTable(points, usernames);
	free(x);
}

int manuelMod(char** matrix, int row, int column, int* x){
	int* particleCount = (int*) calloc(4, sizeof(int)); //0 - P, 1 - E, 2 - p, 3 - e
	char move;
	int ctrl, result;
	clock_t start;
	start = clock();
	double timeSpent = 0.0;
	do{
		clearConsole();
	   	drawBoard(matrix, row, column, x);
	   	printf("\nCollected Particles...\n");
		printf("\nP+ -> %d\ne- -> %d\nP- -> %d\ne+ -> %d\n", particleCount[0], particleCount[1], particleCount[2], particleCount[3]); 
		
	   	ctrl = 0;
	   	
	   	do{
	   		printf("\nif you want to exit then click esc otherwise use arrow keys to move...");
		   	move = getch();
		   	if(move != 27){
				move = getch();
				switch(move){
					case 72:
						if(x[0] >= 1 && matrix[x[0] - 1][x[1]] != '1') x[0]--;
						break;
					case 75:
						if(x[1] >= 1 && matrix[x[0]][x[1] - 1] != '1') x[1]--;
						break;
					case 77:
						if(x[1] < column - 1 && matrix[x[0]][x[1] + 1] != '1') x[1]++;
						break;
					case 80:
						if(x[0] < row - 1 && matrix[x[0] + 1][x[1]] != '1') x[0]++;
						break;
					default:
						printf("\nInvalid Move...");
						ctrl = 1;
				}
			}
			timeSpent = ((double)(clock() - start)) / CLOCKS_PER_SEC;
		} while(ctrl);
		
		ctrl = 0;
		
		if(move != 27){
			if(matrix[x[0]][x[1]] == 'C'){
				printf("\n-----------------------------------\n");
				printf("\nyou came to the exit door, game is finished...");
				ctrl = 1;
			}
			if(matrix[x[0]][x[1]] == 'K'){
				printf("\n-----------------------------------\n");
				printf("\nyou fell into a blackhole, game over...");
				ctrl = 2;
			}
			if(matrix[x[0]][x[1]] == 'P'){
				matrix[x[0]][x[1]] = '0';
				particleCount[0]++;
			}
			if(matrix[x[0]][x[1]] == 'E'){
				matrix[x[0]][x[1]] = '0';
				particleCount[1]++;
			}
			if(matrix[x[0]][x[1]] == 'p'){
				matrix[x[0]][x[1]] = '0';
				particleCount[2]++;
			}
			if(matrix[x[0]][x[1]] == 'e'){
				matrix[x[0]][x[1]] = '0';
				particleCount[3]++;
			}
		}
	} while(!ctrl && move != 27 && timeSpent <= 30.00000);
	
	if(move == 27 || ctrl == 2) return 0;
	if(ctrl == 0 && timeSpent > 30.00000){
		printf("\n-----------------------------------\n");
		printf("\nmaximum amount of time has been reached...");
		sleep(2);
		return 0;
	}
	
	result = findMin(particleCount[2] - particleCount[0], particleCount[3] - particleCount[1]);
	
	return (result < 0) ? 0 : result;
}

//findPath yardýmýyla path bulup helper yardýmýyla da bu path'i dolaþýr. findPath 0 döndürürse o map'in çözümü yok demektir.

int autoMod(char** matrix, int row, int column, int* x){
	int i, j, ctrl = 0, result;
	int* particleCount = (int*) calloc(4, sizeof(int)); //0 - P, 1 - E, 2 - p, 3 - e
	int** reserveMatrix = (int**) calloc(row, sizeof(int*));
	for(i=0;i<row;i++) reserveMatrix[i] = (int*) calloc(column, sizeof(int));
	
	if(!findPath(matrix, row, column, x[0], x[1], reserveMatrix)){
		printf("\nThere is no solution for this map...");
		return 0;
	}
	
	autoModHelper(matrix, row, column, x, particleCount, reserveMatrix);
	
	for(i=0;i<row;i++) free(reserveMatrix[i]);
	free(reserveMatrix);
	
	result = findMin(particleCount[2] - particleCount[0], particleCount[3] - particleCount[1]);
	
	free(particleCount);
	
	return (result < 0) ? 0 : result;
}

//findPath ile bulunan path'i gezerek bu path'teki parçacýklarý toplar ve adým adým ekrana yazdýrýr.
 
void autoModHelper(char** matrix, int row, int column, int* x, int* particleCount, int** reserveMatrix){
	do{
		clearConsole();
	   	drawBoard(matrix, row, column, x);
	   	printf("\nCollected Particles...\n");
		printf("\nP+ -> %d\ne- -> %d\nP- -> %d\ne+ -> %d\n", particleCount[0], particleCount[1], particleCount[2], particleCount[3]);
		sleep(1);
		
		if(x[0] >= 1 && reserveMatrix[x[0] - 1][x[1]]){
			x[0]--;
			reserveMatrix[x[0]][x[1]] = 0;
		} 
		else if(x[1] >= 1 && reserveMatrix[x[0]][x[1] - 1]){ 
			x[1]--;
			reserveMatrix[x[0]][x[1]] = 0;
		}
		else if(x[1] < column - 1 && reserveMatrix[x[0]][x[1] + 1]){
			x[1]++;
			reserveMatrix[x[0]][x[1]] = 0;
		} 
		else if(x[0] < row -1 && reserveMatrix[x[0] + 1][x[1]]){
			x[0]++;
			reserveMatrix[x[0]][x[1]] = 0;
		}
		
		if(matrix[x[0]][x[1]] == 'P'){
			matrix[x[0]][x[1]] = '0';
			particleCount[0]++;
		}
		if(matrix[x[0]][x[1]] == 'E'){
			matrix[x[0]][x[1]] = '0';
			particleCount[1]++;
		}
		if(matrix[x[0]][x[1]] == 'p'){
			matrix[x[0]][x[1]] = '0';
			particleCount[2]++;
		}
		if(matrix[x[0]][x[1]] == 'e'){
			matrix[x[0]][x[1]] = '0';
			particleCount[3]++;
		}
	} while(matrix[x[0]][x[1]] != 'C');
}

//findPath'te kullanmak icin. Zaten ziyaret ettiðimiz bir hücre ise veya map'teki bir duvar veya karedelikse 0 döndürür.

int isValid(char** matrix, int** reserveMatrix, int row, int col, int i, int j) {
    return (i >= 0 && i < row && j >= 0 && j < col && matrix[i][j] != 'K' && matrix[i][j] != '1' && !reserveMatrix[i][j]);
}

//otomatik mod için dfs yardýmýyla giriþten çýkýþa bir path bulur.

int findPath(char** matrix, int row, int column, int i, int j, int** reserveMatrix){
	if(matrix[i][j] == 'C'){
		reserveMatrix[i][j] = 1;
		return 1;
	}
	
    reserveMatrix[i][j] = 1;
    
	if(isValid(matrix, reserveMatrix, row, column, i-1, j) && findPath(matrix, row, column, i-1, j, reserveMatrix)) return 1;
	if(isValid(matrix, reserveMatrix, row, column, i, j-1) && findPath(matrix, row, column, i, j-1, reserveMatrix)) return 1;
	if(isValid(matrix, reserveMatrix, row, column, i, j+1) && findPath(matrix, row, column, i, j+1, reserveMatrix)) return 1;
	if(isValid(matrix, reserveMatrix, row, column, i+1, j) && findPath(matrix, row, column, i+1, j, reserveMatrix)) return 1;
	
	reserveMatrix[i][j] = 0;
	
	return 0;
}

int findMin(int a, int b){
	return (a > b) ? b : a;
}

// signIn ve signUp fonksiyonlarýnda bu fonksiyonu kullanýyorum. verilen parametreye sahip player'i binary dosyada arýyorum. bulamazsa 0, bulursa 1,
// username ayný password farklýysa 2 döner.

int isPlayerRegistered(char* username, char* password){
	FILE *f = fopen("players.dat", "rb");
	
	if(f != NULL){
		PLAYER player;
		while(fread(&player, sizeof(PLAYER), 1, f) == 1){
			if(strcmp(player.username, username) == 0 && strcmp(player.password, password) == 0){
				fclose(f);
				return 1;
			}
			else if(strcmp(player.username, username) == 0 && strcmp(player.password, password) != 0){
				fclose(f);
				return 2;
			}
		}
		fclose(f);
	}
	else printf("\nFile couldnt be opened...\n");
	return 0;
}

int signIn(PLAYER* player){
	char username[20], name[20], password[20];
	int result = 0, i=0;
	
	printf("\nusername: ");
	scanf("%s", username);
	printf("\npassword: ");
	scanf("%s", password);
	
	do{
		result = isPlayerRegistered(username, password);
		if(result == 0){
			printf("\nThere is not a registered player with that username...\n");
			printf("\nusername: ");
			scanf("%s", username);
			printf("\npassword: ");
			scanf("%s", password);
		}
		else if(result == 2){
			printf("\nwrong password, enter again...");
			printf("\npassword: ");
			scanf("%s", password);
		}
	} while(result != 1 && ++i < 5);
	
	if(result == 1){
		strcpy(player -> username, username);
		strcpy(player -> password, password);
		printf("\nSuccessfully signed in...\n\nWelcome %s\n\n\n", player -> username);
		sleep(3);
		return 1;
	}
	if(i == 5 && result != 1) printf("\nmaximum number of attempts has been reached...\n");
	return 0;
}

int signUp(){
	char username[20], name[20], password[20], quit = 0;
	int result;
		
	do{
		printf("\nusername: ");
		scanf("%s", username);
		printf("\nname: ");
		fflush(stdin);
		scanf("%[^\n]s", name);
		printf("\npassword: ");
		scanf("%s", password);
		result = isPlayerRegistered(username, password);
		if(result) printf("\nthere is a player with the same username...\n");
	} while(result);
	
	if(!result){
		PLAYER player;
		strcpy(player.username, username);
		strcpy(player.name, name);
		strcpy(player.password, password);
		FILE *f = fopen("players.dat", "ab");
		if(f != NULL){
			fwrite(&player, sizeof(PLAYER), 1, f);
			fclose(f);
			return 1;
		}
		else printf("\nFile couldnt be opened...\n");
	}
	return 0;
}

void readPointTable(int* points, char** usernames){
	int i = 0;
	FILE *f = fopen("points.txt", "r");
	if(f != NULL){
		while(!feof(f)){
			fscanf(f, "%s %d", usernames[i], &points[i]);
			i++;
		}
		fclose(f);
	}
	else printf("\nFile couldnt be opened...\n");
}

//points dizisini oluþtururken -1'lediðim için yezdýrýken -1'e kadar olanlarý yazdýrýyorum.

void printPointTable(int* points, char** usernames){
	int i = 0;
	printf("\n...Point Table...\n\n     username\tpoint\n\n");
	while(i < 5 && points[i] != -1){
		printf("%d -> %s\t%d\n", i+1, usernames[i], points[i]);
		i++;
	}
}

//Burada verilen point'i points dizisine basit bir insertion iþlemi yapýyorum. points dizisini 6 elemanlý oluþturma sebebim buydu.

void updatePointTable(int* points, char** usernames, int point, char* username){
	int i = 4;
	
	while(i >= 0 && points[i] < point){
		points[i+1] = points[i];
		strcpy(usernames[i+1], usernames[i]);
		i--;
	}
	points[i+1] = point;
	strcpy(usernames[i+1], username);
}

void writePointTable(int* points, char** usernames){
	FILE *f = fopen("points.txt", "w");
	int i = 0;
	if(f != NULL){
		while(i < 4 && points[i] != -1){
			fprintf(f, "%s %d\n", usernames[i], points[i]);
			i++;
		}
		if(i < 5 && points[i] != -1) fprintf(f, "%s %d", usernames[i], points[i]);
		fclose(f);
	}
	else printf("\nFile couldnt be opened...\n");
}

void drawBoard(char** matrix, int row, int column, int* x) {
    int i, j, k;
    printf("\n\n   ");
    for (k = 0; k < column; k++)
        printf("  %d    ", k);
    for (i = 0; i < row; i++) {
        printf("\n   ");
        for (k = 0; k < column; k++)
            printf("-------");
        printf("\n%d |", i);

        for (j = 0; j < column; j++) {
        	if(x[0] == i && x[1] == j) printf("  X   |");
            else printf("  %c   |", matrix[i][j]);
        }
    }
    printf("\n   ");
    for (k = 0; k < column; k++)
        printf("-------");
}

void freeBoard(char** board, int row){
	int i;
	for(i=0;i<row;i++) free(board[i]);
	free(board);
}

void clearConsole(){
		// Windows
		#ifdef _WIN32
        	system("cls");
	    // Unix/Linux/macOS
	    #else
	        system("clear");
	    #endif
}

char** readBoardFromFile(int row, int column, int* x) {
    int i, j, temp;
	char fileName[20];
	FILE* data;
	
	do{
		printf("\nenter the board name: ");
		scanf("%s", fileName);
		data = fopen(fileName, "r");
		if(!data) printf("\nthere is not a file with that name. Enter again...");
	} while(!data);
    
	char** board = (char**) malloc(row * sizeof(char*));
	for(i=0;i<row;i++) board[i] = (char*) malloc(column * sizeof(char));
	
    while (!feof(data)) {
        fscanf(data, "%d %d %c\n", &i, &j, &temp);
        board[i][j] = temp;
        if(temp == 'G'){
        	x[0] = i;
        	x[1] = j;
		}
    }
    fclose(data);
    return board;
}
