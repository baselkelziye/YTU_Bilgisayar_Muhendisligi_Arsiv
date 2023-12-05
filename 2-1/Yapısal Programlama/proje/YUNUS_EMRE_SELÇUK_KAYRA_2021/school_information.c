#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct DERS{
	char ders_kodu[20];
	char ders_adi[20];
	int kredi;
	int kontenjan;
 	struct DERS * next;
	int * no;
	int ogrenci_sayisi;
	int kalan_kontenjan;
}ders;
typedef struct OGRENCI{
	int ogr_no;
	char isim[20];
	char soyisim[20];
	int aldigi_ders;
	int top_kredi;
	struct OGRENCI * next;
	struct OGRENCI * prev;
}ogrenci;
typedef struct{
	int satir;
	char ders_kodu[20];
	int ogr_no;
	char tarih[15];
	char durum[20];
}durum;

ders * ders_bul(ders * p,char n[20]){
		while(p!=NULL && strcmp(p->ders_kodu,n)!=0){
		p=p->next;
	}
	return p;
	
}
ogrenci * ogrenci_bul(ogrenci * p, int t){
	while(p->ogr_no!=t)
	p=p->next;
	return p;
}
durum * durum_oku(int * durum_sayisi,durum * kayit , ders * head){
	int i,ogr_no,satir,k,j;
	char tarih[15],durumu[20],ders_kodu[20];
	ders * sira,*p;
	kayit=(durum*)realloc(kayit, sizeof(durum));
	FILE * data;
	data=fopen("durum.txt","r");
	if(!data){
		printf("Durum okuyacak dosya bulunamadi\n");
		return NULL;
	}

	else{
	i=0;
		while(fscanf(data,"%d %s %d %s %s\n",&satir,ders_kodu,&ogr_no,tarih,durumu)==5){
		i=satir-1;
		kayit=(durum *)realloc(kayit,(satir)*sizeof(durum));
		kayit[i].satir=satir;
		strcpy_s(kayit[i].ders_kodu,20,ders_kodu);
		kayit[i].ogr_no=ogr_no;
		strcpy_s(kayit[i].tarih,15,tarih);
		strcpy_s(kayit[i].durum,15,durumu);
		*durum_sayisi=satir;	

		}
				
for(p=head;p!=NULL;p=p->next){
for(i=0;i<(*durum_sayisi);i++){
if(strcmp(p->ders_kodu,kayit[i].ders_kodu)==0 && !strcmp(kayit[i].durum,"Kayitli")){
if(p->ogrenci_sayisi==0){
	 	p->no=(int*)malloc(sizeof(int));
	 	if(p->no==NULL)
	 	printf("Bos alan yok\n");
	 	else{
	 	p->ogrenci_sayisi=1;
	 	p->no[p->ogrenci_sayisi-1]=kayit[i].ogr_no;
 		p->kalan_kontenjan--;
 		}}
	 else{
k=0;
 for(j=0;j<p->ogrenci_sayisi;j++){
 	if(p->no[j]==kayit[i].ogr_no)
 	k=1;
 }
 if(k==1){

 }
 else{
 p->ogrenci_sayisi++;
 p->no=(int*)realloc(p->no,p->ogrenci_sayisi*sizeof(int));
 j=0;
 while(j<p->ogrenci_sayisi && p->no[j]<kayit[i].ogr_no){
 	j++;
 }
 for(k=p->ogrenci_sayisi-1;k>j;k--){
 	p->no[k]=p->no[k-1];
 }
 p->no[k]=kayit[i].ogr_no;
 p->kalan_kontenjan--;
 //durum_sayisi++;
			
		}}}}}

		
	fclose(data);
	}
	return kayit;
}
durum * durum_guncelle(int * durum_sayisi,durum * kayit){
	int i;
	FILE * data;
	data=fopen("durum.txt","w");
	if(!data){
		printf("Yazdirma islemi olmadi\n");
	}
	else{
	for(i=0;i<(*durum_sayisi);i++){
		fprintf(data,"%d %s %d %s %s\n",i+1,kayit[i].ders_kodu,kayit[i].ogr_no,kayit[i].tarih,kayit[i].durum);		
	}
	fclose(data);
		return kayit;
	}
}
ogrenci * otoogrekle(int * durum_sayisi,ogrenci * onceki,ogrenci * sonraki){
	ogrenci * psira,*nsira,*kontrol_degeri;
 	char isim[20],soyisim[20];
 	int i,k=0,l=0,ogr_no=0,top_kredi=0,top_ders=0;
 	FILE* data;
 	data=fopen("ogrenci.txt","r");
 	if(!data){
 		printf("Ogrenci eklenecek dosya bulunamadi\n");
 		fclose(data);
 		return NULL;
	 }
	 else{
	if(onceki==NULL){
		if(fscanf(data,"%d %s %s %d %d\n",&ogr_no,isim,soyisim,&top_ders,&top_kredi)==5){
		psira=(ogrenci*)malloc(sizeof(ogrenci));
		strcpy_s(psira->isim,20,isim);
		strcpy_s(psira->soyisim,20,soyisim);
		psira->ogr_no=ogr_no;
		psira->top_kredi=top_kredi;
		psira->aldigi_ders=top_ders;
		psira->next=NULL;
		psira->prev=NULL;
		onceki=psira;
		sonraki=psira;
		return onceki;}
		else{
		return NULL;
		}
	}
	fscanf(data,"%d %s %s %d %d\n",&ogr_no,isim,soyisim,&top_ders,&top_kredi);
	while(fscanf(data,"%d %s %s %d %d\n",&ogr_no,isim,soyisim,&top_ders,&top_kredi)==5){
		psira=(ogrenci*)malloc(sizeof(ogrenci));
		strcpy_s(psira->isim,20,isim);
		strcpy_s(psira->soyisim,20,soyisim);
		psira->ogr_no=ogr_no;
		psira->top_kredi=top_kredi;
		psira->aldigi_ders=top_ders;
		psira->next=NULL;
		psira->prev=NULL;
		sonraki->next=psira;
		psira->prev=sonraki;
		sonraki=psira;
		psira=NULL;
}

	 fclose(data);}
	return sonraki;
}
ders* otodersekle(int * durum_sayisi, ders * head){
	FILE *data;
 	ders * sira,*deger,*eskisira,*kontrol_degeri;
 	int i,k=0,j,l=0,kredi,kontenjan;
 	char date[15],adi[20],kod[20];
 	data=fopen("ders.txt","r");
 	if(!data){
 		printf("Ders eklenecek dosya bulunamadi\n");
 		return NULL;
	 }
	else{
		 while(fscanf(data,"%s %s %d %d\n",kod,adi,&kredi,&kontenjan)==4){
	 		deger=(ders*)malloc(sizeof(ders));
	 		strcpy_s(deger->ders_adi,20,adi);
	 		strcpy_s(deger->ders_kodu,20,kod);
	 		deger->kredi=kredi;
	 		deger->kontenjan=kontenjan;
	 		deger->next=NULL;
	 		deger->ogrenci_sayisi=0;
	 		deger->kalan_kontenjan=kontenjan;
	 		if(head==NULL){
	 			head=deger;
	 			eskisira=head;
			 }
			 else{
				eskisira->next=deger;
				eskisira=deger;
				deger=NULL;
			 	
			 }
	 	
	 	}
	 }
	 return head;
}
 ogrenci * ogrenci_sil(int * durum_sayisi,durum * kayit,ders * head,ogrenci * onceki, ogrenci * sonraki,int * count,durum * (*fp)(int *durum_sayisi,durum *kayit)){
 	FILE * data;
 	ogrenci * psira,*osira,*ksira,*bsira,*nsira;
 	ders *p;
 	char date[15];
 	int i,j=0,k=0;
 	 	if(onceki==NULL){
 	 	(*count)=-1;
 		printf("====================================================\nHenuz Ogrenci girisi Olmadi\n====================================================\n");
	 }
	 else{
	printf("====================================================\nLutfen silinecek ogrencinin numarasini giriniz\n====================================================\n");
 	scanf("%d",&i);
	psira=sonraki;
	osira=onceki;
	printf("Lutfen tarihi gg/aa/yy formatinda giriniz\n");
	scanf("%s",date);
	 for(k=0;k<*durum_sayisi;k++)		 {
		if(kayit[k].ogr_no==i)  {
 		strcpy_s(kayit[k].tarih,15,date);
 		strcpy_s(kayit[k].durum,20,"Ogrenci_Silindi");
			 }
		 }
	k=0;
	for(p=head;p!=NULL;p=p->next){
	j=0;
 	while(j<p->ogrenci_sayisi && k==0){
 		if(p->no[j]!=i)
 		j++;	
 		else
 		k=1;
	 }
	 if(k==1){
	 	for(k=j;k<p->ogrenci_sayisi-1;k++){
	 		p->no[k]=p->no[k+1];
		 }
		 p->ogrenci_sayisi--;
		 p->kalan_kontenjan++;
		 p->no=(int*)realloc(p->no,p->ogrenci_sayisi*sizeof(int));
		 
	 }}
	while(psira!=osira && psira->ogr_no!=i && psira->next!=osira && osira->ogr_no!=i){
		psira=psira->prev;
		osira=osira->next;
	}
	if((psira==osira  || psira->next==osira) && psira->ogr_no!=i){
		(*count)=1;
		printf("====================================================\nSilinecek ogrenci bulunamadi\n====================================================\n");
	}
	else{
		if(psira->ogr_no==i){
			if(psira->next==NULL && psira->prev==NULL){
				onceki=NULL;
				sonraki=NULL;
				free(psira);
				(*count)=-1;
				printf("====================================================\nOgrenci basariyla silindi\n====================================================\n");
				}
				else{
			if(psira->next==NULL){
				ksira=psira->prev;
				ksira->next=NULL;
				sonraki=ksira;
				free(psira);
				*count=0;
				printf("====================================================\nOgrenci basariyla silindi\n====================================================\n");
			}
			else{
			ksira=psira->prev;
			bsira=psira->next;
			ksira->next=bsira;
			bsira->prev=ksira;
			*count=1;
			free(psira);
			printf("====================================================\nOgrenci basariyla silindi\n====================================================\n");}
		}}
		else{
			ksira=osira->next;
			if(osira->prev==NULL){
				onceki=ksira;
				ksira->prev=NULL;
				free(osira);
				*count=1;
				printf("====================================================\nOgrenci basariyla silindi\n====================================================\n");
			}
			else{
			bsira=osira->prev;
			bsira->next=ksira;
			ksira->prev=bsira;
			free(osira);
			*count=1;
			printf("====================================================\nOgrenci basariyla silindi\n====================================================\n");
			}
		}
		data=fopen("ogrenci.txt","w");
	 if(data==NULL){
	 	fclose(data);
	 	printf("Dosyaya yazilamadi\n");
	 }
	 else{
	 	psira=onceki;
	 	while(psira!=NULL){
	 		fprintf(data,"%d %s %s %d %d\n",psira->ogr_no,psira->isim,psira->soyisim,psira->aldigi_ders,psira->top_kredi);
	 		psira=psira->next;
		 }}
		 fclose(data);
		kayit=fp(durum_sayisi,kayit);

	}
 		
 	
 	
 }
 if((*count)==1)
		return onceki;
		return sonraki;
 }
 ogrenci *ogrenci_ekle(int * durum_sayisi,durum * kayit,ogrenci * onceki, ogrenci * sonraki, int * count){
 	FILE * data;
 	ogrenci * psira,*nsira,*kontrol_degeri;
 	char date[15];
 	int i,k=0,l=0;
 	psira=(ogrenci*)malloc(sizeof(ogrenci));
 	if(psira==NULL){
 	printf("Alan olusturulamadi\n");
 	(*count)=1;}
 	else{
 	printf("====================================================\nOgrenci numarasi giriniz\n====================================================\n");
 	scanf("%d",&i);
 	 for(k=0;k<*durum_sayisi;k++)
		 {
	if(kayit[k].ogr_no==i && l==0)  {
		printf("Lutfen tarihi gg/aa/yy formatinda giriniz\n");
 		scanf("%s",date);
 		l=1;}
		if(kayit[k].ogr_no==i)  {
		strcpy(kayit[k].tarih,date);
 		strcpy(kayit[k].durum,"Yeni_Kayit");
			 }
		 }
 	if(onceki==NULL){
 	psira->ogr_no=i;
 	printf("====================================================\nLutfen isim giriniz\n====================================================\n");
 	scanf("%s",psira->isim);
 	printf("====================================================\nLutfen soyisim giriniz\n====================================================\n");
 	scanf("%s",psira->soyisim);
 	psira->aldigi_ders=0;
 	psira->top_kredi=0;
 	psira->next=NULL;
 	psira->prev=NULL;
	(*count)=-1;
	onceki=psira;
	sonraki=psira;
	 }
	 else{
 	kontrol_degeri=onceki;
 	k=0;
 		while(kontrol_degeri!=NULL && k==0){
		if(kontrol_degeri->ogr_no==i){
			k=1;
		}
		else
			kontrol_degeri=kontrol_degeri->next;
	}
	if(k==1){
		printf("====================================================\nBu ogrenci kayitlidir \n====================================================\n");
		free(psira);
		(*count)=1;
	}
	else{
 	psira->ogr_no=i;
 	printf("====================================================\nLutfen isim giriniz\n====================================================\n");
 	scanf("%s",psira->isim);
 	printf("====================================================\nLutfen soyisim giriniz\n====================================================\n");
 	scanf("%s",psira->soyisim);
 	psira->aldigi_ders=0;
 	psira->top_kredi=0;
 	psira->next=NULL;
 	psira->prev=NULL;
	nsira=onceki;
	while(nsira->ogr_no<psira->ogr_no && nsira->next!=NULL){
	 	nsira=nsira->next;
		 }
		 if(nsira->prev!=NULL)
		 kontrol_degeri=nsira->prev;
		 	if(nsira->next==NULL){
		 	if(nsira->ogr_no>=psira->ogr_no){
		 	if(nsira->prev==NULL){
		 	onceki=psira;
		 	psira->prev=nsira->prev;
		 	psira->next=nsira;
		 	nsira->prev=psira;
			(*count)=1;
			 }
		 	else{
		 	psira->prev=nsira->prev;
		 	psira->next=nsira;
		 	nsira->prev=psira;	
		 	kontrol_degeri->next=psira;
		 	(*count)=1;
			 }
		 	
				 }
				 else{
		 		sonraki=psira;
		 		nsira->next=psira;
		 		psira->prev=nsira;
		 		(*count)=0;

		 }	}
		 else{
		 	if(nsira==onceki)
			 {
			onceki=psira;
			psira->next=nsira;
		 	nsira->prev=psira;
		 	(*count)=1;
			 }
			 else{
		 	psira->next=nsira;
		 	psira->prev=nsira->prev;
		 	nsira->prev=psira;
			kontrol_degeri->next=psira;
			(*count)=1;
		 }}
	 }

	 }
	 	 data=fopen("ogrenci.txt","w");
	 if(data==NULL){
	 	fclose(data);
	 	printf("Dosyaya yazilamadi\n");
	 }
	 else{
	 	psira=onceki;
	 	while(psira!=NULL){
	 		fprintf(data,"%d %s %s %d %d\n",psira->ogr_no,psira->isim,psira->soyisim,psira->aldigi_ders,psira->top_kredi);
	 		psira=psira->next;
		 }
		 fclose(data);
	 }
	 kayit=durum_guncelle(durum_sayisi,kayit);		
	 printf("Ogrenci basarili sekilde eklendi\n");
	 if(*count==1)
	 return onceki;
	 return sonraki;
 }}
 ders* ders_sil(int * durum_sayisi,durum * kayit,ders * head,ogrenci * onceki, ogrenci * sonraki){
 	FILE * data;
 	ders * sira,*eskisira;
 	ogrenci *psira,*osira;
 	char date[15];
 	char i[20];
 	int j,k;
 	if(head==NULL){
 		printf("====================================================\nHenuz ders girisi olmamistir\n====================================================\n");
	 }
	 else{
 	sira=(head)->next;
 	eskisira=head;
 	printf("====================================================\nSilinecek ders kodunu giriniz\n====================================================\n");
 	scanf("%s",i);
 	printf("Lutfen tarihi gg/aa/yy formatinda giriniz\n");
 	scanf("%s",date);
 	 for(k=1;k<=(*durum_sayisi);k++)
		 {
	if(strcmp(kayit[k-1].ders_kodu,i)==0)  {
 	strcpy(kayit[k-1].tarih,date);
 	strcpy(kayit[k-1].durum,"DERS_KAPANDI");	 } }
 	if(sira==NULL){
 		if(strcmp(eskisira->ders_kodu,i)==0){
 			for(j=0;j<eskisira->ogrenci_sayisi;j++){
 				psira=sonraki;
				osira=onceki;
				while(psira!=osira && psira->ogr_no!=eskisira->no[j] && psira->next!=osira && osira->ogr_no!=eskisira->no[j]){
					psira=psira->prev;
					osira=osira->next;
				}
				if(psira->next==NULL && osira->ogr_no==eskisira->no[j]){
					osira->aldigi_ders--;
					osira->top_kredi-=eskisira->kredi;
				}
				else{
					if(psira->next==NULL){
					psira->aldigi_ders--;
					psira->top_kredi-=eskisira->kredi;
					}
				else{
				if(psira->ogr_no==sira->no[j]){
					psira->aldigi_ders--;
					psira->top_kredi-=eskisira->kredi;
				}
				if(osira->ogr_no==eskisira->no[j]){
					osira->aldigi_ders--;
					osira->top_kredi-=eskisira->kredi;
				}}}}
 			head=NULL;
 			free(eskisira);
 			data=fopen("ders.txt","w");
 			if(data==NULL){
	 	fclose(data);
	 	printf("Dosyaya yazilamadi\n");
	 }
	 else{
	 	
	 	sira=head;
	 	while(sira!=NULL){
	 		fprintf(data,"%s %s %d %d\n",sira->ders_kodu,sira->ders_adi,sira->kredi,sira->kontenjan);
	 		sira=sira->next;
		 }
		 fclose(data);}
 			printf("====================================================\nSilme islemi gerceklesti\n====================================================\n");
 			kayit=durum_guncelle(durum_sayisi,kayit);
		 }
 		else
 		printf("====================================================\nsilinecek ders bulunamadi\n====================================================\n");
	 }
	 else{
	if(strcmp(eskisira->ders_kodu,i)==0){
		for(j=0;j<eskisira->ogrenci_sayisi;j++){
 				psira=sonraki;
				osira=onceki;
				while(psira!=osira && psira->ogr_no!=eskisira->no[j] && psira->next!=osira && osira->ogr_no!=eskisira->no[j]){
					psira=psira->prev;
					osira=osira->next;
				}
				if(psira->next==NULL && osira->ogr_no==sira->no[j]){
					osira->aldigi_ders--;
					osira->top_kredi-=eskisira->kredi;
				}
				else{
					if(psira->next==NULL){
					psira->aldigi_ders--;
					psira->top_kredi-=eskisira->kredi;
					}
				else{
				if(psira->ogr_no==eskisira->no[j]){
					psira->aldigi_ders--;
					psira->top_kredi-=eskisira->kredi;
				}
				if(osira->ogr_no==eskisira->no[j]){
					osira->aldigi_ders--;
					osira->top_kredi-=eskisira->kredi;
				}}}}
 			head=sira;
 			free(eskisira);
 			data=fopen("ders.txt","w");
	 if(data==NULL){
	 	fclose(data);
	 	printf("Dosyaya yazilamadi\n");
	 }
	 else{
	 	sira=head;
	 	while(sira!=NULL){
	 		fprintf(data,"%s %s %d %d\n",sira->ders_kodu,sira->ders_adi,sira->kredi,sira->kontenjan);
	 		sira=sira->next;
		 }
		 fclose(data);
	 }
 			printf("====================================================\nSilme islemi gerceklesti\n====================================================\n");
			 kayit=durum_guncelle(durum_sayisi,kayit);	
	}
	else{
 	while(sira!=NULL && strcmp(sira->ders_kodu,i)){
 		eskisira=sira;
 		sira=sira->next;
	 }
	 if(sira==NULL){
	 	printf("====================================================\nsilinecek ders bulunamadi\n====================================================\n");
	 }
	 else{
	 	for(j=0;j<sira->ogrenci_sayisi;j++){
 				psira=sonraki;
				osira=onceki;
				while(psira!=osira && psira->ogr_no!=sira->no[j] && psira->next!=osira && osira->ogr_no!=sira->no[j]){
					psira=psira->prev;
					osira=osira->next;
				}
					if(psira->next==NULL && osira->ogr_no==sira->no[j]){
					osira->aldigi_ders--;
					osira->top_kredi-=sira->kredi;
				}
				else{
					if(psira->next==NULL){
					psira->aldigi_ders--;
					psira->top_kredi-=sira->kredi;
					}
				else{
				if(psira->ogr_no==sira->no[j]){
					psira->aldigi_ders--;
					psira->top_kredi-=sira->kredi;
				}
				if(osira->ogr_no==sira->no[j]){
					osira->aldigi_ders--;
					osira->top_kredi-=sira->kredi;
				}}}}
		eskisira->next=sira->next;
	 	free(sira);
	 	printf("Silme islemi gerceklesti\n");
	 	data=fopen("ders.txt","w");
	 if(data==NULL){
	 	fclose(data);
	 	printf("Dosyaya yazilamadi\n");
	 }
	 else{
	 	sira=head;
	 	while(sira!=NULL){
	 		fprintf(data,"%s %s %d %d\n",sira->ders_kodu,sira->ders_adi,sira->kredi,sira->kontenjan);
	 		sira=sira->next;
		 }
		 fclose(data);}
	 	kayit=durum_guncelle(durum_sayisi,kayit);
	 }}}}
	 	 	 data=fopen("ogrenci.txt","w");
	 if(data==NULL){
	 	fclose(data);
	 	printf("Dosyaya yazilamadi\n");
	 }
	 else{
	 	psira=onceki;
	 	while(psira!=NULL){
	 		fprintf(data,"%d %s %s %d %d\n",psira->ogr_no,psira->isim,psira->soyisim,psira->aldigi_ders,psira->top_kredi);
	 		psira=psira->next;
		 }
		 fclose(data);
	 }
	 return head;
 }
 ders * ders_ekle(int * durum_sayisi,durum * kayit,ders * head){
 	FILE *data;
 	ders * sira,*deger,*eskisira,*kontrol_degeri;
 	int k=0,j,l=0,mn;
 	char date[15],i[20];
 	deger=(ders*)malloc(sizeof(ders));
 	printf("====================================================\nLutfen ders kodunu giriniz\n====================================================\n");
	scanf("%s",i); 
	kontrol_degeri=head;
	while(kontrol_degeri!=NULL && k==0){
		if(strcmp(kontrol_degeri->ders_kodu,i)==0){
			k=1;
		}
		else
		kontrol_degeri=kontrol_degeri->next;
	}
	if(k==1){
		printf("====================================================\nBu ders onceden girilmistir\n====================================================\n");
		free(deger);
	}else{
	for(k=0;k<(*durum_sayisi);k++)
	 {
	if(strcmp(kayit[k].ders_kodu,i)==0 && l==0)  {
	printf("Lutfen tarihi gg/aa/yy formatinda giriniz\n");
 	scanf("%s",date);
 	l=1;}
	if(strcmp(kayit[k].ders_kodu,i)==0)  {
	strcpy(kayit[k].tarih,date);
 	strcpy(kayit[k].durum,"Yeni_Ders");
		 }
	 }k=0;
	strcpy(deger->ders_kodu,i);
 	printf("====================================================\nLutfen ders adini giriniz\n====================================================\n");
 	scanf("%s",deger->ders_adi);
 	printf("====================================================\nLutfen ders kredisini giriniz\n====================================================\n");
 	scanf("%d",&mn); deger->kredi=mn;
 	printf("====================================================\nLutfen ders kontenjanini giriniz\n====================================================\n");
 	scanf("%d",&mn); deger->kontenjan=mn;deger->kalan_kontenjan=mn;
 	deger->next=NULL;
 	deger->ogrenci_sayisi=0;

 		//fclose(data);
 	if(head==NULL){
 		head=deger;
	 }
	 else{
 	sira=(head)->next;
 	eskisira=head;
 	if(sira==NULL || strcmp(eskisira->ders_kodu,deger->ders_kodu)>0){
 		if(strcmp(head->ders_kodu,deger->ders_kodu)<0)
 		(head)->next=deger;
 		else{
 			deger->next=head;
 			head=deger;
		 }
	 }
	 else{
 	while(sira->next!=NULL && strcmp(sira->ders_kodu,deger->ders_kodu)<0){
 	eskisira=sira;
 	sira=sira->next;
	 }
 	if(sira->next==NULL){
 		if(strcmp(sira->ders_kodu,deger->ders_kodu)<0)
 	sira->next=deger;
 	else{
 		eskisira->next=deger;
 		deger->next=sira;
	 }
	 }
	 else{
	eskisira->next=deger;
	deger->next=sira;
}
}}
	printf("====================================================\nDers basarili bir sekilde eklendi\n====================================================\n");}
	 	data=fopen("ders.txt","w");
 		sira=head;
 		while(sira!=NULL){
 		fprintf(data,"%s %s %d %d\n",sira->ders_kodu,sira->ders_adi,sira->kredi,sira->kontenjan);
 		sira=sira->next;
 		}
 		fclose(data);
 		kayit=durum_guncelle(durum_sayisi,kayit);
 		return head;
 }
 void dersten_ogrenci_sil(int * durum_sayisi,durum * kayit,ders * head,ogrenci * onceki, ogrenci * sonraki){
 	ders * p,*sira;
 	FILE * data;
 	ogrenci * psira;
 	char i[20];
 	ogrenci * kontrol_degeri, *nsira,*osira;
  	int j=0,k=0,mn;
 	printf("====================================================\nLutfen ders kodunu giriniz\n====================================================\n");
 	scanf("%s",i);
 	p=head;	
 	while(p!=NULL && strcmp(p->ders_kodu,i)!=0){
 		p=p->next;
	 }
	 if(p==NULL){
	 	printf("====================================================\nDers bulunamadi\n====================================================\n");
	 }
	 else{
	 nsira=onceki;
	 	printf("====================================================\nLutfen ogrenci numarasini giriniz\n====================================================\n");
 		scanf("%d",&mn);
 	while(j<p->ogrenci_sayisi && k==0){
 		if(p->no[j]!=mn)
 		j++;	
 		else
 		k=1;
	 }
	 if(k!=1){
	 	printf("====================================================\nOgrenci bu dersi almiyor ya da boyle bir ogrenci yok\n====================================================\n");
	 }
	 else{
	 	for(k=j;k<p->ogrenci_sayisi-1;k++){
	 		p->no[k]=p->no[k+1];
		 }
		 p->ogrenci_sayisi--;
		 p->kalan_kontenjan++;
		 nsira=sonraki;
		 osira=onceki;
		 p->no=(int*)realloc(p->no,p->ogrenci_sayisi*sizeof(int));
		 while(nsira->ogr_no !=mn && osira->ogr_no!=mn){
		 	nsira=nsira->prev;
		 	osira=osira->next;
		 }
		 if(nsira->ogr_no==mn){
		 	nsira->aldigi_ders--;
		 	nsira->top_kredi-=p->kredi;
		 }
		 else{
		 	osira->aldigi_ders--;
		 	osira->top_kredi-=p->kredi;
		 }
		 for(k=0;k<*durum_sayisi;k++)
		 {
		 	if(kayit[k].ogr_no==mn && strcmp(kayit[k].ders_kodu,p->ders_kodu)==0)  {
 		printf("Lutfen tarihi gg/aa/yy formatinda giriniz\n");
 		scanf("%s",kayit[k].tarih);
 		strcpy(kayit[k].durum,"Birakti");
			 }
		 }
		 printf("====================================================\nOgrenci basariyla silindi\n====================================================\n");
		 kayit=durum_guncelle(durum_sayisi,kayit);
		 	  	data=fopen("ogrenci.txt","w");
	 if(data==NULL){
	 	fclose(data);
	 	printf("Dosyaya yazilamadi\n");
	 }
	 else{
	 	psira=onceki;
	 	while(psira!=NULL){
	 		fprintf(data,"%d %s %s %d %d\n",psira->ogr_no,psira->isim,psira->soyisim,psira->aldigi_ders,psira->top_kredi);
	 		psira=psira->next;
		 }
		 fclose(data);
		  data=fopen("ders.txt","w");
 		sira=head;
 		while(sira!=NULL){
 		fprintf(data,"%s %s %d %d\n",sira->ders_kodu,sira->ders_adi,sira->kredi,sira->kontenjan);
 		sira=sira->next;
 		}
 		fclose(data);
		 
	 }}}
	 
 }
 durum * derse_ogrenci_ekle(int maximumders,int maximumkredi,int* durum_sayisi,durum * kayit,ders * head,ogrenci * onceki, ogrenci * sonraki){
 	ders * p,*sira;
 	FILE * data;
 	ogrenci * psira;
 	ogrenci * kontrol_degeri,*nsira,*osira;
 	durum * kayit1;
 	kayit1=kayit;
 	char date[15],i[20];
 	int j,k=0,l,mn;
 	printf("====================================================\nLutfen ders kodunu giriniz\n====================================================\n");
 	scanf("%s",i);
 	p=head;	
 	while(p!=NULL && strcmp(p->ders_kodu,i)!=0){
 		p=p->next;
	 }
	 if(p==NULL){
	 	printf("====================================================\nDers bulunamadi\n====================================================\n");
	 }
	 else{
	 if(p->kalan_kontenjan==0){
	 	printf("====================================================\nKontenjan kalmamistir ogrenci eklenemiyor\n====================================================\n");
	 }
	 else{
	 	nsira=onceki;
	 	printf("Lutfen ogrenci numarasini giriniz\n");
 		scanf("%d",&mn);
	 	while(nsira!=NULL && nsira->ogr_no!=mn){
	 	nsira=nsira->next;
		 }
		 if(nsira==NULL){
		 	printf("====================================================\nOgrenci bulunamadi\n====================================================\n");
		 }
		 
		 else{
		 if(nsira->aldigi_ders+1>maximumders|| nsira->top_kredi+p->kredi>maximumkredi){
		 	if(nsira->aldigi_ders+1>7)
		 	printf("====================================================\n!!!Ogrenci maksimum ders sayisina ulasmistir!!!\n====================================================\n");
		 	else
		 	printf("====================================================\n!!!Ogrenci maksimum kredi sayisina ulasmistir!!!\n====================================================\n");
		 }
		 else{
		printf("Lutfen tarihi gg/aa/yy formatinda giriniz\n");
 		scanf("%s",date);
	 if(p->ogrenci_sayisi==0){
	 	p->no=(int*)malloc(sizeof(int));
	 	if(p->no==NULL)
	 	printf("Bos alan yok\n");
	 	else{
	 	p->ogrenci_sayisi=1;
	 	p->no[p->ogrenci_sayisi-1]=mn;
 		p->kalan_kontenjan--;
 		nsira->aldigi_ders++;
 		nsira->top_kredi+=p->kredi;
 		mn=0;
 		while(mn<*durum_sayisi && (strcmp(p->ders_kodu,kayit[mn].ders_kodu )!=0 || kayit[mn].ogr_no!=nsira->ogr_no )){
 		mn++;
		 }
		if(mn<*durum_sayisi){
		strcpy(kayit[mn].tarih,date);
		strcpy(kayit[mn].durum,"Kayitli");
		}
		else{
 		(*durum_sayisi)++;
 		kayit=(durum*)realloc(kayit1,(*durum_sayisi)*sizeof(durum));
 		kayit[(*durum_sayisi)-1].satir=(*durum_sayisi);
 		strcpy(kayit[(*durum_sayisi)-1].ders_kodu,p->ders_kodu);
 		kayit[(*durum_sayisi)-1].ogr_no=nsira->ogr_no;
 		strcpy(kayit[mn].tarih,date);
 		strcpy(kayit[(*durum_sayisi)-1].durum,"Kayitli");}
	 }
	  printf("====================================================\nOgrenci derse basarili bir sekilde eklenmistir\n====================================================\n");
	  	data=fopen("ogrenci.txt","w");
	 if(data==NULL){
	 	fclose(data);
	 	printf("Dosyaya yazilamadi\n");
	 }
	 else{
	 	psira=onceki;
	 	while(psira!=NULL){
	 		fprintf(data,"%d %s %s %d %d\n",psira->ogr_no,psira->isim,psira->soyisim,psira->aldigi_ders,psira->top_kredi);
	 		psira=psira->next;
		 }
		 fclose(data);
		  data=fopen("ders.txt","w");
 		sira=head;
 		while(sira!=NULL){
 		fprintf(data,"%s %s %d %d\n",sira->ders_kodu,sira->ders_adi,sira->kredi,sira->kontenjan);
 		sira=sira->next;
 		}}
 		fclose(data);
 		
	 kayit=durum_guncelle(durum_sayisi,kayit);
	 }
	 else{
k=0;
 for(j=0;j<p->ogrenci_sayisi;j++){
 	if(p->no[j]==mn)
 	k=1;
 }
 if(k==1){
 	printf("====================================================\nOgrenci zaten bu dersi aliyor\n====================================================\n");
 }
 else{
 p->ogrenci_sayisi++;
 p->no=(int*)realloc(p->no,p->ogrenci_sayisi*sizeof(int));
 j=0;
 while(j<p->ogrenci_sayisi && p->no[j]<mn){
 	j++;
 }
 for(k=p->ogrenci_sayisi-1;k>j;k--){
 	p->no[k]=p->no[k-1];
 }
 p->no[k]=mn;
 p->kalan_kontenjan--;
 nsira->aldigi_ders++;
 nsira->top_kredi+=p->kredi;
 		mn=0;
 		while(mn<(*durum_sayisi) && (strcmp(p->ders_kodu,kayit[mn].ders_kodu )!=0|| kayit[mn].ogr_no!=nsira->ogr_no) ){
 		mn++;
		 }
		if(mn<*durum_sayisi){
		strcpy(kayit[mn].tarih,date);
		strcpy(kayit[mn].durum,"Kayitli");
	}
	else{
	l=(*durum_sayisi);
 (*durum_sayisi)++;
kayit=(durum*)realloc(kayit,(l+1)*sizeof(durum));
kayit[l].satir=(*durum_sayisi);
strcpy(kayit[l].ders_kodu,p->ders_kodu);
kayit[l].ogr_no=nsira->ogr_no;
strcpy(kayit[l].tarih,date);
strcpy(kayit[l].durum,"Kayitli");
 }
 printf("====================================================\nOgrenci derse basarili bir sekilde eklenmistir\n====================================================\n");
data=fopen("ogrenci.txt","w");
	 if(data==NULL){
	 	fclose(data);
	 	printf("Dosyaya yazilamadi\n");
	 }
	 else{
	 	psira=onceki;
	 	while(psira!=NULL){
	 		fprintf(data,"%d %s %s %d %d\n",psira->ogr_no,psira->isim,psira->soyisim,psira->aldigi_ders,psira->top_kredi);
	 		psira=psira->next;
		 }
		 fclose(data);
		  data=fopen("ders.txt","w");
 		sira=head;
 		while(sira!=NULL){
 		fprintf(data,"%s %s %d %d\n",sira->ders_kodu,sira->ders_adi,sira->kredi,sira->kontenjan);
 		sira=sira->next;
 		}}
 		fclose(data);
 kayit=durum_guncelle(durum_sayisi,kayit);
 }}}
 }

 }}
 return kayit;
 }
void derse_kayit_listele(int * durum_sayisi,ders * head,ogrenci * onceki){
	ders * p;
	ogrenci * ogr;
	int i;
	char dosyaadi[20],n[20];
	FILE * data;
	printf("Lutfen ders kodu giriniz: ");
	scanf("%s",&n);
	p=head;
	while(p!=NULL && strcmp(p->ders_kodu,n)!=0){
		p=p->next;
	}
	strcat(n,".txt");
	if(p==NULL || p->ogrenci_sayisi==0)
	printf("Boyle bir ders yok ya da bu dersi alan ogrenci yok\n");
	else{
		data=fopen(n,"w");
		if(data!=NULL){
		for(i=0;i<p->ogrenci_sayisi;i++){
			printf("%d. kayit ogrenci no = %d\n",i+1,p->no[i]);
			ogr=ogrenci_bul(onceki,p->no[i]);
			fprintf(data,"%d %s %s\n",ogr->ogr_no,ogr->isim,ogr->soyisim);
		}
		fclose(data);
		}
		else{
			printf("Dosya olusamadi\n");
		}
		printf("\n");
	}}
void ogrenci_dersleri_listele(int * durum_sayisi,durum * kayit,ders * head){
	int i,n,k;
	ders * dersim;
	FILE * data=NULL;
	char dosyaadi[20];
	printf("Lutfen ogrenci numarasi giriniz: ");
	scanf("%d",&n);
	k=n;
	itoa(k,dosyaadi,10);
	strcat(dosyaadi,"_DERSPROGRAMI.txt");
	for(i=0;i<(*durum_sayisi) && data==NULL;i++){
		if(kayit[i].ogr_no==k && !strcmp(kayit[i].durum,"Kayitli")){
			data=fopen(dosyaadi,"w");}
	}
	if(i<=(*durum_sayisi)){
	for(i=0;i<(*durum_sayisi);i++){
		if(kayit[i].ogr_no==k && !strcmp(kayit[i].durum,"Kayitli")){
		dersim=ders_bul(head,kayit[i].ders_kodu);
		fprintf(data,"%s %s %d %d\n",dersim->ders_kodu,dersim->ders_adi,dersim->kredi,dersim->kontenjan);
		printf("%s %s %d %d\n",dersim->ders_kodu,dersim->ders_adi,dersim->kredi,dersim->kontenjan);
		}
	}
	fclose(data);
	}

	printf("\n");

}
void durum_listele(int * durum_sayisi,durum * kayit){
	int i;
	for(i=0;i<(*durum_sayisi);i++){
		printf("\n%d %s %d %s %s\n",kayit[i].satir,kayit[i].ders_kodu,kayit[i].ogr_no,kayit[i].tarih,kayit[i].durum);
	}
}
int main(){
	FILE * data;
	int i,choice,maximumders,maximumkredi;
	int durum_sayisi=0,count;
	ders * p, *p1;
	ders * head=NULL;
	ogrenci * psira,*p1sira;
	durum * kayit;
	ogrenci * sonraki=NULL;
	ogrenci * onceki=NULL;
	ogrenci * deneme=NULL;
	durum_sayisi=0;
	kayit=(durum*)malloc(sizeof(durum));
	printf("Ogrencinin alabileceki maksimum kredi sayisini giriniz\n");
	scanf("%d",&maximumkredi);
	printf("Ogrencinin alabilecegi maximum ders sayisini giriniz\n");
	scanf("%d",&maximumders);
	head=otodersekle(&durum_sayisi,head);
	onceki=otoogrekle(&durum_sayisi,onceki,sonraki);
	sonraki=onceki;
	sonraki=otoogrekle(&durum_sayisi,onceki,sonraki);
	kayit=durum_oku(&durum_sayisi,kayit,head);
	while (i)
    {
        printf("====================================================\nHangisini yapacaksin:\n");
        printf("Ders eklemek icin 1 ---\n");
        printf("Ders silmek icin 2---\n");
        printf("Ogrenci Eklemek icin 3---\n");
        printf("Ogrenci silmek icin 4---\n");
        printf("Derse ogrenci eklemek icin 5---\n");
        printf("Dersten ogrenci silmek icin 6---\n");
        printf("Derse kayitli ogrencileri listelemek icin 7---\n");
        printf("Ogrencinin aldigi dersleri listelemek icin 8---\n");
        printf("Durumlari goruntulemek icin icin 9---\n");
        printf("Cikis yapmak icin 10---\n====================================================\n");
        scanf(" %d", &choice);
        if(choice>10 || choice < 1){
        	printf("====================================================\nMAKINEYI KANDIRAMAZSIN \n====================================================\n");
				i=1;
		}else{
        switch (choice)
        {
        case 1:
            head=ders_ekle(&durum_sayisi,kayit,head);
            break;
        case 2:
            head=ders_sil(&durum_sayisi,kayit,head,onceki,sonraki);
            break;
        case 3:
           deneme=ogrenci_ekle(&durum_sayisi,kayit,onceki,sonraki,&count);
           if(count==1){
           	onceki=deneme;
		   }
		   else{if(count==0){
		   	sonraki=deneme;
		   }
		   else{
		   	onceki=deneme;
		   	sonraki=deneme;
		   }
		   }
		    data=fopen("ogrenci.txt","w");
	 if(data==NULL){
	 	fclose(data);
	 	printf("Dosyaya yazilamadi\n");
	 }
	 else{
	 	psira=onceki;
	 	while(psira!=NULL){
	 		fprintf(data,"%d %s %s %d %d\n",psira->ogr_no,psira->isim,psira->soyisim,psira->aldigi_ders,psira->top_kredi);
	 		psira=psira->next;
		 }
		 fclose(data);
	 }
            break;
        case 4:
            deneme=ogrenci_sil(&durum_sayisi,kayit,head,onceki,sonraki,&count, durum_guncelle);
            if(count == 1){
            	onceki=deneme;
			}
			else{if(count==0)
				sonraki=deneme;
				else
				{
					sonraki=NULL;
					onceki=NULL;
				}
			}
            break;
        case 5:
            kayit=derse_ogrenci_ekle(maximumders,maximumkredi,&durum_sayisi,kayit,head,onceki,sonraki);
            break;
        case 6:
        	dersten_ogrenci_sil(&durum_sayisi,kayit,head,onceki,sonraki);
        	break;
    	case 7:
    		derse_kayit_listele(&durum_sayisi,head,onceki);
    		break;
    	case 8:
    		ogrenci_dersleri_listele(&durum_sayisi,kayit,head);
    		break;
    	case 9:
    		durum_listele(&durum_sayisi,kayit);
    		break;
        case 10:
            i=0; }}
			 }
		free(kayit);
		p=head;
		psira=onceki;
		while(p!=NULL){
			p1=p;
			p=p->next;
			free(p1);
		}
		while(psira!=NULL){
			p1sira=psira;
			psira=psira->next;
			free(p1sira);
		}
		return 0;
}
