#ifndef GAME_H_
#define GAME_H_

#define MAX 50

typedef struct user {
    char nickName[MAX];
    char name[MAX];
    char surname[MAX];
    char password[MAX];
} User;

typedef struct {
    char name[MAX];
    int scores[MAX];
    int scoreCount;
} Player;


typedef struct {
    int row;
    int col;
    int distance;
} Node;

typedef struct {
    Node *array;
    int front, rear;
    unsigned capacity;
} Queue;



#include <unistd.h>
#include <termios.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <stdbool.h>



int getch(void);
void loadMap(char * filename, char *** mapRef, int * rowCount, int * wordCount);
void printMap(char ** map, int rowCount);
void find(char ** map, int rowCount, char term, int * y, int * x);
void preparations(char * filename, User *);
int isValid(char ** map, int rowCount, int y, int x, int dirX[], int dirY[], int dir);
void updateMap(char *** mapRef, int * y, int * x, int dirX[], int dirY[], int dir);
int startUser(char *** mapRef, int rowCount, int * seconds, int * remain_sec);
void updateAMatters(char ** aMatters, int * len);
void findSubatomicalPatterns(char**, int**, int, char**, int*);
int isGameWon(char * aMatters, int len);
void * countdown(void *);
void printOneUser(char * filename, User *);
void addScore(char * filename, const char *name, int score);
int compareScores(const void *a, const void *b);
void findTopScores(char * filename);
Queue *createQueue(unsigned capacity);
int isEmpty(Queue *queue);
void enqueue(Queue *queue, int row, int col, int distance);
Node dequeue(Queue *queue);
int isValidAuto(int row, int col, int ROW, int COL);
int isDestination(int row, int col, int destRow, int destCol);
void findShortestPath(int *** pathRef, int * coorCount, char ** map, int ROW, int COL);
void printMatters(char *, int);


#endif
