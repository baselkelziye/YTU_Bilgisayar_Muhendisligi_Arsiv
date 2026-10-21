/****************************************************************************
 * main.c                                                                   *
 *                                                                          *
 *                              N-QUEEN PROBLEM                             *
 *                                                                          *
 *                                                                          *
 * Modified in 3 December 2014                                              *
 * Written by Mustafa Berkay Mutlu, 11011027                                *
 * www.berkaymutlu.com                                                      *
 *                                                                          *
 * Please feel free to copy this source code.                               *
 *                                                                          *
 * DESCRIPTION:                                                             *
 *  This program calculates where to put N queens on a NxN size board       *
 * in the condition of no congestions.                                      *
 *                                                                          *
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <Math.h> // Absolute fonksiyonu icin gereklidir.

#define ERROR -1
#define EMPTY -1 // boardStatus dizisinde sutunun bos oldugunu ifade etmek icin kullanilir.

// Ayarlar:
#define N 5
#define STACK_SIZE N   // Stack'in boyutunu ifade eder.
#define CHESS_BOARD_SIZE N // Satranc tahtasinin bir kenarinin uzunlugunu ifade eder.
#define QUEEN_COUNT N // Kac vezir yerlestirilecegini ifade eder.
#define DEBUG_MODE 0 // 1 olursa ekrana bilgilendirme yazilir, 0 olursa sadece sonuc yazilir.


typedef enum { false, true } bool;

typedef struct QUEEN{
    int row; // Vezirin satirini tutar.
    int col; // Vezirin sutununu tutar.
}QUEEN;

typedef struct STACK{
    int top; // Stack'in elemanlarindan sonraki bos gozunu isaret eder. Pop/Push islemlerine gore degisir.
    QUEEN data[STACK_SIZE]; // Stack'tir.
}STACK;

int isStackEmpty(STACK *); // Stack tamemen bos ise True, degilse False dondurur.
int isStackFull(STACK *); // Stack tamamen doluysa True, degilse False dondurur.
bool Push(STACK *, QUEEN *, int []); // Stack'e QUEEN Push eder.
bool Pop(STACK *, QUEEN *, int []); // Stack'ten QUEEN Pop eder.
bool CheckCongestion(int[]); // Butun tahtada cakisma olup olmadigini kontrol eder.
int FindNextAvailableRow(int []); // Bir sonraki bos olan satir numarasini dondurur.
bool MoveRight(STACK *, QUEEN *, int[]); // Veziri saga kaydirir. Eger kaydirma basariliysa ve cakisma yoksa True, kaydirma yapacak yer yoksa (problem varsa) False doner.
void BackTrack(STACK *, int []); // Stack'ten eleman alip bir sonraki yere yerlestirir. Rekursiftir.
void PrintBoardStatus(int []); // boardStatus degiskenini ekrana yazdirir.
void PrintStack(STACK *); // Stack'i ekrana yazdirir.
void PrintBoard(int []); // Gorsel olarak duzgun bicimde tahtayi ve vezirleri yazdirir.


int main()
{
    STACK stack = {.top = 0, .data = 0};
    QUEEN item, item2;
    int boardStatus[CHESS_BOARD_SIZE];
    int i;

    for(i=0;i < CHESS_BOARD_SIZE;i++){
        boardStatus[i] = EMPTY;
    }

    while(stack.top < QUEEN_COUNT){
        item.row = FindNextAvailableRow(boardStatus);
        item.col = 0;
        Push(&stack, &item, boardStatus);
        if(CheckCongestion(boardStatus)){ // Eger cakisma varsa:
            Pop(&stack, &item2, boardStatus);
            if(!MoveRight(&stack, &item2, boardStatus)){ // Eger saga ilerletmete sorun varsa (yer kalmadiysa):
                // Yer kalmadi Backtracking yapiliyor:
                BackTrack(&stack, boardStatus);
            }
        }
    }

    printf("\n\n\nIslem bitti, sonuc: \n");
    PrintStack(&stack);
    PrintBoardStatus(boardStatus);
    PrintBoard(boardStatus);
    return 0;
}


int isStackEmpty(STACK *stack){
    if(stack->top == 0) return true;
    else return false;
}

int isStackFull(STACK *stack){
    if(stack->top == STACK_SIZE) return true;
    else return false;
}

bool Push(STACK *stack, QUEEN *queen, int boardStatus[]){
    if(isStackFull(stack)){
        puts("Stack is full.\n");
        return false;
    }
    else{
        stack->data[stack->top] = *queen;
        stack->top++;
        boardStatus[queen->row] = queen->col;
        return true;
    }
}

bool Pop(STACK *stack, QUEEN *queen, int boardStatus[]){
    if(isStackEmpty(stack)){
        puts("Stack is empty.\n");
        return false; // ERROR (-1) if statement için true oldugundan oturu false (0) kullanildi.
    }
    else{
        stack->top--;
        *queen = stack->data[stack->top];
        boardStatus[queen->row] = EMPTY;
        return true;
    }
}

bool CheckCongestion(int boardStatus[]){
    int i, j; // Dongu degiskenleri
    bool congestion = false; // Cakisma varsa Congestion=true, yoksa congestion=false olur. Fonksiyondan bu deger dondurulur.
    int deltaRow, deltaCol; // Satir ve sutun farklarini ifade eden degislenler.

    for(i=0;i < CHESS_BOARD_SIZE && !congestion;i++){
        if(DEBUG_MODE) PrintBoardStatus(boardStatus);

        for(j=i+1;j < CHESS_BOARD_SIZE && !congestion;j++){

            // Ayni satirdalarsa cakisma olur ancak vezirler hep bir alt satira eklendigi icin,
            // satirlarda cakisma olup olmadigi kontrol edilmemistir.

            // Ayni sutundaysa cakisma vardir:
            if((boardStatus[i] != EMPTY) && (boardStatus[i] == boardStatus[j])){
                congestion = true;
            }

            // Ayni kosegendeyse cakisma vardir:
            if(!congestion && (boardStatus[i] != EMPTY) && (boardStatus[j] != EMPTY)){ // Satranc tahtasinin i'ninci ve j'ninci satirinda vezir varsa
                deltaRow = abs(i - j); // Satirlar farki alinir,
                deltaCol = abs(boardStatus[i] - boardStatus[j]); // Sutunlar farki alinir,

                if(deltaRow == deltaCol){ // Satir ve sutun farklari esitse ayni kosegendedirler ve cakisma vardir.
                    congestion = true;
                }
            }
        }
    }

    return congestion;
}

int FindNextAvailableRow(int boardStatus[]){
    int i;

    for(i=0;i < CHESS_BOARD_SIZE;i++){
        if(boardStatus[i] == EMPTY)
            return i;
    }
}

bool MoveRight(STACK *stack, QUEEN *queen, int boardStatus[]){

    if(DEBUG_MODE) PrintBoardStatus(boardStatus);
    if(DEBUG_MODE) printf("position before move right, row: %d col: %d\n",queen->row, queen->col);

    if(queen->col < CHESS_BOARD_SIZE - 1){
        queen->col++;
        if(DEBUG_MODE) PrintStack(stack);
        Push(stack, queen, boardStatus);
        if(DEBUG_MODE) PrintStack(stack);

        if(CheckCongestion(boardStatus)){ // Eger cakisma varsa tekrar saga kaydirilir:
            Pop(stack, queen, boardStatus);
            return MoveRight(stack, queen, boardStatus);
        }
        else {
            return true;
        }
    }
    else {
        if(DEBUG_MODE) printf("End of chess board. No available space left.\n");
        return false;
    }
}

void BackTrack(STACK *stack, int boardStatus[]){
    QUEEN item;
    Pop(stack, &item, boardStatus);
    if(!MoveRight(stack, &item, boardStatus)){
        BackTrack(stack, boardStatus);
    }
}

void PrintStack(STACK *stack){
    int i;

    printf("--------- STACK ---------\n");
    for(i=stack->top-1;i>=0;i--){
        printf("%d) row: %d, col: %d\n", i, stack->data[i].row, stack->data[i].col);
    }

    printf("------- STACK END -------\n\n");
}

void PrintBoardStatus(int boardStatus[]){
    int i;

    printf("----- Board Status -----\n");
    for(i=0;i<CHESS_BOARD_SIZE;i++){
        printf("%d) %d\n", i, boardStatus[i]);
    }
    printf("--- Board Status End ---\n");
}

void PrintBoard(int boardStatus[]){
    int i, j, k;
    int queenCount = 0;

    printf("\n\n");
    for(i=0;i<11;i++) printf("-");
    for(i=0;i<(4*CHESS_BOARD_SIZE - 14)/2;i++) printf("-");
    printf(" BOARD STATUS ");
    for(i=0;i<(4*CHESS_BOARD_SIZE - 14)/2;i++) printf("-");
    for(i=0;i<11;i++) printf("-");
    printf("\n\n\n");

    printf("\t   ");
    for(k=0;k < CHESS_BOARD_SIZE;k++) printf(" %2d ", k);
    printf("\n");

    for(i=0;i < CHESS_BOARD_SIZE;i++){
        printf("\t   ");
        for(k=0;k < CHESS_BOARD_SIZE;k++) printf("----");
        printf("\n\t%2d ", i);
        for(j=0;j < CHESS_BOARD_SIZE;j++){

            if(boardStatus[i] == j)
                printf("| %d ", ++queenCount);
            else
                printf("|   ");
        }
        printf("|\n");
    }

    printf("\t   ");
    for(k=0;k < CHESS_BOARD_SIZE;k++) printf("----");

    printf("\n\n");
    for(i=0;i<10;i++) printf("-");
    for(i=0;i<(4*CHESS_BOARD_SIZE - 16)/2;i++) printf("-");
    printf(" BOARD STATUS END ");
    for(i=0;i<(4*CHESS_BOARD_SIZE - 16)/2;i++) printf("-");
    for(i=0;i<10;i++) printf("-");
    printf("\n");
}

