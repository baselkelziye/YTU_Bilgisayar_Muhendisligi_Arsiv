#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct players{
	int maas;
	int sozlesmeSuresi;
	char mevki[200];
}Players;

void readPlayers(Players*, int );
void sirala(Players*,int );
void printPlayers(Players*,int );
void find(Players* , int ,char* , int );
int main(){
	
	int i,n;
	
	printf("Toplam futbolcu sayisi: ");
	scanf("%d",&n);
	
	Players *players = (Players*) malloc(sizeof(Players) * n);
	
	readPlayers(players,n);
	printPlayers(players,n);
	sirala(players,n);
	printPlayers(players,n);
	find(players,n,"defans",0);
	find(players,n,"forvet",1);
	free(players);
	return 0;
}

void readPlayers(Players *players, int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%d. oyuncunun maasi: ",i+1);
		scanf("%d",&players[i].maas);
		printf("%d. oyuncunun sozlesme suresi: ",i+1);
		scanf("%d",&players[i].sozlesmeSuresi);
		printf("%d. oyuncunun mevkisi: ",i+1);
		scanf("%s",players[i].mevki);
	}
}

void sirala(Players *dizi,int n){
	int i,j;
	Players tmp;
	for(i = 0; i < n-1; i++){
		for(j = i+1; j < n; j++){
			if(dizi[j].maas * dizi[j].sozlesmeSuresi < dizi[i].maas * dizi[i].sozlesmeSuresi){
				tmp = dizi[i];
				dizi[i]= dizi[j];
				dizi[j] = tmp;
			}
		}
	}
}

void printPlayers(Players* players,int n){
	int i;
	printf("MAAS\tSOZLESME SURESI\tMEVKI\n");
	for(i = 0; i < n; i++){
		printf("%d\t%d\t\t%s\n",players[i].maas,players[i].sozlesmeSuresi,players[i].mevki);
	}
}

void find(Players* players, int n,char* mevki, int belirleyici){
	int i,j,enKucukIndex = 0,enBuyukIndex = 0;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(strcmp(players[i].mevki,mevki) == 0 && strcmp(players[j].mevki,mevki) == 0 && belirleyici == 0){
				if(players[j].maas < players[i].maas)
					enKucukIndex = j;
			}
			else if(strcmp(players[i].mevki,mevki) == 0 && strcmp(players[j].mevki,mevki) == 0 && belirleyici == 1){
				if(players[j].maas > players[i].maas)
					enBuyukIndex = j;
			}
			
			if(i == n-1 && j == n-1 && belirleyici == 1)
				printf("\n%s Mevkisinde Oynayan En Yuksek Maasli Topcunun Maas: %d Sozlesme Suresi: %d Mevki: %s\n",players[enBuyukIndex].mevki,players[enBuyukIndex].maas,players[enBuyukIndex].sozlesmeSuresi,players[enBuyukIndex].mevki);
			else if(i == n-1 && j == n-1 && belirleyici == 0)	
				printf("\n%s Mevkisinde Oynayan En Dusuk Maasli Topcunun Maas: %d Sozlesme Suresi: %d Mevki: %s\n",players[enKucukIndex].mevki,players[enKucukIndex].maas,players[enKucukIndex].sozlesmeSuresi,players[enKucukIndex].mevki);
		}
	}
}

