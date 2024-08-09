#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <conio.h>

#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_WHITE   "\x1b[37m"

#define TIME_LIMIT 30
#define RIGHT 77
#define LEFT 75
#define UP 72
#define DOWN 80


typedef struct user{
	char name[30];
	char surname[30];
	char username[30];
	char password[30];
	int score;
}User;


void mainMenu();
void loginMenu(User user);
void mapMenu(User user);
void signUp(int numberOfUsers, int *userOrder, User *users);
void logIn(int numberOfUsers, int *userOrder, User *users);
void howToPlay();
int validPassword(User *users, int *userOrder ,char *password);
User* getUsersFromFile(int *numberOfUsers);
int isRegistered(User *users, int numberOfUsers, char *username, int *userOrder);
void saveUserToFile(User user);
User* getScoresFromFile(int *numberOfScores);
User *sortScores(User *scores, int numberOfScores);
void showScores();
char** createGameBoard(int rows, int columns);
void freeGameBoard(char** gameBoard, int rows);
int* findRowsAndColumns();
void loadMap(User user);
void chooseMap(User user);
void gameModeMenu(int *r_c, char *fileName, User user);
void fillBoard(char **board, char *fileName);
void printBoard(int rows, int columns, char **board, int currx, int currY, int elementNumber, char *elements);
int* findG(char **board,int rows, int columns);
void Play(char **board, int rows, int columns, User user, int mode);
int addElementToArray(char element, char *elements, int *elementNumber);
int isValidMove(char **board, int newX, int newY, int rows, int columns);
void saveScoreToFile(User user, int score);

int main() {
	
	mainMenu();
	
	return 0;
}


void mainMenu(){
	//oyun acilinca acilan ilk menu
	int choice;
	int numberOfUsers = 0, userOrder;
	
	do{
		User *users = getUsersFromFile(&numberOfUsers);
		printf("\n********* Main Menu *********\n\n");
		printf("1-Sign Up\n");
		printf("2-Log In\n");
		printf("3-Exit\n");
		printf("\npress any key from the menu to select option\n");
		printf("choice: ");
		
		do{
			scanf("%d",&choice);
			if(choice<1 || choice>3){
				printf("\nPlease enter a valid option:");
				scanf("%d",&choice);
			}
		}while(choice<1 || choice>3);
		
		switch(choice){
			case 1:
				signUp(numberOfUsers, &userOrder, users);
				system("cls");
				break;
				
			case 2:
				logIn(numberOfUsers, &userOrder, users);
				system("cls");
				break;
		}
		
	}while(choice!=3);
	
}

void loginMenu(User user){
	//oturum acdiktan sonra kullaniciyi karsilayan menu
	
	int choice;
	do{
		printf("\n1-Play the anti-hydrogen production maze game\n2-Top 5 User Score\n3-How To Play Game ?\n4-Back to previous menu\nChoice:");
		do{
			scanf("%d",&choice);
			if(choice<1 || choice>4){
				printf("\nPlease enter a valid choice.\n");
			}
		}while(choice<1 || choice>4);
		
		switch(choice){
			case 1:
				system("cls");
				mapMenu(user);
				system("cls");
				break;
			case 2:
				system("cls");
				showScores();
				printf("\n\nPRESS ANY KEY TO CONTINUE...");
				getch();
				system("cls");
				break;
			case 3:
				system("cls");
				howToPlay();
				printf("\n\nPRESS ANY KEY TO CONTINUE...");
				getch();
				system("cls");
				break;
		}
		
	}while(choice!=4);
}

void mapMenu(User user){
	//haritayi secmek mi yoksa yuklemek mi istedigini soran menu
	int choice;
	do{
		printf("\n1-Choose one of the available maps\n2-Load another map\n3-Back to previous menu\nChoice:");
		do{
			scanf("%d",&choice);
			if(choice<1 || choice>3){
				printf("\nPlease enter a valid choice.\n");
			}
		}while(choice<1 || choice>3);
		
		switch(choice){
			case 1:
				system("cls");
				chooseMap(user);
				system("cls");
				break;
			case 2:
				system("cls");
				loadMap(user);
				system("cls");
				break;
		}
		
	}while(choice!=3);
}

void chooseMap(User user){
	//haritayi secmek istediyse hangi haritayi secmek istedigini soran menu
	int choice;
	char fileName[30];
	int *rc;
	do{
		
		do{
			system("cls");
			printf("\n1-map1\n2-map2\n3-map3\n4-Back to previous menu\nChoice:");
			scanf("%d",&choice);
			if(choice<1 || choice>4){
				printf("\nPlease enter a valid choice.\n");
			}
		}while(choice<1 || choice>4);
		
		if(choice==1){
			strcpy(fileName, "maps\\choose\\map1.txt");
		}else if(choice==2){
			strcpy(fileName, "maps\\choose\\map2.txt");
		}else if(choice==3){
			strcpy(fileName, "maps\\choose\\map3.txt");
		}
		if(choice==1 || choice==2 || choice==3){
			rc= findRowsAndColumns(fileName);
			//printf("enter any key");
			//getch();
			system("cls");
			if(rc!=NULL){
				gameModeMenu(rc, fileName, user);
			}else{
				printf("\nunexpected error");
			}
		}
		if(choice==3){
			system("cls");
			printf("\nYOU JOKED!!!!! HAHAHAHAHHAHA");
			getch();
		}
		
	}while(choice!=4);
}

void loadMap(User user){
	//haritayi yuklemek istediyse yuklemek istedigi haritanin adini alip yukleyen fonksiyon
	char file[30];
	int *r_c;
	char fileName[30] = "maps\\load\\";
	printf("Enter your map file name: ");
	fflush(stdin);
	gets(file);
	strcat(fileName, file);
	r_c = findRowsAndColumns(fileName);
	getch();
	system("cls");
	if(r_c!=NULL){
		gameModeMenu(r_c, fileName, user);
	}else{
		printf("\nunexpected error");
	}
	
	
}

void gameModeMenu(int *r_c, char *fileName, User user){
	//bu menu manuel mi otomatik mi oynanacagini sectiriyor
	int choice, rows, columns;
	char **board;
	rows=*r_c;
	columns = *(r_c+1);
	do{
		board = createGameBoard(rows, columns);
		fillBoard(board, fileName);
		printf("\n1-Player control mode\n2-Computer auto mode\n3-Back to previous menu\nChoice:");
		do{
			scanf("%d",&choice);
			if(choice<1 || choice>3){
				printf("\nPlease enter a valid choice.\n");
			}
		}while(choice<1 || choice>3);
		
		switch(choice){
			case 1:
				Play(board, rows, columns, user,choice);
				break;
			case 2:
				Play(board, rows, columns, user, choice);
				break;
		}
		
	}while(choice!=3);
	freeGameBoard(board, rows);
}

void Play(char **board, int rows, int columns, User user, int mode){
	//Burasi oyunun oynandigi alan, mode otomaik mi manuel mi onu gosteriyor, 1 manuel 2 otomatik icin
	//daha sonra gelen tusa göre yeni konumu guncelliyor
	int *G_x_y = (int*)malloc(2*sizeof(int));
	int i, antiH=0, score;
	int currX;
	int currY;
	int finish=0;
	int Kfinish=0;
	int elementNumber=0;
	int newX, newY;
	char c, newElement;
	time_t start_time, current_time;
    double elapsed_time;
    int remainigTime;
	char *elements = (char*)malloc(100*sizeof(char));
	G_x_y=findG(board, rows, columns);
	currX = *G_x_y;
	currY = *(G_x_y+1);
	time(&start_time);
	do{
		printBoard(rows, columns, board, currX, currY, elementNumber, elements);
		printf("\n\n");
		time(&current_time);
		elapsed_time = difftime(current_time, start_time);
		remainigTime=TIME_LIMIT-(int)elapsed_time;
		printf("Remainig Time: %d sn",remainigTime);
		if(mode==1){
			c=getch();
		}else if(mode==2){
			usleep(500*1000);
			c=rand()%4;
			if(c==0){
				c=72;
			}else if(c==1){
				c=80;
			}else if(c==2){
				c=77;
			}else if(c==3){
				c==75;
			}
		}
		
		newX= currX;
		newY = currY;
		//gelen tusa gore konum guncelleme
		switch(c){
			case UP:
				newX--;
				break;
			case DOWN:
				newX++;
				break;
			case LEFT:
				newY--;
				break;
			case RIGHT:
				newY++;
				break;
		}
		//gidilen yer musait mi yoksa duvar ya da karadelik mi var onu kontrol eden bir fonksiyon
		if (isValidMove(board, newX, newY, rows, columns)) {
            newElement = board[newX][newY];
            elementNumber = addElementToArray(newElement, elements, &elementNumber);
            //addElement daha sonra antiHidrojen uretilip uretilmedigini tespit etmek ve her adýmda ekrana 
            //toplanan elementleri basmak icin tutulan bi element dizisi

            currX = newX;
            currY = newY;
            
            if (board[currX][currY] == 'K' || board[currX][currY] == 'C') {
            	//karadelige girip bitmesiyle cikisa girip bitmesi farkli oldugu icin kontrol ediyoruz
            	if(board[currX][currY] == 'C'){
            		finish=1;
				}else if(board[currX][currY] == 'K'){
					Kfinish=1;
				}
				board[currX][currY] = 'X';
				//guncel labirenti ekrana basiyoruz
				printBoard(rows, columns, board, currX, currY, elementNumber, elements);
	            printf("\n\nGame Over!\n");
        	}
        	if(finish!=1 && Kfinish!=1){
        		board[currX][currY] = '0';
			}
        	//element alindýysa yerine 0 koyuyoruz
            
        }
        
		
	}while(c!=27 && remainigTime>0 && finish!=1 && Kfinish!=1);
    //uretilen antiH sayisini hesaoliyoruz ve skoru ekrana basiyoruz
    antiH = calculateAntiH(elements, elementNumber);
    if(Kfinish!=1){
    	score= antiH*remainigTime;
		printf("\nYou produced %d Anti-Hydrogen\n",antiH);
		printf("Your score is %d", score);
    }else{
    	score= 0;
		printf("\nYou produced %d Anti-Hydrogen but you entered blackhole\n",antiH);
		printf("Your score is %d", score);
	}
	//score scores dosyasýna kaydediyoruz.
	saveScoreToFile(user, score);
	
}

void saveScoreToFile(User user, int score){
	FILE *fp=fopen("scores.txt", "a");
	if(fp==NULL){
		printf("\nFile open error");
		return;
	}
	
	fprintf(fp, "%s\n%d\n\n",user.username, score);
	
	fclose(fp);
}

int calculateAntiH(char *elements, int elementNumber){
	int P=0, p=0, E=0, e=0, i, antiH=0;
	if(elementNumber<2){
		return 0;
	}else{
		for(i=0;i<elementNumber;i++){
			if(elements[i]=='P'){
				P++;
			}else if(elements[i]=='p'){
				p++;
			}
			else if(elements[i]=='E'){
				E++;
			}
			else if(elements[i]=='e'){
				e++;
			}
		}
		while(p>0 && P>0){
			p--;
			P--;
		}
		while(e>0 && E>0){
			e--;
			E--;
		}
		while(p>0 && E>0){
			p--;
			E--;
			antiH++;
		}
		
		return antiH;
	}
}

int isValidMove(char **board, int newX, int newY, int rows, int columns) {
	//duvar ya da tahtanin disi degilse haraket eddebilir diyor
    if (newX < 0 || newX >= rows || newY < 0 || newY >= columns) {
        return 0;
    }
    if (board[newX][newY] == '1') {
        return 0;
    }
    return 1;
}

int addElementToArray(char element, char *elements, int *elementNumber) {
	
	int i=*elementNumber;
    if (element == 'P' || element == 'p' || element == 'E' || element == 'e') {
        elements[i++] = element;
    }
    *elementNumber=i;
    return *elementNumber;
}

int* findG(char **board,int rows, int columns){
	//G nin tahtanin neresinde oldugunu bulup X i oraya yerlestirmek icin
	int *G_x_y;
	G_x_y = (int*)malloc(2*sizeof(int));
	int i, j;
	for(i=0;i<rows;i++){
		for(j=0;j<columns;j++){
			if(board[i][j]=='G'){
				*G_x_y=i;
				*(G_x_y+1)=j;
			}
		}
	}
	return G_x_y;
}

void fillBoard(char **board, char *fileName){
	//board matrisini dosyadan cektigimiz harita ile dolduruyoruz
	FILE *fp = fopen(fileName, "r");
	char c;
	int i=0,j=0;
	if(fp == NULL){
		printf("\nFile could not open.");
		return;
	}else{
		
		do {
			c = fgetc(fp);
			if(c=='\n'){
				i++;
				j=0;
			}
			if(c!=' ' && c!='\n'){
				board[i][j] = c;
				j++;
			}
		}while(!feof(fp));

		fclose(fp);
	}
}

void printBoard(int rows, int columns, char **board, int currX, int currY, int elementNumber, char *elements) {
	//renkli bir sekilde ekrana oyun alaninin guncel durumunu basar
    system("cls");
    char cell;
    int i, j;
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < columns; ++j) {
            cell = board[i][j];
            if (i == currX && j == currY) {
                printf(ANSI_COLOR_MAGENTA "X " ANSI_COLOR_RESET);
            } else {
                switch (cell) {
                    case '1':
                        printf(ANSI_COLOR_WHITE "1 " ANSI_COLOR_RESET);
                        break;
                    case '0':
                        printf(ANSI_COLOR_GREEN "0 " ANSI_COLOR_RESET);
                        break;
                    case 'K':
                        printf(ANSI_COLOR_RED "K " ANSI_COLOR_RESET);
                        break;
                    case 'G':
                        printf(ANSI_COLOR_BLUE "G " ANSI_COLOR_RESET);
                        break;
                    case 'C':
                        printf(ANSI_COLOR_YELLOW "C " ANSI_COLOR_RESET);
                        break;
                    case 'P':
                        printf(ANSI_COLOR_CYAN "P " ANSI_COLOR_RESET);
                        break;
                    case 'p':
                        printf(ANSI_COLOR_CYAN "p " ANSI_COLOR_RESET);
                        break;
                    case 'E':
                        printf(ANSI_COLOR_CYAN "E " ANSI_COLOR_RESET);
                        break;
                    case 'e':
                        printf(ANSI_COLOR_CYAN "e " ANSI_COLOR_RESET);
                        break;
                    default:
                        printf("%c ", cell);
                        break;
                }
            }
        }
        printf("\n");
    }
    printf("\nCollected Elemets Number: %d",elementNumber);
    printf("\nCollected Elements: ");
    for(i=0;i<elementNumber;i++){
    	printf("%c ",elements[i]);
	}
}

int* findRowsAndColumns(char *fileName, char **board){
	//tahtayi dinamik sekilde olusturmak icin dosyadan cekilen haritanin n ve m degerini hesaplar
	//bunu rows_columns adli pointerda tutar ilk degeri rows ikinci degeri columnsdur
	//fileName= "test.txt";
	FILE *fp = fopen(fileName, "r");
	char c;
	int *rows_columns = (int*)malloc(2*sizeof(int));
	int rows=0, columns=0;
	if(fp == NULL){
		printf("\nFile could not open.");
		return NULL;
	}else{
		
		do {
			c = fgetc(fp);
			if(c!='\n' && rows==0){
				columns++;
			}
			if(c=='\n'){
				//printf("1");
				rows++;
			}
			//printf("%c", c);
		}while(!feof(fp));
		rows++;
		columns=(columns+1)/2;
		//printf("\n%d",rows);
		//printf("\n%d",columns);
		fclose(fp);
	}
	*rows_columns=rows;
	*(rows_columns+1)=columns;
	
	return rows_columns;
}

User* getScoresFromFile(int *numberOfScores){
	//en yuksek skorlari gostermek icin daha once kaydedilen skorlari dosyadan ceker ve users isimli diziyi tutar
	//bu dizide sadece username ve score alani kullaniliyor diger oturum acma users dizisinden farklý 
	//bu halihazirda isimi gordugu icin bunu kullandým yeni bir struct tanimlamadim
	int counter=0, i;
	char buff[30];
	
	FILE *fp = fopen("scores.txt", "r");
	
	User *users;
	
	if(fp == NULL){
		printf("\nFile could not open.");
		return;
	}else{
		if(fgets(buff, 30, fp) == NULL){
			printf("dosya bos hic score yok");
			return NULL;
		}
		
		fseek(fp, 0, SEEK_SET);
		while(fgets(buff,30,fp) != NULL){
			counter++;
		}
		//once kac kayit var sayisi bulunuyor daha sonra bu sayi kadar yer acilip dolduruluypr
		//3 e bolmemin sebebi bilgileri alt alta ve bir bosluk ile tutuyorum username score bosluk
		*(numberOfScores) = counter/3;
		users = (User*)malloc((*(numberOfScores)) * sizeof(User));
		if (users == NULL) {
            printf("\nMemory allocation failed.");
            fclose(fp);
            return NULL;
        }
        fseek(fp, 0, SEEK_SET);
        for (i = 0; i < *(numberOfScores); i++) {
            fgets((*(users+i)).username, 30, fp);
            fscanf(fp, "%d", &(*(users+i)).score);
			fgets(buff, 30, fp);
			fgets(buff, 30, fp);
			
			(*(users+i)).username[strcspn(users[i].username, "\n")] = '\0';
        }
		
		fclose(fp);
		
		return users;
	}
}

void showScores(){
	int numberOfScores, i;
	
	User *scores = getScoresFromFile(&numberOfScores);
	scores = sortScores(scores, numberOfScores);
	
	printf("---------Best 5 Scores Table---------\n\n");
	
	if(numberOfScores==0){
		printf("no games played yet.");
		
	}else if(numberOfScores<5){
		printf("    Usernames  |  scores\n\n");
		for(i=0;i<numberOfScores;i++){
			printf("%d %12s |  %2d\n",i+1 ,scores[i].username, scores[i].score);
		}
	}else{
		printf("    Usernames  |  scores\n\n");
		for(i=0;i<5;i++){
			printf("%d %12s |  %2d\n",i+1 ,scores[i].username, scores[i].score);
		}
	}
}

User *sortScores(User *scores, int numberOfScores){
	//en yuksek 5 skoru gostermek icin
	int i, j;
	char tempUsername[30];
	int tempScore;
	
	for(i=0;i<numberOfScores-1;++i){
		for(j=0;j<numberOfScores-i-1;++j){
			if(scores[j].score<scores[j+1].score){
				
				strcpy(tempUsername, scores[j].username);
				tempScore = scores[j].score;
				
				strcpy(scores[j].username, scores[j+1].username);
				scores[j].score = scores[j+1].score;
				
				strcpy(scores[j+1].username, tempUsername);
				scores[j+1].score = tempScore;
			}
		}
	}
	return scores;
}

void howToPlay(){
	printf("\t\t\tHow To Play\n\nThis is an anite hydrogen particle generation maze game.\n");
	printf("There are subatomic particles on the paths in the maze.");
	printf("The user starts the game from the specified entry point and \nprogresses towards the exit point.");
	printf("From the paths of the labyrinth antihydrogen will be produced using the collected \nsubatomic particles.");
	printf("Things to follow while moving through the labyrinth the rules and particles in the maze\nare listed below:");
	printf("\n\n# The following particles are on the paths in the maze.\n\nP+ : proton\ne-: electron\nP-: antiproton\ne+ : antielectron");
	printf("\n\n# In order to produce antihydrogen, you must have only P- and e+ particles at the exit of the maze.");
	printf("\n\n# If a particle and its antiparticle with the opposite sign come together, they annihilate each other.");
	printf("\n\n# Black holes are denoted by K. If you pass through the cells containing black holes, the game ends.");
	printf("\n\n# If the user cannot reach the exit within a certain game time, the game ends.");
	printf("\n\n# The game can be played in user-controlled and auto play mode.");
	printf("\n\n# The user should be able to play by choosing one of the ready-made maps or download a map of his/her choice.");
	printf("\n\n# In user control mode, the game is played by the user by going in four directions of his choice.");
	printf("Arrow keys are used\nto navigate the maze. The user is denoted by x in the game. ");
	printf("The user can exit the game at any time by pressing\nthe esc key.");
	printf("");
	printf("");
	printf("");
}

void logIn(int numberOfUsers, int *userOrder, User *users){

	User user;
	int choice;
	if(numberOfUsers==0){
		printf("No users have registered yet, please sign up first");
		signUp(numberOfUsers,userOrder, users);
	}else{
		
		do{
			fflush(stdin);
			printf("Please enter your username:");
			gets(user.username);
			
			if(isRegistered(users, numberOfUsers, user.username, userOrder)==2){
				printf("There is no such username. Try again or sign up\n");
				printf("1-Try again\n2-Sign Up\nChoice: ");
				scanf("%d",&choice);
				if(choice==2){
					signUp(numberOfUsers,userOrder, users);
					users = getUsersFromFile(&numberOfUsers);
					printf("\nContinue to log in.....\n");
				}
			}
			
			
		}while(isRegistered(users, numberOfUsers, user.username, userOrder)==2);
		//kullanici adi sistemde kayitli mi degil mi onu kontrol ediyoruz
		//degilse kayit ol diyoruz ya da yanlis girme ihtimaline karsi yeniden girmek ister misin diye soruyouz
		
		
		//sistemde tespit ettiysek sifresini kontrol ediyoruz
		if(isRegistered(users, numberOfUsers, user.username, userOrder)==1){
			do{
				printf("Please enter your password:");
				gets(user.password);
				if(validPassword(users, userOrder, user.password)!=1){
					printf("\nThe password you entered is incorrect.\n");
				}
			}while(validPassword(users, userOrder, user.password)!=1);
			
			printf("Successfully logged in....Press any key to continue...");
			getch();
			system("cls");
			loginMenu(user);
		}
	}
}

int validPassword(User *users, int *userOrder ,char *password){
	//verilen users listesindeki userorder sirasinda bulunan password ile parametre olarak gelen password
	//eslesiyor mu onu kontrol edip donuyor
	if(strcmp((*(users+(*(userOrder)))).password,password)==0){
		return 1;
	}else{
		return 0;
	}
}

void signUp(int numberOfUsers, int *userOrder, User *users){
	//kayit olma ekrani sistemde yoksa olusturup kayit ediyo varsa baska kullanici adi almasini istiyor
	User user;
	fflush(stdin);
	printf("\nEnter your name: ");
	gets(user.name);
	
	printf("\nEnter your surname: ");
	gets(user.surname);
	
	do{
		printf("\nEnter your username: ");
		gets(user.username);
		
		if(isRegistered(users, numberOfUsers, user.username, userOrder)==1){
			printf("\nThere is someone with this username, try another one: ");
		}
	}while(isRegistered(users, numberOfUsers, user.username, userOrder)==1);
	
	printf("\nEnter your password: ");
	gets(user.password);
	
	user.score=0;
	saveUserToFile(user);
	
	
}

void saveUserToFile(User user){
	FILE *fp = fopen("users.dat", "ab");
	if(fp==NULL){
		printf("\nFile open error");
		return;
	}
	fwrite(&user, sizeof(User), 1, fp);	
	//printf("\nsuccessfully saved to file");
	fclose(fp);
}

int isRegistered(User *users, int numberOfUsers, char *username, int *userOrder){
	int i=0, match=0;
	
	if(numberOfUsers==0){
		//printf("hic kullanici yok o yuzden sikinti yok");
		return 0;
	}
	while((i<numberOfUsers) && (match!=1)){
		if(strcmp((*(users+i)).username, username)==0)
			match=1;
			*userOrder=i;
		i++;
	}
	if(match==0){
		//printf("\nkullanici adi alinabilir");
		return 2;
	}else{
		//printf("\nbu kullanici adi alinmis");
		return 1;
	}
}

User* getUsersFromFile(int *numberOfUsers){
	int counter=0, i;
	char buff[30];
	
	FILE *fp = fopen("users.dat", "rb");
	
	User *users;
	
	if(fp == NULL){
		//printf("\nFile could not open.");
		return;
	}else{
		fseek(fp, 0, SEEK_END);
	    long fileSize = ftell(fp);
	    fseek(fp, 0, SEEK_SET);
	
	    *numberOfUsers = fileSize / sizeof(User);
	
	    if (*numberOfUsers == 0) {
	        printf("No users have registered yet.\n");
	        fclose(fp);
	        return NULL;
	    }
	
	    User *users = (User *)malloc(sizeof(User) * (*numberOfUsers));
	    if (users == NULL) {
	        printf("\nMemory allocation failed.");
	        fclose(fp);
	        return NULL;
	    }
	
	    fread(users, sizeof(User), *numberOfUsers, fp);
	    fclose(fp);
	    return users;
	}
}

char** createGameBoard(int rows, int columns){
	char **gameBoard = (char**)malloc(rows*sizeof(char*));
	int i;
	if(gameBoard != NULL){
		for(i=0;i<rows;i++){
			gameBoard[i] = (char*)malloc(columns*sizeof(char));
			if(gameBoard[i] == NULL){
				printf("\nThe game board could not be created successfully..");
				exit(1);
			}
		}
	}
	return gameBoard;		
}

void freeGameBoard(char** gameBoard, int rows){
	int i;
	for(i=0;i<rows;i++){
		free(gameBoard[i]);
	}
	free(gameBoard);
	printf("\nboard was successfully released");
}


