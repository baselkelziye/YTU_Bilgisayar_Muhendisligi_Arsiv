#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct hasta{     
	int  randevu_no;      
	char isim[10];       
	char poliklinik[10];  
	char gun[10];	      
}HASTA;

int main(){
	char buffer[1000];
	int N ,i;
	FILE* fp;
	HASTA h[4];
	fp = fopen("input.txt","r+");
	fseek(fp, 0, SEEK_SET);
	fread(&N,sizeof(int),1,fp);
	fread(h,sizeof(HASTA)*N,1,fp);
	fclose(fp);
	char* dosyaAdi = (char*)malloc(10*sizeof(char));
	// MESAJ YAZMA
	for(i=0;i<N;i++){
		strcpy(dosyaAdi,h[i].isim);
		strcat(dosyaAdi,".txt");
		fp = fopen(dosyaAdi,"w+");
		fprintf(fp,"Merhaba %s, %s gunu %s polikilniginde %d nolu randevunuz bulunmaktadir.\nLutfen unutmayiniz. Iyi Gunler.",h[i].isim,h[i].gun,h[i].poliklinik,h[i].randevu_no);
		fclose(fp);
	}
	// MESAJLAR BÝTÝS
	// rapor baslangýc
	int dah=0,goz=0,cer=0;
	for(i=0;i<N;i++){
		if(strcmp(h[i].poliklinik,"dahiliye") == 0){
			dah++;
		}
		else if((strcmp(h[i].poliklinik,"cerrahi") == 0)){
			cer++;
		}
		else{
			goz++;
		}
	}
	fp = fopen("rapor.txt","w+");
	fprintf(fp,"Dahiliye Randevu Sayisi : %d\nCerrahi Randevu Sayisi : %d\nGoz Randevu Sayisi : %d",dah,cer,goz);
	fclose(fp);
	// rapor bitis
}

