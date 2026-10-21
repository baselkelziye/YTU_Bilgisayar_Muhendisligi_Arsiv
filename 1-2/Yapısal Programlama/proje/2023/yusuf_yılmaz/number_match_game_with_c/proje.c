#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 15

void readFromFile(int matris[][MAX], char *fileName,int N);
void drawBoard(int matris[][MAX], int N,int *counter);
void createBoard(int matrix[][MAX],int N);


void drawPath(int matris[][MAX],int moveHistory[][4],int N,int *moveCounter,int *counter2);
void gameMenu(int matris[][MAX],int moveHistory[][4],int N,int *moveCounter,int *counter2);
void runGameManuel(int matris[][MAX],int moveHistory[][4],int N,int *moveCounter,int *counter2);
void runGameAuto(int matris[][MAX],int N);

void UNDO(int matris[][MAX],int r1,int c1,int r2,int c2);

int main(){
	int i,j,matrix[MAX][MAX];
	int moveCounter, matchedNumberCounter, moveHistory[10][4];
	moveCounter =0;
	matchedNumberCounter=0;
	
	int mainMenu,N,game=1,flag=1;
	char playerName[40];
	
	while(flag==1){
		printf("\n| ~~ Ana Menu ~~ |\n");
		printf("\n1) Rastgele Matris Olustur:");
		printf("\n2) Dosyadan Matris Olustur:");
		printf("\n3) Kullanicinin Skorlarini Goster:");
		printf("\n4) Cikis:\n");
		scanf(" %d",&mainMenu);
		  
		switch(mainMenu){
			case 1:
				printf("| ~~ Rastgele Matris Modu ~~ |\n");
				printf("Oyuncu ismini giriniz: ");
	        	scanf(" %s", &playerName);
	        	printf("{%s} Tahta boyutunu giriniz: ",playerName);
	        	scanf("%d",&N);
	        	createBoard(matrix,N);
	        	gameMenu(matrix,moveHistory,N,&moveCounter,&matchedNumberCounter);
				break;
				
			case 2:
				printf("| ~~ Dosya Okuma Modu ~~ |\n");
				printf("Oyuncu ismini giriniz: ");
	        	scanf(" %s", &playerName);
	        	printf("{%s} Tahta boyutunu giriniz: ",playerName);
	        	scanf("%d",&N);
	        	char fileName[20];	
				printf("Dosya Adini Giriniz");
				scanf("%s",fileName);
				readFromFile(matrix, fileName,N);
				gameMenu(matrix,moveHistory,N,&moveCounter,&matchedNumberCounter);
				break;
				
			case 3:
				printf("| ~~ Oyuncu Skorlari ~~ |\n");
				break;
				
			case 4:
				printf("| ~~ Cikis yapiliyor... ~~ |\n");
				flag=0;
				break;
				
			default:
				printf("\ngecerli degerler giriniz !\n");
		}
	}
	
	return 0;
}
void readFromFile(int matris[][MAX], char *fileName,int N){
	int i,j,temp;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			matris[i][j]=0;
		}
	}
	
	FILE *data = fopen(fileName,"r");
	if(!data){
        printf("Dosya Acilamadi!");
		return;
    }
    while(!feof(data)){
        fscanf(data,"%d %d %d\n",&i,&j,&temp);  
		matris[i][j]=temp; 
    }  
  	fclose(data); 
}

void createBoard(int matrix[][MAX],int N){
	int i,j,numberRow,numberColumn;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			matrix[i][j]=0;
		}
	}
	
	srand(time(NULL));
	for(i=1;i<=N;i++){
		for(j=0;j<2;j++){
			numberRow= rand() % N;
			numberColumn = rand() % N;
			while(matrix[numberRow][numberColumn] !=0){
				numberRow= rand() % N;
				numberColumn = rand() % N;
			}
			matrix[numberRow][numberColumn]=i;
		}
	}	
}

void drawBoard(int matris[][MAX], int N,int *counter2){
    int i,j,k;
    printf("\n      |");
    for(j=0;j<N;j++)
			printf("  c%d  |",j);
    for(i=0;i<N;i++){
        printf("\n");
        for (k=0;k<=N;k++)
            printf("------|");
        printf("\n");
        printf("  r%d  |",i);
        for(j=0;j<N;j++)
            if (matris[i][j]!=0)
                printf("  %d   |",matris[i][j]);
            else
                 printf("      |",matris[i][j]);
    }
    printf("\n{eslestirilen sayi adedi: %d}\n",*counter2);
}

void drawPath(int matris[][MAX],int moveHistory[][4],int N,int *moveCounter,int *counter2){
	int i,j,k,r1,c1,r2,c2,is_true;
	
	do{
	is_true=1;
	printf("{Eslestir} Yalnizca bir eksende hareket edebilirsiniz\n\n");
	printf("Source-Row:");
	scanf(" %d",&r1);
	printf("Source-Column:");
	scanf(" %d",&c1);
	printf("Destination-Row:");
	scanf(" %d",&r2);
	printf("Destination-Column:");
	scanf(" %d",&c2);
	if(r1>=N || r2>=N || c1>=N ||c2>=N || r1<0 || r2<0 || c1<0 || c2<0){
		printf("\nKoordinatlar 0 ile (N-1) arasinda olmalidir !\n");
		is_true =0;
	}	
	}while( r1-r2 !=0 && c1-c2 !=0  || r1==r2 && c1==c2 || is_true ==0 );
	
	printf("\nSource: (%d,%d) ---> Destination: (%d,%d)\n",r1,c1,r2,c2);
	
	moveHistory[*moveCounter][0] = r1; //hamle kaydedilecek
	moveHistory[*moveCounter][1] = c1;
	moveHistory[*moveCounter][2] = r2;
	moveHistory[*moveCounter][3] = c2;
	*moveCounter += 1; // hamle sayacý arttýrýldý.
	
	if(r1-r2 !=0){
		// Yukarý-asagi yonde hareket
		k= 1;
		if(r1-r2>0)
			k= -1;
		//process
		i= r1+k;
		
		while(i != r2+k){
			
			if(matris[i][c1] == matris[r1][c1]){
				printf("Sayilar eslesti!\n");
				*counter2 += 1; // eslesen sayýlarýn sayacý arttý
				return; // sayilar eslestiyse duracak 
			}
			else if(matris[i][c1]==0){
				matris[i][c1]= matris[r1][c1]; // bu adimda kaynaktaki sayiyi bu hucreye yerlestiriyoruz
			}
			else{
				printf("Wrong Path, auto-undo running...");
				*moveCounter +=1;
				UNDO(matris,i-k,c1,r1,c1);
				return;
			}
			i += k;
		}
	}
	
	else if(c1-c2 !=0){
		// sag-sol yonunde hareket
		k= 1;
		if(c1-c2>0)
			k= -1;
		//process
		j=c1+k;
		
		while(j != c2+k){
			if(matris[r1][j]== matris[r1][c1]){
				printf("Sayilar eslesti!\n");
				*counter2 += 1; // eslesen sayýlarýn sayacý arttý
				return; // bu adimda sayilar eslestigi icin fonksiyon duracak
			}
			else if(matris[r1][j]== 0){
				matris[r1][j] = matris[r1][c1]; // bu adimda kaynaktaki sayiyi bu hucreye yerlestiriyoruz
			}
			else{
				printf("Wrong Path, auto-undo running...");
				*moveCounter +=1;
				
				UNDO(matris,r1,j-k,r1,c1);
				return;
			}
			j += k;
		}
	}
}

void gameMenu(int matris[][MAX],int moveHistory[][4],int N,int *moveCounter,int *counter2){
	int gameMenu;
	printf("\n| ~~ Game Menu ~~ |\n");
	printf("\n1) Manuel Modda Oyna:");
	printf("\n2) Otomatik Modda Oyna:");
	printf("\n3) Cikis:\n");
	scanf(" %d",&gameMenu);
	
	switch(gameMenu){
		case 1:
			runGameManuel(matris,moveHistory,N,moveCounter,counter2);
			break;
		
		case 2:
			runGameAuto(matris,N);
			break;
		
		case 3:
			break;	
			
		default:
			printf("\ngecerli degerler giriniz !\n");
	}
}

void runGameManuel(int matris[][MAX],int moveHistory[][4],int N,int *moveCounter,int *counter2){
	int game=1,yourMove,r1,c1,r2,c2,is_true;
	printf("\nHamlenizi seciniz:\n1)Eslestir\n2)Geri Al\n3)Cikis\n\n");
	while(game==1){
		drawBoard(matris,N,counter2);
		printf("\nHamleni Sec: ");
		scanf(" %d:",&yourMove);
		
		switch(yourMove){
			case 1:
				drawPath(matris,moveHistory,N,moveCounter,counter2);
				break;
				
			case 2:
				do{
					is_true=1;
					printf("{UNDO} Yalnizca bir eksende hareket edebilirsiniz\n\n");
					printf("Source-Row:");
					scanf(" %d",&r1);
					printf("Source-Column:");
					scanf(" %d",&c1);
					printf("Destination-Row:");
					scanf(" %d",&r2);
					printf("Destination-Column:");
					scanf(" %d",&c2);
					if(r1>=N || r2>=N || c1>=N ||c2>=N || r1<0 || r2<0 || c1<0 || c2<0){
						printf("\nKoordinatlar 0 ile (N-1) arasinda olmalidir !\n");
						is_true =0;
						}	
				}while( r1-r2 !=0 && c1-c2 !=0  || r1==r2 && c1==c2 || is_true ==0 );
				UNDO(matris,r1,c1,r2,c2);
				break;
				
			case 3:
				printf("Cikis yapiliyor...\n");
				game=0;
				break;
				
			default:
				printf("\n [!!!] Gecerli degerler giriniz !\n\n");		
		}		
	}
}
void runGameAuto(int matris[][MAX],int N){
	printf("\nAuto Mod Calisiyor\n");
}
void UNDO(int matris[][MAX],int r1,int c1,int r2,int c2){
	int i,j,k;
	printf("\nDelete_Source: (%d,%d) ---> Delete_Destination: (%d,%d)\n",r1,c1,r2,c2);
	
	if(r1-r2 !=0){
		// Yukarý-asagi yonde hareket
		k= 1;
		if(r1-r2>0)
			k= -1;
		//process
		i= r1;
		while(i != r2){
			matris[i][c1]=0;
			i += k;
		}
	}
	else if(c1-c2 !=0){
		// sag-sol yonunde hareket
		k= 1;
		if(c1-c2>0)
			k= -1;
		//process
		j=c1;
		while(j != c2){
			matris[r1][j]=0;
			j += k;
		}
	}
	
}
