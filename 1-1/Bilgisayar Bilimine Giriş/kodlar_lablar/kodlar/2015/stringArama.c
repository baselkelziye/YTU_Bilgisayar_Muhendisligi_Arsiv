#include <stdio.h>//input output fonksiyonlarini kullanabilmek icin
#include <stdlib.h>//
#include <stdbool.h>//boolean degisken kullanabilmek icin gerekli kutuphaneler ekleniyor

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	char string1[100];//icinde arama yapilacak metin
	char string2[20];//aranacak metin
	int i=0,j=0,k;//cevrim degiskenleri
	int n=0;//birinci metnin uzunlugunu tutacak olan degisken
	int m=0;//ikinci metnin uzunlugunu tutacak olan degisken
	
	bool flag=false;//aranilacak kelimenin olup olmadigini tutan bayrak degiskeni
	
	puts("Birinci metni giriniz:");
	gets(string1);
	//puts(string1); // ekrana yazdirarak denedik
	
	puts("\nAranacak metni giriniz");
	gets(string2);
	//girilen metinlerin uzunluklarini bulmak icin 
	for(k=0;string1[k]!='\0';k++){
		n++;
	}
	
	for(k=0;string2[k]!='\0';k++){
		m++;
	}
	printf("\nbirinci cumle uzunluk:%d",n);
	printf("\nikinci  cumle uzunluk:%d",m);
	printf("\n");
	
	// kelimenin aranmasi burada basliyor
		while(i<n){
			if(string1[i]==string2[j]){
				j++;
				i++;
				if(j==m){
					printf("indis: %d\n",i-m);
					flag=true;
					i=i-m+1;
					j=0;
				}
			}
			else{
				i++;
				j=0;
			}
		}
	//aranilan kelime metinde yoksa kullaniciya bilgi donmek icin
	if(!flag){
		printf("Aranilan kelime metinde yok!");
	}
	
	return 0;
}
