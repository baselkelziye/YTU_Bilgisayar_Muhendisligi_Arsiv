#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Random Number Generator Function
int randNum(int min_inc, int max_exc){
    int result;
    result = rand() % (max_exc - min_inc) + min_inc;
    return result;
}

// Easy Functions
void easyBoardMaker(int matrix[4][4]){
    int i,j;
    for (i = 0; i < 4; i++){
        printf("+---------------+\n");
        for ( j = 0; j < 4; j++){
            if (matrix[i][j] == 42 || matrix[i][j] == 45){
                printf("| %c ", matrix[i][j]);
            }
            else{
                printf("| %d ", matrix[i][j]);
            }
            if (j == 3){
                printf("|");
            }
            if (i == 3 && j == 3){
                printf("\n+---------------+");
            }
        }
        printf("\n");
    }
}
void easyPutNumber(int a, int matrix[4][4]){

    int b = randNum(0,4);
    int c = randNum(0,4);

    if (matrix[b][c] == 0){
        matrix[b][c] = a;
    }
    else{
        easyPutNumber(a, matrix);
    }
}
void easyCompChoice(int *row1, int *column1, int *row2, int *column2, int floor[4][4]){
    *row1 = randNum(1,5);
    *column1 = randNum(1,5);
    *row2 = randNum(1,5);
    *column2 = randNum(1,5);
    if (*row1 == *row2 && *column1 == *column2){
        easyCompChoice(row1, column1, row2, column2, floor);
    }
    else if (floor[*row1-1][*column1-1] == 45){
        easyCompChoice(row1, column1, row2, column2, floor);
    }
    else if (floor[*row2-1][*column2-1] == 45){
        easyCompChoice(row1, column1, row2, column2, floor);
    }
}
void easyMemChanger(int row, int column, int matrix[2][2]){
    matrix[0][0] = matrix[1][0];
    matrix[0][1] = matrix[1][1];
    matrix[1][0] = row;
    matrix[1][1] = column;
}

// Medium Functions
void medBoardMaker(int matrix[6][6]){
    int i,j;
    for (i = 0; i < 6; i++){
        printf("+-----------------------------+\n");
        for ( j = 0; j < 6; j++){
            if (matrix[i][j] == 42 || matrix[i][j] == 45){
                printf("| %c%c ",matrix[i][j], matrix[i][j]);
            }
            else if (matrix[i][j] < 10){
                printf("|  %d ",matrix[i][j]);
            }
            else{
                printf("| %d ",matrix[i][j]);
            }
            if (j == 5){
                printf("|");
            }
            if (i == 5 && j == 5){
                printf("\n+-----------------------------+");
            }
        }
        printf("\n");
    }
}
void medPutNumber(int a, int matrix[6][6]){

    int b = randNum(0,6);
    int c = randNum(0,6);

    if (matrix[b][c] == 0){
        matrix[b][c] = a;
    }
    else{
        medPutNumber(a, matrix);
    }
}
void medCompChoice(int *row1, int *column1, int *row2, int *column2, int floor[6][6]){
    *row1 = randNum(1,7);
    *column1 = randNum(1,7);
    *row2 = randNum(1,7);
    *column2 = randNum(1,7);
    if (*row1 == *row2 && *column1 == *column2){
        medCompChoice(row1, column1, row2, column2, floor);
    }
    else if (floor[*row1-1][*column1-1] == 45){
        medCompChoice(row1, column1, row2, column2, floor);
    }
    else if (floor[*row2-1][*column2-1] == 45){
        medCompChoice(row1, column1, row2, column2, floor);
    }
}
void medMemChanger(int row, int column, int matrix[6][2]){
    int i;
    for (i = 0; i < 5; i++){
        matrix[i][0] = matrix[i+1][0];
        matrix[i][1] = matrix[i+1][1];
    }
    matrix[5][0] = row;
    matrix[5][1] = column;
}

// Hard Functions
void hardBoardMaker (int matrix[8][8]){
    int i,j;
    for (i = 0; i < 8; i++){
        printf("+---------------------------------------+\n");
        for ( j = 0; j < 8; j++){
            if (matrix[i][j] == 42 || matrix[i][j] == 45){
                printf("| %c%c ",matrix[i][j], matrix[i][j]);
            }
            else if (matrix[i][j] < 10){
                printf("|  %d ",matrix[i][j]);
            }
            else{
                printf("| %d ",matrix[i][j]);
            }
            if (j == 7){
                printf("|");
            }
            if (i == 7 && j == 7){
                printf("\n+---------------------------------------+");
            }
        }
        printf("\n");
    }
}
void hardPutNumber(int a, int matrix[8][8]){

    int b = randNum(0,8);
    int c = randNum(0,8);

    if (matrix[b][c] == 0){
        matrix[b][c] = a;
    }
    else{
        hardPutNumber(a, matrix);
    }
}
void hardCompChoice(int *row1, int *column1, int *row2, int *column2, int floor[8][8]){
    *row1 = randNum(1,9);
    *column1 = randNum(1,9);
    *row2 = randNum(1,9);
    *column2 = randNum(1,9);
    if (*row1 == *row2 && *column1 == *column2){
        hardCompChoice(row1, column1, row2, column2, floor);
    }
    else if (floor[*row1-1][*column1-1] == 45){
        hardCompChoice(row1, column1, row2, column2, floor);
    }
    else if (floor[*row2-1][*column2-1] == 45){
        hardCompChoice(row1, column1, row2, column2, floor);
    }
}
void hardMemChanger(int row, int column, int matrix[16][2]){
    int i;
    for (i = 0; i < 15; i++){
        matrix[i][0] = matrix[i+1][0];
        matrix[i][1] = matrix[i+1][1];
    }
    matrix[15][0] = row;
    matrix[15][1] = column;
}

int main() {
    srand(time(NULL));
    //Variables
    int difficulty, flag;
    int i, j;
    int pRow1, pColumn1, pRow2, pColumn2;
    int cRow1, cColumn1, cRow2, cColumn2;
    int pPoint = 0, cPoint = 0;
    int tour = 1;
    int pGuess = 0, cGuess = 0;
    //
    printf("Hi! This is my very first mind game so enjoy it!\n");
    printf("For easy enter 1, for medium enter 2, for hard enter 3.\n");
    scanf("%d",&difficulty);

    if (difficulty == 1){
        // Variables
        int easyNumbers[4][4] = {{0,0,0,0},
                                 {0,0,0,0},
                                 {0,0,0,0},
                                 {0,0,0,0}};

        int easyFloor[4][4] = {{42,42,42,42},
                               {42,42,42,42},
                               {42,42,42,42},
                               {42,42,42,42}};

        int easyCompMem[2][2] = {{0,0},
                                 {0,0}};
        //

        for (i = 1; i < 9; i++){
            easyPutNumber(i, easyNumbers);
            easyPutNumber(i, easyNumbers);
        }
        
		printf("Here's the game board created by the rules.\n");
        easyBoardMaker(easyNumbers);
        printf("Press enter to continue.");
        getch();
		system("cls");
		
        while (pPoint != 5 && cPoint != 5){
            while (tour == 1){
                easyBoardMaker(easyFloor);
                printf("For first card enter row and column:");
                scanf("%d %d", &pRow1, &pColumn1);
                easyMemChanger(pRow1, pColumn1, easyCompMem);
                pRow1 = pRow1 - 1;
                pColumn1 = pColumn1 - 1;
                easyFloor[pRow1][pColumn1] = easyNumbers[pRow1][pColumn1];
                easyBoardMaker(easyFloor);
                printf("For second card enter row and column:");
                scanf("%d %d", &pRow2, &pColumn2);
                easyMemChanger(pRow2, pColumn2, easyCompMem);
                pRow2 = pRow2 - 1;
                pColumn2 = pColumn2 - 1;
                easyFloor[pRow2][pColumn2] = easyNumbers[pRow2][pColumn2];
                easyBoardMaker(easyFloor);
                printf("\nPress enter to continue.");
                getch();
                system("cls");
                if (easyFloor[pRow1][pColumn1] == easyFloor[pRow2][pColumn2]){
                    easyFloor[pRow1][pColumn1] = 45;
                    easyFloor[pRow2][pColumn2] = 45;
                    pPoint++;
                    pGuess += 2;
                    printf("Congratulations your point is: %d\n",pPoint);
                    if (pPoint == 5){
                        tour = 2;
                    }
                }
                else{
                    easyFloor[pRow1][pColumn1] = 42;
                    easyFloor[pRow2][pColumn2] = 42;
                    tour = 0;
                    pGuess += 2;
                }
                easyBoardMaker(easyFloor);
            }
            while (tour == 0){
                // Defining computer's choices
                if(easyFloor[pRow1][pColumn1] == 45 && easyFloor[pRow2][pColumn2] == 45){
                    easyCompChoice(&cRow1, &cColumn1, &cRow2, &cColumn2, easyFloor);
                }
                else{
                    easyCompChoice(&cRow1, &cColumn1, &cRow2, &cColumn2, easyFloor);
                    if (easyNumbers[cRow1-1][cColumn1-1] == easyNumbers[easyCompMem[0][0]-1][easyCompMem[0][1]-1] && (cRow1 != easyCompMem[0][0] && cColumn1 != easyCompMem[0][1])){
                        cRow2 = easyCompMem[0][0];
                        cColumn2 = easyCompMem[0][1];
                    }
                    else if (easyNumbers[cRow1-1][cColumn1-1] == easyNumbers[easyCompMem[1][0]-1][easyCompMem[1][1]-1] && (cRow1 != easyCompMem[1][0] && cColumn1 != easyCompMem[1][1])){
                        cRow2 = easyCompMem[1][0];
                        cColumn2 = easyCompMem[1][1];
                    }
                }
                //
                printf("Computer's turn.\n");
                printf("Computer's first card choice: %d %d\n", cRow1, cColumn1);
                cRow1 = cRow1 - 1;
                cColumn1 = cColumn1 - 1;
                easyFloor[cRow1][cColumn1] = easyNumbers[cRow1][cColumn1];
                easyBoardMaker(easyFloor);
                printf("\nPress enter to continue.\n");
                getch();
                printf("Computer's second card choice: %d %d\n", cRow2, cColumn2);
                cRow2 = cRow2 - 1;
                cColumn2 = cColumn2 - 1;
                easyFloor[cRow2][cColumn2] = easyNumbers[cRow2][cColumn2];
                easyBoardMaker(easyFloor);
                printf("\nPress enter to continue.");
                getch();
                system("cls");
                if (easyFloor[cRow1][cColumn1] == easyFloor[cRow2][cColumn2]){
                    easyFloor[cRow1][cColumn1] = 45;
                    easyFloor[cRow2][cColumn2] = 45;
                    cPoint++;
                    cGuess += 2;
                    printf("Computer's point is: %d\n", cPoint);
                    if (cPoint == 5){
                        tour = 2;
                    }
                }
                else{
                    easyFloor[cRow1][cColumn1] = 42;
                    easyFloor[cRow2][cColumn2] = 42;
                    tour = 1;
                    cGuess += 2;
                }
            }
        }
        if (cPoint == 5 && pPoint != 5){
            printf("Computer wins. Guess time: %d", cGuess);
        }
        else if (pPoint == 5 && cPoint != 5){
            printf("Congratulations you have won. Guess time: %d", pGuess);
        }
        else if (pPoint == 4 && cPoint == 4){
            printf("It's a tie. Nobody wins.");
        }
    }
    else if (difficulty == 2){
        // Variables
        int medNumbers[6][6] = {{0,0,0,0,0,0},
                                {0,0,0,0,0,0},
                                {0,0,0,0,0,0},
                                {0,0,0,0,0,0},
                                {0,0,0,0,0,0},
                                {0,0,0,0,0,0}};

        int medFloor[6][6] = {{42,42,42,42,42,42},
                              {42,42,42,42,42,42},
                              {42,42,42,42,42,42},
                              {42,42,42,42,42,42},
                              {42,42,42,42,42,42},
                              {42,42,42,42,42,42}};

        int medCompMem[6][2] = {{0,0},
                                {0,0},
                                {0,0},
                                {0,0},
                                {0,0},
                                {0,0}};
        //

        for (i = 1; i < 19; i++){
            medPutNumber(i, medNumbers);
            medPutNumber(i, medNumbers);
        }
        
        printf("Here's the game board created by the rules.\n");
        medBoardMaker(medNumbers);
        printf("Press enter to continue.");
        getch();
		system("cls");
		
        while (pPoint != 10 && cPoint != 10){
            while (tour == 1){
                medBoardMaker(medFloor);
                printf("For first card enter row and column:");
                scanf("%d %d", &pRow1, &pColumn1);
                medMemChanger(pRow1, pColumn1, medCompMem);
                pRow1 = pRow1 - 1;
                pColumn1 = pColumn1 - 1;
                medFloor[pRow1][pColumn1] = medNumbers[pRow1][pColumn1];
                medBoardMaker(medFloor);
                printf("For second card enter row and column:");
                scanf("%d %d", &pRow2, &pColumn2);
                medMemChanger(pRow2, pColumn2, medCompMem);
                pRow2 = pRow2 - 1;
                pColumn2 = pColumn2 - 1;
                medFloor[pRow2][pColumn2] = medNumbers[pRow2][pColumn2];
                medBoardMaker(medFloor);
                printf("\nPress enter to continue.");
                getch();
                system("cls");
                if (medFloor[pRow1][pColumn1] == medFloor[pRow2][pColumn2]){
                    medFloor[pRow1][pColumn1] = 45;
                    medFloor[pRow2][pColumn2] = 45;
                    pPoint++;
                    pGuess += 2;
                    printf("Congratulations your point is: %d\n",pPoint);
                    if (pPoint == 10){
                        tour = 2;
                    }
                }
                else{
                    medFloor[pRow1][pColumn1] = 42;
                    medFloor[pRow2][pColumn2] = 42;
                    tour = 0;
                    pGuess += 2;
                }
                medBoardMaker(medFloor);
            }
            while (tour == 0){
                //Defining computer's choices
                flag = 1;
                for (i = 0; i < 5; i++){
                    for (j = i+1; j < 6; j++){
                    	if ((medNumbers[medCompMem[i][0]-1][medCompMem[i][1]-1] == medNumbers[medCompMem[j][0]-1][medCompMem[j][1]-1]) && (medCompMem[i][0] != medCompMem[j][0] || medCompMem[i][1] != medCompMem[j][1])){
                            if ((medCompMem[i][0] != 0 && medCompMem[j][0] != 0) && (medFloor[medCompMem[i][0]-1][medCompMem[i][1]-1] != 45)){
                            	cRow1 = medCompMem[i][0];
                            	cColumn1 = medCompMem[i][1];
                            	cRow2 = medCompMem[j][0];
                           	    cColumn2 = medCompMem[j][1];
                           	    flag = 0;
                           	    i = 5;
                           	    j = 6;
							}
                       	}
                    }
                }
                if (flag == 1){
                    medCompChoice(&cRow1, &cColumn1, &cRow2, &cColumn2, medFloor);
                    for (i = 0; i < 6; i++){
                        if (medNumbers[cRow1-1][cColumn1-1] == medNumbers[medCompMem[i][0]-1][medCompMem[i][1]-1] && (cRow1 != medCompMem[i][0] || cColumn1 != medCompMem[i][1])){
                            if (medCompMem[i][0] != 0){
                            	cRow2 = medCompMem[i][0];
                            	cColumn2 = medCompMem[i][1];
							}
                        }
                    }
                }
                medMemChanger(cRow1, cColumn1, medCompMem);
                medMemChanger(cRow2, cColumn2, medCompMem);
                //
                printf("Computer's turn.\n");
                printf("Computer's first card choice: %d %d\n", cRow1, cColumn1);
                cRow1 = cRow1 - 1;
                cColumn1 = cColumn1 - 1;
                medFloor[cRow1][cColumn1] = medNumbers[cRow1][cColumn1];
                medBoardMaker(medFloor);
                printf("\nPress enter to continue.\n");
                getch();
                printf("Computer's second card choice: %d %d\n", cRow2, cColumn2);
                cRow2 = cRow2 - 1;
                cColumn2 = cColumn2 - 1;
                medFloor[cRow2][cColumn2] = medNumbers[cRow2][cColumn2];
                medBoardMaker(medFloor);
                printf("\nPress enter to continue.");
                getch();
                system("cls");
                if (medFloor[cRow1][cColumn1] == medFloor[cRow2][cColumn2]){
                    medFloor[cRow1][cColumn1] = 45;
                    medFloor[cRow2][cColumn2] = 45;
                    cPoint++;
                    cGuess += 2;
                    printf("Computer's point is: %d\n", cPoint);
                    if (cPoint == 10){
                        tour = 2;
                    }
                }
                else{
                    medFloor[cRow1][cColumn1] = 42;
                    medFloor[cRow2][cColumn2] = 42;
                    tour = 1;
                    cGuess += 2;
                }
            }
        }
        if (cPoint == 10 && pPoint != 10){
            printf("Computer wins. Guess Time: %d", cGuess);
        }
        else if (pPoint == 10 && cPoint != 10){
            printf("Congratulations you have won. Guess Time: %d", pGuess);
        }
        else if (pPoint == 9 && cPoint == 9){
            printf("It's a tie. Nobody wins.");
        }
    }
    else if (difficulty == 3){
        // Variables
        int hardNumbers[8][8] = {{0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0}};

        int hardFloor[8][8] = {{42,42,42,42,42,42,42,42},
                               {42,42,42,42,42,42,42,42},
                               {42,42,42,42,42,42,42,42},
                               {42,42,42,42,42,42,42,42},
                               {42,42,42,42,42,42,42,42},
                               {42,42,42,42,42,42,42,42},
                               {42,42,42,42,42,42,42,42},
                               {42,42,42,42,42,42,42,42}};

        int hardCompMem[16][2] = {{0,1}, {0,2}, {0,3},
                                  {0,4}, {0,5}, {0,6},
                                  {0,7}, {0,8}, {0,9},
                                  {0,0}, {0,1}, {0,2},
                                  {0,3}, {0,4}, {0,5},
                                  {0,6}};
        //

        for (i = 1; i < 33; i++) {
            hardPutNumber(i, hardNumbers);
            hardPutNumber(i, hardNumbers);
        }
        
        printf("Here's the game board created by the rules.\n'");
        hardBoardMaker(hardNumbers);
        printf("Press enter to continue.");
        getch();
		system("cls");

        while (pPoint != 17 && cPoint != 17){
            while (tour == 1){
                hardBoardMaker(hardFloor);
                printf("For first card enter row and column:");
                scanf("%d %d", &pRow1, &pColumn1);
                hardMemChanger(pRow1, pColumn1, hardCompMem);
                pRow1 = pRow1 - 1;
                pColumn1 = pColumn1 - 1;
                hardFloor[pRow1][pColumn1] = hardNumbers[pRow1][pColumn1];
                hardBoardMaker(hardFloor);
                printf("For second card enter row and column:");
                scanf("%d %d", &pRow2, &pColumn2);
                hardMemChanger(pRow2, pColumn2, hardCompMem);
                pRow2 = pRow2 - 1;
                pColumn2 = pColumn2 - 1;
                hardFloor[pRow2][pColumn2] = hardNumbers[pRow2][pColumn2];
                hardBoardMaker(hardFloor);
                printf("Press enter to continue.");
       			getch();
				system("cls");
                if (hardFloor[pRow1][pColumn1] == hardFloor[pRow2][pColumn2]){
                    hardFloor[pRow1][pColumn1] = 45;
                    hardFloor[pRow2][pColumn2] = 45;
                    pPoint++;
                    pGuess += 2;
                    printf("Congratulations your point is: %d\n",pPoint);
                    if (pPoint == 17){
                        tour = 2;
                    }
                }
                else{
                    hardFloor[pRow1][pColumn1] = 42;
                    hardFloor[pRow2][pColumn2] = 42;
                    tour = 0;
                    pGuess += 2;
                }
                hardBoardMaker(hardFloor);
            }
            while (tour == 0){
                //Defining computer's choices
                flag = 1;
                for (i = 0; i < 15; i++){
                    for (j = i+1; j < 16; j++){
                    	if ((hardNumbers[hardCompMem[i][0]-1][hardCompMem[i][1]-1] == hardNumbers[hardCompMem[j][0]-1][hardCompMem[j][1]-1]) && (hardCompMem[i][0] != hardCompMem[j][0] || hardCompMem[i][1] != hardCompMem[j][1])){
                            if ((hardCompMem[i][0] != 0 && hardCompMem[j][0] != 0) && (hardFloor[hardCompMem[i][0]-1][hardCompMem[i][1]-1] != 45)){
                            	cRow1 = hardCompMem[i][0];
                            	cColumn1 = hardCompMem[i][1];
                            	cRow2 = hardCompMem[j][0];
                           	    cColumn2 = hardCompMem[j][1];
                           	    flag = 0;
                           	    i = 15;
                           	    j = 16;
							}
                       	}
                    }
                }
                if (flag == 1){
                    hardCompChoice(&cRow1, &cColumn1, &cRow2, &cColumn2, hardFloor);
                    for (i = 0; i < 16; i++){
                        if (hardNumbers[cRow1-1][cColumn1-1] == hardNumbers[hardCompMem[i][0]-1][hardCompMem[i][1]-1] && (cRow1 != hardCompMem[i][0] || cColumn1 != hardCompMem[i][1])){
                            if (hardCompMem[i][0] != 0){
                            	cRow2 = hardCompMem[i][0];
                            	cColumn2 = hardCompMem[i][1];
							}
                        }
                    }
                }
                hardMemChanger(cRow1, cColumn1, hardCompMem);
                hardMemChanger(cRow2, cColumn2, hardCompMem);
                //
                printf("Computer's turn.\n");
                printf("Computer's first card choice: %d %d\n", cRow1, cColumn1);
                cRow1 = cRow1 - 1;
                cColumn1 = cColumn1 - 1;
                hardFloor[cRow1][cColumn1] = hardNumbers[cRow1][cColumn1];
                hardBoardMaker(hardFloor);
                printf("\nPress enter to continue.\n");
       			getch();
                printf("Computer's second card choice: %d %d\n", cRow2, cColumn2);
                cRow2 = cRow2 - 1;
                cColumn2 = cColumn2 - 1;
                hardFloor[cRow2][cColumn2] = hardNumbers[cRow2][cColumn2];
                hardBoardMaker(hardFloor);
                printf("\nPress enter to continue.");
       			getch();
       			system("cls");
                if (hardFloor[cRow1][cColumn1] == hardFloor[cRow2][cColumn2]){
                    hardFloor[cRow1][cColumn1] = 45;
                    hardFloor[cRow2][cColumn2] = 45;
                    cPoint++;
                    cGuess += 2;
                    printf("Computer's point is: %d\n", cPoint);
                    if (cPoint == 17){
                        tour = 2;
                    }
                }
                else{
                    hardFloor[cRow1][cColumn1] = 42;
                    hardFloor[cRow2][cColumn2] = 42;
                    tour = 1;
                    cGuess += 2;
                }
            }
        }
        if (cPoint == 17 && pPoint != 17){
            printf("Computer wins. Guess time: %d", cGuess);
        }
        else if (pPoint == 17 && cPoint != 17){
            printf("Congratulations you have won. Guess Time: %d", pGuess);
        }
        else if (pPoint == 16 && cPoint == 16){
            printf("It's a tie. Nobody wins.");
        }
    }
    else{
        printf("It's not a valid difficulty value.");
    }
    return 0;
}
