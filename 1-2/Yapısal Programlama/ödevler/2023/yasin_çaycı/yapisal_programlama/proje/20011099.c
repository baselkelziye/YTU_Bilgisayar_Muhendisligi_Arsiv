#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct yazar{
	int yazarID;
	char yazarAd[30];
	char yazarSoyad[30];
	struct yazar *next;
}Yazar;

typedef struct ogrenci{ 
	char ogrID[9];
	char ad[30];
	char soyad[30];
	int puan;
	struct ogrenci *next;
	struct ogrenci *prev;
}Ogrenci;

typedef struct kitapornek{
	char EtiketNo[20];
	char Durum[8];
	struct kitapornek *next;
}KitapOrnek;

typedef struct kitap{
	char kitapAdi[30];
	char ISBN[13];
	int adet;
	struct kitap *next;
	struct kitapornek *head;
}Kitap;

typedef struct kitapyazar{
	char ISBN[13];
	int YazarID;
}KitapYazar;

typedef struct tarih{
	int gun:5;
	int ay:4;
	int yil:12;
}Tarih;

typedef struct kitapodunc{
	char EtiketNo[20];
	char ogrID[8];
	int islemTipi:1;
	struct tarih islemTarihi;
}KitapOdunc;

void addStudent(Ogrenci **head);
void deleteStudent(Ogrenci **head);
void updateStudent(Ogrenci **head);
void printStudent(Ogrenci* head, char ogrID[]);
void printAllStudents(Ogrenci* head);
void ogrUpdateFile(Ogrenci **head);
void readStudentsFile(Ogrenci **head);
void reverseStudents(Ogrenci **head);
void addWriter(Yazar **head);
void deleteWriter(Yazar **head);
void updateWriter(Yazar **head);
void printAllWriters(Yazar* head);
void printWriter(Yazar* head, char yazaradi[]);
void yzrUpdateFile(Yazar **head);
void readWritersFile(Yazar **head);
void reverseWriters(Yazar **head);
void addBook(Kitap **head);
void deleteBook(Kitap **head);
void updateBook(Kitap **head);
void printBook(Kitap* head, char kitapadi[]);
void printAvailableBooks(Kitap* head);
void createBookFile(Kitap *head);
KitapOrnek *createBookSample(Kitap* ktp);
void readBooksFile(Kitap **head,KitapOrnek **head_ornek);
void reverseBooks(Kitap **head);
static int yazarID_inc; //izin verildi
int main(){
	setlocale(LC_ALL,"Turkish");
	Ogrenci *head = NULL;
	Yazar *head_w = NULL;
	Kitap *head_b = NULL;
	KitapOrnek *head_ornek = NULL;
	readStudentsFile(&head);
	reverseStudents(&head);
	readWritersFile(&head_w);
	reverseWriters(&head_w);
	readBooksFile(&head_b,&head_ornek);
	reverseBooks(&head_b);
	
	int choice = 0,in_choice = 0; //ana menü ve içtek seçim için
	char ogr_id[8];
	char yazarAd[30];
	char kitapAdi[30];
	while(choice != 15){
		printf("1- Öðrenci Ekle, Sil, Güncelle:\n2- Öðrenci Bilgisi Görüntüleme: \n3- Kitap Teslim Etmemiþ Öðrencileri Listele:\n4- Cezalý Öðrencileri Listele\n5- Tüm Öðrencileri Listele\n6- Kitap Ödünç Al/Teslim Et\n7- Kitap Ekle, Sil, Güncelle:\n8- Kitap Bilgisi Görüntüleme:\n9- Raftaki Kitaplarý Listele:\n10- Zamanýnda Teslim Edilmeyen Kitaplarý Listele:\n11- Kitap-Yazar Eþleþtir:\n12- Kitabýn Yazarýný Güncelle:\n13- Yazar Ekle, Sil, Güncelle:\n14- Yazar Bilgisi Görüntüleme:\n15- Çýkýþ: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Öðrenci eklemek için 1, silmek için 2, güncellemek için bunlarýn dýþýnda bir deðer giriniz: "); scanf("%d",&in_choice);
				if(in_choice == 1){
					addStudent(&head);
				}
				else if(in_choice == 2){
					deleteStudent(&head);
				}
				else{
					updateStudent(&head);
				}					
				break;
			case 2:
				printf("Görüntülemek istediðiniz öðrencinin numarasýný giriniz: "); //ID bilgisi veya Ad-Soyad bilgisi dendiði için ID ye göre yapýldý
				scanf("%s",ogr_id);
				printStudent(head,ogr_id);
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				printAllStudents(head);
				break;
			case 6:
				break;
			case 7:
				printf("Kitap eklemek için 1, silmek için 2, güncellemek için bunlarýn dýþýnda bir deðer giriniz: "); scanf("%d",&in_choice);
				if(in_choice == 1){
					addBook(&head_b);
				}
				else if(in_choice == 2){
					deleteBook(&head_b);
				}
				else{
					updateBook(&head_b);
				}	
				break;
			case 8:
				printf("Görüntülemek istediðiniz kitabýn ismini giriniz: "); 
				scanf(" %[^\n]",kitapAdi);
				printBook(head_b,kitapAdi);
				break;
			case 9:
				printAvailableBooks(head_b);
				break;
			case 10:
				break;
			case 11:
				break;
			case 12:
				break;
			case 13:
				printf("Yazar eklemek için 1, silmek için 2, güncellemek için bunlarýn dýþýnda bir deðer giriniz:"); scanf("%d",&in_choice);
				if(in_choice == 1){
					addWriter(&head_w);
					printAllWriters(head_w);
				}
				else if(in_choice == 2){
					deleteWriter(&head_w);
					printAllWriters(head_w);
				}
				else{
					updateWriter(&head_w);
					printAllWriters(head_w);
				}				
				break;
			case 14:
				printf("Görüntülemek istediðiniz yazarýn adýný giriniz: "); 
				scanf(" %[^\n]",yazarAd);
				printWriter(head_w,yazarAd);
				break;
			case 15:
				printf("Çýkýþ yapýlýyor...\n");
				break;
			default:
				printf("Hatali deger girildi, program kapatýlýyor...\n");
				return -1;													
		}
	}
	return 0;
}

void reverseBooks(Kitap **head){
	Kitap *prev = NULL;
    Kitap *cur = *head;
    Kitap *next;
    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *head = prev;
}

void readBooksFile(Kitap **head,KitapOrnek **head_ornek){
	FILE *fp = fopen("Kitaplar.csv","r");
	if(fp == NULL){
		printf("Dosya açýlamadý...\n");
		return;
	}
	char kitapAdi[30];
	char ISBN[13];
	int adet,i;
	char inputs[100];
	while(fgets(inputs,sizeof(inputs),fp) != NULL){
		Kitap *kitap = (Kitap*) malloc(sizeof(Kitap));
		sscanf(inputs, "%[^,],%[^,],%d\n",kitapAdi,ISBN,&adet); //satýrý okuyor ^, ile diðer parametreye geçileceði anlaþýlýr
		strcpy(kitap->ISBN,ISBN);
		strcpy(kitap->kitapAdi,kitapAdi);
		kitap->adet = adet;
		createBookSample(kitap); //üstte kitap bilgileri doldurduktan sonra örnekleri bu fonksiyon ile doldurdum
		kitap->next = *head; //baþtan ekleme
		*head = kitap;
	}
	fclose(fp);
}

KitapOrnek *createBookSample(Kitap* ktp){
	int i;
	ktp->head = NULL;
	for(i = 0; i < ktp->adet; i++){
		KitapOrnek *tmp2;
		KitapOrnek *ktpOrnek= (KitapOrnek*) malloc(sizeof(KitapOrnek));
		ktpOrnek->next = NULL;
		if(ktpOrnek == NULL){
			printf("Yer ayrýlamadý...\n");
			return;
		}
		sprintf(ktpOrnek->EtiketNo,"%s_%d",ktp->ISBN,i+1);
		strcpy(ktpOrnek->Durum,"RAFTA"); //tüm örnekler default olarak rafta
		if(i == 0)//ilk örneði head e atmak için
			ktp->head = ktpOrnek;
		else{//sondan ekleme
			tmp2 = ktp->head;
			while(tmp2->next != NULL)
				tmp2 = tmp2->next;
			tmp2->next = ktpOrnek;
		}
	}
	return (ktp->head);
}

void addBook(Kitap **head){
	Kitap *ktp,*tmp;
	ktp = (Kitap*) malloc(sizeof(Kitap));
	ktp->next = NULL;
	if(ktp == NULL){
		printf("Yer ayrýlamadý...\n");
		return;
	}
	
	printf("Kitap adýný giriniz: "); scanf(" %[^\n]",ktp->kitapAdi);
	printf("Kitap ISBN giriniz: "); scanf(" %[^\n]",ktp->ISBN);
	printf("Kitap adetini giriniz: "); scanf("%d",&ktp->adet);
	
	if(*head == NULL){ //ilk baþta eleman yoksa
		*head = ktp;
	} else{
		tmp = *head;
		while(tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = ktp;
	}
	
	ktp->head = createBookSample(ktp);

	// Kitaplar.csv dosyasýna kitap bilgisi yazýlýr
	FILE *fp = fopen("Kitaplar.csv", "a");
	fprintf(fp, "%s,%s,%d\n", ktp->kitapAdi, ktp->ISBN, ktp->adet);
	fclose(fp);
	
}

void deleteBook(Kitap **head){
	Kitap *tmp, *prev, *sakla = *head;
	char kitapAdi[30];
	printf("Silmek istediðiniz kitabýn ismini giriniz: "); scanf(" %[^\n]",kitapAdi); strlwr(kitapAdi);
	tmp = *head;
	prev = *head;
	if(*head == NULL){
		printf("Silinecek isime sahip bir kitap yok...\n");
		return;
	}
	strlwr(tmp->kitapAdi);
	while(strcmp(tmp->kitapAdi,kitapAdi) != 0){ //aranan kitap tmp de
		tmp = tmp->next;
		strlwr(tmp->kitapAdi);
		if(tmp == NULL){
			printf("Girilen isme sahip bir kitap bulunamadý\n");
			return;
		}
	}
	if(tmp == *head){ //kitap listenin baþýndaysa
		*head = (*head)->next;
		free(tmp);
	} else{
		while(prev->next != tmp){
			prev = prev->next;
		}
		prev->next = tmp->next;
		free(tmp);
	}
	
	createBookFile(*head);
}

void updateBook(Kitap **head){
	char kitapAdi[30];
	Kitap *tmp;
	tmp = *head;
	if(*head == NULL){
		printf("Verilen adreste eleman yok\n");
		return;
	}
	printf("Güncellemek istediðiniz kitabýn adýný giriniz: "); scanf(" %[^\n]",kitapAdi); strlwr(kitapAdi);
	strlwr(tmp->kitapAdi);
	while(strcmp(tmp->kitapAdi,kitapAdi) != 0){ //aranan kitap tmp de
		tmp = tmp->next;
		strlwr(tmp->kitapAdi);
		if(tmp == NULL){
			printf("Girilen isme sahip bir kitap bulunamadý\n");
			return;
		}
	}
	printf("Kitabýn güncel adýný giriniz: "); scanf(" %[^\n]",tmp->kitapAdi);
	printf("Kitabýn güncel ISBN numarasýný giriniz: "); scanf(" %[^\n]",tmp->ISBN);
	printf("Kitabýn güncel miktarýný giriniz: "); scanf("%d",&tmp->adet);
	
	//Güncel kitap örnekleri oluþturmak için;
	int i;
	tmp->head = NULL;
	for(i = 0; i < tmp->adet; i++){
		KitapOrnek *tmp2;
		KitapOrnek *ktpOrnek= (KitapOrnek*) malloc(sizeof(KitapOrnek));
		ktpOrnek->next = NULL;
		if(ktpOrnek == NULL){
			printf("Yer ayrýlamadý...\n");
			return;
		}
		sprintf(ktpOrnek->EtiketNo,"%s_%d",tmp->ISBN,i+1);
		strcpy(ktpOrnek->Durum,"RAFTA");
		if(i == 0)//ilk örneði head e atmak için
			tmp->head = ktpOrnek;
		else{ //sondan güncelleme
			tmp2 = tmp->head;
			while(tmp2->next != NULL)
				tmp2 = tmp2->next;
			tmp2->next = ktpOrnek;
		}	
	}
	createBookFile(*head);
	
}

void createBookFile(Kitap *head){
	// Kitaplar.csv dosyasýndaki kitap bilgisini güncellemek için;
	FILE *fp = fopen("Kitaplar.csv", "w");
	Kitap *ktp = head;
	while (ktp != NULL){
	    fprintf(fp, "%s,%s,%d\n", ktp->kitapAdi, ktp->ISBN, ktp->adet);
	    ktp = ktp->next;
	}
	fclose(fp);
}

void printBook(Kitap* head, char kitapadi[]){
	Kitap *tmp = head;
	KitapOrnek* sakla;
	int i;
	strlwr(tmp->kitapAdi);
	strlwr(kitapadi);
	while(tmp != NULL && strcmp(tmp->kitapAdi,kitapadi) != 0){
		tmp = tmp->next;
		strlwr(tmp->kitapAdi);
	}
	if(tmp != NULL){
		sakla = tmp->head; //tmp->head saklandý
		printf("\n%s,%s,%d\n\n",tmp->kitapAdi,tmp->ISBN,tmp->adet); //burada genel kitap listesi yazdýrýldý
		for(i = 0; i < tmp->adet; i++){
			printf("\n%s,%s\n",tmp->head->EtiketNo,tmp->head->Durum); //burada da kitaplarýn örnekleri yazdýrýldý
			tmp->head = tmp->head->next;
		}
		tmp->head = sakla; //eski deðerine kavuþtu
	}
	else
		printf("Girilen isimde bir kitap yok...\n");
	return;	
}

void printAvailableBooks(Kitap* head){
	Kitap *tmp = head;
	KitapOrnek* sakla;
	char Durum[8] = "RAFTA";
	while(tmp != NULL){
		sakla = tmp->head; //tmp->head yedeklendi
		while(tmp->head != NULL){
			if(strcmp(tmp->head->Durum,Durum) == 0){ //arama yapýldý
				printf("%s\n",tmp->head->EtiketNo);
				tmp->head = tmp->head->next;
			}
		}
		tmp->head = sakla; //eski deðerini aldý
		tmp = tmp->next;
	}
}

void reverseWriters(Yazar **head){ //dosya tersten okunduðu için tekrar tersi alýndý
    Yazar *prev = NULL;
    Yazar *cur = *head;
    Yazar *next;
    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *head = prev;
}

void readWritersFile(Yazar **head){
	FILE *fp = fopen("yazarlar.csv","r");
	if(fp == NULL){
		printf("Dosya açýlamadý...\n");
		return;
	}
	int yazarID;
	char yazarAd[30];
	char yazarSoyad[30];
	char inputs[100];
	while(fgets(inputs,sizeof(inputs),fp) != NULL){
		Yazar *yazar = (Yazar*) malloc(sizeof(Yazar));
		sscanf(inputs, "%d,%[^,],%[^\n]\n",&yazarID,yazarAd,yazarSoyad); // ^, ile , görene kadar ^\n ile satýr atlama görene kadar atama yapýldý
		yazar->yazarID = yazarID;
		strcpy(yazar->yazarAd,yazarAd);
		strcpy(yazar->yazarSoyad,yazarSoyad);
		yazar->next = *head; //baþtan ekleme
		*head = yazar;
		yazarID_inc = yazar->yazarID; //en son okunan id atýldý
	}
	fclose(fp);
}

void addWriter(Yazar **head){
	Yazar *yzr,*tmp;
	yzr = (Yazar*) malloc(sizeof(Yazar));
	yzr->next = NULL;
	if(yzr == NULL){
		printf("Yer ayrýlamadý...\n");
		return;
	}
	
	printf("Yazarýn adýný giriniz: "); scanf(" %[^\n]",yzr->yazarAd);
	printf("Yazarýn soyadýný giriniz: "); scanf(" %[^\n]",yzr->yazarSoyad);
	yazarID_inc++; //yazar id otomatik artar
	yzr->yazarID = yazarID_inc;
	if(*head == NULL){ //head boþsa
		*head = yzr;
	} else{ //sondan ekleme
		tmp = *head;
		while(tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = yzr;
	}
	
	// yazarlar.csv dosyasýna yazar eklemek için;
    FILE *fp = fopen("yazarlar.csv", "a");
    fprintf(fp, "%d,%s,%s\n", yzr->yazarID, yzr->yazarAd, yzr->yazarSoyad);
    fclose(fp);
	
}

void deleteWriter(Yazar **head){
	Yazar *tmp, *prev;
	int id;
	printf("Silmek istediðiniz yazarýn numarasýný giriniz: "); scanf("%d",&id);
	tmp = *head;
	prev = *head;
	if(*head == NULL){
		printf("Silinecek bir yazar yok...\n");
		return;
	} 
	while(tmp->yazarID != id){ //tmp ye aranan elemaný atamak için
		tmp = tmp->next;
		if(tmp == NULL){
			printf("Girilen numaraya sahip bir yazar bulunamadý\n");
			return;
		}
	}
	if(tmp == *head){ //ilk eleman silinecekse
		*head = (*head)->next;
		free(tmp);
	} else{
		while(prev->next != tmp){ //prevde silinecek elemandan bir önceki eleman var
			prev = prev->next;
		}
		prev->next = tmp->next;//silinecek elemanýn next i bir öncekinin next ine atandý
		free(tmp);
	}
	
	yzrUpdateFile(head); //güncellemeyi dosyaya kaydetmek için
}

void updateWriter(Yazar **head){
	int id;
	Yazar *tmp;
	tmp = *head;
	if(*head == NULL){ //head boþsa
		printf("Verilen adreste eleman yok\n");
		return;
	}
	printf("Güncellemek istediðiniz yazarýn numarasýný giriniz: "); scanf("%d",&id);
	while(tmp->yazarID != id){ //tmp de aranan yazar var
		tmp = tmp->next;
		if(tmp == NULL){
			printf("Girilen numaraya sahip bir yazar bulunamadý\n");
			return;
		}
	}
	printf("Yazarýn güncel adýný giriniz: "); scanf(" %[^\n]",tmp->yazarAd);
	printf("Yazarýn güncel soyadýný giriniz: "); scanf(" %[^\n]",tmp->yazarSoyad);
		
	yzrUpdateFile(head); //güncellemeyi dosyaya kaydetmek için
}

void yzrUpdateFile(Yazar **head){
	// yazarlar.csv dosyasýndaki yazar bilgisini güncellemek için;
	FILE *fp = fopen("yazarlar.csv", "w");
	Yazar *yazar = *head;
	while (yazar != NULL){
	    fprintf(fp, "%d,%s,%s\n", yazar->yazarID, yazar->yazarAd, yazar->yazarSoyad);
	    yazar = yazar->next;
	}
	fclose(fp);
}

void printWriter(Yazar* head, char yazarAd[]){//alýnan yazar adý bilgisine göre yazarýn bilgileri print edildi
	Yazar *tmp = head;
	strlwr(yazarAd); //Büyük küçük harf durumuna dikkat etmek için
	strlwr(tmp->yazarAd);
	while(tmp != NULL && strcmp(tmp->yazarAd,yazarAd) != 0){
		tmp = tmp->next;
		strlwr(tmp->yazarAd);
	}
	if(tmp != NULL)
		printf("\n%s %s %d\n\n",tmp->yazarAd,tmp->yazarSoyad,tmp->yazarID);
	else
		printf("Girilen isimde bir yazar yok...\n");
	return;		
}

void printAllWriters(Yazar* head){
	Yazar *tmp = head;
	while(tmp != NULL){
		printf("\n%s %s %d\n\n",tmp->yazarAd,tmp->yazarSoyad,tmp->yazarID);
		tmp = tmp->next;
	}
}

void reverseStudents(Ogrenci **head){ //dosyayý tersten okuduðum için okuduktan sonra tersini alarak normal hale getirdim
    Ogrenci *prev = NULL;
    Ogrenci *cur = *head;
    Ogrenci *next;
    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *head = prev;
}

void readStudentsFile(Ogrenci **head){
	FILE *fp = fopen("ogrenciler.csv","r");
	if(fp == NULL){
		printf("Dosya açýlamadý...\n");
		return;
	}
	char ogrID[9];
	char ad[30];
	char soyad[30];
	char inputs[100];
	int puan;
	Ogrenci *ogrenci;
	while(fgets(inputs,sizeof(inputs),fp) != NULL){
		ogrenci = (Ogrenci*) malloc(sizeof(Ogrenci));
		sscanf(inputs, "%[^,],%[^,],%[^,],%d\n",ogrID,ad,soyad,&puan); //satýr yerel deðiþkenlere koyuldu
		strcpy(ogrenci->ogrID,ogrID);
		strcpy(ogrenci->ad,ad);
		strcpy(ogrenci->soyad,soyad);
		ogrenci->puan = puan;//baþtan ekleme
		ogrenci->next = *head;
		*head = ogrenci;
	}
	fclose(fp);
}

void addStudent(Ogrenci **head){
	Ogrenci *ogr,*tmp;
	ogr = (Ogrenci*) malloc(sizeof(Ogrenci));
	ogr->next = NULL;
	if(ogr == NULL){
		printf("Yer ayrýlamadý...\n");
		return;
	}
	char ogrID[8];
	char ad[30];
	char soyad[30];
	printf("Öðrencinin adýný giriniz: "); scanf(" %[^\n]",ogr->ad);
	printf("Öðrencinin soyadýný giriniz: "); scanf(" %[^\n]",ogr->soyad);
	printf("Öðrencinin numarasýný giriniz: "); scanf(" %[^\n]",ogr->ogrID);
	ogr->puan = 100;
	if(*head == NULL){ //head boþsa sondan eklemek veya baþtan eklemek ayný þey olur
		*head = ogr;
	} else{ //sondan eklemek için
		tmp = *head;
		while(tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = ogr;
	}
	
	// ogrenciler.csv dosyasýna öðrenciler eklenir
	FILE *fp = fopen("ogrenciler.csv", "a");
	fprintf(fp, "%s,%s,%s,%d\n", ogr->ogrID, ogr->ad, ogr->soyad, ogr->puan);
	fclose(fp);
	
}

void deleteStudent(Ogrenci **head){
	Ogrenci *tmp, *prev;
	char ogrID[9];
	printf("Silmek istediðiniz öðrencinin numarasýný giriniz: "); scanf("%s",ogrID);
	tmp = *head;
	prev = *head;
	if(*head == NULL){
		printf("Silinecek bir öðrenci yok...\n");
		return;
	} 
	while(strcmp(tmp->ogrID,ogrID) != 0){ //silinecek öðrenci tmp de oluþacak
		tmp = tmp->next;
		if(tmp == NULL){
			printf("Girilen numaraya sahip bir öðrenci bulunamadý\n");
			return;
		}
	}
	if(tmp == *head){ //silinecek eleman listenin ilk elemanýysa
		*head = (*head)->next;
		free(tmp);
	} else{
		while(prev->next != tmp){ //prev silinecek elemandan önceki elemaný tutacak
			prev = prev->next;
		}
		prev->next = tmp->next; //silinecek elemanýn next i öncesinin next ine atandý
		free(tmp);
	}
	ogrUpdateFile(head); //dosya güncellendi
}

void updateStudent(Ogrenci **head){
	char ogrID[9];
	Ogrenci *tmp;
	tmp = *head;
	if(*head == NULL){
		printf("Verilen adreste eleman yok\n");
		return;
	}
	printf("Güncellemek istediðiniz öðrencinin numarasýný giriniz: "); scanf("%s",ogrID);
	while(strcmp(tmp->ogrID,ogrID) != 0){
		tmp = tmp->next;
		if(tmp == NULL){
			printf("Girilen numaraya sahip bir öðrenci bulunamadý\n");
			return;
		}
	}
	printf("Öðrencinin güncel adýný giriniz: "); scanf(" %[^\n]",tmp->ad);
	printf("Öðrencinin güncel soyadýný giriniz: "); scanf(" %[^\n]",tmp->soyad);
	printf("Öðrencinin güncel numarasýný giriniz: "); scanf(" %[^\n]",tmp->ogrID);
	if(tmp == *head){//ilk eleman güncellenecekse
		ogrUpdateFile(head);
		return;
	}
	ogrUpdateFile(head);
}

void ogrUpdateFile(Ogrenci **head){
	// Ogrenciler.csv dosyasýndaki öðrenci bilgisini güncellemek için;
	FILE *fp = fopen("Ogrenciler.csv", "w");
	Ogrenci *ogr2 = *head;
	while (ogr2 != NULL){
	    fprintf(fp, "%s,%s,%s,%d\n", ogr2->ogrID, ogr2->ad, ogr2->soyad, ogr2->puan);
	    ogr2 = ogr2->next;
	}
	fclose(fp);	
}

void printStudent(Ogrenci* head, char ogrID[]){ //id ye göre öðrenci yazdýrdým
	Ogrenci *tmp = head;
	while(tmp != NULL && strcmp(tmp->ogrID, ogrID) != 0){
		tmp = tmp->next;
	}
	if(tmp != NULL)
		printf("\n%s %s %s puan:%d \n\n",tmp->ad,tmp->soyad,tmp->ogrID,tmp->puan);
	else
		printf("Girilen numarada bir öðrenci yok...\n");
	return;		
}

void printAllStudents(Ogrenci* head){
	Ogrenci *tmp = head;
	while(tmp != NULL){
		printf("\n%s %s %s puan:%d \n\n",tmp->ad,tmp->soyad,tmp->ogrID,tmp->puan);
		tmp = tmp->next;
	}
}
