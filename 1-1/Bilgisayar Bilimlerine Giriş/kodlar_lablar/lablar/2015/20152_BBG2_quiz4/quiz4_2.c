#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 20
void HarfKodlariYazdir(int isler[][3], int is);
bool Search(int mat[][3], int son, int ara);
bool SiraDogruMu(int start, int stop);
void paralelGanttDraw(int isler[][3], int is);

int main(void){
	int is, i,head;
	char tmp;
	int isler[MAX][3];
	printf("Yapilacak is sayisini giriniz: ");
	scanf("%d", &is);
	
	for(i = 0; i < is; i++){
		isler[i][0] = 45;
		isler[i][1] = -1;
		isler[i][2] = is;
	}
	
	for(i = 0; i < is; i++){
		system("CLS");
		printf("Yapilacak islerin harf kodlarini giriyorsunuz...\n");
		HarfKodlariYazdir(isler, is);
		do{
			printf("%d. isin harf kodu: ", i+1);
			scanf(" %c", &tmp);
			isler[i][0] = (int) tmp;
		}while(Search(isler, i-1, isler[i][0]));	
	}
	
	system("CLS");
	printf("Yapilacak islerin harf kodlarini asagidaki gibi girildi\n");
	HarfKodlariYazdir(isler, is);
		
	printf("\nSirasiyla her bir islemin baslangic ve bitis zamanlarini gireceksiniz\n");
	for(i = 0; i < is; i++){
		printf("\"%c\" islemi baslangic zamani : ", isler[i][0]);
		scanf("%d", &isler[i][1]);
		do{
			printf("\"%c\" islemi bitis zamani     : ", isler[i][0]);
			scanf("%d", &isler[i][2]);	
		} while(!SiraDogruMu(isler[i][1],isler[i][2]));	
	}
		
	paralelGanttDraw(isler, is);
	
	system("PAUSE");
	return 0;
}





//Eleman sayisi az olacaðýz için bu þekilde aranda yoksa binary search tercih edilmeli.
bool Search(int mat[][3], int son, int ara){
	bool bul = false;
	while(!bul && son >= 0){
		if(mat[son--][0] == ara)
			bul = true;
	}
	return bul;
}

void HarfKodlariYazdir(int isler[][3], int is){
	int i;
	for(i = 0; i < is; i++)
		if(isler[i][0] == 45)
			printf("__  ");
		else
			printf("%c  ", isler[i][0]);
	printf("\n\n");
}

//Farkli indislerin girilmesini engellemek icin
bool SiraDogruMu(int start, int stop){
	return (start<stop);
}

//Dizinin linkli oldugu varsayilarak bu islem gerceklestirilmistir.
void paralelGanttDraw(int isler[][3], int is){
	int  i, j;
		
	printf("\nGantt Diagrami asagidaki gibi olusturuldu...\n\nGantt ->\n");
	for(i = 0; i < is; i++){
		for(j=1;j<isler[i][1];j++)
			printf(" ");
		for(j=isler[i][1];j<=isler[i][2];j++)
			printf("%c",isler[i][0]);
		printf("\n");
	}
	printf("\n\n");
}
