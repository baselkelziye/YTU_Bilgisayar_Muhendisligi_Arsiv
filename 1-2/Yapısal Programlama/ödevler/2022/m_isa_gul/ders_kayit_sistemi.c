#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ders{
	char ders_kodu[50];
	char ders_adi[50];
	int ders_kredisi;
	int ders_kontenjani;
	int ogrenci_sayisi;
	int *liste;
	struct ders *next;
} DERS;

typedef struct ogrenci{
	int ogrenci_numara;
	char ogrenci_adi[50];
	char ogrenci_soyadi[50];
	int ders_sayisi;
	int toplam_kredi;
	
	struct ogrenci *prev;
	struct ogrenci *next;
} OGRENCI;

typedef struct ogrencikayit{
	int id;
	char ders_kodu[50];
	int ogrenci_no;
	char tarih[50];
	char durum[50];
	struct ogrencikayit *next;
} KAYIT;

void derslerOku(DERS **dershead);
void derslerYazdir(DERS *dershead);
void dersOlustur(DERS **head);
void dersEkle(DERS *yeniders,DERS **dershead);
void dersSil(DERS **head,KAYIT **kayithead);
void derslerDosyaya(DERS *dershead);

void ogrencilerOku(OGRENCI **ogrencihead);
void ogrencilerYazdir(OGRENCI *ogrencihead);
void ogrenciOlustur(OGRENCI **head);
void ogrenciEkle(OGRENCI *yeniogrenci,OGRENCI **ogrencihead);
void ogrenciSil(OGRENCI **head);
void ogrencilerDosyaya(OGRENCI *ogrencihead);

void dersKayitEkle(DERS *dershead,OGRENCI *ogrencihead,KAYIT **kayithead,int kredi_limit,int ders_limit);
void dersKayitSil(DERS *dershead,OGRENCI *ogrencihead,KAYIT **kayithead);
void dersListesiOlustur(DERS *dershead,OGRENCI *ogrencihead);
void ogrenciProgram(DERS* dershead);

void dersKayitLog(KAYIT **kayithead,char kod[50],int ogrenci_no,char tarih[50],char durum[50]);
void kayitYaz(KAYIT *kayithead);

int main(){
	int menu=-1,kredi_limit,ders_limit;
	DERS *dershead = NULL;
	OGRENCI *ogrencihead = NULL;
	KAYIT *kayithead = NULL;
	printf("Hazirlayan: M.Isa Gul\n\nHosgeldiniz...\nKredi limitini giriniz: ");
	scanf("%d",&kredi_limit);
	printf("Ders limitini giriniz: ");
	scanf("%d",&ders_limit);
	while(menu != 0){
//		printf("\nMenuyu gormek icin bir tusa basiniz...");
//		getch();
		printf("\n1-Dosyadan dersleri oku.");
		printf("\n2-Dersleri yazdir.");
		printf("\n3-Ders ekle.");
		printf("\n4-Ders sil");
		printf("\n5-Dersleri dosyaya kaydet.");
		printf("\n\n6-Dosyadan ogrencileri oku.");
		printf("\n7-Ogrencileri yazdir.");
		printf("\n8-Ogrenci ekle.");
		printf("\n9-Ogrenci sil.");
		printf("\n10-Ogrencileri dosyaya kaydet.");
		printf("\n\n11-Derse ogrenci kaydet.");
		printf("\n12-Ders ogrenci kaydi sil.");
		printf("\n13-Dersi alan ogrenci listesi olustur.");
		printf("\n14-Ogrenci ders programi olustur.");
		printf("\n15-Log dosyasi olustur.");
		printf("\n0-Cikis.");
		printf("\n\nSeciminiz: ");
		scanf("%d",&menu);
		
		switch(menu){
			case 1:
				derslerOku(&dershead);
				printf("Dersler basariyla okundu. Yazdirmak icin 2'ye basiniz.\n");
				break;
			case 2:
				derslerYazdir(dershead);
				break;
			case 3:
				dersOlustur(&dershead);
				break;
			case 4:
				dersSil(&dershead,&kayithead);
				break;
			case 5:
				derslerDosyaya(dershead);
				printf("Dersler basariyla dosyaya kaydedildi.\n");
				break;
			case 6:
				ogrencilerOku(&ogrencihead);
				printf("Ogrenciler basariyla okundu. Yazdirmak icin 7'ye basiniz.\n");
				break;
			case 7:
				ogrencilerYazdir(ogrencihead);
				break;
			case 8:
				ogrenciOlustur(&ogrencihead);
				break;
			case 9:
				ogrenciSil(&ogrencihead);
				break;
			case 10:
				ogrencilerDosyaya(ogrencihead);
				printf("Ogrenciler basariyla dosyaya kaydedildi.\n");
				break;
			case 11:
				dersKayitEkle(dershead,ogrencihead,&kayithead,kredi_limit,ders_limit);
				break;
			case 12:
				dersKayitSil(dershead,ogrencihead,&kayithead);
				break;
			case 13:
				dersListesiOlustur(dershead,ogrencihead);
				break;	
			case 14:
				ogrenciProgram(dershead);
				break;
			case 15:
				kayitYaz(kayithead);
				break;	
		}
	}
}

void ogrencilerOku(OGRENCI **ogrencihead){
	FILE *ogrencilerfile = fopen("ogrenciler.txt","r");
	char buff[255];
	
	while(fgets(buff,sizeof(buff),ogrencilerfile) != NULL){
		OGRENCI *yeniogrenci = (OGRENCI*) malloc (1*sizeof(OGRENCI));
		
		char *token;
		token=strtok(buff,",\0");
		yeniogrenci->ogrenci_numara = atoi(token);
		token=strtok(NULL,",\0");
		strcpy(yeniogrenci->ogrenci_adi,token);
		token=strtok(NULL,",\0");
		strcpy(yeniogrenci->ogrenci_soyadi,token);
		token=strtok(NULL,",\0");
		yeniogrenci->ders_sayisi = atoi(token);
		token=strtok(NULL,",\0");	
		yeniogrenci->toplam_kredi = atoi(token);
		ogrenciEkle(yeniogrenci,ogrencihead);
	}
	fclose(ogrencilerfile);
}
void ogrenciOlustur(OGRENCI **head){
	OGRENCI *tmp= *head;
	char ad[50];
	char soyad[50];
	int no;

	OGRENCI *yeniogrenci = (OGRENCI*) malloc (1*sizeof(OGRENCI));
	printf("Ogrenci numarasi: ");
	scanf("%d",&no);
	while(tmp !=NULL && tmp->ogrenci_numara != no){
		tmp = tmp->next;
	}
	if(tmp==NULL){
		yeniogrenci->ogrenci_numara = no;
		
		printf("Ogrencinin adi: ");
		gets(ad);
		gets(ad);
		strcpy(yeniogrenci->ogrenci_adi,ad);	
		printf("Ogrencinin soyadi: ");
		gets(soyad);
		strcpy(yeniogrenci->ogrenci_soyadi,soyad);	
		yeniogrenci->ders_sayisi = 0;
		yeniogrenci->toplam_kredi = 0;
		
		ogrenciEkle(yeniogrenci,head);
		printf("Ogrenci basariyla eklendi.\n");
	}
	else{
		printf("Eklemek istediginiz ogrenci listede bulunmakta.\n");
	}
		
}
void ogrenciEkle(OGRENCI *yeniogrenci,OGRENCI **ogrencihead){
	OGRENCI *tmp,*curr;


	if (*ogrencihead == NULL){
		*ogrencihead = yeniogrenci;
		yeniogrenci->next=NULL;
		yeniogrenci->prev=NULL;
	}
	else{
		
		if((*ogrencihead)->ogrenci_numara > yeniogrenci->ogrenci_numara){
			yeniogrenci->next=*ogrencihead;
			yeniogrenci->prev= NULL;
			(*ogrencihead)->prev = yeniogrenci;
			
			*ogrencihead = yeniogrenci;
		}
		else{
			
			tmp = *ogrencihead;
			while(tmp->next != NULL && tmp->next->ogrenci_numara < yeniogrenci->ogrenci_numara){	
				tmp = tmp->next;	
			}
			if(tmp->next != NULL){				
				yeniogrenci->next=tmp->next;
				tmp->next=yeniogrenci;
				yeniogrenci->prev=tmp;

			}
			else{
				tmp->next = yeniogrenci;
				yeniogrenci->prev=tmp;
				yeniogrenci->next = NULL;
			}
		}
	}
}
void ogrenciSil(OGRENCI **head){
	OGRENCI *tmp;
	
	int no;
	printf("Silmek istediginiz ogrencinin numarasini giriniz: ");
	scanf("%d",&no);
	
	if((*head)->ogrenci_numara==no){
		tmp = *head;
		*head = (*head)->next;
		(*head)->prev = NULL;
		free(tmp);
		printf("Ogrenci basariyla silindi.\n");
		
	}else{
		tmp=*head;
		while(tmp->next!=NULL && tmp->next->ogrenci_numara!=no){
			tmp = tmp->next;
		}
		if(tmp->next!=NULL){
			free(tmp->next);
			tmp->next = NULL;
			printf("Ogrenci basariyla silindi.\n");
		}else{
			printf("Ogrenci bulunamadi.\n");
		}
	}
}
void ogrencilerYazdir(OGRENCI *ogrencihead){
	OGRENCI *tmp = ogrencihead;
	
	while(tmp != NULL){
		printf("%d,%s,%s,%d,%d\n", tmp->ogrenci_numara, tmp->ogrenci_adi, tmp->ogrenci_soyadi, tmp->ders_sayisi,tmp->toplam_kredi);
		tmp=tmp->next;
	}
}
void ogrencilerDosyaya(OGRENCI *ogrencihead){
	FILE *fp = fopen("ogrenciler.txt","w");
	OGRENCI *tmp = ogrencihead;
	char yazi[50];
	while(tmp != NULL){
		itoa(tmp->ogrenci_numara,yazi,10);
		fputs(yazi,fp);
		fputc(',',fp);
		fputs(tmp->ogrenci_adi,fp);
		fputc(',',fp);
		fputs(tmp->ogrenci_soyadi,fp);
		fputc(',',fp);
		itoa(tmp->ders_sayisi,yazi,10);
		fputs(yazi,fp);
		fputc(',',fp);
		itoa(tmp->toplam_kredi,yazi,10);
		fputs(yazi,fp);
		fputc('\n',fp);
		tmp=tmp->next;
	}
	fclose(fp);
}

void derslerOku(DERS **dershead){
	
	FILE *derslerfile = fopen("dersler.txt","r");
	char buff[255];
	
	while(fgets(buff,sizeof(buff),derslerfile) != NULL){
		DERS *yeniders = (DERS*) malloc (1*sizeof(DERS));
		
		char *token;
		token=strtok(buff,",\0");
		strcpy(yeniders->ders_kodu,token);
		token=strtok(NULL,",\0");
		strcpy(yeniders->ders_adi,token);
		token=strtok(NULL,",\0");
		yeniders->ders_kredisi=atoi(token);
		token=strtok(NULL,",\0");
		yeniders->ders_kontenjani=atoi(token);
		yeniders->ogrenci_sayisi = 0;
		yeniders->liste=(int*)calloc(1,sizeof(int));
		
		dersEkle(yeniders,dershead);
		
	}
	fclose(derslerfile);
}
void dersOlustur(DERS **head){
	DERS *tmp= *head;
	char kod[50];
	char ad[50];
	int kredi;
	int kontenjan;
	DERS *yeniders = (DERS*) malloc (1*sizeof(DERS));
	printf("Dersin kodu: ");
	gets(kod);
	gets(kod);
	while(tmp !=NULL && strcmp(tmp->ders_kodu,kod) != 0){
		tmp = tmp->next;
	}
	if(tmp==NULL){
		strcpy(yeniders->ders_kodu,kod);
		printf("Dersin adi: ");
		gets(ad);
		strcpy(yeniders->ders_adi,ad);	
		printf("Dersin kredisi: ");
		scanf("%d",&yeniders->ders_kredisi);
		printf("Dersin kontenjani: ");
		scanf("%d",&yeniders->ders_kontenjani);
		yeniders->ogrenci_sayisi = 0;
		
		yeniders->liste=(int*)malloc(1*sizeof(int));
		
		dersEkle(yeniders,head);
		printf("Ders basariyla eklendi.\n");
	}
	else{
		printf("Eklemek istediginiz ders listede bulunmakta.\n");
	}
		
}
void dersEkle(DERS *yeniders,DERS **dershead){
	
	DERS *tmp,*curr;


	if (*dershead == NULL){
		*dershead = yeniders;
		yeniders->next=NULL;
	}
	else{
		
		if(strcmp((*dershead)->ders_kodu,yeniders->ders_kodu)>0){
			yeniders->next=*dershead;
			*dershead = yeniders;
		}
		else{
			
			curr = *dershead;
			while(curr->next != NULL && strcmp(curr->next->ders_kodu,yeniders->ders_kodu) <0){	
				curr = curr->next;	
			}
			if(curr->next != NULL){
				tmp = curr->next;
				curr->next=yeniders;
				yeniders->next=tmp;
			}
			else{
				curr->next=yeniders;
				yeniders->next = NULL;
			}
		}
	}
}
void dersSil(DERS **head,KAYIT **kayithead){
	DERS *tmp,*curr;
	char tarih[50]; //log dosyasinda kullanilacaktir.
	char kod[50];
	printf("Silmek istediginiz dersin kodunu giriniz: ");
	scanf("%s",kod);
	
	if(strcmp((*head)->ders_kodu,kod)==0){
		printf("Tarih giriniz: ");
		scanf("%s",tarih);
		tmp = *head;
		*head=(*head)->next;
		free(tmp);
		printf("Ders basariyla silindi.\n");
		
		dersKayitLog(kayithead,kod,-1,tarih,"KAPANDI");
		
	}else{
		curr=*head;
		while(curr->next!=NULL && strcmp(curr->next->ders_kodu,kod)!=0){
			curr = curr->next;
		}
		if(curr->next!=NULL){
			printf("Tarih giriniz: ");
		scanf("%s",tarih);
			tmp=curr->next;
			curr->next=curr->next->next;
			free(tmp);
			printf("Ders basariyla silindi.\n");
			
			dersKayitLog(kayithead,kod,-1,tarih,"KAPANDI");
		}else{
			printf("Ders bulunamadi.\n");
		}
	}
}
void derslerYazdir(DERS *dershead){
	DERS *tmp = dershead;
	
	while(tmp != NULL){
		printf("%s,%s,%d,%d\n", tmp->ders_kodu, tmp->ders_adi, tmp->ders_kredisi, tmp->ders_kontenjani,tmp->ogrenci_sayisi);
		tmp=tmp->next;
	}
	
}
void derslerDosyaya(DERS *dershead){
	FILE *fp = fopen("dersler.txt","w");
	DERS *tmp = dershead;
	char yazi[50];
	while(tmp != NULL){
		fputs(tmp->ders_kodu,fp);
		fputc(',',fp);
		fputs(tmp->ders_adi,fp);
		fputc(',',fp);
		itoa(tmp->ders_kredisi,yazi,10);
		fputs(yazi,fp);
		fputc(',',fp);
		itoa(tmp->ders_kontenjani,yazi,10);
		fputs(yazi,fp);
		fputc('\n',fp);
		tmp=tmp->next;
	}
	fclose(fp);
}


void dersKayitEkle(DERS *dershead,OGRENCI *ogrencihead,KAYIT **kayithead,int kredi_limit,int ders_limit){
	DERS *tmp= dershead;
	OGRENCI *tmp2 = ogrencihead;
	char kod[50];
	char tarih[50];
	int no,n,i,j,tmp3,min;
	printf("Kayit yapilacak dersin kodu: ");
	scanf("%s",kod);
	printf("Kayit edilecek ogrencinin numarasi: ");
	scanf("%d", &no);

	while(tmp != NULL && strcmp(tmp->ders_kodu,kod)!=0){
		tmp=tmp->next;
	}
	if(tmp == NULL){
		printf("Ders bulunamadi.\n");
	}else{
		if(tmp->ogrenci_sayisi < tmp->ders_kontenjani){
			n=tmp->ogrenci_sayisi;
			while(tmp->liste[i] != no && i<n){
				i += 1;
			}
			if(i<n){
				printf("Ogrenci derse daha once kayit yapmis.\n");
			}else{
				while(tmp2 != NULL && tmp2->ogrenci_numara != no){
					tmp2=tmp2->next;
				}
				if(tmp2 == NULL){
					printf("Ogrenci bulunamadi.\n");
				}
				else{
					if(tmp2->ders_sayisi < ders_limit && tmp2->toplam_kredi+tmp->ders_kredisi <= kredi_limit){
						printf("Tarih giriniz: ");
						scanf("%s",&tarih);
						tmp->liste = (int*) realloc(tmp->liste,(n+1)*sizeof(int));
						tmp->liste[n] = no;
						tmp->ogrenci_sayisi += 1;	
						tmp2->ders_sayisi +=1;
						tmp2->toplam_kredi += tmp->ders_kredisi;
						printf("Ogrenci derse kaydedildi.\n");
						
						
						dersKayitLog(kayithead,kod,no,tarih,"KAYITLI");
						
						
						
						n=tmp->ogrenci_sayisi;
						//yeni kayit eklendikten sonra ogrenci listesi
						//numaraya gore siralanir.
						for(i=0;i<n-1;i++){
							min=i;
							for(j=i+1;j<n;j++){
								if(tmp->liste[j] < tmp->liste[i]){
									min =j;
								}
							}
							tmp3=tmp->liste[i];
							tmp->liste[i]=tmp->liste[min];
							tmp->liste[min]=tmp3;
						}
					}
					else{
						printf("Kayit yapilamadi. Ogrencinin ders limiti veya kredisi dolmus.\n");
					}
				}
			}
		}
		else{
			printf("Dersin kontenjani dolmustur.\n");
		}	
	}
}

void dersKayitSil(DERS *dershead,OGRENCI *ogrencihead,KAYIT **kayithead){
	DERS *tmp= dershead;
	OGRENCI *tmp2 = ogrencihead;
	char kod[50];
	char tarih[50];
	int no,i,n,j,k;
	printf("Kayit silinecek dersin kodu: ");
	scanf("%s",kod);
	printf("Kayit silinecek ogrencinin numarasi: ");
	scanf("%d", &no);

	while(tmp != NULL && strcmp(tmp->ders_kodu,kod)!=0){
		tmp=tmp->next;
	}
	if(tmp == NULL){
		printf("Ders bulunamadi.\n");
	}else{
		printf("Tarih giriniz: ");
		scanf("%s",tarih);
		n=tmp->ogrenci_sayisi;
		while(tmp->liste[j] != no && j<n){
			j += 1;
		}
		if(j<n){						//silinecek kayittan sonrakiler 1 one cekilir.
			for(k=j;k<n-1;k++){
				tmp->liste[k]=tmp->liste[k+1];
			}
			tmp->ogrenci_sayisi -= 1;
			tmp->liste = (int*) realloc(tmp->liste,(n)*sizeof(int));	//hafiza guncellenir.
			printf("Ders kaydi basariyla silindi.\n");
			
			dersKayitLog(kayithead,kod,no,tarih,"BIRAKTI");
			
			while(tmp2->ogrenci_numara != no){
				tmp2=tmp2->next;
			}
			//ogrencinin aldigi ders sayisi ve toplam kredisi guncellenir.
			tmp2->ders_sayisi -= 1;
			tmp2->toplam_kredi -= tmp->ders_kredisi;
		}else{
			printf("Ogrenci derse daha once kayit yapmamis.\n");
		}
	}
}
		


void dersListesiOlustur(DERS *dershead,OGRENCI *ogrencihead){
	DERS *tmp =dershead;
	OGRENCI *tmp2=ogrencihead;
	char kod[50];
	char kod2[50];
	int n,i;
	char yazi[50];
	printf("Ders kodu: ");
	scanf("%s",kod);

	while(tmp != NULL && strcmp(tmp->ders_kodu,kod)!=0){
		tmp=tmp->next;
	}
	if(tmp == NULL){
		printf("Ders bulunamadi.\n");
	}else{
		sprintf(kod2,"%s.txt",kod);		//ders kodunun sonuna .txt eklemek icin kullanildi.
		FILE *fpp = fopen(kod2,"w");
		n = tmp->ogrenci_sayisi;
		
		for(i=0;i<n;i++){
			itoa(tmp->liste[i],yazi,10);
			fputs(yazi,fpp);
			while(tmp2->ogrenci_numara != tmp->liste[i]){
				tmp2=tmp2->next;
			}
			fputc(',',fpp);
			fputs(tmp2->ogrenci_adi,fpp);
			fputc(',',fpp);
			fputs(tmp2->ogrenci_soyadi,fpp);
			fputc('\n',fpp);
		}
		printf("Dosya basariyla olusturuldu.\n");
		fclose(fpp);
	}
}

void ogrenciProgram(DERS* dershead){
	
	DERS *tmp2= dershead;
	int no,n,i;
	char no2[50];
	char no3[50];
	printf("Ogrenci numarasi: ");
	scanf("%d",&no);
	itoa(no,no2,10);
	sprintf(no3,"%s_dersprogrami.txt",no2);		//ders kodunun sonuna .txt eklemek icin kullanildi.
	FILE *fp = fopen(no3,"w");
	
	while(tmp2 != NULL){
		n = tmp2->ogrenci_sayisi;
		for(i=0;i<n;i++){
			if(tmp2->liste[i] == no){
				fputs(tmp2->ders_kodu,fp);
				fputc(',',fp);
				fputs(tmp2->ders_adi,fp);
				fputc('\n',fp);
			}
		}
		tmp2=tmp2->next;
	}
	fclose(fp);
	printf("Program basariyla olusturuldu.\n");
}
//Yapilan degisiklikler linked listte saklanir.
//Linked list, log'lari dosyaya kaydederken kullanilmistir.
void dersKayitLog(KAYIT **kayithead,char kod[50],int ogrenci_no,char tarih[50],char durum[50]){
	
	KAYIT *tmp = *kayithead;
	KAYIT *yenikayit = (KAYIT*) malloc (1*sizeof(KAYIT));
	strcpy(yenikayit->ders_kodu,kod);
	yenikayit->ogrenci_no = ogrenci_no;
	strcpy(yenikayit->tarih,tarih);
	strcpy(yenikayit->durum,durum);
	
	if(*kayithead == NULL){
		*kayithead = yenikayit;
		yenikayit->id = 1;
		yenikayit->next=NULL;
	}
	else{
		if(ogrenci_no == -1){	//Dersi alan tum ogrenciler icin KAPANDI olarak guncellenir.
			while(tmp
			 != NULL){
				if(strcmp(tmp->ders_kodu,kod)==0){
					strcpy(tmp->durum,"KAPANDI");
					strcpy(tmp->tarih,tarih);
				}
				tmp = tmp->next;
			}
		}else{
			
			if(strcmp(durum,"KAYITLI")==0){
			
				while(tmp->next != NULL){
					tmp=tmp->next;
				}
				tmp->next = yenikayit;
				yenikayit->next= NULL;
				yenikayit->id = tmp->id +1;
			}else{
				while((strcmp(tmp->ders_kodu,kod) !=0 || tmp->ogrenci_no !=ogrenci_no)){
					tmp=tmp->next;
				}
				strcpy(tmp->tarih,tarih);
				strcpy(tmp->durum,durum);
			}
		}
	}
}

void kayitYaz(KAYIT *kayithead){
	KAYIT *tmp=kayithead;
	char yazi[50];
	FILE *fp= fopen("OgrenciDersKayit.txt","w");
	while(tmp != NULL){
		itoa(tmp->id,yazi,10);
		fputs(yazi,fp);
		fputc(',',fp);
		fputs(tmp->ders_kodu,fp);
		fputc(',',fp);
		itoa(tmp->ogrenci_no,yazi,10);
		fputs(yazi,fp);
		fputc(',',fp);
		fputs(tmp->tarih,fp);
		fputc(',',fp);
		fputs(tmp->durum,fp);
		fputc('\n',fp);
		tmp=tmp->next;
	}
	fclose(fp);
	printf("Kayit dosyasi basariyla olusturuldu.\n");
}
