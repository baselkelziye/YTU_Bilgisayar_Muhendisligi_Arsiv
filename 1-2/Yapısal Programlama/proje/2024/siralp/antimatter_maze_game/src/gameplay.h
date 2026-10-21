#ifndef _GAMEPLAY_H_
#define _GAMEPLAY_H_

#define RIGHT_ARROW 77
#define LEFT_ARROW 75
#define UP_ARROW 72
#define DOWN_ARROW 80
#define ENTER_KEY 13
#define Q_KEY 113
#define R_KEY 114
#define BLACKHOLE -1
#define END 2
#define PROTON 80 		//P+
#define ANTIPROTON 112	//p-
#define ANTIELECTRON 69	//E+
#define ELECTRON 101	//e-

#include "gamefield.h"

extern int displayMenu();

int move(FIELD*,_Bool,int,char*,int*);
int _A_GAME_(FIELD*,_Bool);
int _M_GAME_(FIELD*,_Bool);
int calcPoints(char[],int);
#endif
