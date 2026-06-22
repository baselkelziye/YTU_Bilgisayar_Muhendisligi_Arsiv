#include<stdio.h>
#define MAX 15   // kullanýlacak max sayi
void drawBoard(int matris[][MAX], int N);
void readFromFile(int matris[][MAX], char *fileName);
int main(){
    int i,j,matris[MAX][MAX]={{0}}; 
    int N = 5; // kullanicidan aliniz
    char fileName[20];	
  	printf("Dosya Adini Giriniz");
  	scanf("%s",fileName);
	/* buradan itibaren menü vb kodlarý olmalidir. dosya okumak için asagidaki kod verilmistir */
	
	readFromFile(matris, fileName);
    drawBoard(matris,N);
	/*
	 * matrisi manuel doldurmak veya Oyunu oynamak icin yazilacak kodlarin
	 * fonksiyon cagrilari buradan  baslamalidir
	 */	
	
	
  return 0;
}
void readFromFile(int matris[][MAX], char *fileName){
	int i,j, temp;
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
   // Buraya kadar olan bolumde dosyadan okuma yapiliyor. Kodu degistirmeyiniz.
}

/* Matrisi ekrana yazdirma fonksiyonu
 * Bu fonksiyonu yapiyi bozmayacak sekilde degistirebilirsiniz.
 */
void drawBoard(int matris[][MAX], int N){
    int i,j,k;
    for(i=0;i<N;i++){
        printf("\n");
        for (k=0;k<N;k++)
            printf("-------");
        printf("\n");
        for(j=0;j<N;j++)
            if (matris[i][j]!=0)
                printf("  %d   |",matris[i][j]);
            else
                 printf("      |",matris[i][j]);
    }
}
