#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WALL '#'
#define SNAKE '1'
#define FOOD '0'
#define EMPTY ' '

int main(void)
{
	int i, j, k, N=100, M=100;
	char gameBoard[100][100];
	int tailX[10000] = { 0 };
	int tailY[10000] = { 0 };

	int snakeSize = 1;
	char direction = 'x';

	int snakeX = 0;
	int snakeY = 0;

	int foodX[10000];
	int foodY[10000];

	int foodCount = 10;
	int firstInit = 0;

	srand(time(NULL));
	printf("Oyun alani satir sayisini giriniz: ");
	scanf("%d", &N);
	printf("Oyun alani sutun sayisini giriniz: ");
	scanf("%d", &M);

	snakeX = rand() % N;
	snakeY = rand() % M;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			gameBoard[i][j] = EMPTY;
		}
	}

	tailX[0] = snakeX;
	tailY[0] = snakeY;

	firstInit = 1;
	gameBoard[snakeX][snakeY] = SNAKE;
	printf("Yemek sayisini gir: ");
	scanf("%d", &foodCount);
	for (i = 0; i < foodCount; i++) {
		do {
			foodX[i] = rand() % N;
			foodY[i] = rand() % M;
		} while (gameBoard[foodX[i]][foodY[i]] != EMPTY);
		gameBoard[foodX[i]][foodY[i]] = FOOD;
	}

	do {
		for (i = 0; i < N; i++){
			if (i == 0){
				printf(" ");
				for (k = 0; k < M; k++)
					printf("%c", WALL);
				printf("\n");
			}
			printf("%c", WALL);
			for (j = 0; j < M; j++){
				printf("%c", gameBoard[i][j]);
			}
			printf("%c", WALL);
			printf("\n");
			if (i == N - 1){
				printf(" ");
				for (k = 0; k < M; k++)
					printf("%c", WALL);
				printf("\n");
			}
		}

		if (gameBoard[snakeX][snakeY] == WALL){
			printf("Oppss, carptiniz. Oyun bitti! \n");
			break;
		}
		
		char prev = direction;
		printf("\n");
		printf("Hamle yonunu belirtin (w = yukari /a = sol/s = asagi/d = sag): ");
		scanf(" %c", &direction);

		int x = tailX[snakeSize - 1];
		int y = tailY[snakeSize - 1];

		if (direction == 'w') {
			if (prev == 's')
				continue;
			snakeX--;
		}
		else if (direction == 'a') {
			if (prev == 'd')
				continue;
			snakeY--;
		}
		else if (direction == 's') {
			if (prev == 'w')
				continue;
			snakeX++;
		}
		else if (direction == 'd') {
			if (prev == 'a')
				continue;
			snakeY++;
		}
		if (snakeX < 0 || snakeX >= N || snakeY < 0 || snakeY >= M) {
			printf("Oyun bitti! Oyun alanini terk ettin...");
			exit(0);
		}

		for (i = 0; i < N; i++){
			for (j = 0; j < M; j++){
				gameBoard[i][j] = EMPTY;
			}
		}

		for (i = snakeSize - 1; i > 0; i--){
			tailX[i] = tailX[i - 1];
			tailY[i] = tailY[i - 1];
		}
		tailX[0] = snakeX;
		tailY[0] = snakeY;

		int foodIndex = -1;
		for (i = 0; i < foodCount; i++){
			if (foodX[i] == snakeX && foodY[i] == snakeY)
				foodIndex = i;
			if (foodIndex > -1 && i >= foodIndex && i <= foodCount - 1){
				foodX[i] = foodX[i + 1];
				foodY[i] = foodY[i + 1];
			}
		}
		if (foodIndex >= 0){
			foodCount--;
			tailX[snakeSize] = x;
			tailY[snakeSize] = y;
			snakeSize++;
		}

		for (i = 0; i < snakeSize; i++)
			gameBoard[tailX[i]][tailY[i]] = i + '1';

		for (i = 0; i < foodCount; i++){
			if (foodX[i] != -1 && foodY[i] != -1)
				gameBoard[foodX[i]][foodY[i]] = FOOD;
		}

		direction = prev;

		if (foodCount == 0) {
			printf("Oyun bitti! Tum yemekler tukendi. \n");
			break;
		}
	} while (1);

	return 0;
}
