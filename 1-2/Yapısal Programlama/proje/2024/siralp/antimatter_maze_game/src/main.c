#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>
//--------------------//
#include "gamefield.h"
#include "gameplay.h"
#include "account.h"
#include "graph.h"

void mainMenu(struct USER*);
struct USER* loginMenu(void);
void printLeaderBoard(struct USER*);
void printRules(void);
//static struct USER* head;

int main(int argc, char *argv[]){
	
	if ( readUserDatas() )
		printf("\n\n\tReading from file completed!");
	else 
		printf("\n\n\tCouldn't read the datas!");
	Sleep(1000);
	
	struct USER* current = loginMenu();
	while ( current == NULL)
		current = loginMenu();
	mainMenu(current);
	return 0;
}

struct USER* loginMenu(){
	system("cls");
	printf("\33[?25l\n\t\t| Welcome to the Antimatter Lab |");
	printf("\t\t by Alperen TEKIN -21011010\n\n\n");
	
	struct SELECTION{
		unsigned int currentSelection:2; 
	};
	struct SELECTION cursor={0};
	char selector[3][75]={
		"\t\t       \33[31m\33[5m> Login <\33[0m\t\tSign up\t\t\t Forgot My Password \t\t",
		"\t\t\t Login\t\t     \33[31m\33[5m > Sign up <\33[0m\t\t Forgot My Password \t\t",
		"\t\t\t Login\t\t\tSign up\t\t     \33[31m\33[5m  > Forgot My Password <\33[0m \t\t"
	};
	printf("%s",selector[cursor.currentSelection]);
	int c;
	while( (c = getch()) != ENTER_KEY ){
		if(	c == RIGHT_ARROW){
			if(cursor.currentSelection == 2)
				cursor.currentSelection = 0;
			else cursor.currentSelection++;
		}
		if(	c == LEFT_ARROW){
			if(cursor.currentSelection == 0)
				cursor.currentSelection = 2;
			else cursor.currentSelection--;
		}
		printf("\33[2K\r");
		printf("%s",selector[cursor.currentSelection]);	
	}
	struct USER* current;
	_Bool success;
	char username[25],psw[25],name[25],lname[25];
	switch (cursor.currentSelection){
		case 0:
			system("cls");
			printf("\n\t\t| Welcome to the Antimatter Lab |");printf("\t\tby Alperen TEKIN -21011010\n\n\n");
			printf("\t\tUsername : ");
			scanf("%s",username);
			success = userLogin(username);
			if(success){
				current = findUser(username);
				Sleep(800);
				return current;				
			}
			return NULL;
		case 1:{
			system("cls");
			printf("\n\t\t| Welcome to the Antimatter Lab |");printf("\t\tby Alperen TEKIN -21011010\n\n\n");
			printf("\t\t\t Enter a username : "); scanf("%s",username);
			printf("\033[A\r\33[2K\r");
			printf("\t\t\t Enter a password : "); scanf("%s",psw);
			printf("\033[A\r\33[2K\r");
			printf("\t\t\t Enter your name : "); scanf("%s",name);
			printf("\033[A\r\33[2K\r");
			printf("\t\t\t Enter your last name : "); scanf("%s",lname);
			
			printf("\033[A\r\33[2K\r\t\t\tWelcome %s,\n\t\t\tPlease enjoy this beatiful screen while we register your account!");
			Sleep(1500);
			if ( userRegister(username,psw,name,lname)){
				printf("\n\t\tYou Have Registered Successfully !");
				current = findLastNode();
			}
			else return NULL;
			return current;
		}
		case 2:{
			system("cls");
			printf("\n\t\t| Welcome to the Antimatter Lab |");printf("\t\tby Alperen TEKIN -21011010\n\n\n");
			printf("\n\n\t\tTo Change Your Password We Will Need Some Information..");
			printf("\n\n\t\tWhat was your username ?: ");
			scanf("%s",username);
			current = findUser(username);
			if ( current == NULL) {
				printf("\n\t\tWe Couldn't Find %s in Our Database, You Register In Main Menu..");
				Sleep(2000);
				return NULL;
			}
			else {
				printf("\t\tYour Name : ");
				scanf("%s",name);
				printf("\t\tYour Last Name : ");
				scanf("%s",lname);
				if ( !strcmp(current->name,name) && !strcmp(current->lastname,lname) ){
					system("cls");
					printf("\n\t\t| Welcome to the Antimatter Lab |");
					printf("\t\tby Alperen TEKIN -21011010\n\n\n");
					printf("\n\n\t\tDatas are Matching!");
					Sleep(500);
					printf("\n\n\t\tEnter a new password : ");
					do{
						scanf("%s",psw);
						if ( !isPswValid(psw) ) 
							printf("\t\tPlease enter a valid password : ");
					}while(!isPswValid(psw));
					strcpy(current->password,psw);
					printf("\n\n\t\tYour password changed successfully!");
					Sleep(2000);
					return NULL;
				}
				else{
					printf("\n\n\t\tSorry, Informations You Gave aren't Matching with Our Datas.");
					Sleep(2000);
					return NULL;
				}
				
			}
			
			break;
		}
	}
	
}

void mainMenu(struct USER* user){
	int c,pointsEarned; 
	struct SELECTION{
		unsigned int currentSelection:2; 
	};

	
	
	struct SELECTION cursor ={0};
	char selector[4][95]={
		"\t    \33[31m\33[5m  > Start Game <\33[0m\t\tLeaderboard\t\tRules\t\tAccount Information\t  ",
		"\t\tStart Game\t    \33[31m\33[5m  > Leaderboard <\33[0m\t\tRules\t\tAccount Information\t  ",
		"\t\tStart Game\t\tLeaderboard\t      \33[31m\33[5m> Rules <\33[0m\t\tAccount Information\t  ",
		"\t\tStart Game\t\tLeaderboard\t\tRules\t      \33[31m\33[5m> Account Information <\33[0m\t  "
	};
	while(1){
		system("cls");
		printf("\33[?25l\n\t\t| Welcome to the Antimatter Lab |");printf("\t\tby Alperen TEKIN -21011010\n");
		printf("\t\t\t\t\t\t\t\tLogged in as %s\n\n",user->username);
		// left:72 ,right:77 , enter: 13
		printf("%s",selector[cursor.currentSelection]);
		while( (c = getch()) != ENTER_KEY ){
	
			if(c == LEFT_ARROW)
				cursor.currentSelection--;
			if(c == RIGHT_ARROW)
				cursor.currentSelection++;
			printf("\33[2K\r");
			printf("%s",selector[cursor.currentSelection]);	
		}
		switch(cursor.currentSelection){
			case 0:
				user->score += displayMenu();
				saveUsers();				
				break;
			case 1:
				mergeSort(&head);
				printLeaderBoard(head);
				printf("\n\n\t> Press ENTER to go back <");
				while( getch() != ENTER_KEY);
				break;
			case 2:
				printRules();
				printf("\n\n\t\t> Press ENTER to go back <");
				while( getch() != ENTER_KEY);
				break;
			case 3:
				system("cls");
				printf("\n\t\t| Welcome to the Antimatter Lab |");printf("\t\tby Alperen TEKIN -21011010\n\n\n");
				printf("\t\tCurrent Account Informations ");
				printf("\n\n\t%sUsername : %s\n\n\tName : %s\n\n\tLast Name : %s\n\n\tTotal Score : %d\n\n%s> Press ENTER to go back <",
				_C_WHITE,user->username,user->name,user->lastname,user->score,__RESET);
				while( getch() != ENTER_KEY);
				break;
		
		}
	}
}

void printLeaderBoard(struct USER* _head){
	int counter=0;
	system("cls");
	printf("\n\t\t| Welcome to the Antimatter Lab |");printf("\t\tby Alperen TEKIN -21011010\n\n\n");
	printf("\t\t\t\t\t%s$ Leaderboard $%s\n\n",__BLINK,__RESET);
	struct USER* iter = _head;
	while ( iter != NULL && counter <5 ){
		printf("\n\t\t\tNo.%d - %s%s\twith %d score%s",++counter, counter == 0 ? _C_RED : counter == 1 ? _C_YELLOW : counter == 2 ? _C_CYAN : _C_DEFAULT
		,iter->username,iter->score,__RESET);
		iter = iter->next;	
	}
}

void printRules(){
	system("cls");
	printf("\n\t\t| Welcome to the Antimatter Lab |");printf("\t\tby Alperen TEKIN -21011010\n\n\n");
	printf("\t\t\t\t\t%s$ Rules $%s",__BLINK,__RESET);
	printf("\n\t%s# You can move with Arrow Keys.",_C_CYAN);
	printf("\n\t# You can press 'Q' whenever you want to quit game. But remember this will cost you some points.");
	printf("\n\t# You can press 'R' whenever you want to restart the current game. But every restart costs you 5 points.");
	printf("\n\t%s----------------------------------------------------------------------------------------------------",_C_DEFAULT);
	printf("\n\t%s# You can select to play in Auto Mode , but AI is kinda sucks at the game and his behaviours seems random.",_C_CYAN);
	printf("\n\t# Check it out for yourself if you want to :)");
	printf("\n\t%s----------------------------------------------------------------------------------------------------",_C_DEFAULT);
	printf("\n\t%s# You will have 2 settings to play a game. Easy & Hard. Hard mode will limit you in terms of move limits.",_C_CYAN);
	printf("\n\t# But in return, if you success you will be awarded with more points than Easy Mode.");
	printf("\n\t%s----------------------------------------------------------------------------------------------------",_C_DEFAULT);
	printf("\n\t%s# You can choose the map you want to play! If you want to , you can add your map too!",_C_CYAN);
	printf("\n\t# All you need to is adding your map.txt file into maps folder. But be careful your file : ");
	printf("\n\t# Should has its sizes at the begining (e.g: 6x10) and a newline char followed by the map elements.%s"_C_DEFAULT);	
}
