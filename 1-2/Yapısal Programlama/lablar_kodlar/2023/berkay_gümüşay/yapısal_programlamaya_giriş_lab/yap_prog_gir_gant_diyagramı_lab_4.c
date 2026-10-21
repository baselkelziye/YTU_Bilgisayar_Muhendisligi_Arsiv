#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
void isKodlari(int isSayisi , char isIsimleri[SIZE]);
int kodKontrol(char isIsimleri[SIZE] , int mevcutKonum);
void isZamanlari(char isIsimleri[SIZE] , int isZaman[SIZE][SIZE] , int isSayisi);
int zamanKontrol(int isZaman[SIZE][SIZE] , int mevcutKonum);
void yazdirGantDiyagrami(char isIsimleri[SIZE] , int isSayisi , int isZaman[SIZE][SIZE]);
int main() {
	int isSayisi , i ,j;
	char isIsimleri[SIZE];
	int isZaman[SIZE][SIZE];
	printf("Yapilacak Is Sayisini Giriniz : ");
	scanf("%d",&isSayisi);
	
	isKodlari(isSayisi,isIsimleri);
	printf("\n\n");
	isZamanlari(isIsimleri,isZaman,isSayisi);
	yazdirGantDiyagrami(isIsimleri,isSayisi,isZaman);
	return 0;
}
void isKodlari(int isSayisi , char isIsimleri[SIZE]){
	int i ;
	int kontrol;
	for(i=0 ; i<isSayisi ; i++){
		kontrol = 0;
		while(kontrol == 0){
			printf("%d. Isin Kodunu Giriniz : ",i+1);
			scanf("%s",&isIsimleri[i]);
			kontrol = kodKontrol(isIsimleri,i);
		}
	}
		
}
int kodKontrol(char isIsimleri[SIZE] , int mevcutKonum){
	int i;
	for(i=mevcutKonum-1 ; i>= 0 ; i=i-1){
		if(isIsimleri[mevcutKonum] == isIsimleri[i] ){
			return 0;
		}
	}
	return 1;
}
void isZamanlari(char isIsimleri[SIZE] , int isZaman[SIZE][SIZE] , int isSayisi){
	int i , j , control;
	
	for(i=0 ; i<isSayisi ; i++){
		control = 0;
		while(control == 0){
			for(j=0 ; j<2 ; j++){
				if(j==0){
					printf("'%c' islemi baslangic zamani : ",isIsimleri[i]);
					scanf("%d",&isZaman[i][j]);
				}
				else{
					printf("'%c' islemi bitis zamani : ",isIsimleri[i]);
					scanf("%d",&isZaman[i][j]);
				}
			}
			control = zamanKontrol(isZaman,i);
		}
		
	}
}
int zamanKontrol(int isZaman[SIZE][SIZE] , int mevcutKonum){
	if (isZaman[mevcutKonum][1] < isZaman[mevcutKonum][0]){
		return 0;
	}
	return 1;
}
void yazdirGantDiyagrami(char isIsimleri[SIZE] , int isSayisi , int isZaman[SIZE][SIZE]){
	int i , j ,control;
	
	
	for(i=0 ; i<isSayisi ; i++){
		control = 1;
		j=1;
		while(control == 1){
			if(j < isZaman[i][0]){
				printf("_");
			}
			else if( (j >= isZaman[i][0]) && (j < isZaman[i][1]) ){
				printf("%c",isIsimleri[i]);
			}
			else if( j == isZaman[i][1] ){
				printf("%c",isIsimleri[i]);
				control = 0;
			}
			j++;
		}
		printf("\n");
	}
}

