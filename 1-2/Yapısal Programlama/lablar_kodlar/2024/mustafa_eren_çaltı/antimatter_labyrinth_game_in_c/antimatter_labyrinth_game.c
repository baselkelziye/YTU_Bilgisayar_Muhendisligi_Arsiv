#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

typedef struct {
	char isim[50];
	char soyisim[50];
	char kullaniciAdi[50];
	char sifre[50];
}kullanici;					// Kullanýcýmýzýn bilgilerini tuttuðumuz struct.

typedef struct {
	char kullaniciAdi[50];
	float puan;
}kullaniciSkor;              //Skor dosyasýndan okunan veriyi isim ve puan olarak ayýrmka için oluþturduðum struct.


//Kullandi[im fonks'yonlarin prototipleri.
kullanici kullaniciOlusturma(const char *dosyaAdi);
int oncekilerleKiyasKullaniciAdi(kullanici* kullaniciListesi,char *isim,char *soyisim,int kullaniciSayisi);
kullanici girisYapma(const char *dosyaAdi);
char **oyunAlaniOlusturma();
void oyunAlaniBastirma(char **oyunAlanim,int n, int m);
void txtdenOkuma(const char *dosyaAdi, char ***oyunAlani,int *n,int *m);
void kullaniciKoordinatBulma(char **oyunAlani,int *x,int *y,int);
void bosluklardanKurtarma(char **oyunAlani, int n,int *m);
float hamleYapma(char **oyunAlani, int n, int m, int *x, int *y,int *flag,char *,int *,int,int,time_t *);
float sagaHamle(char **oyunAlani,int *x,int *y,char *parcaciklar,int *parcacikSayisi,int *flag);
float solaHamle(char **oyunAlani,int *x,int *y,char *parcaciklar,int *parcacikSayisi,int *flag);
float yukariHamle(char **oyunAlani,int *x,int *y,char *parcaciklar,int *parcacikSayisi,int *flag);
float asagiHamle(char **oyunAlani,int *x,int *y,char *parcaciklar,int *parcacikSayisi,int *flag);
void parcacikDizisiGuncelleme(char *parcaciklar,int *parcacikSayisi,char parcacik);
void karadeligeUlasildi(int *flag);
float oyunSonu(char *parcaciklar,int *parcacikSayisi,int *flag);
int skorlariKarsilastir(char *dosya,float skor, kullanici kullanici);
void oyunuBaslat(time_t *baslangicZamani);
void skorlariBastir(char *dosya);
void bilgileriGoster();

int main(){
	int s=0,n,m,x,y;
	float skor=0; // Baslangicta skor 0.
	char **oyunAlani;
	kullanici kullanici;
	int k;
	int secim;
	int secim2;
	int secim3; // Switch case , do while ya da ifler icin kullandigim degiskenler.
	int yenidenKullanma;
		
	printf("Oyuna hosgeldiniz! \n");
	printf("Yeni kullanici olusturmak icin 1'i, var olan bir kullaniciya giris yapmak icin ise 2'yi tuslayiniz: ");
	scanf("%d",&secim);
	switch (secim){
		
		case 1:
			kullanici = kullaniciOlusturma("dosyamiz.bin"); // dosyamiz.bin binary sekilde kullanici bilgilerini tuttugumuz dosya, case 1 yeni kullanici, case 2 ise giris yapma ekrani.
			break;
			
		case 2:
			kullanici = girisYapma("dosyamiz.bin");
			break;
	}
	do{
	system("cls");
	

	
	system("cls");
	printf("Oyunumuzda en yuksek 5 skoru yapmis kisileri ve bu skorlari gormek icin 1'i,\nOyunun nasil oynanacagi hakkindaki bilgileri goruntulemek icin 2'yi\nOyuna baslamak icin 3'u tuslayiniz:  "); // Ana menü..
	scanf("%d",&secim2);
	switch(secim2){
		case 1:
			skorlariBastir("skordosyasi.txt");
			break;
		case 2:
			bilgileriGoster();
			break;
		case 3:
			printf("\nHazir haritalardan biriyle oynamak icin 1'i, \nistediginiz bir haritayi yuklemek icin ise 2'yi tuslayiniz(Lutfen haritanizi oyunAlani isimli bir txt dosyasina kaydedin): ");  // Kullanýcý hazýr haritalardan birisini ya da oyunAlani.txt içerisine kaydetmiþ olduðu kendi oyun alanýyla oynaabilir.
			scanf("%d",&secim);
			if(secim == 1){
				printf("1. harita : \n");
				printf("C 0 0 e 0\n0 P E p 0\nP e P X e\nE 0 e K P\n1 P 0 P e\n1 0 K P 0\n0 0 e P 0");
				printf("\n\n2. harita : \n");
				printf("C p e 0 0 0 0\n0 1 E 0 0 P 0\nP e P X 0 0 0\nE 0 e 0 P 0 e\n1 P 0 P e 1 0\nK 0 1 P 0 P 0\n0 0 e P 0 e 0");    // Hazýr haritalarýn bastýrýlmasý.
				printf("\n\n3. harita : \n");
				printf("0 e 0 0 E 0 C 0\n0 0 0 e P p 0 0\np E P X 0 0 0 0\nE 0 e e 0 e 0 0\n1 P 0 P e K 0 0\n1 P 0 P 0 P 0 e\n0 e 0 P 0 e e 0");
				printf("\n\n4. harita : \n");
				printf("C 0 0 e 0\n0 P E p 0\nP e P X e\nE 0 e 0 P\n1 P 0 P e\n1 0 K P 0\n0 0 e P 0");
				printf("\n Seciminizi yapiniz: ");
				scanf("%d",&secim3);
				if(secim3 == 1){
					FILE *oyun = fopen("oyunAlani.txt","w");
					fprintf(oyun, "C 0 0 e 0\n0 P E p 0\nP e P X e\nE 0 e K P\n1 P 0 P e\n1 0 K P 0\n0 0 e P 0");
					fclose(oyun);
				}
				else if(secim3 == 2){
					FILE *oyun = fopen("oyunAlani.txt","w");
					fprintf(oyun, "C p e 0 0 0 0\n0 1 E 0 0 P 0\nP e P X 0 0 0\nE 0 e 0 P 0 e\n1 P 0 P e 1 0\nK 0 1 P 0 P 0\n0 0 e P 0 e 0");    // Hazýr haritalarý dosyaya yazýp kullanýcýya oynatmak için fprintf fonksiyonu yardýmýyla oyun alaný oluþturulmasý.
					fclose(oyun);
				}
				else if(secim3 == 3){
					FILE *oyun = fopen("oyunAlani.txt","w");
					fprintf(oyun, "0 e 0 0 E 0 C 0\n0 0 0 e P p 0 0\np E P X 0 0 0 0\nE 0 e e 0 e 0 0\n1 P 0 P e K 0 0\n1 P 0 P 0 P 0 e\n0 e 0 P 0 e e 0");
					fclose(oyun);
				}
				else if(secim3 == 4){
					FILE *oyun = fopen("oyunAlani.txt","w");
					fprintf(oyun, "C 0 0 e 0\n0 P E p 0\nP e P X e\nE 0 e 0 P\n1 P 0 P e\n1 0 1 K 0\n0 0 e P 0");
					fclose(oyun);
				}
				txtdenOkuma("oyunAlani.txt",&oyunAlani,&n,&m); // Kullanýcýnýn secýmýnden sonra txt dosyasýndan oyunAlani matrisine okuma yapýp oyun alanýnýn oluþturulmasý.
				if(oyunAlani[0][1] == ' '){
					bosluklardanKurtarma(oyunAlani,n,&m); // Eðer kullanýcý haritayý girerken '0EpE' yerine '0 E p E' þeklinde girmiþse matrise yazýlmýþ verinin indislerini düzeltmek ve kodu kolaylaþtýrmak için bir kontorl. 
				}
				kullaniciKoordinatBulma(oyunAlani,&x,&y,m);   // Oyun alani hazirlandiktan sonra kullanicinin koordinatlarini bulup oyunu onun uzerinden oynatacagiz. Burda da koordinatlari buluyoruz.
			}
			else if(secim == 2){
				txtdenOkuma("oyunAlani.txt",&oyunAlani,&n,&m); // Yukaridaki islemlerin aynisi.. harita sectirmeden bir onceki (varolan) haritayý yükler ya da yeni oluþturulup txt dosyasýnýn içine atýlmýþ olan haritayý oynatýr.
				if(oyunAlani[0][1] == ' '){
					bosluklardanKurtarma(oyunAlani,n,&m);
				}
				kullaniciKoordinatBulma(oyunAlani,&x,&y,m);
			}
			char *parcaciklar;
			parcaciklar = (char *)malloc(1 * sizeof(char)); // oyundayken elde ettiðimiz p E P ve e parçacýklarýný tutup sonradan saymak için oluþturduðum dizi.
			int parcacikSayisi=0; // Her oyunun baþýnda toplanan parçacýk sayýsýnýn sýfýrlanmasý.
			int flag=3; // Oyunu sonlandýrmak için kullandýðým flag.
			int xcpy = x; // Baþlangýç koordinatlarýný baþka fonksiyonlarda kullanmak üzere kopyaladým.
			int ycpy = y;
			time_t baslangicZamani = time(NULL); // Kullanýcýnýn belirli bir zamanda oyunu sonlandýrýp puan almasý ya da sürenin dýþýna çýkýp oyundan atýlmasýný saðlamak için baþlattýðým zaman.
			while(flag == 3){
				skor = hamleYapma(oyunAlani, n, m, &x, &y,&flag,parcaciklar,&parcacikSayisi,xcpy,ycpy,&baslangicZamani); // Oyunu oynattýðým fonksiyon.
			}
			if(skor>1100) // Eðer oyun sonunda kullanýcý baþarýlý þekilde karþýt parça üretemediyse burada yaptýðý skor 0'lanýyor.
			skor = 0;
			skorlariKarsilastir("skordosyasi.txt",skor,kullanici);  // Her oyun sonunda elimdeki kullanýcýnýn skoru ile bundan önceki oyunlarda tuttuðum 5 en yüksek skoru karþýlaþtýrýp burdaki en yüksek 5 skoru tutan fonksiyon.
			break;
		}
		printf("\n Ana menuye donmek icin lutfen 1'i, cikmak icin baska bir tusu tuslayiniz : "); // Kullanýcýnýn ayný kullanýcý olarak oyunu tekrar tekrar oynayabilmesini saðlayan kod.(Yeni kullanýcý giriþi için çýkýp girmek lazým).
		scanf("%d",&yenidenKullanma);
	}while(yenidenKullanma == 1);
	
	return 0;
	
}

void swap(kullaniciSkor *a, kullaniciSkor *b) { // 6 kullaniciyi kiyaslayip selection sort ediyorum. Bunun icin call-by refference kullanan bir swap fonksiyonu.
    kullaniciSkor temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(kullaniciSkor *kullanicilar) {
	int i,j;
    for (i = 0; i < 5; i++) { 
        int maxIndex = i;
        for (j = i + 1; j < 6; j++) {
            if (kullanicilar[j].puan > kullanicilar[maxIndex].puan) {   // Klasik bir selection sort uygulamasý. Her adýmda büyükten küçüðe doðru sýralama yapýyor. maxÝndex burada iterasyonlardaki en büyük deðerin indisini tutuyor. 
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            swap(&kullanicilar[i], &kullanicilar[maxIndex]);
        }
    }
}

int skorlariKarsilastir(char *dosya,float skor, kullanici kullanici){
	FILE *ilkSkorlar = fopen(dosya,"r"); // Skorlarin tutuldugu dosyayi aciyoruz.
	if(ilkSkorlar == NULL){
		fclose(ilkSkorlar);
		FILE *skorlar = fopen(dosya,"w"); 
		int i;
    	for(i=0; i<5; i++){
    		fprintf(skorlar, "a 0\n"); // Eger dosya null'sa selectionSort fonksiyonuna düzgün bir þekilde dizimizi gönderebilmek için dosyanýn içine 0 olan 5 adet skor ve a isminde kullanýcý atýyoruz.
    	}
    	fclose(skorlar);
    	FILE *ilkSkorlar = fopen(dosya,"r"); // Dosya tekrardan okuma modunda açýlýyor.
	}
	kullaniciSkor kullanicilar[6]; // dosyadan diziye okuyup selection sort'ta diziyi sýralamak için 6 elemanlýk bir kullanýcýlar dizisi oluþturdum. Dizi kullaniciSkor structýndan 6 eleman tutuyor.
	int i=0; // Dizinin ilk elemanýndan itibaren eleman eklemek için kullandýðýmýz deðiþken.
	while (fscanf(ilkSkorlar, "%s %f", &kullanicilar[i].kullaniciAdi, &kullanicilar[i].puan) == 2) // Dosyadan kullanýcýlar dizisindeki her bir indisin kullaniciAdi ve puan degiskenlerine atama yapýlýyor.
	i++;
	kullaniciSkor kullanicii; // Dosyadan bundan önceki 5 en yüksek kullanýcýyý okuduk. Þimdi ise parametre olarak aldýðýmýz kullanýcýyý ve onun skorunu atamak için oluþturduðumuz geçici deðiþkeni oluþturuyoruz.
	strcpy(kullanicii.kullaniciAdi,kullanici.kullaniciAdi);
	kullanicii.puan = skor; // Skoru ve kullaniciadini kullanicii isimli deðiþkenimize atadýk.
	kullanicilar[5] = kullanicii; // Kullanýcýmýzý dizinin içine atadýk.
	selectionSort(kullanicilar); // Selection sort'a dizimizi yolladýk. 
	fclose(ilkSkorlar); 
	
	FILE *skorlar = fopen(dosya,"w");
	for (i = 0; i < 5; i++) {
        fprintf(skorlar, "%s %f\n", kullanicilar[i].kullaniciAdi, kullanicilar[i].puan); // Siralanmis dizinin ilk 5 elemanini en yuksek skor basta olmak uzere dosyamiza yaziyoruz.
    }
    fclose(skorlar);
}
void bosluklardanKurtarma(char **oyunAlani, int n,int *m){
	int i,j;
	for(i=0; i<n; i++)
	for(j=2; j<(*m); j+=2){
		oyunAlani[i][j/2] = oyunAlani[i][j];   // Eðer boþluklu bir þekilde oyun alaný verilmiþse 2'þerli bir þekilde ilerleyerek her elemaný bulunduðu indisin yarýsýna kaydýrarak oyun alanýný oynanabilir hale getiriyoruz.
	}
	(*m) = (*m) / 2; // Sütun sayýsýný yarýya bölüyoruz.
}

void kullaniciKoordinatBulma(char **oyunAlani,int *x,int *y,int m){
	int i=0,j=0;
	while(oyunAlani[i][j] != 'X'){ // Kullanýcýnýn indisini bulduðumuz fonksiyon.
		if(j==m){ // Satýr sonuna gelindiðinde alt satýra geçmek için kontrol.
			j=0;
			i++;
		}else
		j++;
	}
	*x = i;
	*y = j;
}

void txtdenOkuma(const char *dosyaAdi, char ***oyunAlani, int *n, int *m) {
    FILE *dosya = fopen(dosyaAdi, "r");
    if (dosya == NULL) {
        fprintf(stderr, "Dosya açilamadi.\n");
        exit(EXIT_FAILURE);
    }

    char buffer[100]; //Bir satýrý okuyacaðýz. Bu satýr için gerekli olan buffer deðiþkenimiz.
    int i;

    *n = 0; // Ýlk satýr ve sütun sayýsý deðerlerimizi 0'lýyoruz.
    *m = 0; //
    *oyunAlani = NULL;

    while (fgets(buffer, sizeof(buffer), dosya) != NULL) { // Bir satýrý okuyoruz.
        (*n)++; // Satýr sayýmýzý bir arttýrýyoruz.
        *oyunAlani = (char **)realloc(*oyunAlani, (*n) * sizeof(char *)); // Oyun alaný matrisini bir satýr geniþletiyoruz.
        if (*oyunAlani == NULL) {
            fprintf(stderr, "Bellek genisletme hatasi.\n");
            exit(EXIT_FAILURE);
        }

        (*m) = strlen(buffer); // sütun sayýsýný buffer deðiþkeninin uzunluðuna atýyoruz.
        (*oyunAlani)[*n - 1] = (char *)malloc((*m + 1) * sizeof(char));  // sütun sayýsý kadar yer açýyoruz satýra.

        if ((*oyunAlani)[*n - 1] == NULL) {
            fprintf(stderr, "Bellek tahsisi hatasi.\n");
            exit(EXIT_FAILURE);
        }

        strcpy((*oyunAlani)[*n - 1], buffer); // Açtýðýmýz satýra okuduðumuz satýrý yazýyoruz.
        
    }
    fclose(dosya);
}

int oncekilerleKiyas(const char *dosyaAdi, kullanici *kullanicim) {
    FILE *dosyaOkuma = fopen(dosyaAdi, "rb");
    if (dosyaOkuma == NULL) {
        fprintf(stderr, "Dosya acilamadi.\n");
        return -1; // Hata durumunu belirtmek için -1 döndürülüyor.
    }
	
    kullanici kullaniciTmp;
	fseek(dosyaOkuma, 0, SEEK_SET);
    while (fread(&kullaniciTmp, sizeof(kullanici), 1, dosyaOkuma) == 1) { // Kullanýcý bilgilerinin tutulduðu .bin uzantýlý dosyayý okuyup burdaki veriyi kullanýcý structý olarak okuyup kullanýcýtmp deðiþkenine atýyoruz.
    	
        if ( strcmp(kullaniciTmp.kullaniciAdi,kullanicim->kullaniciAdi) == 0)  { // Satýrdan okuduðumuz deðiþkenimizin kullanýcý adýyla kontrol etmek için parametre olarak yolladýðýmýz kullanýcý deðiþkeninin kullanýcý isimlerini kýyaslýyoruz.
            fclose(dosyaOkuma);
            return 1; // Eslesme bulundu
        }
    }
    fclose(dosyaOkuma);
    return 0; // Eslesme bulunamadi
}

int sifreDenemesi(const char *dosyaAdi, kullanici *kullanicim){
	FILE *dosyaOkuma = fopen(dosyaAdi, "rb");
    if (dosyaOkuma == NULL) {
        fprintf(stderr, "Dosya acilamadi.\n");
        return -1; // Hata durumunu belirtmek için -1 döndürülebilir
    }
	
    kullanici kullaniciTmp;
    
	fseek(dosyaOkuma, 0, SEEK_SET);
    while (fread(&kullaniciTmp, sizeof(kullanici), 1, dosyaOkuma) == 1) {
    	
        if ( strcmp(kullaniciTmp.kullaniciAdi,kullanicim->kullaniciAdi) == 0 && strcmp(kullaniciTmp.sifre,kullanicim->sifre) == 0 )  { // Sifre verilerini yukaridaki kullaniciadi kiyasi gibi kiyaslayip duruma gore 0 ya da 1 donduruyoruz.
            fclose(dosyaOkuma);
            return 1; // Eslesme bulundu
        }
    }
    fclose(dosyaOkuma);
    return 0; // Eslesme bulunamadi
}

kullanici kullaniciOlusturma(const char *dosyaAdi){
	FILE *dosyaYazma = fopen(dosyaAdi, "ab");
	if(dosyaYazma == NULL){
		printf("Dosya acilamadi..");
		//return -1;
	}
		char gecici[50];
		kullanici kullanicim;
		printf("Kullanici ismi: ");
		scanf("%s",&gecici);
		strcpy(kullanicim.isim,gecici);
		printf("Kullanici soyismi: ");
		scanf("%s",&gecici);                                // Kullanicidan bilgilerini istiyoruz.
		strcpy(kullanicim.soyisim,gecici);
		int flag=1;
		do{
		printf("Kullanici adi: ");
		scanf("%s",&gecici);
		strcpy(kullanicim.kullaniciAdi,gecici);                  //Kullanici olustururken eþsiz bir kullanýcý adý girene kadar kullanýcýdan kullanýcý adý istiyoruz.
		if (oncekilerleKiyas(dosyaAdi, &kullanicim)) {
        	printf("Ayni kullanici bulundu. Tekrar deneyin.\n");
			flag=0;
    	}
		else{
			flag=1;      
		}}while(flag==0);
		printf("Lutfen sifrenizi girin: ");
		scanf("%s",&gecici);
		strcpy(kullanicim.sifre,gecici);
		fwrite(&kullanicim, sizeof(kullanici), 1, dosyaYazma);                    //Kullanýcýnýn bilgilerini struct þekilde dosyaya yazýyoruz.
		printf("Yeni kullanici kaydi basariyla gerceklesti!\n");
		fclose(dosyaYazma);
		return kullanicim;	
}

kullanici girisYapma(const char *dosyaAdi){
	FILE *dosyaOkuma = fopen(dosyaAdi, "rb");   // Kullanýcý bilgilerini tuttuðumuz dosyayý binary okuma modunda açýyoruz.
	char gecici[50];
	char sifre[50];                    //Geçici deðiþkenlerimiz. 
	int flag;
	kullanici girisYapma;              //Kontrol edeceðimiz ve eðer doðru giriþ saðlanýrsa return edeceðimiz kullanýcý.
	do{
		printf("Lutfen giris yapmak istediginiz kullanici adinizi girin: ");    
		scanf("%s",&gecici);
		strcpy(girisYapma.kullaniciAdi,gecici);
		if (oncekilerleKiyas(dosyaAdi, &girisYapma)) {                        // Kullanýcýdan aldýðýmýz kullanýcý adýný kontrol ediyoruz. 
        	//printf("Kullanici bulundu..\n");
			flag=1;
    	}
		else{
			printf("Bu kullanici adi ile kayit olunmamistir. Lutfen kullanici adinizi kontrol ediniz..\n");  //Kullanýcýya döndürdüðüm hata mesajý.
			flag=0;
		}}while(flag==0);
	flag=1;
	do{
		printf("Lutfen sifrenizi girin: ");    
		scanf("%s",&sifre);
		strcpy(girisYapma.sifre,sifre);
		if (sifreDenemesi(dosyaAdi, &girisYapma)) { //Denenecek olan þifreyi fonksiyonumuza gönderiyoruz.
        	printf("Sifreniz dogru..\n");
			flag=0;
    	}
		else{
			printf("Yanlis sifre..\n");
			flag=1;
		}}while(flag==1);
		printf("Giris yapma islemi basariyla gerceklesti!");
		return girisYapma;   //Kullanýcýyý return ediyoruz.
		
}



void oyunAlaniBastirma(char **oyunAlanim, int n, int m){
    printf("---------Oyun Alaniniz---------\n\n");
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
        	if(oyunAlanim[i][j] == 'X'){
        		printf("\033[1;33m%c\033[0m ", oyunAlanim[i][j]); 
			}
			else if(oyunAlanim[i][j] == 'K'){
				printf("\033[1;31m%c\033[0m ",oyunAlanim[i][j]);
			}
			else if(oyunAlanim[i][j] == 'C'){
				printf("\033[1;34m%c\033[0m ",oyunAlanim[i][j]);
			}
			else if (oyunAlanim[i][j] == 'P' || oyunAlanim[i][j] == 'p') {
			    printf("\033[1;35m%c\033[0m ", oyunAlanim[i][j]); 
			}
			else if (oyunAlanim[i][j] == 'E' || oyunAlanim[i][j] == 'e') {
    			printf("\033[1;36m%c\033[0m ", oyunAlanim[i][j]); 
			}
			else{
            printf("%c ", oyunAlanim[i][j]);
        }
    }
        printf("\n");
    }
}

void toplananParcacikGosterme(char *parcaciklar, int *parcacikSayisi) {
    int i;
    
    if (*parcacikSayisi != 0) { //Parcaciklar toplandiktan sonra kulanicinin gormesi icin bastirilacak 
        printf("Toplanan Parcaciklar:\n"); //En az 1 parcacikl toplandiktan sonra kulanicinin gormesi icin bastirilacak 
        

        for (i = 0; i < *parcacikSayisi; i++) {
            switch (parcaciklar[i]) {
                case 'p':
                    printf("P- ");
                    break;
                case 'P':
                    printf("P+ ");
                    break;
                case 'e':
                    printf("e- ");
                    break;
                case 'E':
                    printf("e+ ");
                    break;
                default:
                    break;
            }
        }
        printf("\n");
    }
}




float hamleYapma(char **oyunAlani, int n, int m, int *x, int *y, int *flag, char *parcaciklar,int *parcacikSayisi,int xcpy,int ycpy,time_t *baslangicZamani) {
    system("cls");   //Her hamlede ekran sifirlanir.
    float skor=0; //Skoru sifirliyorum.
	if(xcpy != *x || ycpy != *y) 
	oyunAlani[xcpy][ycpy] = 'G';  //Kullaniciya baslangic noktasini gostermek icin baslangic koordinatlarini G yaptim.
	
    oyunAlaniBastirma(oyunAlani, n, m); //Oyun alanini bastiriyorum.
	toplananParcacikGosterme(parcaciklar,parcacikSayisi);
	time_t simdikiZaman = time(NULL);   //Ýlk hmaleden bu yana ne kadar zaman geçtiðini hesaplamak için zamaný baþlatýyorum.
    int gecenSure = difftime(simdikiZaman, *baslangicZamani);
    int kalanSure = 120 - gecenSure; 
    printf("\n\n Kalan sureniz : %d\n",kalanSure); //Kullanýcýya ne kadar suresý kaldýgýný gosteriyorum.
    if(gecenSure > 120){
    	printf("Size ayrilan sure icerisinde oyunu tamamlayamadiniz! Ana ekrana donduruluyorsunuz.."); // Süre doldu.
    	*flag = 6;
	}
	printf("\nLutfen hamlenizi yapiniz..");
    
    
	char a = getch(); //Kullanýcýdan yaptýðý tuþ hamlesini alýyoruz.

    if (a == 77){
    	if(!(oyunAlani[*x][(*y)+1] == '1' || (*y) == m-1 )){ //Sýnýr ve 1(Duvar) Kontrolü
        	skor = sagaHamle(oyunAlani, x, y,parcaciklar,parcacikSayisi,flag); 
			}
		}
    else if (a == 75){
    	if(!(oyunAlani[*x][(*y)-1] == '1' || (*y) == 0 )){
        	skor = solaHamle(oyunAlani, x, y,parcaciklar,parcacikSayisi,flag);
			}
		}
    else if (a == 72){
    	if(!(oyunAlani[(*x)-1][(*y)] == '1' || (*x) == 0 )){
        skor = yukariHamle(oyunAlani, x, y,parcaciklar,parcacikSayisi,flag); //Basýlan tuþa göre hamleler.
		}
	}
    else if (a == 80){
    	if(!(oyunAlani[(*x)+1][(*y)] == '1' || (*x) == n-1 )){
        skor = asagiHamle(oyunAlani, x, y,parcaciklar,parcacikSayisi,flag);
		}
	}
    else if (a == 27) { //Kullanýcý esc tuþuna basarsa çýkýþ.
        printf("\n OYUNDAN CIKILIYOR... ");
        (*flag)=6;
    }
    
    if(skor != 0){
    	if(skor == -1){
    	(*flag)=6;} //Oyunu bitirme.
    	if(skor > 0){
    		(*flag)=6;
    			time_t gecenSuree = difftime(simdikiZaman, *baslangicZamani);
    			if(skor < 10){
    				skor = (skor * 80 / 100)  +  ((float)(120-gecenSuree) * 20 / 10000) * 10 * (m * n / 20); //Kullanýcýnýn yaptýðý skor.
    				printf("\n\nSkor degerin: %f",skor);}
			return skor;
    		
	}
}
     sleep(0.1);
}

void parcacikDizisiGuncelleme(char *parcaciklar,int *parcacikSayisi,char parcacik){
	(*parcacikSayisi)++;
	char *gecici;
	parcaciklar = realloc(parcaciklar, (*parcacikSayisi) * sizeof(char)); //Dizinin boyutunu arttýrýp elde edilen parçacýðý sonuna ekliyoruz.
	parcaciklar[(*parcacikSayisi)-1] = parcacik; 
	
}


float sagaHamle(char **oyunAlani,int *x,int *y,char *parcaciklar,int *parcacikSayisi,int *flag){
	float skor;
	oyunAlani[*x][*y] = '0'; //Kullanýcýnýn hamleden önceki bulunduðu yeri 0 yapýyoruz.
 	(*y)++;
 	if(oyunAlani[*x][*y] == 'K'){
 		karadeligeUlasildi(flag); //Karadeliðe ulaþýldý.
 		return -1;
	 }
	 else if(oyunAlani[*x][*y] == 'C'){      
 		skor = oyunSonu(parcaciklar,parcacikSayisi,flag); //Oyunu bitiriyoruz çýkýþa ulaþýldýysa.
 		return skor;
	 }
	 else if(oyunAlani[*x][*y] != '0' && oyunAlani[*x][*y] != 'G' && oyunAlani[*x][*y] != 'X'){    //Eðer parçacýk toplandýysa burada parçacýk dizisini güncelliyoruz.
 		parcacikDizisiGuncelleme(parcaciklar,parcacikSayisi,oyunAlani[*x][*y]);
	 }
 	oyunAlani[*x][*y] = 'X';   //Kullanýcýnýn olduðu yeri(hamleden sonraki) X yapýyoruz.  Ayný þeyler diðer tüm hamleler için geçerli.
 	return 0;
}
void karadeligeUlasildi(int *flag){
	system("cls");
	printf("Karadelige ulasildigi icin oyun sonlandirilmistir!");  //Karadeliðe ulaþýldý uyarýsý.
}

float solaHamle(char **oyunAlani,int *x,int *y,char *parcaciklar,int *parcacikSayisi,int *flag){
	float skor;
	oyunAlani[*x][*y] = '0';
 	(*y)--;
 	if(oyunAlani[*x][*y] == 'K'){
 		karadeligeUlasildi(flag);
 		return -1;
	 }
	 else if(oyunAlani[*x][*y] == 'C'){
 		skor = oyunSonu(parcaciklar,parcacikSayisi,flag);    //Buradaki gerekli yorum satýrlarý saða hamlede yazýlmýþtýr.
	 	return skor;
	 }
 	else if(oyunAlani[*x][*y] != '0' && oyunAlani[*x][*y] != 'G' && (oyunAlani[*x][*y] != 'X')){
 		parcacikDizisiGuncelleme(parcaciklar,parcacikSayisi,oyunAlani[*x][*y]);
	 }
 	oyunAlani[*x][*y] = 'X';
 	return 0;
}

float asagiHamle(char **oyunAlani,int *x,int *y,char *parcaciklar,int *parcacikSayisi,int *flag){
	float skor;
	oyunAlani[*x][*y] = '0';
 	(*x)++;
 	if(oyunAlani[*x][*y] == 'K'){
 		karadeligeUlasildi(flag);
 		return -1;
	 }
	 else if(oyunAlani[*x][*y] == 'C'){
 		skor = oyunSonu(parcaciklar,parcacikSayisi,flag);       //Buradaki gerekli yorum satýrlarý saða hamlede yazýlmýþtýr.
 		return skor;
	 }
 	else if(oyunAlani[*x][*y] != '0' && oyunAlani[*x][*y] != 'G' && (oyunAlani[*x][*y] != 'X')){
 		parcacikDizisiGuncelleme(parcaciklar,parcacikSayisi,oyunAlani[*x][*y]);
	 }
 	oyunAlani[*x][*y] = 'X';
 	return 0;
}

float yukariHamle(char **oyunAlani,int *x,int *y,char *parcaciklar,int *parcacikSayisi,int *flag){
	float skor;
	oyunAlani[*x][*y] = '0';
 	(*x)--;
 	if(oyunAlani[*x][*y] == 'K'){
 		karadeligeUlasildi(flag);
 		return -1;
	 }
	 else if(oyunAlani[*x][*y] == 'C'){
 		skor = oyunSonu(parcaciklar,parcacikSayisi,flag);   //Buradaki gerekli yorum satýrlarý saða hamlede yazýlmýþtýr.
		return skor;	 
	 }
 	else if(oyunAlani[*x][*y] != '0' && oyunAlani[*x][*y] != 'G' && (oyunAlani[*x][*y] != 'X')){
 		parcacikDizisiGuncelleme(parcaciklar,parcacikSayisi,oyunAlani[*x][*y]);
	 }
 	oyunAlani[*x][*y] = 'X';
	return 0;
}

float oyunSonu(char *parcaciklar,int *parcacikSayisi,int *flag){
	system("cls");
	printf("Oyununuz basarili bir sekilde sonlandi..");
	int i,psayisi=0,Psayisi=0,esayisi=0,Esayisi=0,skor=1600;
	for(i=0; i<(*parcacikSayisi); i++){
		if(parcaciklar[i] == 'p')
		psayisi++;
		else if(parcaciklar[i] == 'P')    //Kullanýcýnýn topladýðý parçacýklar dizisinde gezilerek parçacýk tespit edilmiþ ve sayýsý arttýrýlmýþtýr.
		Psayisi++;
		else if(parcaciklar[i] == 'e')
		esayisi++;
		else if(parcaciklar[i] == 'E')
		Esayisi++;
	}
	printf("Topladiginiz toplam parcacik sayisi : %d\np- sayisi: %d\np+ sayisi: %d\ne-sayisi: %d\ne+ sayisi: %d\n",psayisi+Psayisi+esayisi+Esayisi,psayisi,Psayisi,esayisi,Esayisi);  //Kullanýcýya topladýklarý parçacýklar hakkýnda bilgi veriliyor.
	psayisi = psayisi - Psayisi;
	Esayisi = Esayisi - esayisi;
	if (psayisi <= 0 || Esayisi <= 0)      //Eðer e+ sayýsý e- sayýsýndan az ya da eþitse veya p- sayýsý p+ sayýsýndan az ya da eþitse karþýt madde üretilemiyor.
	printf("Karsit madde uretilemedi.");
	else if(psayisi > Esayisi){  //Eðer p- sayisi daha fazlaysa E+ sayýsý kadar karþýt madde üretilir.
	printf("%d adet karsit madde uretildi.",Esayisi);
	skor = Esayisi;
	}else{ 
		printf("%d adet karsit madde uretildi.",psayisi);  //Eðer e+ sayisi daha fazlaysa p- sayýsý kadar karþýt madde üretilir.
		skor = psayisi;
	}
	return skor;  //Kullanýcýya e+ sayýsý ya da p- sayýsý kadar skor döndürülür.
}

void oyunuBaslat(time_t *baslangicZamani) {
    *baslangicZamani = time(NULL);    //Oyunu baþlatýrken zamaný ölçmeye yarayan baþlangýç.
}

void skorlariBastir(char *dosya){
	FILE *skordosyasi = fopen(dosya,"r");  //Skorlarý tuttuðumuz dosyayý açýyoruz.
	if(skordosyasi == NULL)
	printf("\nHenuz 0'dan yuksek puan alan cikmadi :( \n");
	kullaniciSkor kullanicilar[5];   //Dosyadan verileri okumak için oluþturulan geçici dizi.
	int i=0;
	while (fscanf(skordosyasi, "%s %f", &kullanicilar[i].kullaniciAdi, &kullanicilar[i].puan) == 2){
		if(kullanicilar[i].puan > 0) //Skoru 0'dan büyük olan kullanýcýlarý ekrana yazdýrýyoruz.
		printf("%d. Kullanicinin Skoru : %f, Kullanici Adi: %s\n",i+1,kullanicilar[i].puan,kullanicilar[i].kullaniciAdi);
		i++;
	}
}
void bilgileriGoster(){  // Kullanýcýya oyunla ilgili bilgileri ve kurallarý gösteriyoruz.
	system("cls");
	printf("1. Labirentteki yollarda asagidaki parcaciklar bulunmaktadir.\n P+ : proton\ne- : elektron\nP- : karsit proton \ne+ : karsit elektron\n");
	printf("2. Karsit hidrojen uretebilmek icin labirentin cikisinda elinizde sadece P- ve e+ parcaciklari bulunmalidir.\n3. Bir parcacikla o parcacigin zit isaretli karsit parçacigi bir araya gelirse birbirini yok eder.\n");
	printf("4. Karadelikler K ile gosterilmistir. Karadeliklerin bulundugu hucrelerden gecildigi takdirde oyun sonlanir.\n5. 120 saniye(2 dakika) icinde kullanici cikisa ulasamazsa oyun sonlanir.");
	printf("6. 0 ile gosterilenler yol, 1 ile gosterilenler ise duvardir. Duvarlardan gecemezsiniz ve eger sinirlarda hamle yapmaya calisirsaniz hamleniz basarisiz olur.\n");
}
