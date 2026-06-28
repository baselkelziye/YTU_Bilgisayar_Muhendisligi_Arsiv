#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
const int N=8;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	
	char temp[1][2];//girilen hucre degerini tutan degisken
	int dama[N][N];//damanin hucrelerini tutan dizi
	
	int i,j,k;//cevrimici degiskenleri
	int x=1;//yon degistirmek için kullanýlan degisken
	
	int satir;//damanin satir degerini tutan degisken
	int sutun;//damanin sutun degerini tutan degisken
	
	bool gecersiz=true;//dama hucresinin degeri yanlis girilip girilmedigini tutan degisken
	
	while(1){//sonsuz dongu yapmak icin
	
	//Hucre kullanicidan soruluyor/
	printf("Hucre degeri girin:(A1 A2 A3 A4....H8)\n");
	scanf("%s",temp);

	
	//dama tahtasinin ici dolduruluyor.
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			dama[i][j]=x;
			x*=(-1);
		}
		x*=(-1);
	}
	
	//damanin ici ekrana yazdiriliyor
	for(i='A';i<='H';i++)
	printf("\t%c",i);
	printf("\n");
	printf("\t======================================================================\n");
	for(j=0;j<N;j++){
		printf("%d ||    ",j+1);
		for(k=0;k<N;k++){
			printf("%d\t",dama[j][k]);
		}
		printf("\n");
	}
	
	//sutun degeri indise cevriliyor
	
	if(temp[0][0]>='A' && temp[0][0]<='H')
		sutun=((int)temp[0][0])-65;
	else if(temp[0][0]>='a' && temp[0][0]<='h')
		sutun=((int)temp[0][0])-97;
	else
		gecersiz=false;
		



//sutun degeri indise cevriliyor
	if(temp[0][1]>='1' && temp[0][1]<='8')
		satir=((int)temp[0][1])-49;
	else
		gecersiz=false;


	if(gecersiz){

		if(dama[satir][sutun]==1)
			printf("\n%s hucresi beyazdir\n",*temp);
		else
			printf("\n%s hucresi siyahtir\n",*temp);
		}
	else
		printf("Gecerli bir hucre giriniz!!!\n");
	
		
	system("PAUSE");//bir giris yapilana kadar ekrani gosterir
	system("CLS");//ekran temizleniyor
}
	return 0;
}
