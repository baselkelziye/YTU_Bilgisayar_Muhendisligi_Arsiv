 /***************************************************************************
 * main.c                                                                   *
 *                                                                          *
 *                       PERFECT MAZE GENERATOR                             *
 *                                                                          *
 *                                                                          *
 * Modified in 11 January 2015                                              *
 * Written by Mustafa Berkay Mutlu, 11011027                                *
 * www.berkaymutlu.com                                                      *
 *                                                                          *
 * Please feel free to copy this source code.                               *
 *                                                                          *
 * DESCRIPTION:                                                             *
 *  This program generates a random perfect maze.                           *
 *                                                                          *
 ***************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG_MODE 1 // Bu etiket acik olursa her adimda stack durumunu ve Pop/Push edilmeleri gorebilirsiniz.
#define ERROR -1

typedef enum { false, true } bool;

typedef struct CELL{
    int posX, posY;                                     // Pop edildikten sonra kullanilmak uzere hucrenin koordinatlari tutulur.
    bool left_wall, right_wall, top_wall, bottom_wall;  // Duvarların olup olmadigi bilgisi tutulur.
    bool visit;                                         // Ziyaret edilip edilmedigi bilgisi tutulur.
    char display;                                       // Isaretlemeyi kolaylastirmasi icin her hucrenin kendi karakteri saklanir.
}CELL;

typedef struct STACK{
    int top;        // Stack'in elemanlarindan sonraki bos gozunu isaret eder. Pop/Push islemlerine gore degisir.
    CELL *data;     // Stack'tir, dinamik olarak girilen N sayisina gore olusturulur.
}STACK;

bool isStackEmpty(STACK *);             // Stack tamemen bos ise BOOL_TRUE, degilse BOOL_FALSE dondurur.
bool isStackFull(STACK *);              // Stack tamamen doluysa BOOL_TRUE, degilse BOOL_FALSE dondurur.
void Push(CELL, STACK *);               // Stack'e char karakter Push eder.
CELL Pop(STACK *);                      // Stack'ten char karakter Pop eder.
void GenerateMaze(STACK *, CELL **);    // Labirenti olusturur.
void PrintMaze(CELL **);                // Labirenti ekrana cizer.

int N = 0;          // Labirent'in bir kenarinin buyuklugunu tutar.
int STACK_SIZE;     // Stack'in buyuklugunu tutar.

int main()
{
    int i, j;                       // Dongu degiskenleri.
    CELL **maze;                    // Labirent
    STACK stack = {.top = 0};       // Stack.

    printf("N sayisini giriniz> \n");
    scanf("%d", &N);
    STACK_SIZE = (N+1)*(N+1);

    // maze ve stack dinamik olarak olusturuluyor:
    maze = (CELL**) malloc(sizeof(CELL*)*(N+1));
    stack.data = (CELL*) malloc(sizeof(CELL)*(STACK_SIZE));

    for(i = 0;i < N+1;i++){
        maze[i] = (CELL *) malloc(sizeof(CELL)*(N+1));
    }

    // Matrisler ilklendiriliyor.
    for(i=0;i < N+1;i++){
        for(j=0;j<N+1;j++){
            maze[i][j].posX = i;
            maze[i][j].posY = j;

            maze[i][j].left_wall = true;
            maze[i][j].right_wall = true;
            maze[i][j].top_wall = true;
            maze[i][j].bottom_wall = true;

            maze[i][j].visit = false;
            maze[i][j].display = ' ';
        }
    }


    GenerateMaze(&stack, maze);

    if(DEBUG_MODE) printStack(&stack);

    PrintMaze(maze);


    getchar();
    return 0;
}

bool isStackEmpty(STACK *stack){
    if(stack->top == 0) return true;
    else return false;
}

bool isStackFull(STACK *stack){
    if(stack->top == STACK_SIZE) return true;
    else return false;
}

void Push(CELL item, STACK *stack){
    if(isStackFull(stack)){
        puts("Stack is full.\n");
        exit(ERROR);
    }
    else{
        stack->data[stack->top] = item;
        stack->top++;
    }
}

CELL Pop(STACK *stack){
    if(isStackEmpty(stack)){
        puts("Stack is empty.\n");
        //return false; // ERROR (-1) if statement için true olduðundan ötürü BOOL_FALSE (0) kullanýldý
        exit(ERROR);
    }
    else{
        stack->top--;
        return stack->data[stack->top];
    }
}

void printStack(STACK *stack){
    int i;
    printf("------ STACK ------\n\n");
    for(i=STACK_SIZE-1;i>=0;i--){
        printf("%3d) posX: %3d posY: %3d, walls=> top: %d, right: %d, left: %d, bottom: %d \n", i, stack->data[i].posX, stack->data[i].posY, stack->data[i].top_wall,
               stack->data[i].right_wall, stack->data[i].bottom_wall, stack->data[i].left_wall);

    }
    printf("\n");
    printf("----- STACK END -----\n\n");
}

void GenerateMaze(STACK *stack, CELL **maze){
    int random;                         // Rasgele sayinin tutuldugu degisken.
    CELL current;                       // Pop edildikten sonra hucrenin saklanacagi degisken.
    int x = 1, y = 1;                   // Koordinatlarin tutuldugu, baslangicta 1e 1 noktasini gosteren degiskenler.
    int totalCellCount = (N-1)*(N-1);   // Toplam hucre sayisidir.
    int visitedCells = 1;               // Ugranilan hucrelerin tutuldugu degisken.

    srand(time(NULL));

    maze[x][y].visit = true;
    maze[x][y].display = '*';

    while(visitedCells < totalCellCount){

        if(((maze[x][y-1].visit == false) && (maze[x][y].top_wall == true) && (maze[x][y-1].bottom_wall == true) && (y > 1)) ||         // Yukaridaki komsuya ugranilmamissa,
          ((maze[x+1][y].visit == false) && (maze[x][y].right_wall == true) && (maze[x+1][y].left_wall == true) && (x < N - 1)) ||      // Sagdaki komsuya ugranilmamissa
          ((maze[x][y+1].visit == false) && (maze[x][y].bottom_wall == true) && (maze[x][y+1].top_wall == true) && (y < N - 1)) ||      // Asagidaki komsuya ugranilmamissa,
          ((maze[x-1][y].visit == false) && (maze[x][y].left_wall == true) && (maze[x-1][y].right_wall == true) && (x > 1))){           // Soldaki komsuya ugranilmamissa.

            random = rand() % 4;
            if(DEBUG_MODE) printf("current=> posX: %d, posY: %d  ", x, y);
            if(DEBUG_MODE) printf("random: %d, %s\n", random, (random==0 ? "yukari" : (random==1 ? "sag" : (random==2 ? "asagi" : (random==3 ? "sol" : "hata")))));

            if((random == 0) && (y > 1)){           // Yukari komsuya git
                if(maze[x][y-1].visit == false){    // Ziyaret edilmemisse.
                    maze[x][y-1].visit = true;
                    maze[x][y-1].display = ' ';
                    maze[x][y-1].bottom_wall = false;

                    maze[x][y].top_wall = false;

                    Push(maze[x][y], stack);
                    y--;

                    visitedCells++;
                }
            }
            else if((random == 1) && (x < N - 1)){  // Sagdaki komsuya git
                if(maze[x+1][y].visit == false){    // Ziyaret edilmemisse.
                    maze[x+1][y].visit = true;
                    maze[x+1][y].display = ' ';
                    maze[x+1][y].left_wall = false;

                    maze[x][y].right_wall = false;

                    Push(maze[x][y], stack);
                    x++;

                    visitedCells++;
                }
            }
            else if((random == 2) && (y < N - 1)){   // Asagidaki komsuya git
                if(maze[x][y+1].visit == false){    // Ziyaret edilmemisse.
                    maze[x][y+1].visit = true;
                    maze[x][y+1].display = ' ';
                    maze[x][y+1].top_wall = false;

                    maze[x][y].bottom_wall = false;

                    Push(maze[x][y], stack);
                    y++;

                    visitedCells++;
                }
            }
            else if((random == 3) && (x > 1)){      // Soldaki komsuya git
                if(maze[x-1][y].visit == false){    // Ziyaret edilmemisse.
                    maze[x-1][y].visit = true;
                    maze[x-1][y].display = ' ';
                    maze[x-1][y].right_wall = false;

                    maze[x][y].left_wall = false;

                    Push(maze[x][y], stack);
                    x--;

                    visitedCells++;
                }
            }
      }
      else {
        current = Pop(stack);
        x = current.posX;
        y = current.posY;
      }
    }

    maze[x][y].display = 'X';
}

void PrintMaze(CELL **maze){
    int i, j;   // Dongu degiskenleri.

    printf("------- MAZE -------\n\n");

    for(i=0;i<=N;i++){

        for(j=0;j<=N;j++){
            printf("%s", (maze[j][i].top_wall == true ? "+-" : "+ "));
        }

        printf("\n");

        for(j=0;j<=N;j++){
            printf("%c%c", (maze[j][i].left_wall == true ? '|' : ' '), maze[j][i].display);
        }

        printf("\n");
    }

    printf("\n\n------ MAZE END ------\n");
}


