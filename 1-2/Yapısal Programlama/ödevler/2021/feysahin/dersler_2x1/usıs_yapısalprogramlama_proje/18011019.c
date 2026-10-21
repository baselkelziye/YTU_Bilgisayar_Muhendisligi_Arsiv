#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<time.h>

typedef struct students{
	char stdID[10], stdName[15], stdSurname[15];
	int numOfLectures, numOfCredits; //numOfLectures: öðrencinin aldýðý ders sayýsý, numOfCredits: öðrencinin aldýðý kredi sayýsý
}STD;

typedef struct lectures{
	char lecCode[10], lecName[20], tchID[10];
	int credit, quota; //quota: kontenjan
}LEC;

typedef struct teachers{
	char tchID[10], tchName[10], tchSurname[10], position[10]; //position:unvan
}TCH;

void lectureUpdate(char *, char *, char *);
void teacherUpdate(char *, char *, char *);
void studentUpdate(char *, char *);
void stdLecRecord(int, int, int, int *, char *, char *, char *);
void stdLecDelete(char *, char *, char *);
void lecByTchID_list(char *, char *);
void stdByCode_list(char *, char *);
void lecByStdID_list(char *, char *);
void printClassroom(char *, char *, char *);

int mevcut(char *, char *, char *, char *);
void deleteMember(char *, char *, char *);
int countLine(char *);

void deleteLecture(char *, char *, char *);

int main(){
	setlocale(LC_ALL,"Turkish");
	
	int choice=-1, maxDers=9, maxKredi=25, maxKota=20, count=1;
	char fstdname[10], flecname[10], ftchname[10], date[12];
	//ÖðrenciDersKayýt dosyasýnda kalýnan yeri bulmalýyýz (sýralamadaki numaralandýrma için)
	count = countLine("OgrenciDersKayit.txt");
	
	printf("\n\t--- Ders Kayýt Programýna Hoþgeldiniz ---\n\n\n");
	printf("Öncelikle bir öðrencinin alabileceði maksimum ders ve kredi sayýsýný giriniz:\n Maksimum ders sayýsý:");
	scanf("%d", &maxDers);
	printf("\n Maksimum kredi sayýsý: ");
	scanf("%d", &maxKredi);
	printf("\n Bir dersin maksimum kontenjanýný giriniz: ");
	scanf("%d", &maxKota);
	
	// TARÝH (OgrenciDersKayit.txt dosyasýna eklenecek)
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	sprintf(date, "%02d.%02d.%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
	
	printf("\nÖðrenci dosyasý adý: ");
	scanf("%s", fstdname);
	//strcpy(fstdname,"std.txt");
	printf("\nAçýlan dersler dosyasý: ");
	scanf("%s", flecname);
	//strcpy(flecname,"lectures.txt");
	printf("\nÖðretim üyesi dosya adý: ");
	scanf("%s", ftchname);
	//strcpy(ftchname,"teachers.txt");
		
	while(choice!=0){
		printf("\n\n\n----------------------MENU-----------------------------\n\n");
		printf(" 1- Yeni ders ekle / sil\n"); 			  			// lectureUpdate()
		printf(" 2- Yeni öðretim üyesi kaydý ekle / sil\n");   		// teacherUpdate()
		printf(" 3- Yeni öðrenci kaydý ekle / sil\n"); 		  		// studentUpdate()
		printf(" 4- Öðrenci ders kaydý ekle\n");				    // stdLecRecord()
		printf(" 5- Öðrenci ders kaydý sil\n");						// stdLecDelete()
		printf(" 6- ID'si verilen öðretim üyesinin verdigi dersleri listele\n");   //lecByTchID_list()
		printf(" 7- Kodu verilen dersi alan öðrencileri listele\n");			   //stdByCode_list()
		printf(" 8- Numarasý verilen bir öðrencinin aldýðý dersleri listele\n");   //lecByStdID_list()
		printf(" 9- ID'si verilen bir öðretim üyesinin verdiði bir dersi alan öðrencilerin sýnýf listesini dosyaya yazdýr\n"); // printClassroom()
		printf(" 0 -ÇIKIÞ\n\n Yapmak istediðiniz iþlemin numarasýný giriniz: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1: lectureUpdate(flecname, ftchname, fstdname); break;	
			case 2: teacherUpdate(ftchname, flecname, fstdname); break;		
			case 3: studentUpdate(fstdname, flecname); break;
			case 4: stdLecRecord(maxDers, maxKredi, maxKota, &count, fstdname, flecname, date); break;
			case 5: stdLecDelete(fstdname, flecname, date); break;
			case 6: lecByTchID_list(flecname, ftchname); break;
			case 7: stdByCode_list(fstdname, flecname); break;
			case 8: lecByStdID_list(fstdname, flecname); break;
			case 9: printClassroom(ftchname, flecname, fstdname); break;
		}		
	}
	printf("\n\t\t --- PROGRAM BAÞARILI BÝR ÞEKÝLDE KAPANDI ---\n");
	return 1;
}

void lectureUpdate(char *flecname, char *ftchname, char *fstdname)
{
	FILE *flec, *ftch, *fstd, *frec;
	char recNO[5], recstdID[10], tire[5], reclecNO[10], pass[10]; //öðrenci-ders kayýt durumlarý için	
	char strLec[10], strCred[10], lecID[10]; // itoa fonksiyonu için (silme kýsmýnda lazým olacak)
	int choice;
	
	printf("\nAçýlan dersler listesinde yapmak istediðiniz iþlemi seçiniz:\n\n");
	printf("1-Ders ekle\n2-Ders sil\t");
	scanf("%d", &choice);
	
	//DERS EKLE
	if(choice == 1)
	{				
	    LEC ders;		
		printf("\nEklemek istediðiniz dersin bilgilerini giriniz:\n\n");
		printf("Ders kodu: "); scanf("%s", ders.lecCode);
		
		//DOSYADA ARAMA ÝÞLEMÝ - ÖNCE, DERS ZATEN MEVCUT MU DÝYE KONTROL EDÝYORUZ		
		if(mevcut(flecname, ders.lecCode, "Bu ders zaten açýlmýþ.", "Ders henüz açýlmamýþ. Açmak için gereken bilgileri girmeye devam ediniz:\n"))
		{
			printf("\n\nMenüye dönmek için herhangi bir tuþa basýnýz: ");
			getch();
			return;  //dersin önceden var olma durumunda veya dosyanýn açýlamamasý durumunda fonksiyon burada bitmeli
		}
		//ÖÐRETÝM ÜYESÝ KAYDI VAR MI KONTROLÜ
		printf("Derse atanacak öðretim üyesi ID no: "); scanf("%s", ders.tchID);
		if(mevcut(ftchname, ders.tchID, "Öðretim üyesi kayýtlý. Lütfen aþaðýdaki bilgileri de giriniz:\n", "Öðretim üyesi kayýtlý deðil. Önce öðretim üyesi kaydý yapýlmalý.\n") != 1)
		{
			printf("\n\nMenüye dönmek için herhangi bir tuþa basýnýz: ");
			getch();
			return;
    	}
				
		flec = fopen(flecname, "a+");
		if(flec) 
		{	
			printf("Ders adý: "); scanf("%s", ders.lecName);				
			
			printf("Kredisi: "); scanf("%d", &ders.credit);
			
			ders.quota = 0;
						
			fprintf(flec, "\n%s %s %d %d %s", ders.lecCode, ders.lecName, ders.credit, ders.quota, ders.tchID);
			fclose(flec);
			printf("\n		Ders baþarýlý bir þekilde açýldý.\n");
        }
		else printf("\nDosya bulunamadý.\n");
		
	}	
	//DERS SÝL
	else if(choice == 2)
	{	
		printf("\nÇýkarýlacak dersin kodu: ");
		scanf("%s", lecID);
		deleteLecture(flecname, fstdname, lecID);
	}
	printf("\n\nMenüye dönmek için herhangi bir tuþa basýnýz: ");
	getch();
}

void studentUpdate(char *fstdname, char *flecname)
{
	FILE *fstd, *frec, *flec;
	int choice;
	
	printf("\nÝþlem seçiniz:\n");
	printf("\n1-Öðrenci ekle\n2-Ögrenci sil\t");
	scanf("%d", &choice);
	
	//ÖÐRENCÝ EKLE
	if(choice==1)
	{
		STD student;		
		printf("\nEklemek istediðiniz ögrenci bilgileri:\n\n");
		printf("ID: "); scanf("%s", student.stdID);
					
		//DOSYADA ARAMA ÝÞLEMÝ - ÖÐRENCÝ ZATEN KAYITLI MI DÝYE KONTROL EDÝYORUZ
		if(mevcut(fstdname, student.stdID, "Öðrenci zaten kayýtlý.", "Öðrenci kaydý yapýlýyor... Lütfen diðer bilgileri de giriniz: ")) return;  //öðrencinin önceden kayýtlý olma durumunda veya dosyanýn açýlamamasý durumunda fonksiyon burada bitmeli
		
		fstd = fopen(fstdname, "a+");		
		if(fstd)
		{			
			printf("Ad: ");	scanf("%s", student.stdName);
			
			printf("Soyad: "); scanf("%s", student.stdSurname);
			
			student.numOfLectures = 0;	//yeni kaydolan hiçbir öðrenci henüz bir ders almamýþtýr
			student.numOfCredits = 0;
			
			fprintf(fstd, "\n%s %s %s %d %d", student.stdID, student.stdName, student.stdSurname, student.numOfLectures, student.numOfCredits);
			fclose(fstd);
			printf("\n		Öðrenci, baþarýlý bir þekilde kaydedildi.\n\nMenüye dönmek için herhangi bir tuþa basýnýz: ");
			getch();
		}
		else printf("Dosya bulunamadý.\n");
	}
	//ÖÐRENCÝ SÝL
	else if(choice == 2)
	{	
		LEC lecture;
		char oID[10], strLecCred[10], strKota[10], ch;	
		char *bufferLEC, *bufLineLEC, *ptrLEC, *lineLEC;
		char *bufferREC, *ptrREC, *line;
		char recNO[5], recstdID[10], tire[5], reclecNO[10], pass[15]; //öðrenci-ders kayýt durumlarý için
		int c = 1; //satýr sayacý (düzgün yazdýrabilmek için)	
		
		//ÖÐRENCÝLERÝ LÝSTELEME
		fstd = fopen(fstdname, "r");
		if(!fstd)
		{
			printf("\nDosya bulunamadý:\n");
			return;
		}
		ch=fgetc(fstd); 
		printf("\n ÖÐRENCÝLER: \n"); 
		while(ch!=EOF){ 
	        printf("%c",ch); 
		    ch=fgetc(fstd); 
	    }
		fclose(fstd);
		
		printf("\n\nKaydý silinecek öðrenci ID no: ");
		scanf("%s", oID);
		
		//DOSYADA ARAMA ÝÞLEMÝ - 'YOKSA ZATEN SÝLÝNEMEZ' DURUMU ÝÇÝN
		if(mevcut(fstdname, oID, "Öðrenci kaydý siliniyor...", "Bu öðrenci zaten kayýtlý deðil.") != 1) return; //öðrencinin önceden var olmama durumunda veya dosyanýn açýlamamasý durumunda fonksiyon burada bitmeli
		
		//ALDIÐI DERS VARSA O DERSÝN KONTENJANI 1 AZALMALI
		frec = fopen("OgrenciDersKayit.txt", "r");
		if(!frec)
		{
			printf("\nDosya bulunamadý:\n");
			return;
		}
		
		//ODK dosyasýný güncellemek için	
		bufferREC = (char*)malloc(sizeof(char)*2000);
		memset(bufferREC, 0, 2000*sizeof(char));
		ptrREC = bufferREC;
		
		//LECTURE dosyasýný güncellemek için
		bufferLEC = (char*)malloc(sizeof(char)*2000);
		bufLineLEC = (char*)malloc(sizeof(char)*100);
		
		lineLEC = (char*)malloc(sizeof(char)*100);
		line = (char*)malloc(sizeof(char)*100);
		
		while(!feof(frec))
		{
			fgets(line, 100, frec);
			if(strstr(line, oID))
			{
				printf("%s", line);
				sscanf(line, "%s %s %s %s %s", recNO, recstdID, tire, reclecNO, pass);	//ODK'da öðrenci kaydý bulundu
				
				if(!strcmp(pass, "KAYITLI"))
				{
					memset(bufferLEC, 0, 2000*sizeof(char));
					ptrLEC = bufferLEC;
					flec = fopen(flecname, "r");
					
					if(!flec)
					{
						printf("\nDosya bulunamadý:\n");
						free(bufferREC);
						free(bufferLEC);
						free(bufLineLEC);
						free(lineLEC);
						free(line);
						return;
					}
					while(!feof(flec))
					{
						fgets(lineLEC, 100, flec);
						if(strstr(lineLEC, reclecNO))
						{
							printf("%s", lineLEC);
							sscanf(lineLEC, "%s %s %d %d %s", lecture.lecCode, lecture.lecName, &lecture.credit, &lecture.quota, lecture.tchID);
							
							lecture.quota--;
							
							memset(bufLineLEC, 0, 100);
							
							itoa(lecture.credit, strLecCred, 10);
							itoa(lecture.quota, strKota, 10);
							
							strcat(bufLineLEC, lecture.lecCode);
							strcat(bufLineLEC, " ");
							strcat(bufLineLEC, lecture.lecName);
							strcat(bufLineLEC, " ");
							strcat(bufLineLEC, strLecCred);
							strcat(bufLineLEC, " ");
							strcat(bufLineLEC, strKota);
							strcat(bufLineLEC, " ");
							strcat(bufLineLEC, lecture.tchID);
							if(c < countLine(flecname)) strcat(bufLineLEC, "\n");			
										
							strcpy(ptrLEC, bufLineLEC);
							ptrLEC += strlen(bufLineLEC);
						}
						else
						{
							strcpy(ptrLEC, lineLEC);
							ptrLEC += strlen(lineLEC);
						}
						c++;
					}
					fclose(flec);
					flec = fopen(flecname, "w");
					fprintf(flec, "%s", bufferLEC);
					fclose(flec);
					c = 1;  //dosyayý baþtan sona tekrar tarayacaðýmýz için c'yi 1'liyoruz
				}			
			}
			else
			{
				strcpy(ptrREC, line);
				ptrREC += strlen(line);
			}
		}
		fclose(frec);
		frec = fopen("OgrenciDersKayit.txt", "w");
		fprintf(frec, "%s", bufferREC);
		fclose(frec);
		
		free(bufferREC);
		free(bufferLEC);
		free(bufLineLEC);
		free(lineLEC);
		free(line);
		
		deleteMember(fstdname, oID, "\n		Öðrenci kaydý baþarýlý bir þekilde silindi.\n");
	}
}

void teacherUpdate(char *ftchname, char *flecname, char *fstdname)
{
	FILE *ftch, *flec;
	int choice, var;
	char *line;
	line = (char*)malloc(sizeof(char)*100);
	
	printf("1-Öðr. üyesi ekle\n2-Öðr. üyesi sil\t");
	scanf("%d", &choice);
	
	TCH teacher;	
	//ÖÐR. ÜYESÝ EKLE
	if(choice==1)
	{	
		printf("Eklemek istediðiniz öðretim üyesi bilgileri:\n");
		printf("ID: ");
		scanf("%s", teacher.tchID);
	
		//DOSYADA ARAMA ÝÞLEMÝ
		if(mevcut(ftchname, teacher.tchID, "Öðretim üyesi zaten kayýtlý.", "Öðretim üyesi kaydý yapýlýyor...")) return;  //öðretim üyesinin önceden kayýtlý olma durumunda veya dosyanýn açýlamamasý durumunda fonksiyon burada bitmeli
		
		ftch = fopen(ftchname, "a+");
		if(ftch)
		{	
			printf("Ad: "); scanf("%s", teacher.tchName);
			
			printf("Soyad: "); scanf("%s", teacher.tchSurname);
			
			printf("Unvan: "); scanf("%s", teacher.position);
			
			fprintf(ftch, "\n%s %s %s %s", teacher.tchID, teacher.tchName, teacher.tchSurname, teacher.position);
			fclose(ftch);
			printf("\n		Öðretim üyesi, baþarýlý bir þekilde kaydedildi.\n\nMenüye dönmek için herhangi bir tuþa basýnýz: ");
			getch();
		}
		else printf("Dosya bulunamadý.\n");
	}	
	//ÖÐR. ÜYESÝ SÝL
	else if(choice == 2)
	{
		LEC lecture;
		char ouID[10], lecID[10];		
		printf("Kaydý silinecek öðretim üyesi ID no: ");
		scanf("%s", ouID);
		
		//DOSYADA ARAMA ÝÞLEMÝ
		if(mevcut(ftchname, ouID, "Öðr. üyesi kaydý siliniyor...", "Öðr. üyesi zaten kayýtlý deðil.") != 1) return; //öðr. üyesinin önceden var olmama durumunda veya dosyanýn açýlamamasý durumunda fonksiyon burada bitmeli
		
		//öðretim üyesinin verdiði dersi buldur
		flec = fopen(flecname, "r");
		if(!flec)
		{
			printf("\nDosya bulunamadý.\n");
			return;
		}
		while(!feof(flec))
		{
			fgets(line, 100, flec);
			if(strstr(line, ouID))
			{
				sscanf(line, "%s %s %d %d %s", lecture.lecCode, lecture.lecName, &lecture.credit, &lecture.quota, lecture.tchID);
				printf("\nlecID: %s", lecture.lecCode);
				
				deleteLecture(flecname, fstdname, lecture.lecCode);
			}
		}
		fclose(flec);
		
		deleteMember(ftchname, ouID, "\n		Öðretim üyesi kaydý baþarýlý bir þekilde silindi.\n\nMenüye dönmek için herhangi bir tuþa basýnýz: ");	
		getch();
	}
	free(line);
}

void stdLecRecord(int maxDers, int maxKredi, int maxKota, int *pcount, char *fstdname, char *flecname, char *date)
{
	FILE *fstd, *flec, *frec;
	char stdIDRec[10], lecCodeRec[10], *line, ch, *buffer, *ptr;
	char recNO[5], recstdID[10], tire[5], reclecNO[10], pass[15]; //öðrenci-ders kayýt durumlarý için
	char *bufLine, strLec[10], strCred[10], strKota[10], strLecCred[10];   //*bufLine ile öðrenci structýný tek bir satýrda oluþturacaðýz
	int found = 0, c = 1; //sadece doðru yazým için satýr sayýsýný kontrol amaçlý
	
	STD student;
	
	fstd = fopen(fstdname, "r");
	if(!fstd){
		printf("Dosya bulunamadý.");
		return;
	}
	printf("\nDers kaydý yapacak öðrencinin ID'sini giriniz: ");
	scanf("%s", stdIDRec);	
	
	//DOSYADA ARAMA ÝÞLEMÝ - 'YOKSA KAYDI YAPILAMAZ' DURUMU ÝÇÝN
	if(mevcut(fstdname, stdIDRec, " ", "Öðrenci kaydý bulunamadý.\n\nMenüye dönmek için herhangi bir tuþa basýnýz... ") != 1) 
	{
		getch();
		return;
	}
	
	line = (char*)malloc(sizeof(char)*100);
	while(!feof(fstd))
	{
		fgets(line, 100, fstd);
		if(strstr(line, stdIDRec) != NULL)
		{
			sscanf(line, "%s %s %s %d %d", student.stdID, student.stdName, student.stdSurname, &student.numOfLectures, &student.numOfCredits);
			printf("\n\nÖðrenci bilgileri:\n ID: %s\n Ad: %s\n Soyad: %s\n Mevcut ders sayýsý: %d\n Mevcut kredi sayýsý: %d\n", student.stdID, student.stdName, student.stdSurname, student.numOfLectures, student.numOfCredits);
		}
	}
	fclose(fstd);
	
	//öðrencinin ders sayýsýný aþýp aþmadýðýný kontrol ediyoruz
	if(student.numOfLectures == maxDers){
		printf("\nÖðrenci ders sayýsýný aþmakta, daha fazla ders alamaz.\n");
		free(line);
		return;
	}
	
	flec = fopen(flecname, "r");
	if(!flec){
		printf("Dosya bulunamadý.");
		free(line);
		return;
	}
			
	LEC lecture;
	
	flec = fopen(flecname, "r");
	if(!flec){
		printf("Dosya bulunamadý.\n");
		free(line);
        return;
	}	
	//mevcut dersleri ekrana yazdýrma
	ch=fgetc(flec); 
	printf("\n AÇILAN DERSLER: \n"); 
	while(ch!=EOF){ 
        printf("%c",ch); 
	    ch=fgetc(flec); 
    }
    rewind(flec);
	printf("\n\nÖðrencinin kaydolmak istediði dersin kodunu giriniz: ");
	scanf("%s", lecCodeRec);
	
	//OgrenciDersKayit.txt dosyasýnda KAYITLI kontrolü
	frec = fopen("OgrenciDersKayit.txt", "r");
	if(!frec)
	{
		printf("\nDosya bulunamadý. Tekrar deneyiniz.\n");
		return;
	}
	while(!feof(frec))
	{
		fgets(line, 100, frec);
		if(strstr(line, stdIDRec) != NULL && strstr(line, lecCodeRec) != NULL)
		{
			sscanf(line, "%s %s %s %s %s", recNO, recstdID, tire, reclecNO, pass, date);
			printf("\n\nöðrenci ID - Ders kodu -> ÖNCEKÝ DURUMU:  %s %s %s %s %s", recNO, recstdID, tire, reclecNO, pass, date);
			found = 1;
		}
	}
	fclose(frec);
	
	if(found == 1)
	{
		if(!strcmp(pass, "KAYITLI"))
		{
			printf("\n\n%s numaralý öðrenci %s kodlu derse zaten kayýtlý.\n", stdIDRec, lecCodeRec);
			return;
		}
		else if(!strcmp(pass, "BIRAKTI"))
		{
			printf("\n%s numaralý öðrenci %s kodlu dersi daha önceden alýp býrakmýþ.\n", stdIDRec, lecCodeRec);
			deleteMember("OgrenciDersKayit.txt", recNO, " ");
			(*pcount)--;
		}
	}
	
	while(!feof(flec))
	{
		fgets(line, 100, flec);
		if(strstr(line, lecCodeRec) != NULL)
		{
			sscanf(line, "%s %s %d %d %s", lecture.lecCode, lecture.lecName, &lecture.credit, &lecture.quota, lecture.tchID);
			printf("\n\nDers bilgileri:\n Ders kodu: %s\n Dersin adý: %s\n Kredi: %d\n Mevcut kontenjan: %d\n Dersi veren öðretim üyesi ID no: %s\n", lecture.lecCode, lecture.lecName, lecture.credit, lecture.quota, lecture.tchID);
		}
	}
	fclose(flec);
	
	//KONTROLLER
	if(lecture.quota == maxKota){
		printf("\nDers kontenjaný dolu.\n");
		return;
	}
	if(student.numOfCredits + lecture.credit > maxKredi){
		printf("\nÖðrenci kredisini aþmakta, daha az kredili bir derse kaydolabilir.\n\nMenüye dönmek için herhangi bir tuþa basýnýz... ");
		getch();		
		return;
	}
	student.numOfLectures++; //öðrencinin aldýðý ders sayýsý arttý
	student.numOfCredits += lecture.credit; //öðrencinin aldýðý kredi sayýsý arttý
	lecture.quota++; //dersin kontenjaný arttý
	
	fstd = fopen(fstdname, "r");
	
	buffer = (char*)malloc(sizeof(char)*2000);
	memset(buffer, 0, 2000*sizeof(char));
	ptr = buffer;
	
	bufLine = (char*)malloc(sizeof(char)*100);
	memset(bufLine, 0, 100);
	
	//ÖÐRENCÝ DOSYASINI YENÝLE
	while(!feof(fstd))
	{
		fgets(line, 100, fstd);
		if(strstr(line, stdIDRec) == NULL)
		{
			strcpy(ptr, line);
			ptr += strlen(line);
		}
		else
		{			
			itoa(student.numOfLectures, strLec, 10);
			itoa(student.numOfCredits, strCred, 10);
			
			strcat(bufLine, student.stdID);
			strcat(bufLine, " ");
			strcat(bufLine, student.stdName);
			strcat(bufLine, " ");
			strcat(bufLine, student.stdSurname);
			strcat(bufLine, " ");
			strcat(bufLine, strLec);
			strcat(bufLine, " ");
			strcat(bufLine, strCred);
			if(c < countLine(fstdname)) strcat(bufLine, "\n");
						
			strcpy(ptr, bufLine);
			ptr += strlen(bufLine);
		}
		c++;
	}
	fclose(fstd);
	fstd = fopen(fstdname, "w");
	fprintf(fstd, "%s", buffer);
	fclose(fstd);
	
	//ders dosyasýný yenile	
	memset(buffer, 0, 2000*sizeof(char));
	ptr = buffer;
	memset(bufLine, 0, 100);
	
	c=1;
	flec = fopen(flecname, "r");	
	while(!feof(flec))
	{
		fgets(line, 100, flec);
		if(strstr(line, lecCodeRec) == NULL)
		{
			strcpy(ptr, line);
			ptr += strlen(line);
		}
		else
		{			
			itoa(lecture.credit, strLecCred, 10);
			itoa(lecture.quota, strKota, 10);
			
			strcat(bufLine, lecture.lecCode);
			strcat(bufLine, " ");
			strcat(bufLine, lecture.lecName);
			strcat(bufLine, " ");
			strcat(bufLine, strLecCred);
			strcat(bufLine, " ");
			strcat(bufLine, strKota);
			strcat(bufLine, " ");
			strcat(bufLine, lecture.tchID);
			if(c < countLine(flecname)) strcat(bufLine, "\n");			
						
			strcpy(ptr, bufLine);
			ptr += strlen(bufLine);
		}
		c++;
	}
	fclose(flec);
	flec = fopen(flecname, "w");
	fprintf(flec, "%s", buffer);
	fclose(flec);
	
	//öðrenciNO-DersKodu dosyasýna yazdýrma
	(*pcount)++;
	frec = fopen("OgrenciDersKayit.txt", "a");
	if(!frec){
		printf("Dosya bulunamadý.");
		free(buffer);
		free(bufLine);
		free(line);
		return;
	}
	fprintf(frec, "\n%d-) %s - %s KAYITLI %s", *pcount, student.stdID, lecture.lecCode, date);
	fclose(frec);	
	printf("\n		Öðrenci ders kaydý baþarýlý bir þekilde yapýldý.\n\nMenüye dönmek için herhangi bir tuþa basýnýz... ");
	getch();
	
	free(buffer);
	free(bufLine);
	free(line);
}

void stdLecDelete(char *fstdname, char *flecname, char *date)
{
	FILE *fstd, *flec, *frec;
	char stdIDRec[10], lecCodeRec[10], *line, ch, *buffer, *ptr, *bufLine;
	char strLec[10], strCred[10], strLecCred[10], strKota[10];    //integer deðerleri stringe çevirmek için
	char recNO[5], recstdID[10], tire[5], reclecNO[10], pass[10]; //öðrenci-ders kayýt durumlarý için
	int found = 0, c = 1;
	
	STD student;
	LEC lecture;
	
	fstd = fopen(fstdname, "r");
	if(!fstd){
		printf("Dosya bulunamadý.");
		return;
	}
	printf("\nDers kaydý silinecek öðrencinin ID'sini giriniz: ");
	scanf("%s", stdIDRec);	
	
	if(mevcut(fstdname, stdIDRec, " ", "Öðrenci kaydý bulunamadý.") != 1)
	{
		printf("\n\nMenüye dönmek için herhangi bir tuþa basýnýz... ");
		getch();
		return;	
	}
	line = (char*)malloc(sizeof(char)*100);
	while(!feof(fstd))
	{
		fgets(line, 100, fstd);
		if(strstr(line, stdIDRec) != NULL)
		{
			printf("%s", line);
			sscanf(line, "%s %s %s %d %d", student.stdID, student.stdName, student.stdSurname, &student.numOfLectures, &student.numOfCredits);
			printf("\n\nÖðrenci bilgileri:\n ID: %s\n Ad: %s\n Soyad: %s\n Mevcut ders sayýsý: %d\n Mevcut kredi sayýsý: %d\n", student.stdID, student.stdName, student.stdSurname, student.numOfLectures, student.numOfCredits);
		}
	}
	fclose(fstd);
	
	flec = fopen(flecname, "r");
	if(!flec){
		printf("Dosya bulunamadý.\n");
		free(line);
        return;
	}	
	//AÇILAN DERSLERÝ EKRANA YAZDIRMA
	ch=fgetc(flec); 
	printf("\n Açýlan dersler: \n"); 
	while(ch!=EOF){ 
        printf("%c",ch); 
	    ch=fgetc(flec); 
    }
    rewind(flec);
    
	//DERS KAYIT DURUMU KONTROLÜ
	frec = fopen("OgrenciDersKayit.txt", "r");
	if(!frec){
		printf("Dosya bulunamadý.\n");
        return;
	}	
	//EKRANA YAZDIRMA
	printf("\n\n Öðrenci-Ders kayýt/býrakma durumlarý: \n"); 
	while(!feof(frec))
	{
		fgets(line, 100, frec);
		if(strstr(line, stdIDRec)) printf("\n%s", line); 
    }
    rewind(frec);
    
	printf("\n\nÖðrencinin býrakmak istediði dersin kodunu giriniz: ");
	scanf("%s", lecCodeRec);
	
	if(mevcut(flecname, lecCodeRec, " ", "Bu ders henüz açýlmamýþ.") != 1)
	{
		printf("\n\nMenüye dönmek için herhangi bir tuþa basýnýz... ");
		getch();
		free(line);
		return;	
	}	
	
	while(!feof(flec))
	{
		fgets(line, 100, flec);
		if(strstr(line, lecCodeRec) != NULL)
		{
			sscanf(line, "%s %s %d %d %s", lecture.lecCode, lecture.lecName, &lecture.credit, &lecture.quota, lecture.tchID);
			printf("\n\nDers bilgileri:\n Ders kodu: %s\n Dersin adý: %s\n Kredi: %d\n Mevcut kontenjan: %d\n Dersi veren öðretim üyesi ID no: %s\n", lecture.lecCode, lecture.lecName, lecture.credit, lecture.quota, lecture.tchID);
		}
	}
	fclose(flec);
    
    //KAYIT DURUMUNU ARAMA
    while(!feof(frec))
	{
		fgets(line, 100, frec);
		if(strstr(line, stdIDRec) != NULL && strstr(line, lecCodeRec) != NULL)
		{
			sscanf(line, "%s %s %s %s %s %s", recNO, recstdID, tire, reclecNO, pass, date);
			printf("\n\nöðrenci ID - Ders kodu -> ÖNCEKÝ DURUMU:  %s %s %s %s %s", recNO, recstdID, tire, reclecNO, pass);
			found = 1;
		}
	}
	fclose(frec);
	
	if(found == 0)
	{
		printf("\n %s numaralý öðrenci daha önce %s dersine kaydolmamýþ.", stdIDRec, lecture.lecName);
		free(line);
		return;
	}
	if(strcmp(pass, "BIRAKTI") == 0)
	{
		printf("\nÖðrenci bu dersi daha önceden býrakmýþ.\n");
		free(line);
		return;
	}		
	else strcpy(pass, "BIRAKTI");
	
	student.numOfLectures--;
	student.numOfCredits -= lecture.credit;
	lecture.quota--;
	
	//KAYDI YENÝLEME	
	buffer = (char*)malloc(sizeof(char)*2000);
	bufLine = (char*)malloc(sizeof(char)*100);
	memset(buffer, 0, 2000*sizeof(char));
	ptr = buffer;
	memset(bufLine, 0, 100);
	
	frec = fopen("OgrenciDersKayit.txt", "r");
	while(!feof(frec))
	{
		fgets(line, 100, frec);
		if(strstr(line, stdIDRec) == NULL || strstr(line, lecCodeRec) == NULL)
		{	
			strcpy(ptr, line);
			ptr += strlen(line);					
		}
		else // ID-CODE ikilisi bu satýrdadýr demektir
		{
			strcat(bufLine, recNO);
			strcat(bufLine, " ");
			strcat(bufLine, recstdID);
			strcat(bufLine, " ");
			strcat(bufLine, tire);
			strcat(bufLine, " ");
			strcat(bufLine, reclecNO);
			strcat(bufLine, " ");
			strcat(bufLine, pass);
			strcat(bufLine, " ");
			strcat(bufLine, date);
			if(c < countLine("OgrenciDersKayit.txt")) strcat(bufLine, "\n");			
						
			strcpy(ptr, bufLine);
			ptr += strlen(bufLine);			
		}
		c++;
	}
	fclose(frec);
	frec = fopen("OgrenciDersKayit.txt", "w");
	fprintf(frec, "%s", buffer);
	fclose(frec);
	
	//ÖÐRENCÝ DOSYASINI YENÝLE	
	memset(buffer, 0, 2000*sizeof(char));
	ptr = buffer;
	memset(bufLine, 0, 100);
	c = 1;
	fstd = fopen(fstdname, "r");
	while(!feof(fstd))
	{
		fgets(line, 100, fstd);
		if(strstr(line, stdIDRec) == NULL)
		{
			strcpy(ptr, line);
			ptr += strlen(line);
		}
		else
		{			
			itoa(student.numOfLectures, strLec, 10);
			itoa(student.numOfCredits, strCred, 10);
			
			strcat(bufLine, student.stdID);
			strcat(bufLine, " ");
			strcat(bufLine, student.stdName);
			strcat(bufLine, " ");
			strcat(bufLine, student.stdSurname);
			strcat(bufLine, " ");
			strcat(bufLine, strLec);
			strcat(bufLine, " ");
			strcat(bufLine, strCred);
			if(c < countLine(fstdname)) strcat(bufLine, "\n");			
						
			strcpy(ptr, bufLine);
			ptr += strlen(bufLine);
		}
		c++;
	}
	fclose(fstd);
	fstd = fopen(fstdname, "w");
	fprintf(fstd, "%s", buffer);
	fclose(fstd);
	
	//DERS DOSYASINI YENÝLE	
	memset(buffer, 0, 2000*sizeof(char));
	ptr = buffer;
	memset(bufLine, 0, 100);
	c = 1;
	flec = fopen(flecname, "r");
	while(!feof(flec))
	{
		fgets(line, 100, flec);
		if(strstr(line, lecCodeRec) == NULL)
		{
			strcpy(ptr, line);
			ptr += strlen(line);
		}
		else
		{			
			itoa(lecture.credit, strLecCred, 10);
			itoa(lecture.quota, strKota, 10);
			
			strcat(bufLine, lecture.lecCode);
			strcat(bufLine, " ");
			strcat(bufLine, lecture.lecName);
			strcat(bufLine, " ");
			strcat(bufLine, strLecCred);
			strcat(bufLine, " ");
			strcat(bufLine, strKota);
			strcat(bufLine, " ");
			strcat(bufLine, lecture.tchID);
			if(c < countLine(flecname))strcat(bufLine, "\n");			
						
			strcpy(ptr, bufLine);
			ptr += strlen(bufLine);
		}
		c++;
	}
	fclose(flec);
	flec = fopen(flecname, "w");
	fprintf(flec, "%s", buffer);
	fclose(flec);
	
	free(buffer);
	free(bufLine);
	free(line);
	
	printf("\n		Ders kayýtlarý baþarýlý bir þekilde güncellendi.\n\nMenüye dönmek için herhangi bir tuþa basýnýz... ");
	getch();
}


void deleteLecture(char *flecname, char *fstdname, char *lecID)
{
	FILE *flec, *ftch, *fstd, *frec;
	char recNO[5], recstdID[10], tire[5], reclecNO[10], pass[10]; //öðrenci-ders kayýt durumlarý için	
	char strLec[10], strCred[10]; // itoa fonksiyonu için (silme kýsmýnda lazým olacak)
	int choice, crec = 1, cstd = 1; //crec ve cstd dosyanýn sonunda olup olmamayý kontrol eder (doðru yazým için)
	
	STD student;
	LEC lecture;
	
	char *bufferREC, *bufferSTD, *bufLineREC, *bufLineSTD, *ptrREC, *ptrSTD, *lineREC, *lineSTD;	
	
	//DOSYADA ARAMA ÝÞLEMÝ - 'YOKSA ZATEN SÝLÝNEMEZ' DURUMU ÝÇÝN
	if(mevcut(flecname, lecID, "Ders çýkarýlýyor...\n", "Bu ders zaten açýlmamýþ.") != 1) return; //dersin önceden var olmama durumunda veya dosyanýn açýlamamasý durumunda fonksiyon burada bitmeli
	
	// DÝÐER DOSYALARDAN DA SÝLME
	//dersler dosyasýndan, silinecek dersin bilgileri alýnmalýdýr
	flec = fopen(flecname, "r");
	if(!flec)
	{
		printf("\nDosya bulunamadý. Dolayýsýyla ders silme iþlemi yapýlamadý.\n");
		return;
	}
	lineREC = (char*)malloc(sizeof(char)*100);
	while(!feof(flec))
	{
		fgets(lineREC, 100, flec);
		if(strstr(lineREC, lecID) != NULL)
		{
			sscanf(lineREC, "%s %s %d %d %s", lecture.lecCode, lecture.lecName, &lecture.credit, &lecture.quota, lecture.tchID);
		}
	}
	fclose(flec);
	
	//dersi alan hiçbir öðrenci yoksa öðrenciler dosyasýnda bir deðiþikliðe gerek de yok demektir
	if(lecture.quota == 0)
	{
		printf("\nBu dersi zaten kimse almamýþ.\n");
		deleteMember(flecname, lecID, "Ders baþarýlý bir þekilde çýkarýldý.");
		free(lineREC);
		return;
	}
	
	//dersleri tutmak için
	bufferREC = (char*)malloc(sizeof(char)*2000);
	bufLineREC =(char*)malloc(sizeof(char)*100);
	memset(bufferREC, 0, 2000*sizeof(char));
	ptrREC=bufferREC;
	
	//öðrencileri tutmak için
	bufferSTD = (char*)malloc(sizeof(char)*2000);
	lineSTD = (char*)malloc(sizeof(char)*100);
	
	//OgrenciDersKayit.txt dosyasýný aç
	frec = fopen("OgrenciDersKayit.txt", "r");
	if(!frec)
	{
		printf("\nDosya açýlamadý. Dolayýsýyla ders silme iþlemi yapýlamadý.\n");
		return;
	}
	
	while(!feof(frec))
	{
		fgets(lineREC, 100, frec);
		if(strstr(lineREC, lecID) == NULL)
		{	
			strcpy(ptrREC, lineREC);
			ptrREC += strlen(lineREC);					
		}
		else // CODE bu satýrdadýr demektir
		{
			sscanf(lineREC, "%s %s %s %s %s", recNO, recstdID, tire, reclecNO, pass);
			printf("\n\nöðrenci ID - Ders kodu -> ÖNCEKÝ DURUMU:  %s %s %s %s %s", recNO, recstdID, tire, reclecNO, pass);
			
			if(!strcmp(pass, "KAYITLI")) //öðrenci kayýtlýysa öðrenciler dosyasýnda da deðiþiklikler yapýlmalýdýr
			{
				memset(bufferSTD, 0, 2000*sizeof(char));	
				ptrSTD=bufferSTD;	
				fstd = fopen(fstdname, "r");
				if(!fstd)
				{
					printf("\nDosya bulunamadý. Dolayýsýyla ders silme iþlemi yapýlamadý.\n");
					return;
				}
				cstd = 1;
				while(!feof(fstd))
				{
					fgets(lineSTD, 100, fstd);
					if(strstr(lineSTD, recstdID) == NULL)
					{
						strcpy(ptrSTD, lineSTD);
						ptrSTD += strlen(lineSTD);
					}
					else
					{   //öðrenciyi bulduk
						sscanf(lineSTD, "%s %s %s %d %d", student.stdID, student.stdName, student.stdSurname, &student.numOfLectures, &student.numOfCredits);
						printf("\n\nÖðrenci bilgileri:\n ID: %s\n Ad: %s\n Soyad: %s\n Mevcut ders sayýsý: %d\n Mevcut kredi sayýsý: %d\n", student.stdID, student.stdName, student.stdSurname, student.numOfLectures, student.numOfCredits);
						
						student.numOfLectures--;
						student.numOfCredits -= lecture.credit;
						
						itoa(student.numOfLectures, strLec, 10);
						itoa(student.numOfCredits, strCred, 10);
						
						memset(bufLineSTD, 0, 100);
						
						strcat(bufLineSTD, student.stdID);
						strcat(bufLineSTD, " ");
						strcat(bufLineSTD, student.stdName);
						strcat(bufLineSTD, " ");
						strcat(bufLineSTD, student.stdSurname);
						strcat(bufLineSTD, " ");
						strcat(bufLineSTD, strLec);
						strcat(bufLineSTD, " ");
						strcat(bufLineSTD, strCred);
						if(cstd < countLine(fstdname)) strcat(bufLineSTD, "\n");			
									
						strcpy(ptrSTD, bufLineSTD);
						ptrSTD += strlen(bufLineSTD);
					}
					cstd++;
				}
				fclose(fstd);
				fstd = fopen(fstdname, "w");
				fprintf(fstd, "%s", bufferSTD);
				fclose(fstd);
			}
			strcpy(pass, "DERS_SILINDI");
	
			memset(bufLineREC, 0, 100);
			
			strcat(bufLineREC, recNO);
			strcat(bufLineREC, " ");
			strcat(bufLineREC, recstdID);
			strcat(bufLineREC, " ");
			strcat(bufLineREC, tire);
			strcat(bufLineREC, " ");
			strcat(bufLineREC, reclecNO);
			strcat(bufLineREC, " ");
			strcat(bufLineREC, pass);
			if(crec < countLine("OgrenciDersKayit.txt")) strcat(bufLineREC, "\n");			
						
			strcpy(ptrREC, bufLineREC);
			ptrREC += strlen(bufLineREC);			
		}
		crec++;
	}
	fclose(frec);
	frec = fopen("OgrenciDersKayit.txt", "w");
	fprintf(frec, "%s", bufferREC);
	fclose(frec);
	
	free(bufferREC);
	free(bufferSTD);
	free(bufLineREC);
	free(bufLineSTD);
	free(lineSTD);
	
	deleteMember(flecname, lecID, "\n		Ders baþarýlý bir þekilde çýkarýldý.");	
}
//DOSYADA ARAMA FONKSÝYONU
int mevcut(char *fname, char *NO, char *varInfo, char *yokInfo){
	FILE *fptr;
	char *line;
	fptr = fopen(fname, "r");
	if(!fptr){
		printf("\n\t\tDosya bulunamadý.\n");
		return -1 ;
	}	
	line = (char*)malloc(sizeof(char)*100);
	while(!feof(fptr))
	{
		fgets(line, 100, fptr);
		if(strstr(line, NO) != NULL)
		{
			printf("\nBulunan bilgiler: %s", line);
			fclose(fptr);
			printf("\n		%s\n", varInfo);
			free(line);
			return 1;
		}
	}
	printf("\n		%s\n", yokInfo);
	fclose(fptr);
	free(line);
	return 0;
}
//SÝLME ve TEKRAR YAZDIRMA FONKSÝYONU
void deleteMember(char *fname, char *NO, char *info)
{
	FILE *fptr;
	char *buffer, *ptr, *line, *delp; //delp: sadece satýr sonu deðiþikliði durumunda boþluk býrakýlmamasý için
	int c = 1, found = 0; //c: satýr sayacý
	buffer = (char*)malloc(sizeof(char)*2000);
	line = (char*)malloc(sizeof(char)*100);
	memset(buffer, 0, 2000*sizeof(char));
	ptr=buffer;
	fptr = fopen(fname, "r");		
	if(fptr) 
	{
		while(!feof(fptr))
		{
			fgets(line, 100, fptr);
			if(strstr(line, NO) == NULL)
			{
				if(c != (countLine(fname) - 1) ||  found==1)
				{
					strcpy(ptr, line);
					ptr += strlen(line);
				}
				else
				{
					delp = strtok(line, "\n");
					strcpy(ptr, delp);
					ptr += strlen(delp);
				}
			}else found=1;
			c++;
		}
		fclose(fptr);
		fptr = fopen(fname, "w");
		fprintf(fptr, "%s", buffer);
		fclose(fptr);
		free(buffer);
		printf("\n		%s\n", info);
	}
	else printf("\nDosya bulunamadý.");
	free(buffer);
	free(line);
}

int countLine(char *fname)
{
	int count = 1;
	char c;
	FILE *fptr;
	fptr = fopen(fname, "r");
	if(!fptr)
	{
		printf("\nDosya açýlamadý.\n");
		return 0;
	}
	for(c = getc(fptr); c != EOF; c = getc(fptr))
	{
		if (c == '\n') count++; 
	}
	fclose(fptr);
	return count;
}

void lecByTchID_list(char *flecname, char *ftchname)
{
	FILE *flec, *ftch;
	char *line;
	char ouID[10];
	int found = 0;
	
	LEC lecture;
	TCH teacher;
	
	printf("\nVerdiði dersleri görmek istediðiniz öðretim üyesinin ID numarasýný giriniz: ");
	scanf("%s", ouID);
	
	//ÖÐR. ÜYESÝ KAYIT KONTROLÜ
	if(mevcut(ftchname, ouID, " ", "Öðr. üyesi henüz kayýtlý deðil. Önce kaydýný yapabilirsiniz.") != 1) return; //öðr. üyesinin önceden var olmama durumunda veya dosyanýn açýlamamasý durumunda fonksiyon burada bitmeli
	
	ftch = fopen(ftchname, "r");
	if(!ftch)
	{
		printf("\nDosya bulunamadý. Lütfen tekrar deneyiniz.\n");
		return;
	}
	line = (char*)malloc(sizeof(char)*100);
	while(!feof(ftch))
	{
		fgets(line, 100, ftch);
		if(strstr(line, ouID))
		{
			sscanf(line, "%s %s %s %s", teacher.tchID, teacher.tchName, teacher.tchSurname, teacher.position);
		}
	}
	fclose(ftch);
	
	flec = fopen(flecname, "r");
	if(!flec)
	{
		printf("\nDosya bulunamadý. Lütfen tekrar deneyiniz.\n");
		return;
	}
	printf("\n%s ID numaralý öðretim üyesinin verdiði dersler:\n\n  DERS KODU	DERS ADI\n", teacher.tchID);
	while(!feof(flec))
	{
		fgets(line, 100, flec);
		if(strstr(line, ouID))
		{
			sscanf(line, "%s %s %d %d %s", lecture.lecCode, lecture.lecName, &lecture.credit, &lecture.quota, lecture.tchID);
			printf("\n  %s  	%s\n", lecture.lecCode, lecture.lecName);
			found = 1;
		}
	}
	fclose(flec);
	if(found == 0)
	{
		printf("\n\n%s %s, henüz herhangi bir derse atanmamýþtýr.\n", teacher.tchName, teacher.tchSurname);
	}
	free(line);
}

void stdByCode_list(char *fstdname, char *flecname)
{
	FILE *fstd, *frec, *flec;
	STD student;
	char *lineREC;
	char *lineSTD;
	char recNO[5], recstdID[10], tire[5], reclecNO[10], pass[10]; //öðrenci-ders kayýt durumlarý için		
	char dersKodu[10];
	int found = 0;
	
	printf("\nÖðrencilerini görmek istediðiniz dersin kodunu giriniz: ");
	scanf("%s", dersKodu);
	
	//DERS KAYIT KONTROLÜ
	if(mevcut(flecname, dersKodu, " ", "Bu ders henüz açýlmamýþ.") != 1) return; //dersin önceden açýlmama durumunda veya dosyanýn açýlamamasý durumunda fonksiyon burada bitmeli
	
	printf("\n%s kodlu dersi alan öðrenciler:\n\n ÖÐRENCÝ ID   ÖÐRENCÝ AD-SOYAD\n", dersKodu);
	
	frec = fopen("OgrenciDersKayit.txt", "r");
	if(!frec)
	{
		printf("\nDosya bulunamadý. Lütfen tekrar deneyiniz.\n");
		return;
	}
	
	lineREC = (char*)malloc(sizeof(char)*100);
	lineSTD = (char*)malloc(sizeof(char)*100);
	while(!feof(frec))
	{
		fgets(lineREC, 100, frec);
		if(strstr(lineREC, dersKodu))
		{
			sscanf(lineREC, "%s %s %s %s %s", recNO, recstdID, tire, reclecNO, pass);
			
			if(!strcmp(pass, "KAYITLI"))
			{
				//öðrencinin adýný da listelemek için öðrenciler dosyasýný açýyoruz
				fstd = fopen(fstdname, "r");
				if(!fstd)
				{
					printf("\nDosya bulunamadý. Lütfen tekrar deneyiniz.\n");
					return;
				}
				while(!feof(fstd))
				{
					fgets(lineSTD, 100, fstd);
					if(strstr(lineSTD, recstdID))
					{
						sscanf(lineSTD, "%s %s %s %d %d", student.stdID, student.stdName, student.stdSurname, &student.numOfLectures, &student.numOfCredits);
						
						printf("\n %s     %s %s\n", student.stdID, student.stdName, student.stdSurname);
						found = 1;						
					}
				}
				fclose(fstd);
			}			
		}
	}
	fclose(frec);
	
	if(found == 0)
	{
		printf("\n\n%s dersini henüz kimse almamýþtýr.\n", dersKodu);
	}	
	free(lineREC);
	free(lineSTD);
	
	printf("\n\nMenüye dönmek için herhangi bir tuþa basýnýz: ");
	getch();
}

void lecByStdID_list(char *fstdname, char *flecname)
{
	FILE *fstd, *flec, *frec;
	char oID[10], *line, *lineLEC;
	char recNO[5], recstdID[10], tire[5], reclecNO[10], pass[10]; //öðrenci-ders kayýt durumlarý için			
	int found = 0;
	
	STD student;
	LEC lecture;
	
	printf("\nDerslerini görmek istediðiniz öðrenci ID numarasýný giriniz: ");
	scanf("%s", oID);
	
	//hem öðrenci varlýðý kontrolü hem de öðrenci bilgilerini alma iþlemi
	fstd = fopen(fstdname, "r");
	if(!fstd)
	{
		printf("\nDosya bulunamadý. Lütfen tekrar deneyiniz.\n");
		return;
	}
	
	line = (char*)malloc(sizeof(char)*100);
	lineLEC = (char*)malloc(sizeof(char)*100);
	while(!feof(fstd))
	{
		fgets(line, 100, fstd);
		if(strstr(line, oID))
		{
			sscanf(line, "%s %s %s %d %d", student.stdID, student.stdName, student.stdSurname, &student.numOfLectures, &student.numOfCredits);
			printf("\nÖðrenci Ad-Soyad: %s %s\n", student.stdName, student.stdSurname);
			found = 1;						
		}
	}
	fclose(fstd);
	if(found == 0)
	{
		printf("\n\n%s numaralý bir öðrenci kaydý bulunamadý.\n", oID);
		free(line);
		free(lineLEC);
		return;
	}
	found = 0;
	
	printf("\n %s numaralý öðrencinin aldýðý dersler:\n\n  DERS KODU   DERS ADI\n", oID);
	
	//ODK KAYIT DURUMU KONTROLÜ
	frec = fopen("OgrenciDersKayit.txt", "r");
	if(!frec)
	{
		printf("\nDosya bulunamadý. Lütfen tekrar deneyiniz.\n");
		free(line);
		free(lineLEC);
		return;
	}
	while(!feof(frec))
	{
		fgets(line, 100, frec);
		if(strstr(line, oID))
		{
			sscanf(line, "%s %s %s %s %s", recNO, recstdID, tire, reclecNO, pass);
			
			if(!strcmp(pass, "KAYITLI"))
			{
				//dersin adýný da listede göstermek için dersler dosyasýný açýyoruz
				flec = fopen(flecname, "r");
				if(!flec)
				{
					printf("\nDosya bulunamadý. Lütfen tekrar deneyiniz.\n");
					return;
				}
				while(!feof(flec))
				{
					fgets(lineLEC, 100, flec);
					if(strstr(lineLEC, reclecNO))
					{
						sscanf(lineLEC, "%s %s %d %d %s", lecture.lecCode, lecture.lecName, &lecture.credit, &lecture.quota, lecture.tchID);
						printf("\n  %s  	%s\n", lecture.lecCode, lecture.lecName);
						found = 1;
					}
				}
				fclose(flec);
			}			
		}
	}
	fclose(frec);
	
	if(found == 0)
	{
		printf("\n\n%s numaralý öðrenci henüz ders almamýþtýr.\n", oID);
	}
	free(line);
	free(lineLEC);
	
	printf("\n\nMenüye dönmek için herhangi bir tuþa basýnýz: ");
	getch();
}

void printClassroom(char *ftchname, char *flecname, char *fstdname)
{
	FILE *ftch, *flec, *fstd, *frec, *fptr;
	TCH teacher;
	LEC lecture;
	STD student;
	char *buffer = (char*)malloc(sizeof(char)*2000);
	char *bufLine = (char*)malloc(sizeof(char)*100);
	char *lineREC = (char*)malloc(sizeof(char)*100);
	char *lineSTD = (char*)malloc(sizeof(char)*100);
	char recNO[5], recstdID[10], tire[5], reclecNO[10], pass[10]; //öðrenci-ders kayýt durumlarý için		
	char ouID[10], dersKodu[10], *ptr, fname[20];
	int found = 0;
	
	//KAYITLARI TUTUP DOSYAYA YAZDIRMAK ÝÇÝN
	memset(buffer, 0, 2000*(sizeof(char)));
	ptr = buffer;
	
	lecByTchID_list(flecname, ftchname);
	
	printf("\nSýnýf listesini yazdýrmak için öðretim üyesi ID numarasýný lüten tekrar giriniz: ");
	scanf("%s", ouID);
	
	if(mevcut(ftchname, ouID, " ", " ") != 1)
	{
		printf("\nÖðretim üyesi kaydý yine bulunamadý.");
		printf("\n\nMenüye dönmek için herhangi bir tuþa basýnýz: ");
		getch();
		free(lineREC);
		free(lineSTD);
		free(bufLine);
		free(buffer);
		return;
	}
	
	printf("\nSýnýf listesini, DERSKODU_SINIFLiSTESi.txt dosyasýna yazdýrmak istediðiniz ders kodunu giriniz: ");
	scanf("%s", dersKodu);
	
	strcpy(ptr, ouID);
	ptr += strlen(ouID);
	
	strcpy(ptr, " numarali ogretim uyesinden ");
	ptr += strlen(" numarali ogretim uyesinden ");
	
	strcpy(ptr, dersKodu);
	ptr += strlen(dersKodu);
	
	strcpy(ptr, " kodlu dersi alan ogrenciler:\n\n");
	ptr += strlen(" kodlu dersi alan ogrenciler:\n\n");
	
	//DERS KAYIT KONTROLÜ
	strcpy(ptr, "OGRENCI ID   OGRENCI AD-SOYAD\n");
	ptr += strlen("OGRENCI ID   OGRENCI AD-SOYAD\n");
		
	frec = fopen("OgrenciDersKayit.txt", "r");
	if(!frec)
	{
		printf("\nDosya bulunamadý. Lütfen tekrar deneyiniz.\n");
		free(lineREC);
		free(lineSTD);
		free(bufLine);
		free(buffer);
		return;
	}
	while(!feof(frec))
	{
		fgets(lineREC, 100, frec);
		if(strstr(lineREC, dersKodu))
		{
			sscanf(lineREC, "%s %s %s %s %s", recNO, recstdID, tire, reclecNO, pass);
			
			if(!strcmp(pass, "KAYITLI"))
			{
				//öðrencinin adýný da listelemek için öðrenciler dosyasýný açýyoruz
				fstd = fopen(fstdname, "r");
				if(!fstd)
				{
					printf("\nDosya bulunamadý. Lütfen tekrar deneyiniz.\n");
					free(lineREC);
					free(lineSTD);
					free(bufLine);
					free(buffer);
					return;
				}
				while(!feof(fstd))
				{
					fgets(lineSTD, 100, fstd);
					if(strstr(lineSTD, recstdID))
					{
						sscanf(lineSTD, "%s %s %s %d %d", student.stdID, student.stdName, student.stdSurname, &student.numOfLectures, &student.numOfCredits);
						
						memset(bufLine, 0, 100);
						
						strcat(bufLine, student.stdID);
						strcat(bufLine, "     ");
						strcat(bufLine, student.stdName);
						strcat(bufLine, " ");
						strcat(bufLine, student.stdSurname);
						strcat(bufLine, "\n");
						
						strcpy(ptr, bufLine);
						ptr += strlen(bufLine);
						
						found = 1;						
					}
				}
				fclose(fstd);
			}			
		}
	}
	fclose(frec);
	
	if(found == 0)
	{
		printf("\n\n%s dersini henüz kimse almamýþtýr. Dosyaya bir þey yazýlamadý.\n", dersKodu);
		return;
	}
	printf("\nOluþturmak istediðiniz sýnýf listesinin adýný derskodu_SINIFLiSTESi.txt formatýnda giriniz: ");
	scanf("%s", fname);
	fptr = fopen(fname, "a");
	fprintf(fptr, "%s", buffer);
	fclose(fptr);
	
	free(lineREC);
	free(lineSTD);
	free(bufLine);
	free(buffer);
	
	printf("\n		DERSKODU_SINIFLiSTESi.txt dosyasýna sýnýf listesi oluþturuldu.\n\nMenüye dönmek için herhangi bir tuþa basýnýz: ");
	getch();
}

