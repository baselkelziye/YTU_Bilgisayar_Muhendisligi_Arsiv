#include <stdio.h>
#include <stdlib.h>
#include <string.h>   
#include <conio.h>
#include <time.h>
#include <unistd.h>

#define LEN 15

/*
-- -- -- -- -- -- -- -- -- -- -- -- - PROJE HAKKINDA - -- -- -- -- -- -- -- -- -- -- -- -- --
-> Auto-Play modu haricinde geri kalan butun istenilenler bulunmaktadir.
-> Ek olarak ana menu secim ekraninda 8 tuslandiginda kayitli kullanicilari listelenmektedir,
   7 tuslandiginda her kullaniciya ait en yuksek 5 skor listelenmektedir
   ve yine ana menude 9 tuslandiginda kayitli kullanicilari silmektedir. 
-> Bu ozellikler ana menu secim ekraninda ekrana yazdirilmamistir.
*/

//Kullanici bilgilerinin tutuldugu struct.
struct Kullanici{
	char isim[LEN];
	char soyIsim[LEN];
	char kullaniciAdi[LEN];
	char sifre[LEN];
	int skor[5]; //En yuksek 5 skor ayni kullaniciya ait olabileceginden dolayi her kullaniciya ait en yuksek 5 skor struct'ta saklanmistir.
};

//Kullanici islemleri ile ilgili fonksiyonlar
struct Kullanici* kullaniciAl(char *dosyaAdi, int *N);
void kullaniciYazdir(char *dosyaAdi, struct Kullanici* kullanicilar, int N);
void kullaniciOlustur(struct Kullanici* kullanicilar, int *N);
int girisYap(struct Kullanici* kullanicilar, int N);
void kullanicilariListele(struct Kullanici* kullanicilar, int n);
void kullanicilariSifirla(char *dosyaAdii, int *N);

//Oyun ve skor ile ilgili fonksiyonlar
char** haritaAl(char* dosyaAdi, int *N, int *M);
void haritaYazdir(char **matris, int n, int m);
void skorlar(struct Kullanici *kullanicilar, int n);
void butunSkorlar(struct Kullanici *kullanicilar, int n); //silinecek
int manuelOyna(char **harita, int N, int M);
char hamleKontrol(char **harita, int N, int M, int x, int y);
void parcacikYazdir(char *parcaciklar, int parcacikSayisi);
int karsitMaddeHesapla(char *parcaciklar, int parcacikSayisi);
int min(int x, int y);
int skorHesapla(double kalanSure, int karsitMadde, double yapilanHamle, int tamamlandi);
void skorKaydet(struct Kullanici *kullanicilar, int x, int skor);

//Ekran duzeni ve kullaniciyi bilgilendirme ile ilgili fonksiyonlar
void ortala(char* metin);
void temizle();
void mesajVeTemizle(char mesaj[]);
void devam();
void nasilOynanir();

int main(){
	int n = 0; //Kullanici sayisi.
	int secim; //Ana menude yapilan secim.
	int kullanici; //Giris yapan kullanicinin listedeki indeksi.
	int secimOyun; //Oyun menusunda yapilan secim.
	int skor;
	int N,M; //Oyun haritasinin boyutlari.
	char kullaniciDosya[] = "kullanicilar.bin"; //Kullanicilarin bulundugu dosyanin ismi.
	char dosyaAdi[20]; //Alinacak haritanin bulundugu dosyanin ismi. Kullanicidan alinir.
	char **harita;
	
	//Kullanicilarin tutuldugu struct dizisi dinamik olarak tanimlanmistir.
	struct Kullanici *kullanicilar = kullaniciAl(kullaniciDosya, &n);
	
	//Ana menu cikis yapilana kadar ekrana yazdirilir.
	do{
		printf("\033[1;3%dm%s\033[0m\n", 4, " *ANA MENU* ");
		printf("1- Giris Yap\n");
		printf("2- Kayit Ol\n");
		printf("3- Cikis\n");
		printf("Seciminiz: ");
		scanf("%d",&secim);
		
		switch(secim){
			case 1: //Giris Yap
				temizle();
				kullanici = girisYap(kullanicilar, n);
				if(kullanici>-1){
					//Oyun menusu cikis yapilana kadar ekrana yazdirilir.
					do{
						printf("\033[1;3%dm%s\033[0m\n", 4, "    *OYUN MENUSU*    ");
						printf("1- Hazir Harita Yukle\n");
						printf("2- Harita Yukle\n");
						printf("3- Skorlar\n");
						printf("4- Nasil Oynanir?\n");
						printf("5- Geri Don\n");
						printf("Seciminiz: ");
						scanf("%d",&secimOyun);
						
						switch(secimOyun){
							case 1: //Hazir harita olarak harita1.txt dosyasini kullanir.
								harita = haritaAl("harita1.txt",&N,&M);
								if(harita != NULL){
									skor = manuelOyna(harita,N,M);
									skorKaydet(kullanicilar, kullanici, skor);
								}else{
									mesajVeTemizle("Harita acilamadi! Menuye geri donuluyor...");
								}
								
								break;
							case 2: //Girilen dosya ismindeki dosyadan oyun haritasini alir.
								temizle();
								printf("Dosya ismi giriniz: ");
								scanf("%s",dosyaAdi);
								harita = haritaAl(dosyaAdi,&N,&M);
								if(harita != NULL){
									skor = manuelOyna(harita,N,M);
									skorKaydet(kullanicilar, kullanici, skor);
								}else{
									mesajVeTemizle("Harita acilamadi! Menuye geri donuluyor...");
								}
								break;
							case 3: //Oyuna ait en yuksek 5 skoru yazdirir.
								temizle();
								skorlar(kullanicilar, n);
								devam();
								break;
							case 4: //Oyunun nasil oynanacagina ait bilgileri yazdirir.
								temizle();
								nasilOynanir();
								break;
							case 5: //Ana Menuye Don
								mesajVeTemizle("Ana menuye donuluyor...");
								break;
							default:
								mesajVeTemizle("Hatali secim yaptiniz!");
								break;
						}
					}while(secimOyun != 5);
				}
				break;
			case 2: //Kayit Ol
				temizle();
				kullaniciOlustur(kullanicilar, &n);
				break;
			case 3: //Cikis Yap
				printf("Cikis yapiliyor...");
				kullaniciYazdir(kullaniciDosya, kullanicilar, n);
				sleep(1);
				break;
			case 7: //Kullanicilar ait butun skorlari listeler.
				temizle();
				butunSkorlar(kullanicilar, n);
				devam();
				break;
			case 8: //Kullanicilar ait bilgileri listeler.
				temizle();
				kullanicilariListele(kullanicilar,n);
				devam();
				break;
			case 9: //Kullanicilari ve kullanicilarin bulundugu dosyayi temizler.
				temizle();
				kullanicilariSifirla(kullaniciDosya, &n);
				devam();
				break;		
			default:
				mesajVeTemizle("Hatali secim yaptiniz!");
				break;
		}
	}while(secim != 3);
	
	free(kullanicilar);	
	return 0;
}

//Kullanicilari dosyadan okur ve kullanicilari dinamik olarak kaydedip dondurur.
struct Kullanici* kullaniciAl(char *dosyaAdi, int *N){
	int n = 0;
	
	FILE *dosya = fopen(dosyaAdi, "rb");
	if(dosya == NULL){ //Eger kullanicilarin okunacagi dosya yoksa dosyayi kendisi olusturur.
		dosya = fopen(dosyaAdi, "wb");
	}
	
	struct Kullanici *kullanicilar = (struct Kullanici*) calloc(1, sizeof(struct Kullanici));	
	
	while(fread(&kullanicilar[n], sizeof(struct Kullanici), 1, dosya) == 1){
		n++;
		kullanicilar = (struct Kullanici*) realloc(kullanicilar, (n+1)*sizeof(struct Kullanici));		
	}
	*N = n;
	
	fclose(dosya);
	return kullanicilar;
}

//Programdan cikis yapildiginda kullanicilari dosyaya yazdirir.
void kullaniciYazdir(char *dosyaAdi, struct Kullanici* kullanicilar, int N){
	FILE *dosya = fopen(dosyaAdi, "wb");
	
	int i;
	for(i=0;i<N;i++){
		fwrite(&kullanicilar[i], sizeof(struct Kullanici), 1, dosya);
	}	
}

//Yeni kullanici olusturur, bu islemi gerceklestirirken gerekli kontrol islemlerini yapar.
void kullaniciOlustur(struct Kullanici* kullanicilar, int *N){
	int n = *N;
	struct Kullanici u;	
	
	printf("\033[1;3%dm%s\033[0m\n", 3, "          -Kayit Ol-");
	printf("Kullanici Adi: ");
	scanf("%s",u.kullaniciAdi);
	printf("         Isim: ");
	scanf("%s",u.isim);	
	printf("      Soyisim: ");
	scanf("%s",u.soyIsim);	
	printf("        Sifre: ");
	scanf("%s",u.sifre);
	
	int i = 0;
	while(i<n && strcmp(kullanicilar[i].kullaniciAdi, u.kullaniciAdi)){
		i++;
	}
	
	if(i==n){
		kullanicilar = (struct Kullanici*) realloc(kullanicilar, (n+1)*sizeof(struct Kullanici));
		kullanicilar[n] = u;
		for(i=0;i<5;i++){
			kullanicilar[n].skor[i] = 0;
		}
		(*N)++;
		mesajVeTemizle("Kullanici olusturuldu! Ana menuye donuluyor...");
	}else{
		mesajVeTemizle("Bu kullanici adina sahip birisi var! Ana menuye donuluyor...");
	}	
}

//Kullanicinin giris yapmasini saglar, gerekli kontrolleri yapar.
int girisYap(struct Kullanici* kullanicilar, int N){
	char kullaniciAdi[15];
	char sifre[15];
	
	printf("\033[1;3%dm%s\033[0m\n", 3, "        -Giris Yap-");
	printf("Kullanici adi: ");
	scanf("%s", kullaniciAdi);
	printf("        Sifre: ");
	scanf("%s",sifre);
	
	int i = 0;
	while(i<N && strcmp(kullanicilar[i].kullaniciAdi, kullaniciAdi)){
		i++;
	}
	
	if(i != N){
		if(!strcmp(kullanicilar[i].sifre, sifre)){
			mesajVeTemizle("Basariyla giris yapildi! Oyun menusune geciliyor...");
			return i;
		}else{
			mesajVeTemizle("Hatali sifre! Ana menuye donuluyor...");
			return -1;
		}
	}else{
		mesajVeTemizle("Boyle bir kullanici adina sahip kullanici bulunamadi! Ana menuye donuluyor...");
		return -1;
	}
}

//Dosyadan oyun haritasini okur. Harita dosyaya su sekilde kaydedilmelidir:
//Ilk satira satir ve sutun sayisi aralarinda bir bosluk olacak sekilde kaydedilir.
//Sonraki her satira sirasiyla satir sutun ve matrisin o bolmesinde bulunan deger aralarinda bir bosluk olacak sekilde kaydedilir.
char** haritaAl(char* dosyaAdi, int *N, int *M){
	int n,m,i,j;
	char c;
	
	FILE *dosya = fopen(dosyaAdi, "r");
	if(dosya == NULL){
		return NULL;
	}
	
	fscanf(dosya,"%d %d\n",&n,&m);
	(*N) = n;
	(*M) = m;
	
	char **matris = (char**) calloc(n,sizeof(char*));
	for(i=0;i<n;i++){
		matris[i] = (char*) calloc(m,sizeof(char));
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			matris[i][j] = '0';
		}
	}
	
	while(!feof(dosya)){
		fscanf(dosya,"%d %d %c\n",&i,&j,&c);
		matris[i][j] = c;
	}
	
	fclose(dosya);
	return matris;
}

//Oyun oynanirken ekrana haritayi yazdirir.
void haritaYazdir(char **harita, int n, int m){
	int i, j;
	char nokta;
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			nokta = harita[i][j];
			if(nokta == 'K' || nokta == 'C'){
				printf("\033[1;3%dm%c\033[0m ", 0, nokta);
			}else if(nokta == 'P'){
				printf("\033[1;3%dm%c\033[0m ", 4, nokta);
			}else if(nokta == 'p'){
				printf("\033[1;3%dm%c\033[0m ", 6, nokta);	
			}else if(nokta == 'E' || nokta == 'e'){
				printf("\033[1;3%dm%c\033[0m ", 2, nokta);
			}else if(nokta == 'X' || nokta == 'G'){
				printf("\033[1;3%dm%c\033[0m ", 1, nokta);
			}else if(nokta == '0'){
				printf("\033[1;3%dm%c\033[0m ", 7, nokta);
			}else if(nokta == '1'){
				printf("\033[1;3%dm%c\033[0m ", 3, nokta);
			}else{
				printf("%c ", nokta);
			}
		}
		printf("\n");
	}
}

//Oyuna ait en yuksek 5 skoru ekrana yazdirir.
void skorlar(struct Kullanici *kullanicilar, int n){
	int skor[5] = {-1,-1,-1,-1,-1};
	int index[5][2] = {{0,0},{0,0},{0,0},{0,0},{0,0}};
	int i=0,j,k,m;
	
	while(i<n){		
		for(m=0;m<5;m++){
			j = 0;
			while(j<5){
				if(kullanicilar[i].skor[m] > skor[j]){
					for(k=4;k>j;k--){
						skor[k] = skor[k-1];
						index[k][0] = index[k-1][0];
						index[k][1] = index[k-1][1];
					}
					skor[j] = kullanicilar[i].skor[m];
					index[j][0] = i;
					index[j][1] = m;
					
					j = 5;
				}else{
					j++;
				}				
			}
		}
		i++;
	}
	
	printf("\033[1;3%dm%s\033[0m\n", 3, "     -En Yuksek 5 Skor-");
	for(i=0;i<5;i++){
		printf("%d. %5d -> %s\n", i+1, kullanicilar[index[i][0]].skor[index[i][1]], kullanicilar[index[i][0]].kullaniciAdi);
	}
}

//Oyuna ait butun skorlari ekrana yazdirir.
void butunSkorlar(struct Kullanici *kullanicilar, int n){
	int i;
	printf("+---------------+-----------------------------+\n");
	printf("| \033[1;33mKULLANICI ADI\033[0m |           \033[1;33mSKORLAR\033[0m           |\n");
	printf("+---------------+-----------------------------+\n");
	for(i=0;i<n;i++){
		ortala(kullanicilar[i].kullaniciAdi);
		printf("| %4d, %4d, %4d, %4d, %4d|\n", kullanicilar[i].skor[0], kullanicilar[i].skor[1], kullanicilar[i].skor[2], kullanicilar[i].skor[3], kullanicilar[i].skor[4]);
		printf("+---------------+-----------------------------+\n");
	}
}

//Oyunu manuel olarak oynattirir.
int manuelOyna(char **harita, int N, int M){
	char yon;
	char nokta;
	int i,x,y;
	int skor;
	int parcacikSayisi = 0;
	int tamamlandi = 0;	
	int karsitMaddeSayisi = 0;
	int hamleSayisi = 0;
	int sure = N*M;
	int kalanSure = sure;
	int dx=0, dy=0;
	
	clock_t baslangic;
	clock_t anlik;
	
	char *parcaciklar = (char*) malloc(sizeof(char));
	
	for(i=0;i<N;i++){ //Haritanin girisini bularak X'i girise konumlandirir.
		y=0;
		while(y<M && harita[i][y] != 'G'){
			y++;
		}
		if(y!=M){
			x = i;
			i = N;
		}
	}
	harita[x][y] = 'X';
	
	temizle();
	printf("Oyun basliyor!\n");
	sleep(1);
	for(i=3;i>0;i--){
		printf("%d...\n",i);
		sleep(1);
	}
	temizle();	
	haritaYazdir(harita,N,M);
	printf("Kalan Sure: %d saniye\n",kalanSure);
	printf("Toplanan parcaciklar: \n");
	baslangic = clock();
	do{
		yon = getch();
		
		if(yon == -32){ // Ok tuslarindan biri tuslandiginda gerekli hamleyi yapar.
			yon = getch();
			switch(yon){
				case 72: //yukari
					dx = -1;
					dy = 0;
					break;
				case 80: //asagi
					dx = 1;
					dy = 0;
					break;
				case 77: //sag
					dx = 0;
					dy = 1;
					break;
				case 75: //sol
					dx = 0;
					dy = -1;
					break;
				default:
					printf("Farkli bir tusa bastiniz!\n");
					break;
			}
			nokta = hamleKontrol(harita, N, M, x+dx, y+dy);
			if(nokta == 'C' || nokta == 'K'){ //Kara delige ya da cikisa ulasilirsa oyun sonlanir.
				tamamlandi = 1;
			}else if(nokta != '0' && nokta != -1){
				parcaciklar = (char*) realloc(parcaciklar, (parcacikSayisi+1)*sizeof(char));
				parcaciklar[parcacikSayisi] = nokta;
				parcacikSayisi++;
			}
			
			if(nokta != -1){
				harita[x][y] = '0';
				x += dx;
				y += dy;
				harita[x][y] = 'X';
				temizle();
				haritaYazdir(harita,N,M);
				printf("Kalan Sure: %d saniye\n",kalanSure=sure-(clock()-baslangic)/CLOCKS_PER_SEC);
				parcacikYazdir(parcaciklar, parcacikSayisi);
			}
			hamleSayisi++;
		}
	//esc tuslandiginda, oyun tamamlandiginda ya da sure doldugunda oyunu sonlandirir.
	}while(yon != 27 && tamamlandi == 0 && (kalanSure = sure-(clock()-baslangic)/CLOCKS_PER_SEC)>0);
	
	if(nokta != 'K'){ //Kara delik ile karsilasildiginda skor hesaplanir ancak toplanan parcaciklar yok olur.
		karsitMaddeSayisi = karsitMaddeHesapla(parcaciklar, parcacikSayisi);
	}	
	skor = skorHesapla((double)kalanSure/sure, karsitMaddeSayisi, (double) hamleSayisi/(N*M), tamamlandi);
	
	//Oyunun sonlanma bicimine gore kullaniciya oyun sonucunu yazdirir.
	if(tamamlandi == 1){
		if(nokta == 'K'){
			printf("Kara delik ile karsilasildi, butun parcaciklar yok oldu!\n");
			printf("Oyunu %d skor ile bitirdiniz!\n", skor);
		}else{
			printf("Tebrikler! Oyunu %d adet karsit madde toplayarak %d skor ile bitirdiniz!\n", karsitMaddeSayisi, skor);
		}		
	}else if(yon == 27){
		printf("Oyun kullanici tarafindan sonlandirildi! Oyunu %d adet karsit madde toplayarak %d skor ile bitirdiniz!\n", karsitMaddeSayisi, skor);
	}else{
		printf("Sure doldu! Oyunu %d adet karsit madde toplayarak %d skor ile bitirdiniz!\n", karsitMaddeSayisi, skor);
	}
	
	devam();
	free(parcaciklar);
	
	for(i=0;i<N;i++){
		free(harita[i]);
	}
	free(harita);
	
	return skor;
}

//Yapilan hamle gecerliyse yeni konumdaki elementi, gecersizse -1 dondurur.
char hamleKontrol(char **harita, int N, int M, int x, int y){
	if(x!=N && y!=M && x!=-1 && y!=-1 && harita[x][y] != '1'){
		return harita[x][y];
	}
	
	return -1;
}

//Toplanan parcaciklari yazdirir.
void parcacikYazdir(char *parcaciklar, int parcacikSayisi){
	int i;
	printf("Toplanan parcaciklar: ");
	for(i=0;i<parcacikSayisi;i++){
		printf("%c ",parcaciklar[i]);
	}
	printf("\n");
}

//Olusturulan karsit madde sayisini dondurur.
//Karsit madde sayisi oyun sonlandiginda hesaplanir.
int karsitMaddeHesapla(char *parcaciklar, int parcacikSayisi){
	int karsitMadde = 0;
	int i;
	int p=0,P=0,e=0,E=0;
	int yokOlanParcacikSayisi;
	
	for(i=0;i<parcacikSayisi;i++){
		if(parcaciklar[i] == 'p'){
			p++;
		}else if(parcaciklar[i] == 'P'){
			P++;
		}else if(parcaciklar[i] == 'e'){
			e++;
		}else if(parcaciklar[i] == 'E'){
			E++;
		}
	}

	yokOlanParcacikSayisi = min(p,P);
	p = p - yokOlanParcacikSayisi;
	P = P - yokOlanParcacikSayisi;
	yokOlanParcacikSayisi = min(e,E);
	e = e - yokOlanParcacikSayisi;
	E = E - yokOlanParcacikSayisi;	

	return min(p,E);
}

//Verilen iki sayidan kucugunu dondurur.
int min(int x, int y){
	if(x<y){
		return x;
	}else{
		return y;
	}
}

//Oyuna ait skoru hesaplayip dondurur.
int skorHesapla(double kalanSure, int karsitMadde, double yapilanHamle, int tamamlandi){
	int skor = (karsitMadde*400) - (yapilanHamle*200);
	
	if(tamamlandi==0){
		skor = skor*0.2;
	}else{
		skor += (kalanSure*300);
	}
	
	return skor;
}

//Oynanan oyun sonucu elde edilen skor, kullanicinin en yuksek skorlari arasindaysa kullanicinin skorlarina sirali bicimde kaydedilir.
void skorKaydet(struct Kullanici *kullanicilar, int x, int skor){
	int i = 0,j;
	while(i<5 && skor<kullanicilar[x].skor[i]){
		i++;
	}
	
	if(i!=5){
		for(j=4;j>i;j--){
			kullanicilar[x].skor[j] = kullanicilar[x].skor[j-1];
		}
		kullanicilar[x].skor[i] = skor;
	}
}

//Ekrani temizler.
void temizle(){
	system("cls");	
}

//Girilen mesaji ekrana yazdirir ve ekrani temizler.
void mesajVeTemizle(char mesaj[]){
	printf("%s",mesaj);
	sleep(2);
	temizle();	
}

//Herhangi bir tus tuslandiginda basildiginda ekrani temizler.
void devam(){
	sleep(1);
	printf("Devam etmek icin herhangi bir tusa basiniz...");
	getch();
	system("cls");	
}

//Oyunun nasil oynanacagina dair bilgileri ekrana yazdirir.
void nasilOynanir(){
	int N,M,i;
	char **harita = haritaAl("harita1.txt",&N,&M);
	printf("\033[1;3%dm%s\033[0m\n\n", 3, "                                      -Nasil Oynanir?-");
	haritaYazdir(harita, N, M);
	printf("\n-> \033[1;31mX\033[0m, kullanicinin haritada bulundugu konumu gostermektedir.\n");
	printf("-> \033[1;33m1\033[0m, haritada bulunan duvarlari gostermektedir.\n");
	printf("   Duvarlarin ustune gelinemez.\n");
	printf("-> \033[1;37m0\033[0m, haritada bulunan yollari gostermektedir.\n");
	printf("   Yollarin uzerinden gecilebilir.\n");
	printf("-> \033[1;36mp\033[0m, karsit protonlari ifade etmektedir.\n");
	printf("-> \033[1;34mP\033[0m, protonlari ifade etmektedir.\n");
	printf("-> \033[1;32mE\033[0m, karsit elektronlari ifade etmektedir.\n");
	printf("-> \033[1;32me\033[0m, elektronlari ifade etmektedir.\n");
	printf("-> \033[1;30mK\033[0m, kara delikleri ifade etmektedir.\n");
	printf("   Kara delik uzerine gelindiginde butun parcaciklar yok olur ve oyun sonlanir.\n");
	printf("-> \033[1;30mC\033[0m, cikisi ifade etmektedir.\n");
	printf("   Cikis uzerine gelindiginde oyun sonlanir.\n");
	
	printf("\n-> Harita uzerinde hareket etmek icin yon tuslari kullanilmalidir.\n");
	printf("-> Oyunu direkt sonlandirmak icin esc tusuna basilmalidir.\n");
	
	printf("-> Oyunun amaci karsit madde uretmektir.\n");
	printf("   Karsit madde uretmek icin karsit proton (\033[1;36mp\033[0m) ve karsit elektron (\033[1;32mE\033[0m) toplanmalidir.\n");
	printf("   Bir parcacik ve onun karsit parcacigi birbirini yok eder.\n\n");
	
	devam();
	
	printf("-> Skor hesaplanirken asagidaki formul kullanilir.\n");
	printf("   skor = (Karsit Madde Sayisi * 400) - (Yapilan Hamle Orani * 200)\n\n");
	printf("   Eger oyun cikisa gelerek tamamlanmissa:\n");
	printf("   skor += (Kalan Sure Orani * 300)\n\n");
	printf("   Eger oyun kullanici tarafindan sonlandirilmissa:\n");
	printf("   skor = skor * 0.2\n\n");
	
	for(i=0;i<N;i++){
		free(harita[i]);
	}
	free(harita);
	
	devam();
}

//Kullanicilara ait bilgileri listeler.
void kullanicilariListele(struct Kullanici* kullanicilar, int n) {
    int i;
	
    printf("+---------------+---------------+---------------+---------------+\n");
    printf("|     \033[1;33mISIM\033[0m      |    \033[1;33mSOYISIM\033[0m    | \033[1;33mKULLANICI ADI\033[0m |     \033[1;33mSIFRE\033[0m     |\n");
    printf("+---------------+---------------+---------------+---------------+\n");
    
    for (i = 0; i < n; i++) {
        ortala(kullanicilar[i].isim);
        ortala(kullanicilar[i].soyIsim);
        ortala(kullanicilar[i].kullaniciAdi);
        ortala(kullanicilar[i].sifre);
        printf("|\n");
        printf("+---------------+---------------+---------------+---------------+\n");
    }
}

//Kullanicilara ait bilgiler ve skorlar listelenirken kullaniciya ait bilgiler duzgun gosterilmesi icin ortalanmis bir bicimde yazilir.
void ortala(char* metin){
    int uzunluk = strlen(metin);
    int bosluk = (LEN - uzunluk) / 2;
    if(uzunluk%2==0){
    	printf("|%*s%s%*s", bosluk+1, "", metin, bosluk, "");
	}else{
		printf("|%*s%s%*s", bosluk, "", metin, bosluk, "");
	}
}

//Kullanicilari ve kullanicilarin bulundugu dosyayi sifirlar.
void kullanicilariSifirla(char *dosyaAdi, int* N){
	char onay;
	
	printf("Kullanicilari sifirlamak icin e/E tusuna basiniz: ");
	scanf(" %c",&onay);
	
	if(onay == 'e' || onay == 'E'){
		FILE *dosya = fopen(dosyaAdi, "wb");
		fclose(dosya);
		(*N) = 0;
		printf("Kullanicilar sifirlandi.\n");
	}else{
		printf("Kullanicilar sifirlanmadi.\n");
	}	
}

