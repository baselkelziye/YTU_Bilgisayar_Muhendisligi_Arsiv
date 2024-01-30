#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void HarfKodlariYazdir(int isler[][3], int is);
bool Search(int mat[][3], int son, int ara);
bool SiraDogruMu(int isler[][3], int son, int ara, int is,int head);
void SequentialGanttDraw(int isler[][3], int is,int head);

int main(void){
	int is, i,head;
	char tmp;
	printf("Yapilacak is sayisini giriniz: ");
	scanf("%d", &is);
	
	int isler[is][3];
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
		
	printf("\nSirasiyla her bir islemin ne kadar sureceginiz gireceksiniz\n");
	for(i = 0; i < is; i++){
		printf("\"%c\" islemi: ", isler[i][0]);
		scanf("%d", &isler[i][1]);
	}
	
	do{
		printf("\nHead indisini giriniz: ");
		scanf("%d", &head);	
	}while(head<0 || head >=is);
	
	printf("\nSirasiyla her bir islemin hangi oncelikte oldugunu gireceksiniz\n");
	for(i = 0; i < is; i++){
		do{
			printf("%d birim suren \"%c\" isleminin linki: ", isler[i][1], isler[i][0]);
			scanf("%d", &isler[i][2]);
		}while(SiraDogruMu(isler, i-1, isler[i][2], is, head));
	}
	SequentialGanttDraw(isler, is,head);
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
bool SiraDogruMu(int isler[][3], int son, int ara, int is, int head){
	bool bul = false;
	
	if((ara < -1) || (ara >= is) || (ara==head)){
		return true;
	}else{
		while(!bul && son >= 0){
			if(isler[son--][2] == ara)
				bul = true;
		}
		return bul;
	}
}

//Dizinin linkli oldugu varsayilarak bu islem gerceklestirilmistir.
void SequentialGanttDraw(int isler[][3], int is, int head){
	int  i, ind;
	
	printf("\nGantt Diagrami asagidaki gibi olusturuldu...\n\nGantt ->  ");
	for(i = 0; i < is; i++){
		do{
			printf("%c ", isler[head][0]);
		}while(head != -1 && isler[head][1]-- > 1);
		head = isler[head][2];
	}
	printf("\n\n");
}
