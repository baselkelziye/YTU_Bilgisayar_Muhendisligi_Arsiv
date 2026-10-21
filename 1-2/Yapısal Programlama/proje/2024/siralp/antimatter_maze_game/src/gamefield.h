#ifndef _GAMEFIELD_H_
#define _GAMEFIELD_H_
#define MAX_STR 80

typedef struct{
	char **gameField;
	unsigned int fieldSize[2];
	unsigned int curLocation[2];
} FIELD;

extern void *readGameField(char *);
extern void displayGameField(FIELD *, int);
extern _Bool printMapsFolder(char *);

#endif
