#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//	typedef struct{
		//	int no;
		//	float no1;
	//	}virgül;
	typedef	 struct{
		char isim[10];
		float x;
		float y;
	}nokta;
int main(void){
	int i;
	char * a;
	
	/*struct tarih{
		int gun;
		char ay[10];
		int yil;
	};
	struct calisan_bilgi{
		int sicil_no;
		char isim[30];
		char adres[50];
		struct tarih ise_giris;
		double maas;
	};calisan
	struct sehir{
		char sehir_adi[20];
		int sicaklik;};
		struct sehir turkiye[82];
		typedef float tipim;
		struct hacim_prizma{
			tipim en;
			tipim boy;
			tipim yukseklik;
			tipim hacim;
		};
		typedef struct hacim_prizma prizma;
		prizma prizma_a;
		struct ogrenci{
			char ad[10];
			char soyad[10];
			int no;
		};
		struct ogrenci can;
		strcpy(can.ad,"can");
		strcpy(can.soyad,"man");
		can.no=12;
		printf("%s %s %d",can.ad,can.soyad,can.no);
		struct ogrenci ahmet={"ahmet","bulut",25};	
		printf("%s %s %d",ahmet.ad,ahmet.soyad,ahmet.no);
		struct ogr_bilgi{
			int no;
			char ad[20];
			char soyad[20];
			int yas;
		};
		struct ogr_bilgi ogrenci_1,ogrenci_2;
		ogrenci_1.no=15;
		strcpy(ogrenci_1.ad,"Ogrenci");
		strcpy(ogrenci_1.soyad,"Soyadým");
		ogrenci_1.yas=18;
		printf("%d %s %s %d",ogrenci_1.no,ogrenci_1.ad,ogrenci_1.soyad,ogrenci_1.yas);
		ogrenci_2=ogrenci_1;
		printf("%d %s %s %d",ogrenci_2.no,ogrenci_2.ad,ogrenci_2.soyad,ogrenci_2.yas);
		*/
	
	//	virgül man;
		//man.no=1;
	//	man.no1=2;
	//	printf("%d %f",man.no,man.no1);
	nokta can[5]={{"can",3,4},{"man",5,6},{"kan",1,2},{"osman",8,9},{"kazým",7,8}};
	a=can[0].isim;
	strcpy(a,"Mahmut");
	
	for(i=0;i<5;i++){
		printf("%s %f %f \n",can[i].isim,can[i].x,can[i].y);
	}
				return 0;
}
