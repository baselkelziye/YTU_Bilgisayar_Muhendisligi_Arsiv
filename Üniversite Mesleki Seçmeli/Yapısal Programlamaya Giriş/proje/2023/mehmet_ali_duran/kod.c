#include<stdio.h>
#include<time.h>
#include<string.h>
#include<windows.h>
#define MAX 15
#define MOVE_LIMIT 150


void mainMenu(void);
void gameMenu(int matrix[][MAX], int *p_gameMode, int *p_matrixMode, int scores[MAX], int *p_userNum);
void drawBoard(int matris[][MAX], int N);
void readFromFile(int matris[][MAX], char *fileName);
void generRandomMatrix(int matrix[][MAX], int N);
void showScores(char users[][20], int scores[], int *p_userNum);
int calcScore(int N, int *p_gameMode, int *p_matrixMode, int *p_undoCounter, int gameTime);
void playManuel(int matrix[][MAX], int N, int *p_gameMode, int *p_matrixMode, int scores[MAX], int *p_userNum);
int finishControl(int matrix[][MAX], int N);
void connectDot(int matrix[][MAX], int N);
void pushMove(int matrix[][MAX], int records[][MAX*MAX], int N, int *top);
void popMove(int matrix[][MAX], int records[][MAX*MAX], int N, int *top);
int findUser(char users[][20], int *p_userNum, char *user);
void userAdd(char users[][20], int *p_userNum);
void matrixZero(int matrix[][MAX]);
void playAuto(int matrix[][MAX], int N, int *p_gameMode, int *p_matrixMode, int scores[MAX], int *p_userNum);

int main(){
	
    mainMenu();    

	return 0;
}

//Ana menu
void mainMenu(void) {
	
	int choice;
	int i,j,matrix[MAX][MAX]={{0}};
	int userNum=0;
	int *p_userNum = &userNum;
    char users[MAX][20];
    int scores[MAX] = {0};
    int gameMode, matrixMode;
    int *p_gameMode = &gameMode;
    int *p_matrixMode = &matrixMode;
    
	
	do{
		printf("\n********* Main Menu *********\n\n");
		printf("1-Generate random matrix\n");
		printf("2-Generate matrix from file\n");
		printf("3-Show users scores\n");
		printf("0-Exit\n");
		printf("\npress any key from the menu to select option or press zero to exit\n");
		printf("choice: ");
		
		do{
			fflush(stdin);
			scanf("%d",&choice);
			if(choice<0)
				printf("\nenter the valid option: ");
		}while(choice<0);
		
		switch(choice){
			
			case 1:
				*p_matrixMode=5;
				userAdd(users, p_userNum);
				gameMenu(matrix, p_gameMode, p_matrixMode, scores, p_userNum);
				break;
			
			case 2:
				*p_matrixMode = 2;
				userAdd(users, p_userNum);
				gameMenu(matrix, p_gameMode, p_matrixMode, scores, p_userNum);
				break;
			
			case 3:
				
				showScores(users,scores,p_userNum);
				break;
				
		}
	}while(choice!=0);
	printf("\nThank you for choosing us...");
}

//Oyun menusu girdiler; matriks oyunmodu, matriks modu, skor dizisi kullanýcý sayýsý
void gameMenu(int matrix[][MAX], int *p_gameMode, int *p_matrixMode, int scores[MAX], int *p_userNum) {
	int choice, N;
	char fileName[20];
	do{
		printf("\n********* Game Menu *********\n\n\n");
		printf("1-Play in manuel mode\n");
		printf("2-Play in auto mode\n");
		printf("3-Back to Main Menu\n");
		printf("\npress any key from the menu to select game mode or press 3 back to main menu\n");
		printf("choice: ");
		
		do{
			fflush(stdin);
			scanf("%d",&choice);
			if(choice>3 || choice<0)
				printf("\nenter the valid option: ");
		}while(choice>3 || choice<0);
		
		switch(choice){
			
			case 1:
				
				*p_gameMode=5;
				
				printf("enter N, which is the size of the matrix: ");
				fflush(stdin);
				scanf("%d",&N);
				
				if((*p_matrixMode) == 5) {
					
					matrixZero(matrix);
					generRandomMatrix(matrix, N);
					drawBoard(matrix, N);
					
				}else if((*p_matrixMode) == 2){
					
					matrixZero(matrix);
					printf("Dosya Adini Giriniz: ");
	  				scanf("%s",fileName);
					readFromFile(matrix,fileName);
					drawBoard(matrix, N);
				}
				playManuel(matrix, N, p_gameMode, p_matrixMode, scores, p_userNum);
				break;
			
			case 2:
				
				*p_gameMode=3;
				
				printf("enter N, which is the size of the matrix: ");
				fflush(stdin);
				scanf("%d",&N);
				
				if((*p_matrixMode) == 5) {
					
					matrixZero(matrix);
					generRandomMatrix(matrix, N);
					drawBoard(matrix, N);
					
				}else if((*p_matrixMode) == 2){
					
					matrixZero(matrix);
					printf("Dosya Adini Giriniz: ");
	  				scanf("%s",fileName);
					readFromFile(matrix,fileName);
					drawBoard(matrix, N);
				}
				playAuto(matrix, N, p_gameMode, p_matrixMode, scores, p_userNum);
				break;
		}
		
	}while(choice!=3);
}

void readFromFile(int matrix[][MAX], char *fileName){
	int i,j, temp;
	FILE *data = fopen(fileName,"r");
	if(!data){
        printf("Dosya Acilamadi!");
		return;
    }
    while(!feof(data)){
        fscanf(data,"%d %d %d\n",&i,&j,&temp);  
		matrix[i][j]=temp; 
    }  
  	fclose(data); 
   // Buraya kadar olan bolumde dosyadan okuma yapiliyor. Kodu degistirmeyiniz.
}

void drawBoard(int matrix[][MAX], int N){
	
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
    int i,j,k;
    printf("\n   ");
    for (k=0;k<N;k++)
        printf("  %d    ",k);
    for(i=0;i<N;i++){
        printf("\n   ");
        for (k=0;k<N;k++)
            printf("-------");
        printf("\n%d |",i);
        for(j=0;j<N;j++){
            if (matrix[i][j]!=0){
            	SetConsoleTextAttribute(hConsole, matrix[i][j]);
            	printf("  %d",matrix[i][j]);
            	SetConsoleTextAttribute(hConsole, 7);
            	printf("   |",matrix[i][j]);
			}
            else
                 printf("      |",matrix[i][j]);
        }
    }
    printf("\n   ");
    for (k=0;k<N;k++)
        printf("-------");
}
//rastgele matris uretme fonksiyonu
void generRandomMatrix(int matrix[][MAX], int N){
	srand(time(NULL));
	int i, j, rand1, rand2, doublePoint = 0, counter = 0;
	
	while(counter<N){
		
		rand1 = rand()%N;
		rand2 = rand()%N;
		
		if(matrix[rand1][rand2] == 0){
			matrix[rand1][rand2] = counter +1;
			doublePoint++;
		}
		
		if(doublePoint == 2){
			counter++;
			doublePoint = 0;
		}		
	}
}
//manuel oynama girdiler; matriks, matriks boyutu, oyun modu, matriks modu, skor dizisi, kullanýcý sayýsý
void playManuel(int matrix[][MAX], int N, int *p_gameMode, int *p_matrixMode, int scores[MAX], int *p_userNum) {
	
	int i, j, top, finish=0, score=0, undoCounter;
	int records[MOVE_LIMIT][MAX*MAX];
	int *p_top = &top; 
	int *p_undoCounter = &undoCounter;
	char c;
	int gameTime;
	clock_t start_t, end_t;
	top = 0;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			records[0][(i*N)+j] = matrix[i][j];
		}
	}
		
	*p_undoCounter = 0;
	
	start_t = clock();
	
	while(!finish){
		connectDot(matrix, N);
		pushMove(matrix, records, N, p_top);
		drawBoard(matrix, N);
		printf("\n'u' for undo or 'c' for continue or 's for stop': ");
		scanf(" %c",&c);		
		if(c=='u'){
			popMove(matrix, records, N, p_top);
			drawBoard(matrix, N);
			(*p_undoCounter)+=1;
		}
		finish = finishControl(matrix, N);
		if(c=='s')
			finish=1;
	}
	
	end_t = clock();
	
	gameTime = (int)(end_t - start_t) / CLOCKS_PER_SEC;
	if((c=='s') && (!finishControl(matrix, N))) {
		score=0;
	}else if((c=='s') && (finishControl(matrix, N)))
		score = calcScore(N, p_gameMode, p_matrixMode, p_undoCounter, gameTime);
	else if((c=='c') && (finishControl(matrix, N)))
		score = calcScore(N, p_gameMode, p_matrixMode, p_undoCounter, gameTime);
	
	scores[(*p_userNum)-1] = scores[(*p_userNum)-1] + score; 
	
	if(finish)
		printf("\nCongrats, finished game!!!\nPassing time %d sn",gameTime);

	printf("\nYour score is :%d\n",score);;
	
}
//otomatik mod kodlanmamastýr
void playAuto(int matrix[][MAX], int N, int *p_gameMode, int *p_matrixMode, int scores[MAX], int *p_userNum){
		
	
}
//skorlarý gösterme fonksyionu ana menude calisir, girdiler skor tablosu, kullanýcý sayýsý ve listesi
void showScores(char users[][20], int scores[], int *p_userNum) {
	int i;
	
	if((*p_userNum) == 0) {
		printf("\nno user login yet\n");
	}else{
		printf("               Users     |    Scores\n");
		printf("              ***********|***********\n");
		for(i=0;i<*p_userNum;i++){
			printf("%20s     |    %d\n",users[i],scores[i]);
		}
	}
	
	
}
//skor hesaplama fonksiyonu girdiler, matriks boyutu oyunmodu, matriks modu, geri hamle sayacý, oyun süresi
int calcScore(int N, int *p_gameMode, int *p_matrixMode, int *p_undoCounter, int gameTime){
	
	double formula;
	
	gameTime = 2000/gameTime;
	
	formula = (10*N) + ((*p_matrixMode)*5) + ((*p_gameMode)*5) - ((*p_undoCounter)*5) + (gameTime*10);
	
	return (int)formula;
}
//oyunun bitip bitmedigini kontrol eden fonksiyon
int finishControl(int matrix[][MAX], int N) {
	int finish = 1, i, j;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(!matrix[i][j])
				finish=0;
		}
	}
	
	return finish;
}
//noktalarý birlestiren fonksiyon
void connectDot(int matrix[][MAX], int N){
	int i, j, m, n, k, l;
	
	printf("\nenter the coordinates of the points");
	printf("\nwarning!! joint must be from point to space");
	printf("\n(enter at the same time with space) first points i j :");
	do{
		scanf("%d %d",&m ,&n);
	}while(((m<0) || (m>N)) && ((n<0) || (n>N)));
	
	
	printf("\n(enter at the same time with space) second points i j :");
	do{
		scanf("%d %d",&k ,&l);
	}while(((k<0) || (k>N)) && ((l<0) || (l>N)));
	
	if(!(m-k)){
		if((l-n)>0){
			for(i=n+1;i<=l;i++){
				matrix[m][i] = matrix[m][n];
			}
		}else{
			for(i=n-1;i>=l;i--){
				matrix[m][i] = matrix[m][n];
			}
		}
	}else if(!(l-n)){
		if((k-m)>0){
			for(i=m+1;i<=k;i++){
				matrix[i][l] = matrix[m][n];
			}
		}else{
			for(i=m-1;i>=k;i--){
				matrix[i][l] = matrix[m][n];
			}
		}
	}
}
//yapýlan hamleyi geri alabilmek için kayýt eden fonksiyon
//girdileri matriks, hamleler sonucu tahtanýn son halini kaydeden records matriksi, stack mantýgini isletmek
//icin top degiskeni, top en son hamleyi tutar
void pushMove(int matrix[][MAX], int records[][MAX*MAX], int N, int *top){
	
	int i, j;
	
	if((*top+1) == MOVE_LIMIT){
		printf("move limit exceeded");
	}else{
		*top+=1;
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				records[(*top)][(i*N)+j] = matrix[i][j];
			}
		}
	}
}
//geri alma fonksiyonu
void popMove(int matrix[][MAX], int records[][(MAX*MAX)], int N, int *top){
	int i, j;
	
	if(*top==-1){
		printf("you haven't made a move yet");
	}else if((*top == 0)){
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				matrix[i][j] = records[(*top)][(i*N)+j];
			}
		}
	}else{
		*top-=1;
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				matrix[i][j] = records[(*top)][(i*N)+j];
			}
		}
	}
}
//kullaici ekleme ana menuden 1 ya da 2 secilince calisir
void userAdd(char users[][20], int *p_userNum) {
	
	char user[30];
	int isThere=0;
	
	printf("enter user name that add:");
	
	fflush(stdin);
	scanf("%[^\n]s",user);
	
	printf("\nWelcome to DotConnect Game %s\n",user);
	
	if((*p_userNum) == 0){
		(*p_userNum)+=1;
		strcpy(users[0], user);
	}else{
		isThere = findUser(users, p_userNum, user);
		if(isThere){
			printf("\nthis user is already registered, you can continue with '%s'",user);
		}else{
			strcpy(users[(*p_userNum)] ,user);
			(*p_userNum)+=1;
		}
	}
}
//kullanici daha once var mý yok mu onu kontrol eder
int findUser(char users[][20], int *p_userNum, char *user) {
	
	int i, isThere=0;
	
	for(i=0;i<*p_userNum;i++){
		if(!strcmp(users[i], user))
			isThere = 1;
	}
	
	return isThere;
}
//matriksin sýfýrlanmasý icin fonksyion
void matrixZero(int matrix[][MAX]) {
	int i, j;
	
	for(i=0;i<MAX;i++){
		for(j=0;j<MAX;j++){
			matrix[i][j] = 0;
		}
	}
}


