//M Ali Bugday
//Date created: 25,05,2022
//Date Modified: 05,06,2022
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <conio.h>
#define N 50
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*
duvar->0
bos->1
elma degeri->2 
gezilmis->3 
baslangic->1000
bitis->1001
*/

int cikmaz_sokak;
int puan = 0;

typedef struct node{
	int x;
	int y;
}NODE;

NODE baslangic;
NODE bitis;

void labirent_oku(int *n, int *m, int **matris, char* filename);
void matris_yazdir(int **matris,int n, int m);
void labirent_yazdir(int **matris, int n);//kullanilmadi
void elma_ata(int n, int m, int **matris, int elma_sayisi);
void dfs(int n, int m, int **matris, int visited[n-2][m-2], int row, int col);

int main() {
	int i,j, n, m, **matris, elma_sayisi;
	char *filename = "maze.txt";
	time_t t;
	srand((unsigned) time(&t));
	
	
	
	matris = (int**)malloc(N*sizeof(int*));
	for(i=0;i<N;i++){//50x50 alanli buyuk bir alan ayýrma islemi, daha sonra matris okuyup buraya kaydedilecek
		matris[i] = (int*)malloc(N*sizeof(int)); 
	}
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			matris[i][j] = 0;
		}
	}
	
	labirent_oku(&n, &m, matris, filename);	
	
	printf("elma sayisini giriniz:");
	scanf("%d",&elma_sayisi);
	
	elma_ata(n, m, matris, elma_sayisi);
	
	printf("\n--------------------\n");
	
	printf("satir:%d sutun%d\n",n,m);
	
	matris_yazdir(matris, n, m);
	
	//-----------------------------------------------------------
	//matris baslangic ve bitis noktalari
	do{
		printf("baslangic noktasinin x kodrinatini giriniz (kordinatlar sifirdan basliyor)");
		scanf("%d",&baslangic.x);
		printf("baslangic noktasinin y kodrinatini giriniz");
		scanf("%d",&baslangic.y);
		if(matris[baslangic.x][baslangic.y] != 1){
			printf("girdiginiz noktalar baslangic noktasi icin uygun degil tekrar giriniz\n");
		}
	}while(matris[baslangic.x][baslangic.y] != 1);
	matris[baslangic.x][baslangic.y]=1000;
	
	matris_yazdir(matris, n, m);
	
	do{
		printf("bitis noktasinin x kodrinatini giriniz");
		scanf("%d",&bitis.x);
		printf("bitis noktasinin y kodrinatini giriniz");
		scanf("%d",&bitis.y);
		if(matris[bitis.x][bitis.y] != 1){
			printf("girdiginiz noktalar bitis noktasi icin uygun degil tekrar giriniz\n");
		}
	}while(matris[bitis.x][bitis.y] != 1);
	matris[bitis.x][bitis.y]=1001;
	
	matris_yazdir(matris, n, m);
	//-----------------------------------------------------------
	
	printf("\nbasliyor.");
	sleep(2);
	printf(".");
	sleep(1);
	printf(".\n");
	sleep(1);
	
	int visited[n-2][m-2];
	for(i=0;i<n-2;i++){
		for(j=0;j<m-2;j++){
			visited[i][j] = 0;
		}
	}
	dfs(n, m, matris, visited, baslangic.x, baslangic.y);
	
	return 0;
}


void labirent_oku(int *n, int *m, int **matris, char* filename){
	int i = 0, j = 0;
	char *token, kelime[255];
	
	
	FILE *oku = fopen(filename,"r");
	
	if(oku == NULL){
		printf("dosya acilamadi");
		return;
	}
	
	while(fgets(kelime, 255, oku) != NULL){
		j=0;
		token = strtok(kelime, " ");
		if(token != NULL){
			matris[i+1][j+1] = atoi(token);
		}
		j++;
		while(token!=NULL){
			token = strtok(NULL, " ");
			if(token != NULL){
				matris[i+1][j+1] = atoi(token);
			}
			j++;
		}
		i++;
	}
	
	fclose(oku);
	*n=i+2;
	*m=j+1;
}

void matris_yazdir(int **matris,int n, int m){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(j==m-1){//son sutun ise
				if(i==0){//ilk satir ise
					printf("%d                             puan:%d",matris[i][j], puan);	
				}else{
					printf("%d",matris[i][j]);
				}
				
			}else{
				if(matris[i][j]==1000){
					printf("B-");
				}else if(matris[i][j]==1001){
					printf("C-");	
				}else if(matris[i][j]==2){
					printf("E-");
				}else if(matris[i][j]==3){
					printf("*-");
				}
				else{
					printf("%d-",matris[i][j]);		
				}
			}
		}
		printf("\n");
	}
}

void labirent_yazdir(int **matris, int n){
	int i, j, flag1;
	
	for(i=0;i<n;i++){
		flag1=0; 
		for(j=0;j<n;j++){
			if(matris[i][j]==0){
				if(i%2==0){
					printf("+-");
					flag1=1;
				}
				else{
					printf("| ");
				}
			}
			else{
				if(matris[i][j]==1){
					printf("  ");
				}
				else if(matris[i][j]==2){
					printf(" O");
				}
			}
		}
		if(flag1 == 1){
			printf("+\n");
		}else{
			printf("|\n");
		}
	}
	
}

void elma_ata(int n, int m, int **matris, int elma_sayisi){
	int i, x, y;
	i=0;
	while(i<elma_sayisi){
		x=rand()%(n-2);
		y=rand()%(m-2);
		if(matris[x+1][y+1]==1){//matris x ve y kordinatlarýnda bosise
			matris[x+1][y+1]=2;//elmayi ata
			i++;
		}			
	}
} 


void dfs(int n, int m, int **matris, int visited[n-2][m-2], int row, int col){
	
	if(row<1 || col<1 || row>(n-1) || col>(m-1) || visited[row-1][col-1]){//kenarlarý asmissa veya ziyaret edilmisse return 
		return;
	}
	
	if(matris[row][col]==0){//duvar ise return et
		return;
	}
	
	if(matris[row][col]==1001){
		printf("cikis bulundu");
		exit(0);
	}
	//if elma veya cikis ise
	if(matris[row][col] == 2){
		puan+=10;
	}
	
	
	visited[row-1][col-1] = 1;
	matris[row][col] = 3;// animasyonda * gezilmise cevirme islemi
	sleep(1);
	
	//clrscr();
	matris_yazdir(matris, n, m);
	cikmaz_sokak = 1;//cikmaz sokaktan cikarken her noktada puan azaltmamak için kontrol
	dfs(n, m, matris, visited, row-1, col);//yukari
	dfs(n, m, matris, visited, row, col+1);//sag
	dfs(n, m, matris, visited, row+1, col);//asagi
	dfs(n, m, matris, visited, row, col-1);//sol
	
	
	
	//cikmaz sokak
	
	matris[row][col]=1;
	
	if(cikmaz_sokak){
		//printf("\ncikmaz sokak\n");
		cikmaz_sokak = 0;
		puan-=5;	
	}
	
	
}
 
