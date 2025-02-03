#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h> 
#include<time.h>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1b[37m"
#define RESET   "\x1b[0m"

typedef struct user{
	char name[20];
	char surname[20];
	char userName[20];
	char password[20];
}USER;

typedef struct score{
	char userName[20];
	int score;
}SCORE;

void menu();
void submenu(char *userName);
void showTopScores(char *userName);
SCORE* getTopScoresFromFile();
void saveScore(char *userName, int score);
void saveTopScoresToFile(SCORE *scores);
SCORE* sortTopScores(SCORE *scores);;
void showHowToPlay(char *userName);
void playGame(char **board, int row, int column, char *userName,int gameMode);
int calculateScore(char *collectedItems, int itemCounter);
void printCollectedItems(char *collectedItems, int itemCounter);
char move(char **board, int rowNumber, int colNumber, int *curRow, int *curCol, int moveRow, int moveCol);
char** selectMap(int *row, int *column);
char** getMapFromFile(int mapCode,char customMapName[20],int *rowNumber, int *columnNumber);
void selectGameMode();
void login();
void userRegister();
int passwordConfirmation(char userName[20],char password[20]);
int isUserRegistered(char userName[20]);
void saveUserToFile(USER user);
void printBoard(char **board,int row,int column);

int main(){ 
	srand(time(NULL));
	menu();
}

void menu(){
	int choice;
	system("cls");
	printf(CYAN"----- Welcome -----"RESET"\n"GREEN"1-"RESET" Log in\n"GREEN"2-"RESET" Sign up\nChoice: ");
	scanf("%d",&choice);
	
	if(choice==1){
		system("cls");
		login();
	}
	else{
		system("cls");
		userRegister();
	}	
}

void submenu(char *userName){
	int choice;
	system("cls");
	printf(CYAN"------ Menu ------"RESET"\n"GREEN"1-"RESET" Play Game\n"GREEN"2-"RESET" How to Play\n"GREEN"3-"RESET" Top Scores\n"GREEN"4-"RESET" Log out\nChoice: ");
	scanf("%d",&choice);
	
	switch(choice){
		case 1:
			selectGameMode(userName);
			break;
		case 2:
			showHowToPlay(userName);
			break;
		case 3:
			showTopScores(userName);
			break;
		case 4:
			menu();
			break;
	}	
}

void showTopScores(char *userName){
	int i=0, choice;
	SCORE *scores=getTopScoresFromFile();
	scores=sortTopScores(scores);

	system("cls");
	printf(CYAN"------ Top Scores ------\n"RESET);
	while(scores[i].score!=0){
		printf(GREEN"%d-"RESET" %s %d\n",i+1,scores[i].userName,scores[i].score);
		i++;
	}
	
	printf("\n\nPress 0 to return to menu: ");
	scanf("%d",&choice);
	if(choice==0)
		submenu(userName);
}

SCORE* getTopScoresFromFile(){
	SCORE *scores=(SCORE*)calloc(5,sizeof(SCORE));
	char userName[30];
	int i=0, score;
	FILE *fp=fopen("topscores.txt","r");

	while(fscanf(fp,"%s %d",userName,&score)==2){
		strcpy(scores[i].userName,userName);
		scores[i].score=score;
		i++;
	}
	
	fclose(fp);
	
	return scores;
}

void saveScore(char *userName, int score){
	int i, minScore=0, minIndex;
	SCORE currentScore;
	SCORE *tmpScore;
	SCORE *scores=getTopScoresFromFile();
	
	for(i=0;i<5;i++){
		if(scores[i].score==0){
			strcpy(scores[i].userName,userName);
			scores[i].score=score;
			saveTopScoresToFile(scores);
			return;
		}
	}
	
	minScore=scores[0].score;
	minIndex=0;
	for(i=1;i<5;i++){
		if(scores[i].score<minScore){
			minScore=scores[i].score;
			minIndex=i;
		}
	}
	
	if(score>minScore){
		scores[minIndex].score=score;
		strcpy(scores[minIndex].userName,userName);
	}
	
	saveTopScoresToFile(scores);
}

void saveTopScoresToFile(SCORE *scores){
	int i=0;
	FILE *fp=fopen("topscores.txt","w");
	
	while(scores[i].score!=0){
		fprintf(fp,"%s %d\n",scores[i].userName,scores[i].score);
		i++;
	}
	
	fclose(fp);	
}

SCORE* sortTopScores(SCORE *scores){
	int i,j;
	
	for (i=0;i<4; ++i){
        for (j=0;j<4-i-1;++j){
            if (scores[j].score < scores[j + 1].score){
                SCORE temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
            }
        }
    }
    return scores;
}

void showHowToPlay(char *userName){
	int choice;
	system("cls");
	printf(CYAN"------- Antimatter Labyrinth --------"RESET"\n"GREEN"-"RESET"Get a high score by collecting as many antiprotons and antielectrons as possible in the maze within the given time.\n"GREEN"-"RESET"Remember that the proton and its opposite cancel each other out. The same goes for electrons.\n"GREEN"-"RESET"There are black holes in some places in the labyrinth. If you enter them, the game will end and you will be considered unsuccessful.\n"GREEN"-"RESET"To successfully complete the game, you must either reach the location marked 'C' or wait for the time to expire.\n"RED"-- Good Luck --"RESET);
	printf("\n\nPress 0 to return to menu: ");
	scanf("%d",&choice);
	if(choice==0)
		submenu(userName);
}

void playGame(char **board, int row, int column, char *userName,int gameMode){
	int i, j, curRow, curColumn, remainingTime=30, itemCounter=0, score=0, winControl=1, randomNumber, choice;
	time_t startTime, curTime;
	char direction, collectedElement, collectedItems[20];
	
	system("cls");
	
	for(i=0;i<row;i++){ // x in yerini belirleme
		for(j=0;j<column;j++){
			if(board[i][j]=='G'){
				curRow=i;
				curColumn=j;
			}
		}
	}
	
	time(&startTime); 
	
	while(remainingTime>=0){
		printBoard(board,row,column);
		printf("Time:%d\n",remainingTime);
		printCollectedItems(collectedItems,itemCounter);
		
		if(!gameMode){ // manuel mode
			direction=getch();
		}
		else{          // auto mode
			randomNumber=rand()%4;
			switch(randomNumber){
				case 0:
					direction=72;
					break;
				case 1:
					direction=80;
					break;
				case 2:
					direction=77;
					break;
				case 3:
					direction=75;
					break;
			}
			usleep(200000);
		}
		
		collectedElement=' ';
		if((int)direction==72)      // up
			collectedElement=move(board,row,column,&curRow,&curColumn,-1,0);
		else if((int)direction==80) //down
			collectedElement=move(board,row,column,&curRow,&curColumn,1,0);
		else if((int)direction==77) //right
			collectedElement=move(board,row,column,&curRow,&curColumn,0,1);
		else if((int)direction==75) //left
			collectedElement=move(board,row,column,&curRow,&curColumn,0,-1);
		
		time(&curTime); 
		remainingTime=30-curTime+startTime;
		
		if(collectedElement=='C' || collectedElement=='K'){
			remainingTime=-1;
			if(collectedElement=='K')
				winControl=0;
		}
		else if(collectedElement!=' ' && collectedElement!='0')
			collectedItems[itemCounter++]=collectedElement;
			
		if(direction==27){
			remainingTime=-1;
			winControl=0;
		}
		
		system("cls");
	}
	
	if(winControl){
		score=calculateScore(collectedItems,itemCounter);
		saveScore(userName,score);
		printf("\nMission Completed. %d antihydrogen were produced.\n\t  "CYAN"------ "RED"Score: %d"CYAN" ------"RESET,score,score);
	}
	else{
		if(direction==27)
			printf("\nMission failed! You escaped.\n  "CYAN"------ "RED"Score: 0"CYAN" ------"RESET);
		else
			printf("\nMission failed! You had fallen into black hole.\n\t"CYAN"------ "RED"Score: 0"CYAN" ------"RESET);
	}
	
	printf("\n\nPress 0 to return to menu: ");
	scanf("%d",&choice);
	if(choice==0)
		submenu(userName);
}

int calculateScore(char *collectedItems, int itemCounter){
	int i, proton=0, antiProton=0, electron=0, antiElectron=0, antiHydrogen=0;
	
	for(i=0;i<itemCounter;i++){
		switch(collectedItems[i]){
			case 'P':
				proton++;
				break;
			case 'p':
				antiProton++;
				break;
			case 'e':
				electron++;
				break;
			case 'E':
				antiElectron++;
				break;
				
		}
	}
	
	while(proton>0 && antiProton>0){
		proton--;
		antiProton--;
	}
	
	while(electron>0 && antiElectron>0){
		electron--;
		antiElectron--;
	}
	
	while(antiElectron>0 && antiProton>0){
		antiElectron--;
		antiProton--;
		antiHydrogen++;
	}
		
	return antiHydrogen;
}

void printCollectedItems(char *collectedItems, int itemCounter){
	int i;
	printf("Collected Items: ");
	for(i=0;i<itemCounter;i++){
		printf("%c ",collectedItems[i]);
	}
}

char move(char **board, int rowNumber, int colNumber, int *curRow, int *curCol, int moveRow, int moveCol){
	char targetElement;
	
	if(*curRow+moveRow>rowNumber-1 || *curRow+moveRow<0)
		return ' ';
	if(*curCol+moveCol>colNumber-1 || *curCol+moveCol<0)
		return ' ';
	
	targetElement=board[*curRow+moveRow][*curCol+moveCol];
	if(targetElement=='1')
		return ' ';
	
	board[*curRow][*curCol]='0';
	*curRow=*curRow+moveRow;
	*curCol=*curCol+moveCol;
	board[*curRow][*curCol]='X';
	return targetElement;
}

char** selectMap(int *row, int *column){
	int choice;
	char fileName[20];
	char **board;
	system("cls");
	printf(CYAN"----- Map Selection -----"RESET"\n"GREEN"1-"RESET" Standart Maps\n"GREEN"2-"RESET" Custom Maps\nChoice: ");
	scanf("%d",&choice);
	
	if(choice==1){
		printf(GREEN"1-"RESET" 4x7 Map\n"GREEN"2-"RESET" 6x10 Map\n"GREEN"3-"RESET" 7x11 Map\nChoice: ");
		scanf("%d",&choice);
		board=getMapFromFile(choice,NULL,row,column);
	}
	else if(choice==2){
		printf("Please enter text name (Ex: custom.txt)\n");
		scanf("%s",fileName);
		board=getMapFromFile(0,fileName,row,column);
	}
	
	return board;
}

char** getMapFromFile(int mapCode,char customMapName[20],int *rowNumber, int *columnNumber){
	int i=0, j=0, column=0;
	char buf[30], fileName[20], **board;
	FILE *fp;
	
	if(mapCode==0){
		sprintf(fileName,"%s",customMapName);
	}
	else{
		sprintf(fileName,"map%d.txt",mapCode);
	}
	fp=fopen(fileName,"r");
	
	if(fp==NULL){
		printf("File couldn't open!");
	}
	
	while(fgets(buf,29,fp)!=NULL){         //satir sayisini belirleme
		*rowNumber=*rowNumber+1;
	}
	*columnNumber=strlen(buf)/2+1;          //sutun sayýsýný belirleme
	
	board=(char**)calloc(*rowNumber,sizeof(char*));         //memory allocation
	for(i=0;i<*rowNumber;i++){
		board[i]=(char*)calloc(*columnNumber,sizeof(char));
	}
	
	fseek(fp, 0, SEEK_SET);        // fp pointerý dosyanýn basina gonderme
	
	i=0;
	while(fgets(buf,29,fp)!=NULL){
        j=0;
        column=0;
		while(buf[j]!='\0'){
			if(buf[j]!=' '){
        		board[i][column]=buf[j];
        		column++;
			}
			j++;
		}
		i++;
    }  
  	fclose(fp);
  	
	return board;
}

void selectGameMode(char *userName){
	int choice, row=0, column=0;
	char **board=selectMap(&row,&column);
	
	printf(CYAN"-------Game Mode--------"RESET"\n"GREEN"1-"RESET" Manuel Mode\n"GREEN"2-"RESET" Auto Mode\nChoice: ");
	scanf("%d",&choice);
	if(choice==1){
		playGame(board,row,column,userName,0); // 0 represents manuel mode
	}
	else{
		playGame(board,row,column,userName,1); // 1 represents auto mode
	}	
}

void login(){
	int choice;
	char userName[20], password[20];
	printf(CYAN"-------LOGIN--------"RESET"\n"YELLOW"Username: "RESET);
	scanf("%s",userName);
	
	printf(YELLOW"Password: "RESET);
	scanf("%s",password);
	
	if(isUserRegistered(userName) && passwordConfirmation(userName,password)){
		printf(RED"Logged in successfuly"RESET);
		usleep(500000);
		system("cls");
		submenu(userName);
		return;
	}
	
	printf(RED"\nUser was not found!\n"GREEN"1-"RESET" If you don't have an account, sign up now\n"GREEN"2-"RESET" Try again to login\nChoice: ");
	scanf("%d",&choice);
	if(choice==1){
		system("cls");
		userRegister();
	}
	else{
		system("cls");
		login();
	}
}

void userRegister(){
	int control=1;
	char tmp[20];
	//USER *newUser=(USER*)calloc(1,sizeof(USER));
	USER newUser;
	
	printf(CYAN"-------SIGN UP--------"RESET"\n"YELLOW"Name: "RESET);
	scanf(" %[^\n]",tmp);
	strcpy(newUser.name,tmp);
	
	printf(YELLOW"Surname: "RESET);
	scanf("%s",tmp);
	strcpy(newUser.surname,tmp);
	
	while(control){
		control=0;
		printf(YELLOW"Username: "RESET);
		scanf("%s",tmp);
		if(isUserRegistered(tmp)){
			printf(RED"There is already a user with same username! Please, enter a unique username\n"RESET);
			control=1;
		}
		strcpy(newUser.userName,tmp);
	}
	
	printf(YELLOW"Password: "RESET);
	scanf("%s",tmp);
	strcpy(newUser.password,tmp);
	
	saveUserToFile(newUser);
	system("cls");
	menu();
}

int passwordConfirmation(char userName[20],char password[20]){ // if user's password is correct returns 1 otherwise 0
	USER user;
	
	FILE *dosya = fopen("userData.dat", "rb");
    
    while (fread(&user, sizeof(USER), 1, dosya) == 1) {
		if(strcmp(userName,user.userName)==0 && strcmp(user.password,password)==0){
			return 1;
		}
    }
    fclose(dosya);
    return 0;
}

int isUserRegistered(char userName[20]){ // if user has registered returns 1 otherwise 0
	USER user;
	
	FILE *dosya = fopen("userData.dat", "rb");
    
    while (fread(&user, sizeof(USER), 1, dosya) == 1) {
		if(strcmp(userName,user.userName)==0){
			return 1;
		}
    }
    fclose(dosya);
    return 0;
}

void saveUserToFile(USER user){
	FILE *fp;
	fp=fopen("userData.dat","ab");
	
	fwrite(&user,sizeof(USER),1,fp);
	//fprintf(fp,"%s,%s,%s,%s\n",user->name,user->surname,user->userName,user->password);
	
	fclose(fp);
}

void printBoard(char **board,int row,int column){
    int i, j;
    printf("+");
    for (j = 0; j < column; j++) {
        printf("---+");
    }
    printf("\n");
    
    for (i = 0; i < row; i++) {
        printf("|");
        for (j = 0; j < column; j++) {
        	switch(board[i][j]){
        		case '1':
        			printf(GREEN" %c "RESET"|", board[i][j]);
        			break;
        		case '0':
        			printf(CYAN" %c "RESET"|", board[i][j]);
        			break;
        		case 'p':
        			printf(BLUE" %c "RESET"|", board[i][j]);
        			break;
        		case 'P':
        			printf(BLUE" %c "RESET"|", board[i][j]);
        			break;
        		case 'E':
        			printf(YELLOW" %c "RESET"|", board[i][j]);
        			break;
        		case 'e':
        			printf(YELLOW" %c "RESET"|", board[i][j]);
        			break;
        		case 'G':
        			printf(RED" %c "RESET"|", board[i][j]);
        			break;
        		case 'C':
        			printf(RED" %c "RESET"|", board[i][j]);
        			break;
        		case 'X':
        			printf(RED" %c "RESET"|", board[i][j]);
        			break;
        		default:
        			printf(" %c |", board[i][j]);
			}
        }
        printf("\n+");

        for (j = 0; j < column; j++) {
            printf("---+");
        }
        printf("\n");
    }
}

