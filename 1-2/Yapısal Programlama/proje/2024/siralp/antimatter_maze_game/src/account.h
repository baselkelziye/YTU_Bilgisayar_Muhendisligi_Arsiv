#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <stdio.h>
#include <stdlib.h>

struct USER{
	char username[25];
	char name[25];
	char lastname[25];
	char password[25];
	int score;
	struct USER* next;
};

extern void mergeSort(struct USER**);
struct USER* merge(struct USER*,struct USER*);
void split(struct USER*,struct USER**,struct USER**);
extern struct USER* head;
extern _Bool readUserDatas();
extern _Bool saveUsers();
extern struct USER* findLastNode();
extern _Bool userRegister(char*,char*,char*,char*);
extern _Bool userLogin(char*);
extern struct USER* findUser(char*);
_Bool isUserExist(char*);
_Bool isPswValid(char*);
_Bool isNameValid(char*,char*);

#endif
