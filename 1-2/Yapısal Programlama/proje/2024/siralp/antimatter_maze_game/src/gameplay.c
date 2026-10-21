#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <math.h>
#include <time.h>

#include "gameplay.h"
#include "gamefield.h"

int displayMenu(){
	auto void printHeader();
	auto void printChoices();
	auto int printLobby();
	struct SELECTION
	{
		unsigned int currentSelection : 2;
	};
	struct INNER_SELECTION
	{
		unsigned int autoMod : 1;
		unsigned int difficulty : 1;
		char fileName[20];
	};

	struct INNER_SELECTION settings = {0};
	struct SELECTION cursor = {0};

	strcpy(settings.fileName, "field1.txt");

	char selector[4][80] = {
		"\t      > Choose Map <\t\tGameplay Mode\t\tDifficulty\t\tSTART GAME\t\t",
		"\t\tChoose Map\t      > Gameplay Mode <\t\tDifficulty\t\tSTART GAME\t\t",
		"\t\tChoose Map\t\tGameplay Mode\t      > Difficulty <\t\tSTART GAME\t\t",
		"\t\tChoose Map\t\tGameplay Mode\t\tDifficulty\t      > START GAME <\t\t"};

	FIELD *field = NULL;
	int output = printLobby();
	while (output == 0 || output == 1)
	{
		if (output == 1)
		{
			char *fileName = (char *)malloc(sizeof(char) * 25);
			if (!printMapsFolder(fileName))
				printf("\n\t\t! Couldn't read the folder/files !");
			strcat(fileName, ".txt");
			field = readGameField(fileName);
			if (field != NULL)
			{
				strcpy(settings.fileName, fileName);
			}
			output = printLobby();
			free(fileName);
		}
		else
			output = printLobby();
	}
	if (output == -1)
	{
		return settings.autoMod ? _A_GAME_(field, settings.difficulty) : _M_GAME_(field, settings.difficulty);
	}
	else
		return -1; // back to main

	// -------------Function Decleration -------------------//
	int printLobby()
	{

		printHeader();
		printf("%s", selector[cursor.currentSelection]);
		printChoices();
		int c;
		while ((c = getch()) != ENTER_KEY)
		{

			if (c == LEFT_ARROW)
				cursor.currentSelection--;
			if (c == RIGHT_ARROW)
				cursor.currentSelection++;

			printf("\33[2K\r");
			printf("\033[A");
			printf("\33[2K\r");
			printf("%s", selector[cursor.currentSelection]);
			printChoices();
		}
		switch (cursor.currentSelection)
		{
		case 0:
		{
			printf("\nEXCEPTION : PLEASE CHOSE A MAP FIRST !");
			return 1;
		}
		case 1:
		{
			settings.autoMod++;
			return 0;
		}
		case 2:
		{
			settings.difficulty++;
			return 0;
		}
		case 3:
		{
			printf("\nEXCEPTION : PLEASE CHOSE A MAP FIRST !");
			return -1;
		}
		}
	}

	void printHeader()
	{
		system("cls");
		printf("\n\t\t\t\t# GAMEPLAY #\n\n");
	}
	void printChoices()
	{
		printf("\n\t\t# %s #\t\t # %s #\t\t# %s #\t\t\t\t",
			   settings.fileName,
			   settings.autoMod ? "AUTO" : "MANUEL",
			   settings.difficulty ? "HARD" : "EASY");
	}
}

int _A_GAME_(FIELD *field, _Bool isHard)
{
	char items[25] = {0};
	int itemCount = 0;
	int i, nextSquare;
	struct T
	{
		unsigned int head : 2;
		unsigned int leftHandSide : 2;
	};
	int moveCounter = isHard ? field->fieldSize[0] * field->fieldSize[1] : 1.5 * field->fieldSize[0] * field->fieldSize[1];
	auto struct T *player;
	auto int directions[4] = {UP_ARROW, RIGHT_ARROW, DOWN_ARROW, LEFT_ARROW};
	srand(time(NULL));
	int _random = rand() % 4;
	player->head = _random;
	player->leftHandSide = player->head - 1;

	// ------------------------------------------------------------------------//
	while (1)
	{
		if (moveCounter <= 0)
		{
			system("cls");
			displayGameField(field, moveCounter);
			printf("\n\n\t\tYou are out of your moves !\n\n\t\tReactors in your pocket harming you, You lost %d points\n", 2 * itemCount);
			for (i = 0; i < 6; i++)
			{
				printf("\t\tWill be sent to lobby in %d seconds..", 6 - i);
				Sleep(1000);
				printf("\33[2K\r");
			}
			return (-2) * itemCount;
		}
		if (nextSquare == END)
		{
			printf("\n\n\tGAME ENDED !!");
			Sleep(1000);
			int point = calcPoints(items, itemCount);
			return point;
		}
		else
		{
			system("cls");
			displayGameField(field, moveCounter);
			printf("\n\t\t$$ AUTO MOD $$  --> 'Q' to quit\n\n\t\tCollected Items: ");
			printf("\n\nDIRECTIONS - head->%s", player->head == 0 ? "UP" : player->head == 1 ? "RIGHT"
																	   : player->head == 2	 ? "DOWN"
																							 : "LEFT");
			Sleep(250);
			for (i = 0; i < itemCount; i++)
			{
				printf("%c ", items[i]);
			}

			if ((nextSquare = move(field, 1, directions[player->leftHandSide], items, &itemCount)) >= 1)
			{ // moved to left-hand-side
				player->leftHandSide--;
				player->head--;
			}
			else if ((nextSquare = move(field, 1, directions[player->head], items, &itemCount)) >= 1)
				; // kept going straight
			else
			{
				player->leftHandSide++;
				player->head++;
			} // couldn't do either so turned right
			moveCounter--;
		}
	}
}

int _M_GAME_(FIELD *field, _Bool isHard)
{
	char items[25] = {0};
	int itemCount = 0;
	int nextSquare;
	int i;
	FIELD *copyField = (FIELD *)malloc(sizeof(FIELD));
	copyField = field;
	int moveCounter = isHard ? field->fieldSize[0] * field->fieldSize[1] / 6 + 5 : field->fieldSize[0] * field->fieldSize[1] / 4 + 5;
	while (1)
	{
		system("cls");
		displayGameField(field, moveCounter);

		printf("\n\t\tControls : Left-Up-Right-Down Arrows  &  'Q' to quit  -  'R' to restart\n\n\t\tCollected Items: ");
		int i;
		for (i = 0; i < itemCount; i++)
		{
			printf("%c ", items[i]);
		}

		nextSquare = move(field, 0, 0, items, &itemCount);
		if (nextSquare >= 1 && nextSquare <= ANTIPROTON)
			moveCounter--;

		if (nextSquare == END)
		{
			int p = calcPoints(items, itemCount);
			if (isHard && p > 0)
				p = 1.5 * p;
			printf("\n\t\t< You %s %d points >\n\n", p >= 0 ? "Earned" : "Lost", (int)fabs(p));
			for (i = 0; i < 10; i++)
			{
				printf("\t\tWill be sent to lobby in %d seconds..", 10 - i);
				Sleep(995);
				printf("\33[2K\r");
			}
			return p;
		}
		if (nextSquare == BLACKHOLE)
		{
			printf("\n\n\t\t YOU HAVE FALLEN INTO A BLACKHOLE ! GAME ENDED! -15 Points.");
			Sleep(5000);
			return -15;
		}

		if (nextSquare == Q_KEY)
		{
			printf("\n\t\tQuitting Game  -  You Will Be Punished by 20 Points");
			Sleep(3000);
			return -20;
		}
		if (nextSquare == R_KEY)
		{
			printf("\n\tRestarting Game -  You Will Be Punished 5 Points");
			Sleep(3000);
			return _M_GAME_(copyField, isHard) - 5;
		}

		if (moveCounter <= 0)
		{
			system("cls");
			displayGameField(field, moveCounter);
			printf("\n\n\t\t You are out of your moves ! Reactors in your pocket harming you, You lost %d points\n", 2 * itemCount);
			for (i = 0; i < 6; i++)
			{
				printf("\t\tWill be sent to lobby in %d seconds..", 6 - i);
				Sleep(1000);
				printf("\33[2K\r");
			}
			return (-2) * itemCount;
		}
	}
}

int move(FIELD *field, _Bool isAuto, int dir, char *bag, int *itemCount)
{
	auto int moveable(char);
	int canMove, _Move;

	if (!isAuto)
		_Move = getch();
	else
		_Move = dir;

	switch (_Move)
	{
	case RIGHT_ARROW:
		if (field->curLocation[1] == field->fieldSize[1] - 1)
			return 0;
		else
			canMove = moveable(field->gameField[field->curLocation[0]][field->curLocation[1] + 1]);
		if (isAuto == 1 && canMove == BLACKHOLE)
			canMove = 0; // for auto mod
		if (canMove >= 1)
			field->curLocation[1]++;
		return canMove;
	case LEFT_ARROW:
		if (field->curLocation[1] == 0)
			canMove = 0;
		else
			canMove = moveable(field->gameField[field->curLocation[0]][field->curLocation[1] - 1]);
		if (isAuto && canMove == BLACKHOLE)
			canMove = 0; // for auto mod
		if (canMove >= 1)
			field->curLocation[1]--;
		return canMove;
	case UP_ARROW:
		if (field->curLocation[0] == 0)
			canMove = 0;
		else
			canMove = moveable(field->gameField[field->curLocation[0] - 1][field->curLocation[1]]);
		if (isAuto && canMove == BLACKHOLE)
			canMove = 0; // for auto mod
		if (canMove >= 1)
			field->curLocation[0]--;
		return canMove;
	case DOWN_ARROW:
		if (field->curLocation[0] == field->fieldSize[0] - 1)
			canMove = 0;
		else
			canMove = moveable(field->gameField[field->curLocation[0] + 1][field->curLocation[1]]);
		if (isAuto && canMove == BLACKHOLE)
			canMove = 0; // for auto mod
		if (canMove >= 1)
			field->curLocation[0]++;
		return canMove;
	case Q_KEY:
		return Q_KEY;
	case R_KEY:
		return R_KEY;
	}

	int moveable(char des)
	{
		if (des == '1')
			return 0;
		if (des == '0')
		{
			field->gameField[field->curLocation[0]][field->curLocation[1]] = '0';
			return 1;
		}
		if (des == ANTIPROTON || des == PROTON || des == ANTIELECTRON || des == ELECTRON)
		{
			field->gameField[field->curLocation[0]][field->curLocation[1]] = '0';
			bag[*itemCount] = des;
			*itemCount += 1;
			return 1;
		}
		if (des == 'K' || des == 'k')
			return -1;
		if (des == 'C' || des == 'c')
			return 2;
	}
}

int calcPoints(char bag[], int itemCount)
{
	auto void printBag(char *b, int i, int c1, int c2)
	{
		int j;
		printf("\33[2K\r\t\tBag : ");
		for (j = 0; j < i; j++)
		{
			if (j == c1)
				printf("[%c] ", bag[j]);
			else if (j == c2)
				printf("[%c] ", bag[j]);
			else
				printf("%c ", bag[j]);
		}
	}

	system("cls");
	printf("\n\n\n\n\t\tNow It's Time to Calculate Your Points ...\n\t\t");
	printBag(bag, itemCount, -1, -1);
	int index = 0;
	while (index < itemCount)
	{
		char item = bag[index];
		int temp = index + 1;
		while (temp < itemCount)
		{
			printBag(bag, itemCount, index, temp);
			Sleep(1000);
			int diff = fabs(bag[temp] - item);
			if (diff == 32)
			{
				if ((item == ELECTRON && bag[temp] == ANTIELECTRON) ||
					(item == ANTIELECTRON && bag[temp] == ELECTRON) ||
					(item == PROTON && bag[temp] == ANTIPROTON) ||
					(item == ANTIPROTON && bag[temp] == PROTON))
				{
					int i;
					printf("\n\t\tWARNING ! A Pair of %c and %c Reacted Dangerously and Vanished Away..", item, bag[temp]);
					for (i = temp; i <= itemCount - 2; i++)
						bag[i] = bag[i + 1]; // righthand-side item removed
					itemCount--;
					for (i = index; i <= itemCount - 2; i++)
						bag[i] = bag[i + 1]; // lefthand-side item removed
					itemCount--;
					index--;
					Sleep(3000);
					printf("\33[2K\r\033[A\33[2K\r");
					break;
				}
			}
			temp++;
		}
		index++;
	}
	printBag(bag, itemCount, -1, -1);
	int antiElec = 0, antiProt = 0;
	for (index = 0; index < itemCount; index++)
		if (bag[index] == ANTIELECTRON)
			antiElec++;
	for (index = 0; index < itemCount; index++)
		if (bag[index] == ANTIPROTON)
			antiProt++;
	if (antiElec >= antiProt)
		return antiProt * 10;
	else
		return antiElec * 10;
}
