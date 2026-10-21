#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
1- Tüm utbolcular Players isimli dizide tut dinamik[x]
2- Tüm futbolcularýn maaþ mevki ve sözleþme bitimini alan fonksiyonu yaz[x]
3- Players dizisini maaþ*sözleþmeye göre sýrala[x]
4- Sýralý Players Dizisini Yazdýr[x]
5- Verilen mevki ve minimum parametresine göre en fzla veya en az maaç aþ-lan futbolcuyu bulan find fonk[x]
*/
typedef struct player{
	int sozlesmeSuresi;
	int maas;
	char *mevki;
}Player;
Player* makePlayer(int sozlesmeSuresi,int maas,char *mevki){
	Player *newPlayer = (Player*)malloc(1*sizeof(Player));
	newPlayer->mevki = (char*)malloc((strlen(mevki)+1)*sizeof(char));
	strcpy(newPlayer->mevki,mevki);
	newPlayer->maas = maas;
	newPlayer->sozlesmeSuresi = sozlesmeSuresi;
	return newPlayer;
}
void addPlayer(Player ***players,int playerCount, Player* newPlayer){
	(*players)[playerCount] = newPlayer;
}
void bubbleSortMaas(Player **players,int playerCount){
	int i,j;
	Player tmp;
	int maas1,maas2;
	for(i=0;i<playerCount-1;i++){
		for(j=0;j<playerCount-1-i;j++){
			maas1 = (players[j]->maas) * (players[j]->sozlesmeSuresi);
			maas2 = (players[j+1]->maas) * (players[j+1]->sozlesmeSuresi);
			if(maas1 > maas2){
				tmp = *players[j];
				*players[j] = *players[j+1] ;
				*players[j+1] = tmp;
				
			}
		}
	}
}
void printArray(Player **players,int playerCount){
	int i;
	printf("Mevki\t|Maas\t|SozlesmeSuresi");;
	for(i=0;i<playerCount;i++){
		printf("\n%s\t|%d\t|%d\n",players[i]->mevki,players[i]->maas,players[i]->sozlesmeSuresi); // Deneme
	}
}
void findMinOrMax(Player **players,int playerCount,char *mevki,int minmax){
	int i;
	
	Player *cmpPlayer = players[0];
	if(minmax == 0){
		for(i=1;i<playerCount;i++){
			if((players[i]->maas > cmpPlayer->maas) && (strcmp(players[i]->mevki,cmpPlayer->mevki) == 0) ){
				cmpPlayer = players[i];
			}
		}
		printf("Maasi En Dusuk Olan %s Mevkisindeki Oyuncunun Degerleri:\nMevki: %s | Maas: %d | Sozlesme Suresi: %d\n",mevki,cmpPlayer->mevki,cmpPlayer->maas,cmpPlayer->sozlesmeSuresi);
	}
	else if(minmax == 1){
		for(i=1;i<playerCount;i++){
			if((players[i]->maas > cmpPlayer->maas) && (strcmp( (players[i]->mevki) , (cmpPlayer->mevki) ) == 0) ){
				cmpPlayer = players[i];
			}
		}
		printf("Maasi En Yuksek Olan %s Mevkisindeki Oyuncunun Degerleri:\nMevki: %s | Maas: %d | Sozlesme Suresi: %d\n",mevki,cmpPlayer->mevki,cmpPlayer->maas,cmpPlayer->sozlesmeSuresi);
	}
	
}
int main(int argc, char *argv[]) {
	int playerCount,i,minmax;
	Player **players;
	Player *newPlayer;
	char mevki[50];
	int maas,sozlesmeSuresi;
	printf("Toplam Futbolcu Sayisini Giriniz: ");
	scanf("%d",&playerCount);
	players = (Player**)malloc(playerCount*sizeof(Player*));
	for(i=0;i<playerCount;i++){
		printf("%d. Futbolcunun Mevkisini Giriniz: ",i+1);
		scanf("%s",mevki);
		printf("%d. Futbolcunun Maasini Giriniz: ",i+1);
		scanf("%d",&maas);
		printf("%d. Futbolcunun Sozlesme Suresini Giriniz: ",i+1);
		scanf("%d",&sozlesmeSuresi);
		newPlayer = makePlayer(sozlesmeSuresi,maas,mevki);
		addPlayer(&players,i,newPlayer);
	}
	printf("\n");
	bubbleSortMaas(players,playerCount);
	printArray(players,playerCount);
	printf("\n\nMaasini Bulmak Istediginiz Oyuncunun Mevkisini Girin:");
	scanf("%s",mevki);
	printf("0.) En Dusuk\n1.) En Yuksek\nSecim: ");
	scanf("%d",&minmax);
	findMinOrMax(players,playerCount,mevki,minmax);
	return 0;
}
