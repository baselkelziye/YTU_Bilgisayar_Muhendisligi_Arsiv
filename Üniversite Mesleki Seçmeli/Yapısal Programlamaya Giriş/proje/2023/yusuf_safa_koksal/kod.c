#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 20

void mainMenu(char userNamesData[MAX][MAX],int usersScores[MAX][MAX],int gameMatrix[][MAX],int *person,int *len);
void gameModeSelection(char userNamesData[MAX][MAX],int usersScores[MAX][MAX],int gameMatrix[][MAX],int *person,int *len);
void autoMode(int gameMatrix[][MAX],int usersScores[MAX][MAX],int len,int *person,int whichRound);
int pathControl(int gameMatrix[][MAX],int numberCoordinate[MAX][4],int lastPaths[MAX][20],int number,int y,int x,int direction,int currIndex);
int lastPathControl(int lastPaths[MAX][20],int y,int x,int currIndex);
void labelAuto(int gameMatrix[][MAX],int path[100][3],int tmpGameMatrix[MAX][MAX][50],int numberCoordinate[MAX][4],int len,int number,int y,int x,int currIndex,int direction,int *currStackAmount,int *isArrived);
void printPath(int path[][3],int gameMatrix[][MAX],int tmpGameMatrix[MAX][MAX][50],int number,int len,int currIndex,int *currStackAmount);
void manuelMode(int gameMatrix[][MAX],int usersScores[MAX][MAX],int len,int *person,int whichRound);
int winControl(int gameMatrix[][MAX],int len);
void finishLabel(int gameMatrix[][MAX],int len,int number,int row,int column);
int calculateScore(int gameMode,int len,int time,int undoAmount);
void popTmpGameMatrix(int gameMatrix[][MAX],int tmpGameMatrix[][MAX][50],int len, int *currStackAmount);
void pushTmpGameMatrix(int gameMatrix[][MAX],int tmpGameMatrix[][MAX][50],int len, int *currStackAmount);
void createRandomMatrix(int gameMatrix[][MAX],int *len);
void createMatrixFromData(int gameMatrix[][MAX],int *len);
void labelGameMatrix(int gameMatrix[][MAX],int len, int source[], int dest[], int label);
void printGameMatrix(int gameMatrix[][MAX],int len);
void readFromFile(int matris[][MAX], char *fileName);
void takeUserName(char userNamesData[MAX][MAX],int *person);
void printUsersScores(char userNamesData[MAX][MAX],int usersScores[MAX][MAX],int *person);

int main()
{
	int i, j;
	int gameMatrix[MAX][MAX];
	char userNamesData[MAX][MAX];
	int usersScores[MAX][MAX]={{0}};
	int len, person=-1;
	
	srand(time(NULL));
	
	for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)
		{
			gameMatrix[i][j]=0;
		}
	}
	
	printf("Welcome to Number Matching Game!\n");
	mainMenu(userNamesData,usersScores,gameMatrix,&person,&len);
	
	printf("\nGame Finished!");
	
	return 0;
}

void mainMenu(char userNamesData[MAX][MAX],int usersScores[MAX][MAX],int gameMatrix[][MAX],int *person,int *len) // menu
{	
	int choice, continueControl=1;
	
	while(continueControl)
	{
		continueControl=0;
		
		printf("\n1- Create Random Matrix\n2- Create Matrix From Data\n3- Show Users' Score\n4- Quit\n\nYour Choice: ");
		scanf("%d",&choice);
	
		switch(choice)
		{
			case 1:
				takeUserName(userNamesData,person);
				createRandomMatrix(gameMatrix,len);
				gameModeSelection(userNamesData,usersScores,gameMatrix,person,len);
				break;
			
			case 2:
				takeUserName(userNamesData,person);
				createMatrixFromData(gameMatrix,len);
				gameModeSelection(userNamesData,usersScores,gameMatrix,person,len);
				break;
				
			case 3:
				printUsersScores(userNamesData,usersScores,person);
				continueControl=1;
				break;
				
			case 4:
				break;
				
			default:
				printf("\nPlease, enter a valid number!!!\n\n");
				continueControl=1;
				sleep(1);
	        	system("cls");
		}
	}
}

void gameModeSelection(char userNamesData[MAX][MAX],int usersScores[MAX][MAX],int gameMatrix[][MAX],int *person,int *len) // alt menu
{
	int choice, continueControl=1, matrixType, whichRound=0;
	char inputChar;
	
	while(continueControl)
	{
		printf("\n1- Play in Manual Mode\n2- Play in Auto Mode\n3- Back Main Menu\n\nYour Choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				manuelMode(gameMatrix,usersScores,*len,person,whichRound);
				whichRound++;
				break;
				
			case 2:
				autoMode(gameMatrix,usersScores,*len,person,whichRound);
				whichRound++;
				break;
				
			case 3:
				mainMenu(userNamesData,usersScores,gameMatrix,person,len);
				break;
				
			default:
				printf("\nPlease, enter a valid number!!!\n\n");
				sleep(1);
	        	system("cls");
		}
		
		printf("\n\nDo you want to play again? (y/n) ");
		scanf(" %c",&inputChar);
		
		if(inputChar=='y' || inputChar=='Y')       // Kullanici tekrar oynamak isterse yeni bir matrisle yeniden baslatilir
		{
			printf("\n(1) Create Random Matrix\n(2) Create Matrix From Data\nChoice: ");
			scanf("%d",&matrixType);
			if(matrixType==1)
				createRandomMatrix(gameMatrix,len);
			else if(matrixType==2)
				createMatrixFromData(gameMatrix,len);
		}
		else if(inputChar=='n' || inputChar=='N')
		{
			continueControl=0;
			mainMenu(userNamesData,usersScores,gameMatrix,person,len);
		}
	}
}

void autoMode(int gameMatrix[][MAX],int usersScores[MAX][MAX],int len,int *person,int whichRound) // otomatik oyun modu
{
	int i, j;
	int tmpGameMatrix[MAX][MAX][50]={0};
	int path[100][3];
	int numberCoordinate[MAX][4];
	int lastPaths[MAX][20];
	int number=1, queue=0, isArrived, start, newMatrixType;
	int currStackAmount=0, undoAmount=0 ,iteration=0;
	float elapsedTime;
	time_t startTime, endTime;
	
	printGameMatrix(gameMatrix,len);
	printf("\nPress '1' to start || Press '2' to create new matrix       Choice ----> ");
	scanf("%d",&start);
	if(start==2)
	{
		printf("\n(1) Create Random Matrix\n(2) Create Matrix From Data\nChoice: ");
		scanf("%d",&newMatrixType);
		
		if(newMatrixType==1)
			createRandomMatrix(gameMatrix,&len);
		else if(newMatrixType==2)
			createMatrixFromData(gameMatrix,&len);
			
		autoMode(gameMatrix,usersScores,len,person,whichRound);
		return;
	}
	
	startTime=time(NULL);
	
	while(number<=len)   // baslangic ve bitis noktalari matriste tutulur
	{
		for(i=0;i<len;i++)
		{
			for(j=0;j<len;j++)
			{
				if(gameMatrix[i][j]==number)
				{
					queue++;
					if(queue%2==1)
						numberCoordinate[number][0]=i, numberCoordinate[number][1]=j;
					else
						numberCoordinate[number][2]=i, numberCoordinate[number][3]=j;
				}
			}
		}
		number++;
	}
	
	number=1;
	while(number<=len)
	{
		if(!pathControl(gameMatrix,numberCoordinate,lastPaths,number,numberCoordinate[number][0],numberCoordinate[number][1],0,0))  // sayinin eslesmesi tamamlanmamis ise yol bulunmasi icin donguye girer
		{	
			isArrived=0;
			do{
				labelAuto(gameMatrix,path,tmpGameMatrix,numberCoordinate,len,number,numberCoordinate[number][0],numberCoordinate[number][1],0,0,&currStackAmount,&isArrived);
				if(isArrived==0)  // eger hedefe ulasilamadiysa matris 1 adým geri alinir ve tekrar denenir
				{
					undoAmount++;
					iteration++;
					if(iteration>=100)
						isArrived=1;
					if(len<=5)
						printf("\nUndo");
					popTmpGameMatrix(gameMatrix,tmpGameMatrix,len,&currStackAmount);
				}
			}while(isArrived==0);
		}
		number++;

		if(number==len+1) // son sayiya gelindiginde butun sayilarýn eslesmesi tamamlanmis mi diye kontrol edilir tamamlanmamýs ise o sayidan dongu yeniden baslar
		{
			for(i=1;i<=len;i++)
			{
				if(!pathControl(gameMatrix,numberCoordinate,lastPaths,i,numberCoordinate[i][0],numberCoordinate[i][1],0,0))
				{
					number=i;
					i=len+1;
				}
			}
		}
		
		if(iteration>=100)
			number=len+1;
	}	
	printGameMatrix(gameMatrix,len);
	endTime=time(NULL);
	elapsedTime=difftime(endTime,startTime);
	
	if(iteration>=100) // fonksiyon duzgun calismadiysa sonuc duzgun bulunamadiysa bu sarta girer
	{
		usersScores[*person][whichRound]=-100;
		printf("\n---- Game Over! ----\n(Couldn't be resolved exactly)");
	}	
	else
		usersScores[*person][whichRound]=calculateScore(2,len,elapsedTime,undoAmount);
}

int pathControl(int gameMatrix[][MAX],int numberCoordinate[MAX][4],int lastPaths[MAX][20],int number,int y,int x,int direction,int currIndex) // otomatik oyun modunda sayýlarin dogru eslesip eslesmedigini kontrol eder
{
	if(x==numberCoordinate[number][3] && y==numberCoordinate[number][2]) // hedefe ulastiysa bu sarta girer
		return 1;
	
	lastPaths[currIndex][0]=y;
	lastPaths[currIndex][1]=x;
	
	if(gameMatrix[y+1][x]==number && direction!=1 && lastPathControl(lastPaths,y+1,x,currIndex-1))
	{
		return pathControl(gameMatrix,numberCoordinate,lastPaths,number,y+1,x,3,currIndex+1);
	}
	else if(gameMatrix[y-1][x]==number && direction!=3 && lastPathControl(lastPaths,y-1,x,currIndex-1))
	{
		return pathControl(gameMatrix,numberCoordinate,lastPaths,number,y-1,x,1,currIndex+1);
	}
	else if(gameMatrix[y][x+1]==number && direction!=4 && lastPathControl(lastPaths,y,x+1,currIndex-1))
	{
		return pathControl(gameMatrix,numberCoordinate,lastPaths,number,y,x+1,2,currIndex+1);
	}
	else if(gameMatrix[y][x-1]==number && direction!=2 && lastPathControl(lastPaths,y,x-1,currIndex-1))
	{
		return pathControl(gameMatrix,numberCoordinate,lastPaths,number,y,x-1,4,currIndex+1);
	}
	else
		return 0;
}

int lastPathControl(int lastPaths[MAX][20],int y,int x,int currIndex) // pathControl fonksiyonuna yardimci olur
{
	int i, flag=1;
	
	for(i=0;i<currIndex;i++)
	{
		if(y==lastPaths[i][0] && x==lastPaths[i][1])
		{
			flag=0;
		}
	}
	
	if(flag==1)
		return 1;
	else
		return 0;
}

void labelAuto(int gameMatrix[][MAX],int path[100][3],int tmpGameMatrix[MAX][MAX][50],int numberCoordinate[MAX][4],int len,int number,int y,int x,int currIndex,int direction,int *currStackAmount,int *isArrived) // otomatik modda gidilebilecek yollari bulan recursive fonksiyon
{
	int noWay=1;
	
	if(y-1==numberCoordinate[number][2] && x==numberCoordinate[number][3] || y+1==numberCoordinate[number][2] && x==numberCoordinate[number][3] || y==numberCoordinate[number][2] && x-1==numberCoordinate[number][3] || y==numberCoordinate[number][2] && x+1==numberCoordinate[number][3])
	{
		path[currIndex][0]=y;
		path[currIndex][1]=x;
		path[currIndex][2]=direction;
		printPath(path,gameMatrix,tmpGameMatrix,number,len,currIndex,currStackAmount);
		*isArrived=1;
		return;
	}
	
	if( (gameMatrix[y][x]==0 && currIndex>0) || (gameMatrix[y][x]==number && currIndex==0) ) // gecerli koordinati path'e ekleme
	{
		path[currIndex][0]=y;
		path[currIndex][1]=x;
		path[currIndex][2]=direction;
	}
	
	if(direction==1 && gameMatrix[y-1][x]==0 && y-1>=0 && *isArrived!=1)  // ayni yonden devam edilip edilemeyecegini kontrol eder
	{
		noWay=0;
		labelAuto(gameMatrix,path,tmpGameMatrix,numberCoordinate,len,number,y-1,x,currIndex+1,1,currStackAmount,isArrived);
	}
	else if(direction==2 && gameMatrix[y][x+1]==0 && x+1<len && *isArrived!=1)
	{
		noWay=0;
		labelAuto(gameMatrix,path,tmpGameMatrix,numberCoordinate,len,number,y,x+1,currIndex+1,2,currStackAmount,isArrived);
	}
	else if(direction==3 && gameMatrix[y+1][x]==0 && y+1<len && *isArrived!=1)
	{
		noWay=0;
		labelAuto(gameMatrix,path,tmpGameMatrix,numberCoordinate,len,number,y+1,x,currIndex+1,3,currStackAmount,isArrived);
	}
	else if(direction==4 && gameMatrix[y][x-1]==0 && x-1>=0 && *isArrived!=1)
	{
		noWay=0;
		labelAuto(gameMatrix,path,tmpGameMatrix,numberCoordinate,len,number,y,x-1,currIndex+1,4,currStackAmount,isArrived);
	}	
	
	
	if(gameMatrix[y+1][x]==0 && direction!=1 && y+1<len && *isArrived!=1)  // gelinen taraf haric diger yonleri kontrol eder
	{
		noWay=0;
		labelAuto(gameMatrix,path,tmpGameMatrix,numberCoordinate,len,number,y+1,x,currIndex+1,3,currStackAmount,isArrived);
	}
	if(gameMatrix[y-1][x]==0 && direction!=3 && y-1>=0 && *isArrived!=1)
	{
		noWay=0;
		labelAuto(gameMatrix,path,tmpGameMatrix,numberCoordinate,len,number,y-1,x,currIndex+1,1,currStackAmount,isArrived);
	}
	if(gameMatrix[y][x+1]==0 && direction!=4 && x+1<len && *isArrived!=1)
	{
		noWay=0;
		labelAuto(gameMatrix,path,tmpGameMatrix,numberCoordinate,len,number,y,x+1,currIndex+1,2,currStackAmount,isArrived);
	}
	if(gameMatrix[y][x-1]==0 && direction!=2 && x-1>=0 && *isArrived!=1)
	{
		noWay=0;
		labelAuto(gameMatrix,path,tmpGameMatrix,numberCoordinate,len,number,y,x-1,currIndex+1,4,currStackAmount,isArrived);
	}
	if(noWay)
		return;
}

void printPath(int path[][3],int gameMatrix[][MAX],int tmpGameMatrix[MAX][MAX][50],int number,int len,int currIndex,int *currStackAmount) // otomatik modda bulunan yollari matris uzerinde gunceller ve islemler ekrana raporlanir
{
	int i, j, k;
	int tmpDirection=path[1][2];
	int source[2]={path[0][0],path[0][1]};
	int dest[2];
	
	for(i=1;i<=currIndex;i++)
	{
		if(tmpDirection!=path[i][2])
		{
			dest[0]=path[i-1][0];
			dest[1]=path[i-1][1];
			
			if(len<=5)
				printf("\nSource-->(%d , %d)     Destination-->(%d , %d)    Number-->%d",source[0],source[1],dest[0],dest[1],number);
			
			labelGameMatrix(gameMatrix,len,source,dest,number);
			pushTmpGameMatrix(gameMatrix,tmpGameMatrix,len,currStackAmount);
			
			source[0]=path[i-1][0];
			source[1]=path[i-1][1];
		}
		tmpDirection=path[i][2];
	}
	if(gameMatrix[path[currIndex][0]][path[currIndex][1]]==0)
	{
		dest[0]=path[i-1][0];
		dest[1]=path[i-1][1];
		
		if(len<=5)
			printf("\nSource-->(%d , %d)     Destination-->(%d , %d)    Number-->%d",source[0],source[1],dest[0],dest[1],number);
		labelGameMatrix(gameMatrix,len,source,dest,number);
		pushTmpGameMatrix(gameMatrix,tmpGameMatrix,len,currStackAmount);
	}
}

void manuelMode(int gameMatrix[][MAX],int usersScores[MAX][MAX],int len,int *person,int whichRound) // manuel oyun modu
{
	int i, j;
	int tmpGameMatrix[MAX][MAX][50]={0};
	int source[2], dest[2];
	int label, tmp, finishControl=1, win, choice, score, start=0, newMatrixType;
	int currStackAmount=0, undoAmount=0;
	float elapsedTime;
	time_t startTime, endTime;
	
	printGameMatrix(gameMatrix,len);
	printf("\nPress '1' to start || Press '2' to create new matrix       Choice ----> ");
	scanf("%d",&start);
	if(start==2)
	{
		printf("\n(1) Create Random Matrix\n(2) Create Matrix From Data\nChoice: ");
		scanf("%d",&newMatrixType);
		
		if(newMatrixType==1)
			createRandomMatrix(gameMatrix,&len);
		else if(newMatrixType==2)
			createMatrixFromData(gameMatrix,&len);
			
		manuelMode(gameMatrix,usersScores,len,person,whichRound);
		return;
	}
	
	startTime=time(NULL);
	
	while(finishControl)
	{
		printGameMatrix(gameMatrix,len);
		
		printf("\nPress '1' for labelling || Press '2' for UNDO    Choice ----> ");
		scanf("%d",&choice);
		
		if(choice==1)
		{
			pushTmpGameMatrix(gameMatrix,tmpGameMatrix,len,&currStackAmount);
			printf("\nSource:       ");
			scanf("%d %d",&source[0],&source[1]);
			printf("Destination:  ");
			scanf("%d %d",&dest[0],&dest[1]);
			printf("Number:       ");
			scanf("%d",&label);
			labelGameMatrix(gameMatrix,len,source,dest,label);
		}
		else if(choice==2)
		{
			popTmpGameMatrix(gameMatrix,tmpGameMatrix,len,&currStackAmount);
			undoAmount++;
		}
		else
			printf("\nUndefined choice! Please, only press '1' or '2'.");
			
		finishControl=0;
		for(i=0;i<len;i++) // hepsi 0 dan farkli olunca oyun biter
		{
			for(j=0;j<len;j++)
			{
				if(gameMatrix[i][j]==0)
					finishControl=1;
			}
		}
	}
	printGameMatrix(gameMatrix,len);
	endTime=time(NULL);
	elapsedTime=difftime(endTime,startTime);
	
	win=winControl(gameMatrix,len);  // kazanma durumunu inceler
	if(win)
	{
		usersScores[*person][whichRound]=calculateScore(1,len,elapsedTime,undoAmount);
	}
	else
	{
		printf("\n---- Game Over! ----");
		usersScores[*person][whichRound]=-100;
	}
}

int winControl(int gameMatrix[][MAX],int len) // manuel modda kullanici matrisi doldurdugunda kazanip kazanamadigini kontrol eder
{
	int i, j, number=1, flag=1;
	
	while(number<=len)
	{
		for(i=0;i<len;i++)
		{
			for(j=0;j<len;j++)
			{
				if(gameMatrix[i][j]==number)
				{
					finishLabel(gameMatrix,len,number,i,j);
					i=j=len;
				}
			}
		}
		number++;
	}
	
	for(i=0;i<len;i++)  // label islemi yapilan matriste sayi kalmis ise 0 dondurur kullanici kazanamamis demektir
	{
		for(j=0;j<len;j++)
		{
			if(gameMatrix[i][j]!=-1)
			{
				flag=0;
			}
		}
	}
	
	return flag;
}

void finishLabel(int gameMatrix[][MAX],int len,int number,int row,int column) // manuel modda kazanmayý kontrol etmeye yardýmcý olur recursive olarak label islemi yapar
{
	if(row==len || row==-1) return;
	if(column==len || column==-1) return;
	
	if(gameMatrix[row][column]==number)
		gameMatrix[row][column]=-1;
	else
		return;
	
	finishLabel(gameMatrix,len,number,row+1,column);
	finishLabel(gameMatrix,len,number,row-1,column);
	finishLabel(gameMatrix,len,number,row,column+1);
	finishLabel(gameMatrix,len,number,row,column-1);
}

int calculateScore(int gameMode,int len,int time,int undoAmount) // oyun sonunda kullanicinin skorunu hesaplar
{
	int score=0;
	
	score=(len*len*100)-((time%10)*50)-(undoAmount*20);
	printf("\n---- Congratulations! ----\n         You Won!\nTime: %d\nMatrix Size: %d\nUndo Amount: %d\nGamemode: ",time,len,undoAmount);
	
	if(gameMode==1) // manuel mode
	{
		score*=2;
		printf("Manuel Mode\nScore: %d",score);
	}
	else            // auto mode
	{
	    printf("Auto Mode\nScore: %d",score);
	}
	
	return score;
}

void popTmpGameMatrix(int gameMatrix[][MAX],int tmpGameMatrix[][MAX][50],int len, int *currStackAmount) // undo yapildiginda oyun matrisinin son halini geri getirir
{
	int i, j;
	if(*currStackAmount!=0)
	{
		for(i=0;i<len;i++)
		{
			for(j=0;j<len;j++)
			{
				gameMatrix[i][j]=tmpGameMatrix[i][j][*currStackAmount-1];
			}
		}
		
		*currStackAmount=*currStackAmount-1;
	}
}

void pushTmpGameMatrix(int gameMatrix[][MAX],int tmpGameMatrix[][MAX][50],int len, int *currStackAmount) // yapilan hamleyi geri alma ihtimaline karsi matris dizisine kaydeder
{
	int i, j, k;
	
	if(*currStackAmount!=100)  // Yigin belirli sinira ulasmadiysa oyun alaninin son halini son yigina ekler
	{
		*currStackAmount=*currStackAmount+1;
		
		for(i=0;i<len;i++)
		{
			for(j=0;j<len;j++)
			{
				tmpGameMatrix[i][j][*currStackAmount-1]=gameMatrix[i][j];
			}
		}
	}
	else                    // Yigin belirli sinira ulasinca once en eskisini siler sonra bir kaydirma yapip sona da oyun alaninin son halini ekler 
	{
		for(k=0;k<*currStackAmount-1;k++)
		{
			for(i=0;i<len;i++)
			{
				for(j=0;j<len;j++)
				{
					tmpGameMatrix[i][j][k]=tmpGameMatrix[i][j][k+1];
				}
			}
		}
		
		for(i=0;i<len;i++)
		{
			for(j=0;j<len;j++)
			{
				tmpGameMatrix[i][j][*currStackAmount-1]=gameMatrix[i][j];
			}
		}
	}
}

void createRandomMatrix(int gameMatrix[][MAX],int *len) // random bir oyun matrisi olusturur
{
	int i, j;
	int label=1;
	int row, column;
	
	printf("\nEnter the size of matrix: ");
	scanf("%d",len);
	
	for(i=0;i<*len;i++)
	{
		for(j=0;j<*len;j++)
		{
			gameMatrix[i][j]=0;
		}
	}
	
	while(label<=*len)
	{
		for(i=0;i<2;i++)
		{
			row= rand() % *len;
			column= rand() % *len;
			
			if(gameMatrix[row][column]==0)
				gameMatrix[row][column]=label;
			else
				i--;
		}
		label++;
	}
}

void createMatrixFromData(int gameMatrix[][MAX],int *len) // datadan bir oyun matrisi olusturur
{
	int i, j;
	char fileName[20];
	
	printf("\nEnter the size of matrix: ");
	scanf("%d",len);
	
	for(i=0;i<*len;i++)
	{
		for(j=0;j<*len;j++)
		{
			gameMatrix[i][j]=0;
		}
	}
	
	printf("\nEnter file name: ");
	scanf("%s",fileName);
	
	readFromFile(gameMatrix, fileName);
}

void labelGameMatrix(int gameMatrix[][MAX],int len, int source[], int dest[], int label) // oyun matrisi uzerindeki label islemi bu fonksiyon uzerinden yapilir
{
	int i;
	
	if(source[0]==dest[0]) // row degerleri ayni ise
	{
		if(source[1]>dest[1])
		{
			for(i=source[1]-1;i>=dest[1];i--)
			{
				gameMatrix[source[0]][i]=label;
			}
		}
		else if(source[1]<dest[1])
		{
			for(i=source[1]+1;i<=dest[1];i++)
			{
				gameMatrix[source[0]][i]=label;
			}
		}
	}
	else if(source[1]==dest[1]) // column degerleri ayni ise
	{
		if(source[0]>dest[0])
		{
			for(i=source[0]-1;i>=dest[0];i--)
			{
				gameMatrix[i][source[1]]=label;
			}
		}
		else if(source[0]<dest[0])
		{
			for(i=source[0]+1;i<=dest[0];i++)
			{
				gameMatrix[i][source[1]]=label;
			}
		}
	}
	else // duzgun bir yonde label islemi yapilamayacak ise
		printf("You can only label in a straight direction not diagonally!");
}

void printGameMatrix(int gameMatrix[][MAX],int len) // oyun matrisini yazdirir
{
	int i,j,k;
    for(i=0;i<len;i++){
        printf("\n-");
        for (k=0;k<len;k++)
            printf("--------");
        printf("\n|");
        for(j=0;j<len;j++)
            if (gameMatrix[i][j]!=0)
                printf("  %2.d   |",gameMatrix[i][j]);
            else
                 printf("       |",gameMatrix[i][j]);
    }
    printf("\n-");
	for (i=0;i<len;i++)
            printf("--------");
}

void readFromFile(int gameMatrix[][MAX], char *fileName) // datadan matris cekmek icin yardimci fonksiyon
{
	int i,j, temp;
	FILE *data = fopen(fileName,"r");
	if(!data){
        printf("Dosya Acilamadi!");
		return;
    }
    while(!feof(data)){
        fscanf(data,"%d %d %d\n",&i,&j,&temp);  
		gameMatrix[i][j]=temp; 
    }  
  	fclose(data); 
}

void takeUserName(char userNamesData[MAX][MAX],int *person) // kullanici adini alir ve kaydeder
{
	int i,j;
	*person=*person+1;
	printf("\nPlease, enter user name: ");
	scanf(" %[^\n]s",userNamesData[*person]);
}

void printUsersScores(char userNamesData[MAX][MAX],int usersScores[MAX][MAX],int *person) // skor tablosunu yazdirir
{
	int i, j, k;
	int nameLen, maxGame=0;
	
	for(i=0;i<=*person;i++)
	{
		j=0;
		while(usersScores[i][j]!=0)
		{
			if(j>maxGame)
			{
				maxGame=j;
			}
			j++;
		}
	}
	
	printf("\nSCORE TABLE:\n\n");
	
	for(i=0;i<28;i++)
		printf(" ");
	j=0;
	while(j<=maxGame)
	{
		printf("Game %d",j+1);
		for(i=0;i<4;i++)
		printf(" ");
		j++;
	}
	
	printf("\n\n");
	for(i=0;i<=*person;i++)
	{
		nameLen=strlen(userNamesData[i]);
		printf("%s  ",userNamesData[i]);
		for(j=0;j<20-nameLen;j++)
			printf("-");
		printf(">");
		
		j=0;
		while(usersScores[i][j]!=0)
			printf("%10.d",usersScores[i][j++]);
		
		printf("\n\n");
	}
}
