#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#include <conio.h>

#define ROW 31
#define COL 43
int k = 0;

int main()
{
	FILE *maze = fopen("maze.txt", "r");
	char c;
	int i, j;

	char symPlus = '+';
	char symMinus = '-';
	char symPipe = '|';
	char symSpace = ' ';
	char symB = 'b';
	char symC = 'c';

	int startI;
	int startJ;

	int exitI;
	int exitJ;

	int currI;
	int currJ;

	int mazeMat[ROW][COL];

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL + 1; j++)
		{

			c = fgetc(maze);
			printf("%c", c);

			if (c == symPlus || c == symMinus || c == symPipe)
			{
				mazeMat[i][j] = 0;
			}
			else if (c == symSpace)
			{
				mazeMat[i][j] = 1;
			}

			else if (c == symB)
			{
				startI = i;
				startJ = j;
				mazeMat[i][j] = 1;
			}
			else if (c == symC)
			{
				exitI = i;
				exitJ = j;
				mazeMat[i][j] = 1;
			}
		}
	}
	printf("\n\n");
	currI = startI;
	currJ = startJ;
	printf("Press any key to start maze solver.");
	getchar();
	dfs(mazeMat, currI, currJ, exitI, exitJ);
	getchar();
	return 0;
}
void changeColor(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (color == 0)
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	}
	else if (color == 1)
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	}
	else if (color == 2)
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
	}
}

void printMaze(int mazeMat[ROW][COL])
{
	int i, j;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	saved_attributes = consoleInfo.wAttributes;

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (mazeMat[i][j] == 0)
			{
				printf("%c", 987);
			}
			else if (mazeMat[i][j] == 2)
			{
				changeColor(1);
				printf("%c", 987);
				SetConsoleTextAttribute(hConsole, saved_attributes);
			}
			else if (mazeMat[i][j] == 3)
			{
				changeColor(0);
				printf("%c", 987);
				SetConsoleTextAttribute(hConsole, saved_attributes);
			}
			else
			{
				printf("%c", ' ');
			}
		}
		printf("\n");
	}
}

int dfs(int mazeMat[ROW][COL], int currI, int currJ, int exitI, int exitJ)
{
	//	system("cls");
	//	printMaze(mazeMat);
	//	usleep(1000);
	printf("%d\n", k++);
	printf("\n\n");
	if (currI == exitI && currJ == exitJ)
	{
		printMaze(mazeMat);
		printf("\nReached to exit!\n");
		return 1;
	}
	if (mazeMat[currI][currJ] == 1)
	{
		printf("%d\n", k);
		k++;
		printf("\n\n");
		mazeMat[currI][currJ] = 2;
		if (dfs(mazeMat, currI - 1, currJ, exitI, exitJ))
		{ // north
			return 1;
		}
		if (dfs(mazeMat, currI, currJ - 1, exitI, exitJ))
		{ // west
			return 1;
		}
		if (dfs(mazeMat, currI + 1, currJ, exitI, exitJ))
		{ // south
			return 1;
		}
		if (dfs(mazeMat, currI, currJ + 1, exitI, exitJ))
		{ // east
			return 1;
		}
		mazeMat[currI][currJ] = 3;
	}
	return 0;
}
