#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define rows 11 // maze = 31, maze2 =  31, maze3 = 11
#define cols 15 // maze = 64, maze2 =  43, maze3 = 15

int** visited;
int score=0;
int deadEnd=0;

enum terrain {
	empty,
	wall,
	goal,
    fruit,
	crumb
};


void addPath(char maze[rows][cols], int , int, int);
void print(char maze[rows][cols]);
void initialize(char maze[rows][cols]);
void allocVisited();
void initVisited(char maze[rows][cols]);
int dfs(char maze[rows][cols], int row, int col);
void delay(int);


int main() {
//********** Maze INIT ********** //
    int i=0, j;
    int start_row, start_col, state=0;
    char buffer[255]; /* not ISO 90 compatible */
    char maze[rows][cols];
    initialize(maze);
    FILE *fp = fopen("maze3.txt", "r");
    while (fgets(buffer, 128, fp)){
            //printf("%d", buffer[i]);
        for(j=0; j<cols; j++){
        
            if(buffer[j] == ' '){ // ASCII of ' ' 32
                state = 0;
                addPath(maze, i, j, state);
            }
            else if(buffer[j] == 'b'){ // ASCII of 'b' 98
                state = 1;
                addPath(maze, i, j, state);
                start_row = i;
                start_col = j;
            }
            else if(buffer[j] == 'c'){ // 'c' 99
                state = 2;
                addPath(maze, i, j, state);
            }
            else if(buffer[j] == 'F'){ // 'c' 99
                state = 3;
                addPath(maze, i, j, state);
            }
        }
    i++;
    }
    fclose(fp);
//********** END MAZE READ **********//


// ********** main ********** //
    initVisited(maze);
    print(maze);
    if (!dfs(maze, start_row, start_col)) {
		printf("No path to the exit could be found.\n");
    } 
    else {
        system("clear");
	    print(maze);
    }
    return 0;
// ********** ****** ********** //
}

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

void addPath(char maze[rows][cols], int i, int j, int state){
    if(state == 0){
        maze[i][j] = '1';
    }
    else if(state == 1){
        maze[i][j] = 'b';
    }
    else if(state == 3){
        maze[i][j] = 'F';
    }
    else
        maze[i][j] = 'c';
}

void print(char maze[rows][cols]){
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
        printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n*****  SCORE: %d  *****\n", score);
}

void initialize(char maze[rows][cols]){
    int i, j;
    for(i=0; i<rows; i++)
        for(j=0; j<cols; j++)
            maze[i][j] = '0';
}

void allocVisited()
{
	visited = malloc(rows * sizeof(int*));
	int i;
	for (i = 0; i < rows; ++i){
		visited[i] = malloc(cols * sizeof(int*));
	}
}

void initVisited(char maze[rows][cols])
{
	allocVisited();

	int i, j;
	for (i = 0; i < rows; ++i) {
		for (j = 0; j < cols; ++j) {
			if (maze[i][j] == '0') {
				visited[i][j] = wall;
			} else if (maze[i][j] == 'c') {
				visited[i][j] = goal;
			} else if(maze[i][j] == 'F'){
                visited[i][j] = fruit;
            } else {
				visited[i][j] = empty;
			}
		}
	}
}	


int dfs(char maze[rows][cols], int row, int col){
	int* current = &visited[row][col];

	if (*current == goal) {
		return 1;
	}

    if(*current == fruit){
        score += 10;
    }


	if (*current == empty || *current == fruit) {
		*current = crumb;
    
        if (maze[row][col] != 'b' && *current == crumb) {
				system("clear");
	            print(maze);
                delay(100);
                maze[row][col] = '.'; // It's better than '*' to keep up with terminal visualizaliton
                if(deadEnd==1){
                    score -=5;
                    deadEnd = 0;
                } // debug edip stack durumunu takip ettim, ilk donmeye basladigi
                  // an degil burada skoru cikarinca sorun cozuluyor (yeni path)
        }

		if (dfs(maze, row, col - 1)){  // WEST (LEFT)
			*current = crumb;
			return 1;
		} 
		if (dfs(maze, row + 1, col)){  // SOUTH (DOWN)
			*current = crumb;
			return 1;
		} 
		if (dfs(maze, row, col + 1)){  // EAST (RIGHT)
			*current = crumb;
			return 1;		
		}
		if (dfs(maze, row - 1, col)){  // NORTH (UP)
			*current = crumb;
			return 1;
		}

        if (visited[row][col] != empty && *current == crumb) { // cleaning path of deadend
			system("clear");                                   
	        print(maze);
            delay(100);
            maze[row][col] = '1';
            deadEnd = 1;
	    }
	}
    
    return 0;
}