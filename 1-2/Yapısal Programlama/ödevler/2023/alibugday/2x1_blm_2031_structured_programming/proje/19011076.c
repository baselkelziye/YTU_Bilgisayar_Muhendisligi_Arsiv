#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KREDI_MAX 25
#define DERS_MAX 10
#define MAX_KAPASITE 200
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


typedef struct ogr_ders{
	int id;
	char *kod;
	int ogr_numara;
	char *tarih;
	char *durum;
}OGR_DERS;

typedef struct linked1{
	char *ders_kodu;
	char *ders_adi;
	int kapasite;
	int kredi;
	OGR_DERS *numaralar;
	int ogr_num_sayisi;
	struct linked1 *onceki;	 
}LINKED1;

typedef struct linked2{
	int no;
	int numara;
	char *isim_soyisim;
	int alinan_toplam_ders;
	int aldigi_kredi;
	struct linked2 *onceki, *sonraki;
}LINKED2;


void swap(struct linked1 *a, struct linked1 *b);//linked1 icin
void swap2(struct linked2 *a, struct linked2 *b);//linked2 icin
void bubbleSort(struct linked1 *start);//linked1 siralar
void bubbleSort2(struct linked2 *start);//linked2 siralar
void linked1_listele(struct linked1 *yiginustu);
void linked2_listele(struct linked2 *listebaslangici);
LINKED1* linked1_olustur();
LINKED2* linked2_olustur();
void dersler_ekle();
void ogrenci_ekle();
void kayit_ekle();
void ders_sil();
void ogrenci_sil();
void derskyt_sil();
void dersler_yazdir(LINKED1 *start);
void ogrenciler_yazdir(LINKED2 *start);
void derskyt_yazdir(LINKED1 *start);
void ogr_num_yazdir();
void ders_kod_yazdir();

int main() {
	LINKED1 *yiginustu=NULL,*temp;
	LINKED2 *listebaslangici=NULL,*listesonu=NULL,*yenieleman;
	/*
	FILE* olustur;
	olustur = fopen("OgrenciDersKayit.txt", "a");
	fclose(olustur);
	olustur = fopen("ogrenciler.txt", "a");
	fclose(olustur);
	olustur = fopen("dersler.txt", "a");
	fclose(olustur);
	olustur = fopen("deneme.txt", "a");
	fseek(olustur, 0, SEEK_END);
	if(ftell(olustur) == 0){
		fprintf(olustur, "00000");
	}
	fclose(olustur);
	*/
	int choice=1;
	void (*fonk_secim[])(void) = {dersler_ekle, ders_sil, ogrenci_ekle, ogrenci_sil, kayit_ekle, derskyt_sil, ogr_num_yazdir, ders_kod_yazdir};
	while(choice != 0){
		yiginustu=linked1_olustur();
		temp=yiginustu;
		listebaslangici=linked2_olustur();
		yenieleman=listebaslangici;
		printf("\n\nislem numarasi seciniz:\n"
		"1. Ders ekle\n"
		"2. Ders sil\n"
		"3. Ogrenci ekle\n"
		"4. Ogrenci sil\n"
		"5. Ders kayit ekle\n"
		"6. Ders kayit sil\n"
		"7. Ogrencinin kayit oldugu dersleri yazdir\n"
		"8. Derse kaydolmus ogrencileri yazdir \n"
		"9. Birinci linkli listeyi listele \n"//9. ve 10. secenekleri ekstradan koydum
		"10.Ikinci linkli listeyi listele \n"
		"0. cikis\n\n");
		scanf("%d", &choice);
		if(choice < 1 || choice > 10){
			printf("Gecersiz islem\n");
		}else{
			if (choice==9 || choice==10){
				if(choice==9){
					linked1_listele(temp);
				}
				else{
					linked2_listele(yenieleman);
				}
			}
			else{
				(*fonk_secim[choice-1])();
			}
		}
	}
	
	return 0;

}

//-----------------------------------------------------------------------------------------------------

LINKED2* linked2_olustur(){
	LINKED2 *listebaslangici=NULL,*listesonu=NULL,*yenieleman;
	int i=0,ch;
	FILE *oku;
	
	oku=fopen("ogrenciler.txt","r");
	
	while(ch != EOF){
		yenieleman=(LINKED2*)malloc(sizeof(struct linked2));
		yenieleman->isim_soyisim=(char*)malloc(40*sizeof(char));
		
		
		fscanf(oku, "%d %[^/]/ %d %d", &yenieleman->numara, yenieleman->isim_soyisim, &yenieleman->aldigi_kredi, &yenieleman->alinan_toplam_ders);
		yenieleman->no=i+1;
		i+=1;
		
		if (listebaslangici==NULL){
			listebaslangici=yenieleman;
			listesonu=yenieleman;
			listebaslangici->sonraki=NULL;
			listebaslangici->onceki=NULL;
		}else{
			listesonu->sonraki=yenieleman;
			yenieleman->onceki=listesonu;
			listesonu=yenieleman;
			listesonu->sonraki=NULL;
		}
		ch = fgetc(oku);
	}
	fclose(oku);
	
	return listebaslangici;
}

//-----------------------------------------------------------------------------------------------------

LINKED1* linked1_olustur(){
	int ch,ch2,i,j;
	LINKED1 *yiginustu=NULL,*temp;
	OGR_DERS *ogr_dersk;
	
	FILE *oku;
	temp=yiginustu;
	oku=fopen("dersler.txt","r");
	
	
	while(ch != EOF){
		temp=(LINKED1*)malloc(sizeof(LINKED1));
		temp->ders_kodu=(char*)malloc(7);
		temp->ders_adi=(char*)malloc(45*sizeof(char));
		temp->numaralar=(OGR_DERS*)malloc(sizeof(OGR_DERS));
		fscanf(oku, "%s %[^/]/ %d %d", temp->ders_kodu, temp->ders_adi, &temp->kredi, &temp->kapasite);
		FILE *oku2;
		oku2=fopen("OgrenciDersKayit.txt","r");
		int N=1;
		do{
			ogr_dersk=(OGR_DERS*)malloc(sizeof(OGR_DERS));
			ogr_dersk->durum=(char*)malloc(20*sizeof(char));
			ogr_dersk->kod=(char*)malloc(7*sizeof(char));
			ogr_dersk->tarih=(char*)malloc(20*sizeof(char));
			fscanf(oku2,"%d %s %d %s %[^/]/",&ogr_dersk->id, ogr_dersk->kod, &ogr_dersk->ogr_numara, ogr_dersk->tarih,ogr_dersk->durum);
			if ((strcmp(temp->ders_kodu,ogr_dersk->kod)==0)  && (strcmp(ogr_dersk->durum,"kayitli")==0)){
				temp->numaralar=(OGR_DERS*)realloc(temp->numaralar,N*sizeof(OGR_DERS));
				temp->numaralar[N-1].id=ogr_dersk->id;
				temp->numaralar[N-1].kod=ogr_dersk->kod;
				temp->numaralar[N-1].ogr_numara=ogr_dersk->ogr_numara;
				temp->numaralar[N-1].tarih=ogr_dersk->tarih;
				temp->numaralar[N-1].durum=ogr_dersk->durum;
				N+=1;
			}
			temp->ogr_num_sayisi=N-1;			
			ch2 = fgetc(oku2);
			free(ogr_dersk);				
		}while(ch2 != EOF);
		
		temp->onceki=yiginustu;
		yiginustu=temp;
		ch = fgetc(oku);
	}
	fclose(oku);
	temp=yiginustu;
	return temp;
}


//------------------------------------------------------------------------------------------------------------


void linked1_listele(struct linked1 *start){
	LINKED1 *yiginustu=NULL,*temp;
	temp=start;
	int i=0,j, max_len;
	while(temp!=NULL){
		printf("%s %s %d %d",temp->ders_kodu,temp->ders_adi,temp->kredi,temp->kapasite);
		for (i=0;i<temp->ogr_num_sayisi;i++){
			printf(" %d",temp->numaralar[i].ogr_numara);
		}
		printf("\n");
		
		temp=temp->onceki;
	}
	
}

void linked2_listele(struct linked2 *start){
	LINKED2 *listebaslangici=NULL,*listesonu=NULL,*yenieleman;
	yenieleman=start;
	
	while(yenieleman!=NULL){
		printf("numarasi:%d\n",yenieleman->no);
		printf("isim soyisim:%s\n",yenieleman->isim_soyisim);
		printf("numarasi:%d\n",yenieleman->numara);
		printf("toplam kredi:%d\n",yenieleman->aldigi_kredi);
		printf("toplam aldigi ders:%d\n",yenieleman->alinan_toplam_ders);
		yenieleman=yenieleman->sonraki;
		printf("================================\n");
	}
}

//----------------------------------------------------------------------------------------------------------------------

void dersler_yazdir(LINKED1 *start){
	LINKED1 *yiginustu=NULL,*temp;
	FILE* oku = fopen("dersler.txt", "w");	
	
	temp=start;
	bubbleSort(temp);
	
	while(temp->onceki!=NULL){
		fprintf(oku, "%s %s/ %d %d\n", temp->ders_kodu, temp->ders_adi, temp->kredi, temp->kapasite);
		temp=temp->onceki;
	}
	fprintf(oku, "%s %s/ %d %d", temp->ders_kodu, temp->ders_adi, temp->kredi, temp->kapasite);
	temp=temp->onceki;
	fclose(oku);
	
}

void derskyt_yazdir(LINKED1 *start){
	int ch,i,flag,flag2=0,prev_id=15654;
	LINKED1 *yiginustu=NULL,*temp;
	OGR_DERS *derskayit=(OGR_DERS*)malloc(sizeof(OGR_DERS));
	derskayit->kod=(char*)malloc(8*sizeof(char));
	derskayit->tarih=(char*)malloc(15*sizeof(char));
	derskayit->durum=(char*)malloc(20*sizeof(char));
	
	FILE* oku = fopen("OgrenciDersKayit.txt", "r");
	FILE* yaz = fopen("deneme.txt", "w");
	
	
	
	yiginustu=start;
	//bubbleSort(yiginustu);
	while(ch!=EOF){
		
		fscanf(oku,"%d %s %d %s %[^/]/",&derskayit->id, derskayit->kod, &derskayit->ogr_numara, derskayit->tarih,derskayit->durum);
		temp=yiginustu;
		flag=0;
		while(temp!=NULL){
			for (i=0;i<temp->ogr_num_sayisi;i++){
				if (derskayit->id==temp->numaralar[i].id){
					fprintf(yaz, "%d %s %d %s %s/\n", temp->numaralar[i].id, temp->numaralar[i].kod, temp->numaralar[i].ogr_numara, temp->numaralar[i].tarih,temp->numaralar[i].durum);
					flag=1;
				}
			}
			temp=temp->onceki;
		}
		
		if (flag==0){
			fprintf(yaz, "%d %s %d %s %s/\n", derskayit->id, derskayit->kod, derskayit->ogr_numara, derskayit->tarih,derskayit->durum);
		}
		
		ch = fgetc(oku);
	}
	fclose(oku);
	fclose(yaz);
	

	//temp dosyasina okunan verileri tekrar derskayit dosyasýna gecirme
	oku = fopen("deneme.txt", "r");
	yaz = fopen("OgrenciDersKayit.txt","w");
	int ch2;
	fscanf(oku,"%d %s %d %s %[^/]/",&derskayit->id, derskayit->kod, &derskayit->ogr_numara, derskayit->tarih,derskayit->durum);
	fprintf(yaz, "%d %s %d %s %s/", derskayit->id, derskayit->kod, derskayit->ogr_numara, derskayit->tarih,derskayit->durum);
	prev_id=derskayit->id;
	ch2 = fgetc(oku);
	while(ch2!=EOF){
		fscanf(oku,"%d %s %d %s %[^/]/",&derskayit->id, derskayit->kod, &derskayit->ogr_numara, derskayit->tarih,derskayit->durum);
		if(derskayit->id!=prev_id){
			fprintf(yaz, "\n%d %s %d %s %s/", derskayit->id, derskayit->kod, derskayit->ogr_numara, derskayit->tarih,derskayit->durum);
		}
		ch2 = fgetc(oku);
		prev_id=derskayit->id;
	}
	
	fclose(oku);
	fclose(yaz);
}

void ogrenciler_yazdir(LINKED2 *start){
	//LINKED2 gecici;
	LINKED2 *listebaslangici=NULL,*listesonu=NULL,*yenieleman;
	FILE* oku = fopen("ogrenciler.txt", "w");	
	
	yenieleman=start;
	bubbleSort2(yenieleman);
	//printf("flag");
	while(yenieleman->sonraki!=NULL){
		//printf("flag2");
		fprintf(oku, "%d %s/ %d %d\n", yenieleman->numara, yenieleman->isim_soyisim, yenieleman->aldigi_kredi, yenieleman->alinan_toplam_ders); 
		yenieleman=yenieleman->sonraki;
	}
	fprintf(oku, "%d %s/ %d %d", yenieleman->numara, yenieleman->isim_soyisim, yenieleman->aldigi_kredi, yenieleman->alinan_toplam_ders);
	yenieleman=yenieleman->sonraki;
	fclose(oku);
}

//--------------------------------------------------------------------------------------------------------------------

void dersler_ekle(){
	LINKED1 *yiginustu=NULL,*temp;
	OGR_DERS *ogr_dersk;
	char* kod = (char*) malloc(7);
	char* ders_isim=(char*) malloc(40);
	char deneme;
	int ch2,kredi,kapasite; 
	yiginustu=linked1_olustur();
	temp=yiginustu;
	
	printf("Eklenecek dersin kodunu giriniz:\n");
	scanf("%s", kod);
	
	while(!temp==NULL){
		if(strcmp(temp->ders_kodu,kod)==0){
			printf("ders kodu zaten mevcut");
			return;
		}
		temp=temp->onceki;
	}
	
	printf("Dersin full adini giriniz:");
	scanf("%c",&deneme);
	scanf("%[^\n]", ders_isim);
	printf("Kredi girin:");
	scanf("%d", &kredi); 
	
	if(kredi > 9){
		printf("Dersin kredisi fazla girdiniz max 9");
		return;
	}
	
	printf("dersin kontenjanini giriniz:");
	scanf("%d", &kapasite);
	
	if(kredi > MAX_KAPASITE){
		printf("Dersin kapasitesini fazla girdiniz max 200");
		return;
	}
	
	temp=(LINKED1*)malloc(sizeof(LINKED1));
	temp->ders_kodu=(char*)malloc(7);
	temp->ders_adi=(char*)malloc(45*sizeof(char));
	temp->numaralar=(OGR_DERS*)malloc(sizeof(OGR_DERS));
	temp->ders_kodu=kod;
	temp->ders_adi=ders_isim;
	temp->kredi=kredi;
	temp->kapasite=kapasite;
	FILE *oku2;
	oku2=fopen("OgrenciDersKayit.txt","r");
	int N=1;
	do{
		ogr_dersk=(OGR_DERS*)malloc(sizeof(OGR_DERS));
		ogr_dersk->durum=(char*)malloc(20*sizeof(char));
		ogr_dersk->kod=(char*)malloc(7*sizeof(char));
		ogr_dersk->tarih=(char*)malloc(20*sizeof(char));
		fscanf(oku2,"%d %s %d %s %[^/]/",&ogr_dersk->id, ogr_dersk->kod, &ogr_dersk->ogr_numara, ogr_dersk->tarih,ogr_dersk->durum);
		if (strcmp(temp->ders_kodu,ogr_dersk->kod)==0){
			temp->numaralar=(OGR_DERS*)realloc(temp->numaralar,N*sizeof(OGR_DERS));
			temp->numaralar[N-1].id=ogr_dersk->id;
			temp->numaralar[N-1].kod=ogr_dersk->kod;
			temp->numaralar[N-1].ogr_numara=ogr_dersk->ogr_numara;
			temp->numaralar[N-1].tarih=ogr_dersk->tarih;
			temp->numaralar[N-1].durum=ogr_dersk->durum;
			N+=1;
		}
		temp->ogr_num_sayisi=N-1;			
		ch2 = fgetc(oku2);
		free(ogr_dersk);				
	}while(ch2 != EOF);
	fclose(oku2);
	
	temp->onceki=yiginustu;
	yiginustu=temp;
	
	printf("ekleme islemi basarili\n");
	
	dersler_yazdir(yiginustu);
		
}

void ogrenci_ekle(){
	LINKED2 *listebaslangici=NULL,*listesonu=NULL,*yenieleman;
	char* ogrenci_isim=(char*) malloc(40);
	int num;
	char harf;
	
	
	printf("Eklenecek ogrencinin numarasini giriniz:\n");
	scanf("%d", &num);
	
	yenieleman=linked2_olustur();
	while(!yenieleman==NULL){
		if(yenieleman->numara==num){
			printf("ogrenci numarasi zaten mevcut");
			return;
		}
		yenieleman=yenieleman->sonraki;
	}
	
	printf("ogrencinin isim soyisim ayni anda giriniz:");
	scanf("%c",&harf);
	scanf("%[^\n]", ogrenci_isim);
	
	listebaslangici=linked2_olustur();
	LINKED2 *ekeleman,*komsueleman,*ptr=listebaslangici;
	ekeleman=(LINKED2*)malloc(sizeof(struct linked2));
	ekeleman->numara=num;
	ekeleman->isim_soyisim=ogrenci_isim;
	ekeleman->aldigi_kredi=0;
	ekeleman->alinan_toplam_ders=0;
	
	int k=1;
	
	
	komsueleman=listebaslangici;
	listebaslangici=ekeleman;
	listebaslangici->onceki=NULL;
	listebaslangici->sonraki=komsueleman;
	komsueleman->onceki=ekeleman;
	
	
	
	bubbleSort2(listebaslangici);
	//linked2_listele(listebaslangici);
	ogrenciler_yazdir(listebaslangici);
}


//----------------------------------------------------------------------------------------------------------------------

void ders_sil(){
	LINKED1 *yiginustu=NULL,*temp;
	LINKED2 *listebaslangici=NULL,*listesonu=NULL,*yenieleman;
	char *kod=(char*)malloc(8*sizeof(char));
	int i,j;
	
	printf("Silinecek dersin kodunu giriniz:");
	scanf("%s",kod);
	
	yiginustu=linked1_olustur();
	temp=yiginustu;
	int flag=0;
	while(temp!=NULL){
		if(strcmp(temp->ders_kodu,kod)==0){
			flag=1;
		}
		temp=temp->onceki;
	}
	if(flag==0){
		printf("Bu ders kodu adinda ders bulunmuyor");
		return;
	}
	
	
	temp=yiginustu;
	listebaslangici=linked2_olustur();
	while(temp!=NULL){
		if(strcmp(temp->ders_kodu,kod)==0){
			for (i=0;i<temp->ogr_num_sayisi;i++){
				if(strcmp(temp->numaralar[i].durum,"kayitli")==0){
					temp->numaralar[i].durum="ders kapandi";
					yenieleman=listebaslangici;//linked2 
					while(yenieleman!=NULL){
						if(temp->numaralar[i].ogr_numara==yenieleman->numara){
							yenieleman->aldigi_kredi-=temp->kredi;
							yenieleman->alinan_toplam_ders-=1;
							if((yenieleman->aldigi_kredi<0) || (yenieleman->alinan_toplam_ders<0)){
								yenieleman->aldigi_kredi=0;
								yenieleman->alinan_toplam_ders=0;
							}
						}
						yenieleman=yenieleman->sonraki;
					}
				}
			}
		}
		
		temp=temp->onceki;
	}
	temp=yiginustu;
	
	derskyt_yazdir(temp); 
	//linked1_listele(temp);
	temp=yiginustu;
	
	if(strcmp(temp->ders_kodu,kod)==0){
		yiginustu=yiginustu->onceki;
	}
	temp=yiginustu;
	while(temp->onceki->onceki!=NULL){
		if(strcmp(temp->onceki->ders_kodu,kod)==0){
			temp->onceki=temp->onceki->onceki;
			//printf("%s\n",temp->onceki->ders_kodu);
			//temp=temp->onceki;
		}
		//printf("%s\n",temp->ders_kodu);
		temp=temp->onceki;
	}
	//temp=temp->onceki;
	if(strcmp(temp->onceki->ders_kodu,kod)==0){
		temp->onceki=NULL;
	}
	
	temp=yiginustu;
	//linked1_listele(temp);
	yenieleman=listebaslangici;
	dersler_yazdir(temp);
	ogrenciler_yazdir(yenieleman);
	//linked1_listele(temp);
}

//--------------------------------------------------------------------------------------------------------------------

 void ogrenci_sil(){
 	LINKED1 *yiginustu=NULL,*temp;
	LINKED2 *listebaslangici=NULL,*listesonu=NULL,*yenieleman;
	int i,num;
	
	
	listebaslangici=linked2_olustur();
	yenieleman=listebaslangici;
	//linked2_listele(yenieleman);
	//printf("=========================\n");
	printf("Silinecek ogrencinin numarasi:");
	scanf("%d",&num);
	
	
	int flag=0;
	while(yenieleman!=NULL){
		if(yenieleman->numara==num){
			flag=1;
		}
		yenieleman=yenieleman->sonraki;
	}
	
	if(flag==0){
		printf("Bu numarada ogrenci bulunmamaktadir");
		return;
	}
	
	
	yiginustu=linked1_olustur();
	temp=yiginustu;
	while(temp!=NULL){
		for(i=0;i<temp->ogr_num_sayisi;i++){
			if(temp->numaralar[i].ogr_numara==num){
				temp->kapasite-=1;
				//temp->ogr_num_sayisi-=1;
				//free(temp->numaralar[i]);
				temp->numaralar[i].durum="ogrenci silindi";
			}
		}
		temp=temp->onceki;
	}
	
	temp=yiginustu;
	dersler_yazdir(temp);
	derskyt_yazdir(temp);
	
	yenieleman=listebaslangici;
	while(yenieleman->sonraki!=NULL){
		yenieleman=yenieleman->sonraki;
	}
	listesonu=yenieleman;
	
	yenieleman=listebaslangici;
	while(yenieleman!=NULL){
		if(yenieleman->numara==num){
			if(listebaslangici == yenieleman){
				listebaslangici=yenieleman->sonraki;
				listebaslangici->onceki=NULL;
			}
			else{
				yenieleman->onceki->sonraki=yenieleman->sonraki;
				if(yenieleman!=listesonu){
					yenieleman->sonraki->onceki=yenieleman->onceki;
				}else{
					listesonu=yenieleman->onceki;
				}
			}
		}
		yenieleman=yenieleman->sonraki;
	}
	
	yenieleman=listebaslangici;
	ogrenciler_yazdir(yenieleman); 
 	
 }

//--------------------------------------------------------------------------------------------------------------------

void kayit_ekle(){
	OGR_DERS *ogr_dersk;
	LINKED1 *yiginustu=NULL,*temp;
	LINKED2 *listebaslangici=NULL,*listesonu=NULL,*yenieleman;
	int i,j,ch,num,flag,kredi;
	char *kod=(char*)malloc(8*sizeof(char));
	char *tarih=(char*)malloc(12*sizeof(char));
	FILE *yaz;
	
	yiginustu=linked1_olustur();
	temp=yiginustu;
	
	printf("Ders kodlari:\n");
	
	while(temp!=NULL){
		printf("%s\n",temp->ders_kodu);
		temp=temp->onceki;
	}
	
	printf("ogrencinin kayit edilecegi ders kodu:");
	scanf("%s",kod);
	
	temp=yiginustu;
	flag=0;
	while(temp!=NULL){
		if(strcmp(temp->ders_kodu,kod)==0){
			kredi=temp->kredi;
			temp->kapasite+=1;
			if(temp->kapasite>MAX_KAPASITE){
				printf("Dersin kapasitesi FULL!");
				temp->kapasite-=1;
				return;
			}
			flag=1;
		}
		temp=temp->onceki;
	}
	if(flag==0){
		printf("Bu koda ait ders bulunmuyor");
		return;
	}
	
	
	listebaslangici=linked2_olustur(); 
	yenieleman=listebaslangici;
	printf("numaralar:\n");
	while(yenieleman!=NULL){
		printf("%d\n",yenieleman->numara);
		yenieleman=yenieleman->sonraki;
	}
	
	printf("derse kayit edilecek ogrencinin numarasini giriniz:");
	scanf("%d",&num);
	
	
	yenieleman=listebaslangici;
	flag=0;
	while(yenieleman!=NULL){
		if(yenieleman->numara==num){
			yenieleman->aldigi_kredi+=kredi;
			yenieleman->alinan_toplam_ders+=1;
			if(yenieleman->aldigi_kredi>KREDI_MAX || yenieleman->alinan_toplam_ders>DERS_MAX){
				printf("Ogrenci alinan toplam ders veya krediyi asti");
				yenieleman->aldigi_kredi-=kredi;
				yenieleman->alinan_toplam_ders-=1;
				if((yenieleman->aldigi_kredi<0) || (yenieleman->alinan_toplam_ders<0)){
					yenieleman->aldigi_kredi=0;
					yenieleman->alinan_toplam_ders=0;
				}
				return;
			}
			flag=1;
		}
		yenieleman=yenieleman->sonraki;
	}
	if(flag==0){
		printf("Bu numaraya ait ogrenci bulunmuyor");
		return;
	}
	
	printf("Su anki tarihi gg.aa.yyyy formatinda giriniz:");
	scanf("%s",tarih);
	
	FILE *oku=fopen("OgrenciDersKayit.txt","r");
	
	int id_max=0; 
	while(ch!=EOF){
		ogr_dersk=(OGR_DERS*)malloc(sizeof(OGR_DERS));
		ogr_dersk->durum=(char*)malloc(20*sizeof(char));
		ogr_dersk->kod=(char*)malloc(7*sizeof(char));
		ogr_dersk->tarih=(char*)malloc(20*sizeof(char));
		fscanf(oku,"%d %s %d %s %[^/]/",&ogr_dersk->id, ogr_dersk->kod, &ogr_dersk->ogr_numara, ogr_dersk->tarih,ogr_dersk->durum);
		if(id_max<ogr_dersk->id){
			id_max=ogr_dersk->id;
		}
		ch=fgetc(oku); 
	}
	id_max++;
	fclose(oku);
	
	/*temp=yiginustu;
	while(temp!=NULL){
		for(i=0;i<temp->ogr_num_sayisi;i++){
			if(id_max<temp->numaralar[i].id){
				id_max=temp->numaralar[i].id;
			}
		}
		temp=temp->onceki;
	}
	id_max++;*/
	
	temp=yiginustu;
	while(temp!=NULL){
		if(strcmp(temp->ders_kodu,kod)==0){
			temp->ogr_num_sayisi+=1;
			temp->numaralar=(OGR_DERS*)realloc(temp->numaralar,temp->ogr_num_sayisi*sizeof(OGR_DERS));
			temp->numaralar[temp->ogr_num_sayisi-1].id=id_max;
			temp->numaralar[temp->ogr_num_sayisi-1].kod=kod;
			temp->numaralar[temp->ogr_num_sayisi-1].ogr_numara=num;
			temp->numaralar[temp->ogr_num_sayisi-1].tarih=tarih;
			temp->numaralar[temp->ogr_num_sayisi-1].durum="kayitli";
			yaz=fopen("OgrenciDersKayit.txt","a");
			fprintf(yaz, "\n%d %s %d %s %s/", temp->numaralar[temp->ogr_num_sayisi-1].id, temp->numaralar[temp->ogr_num_sayisi-1].kod, temp->numaralar[temp->ogr_num_sayisi-1].ogr_numara, temp->numaralar[temp->ogr_num_sayisi-1].tarih,temp->numaralar[temp->ogr_num_sayisi-1].durum);
			fclose(yaz);
		}
		temp=temp->onceki;
	}
	temp=yiginustu;
	yenieleman=listebaslangici;
	
	dersler_yazdir(temp);
	
	ogrenciler_yazdir(yenieleman);
	
	
}


void derskyt_sil(){
	LINKED1 *yiginustu=NULL,*temp;
	LINKED2 *listebaslangici=NULL,*listesonu=NULL,*yenieleman;
	int i,j,id,num,kredi;
	
	yiginustu=linked1_olustur();
	temp=yiginustu;
	while(temp!=NULL){
		for(i=0;i<temp->ogr_num_sayisi;i++){
			printf("%d %s %d %s %s/\n", temp->numaralar[i].id, temp->numaralar[i].kod, temp->numaralar[i].ogr_numara, temp->numaralar[i].tarih,temp->numaralar[i].durum);	
		}
		
		temp=temp->onceki;
	}
	
	printf("silmek istediðiniz kayidin id giriniz:");
	scanf("%d",&id);
	
	temp=yiginustu;
	while(temp!=NULL){
		for(i=0;i<temp->ogr_num_sayisi;i++){
			if(temp->numaralar[i].id==id){
				temp->kapasite-=1;
				temp->numaralar[i].durum="sildi";
				num=temp->numaralar[i].ogr_numara;
				kredi=temp->kredi;
			}			
		}
		
		temp=temp->onceki;
	}
	
	
	listebaslangici=linked2_olustur();
	yenieleman=listebaslangici;
	while(yenieleman!=NULL){
		if(yenieleman->numara==num){
			yenieleman->aldigi_kredi-=kredi;
			yenieleman->alinan_toplam_ders-=1;
		}
		yenieleman=yenieleman->sonraki;
	}
	
	temp=yiginustu;
	yenieleman=listebaslangici;
	
	derskyt_yazdir(temp);
	dersler_yazdir(temp);
	ogrenciler_yazdir(yenieleman);
	
}


//--------------------------------------------------------------------------------------------------------------------

void ogr_num_yazdir(){
	LINKED1 *yiginustu=NULL,*temp;
	LINKED2 *listebaslangici=NULL,*listesonu=NULL,*yenieleman;
	int i,j,flag,num;
	char *filename=(char*)malloc(12);
	
	printf("ogrenci numaralari\n");
	listebaslangici=linked2_olustur();
	yenieleman=listebaslangici;
	while(yenieleman!=NULL){
		printf("%d\n",yenieleman->numara);
		yenieleman=yenieleman->sonraki;
	}
	
	printf("Derslerini yazdirmak istediginiz ogrencinin numarasi:");
	scanf("%d",&num);
	
	sprintf(filename, "%d", num);
	strcat(filename,".txt");
	
	FILE *yaz;
	yaz=fopen(filename,"w");
	yiginustu=linked1_olustur();
	temp=yiginustu;
	
	flag=0;
	while(temp!=NULL){
		for(i=0;i<temp->ogr_num_sayisi;i++){
			if(temp->numaralar[i].ogr_numara==num){
				fprintf(yaz,"%s\n",temp->ders_kodu);
				flag=1;
			}
		}
		temp=temp->onceki;
	}
	if(flag==0){
		fprintf(yaz,"Bu ogrenciye ait ders bulunmamaktadir");
	}
	
	fclose(yaz);
	
	
}

void ders_kod_yazdir(){
	LINKED1 *yiginustu=NULL,*temp;
	LINKED2 *listebaslangici=NULL,*listesonu=NULL,*yenieleman;
	int i,j,flag;
	char *kod=(char*)malloc(12);
	char *prevkod=(char*)malloc(8);
	
	printf("Ders kodlari:\n");
	
	yiginustu=linked1_olustur();
	temp=yiginustu;
	while(temp!=NULL){
		printf("%s %s\n",temp->ders_kodu,temp->ders_adi);
		temp=temp->onceki;
	}
	
	
	printf("Kayitli ogrencileri yazdirmak istediginiz ders kodunu giriniz:");
	scanf("%s",kod);
	strcpy(prevkod,kod);
	strcat(kod,".txt");
	
	FILE *yaz;
	yaz=fopen(kod,"w");
	temp=yiginustu;
	
	flag=0;
	while(temp!=NULL){
		if(strcmp(temp->ders_kodu,prevkod)==0){
			for(i=0;i<temp->ogr_num_sayisi;i++){	
				fprintf(yaz,"%d\n",temp->numaralar[i].ogr_numara);
				flag=1;
			}		
		}
		temp=temp->onceki;
	}
	if(flag==0){
		fprintf(yaz,"Bu derse ait ogrenci bulunmamaktadir");
	}
	
	fclose(yaz);
}

//--------------------------------------------------------------------------------------------------------------------

void bubbleSort(struct linked1 *start)
{
    int swapped, i;
    struct linked1 *ptr1;
    struct linked1 *lptr = NULL;
  
    
    if (start == NULL)
        return;
  
    do
    {
        swapped = 0;
        ptr1 = start;
  
        while (ptr1->onceki != lptr)
        {
            if (strcmp(ptr1->ders_kodu,ptr1->onceki->ders_kodu)==1)
            { 
                swap(ptr1, ptr1->onceki);
                swapped = 1;
            }
            ptr1 = ptr1->onceki;
        }
        lptr = ptr1;
    }
    while (swapped);    
}

void bubbleSort2(struct linked2 *start)
{
    int swapped, i;
    struct linked2 *ptr1;
    struct linked2 *lptr = NULL;
  
    
    if (start == NULL)
        return;
  
    do
    {
        swapped = 0;
        ptr1 = start;
        while (ptr1->sonraki != lptr)
        {
            if (ptr1->numara > ptr1->sonraki->numara)//kod tekrari
            { 
                swap2(ptr1, ptr1->sonraki);
                swapped = 1;
            }
            ptr1 = ptr1->sonraki;
        }
        lptr = ptr1;
    }
    while (swapped);    
}

void swap(struct linked1 *a, struct linked1 *b)
{	
    struct linked1 gecici=*a;
    *a = *b;
    *b = gecici;
    gecici.onceki=a->onceki;
    a->onceki=b->onceki;
	b->onceki=gecici.onceki;
}  
  
void swap2(struct linked2 *a, struct linked2 *b)
{	
    struct linked2 gecici=*a;
    *a = *b;
    *b = gecici;
    gecici.onceki=a->onceki;
    a->onceki=b->onceki;
	b->onceki=gecici.onceki;
	
	gecici.sonraki=a->sonraki;
    a->sonraki=b->sonraki;
	b->sonraki=gecici.sonraki;
}











