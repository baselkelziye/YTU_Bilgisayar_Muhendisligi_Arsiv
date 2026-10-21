#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	int OgrNo;
	char ad[10];
	char soyad[20];
	int topDers;
	int topKredi;
}OGRENCILER;

typedef struct{
	int dersID;
	char dersAdi[25];
	int kredi;
	int kontenjan;
	int ogrUyeID;
}DERSLER;

typedef struct{
	int ogrUyeID;
	char ad[10];
	char soyad[10];
	char unvan[10];
}OgrUyeleri;

typedef struct{
	int id;
	int ogrno;
	int dersno;
	int dersdurum;
	char bilgi[20];
}OgrenciDersKayit;

void OgrDersKayit();
void OgrDersSilme();
void OgrenciGuncelleme(int , int , int);
void OgrenciEkle();
void OgrenciSil();
void OgrencileriBastir();
void OgrAldDersListele();
void OgretimUyesiEkle();
void DersEkle();
void OgretimUyesiSil();
void OgrUyeVerdDersListele();
void DersiAlanOgrencileriListele();
void derskodusiniflistesi();
void DersSil();
void OgrenciGuncelle();
void OgretimUyesiGuncelle();
void DersGuncelle();
void OgrenciKrediGuncelleme(int , int , int);

int main(){
	
	int secim,sec;
	printf("Yapmak istediginiz islemi giriniz.\n");
	printf("Ogrencilerle ilgili islem yapmak icin 1'e basiniz.\n");
	printf("Ogretim uyeleri ile ilgili islem yapmak icin 2'ye basiniz.\n");
	printf("Derslerle ilgili islem yapmak icin 3'e basiniz.\n");
	printf("DERSKODU_SINIFLISTESI.txt olusturmak icin 4'e basiniz.\n");
	printf("Cikis icin 9'a basiniz.\n");
	scanf("%d",&secim);
	while(secim>=1 && secim<=9){
	switch(secim){
		case 1:
			printf("Yapmak istediginiz islemi giriniz.\n");
			printf("Ogrenci Numarasini girerek ogrencinin aldigi dersleri listeleme: 1\n");
			printf("Ogrenci Numarasi girerek ogrenciyi derse kaydetme: 2\n");
			printf("Ogrenci Numarasi girerek ogrenciyi dersten silme: 3\n");
			printf("Yeni ogrenci ekleme: 4\n");
			printf("Ogrenciyi silme: 5\n");
			printf("Ogrenci bilgisi guncelleme: 6\n");
	        printf("Cikis icin 9'a basiniz.\n");
			scanf("%d",&sec);
			switch(sec){
				case 1:
					OgrAldDersListele();
					printf("\n");
					printf("Yapmak istediginiz islemi giriniz.\n");
	                printf("Ogrencilerle ilgili islem yapmak icin 1'e tiklayiniz.\n");
	                printf("Ogretim uyeleri ile ilgili islem yapmak icin 2'ye tiklayiniz.\n");
	                printf("Derslerle ilgili islem yapmak icin 3'e tiklayiniz.\n");
	                printf("DERSKODU_SINIFLISTESI.txt olusturmak icin 4'e basiniz.\n");
	                printf("Cikis icin 9'a basiniz.\n");
	                scanf("%d",&secim);
					break;
				case 2:
					OgrDersKayit();
					printf("\n");
					printf("Yapmak istediginiz islemi giriniz.\n");
	                printf("Ogrencilerle ilgili islem yapmak icin 1'e tiklayiniz.\n");
	                printf("Ogretim uyeleri ile ilgili islem yapmak icin 2'ye tiklayiniz.\n");
	                printf("Derslerle ilgili islem yapmak icin 3'e tiklayiniz.\n");
	                printf("DERSKODU_SINIFLISTESI.txt olusturmak icin 4'e basiniz.\n");
	                printf("Cikis icin 9'a basiniz.\n");
	                scanf("%d",&secim);
					break;
			    case 3:
			    	OgrDersSilme();
			    	printf("\n");
			    	printf("Yapmak istediginiz islemi giriniz.\n");
	                printf("Ogrencilerle ilgili islem yapmak icin 1'e tiklayiniz.\n");
	                printf("Ogretim uyeleri ile ilgili islem yapmak icin 2'ye tiklayiniz.\n");
	                printf("Derslerle ilgili islem yapmak icin 3'e tiklayiniz.\n");
	                printf("DERSKODU_SINIFLISTESI.txt olusturmak icin 4'e basiniz.\n");
	                printf("Cikis icin 9'a basiniz.\n");
	                scanf("%d",&secim);
			    	break;
			    case 4:
			    	OgrenciEkle();
			    	printf("\n");
			    	printf("Yapmak istediginiz islemi giriniz.\n");
	                printf("Ogrencilerle ilgili islem yapmak icin 1'e tiklayiniz.\n");
	                printf("Ogretim uyeleri ile ilgili islem yapmak icin 2'ye tiklayiniz.\n");
	                printf("Derslerle ilgili islem yapmak icin 3'e tiklayiniz.\n");
	                printf("DERSKODU_SINIFLISTESI.txt olusturmak icin 4'e basiniz.\n");
	                printf("Cikis icin 9'a basiniz.\n");
	                scanf("%d",&secim);
			    	break;
			    case 5:
			    	OgrenciSil();
			    	//printf("yyy\n");
			    	printf("\n");
			    	printf("Yapmak istediginiz islemi giriniz.\n");
	                printf("Ogrencilerle ilgili islem yapmak icin 1'e tiklayiniz.\n");
	                printf("Ogretim uyeleri ile ilgili islem yapmak icin 2'ye tiklayiniz.\n");
	                printf("Derslerle ilgili islem yapmak icin 3'e tiklayiniz.\n");
	                printf("DERSKODU_SINIFLISTESI.txt olusturmak icin 4'e basiniz.\n");
	                printf("Cikis icin 9'a basiniz.\n");
	                scanf("%d",&secim);			    	
			    	break;
			    case 6:
			    	OgrenciGuncelle();
			    	printf("\n");
			    	printf("Yapmak istediginiz islemi giriniz.\n");
	                printf("Ogrencilerle ilgili islem yapmak icin 1'e tiklayiniz.\n");
	                printf("Ogretim uyeleri ile ilgili islem yapmak icin 2'ye tiklayiniz.\n");
	                printf("Derslerle ilgili islem yapmak icin 3'e tiklayiniz.\n");
	                printf("DERSKODU_SINIFLISTESI.txt olusturmak icin 4'e basiniz.\n");
	                printf("Cikis icin 9'a basiniz.\n");
	                scanf("%d",&secim);	
			    case 9:
			    	return 0;
			}
		break;
		case 2:
			printf("Yapmak istediginiz islemi giriniz.\n");
			printf("Ogretim Uyesi ID'si girerek ogretim uyesinin verdigi dersleri listeleme: 1\n");
			printf("Yeni ogretim uyesi ekleme: 2\n");
			printf("Ogretim uyesini silme: 3\n");
			printf("Ogretim uyesi bilgisini guncelleme: 4\n");
			scanf("%d",&sec);
			switch(sec){
				case 1:
					OgrUyeVerdDersListele();
					printf("\n");
					printf("Yapmak istediginiz islemi giriniz.\n");
	                printf("Ogrencilerle ilgili islem yapmak icin 1'e tiklayiniz.\n");
	                printf("Ogretim uyeleri ile ilgili islem yapmak icin 2'ye tiklayiniz.\n");
	                printf("Derslerle ilgili islem yapmak icin 3'e tiklayiniz.\n");
	                printf("DERSKODU_SINIFLISTESI.txt olusturmak icin 4'e basiniz.\n");
	                printf("Cikis icin 9'a basiniz.\n");
	                scanf("%d",&secim);
					break;
				case 2:
					OgretimUyesiEkle();
					printf("\n");
					printf("Yapmak istediginiz islemi giriniz.\n");
	                printf("Ogrencilerle ilgili islem yapmak icin 1'e tiklayiniz.\n");
	                printf("Ogretim uyeleri ile ilgili islem yapmak icin 2'ye tiklayiniz.\n");
	                printf("Derslerle ilgili islem yapmak icin 3'e tiklayiniz.\n");
	                printf("DERSKODU_SINIFLISTESI.txt olusturmak icin 4'e basiniz.\n");
	                printf("Cikis icin 9'a basiniz.\n");
	                scanf("%d",&secim);
					break;
				case 3:
					OgretimUyesiSil();
					printf("\n");
					printf("Yapmak istediginiz islemi giriniz.\n");
	                printf("Ogrencilerle ilgili islem yapmak icin 1'e tiklayiniz.\n");
	                printf("Ogretim uyeleri ile ilgili islem yapmak icin 2'ye tiklayiniz.\n");
	                printf("Derslerle ilgili islem yapmak icin 3'e tiklayiniz.\n");
	                printf("DERSKODU_SINIFLISTESI.txt olusturmak icin 4'e basiniz.\n");
	                printf("Cikis icin 9'a basiniz.\n");
	                scanf("%d",&secim);
					break;
				case 4:
					OgretimUyesiGuncelle();
					printf("\n");
					printf("Yapmak istediginiz islemi giriniz.\n");
	                printf("Ogrencilerle ilgili islem yapmak icin 1'e tiklayiniz.\n");
	                printf("Ogretim uyeleri ile ilgili islem yapmak icin 2'ye tiklayiniz.\n");
	                printf("Derslerle ilgili islem yapmak icin 3'e tiklayiniz.\n");
	                printf("DERSKODU_SINIFLISTESI.txt olusturmak icin 4'e basiniz.\n");
	                printf("Cikis icin 9'a basiniz.\n");
	                scanf("%d",&secim);
	                break;
				case 9:
					return 0;
			}
		break;
		case 3:
			printf("Yapmak istediginiz islemi giriniz.\n");
			printf("Ders kodu girerek o dersi alan tum ogrencileri listeleme: 1\n");
			printf("Yeni ders ekleme: 2\n");
			printf("Ders silme: 3\n");
			printf("Ders bilgisi guncelleme: 4\n");
			scanf("%d",&sec);
			switch(sec){
				case 1:
					DersiAlanOgrencileriListele();
					printf("\n");
					printf("Yapmak istediginiz islemi giriniz.\n");
	                printf("Ogrencilerle ilgili islem yapmak icin 1'e tiklayiniz.\n");
	                printf("Ogretim uyeleri ile ilgili islem yapmak icin 2'ye tiklayiniz.\n");
	                printf("Derslerle ilgili islem yapmak icin 3'e tiklayiniz.\n");
	                printf("DERSKODU_SINIFLISTESI.txt olusturmak icin 4'e basiniz.\n");
	                printf("Cikis icin 9'a basiniz.\n");
	                scanf("%d",&secim);
					break;
				case 2:
					DersEkle();
					printf("\n");
					printf("Yapmak istediginiz islemi giriniz.\n");
	                printf("Ogrencilerle ilgili islem yapmak icin 1'e tiklayiniz.\n");
	                printf("Ogretim uyeleri ile ilgili islem yapmak icin 2'ye tiklayiniz.\n");
	                printf("Derslerle ilgili islem yapmak icin 3'e tiklayiniz.\n");
	                printf("DERSKODU_SINIFLISTESI.txt olusturmak icin 4'e basiniz.\n");
	                printf("Cikis icin 9'a basiniz.\n");
	                scanf("%d",&secim);
					break;
				case 3:
					DersSil();
					printf("\n");
					printf("Yapmak istediginiz islemi giriniz.\n");
	                printf("Ogrencilerle ilgili islem yapmak icin 1'e tiklayiniz.\n");
	                printf("Ogretim uyeleri ile ilgili islem yapmak icin 2'ye tiklayiniz.\n");
	                printf("Derslerle ilgili islem yapmak icin 3'e tiklayiniz.\n");
	                printf("DERSKODU_SINIFLISTESI.txt olusturmak icin 4'e basiniz.\n");
	                printf("Cikis icin 9'a basiniz.\n");
	                scanf("%d",&secim);
					break;
				case 4:
					DersGuncelle();
					printf("\n");
					printf("Yapmak istediginiz islemi giriniz.\n");
	                printf("Ogrencilerle ilgili islem yapmak icin 1'e tiklayiniz.\n");
	                printf("Ogretim uyeleri ile ilgili islem yapmak icin 2'ye tiklayiniz.\n");
	                printf("Derslerle ilgili islem yapmak icin 3'e tiklayiniz.\n");
	                printf("DERSKODU_SINIFLISTESI.txt olusturmak icin 4'e basiniz.\n");
	                printf("Cikis icin 9'a basiniz.\n");
	                scanf("%d",&secim);
	                break;
				case 9:
					return 0;
			}
		break;
		case 4:
			derskodusiniflistesi();
			printf("Yapmak istediginiz islemi giriniz.\n");
			printf("Ogrencilerle ilgili islem yapmak icin 1'e basiniz.\n");
			printf("Ogretim uyeleri ile ilgili islem yapmak icin 2'ye basiniz.\n");
			printf("Derslerle ilgili islem yapmak icin 3'e basiniz.\n");
			printf("DERSKODU_SINIFLISTESI.txt olusturmak icin 4'e basiniz.\n");
			printf("Cikis icin 9'a basiniz.\n");
	        scanf("%d",&secim);
			break;
		case 9:
			return 0;
		default:
			return 0;
	}
}//while
	return 0;
}//int main

void OgrDersKayit(){
	OGRENCILER ogrenci;
	DERSLER ders;
	OgrenciDersKayit odk;
	int dersid, i=1, ogrno,temp=1, tmp=1, kredi, cont=1, dur=3, yenikredi,devam=1,var=1;
	FILE *fp, *fp1, *fp2;
	printf("Derse kaydetmek istediginiz ogrencinin numarasini giriniz.\n");
	scanf("%d",&ogrno);
	fp1=fopen("Ogrenciler.txt","r");
	if(fp1==NULL){
		printf("dosya acilamadi.\n");
	}
	while(!feof(fp1) && temp==1){
		fscanf(fp1,"%d %s %s %d %d\n",&ogrenci.OgrNo,ogrenci.ad,ogrenci.soyad,&ogrenci.topDers,&ogrenci.topKredi);
		if(ogrenci.OgrNo==ogrno){
			temp=0;
		}else{
			temp=1;
		}
	}
	//fclose(fp1);
	if(temp==0){
	printf("Kaydolunacak dersin ID'sini giriniz.\n");
	scanf("%d",&dersid);
	fp2=fopen("Dersler.txt","r");
	if(fp2==NULL){
		printf("dosya acilamadi.\n");
	}
	while(!feof(fp2) && tmp==1){
		fscanf(fp2,"%d %s %d %d %d\n",&ders.dersID,ders.dersAdi,&ders.kredi,&ders.kontenjan,&ders.ogrUyeID);
		if(ders.dersID==dersid){
			tmp=0;
			kredi=ders.kredi;
		}else{
			tmp=1;
		}
	}
	fclose(fp2);
	if(tmp==0){
		int maxk,maxd;
		printf("Ogrencinin alabilecegi maksimum kredi sayisini giriniz.\n");
		scanf("%d",&maxk);
		printf("Ogrencinin alabilecegi maksimum ders sayisini giriniz.\n");
		scanf("%d",&maxd);
		fclose(fp1);
		fp1=fopen("Ogrenciler.txt","r");
		if(fp1==NULL){
			printf("dosya acilamadi\n");
		}
		while(!feof(fp1) && cont==1){
			fscanf(fp1,"%d %s %s %d %d\n",&ogrenci.OgrNo,ogrenci.ad,ogrenci.soyad,&ogrenci.topDers,&ogrenci.topKredi);
			if(ogrenci.OgrNo==ogrno){
				yenikredi=ogrenci.topKredi+kredi;
				if(yenikredi<=maxk){
					if(ogrenci.topDers<maxd){
						dur=4;//dersi ekle
						cont=0;
					}else{
						printf("Ogrenci alabilecegi maksimum sayida dersi almis bulunmakta.\nDerse kayit edilemedi.\n");
						cont=0;
					}
				}else{
					printf("Ders, ogrencinin alabilecegi maksimum kredi sinirini asiyor.\nDerse kayit edilemedi.\n");
					cont=0;
				}
			}else{
				cont=1;
			}
		}//while
		fclose(fp1);
		if(dur==4){
		fp=fopen("OgrenciDersKayit.txt","r+");
	if(fp==NULL){
		printf("dosya acilamadi.\n");
	}
	while(!feof(fp) && devam==1){
		fscanf(fp,"%d)	<%d - %d>	Ders Durumu:%d%s\n",&odk.id,&odk.ogrno,&odk.dersno,&odk.dersdurum,odk.bilgi);
		if(odk.ogrno==ogrno && odk.dersno==dersid){
            devam=0;
		}else{
			devam=1;
		}
	}
	if(devam==0){
		if(odk.dersdurum==0){
	    odk.dersdurum=1;
	    strcpy(odk.bilgi,"(KAYITLI)");
	    fseek(fp,-12,SEEK_CUR);
	    fprintf(fp,"%d%s\n",odk.dersdurum,odk.bilgi);
	    }else{
	    	var=5;
		}
    }else{
    	odk.dersdurum=1;
    	strcpy(odk.bilgi,"(KAYITLI)");
    	fprintf(fp,"1)	<%d - %d>	Ders Durumu:%d%s\n",ogrenci.OgrNo,ders.dersID,odk.dersdurum,odk.bilgi);
	}
	fclose(fp);
	OgrenciGuncelleme(kredi,ogrno,var);
}else{
	
}
	}else{
		printf("Boyle bir ders bulunmamaktadir.\n");
	}
	}else{
		printf("Boyle bir ogrenci bulunmamaktadir.\n");
	}
	
}//fonksiyon parantezi

void OgrDersSilme(){
	OgrenciDersKayit odk,odk1,odk2;
	OGRENCILER ogrenci;
	DERSLER ders;
	FILE *fp, *fp1, *fp2, *fp3, *fp4, *fp5;
	int ogrno,temp=1,dersid,tmp=1, tmmp=1, ite=1, dur=3;
	char junk[]=" ";
	printf("OgrenciDersKayit dosyasi:\n");
	printf("	OgrNo - DersID	\n");
	fp3=fopen("OgrenciDersKayit.txt","r");
	if(fp3==NULL){
		printf("dosya acilamadi.\n");
	}
	while(!feof(fp3)){
		fscanf(fp3,"%d)	<%d - %d>	Ders Durumu:%d%s\n",&odk1.id,&odk1.ogrno,&odk1.dersno,&odk1.dersdurum,odk1.bilgi);
		printf("%d)	<%d - %d>	Ders Durumu:%d%s\n",odk1.id,odk1.ogrno,odk1.dersno,odk1.dersdurum,odk1.bilgi);
	}
	fclose(fp3);
	printf("Dersten silmek istediginiz ogrencinin numarasini giriniz.\n");
	scanf("%d",&ogrno);
	fp1=fopen("Ogrenciler.txt","r");
	if(fp1==NULL){
		printf("dosya acilamadi.\n");
	}
	while(!feof(fp1) && temp==1){
		fscanf(fp1,"%d %s %s %d %d\n",&ogrenci.OgrNo,ogrenci.ad,ogrenci.soyad,&ogrenci.topDers,&ogrenci.topKredi);
		if(ogrenci.OgrNo==ogrno){
			temp=0;
		}else{
			temp=1;
		}
	}
	fclose(fp1);
	if(temp==0){
		printf("Ogrencinin kaydinin silinecegi dersin ID'sini giriniz.\n");
		scanf("%d",&dersid);
		fp2=fopen("Dersler.txt","r");
		if(fp2==NULL){
		printf("dosya acilamadi.\n");
	}
	while(!feof(fp2) && tmp==1){
		fscanf(fp2,"%d %s %d %d %d",&ders.dersID,ders.dersAdi,&ders.kredi,&ders.kontenjan,&ders.ogrUyeID);
		if(ders.dersID==dersid){
			fp1=fopen("OgrenciDersKayit.txt","r");
			if(fp2==NULL){
		         printf("dosya acilamadi.\n");
	        }
	        while(!feof(fp1) && ite==1){
	        	fscanf(fp1,"%d)	<%d - %d>	Ders Durumu:%d%s\n",&odk2.id,&odk2.ogrno,&odk2.dersno,&odk2.dersdurum,odk2.bilgi);
	        	if(odk2.dersno==dersid && odk2.ogrno==ogrno && odk2.dersdurum==0){
	        		printf("%d no'lu ogrenci %d kodlu dersi zaten almamaktadir.\n",ogrno,dersid);
	        		printf("\n");
	        		ite=2;
	        		dur=4;
				}else{
					ite=1;
				}
			}
			fclose(fp1);
			tmp=0;
		}else{
			tmp=1;
		}
	}
	fclose(fp2);
	if(tmp==0){
		fp=fopen("OgrenciDersKayit.txt","r+");
		if(fp==NULL){
			printf("dosya acilamadi.\n");
		}
		while(!feof(fp) && tmmp==1){
			fscanf(fp,"%d)	<%d - %d>	Ders Durumu:%d%s\n",&odk.id,&odk.ogrno,&odk.dersno,&odk.dersdurum,odk.bilgi);
			if(odk.ogrno==ogrenci.OgrNo && odk.dersno==ders.dersID){
				tmmp=0;
			}else{
				tmmp=1;
			}
		}
		if(tmmp==0){
			odk.dersdurum=0;
			strcpy(odk.bilgi,"(BIRAKTI)");
			fseek(fp,-12,SEEK_CUR);
			fprintf(fp,"%d%s\n",odk.dersdurum,odk.bilgi);
			fclose(fp);
			fp3=fopen("OgrenciDersKayit.txt","r");
	        if(fp3==NULL){
		    printf("dosya acilamadi.\n");
	        }
	        while(!feof(fp3)){
		    fscanf(fp3,"%d)	<%d - %d>	Ders Durumu:%d%s\n",&odk1.id,&odk1.ogrno,&odk1.dersno,&odk1.dersdurum,odk1.bilgi);
		    printf("%d)	<%d - %d>	Ders Durumu:%d%s\n",odk1.id,odk1.ogrno,odk1.dersno,odk1.dersdurum,odk1.bilgi);
	        }
	        fclose(fp3);
		}else{
			printf("Aradiginiz eslesme bulunmamaktadir.\n");
		}
	}else{
		printf("Boyle bir ders bulunmamaktadir.\n");
	}
	}else{
		printf("Boyle bir ogrenci bulunmamaktadir.\n");
	}
    //aþaðý kýsým öðrenciler dosyasýndaki güncelleme iþlemlerini yapar.
	
	if(dur!=4){

	tmp=1;
	temp=1;
    DERSLER ders2;
    OGRENCILER *ogrenci2;
	int k=0, m=0, kredi, don=1, count=0, j;
	fp5=fopen("Dersler.txt","r");
	if(fp5==NULL){
		printf("dosya acilamadi.\n");
	}
	while(!feof(fp5) && tmp==1){
		fscanf(fp5,"%d %s %d %d %d",&ders2.dersID,ders2.dersAdi,&ders2.kredi,&ders2.kontenjan,&ders2.ogrUyeID);
		if(ders2.dersID==dersid){
			tmp=2;
			kredi=ders2.kredi;
		}else{
			tmp=1;
		}
	}
	fclose(fp5);
	fp4=fopen("Ogrenciler.txt","r");
	if(fp4==NULL){
		printf("dosya acilamadi.\n");
	}
	ogrenci2=(OGRENCILER*)malloc(sizeof(OGRENCILER));
	while(!feof(fp4) && temp==1){
		fscanf(fp4,"%d %s %s %d %d\n",&ogrenci2[m].OgrNo,ogrenci2[m].ad,ogrenci2[m].soyad,&ogrenci2[m].topDers,&ogrenci2[m].topKredi);
		if(ogrenci2[m].OgrNo==ogrno){
			ogrenci2[m].topDers-=1;
			ogrenci2[m].topKredi-=kredi;
			m++;
			ogrenci2=(OGRENCILER*)realloc(ogrenci2,(m+1)*sizeof(OGRENCILER));
		}else{
			m++;
			ogrenci2=(OGRENCILER*)realloc(ogrenci2,(m+1)*sizeof(OGRENCILER));
		}
		count++;
	}
	fclose(fp4);
	fp4=fopen("Ogrenciler.txt","w");
	if(fp4==NULL){
		printf("dosya acilamadi.\n");
	}
	for(j=0;j<count;j++){
	fprintf(fp4,"%d %s %s %d %d\n",ogrenci2[j].OgrNo,ogrenci2[j].ad,ogrenci2[j].soyad,ogrenci2[j].topDers,ogrenci2[j].topKredi);
    }
    fclose(fp4);
}else{
	
}
}//fonksiyon parantezi

void OgrenciGuncelleme(int kredi, int ogrno, int var){
	//oðrenci ders alýnca ogrenciler.txt dosyasýnda kredi ve aldýðý ders sayýsýný günceller.
	FILE *fp,*fp1,*fp2;
	OGRENCILER *ogrenciler;
	int k=0,sayac=0,m;
	fp=fopen("Ogrenciler.txt","r");
	ogrenciler=(OGRENCILER*)malloc(sizeof(OGRENCILER));
	if(var!=5){
	
	while(!feof(fp)){
		fscanf(fp,"%d %s %s %d %d\n",&ogrenciler[k].OgrNo,ogrenciler[k].ad,ogrenciler[k].soyad,&ogrenciler[k].topDers,&ogrenciler[k].topKredi);
		if(ogrenciler[k].OgrNo==ogrno){
			ogrenciler[k].topDers++;
			ogrenciler[k].topKredi+=kredi;
			k++;
		}else{
			k++;
		}
		ogrenciler=(OGRENCILER*)realloc(ogrenciler,(k+1)*sizeof(OGRENCILER));
		sayac++;
	}
	fclose(fp);
	fp=fopen("Ogrenciler.txt","w");
	if(fp==NULL){
		printf("dosya acilamadi.\n");
	}
	for(m=0;m<sayac;m++){
		fprintf(fp,"%d %s %s %d %d\n",ogrenciler[m].OgrNo,ogrenciler[m].ad,ogrenciler[m].soyad,ogrenciler[m].topDers,ogrenciler[m].topKredi);
	}
	fclose(fp);
}
	
}//fonksiyon parantezi

void OgrenciEkle(){
	int temp=1;
	OGRENCILER ogrenci, ogrenci2;
	FILE *fp;
	printf("Ogrencinin ID'sini giriniz.\n");
	scanf("%d",&ogrenci2.OgrNo);
	fp=fopen("Ogrenciler.txt","r");
	if(fp==NULL){
		printf("dosya acilamadi.\n");
	}
	while(!feof(fp) && temp==1){
		fscanf(fp,"%d %s %s %d %d\n",&ogrenci.OgrNo,ogrenci.ad,ogrenci.soyad,&ogrenci.topDers,&ogrenci.topKredi);
		if(ogrenci.OgrNo==ogrenci2.OgrNo){
			printf("Ayni ID'li bir ogrenci zaten mevcut.\n");
			temp=0;
		}else{
			temp=1;
		}
	}
	fclose(fp);
	if(temp==1){
		printf("Ogrencinin adini giriniz.\n");
		scanf("%s",ogrenci2.ad);
		printf("Ogrencinin soyadini giriniz.\n");
		scanf("%s",ogrenci2.soyad);
		ogrenci2.topDers=0;
		ogrenci2.topKredi=0;
		fp=fopen("Ogrenciler.txt","a");
		if(fp==NULL){
		printf("dosya acilamadi.\n");
		}
		fprintf(fp,"%d %s %s %d %d\n",ogrenci2.OgrNo,ogrenci2.ad,ogrenci2.soyad,ogrenci2.topDers,ogrenci2.topKredi);
		fclose(fp);
		}
	
}//fonksiyon parantezi

void OgrenciSil(){
	FILE *fp, *fp1, *fp2, *fp6;
	OGRENCILER ogrenci, *ogrenciler;
	OgrenciDersKayit *odk;
	int no, temp=1, k=0, count=0, i, m=0, sayac=0, j, tmp=1, junk;
	OgrencileriBastir();
	printf("Sistemden silmek istediginiz ogrencinin numarasini giriniz.\n");
	scanf("%d",&no);
	fp=fopen("Ogrenciler.txt","r");
	if(fp==NULL){
		printf("dosya acilamadi.\n");
	}
	//printf("xxx\n");
	while(!feof(fp) && temp==1){
		fscanf(fp,"%d %s %s %d %d\n",&ogrenci.OgrNo,ogrenci.ad,ogrenci.soyad,&ogrenci.topDers,&ogrenci.topKredi);
		if(ogrenci.OgrNo==no){
			//printf("xxx\n");
			temp=0;
		}else{
			//printf("xxx\n");
			temp=1;
		}
	}
	fclose(fp);
	ogrenciler=(OGRENCILER*)malloc(sizeof(OGRENCILER));
	if(temp==1){
		printf("Boyle bir ogrenci bulunmamaktadir.\n");
	}else{
		fp1=fopen("Ogrenciler.txt","r");
		if(fp1==NULL){
			printf("dosya acilamadi.\n");
		}
		while(!feof(fp1)){
			//printf("xxx\n");
			fscanf(fp1,"%d %s %s %d %d\n",&ogrenciler[k].OgrNo,ogrenciler[k].ad,ogrenciler[k].soyad,&ogrenciler[k].topDers,&ogrenciler[k].topKredi);
			if(ogrenciler[k].OgrNo!=no){
				k++;
				ogrenciler=(OGRENCILER*)realloc(ogrenciler,(k+1)*sizeof(OGRENCILER));
				count++;
			}else{
				
			}
		}
		//printf("%d",count);
		fclose(fp1);
		fp1=fopen("Ogrenciler.txt","w");
		if(fp1==NULL){
			printf("dosya acilamadi.\n");
		}
		for(i=0;i<count;i++){
			//printf("xxx\n");
			fprintf(fp1,"%d %s %s %d %d\n",ogrenciler[i].OgrNo,ogrenciler[i].ad,ogrenciler[i].soyad,ogrenciler[i].topDers,ogrenciler[i].topKredi);
		}
		fclose(fp1);
	
	//ogrenciderskayit'a yazan kýsým	
	fp1=fopen("OgrenciDersKayit.txt","r");
	if(fp1==NULL){
		printf("dosya acilamadi.\n");
	}
	//printf("burasi1\n");
	odk=(OgrenciDersKayit*)malloc(sizeof(OgrenciDersKayit));
	//printf("burasi2\n");
	//rewind(fp2);
	while(!feof(fp1)){
		//printf("burasi3\n");//sonsuz döngüye giriyor
		fscanf(fp1,"%d)	<%d - %d>	Ders Durumu:%d%s\n",&odk[m].id,&odk[m].ogrno,&odk[m].dersno,&odk[m].dersdurum,odk[m].bilgi);
		//printf("%d)	<%d - %d>	Ders Durumu:%d%s\n",odk[m].id,odk[m].ogrno,odk[m].dersno,odk[m].dersdurum,odk[m].bilgi);
		if(odk[m].ogrno!=no){
			//printf("burasi4\n");
			m++;
			odk=(OgrenciDersKayit*)realloc(odk,(m+1)*sizeof(OgrenciDersKayit));
			sayac++;
		}else{
			
		}
	}
	
	//printf("%d",sayac);
	fclose(fp1);
	fp=fopen("OgrenciDersKayit.txt","w");
	if(fp==NULL){
		printf("dosya acilamadi.\n");
	}
	for(j=0;j<sayac;j++){
		//printf("burasi4\n");
		fprintf(fp,"%d)	<%d - %d>	Ders Durumu:%d%s\n",odk[j].id,odk[j].ogrno,odk[j].dersno,odk[j].dersdurum,odk[j].bilgi);
	}
	fclose(fp);
	}//büyük else
	

	
}//fonksiyon parantezi

void OgrencileriBastir(){
	FILE *fp;
	OGRENCILER ogrenci5;
	fp=fopen("Ogrenciler.txt","r");
	if(fp==NULL){
		printf("dosya acilamadi.\n");
	}
	while(!feof(fp)){
		fscanf(fp,"%d %s %s %d %d\n",&ogrenci5.OgrNo,ogrenci5.ad,ogrenci5.soyad,&ogrenci5.topDers,&ogrenci5.topKredi);
		printf("%d %s %s %d %d\n",ogrenci5.OgrNo,ogrenci5.ad,ogrenci5.soyad,ogrenci5.topDers,ogrenci5.topKredi);
	}
	fclose(fp);
}

void ODKBastir(){
	FILE *fp;
	OgrenciDersKayit odk;
	fp=fopen("OgrenciDersKayit.txt","r");
	if(fp==NULL){
		printf("dosya acilamadi.\n");
	}
	while(!feof(fp)){
		fscanf(fp,"%d)	<%d - %d>	Ders Durumu:%d%s\n",&odk.id,&odk.ogrno,&odk.dersno,&odk.dersdurum,odk.bilgi);
		printf("%d)	<%d - %d>	Ders Durumu:%d%s\n",odk.id,odk.ogrno,odk.dersno,odk.dersdurum,odk.bilgi);
	}
	fclose(fp);

}

void OgrAldDersListele(){
	FILE *fp,*fp1;
	OGRENCILER ogrenci;
	OgrenciDersKayit odk;
	int ogrno,temp=1;
	printf("Aldigi dersleri gormek istediginiz ogrencinin numarasini giriniz.\n");
	scanf("%d",&ogrno);
	fp=fopen("Ogrenciler.txt","r");
	if(fp==NULL){
		printf("dosya acilamadi.\n");
	}
	while(!feof(fp) && temp==1){
		fscanf(fp,"%d %s %s %d %d\n",&ogrenci.OgrNo,ogrenci.ad,ogrenci.soyad,&ogrenci.topDers,&ogrenci.topKredi);
		if(ogrenci.OgrNo==ogrno){
			temp=0;
		}else{
			temp=1;
		}
	}
	fclose(fp);
	if(temp==1){
		printf("Boyle bir ogrenci bulunmamaktadir.\n");
	}else{
		fp1=fopen("OgrenciDersKayit.txt","r");
		if(fp1==NULL){
			printf("dosya acilamadi.\n");
		}
		while(!feof(fp1)){
			fscanf(fp1,"%d)	<%d - %d>	Ders Durumu:%d%s\n",&odk.id,&odk.ogrno,&odk.dersno,&odk.dersdurum,odk.bilgi);
			if(odk.ogrno==ogrno && odk.dersdurum==1){
				printf("<%d - %d>	Ders Durumu:%d%s\n",odk.ogrno,odk.dersno,odk.dersdurum,odk.bilgi);
			}else{
			}
		}
		fclose(fp1);
	}//büyük else
	
}//fonksiyon parantezi

void OgretimUyesiEkle(){
	OgrUyeleri ogruye, ogruye2, *uye;
	FILE *fp,*fp1;
	int temp=1,m=0,i,sayac=0;
	printf("Eklemek istediginiz ogretim uyesinin ID'sini giriniz.\nID 4 basamakli bir sayi olmalidir.\n");
	scanf("%d",&ogruye2.ogrUyeID);
	fp1=fopen("OgrUye.txt","r");
	if(fp1==NULL){
		printf("dosya acilamadi.\n");
	}
	while(!feof(fp1) && temp==1){
		fscanf(fp1,"%d %s %s %s\n",&ogruye.ogrUyeID,ogruye.ad,ogruye.soyad,ogruye.unvan);
		if(ogruye.ogrUyeID==ogruye2.ogrUyeID){
			printf("Ayni ID'li bir ogretim uyesi zaten mevcut.\n");
			temp=0;
		}else{
			temp=1;
		}
	}
	fclose(fp1);
	if(temp==1){
		printf("Eklemek istediginiz ogretim uyesinin adini giriniz.\n");
		scanf("%s",ogruye2.ad);
		printf("Eklemek istediginiz ogretim uyesinin soyadini giriniz.\n");
		scanf("%s",ogruye2.soyad);
		printf("Eklemek istediginiz ogretim uyesinin unvanini giriniz.\n");
		scanf("%s",ogruye2.unvan);
		fp=fopen("OgrUye.txt","r");
	    if(fp==NULL){
		printf("dosya acilamadi.\n");
	    }
	    uye=(OgrUyeleri*)malloc(sizeof(OgrUyeleri));
	    while(!feof(fp)){
	    	fscanf(fp,"%d %s %s %s\n",&ogruye.ogrUyeID,ogruye.ad,ogruye.soyad,ogruye.unvan);
	    //sayac++;	
		}
		if(feof){
			fp1=fopen("OgrUye.txt","a");
			if(fp1==NULL){
				printf("dosya acilamadi.\n");
			}
			fprintf(fp1,"%d %s %s %s\n",ogruye2.ogrUyeID,ogruye2.ad,ogruye2.soyad,ogruye2.unvan);
			fclose(fp1);
		}else{
		
	    rewind(fp);
		while(!feof(fp)){
        	fscanf(fp,"%d %s %s %s\n",&uye[m].ogrUyeID,uye[m].ad,uye[m].soyad,uye[m].unvan);
        	//printf("%d %s %s %s\n",uye[m].ogrUyeID,uye[m].ad,uye[m].soyad,uye[m].unvan);
        	m++;
        	uye=(OgrUyeleri*)realloc(uye,(m+1)*sizeof(OgrUyeleri));
		}
		uye[m].ogrUyeID=ogruye2.ogrUyeID;
		strcpy(uye[m].ad,ogruye2.ad);
		strcpy(uye[m].soyad,ogruye2.soyad);
		strcpy(uye[m].unvan,ogruye2.unvan);
	    fclose(fp);
	    fp=fopen("OgrUye.txt","w");
	    if(fp==NULL){
	    	printf("dosya acilamadi.\n");
		}
		for(i=0;i<=m;i++){
			//printf("%d %s %s %s\n",uye[i].ogrUyeID,uye[i].ad,uye[i].soyad,uye[i].unvan);
			fprintf(fp,"%d %s %s %s\n",uye[i].ogrUyeID,uye[i].ad,uye[i].soyad,uye[i].unvan);
		}
		fclose(fp);
		}
    }

}//fonksiyon paranezi

void DersEkle(){
	FILE *fp, *fp1;
	DERSLER ders,ders2,*derss;
	OgrUyeleri ogruye;
	int temp=1, tmp=1, m=0,i;
	printf("Eklemek istediginiz dersin kodunu giriniz.Ders kodu 3 basamakli bir sayi olmalidir.\n");
	scanf("%d",&ders2.dersID);
	fp=fopen("Dersler.txt","r");
	if(fp==NULL){
		printf("dosya acilamadi.\n");
	}
	while(!feof(fp) && temp==1){
		fscanf(fp,"%d %s %d %d %d\n",&ders.dersID,ders.dersAdi,&ders.kredi,&ders.kontenjan,&ders.ogrUyeID);
		if(ders.dersID==ders2.dersID){
			printf("Ayni ders kodlu bir ders zaten bulunmakta.\n");
			temp=0;
		}else{
			temp=1;
		}
	}
	fclose(fp);
	if(temp==1){
		printf("Dersin adini giriniz.\n");
		scanf("%s",ders2.dersAdi);
		printf("Dersin kredisini giriniz.\n");
		scanf("%d",&ders2.kredi);
		printf("Dersin kontenjanini giriniz.\n");
		scanf("%d",&ders2.kontenjan);
		printf("Dersi verecek ogretim uyesinin ID'sini giriniz.\n");
		scanf("%d",&ders2.ogrUyeID);
		fp=fopen("OgrUye.txt","r");
		if(fp==NULL){
			printf("dosya acilamadi.\n");
		}
		while(!feof(fp) && tmp==1){
			fscanf(fp,"%d %s %s %s\n",&ogruye.ogrUyeID,ogruye.ad,ogruye.soyad,ogruye.unvan);
			if(ogruye.ogrUyeID==ders2.ogrUyeID){
				tmp=0;
			}else{
				tmp=1;
			}
		}
		fclose(fp);
		derss=(DERSLER*)malloc(sizeof(DERSLER));
		if(tmp==0){
			fp=fopen("Dersler.txt","r");
			if(fp==NULL){
				printf("dosya acilamadi.\n");
			}
			while(!feof(fp)){
				fscanf(fp,"%d %s %d %d %d\n",&ders.dersID,ders.dersAdi,&ders.kredi,&ders.kontenjan,&ders.ogrUyeID);
			}
			if(feof){
				fp1=fopen("Dersler.txt","a");
				if(fp1==NULL){
					printf("dosya acilamadi.\n");
				}
				fprintf(fp1,"%d %s %d %d %d\n",ders2.dersID,ders2.dersAdi,ders2.kredi,ders2.kontenjan,ders2.ogrUyeID);
				fclose(fp1);
			}else{
			
			rewind(fp);
            while(!feof(fp)){
            	fscanf(fp,"%d %s %d %d %d\n",&derss[m].dersID,derss[m].dersAdi,&derss[m].kredi,&derss[m].kontenjan,&derss[m].ogrUyeID);
            	//printf("%d %s %d %d %d\n",derss[m].dersID,derss[m].dersAdi,derss[m].kredi,derss[m].kontenjan,derss[m].ogrUyeID);
            	m++;
            	derss=(DERSLER*)realloc(derss,(m+1)*sizeof(DERSLER));
			}
			derss[m].dersID=ders2.dersID;
			strcpy(derss[m].dersAdi,ders2.dersAdi);
			derss[m].kredi=ders2.kredi;
			derss[m].kontenjan=ders2.kontenjan;
			derss[m].ogrUyeID=ders2.ogrUyeID;
			fclose(fp);
			fp=fopen("Dersler.txt","w");
			if(fp==NULL){
				printf("dosya acilamadi.\n");
			}
			for(i=0;i<=m;i++){
				fprintf(fp,"%d %s %d %d %d\n",derss[i].dersID,derss[i].dersAdi,derss[i].kredi,derss[i].kontenjan,derss[i].ogrUyeID);
			}
			fclose(fp);
			}
		}else{
			printf("Boyle bir ogretim uyesi bulunmamaktadir.Lutfen once ana menuden ogretim uyesini ekleyiniz.\n");
		}
	
	}//buyuk if eðer ayný kodlu ders yoksa çalýþýyor
	
	
}//fonksiyon parantezi

void OgretimUyesiSil(){
	
	DERSLER ders, *derss, ders3, *ders2;
	OgrUyeleri ogruye, *uye;
	FILE *fp, *fp1, *fp8;
	int ogruyeid, count=0, devam, sayac=0, k=0, m=0, temp=1, i, n=0, derslersayac=0, j, ogruyesayac=0, counter=0;
	printf("Silmek istediginiz ogretim uyesinin ID'sini giriniz.\n");
	scanf("%d",&ogruyeid);
	fp=fopen("OgrUye.txt","r");
	if(fp==NULL){
		printf("dosya acilamadi.\n");
	}
	while(!feof(fp) && temp==1){
		fscanf(fp,"%d %s %s %s\n",&ogruye.ogrUyeID,ogruye.ad,ogruye.soyad,ogruye.unvan);
		if(ogruye.ogrUyeID==ogruyeid){
			temp=0;
		}else{
			temp=1;
		}
	}
	fclose(fp);
	if(temp==0){ //öðretim üyesi var
		fp=fopen("Dersler.txt","r");
	    if(fp==NULL){
			printf("dosya acilamadi.\n");
	    }
	    derss=(DERSLER*)malloc(sizeof(DERSLER));
		while(!feof(fp)){
			fscanf(fp,"%d %s %d %d %d\n",&ders.dersID,ders.dersAdi,&ders.kredi,&ders.kontenjan,&ders.ogrUyeID);
			if(ders.ogrUyeID==ogruyeid){
		        derss[count].dersID=ders.dersID;
		        strcpy(derss[count].dersAdi,ders.dersAdi);
		        derss[count].kredi=ders.kredi;
		        derss[count].kontenjan=ders.kontenjan;
		        derss[count].ogrUyeID=ders.ogrUyeID;
				count++; // derss struct dizisinde sadece silinecek öðretim üyesinin verdiði dersler var.
				derss=(DERSLER*)realloc(derss,(count+1)*sizeof(DERSLER));
				printf("%d %s %d %d %d\n",ders.dersID,ders.dersAdi,ders.kredi,ders.kontenjan,ders.ogrUyeID);
				devam=0;
			}else{
				counter++;
			}
			derslersayac++;
		}
		if(counter==derslersayac){
			devam=1;		//öðretim üyesi hiç ders vermiyormuþ.
		}
		if(devam==0){
			printf("Yukaridaki dersler %d ID'li ogretim uyesinin verdigi derslerdi.\n",ogruyeid);
			printf("Ekrandaki derslerin her birine yeni bir ogretim uyesi atamaniz gerekmektedir.\n");
			for(i=0;i<count;i++){
				printf("%d kodlu dersi verecek yeni ogretim uyesinin ID'sini giriniz.\n",derss[i].dersID);
				scanf("%d",&derss[i].ogrUyeID); //boyle bir ogretim uyesi var mi diye kontrol et! 
			}
			fclose(fp);
			fp1=fopen("Dersler.txt","r");
			if(fp1==NULL){
				printf("dosya acilamadi.\n");
			}
			ders2=(DERSLER*)malloc(sizeof(DERSLER));
			while(!feof(fp1)){
				fscanf(fp1,"%d %s %d %d %d\n",&ders2[k].dersID,ders2[k].dersAdi,&ders2[k].kredi,&ders2[k].kontenjan,&ders2[k].ogrUyeID);
				if(ders2[k].ogrUyeID==ogruyeid){
					ders2[k].ogrUyeID=derss[sayac].ogrUyeID;
					sayac++;
				}else{
					
				}
				k++;
				ders2=(DERSLER*)realloc(ders2,(k+1)*sizeof(DERSLER));
			}

			fclose(fp1);
			fp8=fopen("Dersler.txt","w");
			if(fp8==NULL){
				printf("dosya acilamadi.\n");
			}
			for(n=0;n<derslersayac;n++){
				fprintf(fp8,"%d %s %d %d %d\n",ders2[n].dersID,ders2[n].dersAdi,ders2[n].kredi,ders2[n].kontenjan,ders2[n].ogrUyeID);
			}
			fclose(fp8);
		}else{
			//öðretim üyesi var ama hiç ders veriyormuþ.
		}
		//öðretim üyesini OgrUye.txt'den burada sil.
		fp=fopen("OgrUye.txt","r");
		if(fp==NULL){
			printf("dosya acilamadi.\n");
		}
		k=0;
		uye=(OgrUyeleri*)malloc(sizeof(OgrUyeleri));
		while(!feof(fp)){
			fscanf(fp,"%d %s %s %s\n",&uye[k].ogrUyeID,uye[k].ad,uye[k].soyad,uye[k].unvan);
			if(uye[k].ogrUyeID==ogruyeid){
				
			}else{
			k++;
			uye=(OgrUyeleri*)realloc(uye,(k+1)*sizeof(OgrUyeleri));
			ogruyesayac++;
			}
		}
		fclose(fp);
		fp=fopen("OgrUye.txt","w");
		if(fp==NULL){
			printf("dosya acilamadi.\n");
		}
		for(i=0;i<ogruyesayac;i++){
			fprintf(fp,"%d %s %s %s\n",uye[i].ogrUyeID,uye[i].ad,uye[i].soyad,uye[i].unvan);
		}
		fclose(fp);
	}else{
		printf("Boyle bir ogretim uyesi zaten bulunmamaktadir.\n");
	}
	
}

void OgrUyeVerdDersListele(){
	
	int ogruyeid,temp=1;
	FILE *fp;
	DERSLER ders;
	OgrUyeleri ogruye;
	fp=fopen("OgrUye.txt","r");
	printf("Verdigi dersleri gormek istediginiz ogretim uyesinin ID'sini giriniz:\n");
	scanf("%d",&ogruyeid);
	if(fp==NULL){
		printf("dosya acilamadi.\n");
	}
	while(!feof(fp) && temp==1){
		fscanf(fp,"%d %s %s %s\n",&ogruye.ogrUyeID,ogruye.ad,ogruye.soyad,ogruye.unvan);
		if(ogruye.ogrUyeID=ogruyeid){
			temp=0;
		}else{
			temp=1;
		}
	}
	fclose(fp);
	fp=fopen("Dersler.txt","r");
	if(fp==NULL){
		printf("dosya acilamadi.\n");
	}	
	if(temp==0){
	while(!feof(fp)){
			fscanf(fp,"%d %s %d %d %d\n",&ders.dersID,ders.dersAdi,&ders.kredi,&ders.kontenjan,&ders.ogrUyeID);
			if(ders.ogrUyeID==ogruyeid){
				printf("%d %s %d %d %d\n",ders.dersID,ders.dersAdi,ders.kredi,ders.kontenjan,ders.ogrUyeID);
			}else{
				
			}
		}
		
	}else{
		printf("Bu ID'li bir ogretim uyesi bulunmamaktadir.\n");
	}
	fclose(fp);
	
}//fonksiyon parantezi

void DersiAlanOgrencileriListele(){
	
	int *dizi;
	dizi=(int*)calloc(200,sizeof(int));
	OGRENCILER ogrenci, ogrenci2;
	OgrenciDersKayit odk;
	DERSLER ders;
	FILE *fp;
	int derskod, temp=1, k=0, sayac=0,i,j,m;
	printf("Hangi ogrenciler tarafinden alindigini listelemek istediginiz dersin kodunu giriniz.\n");
	scanf("%d",&derskod);
	fp=fopen("Dersler.txt","r");
	if(fp==NULL){
		printf("dosya acilamadi.\n");
	}
	while(!feof(fp) && temp==1){
		fscanf(fp,"%d %s %d %d %d\n",&ders.dersID,ders.dersAdi,&ders.kredi,&ders.kontenjan,&ders.ogrUyeID);
		if(ders.dersID==derskod){
			temp=0;
		}else{
			temp=1;
		}
	}
	fclose(fp);
	if(temp==1){
		printf("Boyle bir ders bulunmamaktadir.\n");
	}else{
		fp=fopen("OgrenciDersKayit.txt","r");
		if(fp==NULL){
			printf("dosya acilamadi.\n");
		}
		while(!feof(fp)){
			fscanf(fp,"%d)	<%d - %d>	Ders Durumu:%d%s\n",&odk.id,&odk.ogrno,&odk.dersno,&odk.dersdurum,odk.bilgi);
			if(odk.dersno==derskod && odk.dersdurum==1){
				dizi[k]=odk.ogrno;
				k++;
			}else{
				
			}
		}
		fclose(fp);
		fp=fopen("Ogrenciler.txt","r");
		if(fp==NULL){
			printf("dosya acilamadi.\n");
		}
		while(!feof(fp)){
			fscanf(fp,"%d %s %s %d %d\n",&ogrenci.OgrNo,ogrenci.ad,ogrenci.soyad,&ogrenci.topDers,&ogrenci.topKredi);
			sayac++;
		}
		rewind(fp);
		for(j=0;j<k;j++){
			rewind(fp);
			for(i=0;i<sayac;i++){
				fscanf(fp,"%d %s %s %d %d\n",&ogrenci2.OgrNo,ogrenci2.ad,ogrenci2.soyad,&ogrenci2.topDers,&ogrenci2.topKredi);
				if(dizi[j]==ogrenci2.OgrNo){
					printf("%d %s %s %d %d\n",ogrenci2.OgrNo,ogrenci2.ad,ogrenci2.soyad,ogrenci2.topDers,ogrenci2.topKredi);
				}else{
					
				}
			}
		}
		fclose(fp);
	}//else
	
}//fonksiyon parantezi

void derskodusiniflistesi(){
	
	FILE *fp, *fp1;
	OgrenciDersKayit odk;
	OgrUyeleri ogruye;
	DERSLER ders;
	OGRENCILER ogrenci, ogrenci2;
	int temp=1, tmp=1, k=0, sayac=0, i ,j, ogruyeid,derskod;
	int *dizi;
	dizi=(int*)calloc(200,sizeof(int));
	printf("Ogretim Uyesinin ID'sini giriniz.\n");
	scanf("%d",&ogruyeid);
	fp=fopen("OgrUye.txt","r");
	if(fp==NULL){
		printf("dosya acilamadi.\n");
	}
	while(!feof(fp) && temp==1){
		fscanf(fp,"%d %s %s %s\n",&ogruye.ogrUyeID,ogruye.ad,ogruye.soyad,ogruye.unvan);
		if(ogruye.ogrUyeID==ogruyeid){
			temp=0;
		}else{
			temp=1;
		}
	}
	fclose(fp);
	if(temp==0){
		fp=fopen("Dersler.txt","r");
		if(fp==NULL){
			printf("dosya acilamadi.\n");
		}
		printf("Asagidaki hangi derse ait sinif listesi olusturmak istediginizi dersin kodunu girerek belirtiniz.\n");
		while(!feof(fp)){
			fscanf(fp,"%d %s %d %d %d\n",&ders.dersID,ders.dersAdi,&ders.kredi,&ders.kontenjan,&ders.ogrUyeID);
			if(ders.ogrUyeID==ogruyeid){
				printf("%d %s %d %d %d\n",ders.dersID,ders.dersAdi,ders.kredi,ders.kontenjan,ders.ogrUyeID);
			}
		}
		fclose(fp);
		scanf("%d",&derskod);
		fp=fopen("Dersler.txt","r");
		if(fp==NULL){
			printf("dosya acilamadi.\n");
		}
		while(!feof(fp) && tmp==1){
			fscanf(fp,"%d %s %d %d %d\n",&ders.dersID,ders.dersAdi,&ders.kredi,&ders.kontenjan,&ders.ogrUyeID);
			if(derskod==ders.dersID){
				tmp=0;
			}else{
				tmp=1;
			}
		}
		fclose(fp);
		if(tmp==0){
			fp=fopen("OgrenciDersKayit.txt","r");
		if(fp==NULL){
			printf("dosya acilamadi.\n");
		}
		while(!feof(fp)){
			fscanf(fp,"%d)	<%d - %d>	Ders Durumu:%d%s\n",&odk.id,&odk.ogrno,&odk.dersno,&odk.dersdurum,odk.bilgi);
			if(odk.dersno==derskod && odk.dersdurum==1){
				dizi[k]=odk.ogrno;
				k++;
			}else{
				
			}
		}
		fclose(fp);
		fp=fopen("Ogrenciler.txt","r");
		if(fp==NULL){
			printf("dosya acilamadi.\n");
		}
		while(!feof(fp)){
			fscanf(fp,"%d %s %s %d %d\n",&ogrenci.OgrNo,ogrenci.ad,ogrenci.soyad,&ogrenci.topDers,&ogrenci.topKredi);
			sayac++;
		}
		char dersAdi[30];
		dersAdi[0]='\0';
		itoa(derskod,dersAdi,10);
		strcat(dersAdi,"_SINIFLISTESI.txt");
		fp1=fopen(dersAdi,"w+");
		if(fp1==NULL){
			printf("dosya acilamadi\n");
		}
		
		rewind(fp);
		for(j=0;j<k;j++){
			rewind(fp);
			for(i=0;i<sayac;i++){
				fscanf(fp,"%d %s %s %d %d\n",&ogrenci2.OgrNo,ogrenci2.ad,ogrenci2.soyad,&ogrenci2.topDers,&ogrenci2.topKredi);
				if(dizi[j]==ogrenci2.OgrNo){
					fprintf(fp1,"%d %s %s %d %d\n",ogrenci2.OgrNo,ogrenci2.ad,ogrenci2.soyad,ogrenci2.topDers,ogrenci2.topKredi);
				}else{
					
				}
			}
		}
		fclose(fp1);
		fclose(fp);
		}else{
			printf("Boyle bir ders bulunmamaktadir.\n");
		}
	}else{
		printf("Boyle bir ogretim uyesi bulunmamaktadir.\n");
	}
	
	
}//fonksiyon parantezi

void DersSil(){
	
	FILE *fp;
	int derskod, temp=1, m=0, i, kredi, k=0, t=0, y=0, sayac=0, x=0, j, counter=0;
	int *dizi;
	dizi=(int*)calloc(200,sizeof(int));
	DERSLER ders, *derss;
	OgrenciDersKayit *odk;
	OGRENCILER *ogrenci, *ogrenci2;
	printf("Silmek istediginiz dersin kodunu giriniz.\n");
	scanf("%d",&derskod);
	fp=fopen("Dersler.txt","r");
	if(fp==NULL){
		printf("dosya acilamadi.\n");
	}
	while(!feof(fp) && temp==1){
		fscanf(fp,"%d %s %d %d %d\n",&ders.dersID,ders.dersAdi,&ders.kredi,&ders.kontenjan,&ders.ogrUyeID);
		if(ders.dersID==derskod){
			temp=0;
		}else{
			temp=1;
		}
	}
	fclose(fp);
	derss=(DERSLER*)malloc(sizeof(DERSLER));
	if(temp==0){
		fp=fopen("Dersler.txt","r");
	    if(fp==NULL){
		printf("dosya acilamadi.\n");
	    }
	    while(!feof(fp)){
	    	fscanf(fp,"%d %s %d %d %d\n",&derss[m].dersID,derss[m].dersAdi,&derss[m].kredi,&derss[m].kontenjan,&derss[m].ogrUyeID);
	    	if(derss[m].dersID!=derskod){
	    		m++;
	    		derss=(DERSLER*)realloc(derss,(m+1)*sizeof(DERSLER));
			}else{
				kredi=derss[m].kredi;
			}
		}
		fclose(fp);
		fp=fopen("Dersler.txt","w");
		if(fp==NULL){
			printf("dosya acilamadi.\n");
		}
		for(i=0;i<m;i++){
			fprintf(fp,"%d %s %d %d %d\n",derss[i].dersID,derss[i].dersAdi,derss[i].kredi,derss[i].kontenjan,derss[i].ogrUyeID);
		}
		fclose(fp);
		fp=fopen("OgrenciDersKayit.txt","r");
		if(fp==NULL){
			printf("dosya acilamadi.\n");
		}
		odk=(OgrenciDersKayit*)malloc(sizeof(OgrenciDersKayit));
		while(!feof(fp)){
			fscanf(fp,"%d)	<%d - %d>	Ders Durumu:%d%s\n",&odk[k].id,&odk[k].ogrno,&odk[k].dersno,&odk[k].dersdurum,odk[k].bilgi);
			if(odk[k].dersno!=derskod){
				k++;
				odk=(OgrenciDersKayit*)realloc(odk,(k+1)*sizeof(OgrenciDersKayit));
			}else{
				if(odk[k].dersdurum==1){
					dizi[t]=odk[k].ogrno;
					t++;
				}
			}
		}
		fclose(fp);
		fp=fopen("OgrenciDersKayit.txt","w");
		if(fp==NULL){
			printf("dosya acilamadi.\n");
		}
		for(i=0;i<k;i++){
			fprintf(fp,"%d)	<%d - %d>	Ders Durumu:%d%s\n",odk[i].id,odk[i].ogrno,odk[i].dersno,odk[i].dersdurum,odk[i].bilgi);
		}
		fclose(fp);
		fp=fopen("Ogrenciler.txt","r");
		if(fp==NULL){
			printf("dosya acilamadi.\n");
		}
		ogrenci=(OGRENCILER*)malloc(sizeof(OGRENCILER));
		while(!feof(fp)){
			fscanf(fp,"%d %s %s %d %d\n",&ogrenci[y].OgrNo,ogrenci[y].ad,ogrenci[y].soyad,&ogrenci[y].topDers,&ogrenci[y].topKredi);
			//printf("%d %s %s %d %d\n",ogrenci[y].OgrNo,ogrenci[y].ad,ogrenci[y].soyad,ogrenci[y].topDers,ogrenci[y].topKredi);
			y++;
			ogrenci=(OGRENCILER*)realloc(ogrenci,(y+1)*sizeof(OGRENCILER));
			counter++;
		}
		rewind(fp);
		for(i=0;i<t;i++){
		for(j=0;j<counter;j++){
			if(ogrenci[j].OgrNo==dizi[i]){
				ogrenci[j].topKredi-=kredi;
				ogrenci[j].topDers--;
			}else{
			}
		}
	}
	fclose(fp);
		fp=fopen("Ogrenciler.txt","w");
	if(fp==NULL){
		printf("dosya acilamadi.\n");
	}
	for(i=0;i<counter;i++){
		fprintf(fp,"%d %s %s %d %d\n",ogrenci[i].OgrNo,ogrenci[i].ad,ogrenci[i].soyad,ogrenci[i].topDers,ogrenci[i].topKredi);
	}
	fclose(fp);
		//OgrenciKrediGuncellemeV2(derskod,kredi,dizi[200]);
	}else{
		printf("Sistemde zaten boyle bir ders bulunmamaktadir.");
	}
	
	
}

void OgrenciGuncelle(){
	
	//char ad[20], soyad[20];
	char *ad, *soyad;
	ad=(char*)calloc(20,sizeof(char));
	soyad=(char*)calloc(20,sizeof(char));
	int temp=1, sayac=0, k=0, ogrno, i;
	FILE *fp;
	OGRENCILER ogrenci, *ogrenci1;
	printf("Ogrencinin sadece adini veya soyadini guncelleyebilirsiniz.\nOgrencinin adi ve soyadi tek kelimeden olusmalidir.\n");
	printf("Guncellemek istediginiz ogrencinin numarasini giriniz.\n");
	scanf("%d",&ogrno);
	fp=fopen("Ogrenciler.txt","r");
	if(fp==NULL){
		printf("dosya acilamadi.\n");
	}
	while(!feof(fp) && temp==1){
		fscanf(fp,"%d %s %s %d %d\n",&ogrenci.OgrNo,ogrenci.ad,ogrenci.soyad,&ogrenci.topDers,&ogrenci.topKredi);
		if(ogrenci.OgrNo==ogrno){
			temp=0;
		}else{
		}
	}
	fclose(fp);
	if(temp==0){
	fp=fopen("Ogrenciler.txt","r");
	if(fp==NULL){
		printf("dosya acilamadi.\n");
	}
		printf("Ogrencinin yeni adini giriniz.\n");
		scanf("%s",ad);
		printf("Ogrencinin yeni soyadini giriniz.\n");
		scanf("%s",soyad);
		ogrenci1=(OGRENCILER*)malloc(sizeof(OGRENCILER));
		while(!feof(fp)){
			fscanf(fp,"%d %s %s %d %d\n",&ogrenci1[k].OgrNo,ogrenci1[k].ad,ogrenci1[k].soyad,&ogrenci1[k].topDers,&ogrenci1[k].topKredi);
			if(ogrenci1[k].OgrNo==ogrno){
				strcpy(ogrenci1[k].ad,ad);
				strcpy(ogrenci1[k].soyad,soyad);
			}else{
			
			}
			k++;
			sayac++;
			ogrenci1=(OGRENCILER*)realloc(ogrenci1,(k+1)*sizeof(OGRENCILER));
		}
		fclose(fp);
		fp=fopen("Ogrenciler.txt","w");
		if(fp==NULL){
			printf("dosya acilamadi.\n");
		}
	
		for(i=0;i<sayac;i++){
			fprintf(fp,"%d %s %s %d %d\n",ogrenci1[i].OgrNo,ogrenci1[i].ad,ogrenci1[i].soyad,ogrenci1[i].topDers,ogrenci1[i].topKredi);
		}
		fclose(fp);
		
	}else{
		printf("Boyle bir ogrenci bulunamamaktadir.\n");
	}

	
}

void OgretimUyesiGuncelle(){
	
	char junk;
	FILE *fp, *fp1;
	//char ad[20], soyad[20], unvan[20];
	char *ad, *soyad, *unvan;
	ad=(char*)calloc(20,sizeof(char));
	soyad=(char*)calloc(20,sizeof(char));
	unvan=(char*)calloc(20,sizeof(char));
	OgrUyeleri ogruye, *uye;
	int ogruyeid, temp=1, choice, k=0, kontrol=1, sayac=0, i, choice2, choice3;
	printf("Ogretim uyesinin adini, soyadini ve unvanini guncelleyebilirsiniz.\n");
	printf("Her biri tek kelime olmalidir.\n");
	printf("Guncellemek istediginiz ogretim uyesinin ID'sini giriniz.\n");
	scanf("%d",&ogruyeid);
	fp=fopen("OgrUye.txt","r");
	if(fp==NULL){
		printf("dosya acilamadi.\n");
	}
	while(!feof(fp) && temp==1){
		fscanf(fp,"%d %s %s %s\n",&ogruye.ogrUyeID,ogruye.ad,ogruye.soyad,ogruye.unvan);
		if(ogruye.ogrUyeID==ogruyeid){
			temp=0;
		}else{
		}
	}
	rewind(fp);
	while(!feof(fp)){
		fscanf(fp,"%d %s %s %s\n",&ogruye.ogrUyeID,ogruye.ad,ogruye.soyad,ogruye.unvan);
		sayac++;
	}
	fclose(fp);
  if(temp==0){
		printf("Ogretim uyesinin adini guncellemek istiyor musunuz?\nEvet icin 1'e, Hayir icin 2'ye basiniz.\n");
		scanf("%d",&choice);
		if(choice==1){
			printf("Ogretim uyesinin yeni adini giriniz.\n");
			scanf("%s",ad);
			fp=fopen("OgrUye.txt","r");
			if(fp==NULL){
				printf("dosya acilamadi.\n");
			}
			uye=(OgrUyeleri*)malloc(sizeof(OgrUyeleri));
			while(!feof(fp)){
				fscanf(fp,"%d %s %s %s\n",&uye[k].ogrUyeID,uye[k].ad,uye[k].soyad,uye[k].unvan);
				//printf("%d %s %s %s\n",uye[k].ogrUyeID,uye[k].ad,uye[k].soyad,uye[k].unvan);
				if(uye[k].ogrUyeID==ogruyeid){
					strcpy(uye[k].ad,ad);
				}else{
				}
				k++;
				uye=(OgrUyeleri*)realloc(uye,(k+1)*sizeof(OgrUyeleri));
			}
			
		}else{
		}
		fp1=fopen("OgrUye.txt","w");
		if(fp1==NULL){
			printf("dosya acilamadi.\n");
	}
		for(i=0;i<sayac;i++){
			fprintf(fp1,"%d %s %s %s\n",uye[i].ogrUyeID,uye[i].ad,uye[i].soyad,uye[i].unvan);
		}
		fclose(fp1);

		k=0;
		rewind(fp);
		printf("Ogretim uyesinin soyadini guncellemek istiyor musunuz?\nEvet icin 1'e, Hayir icin 2'ye basiniz.\n");
		scanf("%d",&choice2);
		if(choice2==1){
			printf("Ogretim uyesinin yeni soyadini giriniz.\n");
			scanf("%s",soyad);
			while(!feof(fp)){
				fscanf(fp,"%d %s %s %s\n",&uye[k].ogrUyeID,uye[k].ad,uye[k].soyad,uye[k].unvan);
				//printf("%d %s %s %s\n",uye[k].ogrUyeID,uye[k].ad,uye[k].soyad,uye[k].unvan);
				if(uye[k].ogrUyeID==ogruyeid){
					strcpy(uye[k].soyad,soyad);
				}else{
				}
				k++;
			}
		}else{
		}
		fp1=fopen("OgrUye.txt","w");
		if(fp1==NULL){
			printf("dosya acilamadi.\n");
	}
		for(i=0;i<sayac;i++){
			fprintf(fp1,"%d %s %s %s\n",uye[i].ogrUyeID,uye[i].ad,uye[i].soyad,uye[i].unvan);
		}
		fclose(fp1);
		k=0;
		rewind(fp);
		printf("Ogretim uyesinin unvanini guncellemek istiyor musunuz?\nEvet icin 1'e, Hayir icin 2'ye basiniz.\n");
		scanf("%d",&choice3);
		if(choice3==1){
			printf("Ogretim uyesinin yeni unvanini giriniz.\n");
			scanf("%s",unvan);
			while(!feof(fp)){
				fscanf(fp,"%d %s %s %s\n",&uye[k].ogrUyeID,uye[k].ad,uye[k].soyad,uye[k].unvan);
				//printf("%d %s %s %s\n",uye[k].ogrUyeID,uye[k].ad,uye[k].soyad,uye[k].unvan);
				if(uye[k].ogrUyeID==ogruyeid){
				strcpy(uye[k].unvan,unvan);
				}else{
				}
				k++;
			}
		}else{
		}
		
		fclose(fp);
		fp1=fopen("OgrUye.txt","w");
		if(fp1==NULL){
			printf("dosya acilamadi.\n");
	}
		//k=0;
		for(i=0;i<sayac;i++){
			fprintf(fp1,"%d %s %s %s\n",uye[i].ogrUyeID,uye[i].ad,uye[i].soyad,uye[i].unvan);
		}
		fclose(fp1);
      
	}else{
		printf("Boyle bir ogretim uyesi bulunmamaktadir.\n");
	}
}//fonksiyon parantezi

void DersGuncelle(){
	
	//char ad[20];
	char *ad;
	ad=(char*)calloc(20,sizeof(char));
	int temp=1, sayac=0, k=0, derskod, choice, choice2, choice3, choice4, i, kontenjan, ogruyeid, kredi, eskikredi;
	DERSLER ders, *dersler;
	OgrUyeleri ogruye;
	FILE *fp, *fp1, *fp2;
	printf("Dersin adini, kredisini, kontenjanini ve dersi veren ogretim uyesini degistirebilirsiniz.\n");
	printf("Guncellemek istediginiz dersin kodunu giriniz.\n");
	scanf("%d",&derskod);
	fp=fopen("Dersler.txt","r");
	if(fp==NULL){
		printf("dosya acilamadi.\n");
	}
	while(!feof(fp) && temp==1){
		fscanf(fp,"%d %s %d %d %d\n",&ders.dersID,ders.dersAdi,&ders.kredi,&ders.kontenjan,&ders.ogrUyeID);
		if(ders.dersID==derskod){
			temp=0;
		}
	}
	rewind(fp);
	while(!feof(fp)){
		fscanf(fp,"%d %s %d %d %d\n",&ders.dersID,ders.dersAdi,&ders.kredi,&ders.kontenjan,&ders.ogrUyeID);
		sayac++;
	}
	rewind(fp);
	dersler=(DERSLER*)malloc(sizeof(DERSLER));
	while(!feof(fp)){
		fscanf(fp,"%d %s %d %d %d\n",&dersler[k].dersID,dersler[k].dersAdi,&dersler[k].kredi,&dersler[k].kontenjan,&dersler[k].ogrUyeID);
		//printf("%d %s %d %d %d\n",dersler[k].dersID,dersler[k].dersAdi,dersler[k].kredi,dersler[k].kontenjan,dersler[k].ogrUyeID);
		k++;
		dersler=(DERSLER*)realloc(dersler,(k+1)*sizeof(DERSLER));
	}
	fclose(fp);
	if(temp==0){
		fp=fopen("Dersler.txt","r");
		if(fp==NULL){
			printf("dosya acilamadi.\n");
		}
		printf("Dersin adini guncellemek istiyor musunuz?\nEvet icin 1'e, Hayir icin 2'ye basiniz.\n");
		scanf("%d",&choice);
		if(choice==1){
		printf("Dersin yeni adini giriniz.\nDersin adi tek kelimeden olusmalidir.\n");
		scanf("%s",ad);
		k=0;
		while(!feof(fp)){
			fscanf(fp,"%d %s %d %d %d\n",&dersler[k].dersID,dersler[k].dersAdi,&dersler[k].kredi,&dersler[k].kontenjan,&dersler[k].ogrUyeID);
			//printf("%d %s %d %d %d\n",dersler[k].dersID,dersler[k].dersAdi,dersler[k].kredi,dersler[k].kontenjan,dersler[k].ogrUyeID);
			if(dersler[k].dersID==derskod){
				strcpy(dersler[k].dersAdi,ad);
			}else{
			}
			k++;

		}
		fp1=fopen("Dersler.txt","w");
		if(fp1==NULL){
			printf("dosya acilamadi.\n");
		}
		for(i=0;i<sayac;i++){
			fprintf(fp1,"%d %s %d %d %d\n",dersler[i].dersID,dersler[i].dersAdi,dersler[i].kredi,dersler[i].kontenjan,dersler[i].ogrUyeID);
		}
		fclose(fp1);
	}else{
	}
	

	
	printf("Dersin kontenjanini degistirmek istiyor musunuz?\nEvet icin 1'e, Hayir icin 2'ye basiniz.\n");
	scanf("%d",&choice2);
	if(choice2==1){
		printf("Dersin yeni kontenjanini giriniz.\n");
		scanf("%d",&kontenjan);
			//if(choice==2){
			//}else{
			
			k=0;
			rewind(fp);
			//}
		while(!feof(fp)){
			fscanf(fp,"%d %s %d %d %d\n",&dersler[k].dersID,dersler[k].dersAdi,&dersler[k].kredi,&dersler[k].kontenjan,&dersler[k].ogrUyeID);
			//printf("%d %s %d %d %d\n",dersler[k].dersID,dersler[k].dersAdi,dersler[k].kredi,dersler[k].kontenjan,dersler[k].ogrUyeID);
			if(dersler[k].dersID==derskod){
				dersler[k].kontenjan=kontenjan;
			}else{
			}
			k++;
		}
		fp1=fopen("Dersler.txt","w");
		if(fp1==NULL){
			printf("dosya acilamadi.\n");
		}
		for(i=0;i<sayac;i++){
			fprintf(fp1,"%d %s %d %d %d\n",dersler[i].dersID,dersler[i].dersAdi,dersler[i].kredi,dersler[i].kontenjan,dersler[i].ogrUyeID);
		}
		fclose(fp1);
	}else{
	}
	

	
	printf("Dersi veren ogretim uyesini degistirmek istiyor musunuz?\nEvet icin 1'e, Hayir icin 2'ye basiniz.\n");
	scanf("%d",&choice3);
	if(choice3==1){
		printf("Dersi verecek yeni ogretim uyesinin ID'sini giriniz.\n");
		scanf("%d",&ogruyeid);
		fp2=fopen("OgrUye.txt","r");
		if(fp2==NULL){
			printf("dosya acilamadi.\n");
		}
		while(!feof(fp2) && temp==1){
			fscanf(fp2,"%d %s %s %s\n",&ogruye.ogrUyeID,ogruye.ad,ogruye.soyad,ogruye.unvan);
			if(ogruye.ogrUyeID==ogruyeid){
				temp=0;
			}else{
			}
		}
		fclose(fp2);
		if(temp==0){
			k=0;
			rewind(fp);
			while(!feof(fp)){
				fscanf(fp,"%d %s %d %d %d\n",&dersler[k].dersID,dersler[k].dersAdi,&dersler[k].kredi,&dersler[k].kontenjan,&dersler[k].ogrUyeID);
				//printf("%d %s %d %d %d\n",dersler[k].dersID,dersler[k].dersAdi,dersler[k].kredi,dersler[k].kontenjan,dersler[k].ogrUyeID);
				if(dersler[k].dersID==derskod){
					dersler[k].ogrUyeID=ogruyeid;
				}else{
				}
				k++;
			}
			fp1=fopen("Dersler.txt","w");
			if(fp1==NULL){
				printf("dosya acilamadi.\n");
			}
			for(i=0;i<sayac;i++){
				fprintf(fp1,"%d %s %d %d %d\n",dersler[i].dersID,dersler[i].dersAdi,dersler[i].kredi,dersler[i].kontenjan,dersler[i].ogrUyeID);
			}
			fclose(fp1);
		}else{
			printf("Boyle bir ogretim uyesi bulunmamaktadir.\n");
		}
	}else{
	}
	
	fclose(fp);
	
	fp=fopen("Dersler.txt","r");
	if(fp==NULL){
		printf("dosya acilamadi.\n");
	}
	printf("Dersin kredisini degistirmek istiyor musunuz?\nEvet icin 1'e, Hayir icin 2'ye basiniz.\n");
	scanf("%d",&choice4);
	if(choice4==1){
		printf("Dersin yeni kredi bilgisini giriniz.\n");
		scanf("%d",&kredi);
		printf("kredi=%d\n",kredi);
		//rewind(fp);
			k=0;
			//rewind(fp);
		while(!feof(fp)){
			fscanf(fp,"%d %s %d %d %d\n",&dersler[k].dersID,dersler[k].dersAdi,&dersler[k].kredi,&dersler[k].kontenjan,&dersler[k].ogrUyeID);
			//printf("%d %s %d %d %d\n",dersler[k].dersID,dersler[k].dersAdi,dersler[k].kredi,dersler[k].kontenjan,dersler[k].ogrUyeID);
			if(dersler[k].dersID==derskod){
				eskikredi=dersler[k].kredi;
				dersler[k].kredi=kredi;
			}
			k++;
		}
		fclose(fp);
		fp1=fopen("Dersler.txt","w");
		if(fp1==NULL){
			printf("dosya acilamadi.\n");
		}
		for(i=0;i<sayac;i++){
			fprintf(fp1,"%d %s %d %d %d\n",dersler[i].dersID,dersler[i].dersAdi,dersler[i].kredi,dersler[i].kontenjan,dersler[i].ogrUyeID);
		}
		fclose(fp1);
		OgrenciKrediGuncelleme(derskod,kredi,eskikredi);
	}else{
	}
	
	
	}else{
		printf("Boyle bir ders bulunmamaktadir.\n");
	}
	
}//fonksiyon parantezi

void OgrenciKrediGuncelleme(int derskod, int kredi, int eskikredi){
	//printf("derskod:%d\n",derskod);
	//printf("yenikredi:%d\n",kredi);
	//printf("eskikredi:%d\n",eskikredi);
	FILE *fp;
	OgrenciDersKayit odk;
	OGRENCILER *ogrenci;
	DERSLER ders, *dersler;
	int w=0, i, j, k=0, counter=0;
	int *dizi;
	dizi=(int*)calloc(200,sizeof(int));
	fp=fopen("OgrenciDersKayit.txt","r");
	if(fp==NULL){
		printf("dosya acilamadi.\n");
	}
	//printf("burasi1\n");
	while(!feof(fp)){
		//printf("burasi2\n");
		fscanf(fp,"%d)	<%d - %d>	Ders Durumu:%d%s\n",&odk.id,&odk.ogrno,&odk.dersno,&odk.dersdurum,odk.bilgi);
		if(odk.dersno==derskod && odk.dersdurum==1){
			dizi[w]=odk.ogrno;
			//printf("%d\n",dizi[w]);
			w++;
		}
	}
	fclose(fp);
	fp=fopen("Ogrenciler.txt","r");
	if(fp==NULL){
		printf("dosya acilamadi.\n");
	}
	//rewind(fp);
	ogrenci=(OGRENCILER*)malloc(sizeof(OGRENCILER));
	while(!feof(fp)){
		fscanf(fp,"%d %s %s %d %d\n",&ogrenci[k].OgrNo,ogrenci[k].ad,ogrenci[k].soyad,&ogrenci[k].topDers,&ogrenci[k].topKredi);
		//printf("%d %s %s %d %d\n",ogrenci[k].OgrNo,ogrenci[k].ad,ogrenci[k].soyad,ogrenci[k].topDers,ogrenci[k].topKredi);
		k++;
		ogrenci=(OGRENCILER*)realloc(ogrenci,(k+1)*sizeof(OGRENCILER));
		counter++;
	}
	rewind(fp);
	for(i=0;i<w;i++){
		for(j=0;j<counter;j++){
			if(ogrenci[j].OgrNo==dizi[i]){
				ogrenci[j].topKredi+=kredi-eskikredi;
			}else{
			}
		}
	}
	fclose(fp);
	fp=fopen("Ogrenciler.txt","w");
	if(fp==NULL){
		printf("dosya acilamadi.\n");
	}
	for(i=0;i<counter;i++){
		fprintf(fp,"%d %s %s %d %d\n",ogrenci[i].OgrNo,ogrenci[i].ad,ogrenci[i].soyad,ogrenci[i].topDers,ogrenci[i].topKredi);
	}
	fclose(fp);
	
}//fonksiyon parantezi

