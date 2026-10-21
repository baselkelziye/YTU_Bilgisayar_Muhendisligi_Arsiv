#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 15

void matrisYazdir(int matris[][MAX], int N);
int dosyadanOku(int matris[][MAX], char *dosyaAdi);
void matrisSifirla(int matris[][MAX], int N);
void rastgeleMatrisOlustur(int matris[][MAX], int N);
int manuelOyna(int matris[][MAX], int N);
int manuelHamle(int matris[][MAX], int N, int x1, int y1, int x2, int y2, int* gecerliMi);
int boslukKontrol(int matris[][MAX], int N);
void skorHesapla(int skorlar[][MAX], int oyuncu);
void skorYazdir(int skorlar[][MAX], char kullanici[][MAX],int oyuncu);
void matrisKopyala(int matris[][MAX], int kopya[][MAX], int N);
void oyunHakkinda();

int main(){
    int matris[MAX][MAX]={{0}};
	char kullanici[MAX][MAX];
	int skorlar[MAX][MAX];
	int secim;
	int secimOyun;
	int oyuncu=0;
    int N;
    int tamamlandi;
    char dosyaAdi[20];
    clock_t sure; 

    oyunHakkinda();
	do{
		printf("\n  -- -- --  ANA MENU  -- -- --  \n");
		printf("1: Yeni Oyuncu\n");
		if(oyuncu>0){
			printf("2: Kullanici Skorlarini Goster\n");
		}
		printf("0: Cikis\n");
		printf("Seciminiz: ");
		scanf("%d",&secim);

		switch(secim){
			case 1:
				printf("Kullanici adi giriniz: ");
				scanf("%s",kullanici[oyuncu]);
				printf("'%s' olarak oynuyorsunuz.\n",kullanici[oyuncu]);
                skorlar[oyuncu][4] = 0;
				do{
					printf("\n  --  Oyun Menusu  --  \n");
					printf("1: Rastgele Matris Olustur\n");
					printf("2: Dosyadan Matris Olustur\n");
					printf("3: Kullanici Skorlarini Goster\n");
					printf("0: Ana Menuye Don\n");
					printf("Seciminiz: ");
					scanf("%d",&secimOyun);

					switch(secimOyun){
						case 1:
                            skorlar[oyuncu][2] = 1;
							printf("Matris boyutunu giriniz: ");
							scanf("%d",&N);
                            while(N<2){
                                printf("Matris boyutu 1'den buyuk olmalidir. Matris boyutunu yeniden giriniz: ");
							    scanf("%d",&N);
                            }
                            skorlar[oyuncu][0] = N;
							rastgeleMatrisOlustur(matris,N);
                            sure = clock();
							tamamlandi = manuelOyna(matris,N);
                            sure = clock() - sure;
                            skorlar[oyuncu][1] = sure / CLOCKS_PER_SEC;
                            if(tamamlandi){
                                skorHesapla(skorlar,oyuncu);
                            }                            
							matrisSifirla(matris,N);
							break;
						case 2:
                            skorlar[oyuncu][2] = 0;
							printf("Dosya Adini Giriniz: ");
  							scanf("%s",dosyaAdi);
  							N = dosyadanOku(matris,dosyaAdi);
  							if(N>0){
  								skorlar[oyuncu][0] = N;
  								sure = clock();
								tamamlandi = manuelOyna(matris,N);
                            	sure = clock() - sure;
                            	skorlar[oyuncu][1] = sure / CLOCKS_PER_SEC;
                            	if(tamamlandi){
                                    skorHesapla(skorlar,oyuncu);
                                } 
								matrisSifirla(matris,N);
							}		
							break;
						case 3:
							skorYazdir(skorlar,kullanici,oyuncu);
							break;
						case 0:
							printf("Ana menuye donuluyor...\n");
							break;
						default:
							printf("Hatali secim yaptiniz!\n\n");
					}
				}while(secimOyun);
				oyuncu++;
				break;
			case 2:
				if(oyuncu>0){
					skorYazdir(skorlar,kullanici,oyuncu-1);
				}
				else{
					printf("Hatali secim yaptiniz!\n\n");
				}
				break;
			case 0:
				printf("Cikis yapiliyor...");
				break;
			default:
				printf("Hatali secim yaptiniz!\n\n");
		}
	}while(secim);

	return 0;
}

// Girilen dosyadan matrisi alir ve cikti olarak matrisin boyutunu verir.
int dosyadanOku(int matris[][MAX], char *dosyaAdi){
	int i,j,temp;
	int N=0;
	FILE *data = fopen(dosyaAdi,"r");
	if(!data){
        printf("Dosya Acilamadi!\n");
		return 0;
    }
    while(!feof(data)){
        fscanf(data,"%d %d %d\n",&i,&j,&temp);  
		matris[i][j]=temp;
		N++;   // Dosyadan okunan matrisin boyutunu hesaplar ve fonksiyon ciktisi olarak verir
    }  
  	fclose(data);
  	return N/2;
}

// Girilen NxN'lik matrisi yazdirir.
void matrisYazdir(int matris[][MAX], int N){
    int i,j,k;
    printf("\n      ");
    for(k=0;k<N;k++)
            printf("  %d   ",k);
    for(i=0;i<N;i++){
        printf("\n     -");
        for(k=0;k<N;k++)
            printf("------");
        printf("\n  %d  |",i);
        for(j=0;j<N;j++)
            if(matris[i][j]!=0)
                printf("  \033[1;3%dm%d\033[0m  |",matris[i][j]%8,matris[i][j]);
            else
                printf("     |");
    }
    printf("\n     -");
    for(k=0;k<N;k++)
        printf("------");
    printf("\n");
}

// Oyun oynandiktan sonra girilen NxN'lik matrisin tum elemanlarini sifirlar.
void matrisSifirla(int matris[][MAX], int N){
	int i;
	int j;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			matris[i][j] = 0;
		}
	}
}

// Girilen NxN'lik matrisin boyut sayisi kadar sayi ciftini matrise rastgele yazar.
void rastgeleMatrisOlustur(int matris[][MAX], int N){
	int i;
	int j;
	int rastgeleSatir;
	int rastgeleSutun;
	
	srand(time(0));
	i=0;
	while(i<N*2){
		rastgeleSatir = rand()%N;
        rastgeleSutun = rand()%N;
        j=1;
        while(j){
			if(matris[rastgeleSatir][rastgeleSutun]!=0){
				rastgeleSatir = rand()%N;
        		rastgeleSutun = rand()%N;
			}
			else{
				j=0;
			}	
		}
		matris[rastgeleSatir][rastgeleSutun] = (i/2)+1;
		i++;
	}
}

// Matris olusturulduktan sonra oyunu manuel olarak oynatir.
int manuelOyna(int matris[][MAX], int N){
    int matrisYedek[5][MAX][MAX];
    int birlesme=0;
    int tamamlandi=1;
    int sonuc[MAX*MAX];
    int hamle=1;
    int geriHamle=0;
    int x1,y1,x2,y2;
    int gecerli;
	
	matrisKopyala(matris,matrisYedek[0],N);
    do{
        gecerli = 0;
        matrisYazdir(matris,N);
        printf("Baslangic noktasinin koordinatlarini giriniz (satir,sutun) : ");
        scanf("%d",&x1);
        if(x1 == -1){
            if(hamle>1){
            	if(geriHamle>0){
            		if(geriHamle>4){
            			geriHamle = 4;
					}
            		matrisKopyala(matrisYedek[(hamle-2)%5],matris,N);
                	hamle--;
                	geriHamle--;
                	if(sonuc[hamle]){
                		birlesme--;                		
					}
				}
				else{
					printf("Daha fazla geri hamle yapamazsiniz!\n");
				}                
            }
            else{
                printf("Oncelikle hamle yapmalisiniz!\n");
            }
        }
        else if(x1 == -2){
            printf("Oyun sonlandiriliyor...\n");            
            return 0;
        }
        else{
            scanf("%d",&y1);
            printf("Varis noktasinin koordinatlarini giriniz (satir,sutun)     : ");
            scanf("%d%d",&x2,&y2);
            sonuc[hamle] = manuelHamle(matris,N,x1,y1,x2,y2,&gecerli);
            if(gecerli){
                birlesme = birlesme + sonuc[hamle];
				printf("Eslestirilen nokta sayisi: %d",birlesme);                
                if(birlesme==N && boslukKontrol(matris,N)){
                    tamamlandi = 0;
                    matrisYazdir(matris,N);
                }
                else{
                    matrisKopyala(matris,matrisYedek[hamle%5],N);
                    hamle++;
                    geriHamle++;
                }                
            }            
        }
    }while(tamamlandi);
    return 1;
}

// manuelOyna() fonksiyonundan aldigi baslangic ve varis noktlarinin birlesimini kontrol eder,
// birlesebiliyorsa birlestirir ve cikti olarak birlesim durumuna gore 1 ya da 0 verir.
int manuelHamle(int matris[][MAX], int N, int x1, int y1, int x2, int y2, int* gecerliMi){
    int i;
    int gecerli = 1;
    int birlestiMi = 0;
    int nokta;

    if(x1<N && y1<N && x2<N && y2<N){
        if(matris[x1][y1]>0){
            if((x1==x2 && y1!=y2) || (x1!=x2 && y1==y2)){
                nokta = matris[x1][y1];
                if(x1==x2){                    
                    if(y1<y2){
                        i=y1+1;
                        while(i<=y2 && gecerli){
                            if(matris[x1][i]!=0){
                                gecerli = 0;
                            }
                            else{
                                i++;
                            }
                        }
                        if(i==y2 && matris[x1][i]==nokta){
                            gecerli = 1;
                            birlestiMi = 1;
                        }
                        if(gecerli){
                            for(i=y1+1;i<=y2;i++){
                                matris[x1][i] = nokta;
                            }
                            *gecerliMi = 1;                           
                        }
                        else{
                            printf("Hatali hamle yaptiniz!\n");
                        }                        
                    }
                    else{
                        i=y1-1;
                        while(i>=y2 && gecerli){
                            if(matris[x1][i]!=0){
                                gecerli = 0;
                            }
                            else{
                                i--;
                            }
                        }
                        if(i==y2 && matris[x1][i]==nokta){
                            gecerli = 1;
                            birlestiMi = 1;
                        }
                        if(gecerli){
                            for(i=y1-1;i>=y2;i--){
                                matris[x1][i] = nokta;
                            }
                            *gecerliMi = 1;                            
                        }
                        else{
                            printf("Hatali hamle yaptiniz!\n");
                        }
                    }
                }
                else{
                    if(x1<x2){
                        i=x1+1;
                        while(i<=x2 && gecerli){
                            if(matris[i][y1]!=0){
                                gecerli = 0;
                            }
                            else{
                                i++;
                            }
                        }
                        if(i==x2 && matris[i][y1]==nokta){
                            gecerli = 1;
                            birlestiMi = 1;
                        }
                        if(gecerli){
                            for(i=x1+1;i<=x2;i++){
                                matris[i][y1] = nokta;
                            }
                            *gecerliMi = 1;                            
                        }
                        else{
                            printf("Hatali hamle yaptiniz!\n");
                        }
                    }
                    else{
                        i=x1-1;
                        while(i>=x2 && gecerli){
                            if(matris[i][y1]!=0){
                                gecerli = 0;
                            }
                            else{
                                i--;
                            }
                        }
                        if(i==x2 && matris[i][y1]==nokta){
                            gecerli = 1;
                            birlestiMi = 1;
                        }
                        if(gecerli){
                            for(i=x1-1;i>=x2;i--){
                                matris[i][y1] = nokta;
                            }
                            *gecerliMi = 1;                        
                        }
                        else{
                            printf("Hatali hamle yaptiniz!\n");
                        }
                    }                    
                }
            }
            else{
                printf("Birlestireceginiz noktalar dikey ya da yatay eksende olmalidir!\n");
            }
        }
        else{
            printf("Hatali nokta sectiniz!\n");
        }            
    }
    else{
        printf("Matriste olmayan bir nokta girdiniz!\n");
    }
    return birlestiMi;
}

// Tum sayilar birlestikten sonra oyunun sonlanmasi icin gerekli olan bosluk kontrolunu yapar,
// eger bosluk bulunuyorsa 0, bulunmuyorsa 1 ciktisini verir.
int boslukKontrol(int matris[][MAX], int N){
    int i,j;
    i=0;
    while(i<N){
        j=0;
        while(j<N){
            if(matris[i][j]==0){
                return 0;
            }
            j++;
        }
        i++;
    }
    return 1;
}

// Oyun basarili bir sekilde tamamlandiktan sonra oyunun puanini hesaplar ve ekrana yazdirir.
void skorHesapla(int skorlar[][MAX], int oyuncu){
    /*  
        0. sutun: Matris boyutu
        1. sutun: Oyunun tamamlanma suresi
        2. sutun: Rastgele/Dosyadan Matris
        3. sutun: Kullanicinin oyun sonunda kazandigi skor
        4. sutun: Kullanicinin toplam skoru
    */

    int skor=0;

    skor += skorlar[oyuncu][0]*200;
    skor -= (skorlar[oyuncu][1]*20) / skorlar[oyuncu][0];
    if(skorlar[oyuncu][2]){
        skor *= 1.2;
    }
    skorlar[oyuncu][3] = skor;
    skorlar[oyuncu][4] += skor;
    
    printf("Tebrikler, oyunu %d saniyede tamamladiniz!\n",skorlar[oyuncu][1]);
    printf("Oyunu tamamlayarak %d puan kazandiniz ve toplamda %d puaniniz var!\n",skorlar[oyuncu][3],skorlar[oyuncu][4]);
}

// Tum oyuncularin puanini ekrana yazdirir.
void skorYazdir(int skorlar[][MAX], char kullanici[][MAX],int oyuncu){
    int i;
    printf("\n  -- --  Kullanici Skorlari  -- --  \n");
    for(i=0;i<=oyuncu;i++){
        printf("'%s' adli kullanicinin %d puani var.\n",kullanici[i],skorlar[i][4]);
    }
}

// Geri hamle islemini yapabilmek icin matris'i kopya'ya yedekler.
void matrisKopyala(int matris[][MAX], int kopya[][MAX], int N){
    int i,j;

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            kopya[i][j] = matris[i][j];
        }
    }
}

// Oyun basinda kullaniciya oyun hakkinda bilgi verir.
void oyunHakkinda(){
    printf("\n  -- -- -- -- -- -- -- --  Oyun Hakkinda  -- -- -- -- -- -- -- --  \n");
    printf("\n-> Geri hamle icin '-1' tuslanmalidir.\n");
    printf("   Baslangic noktasinin koordinatlarini giriniz (satir,sutun) : -1\n");
    printf("\n-> Oyunu bitirmeden sonlandirmak icin '-2' tuslanmalidir.\n");
    printf("   Baslangic noktasinin koordinatlarini giriniz (satir,sutun) : -2\n");
    printf("\n-> Puan hesaplamasi asagidaki sekilde yapilmaktadir.\n");
    printf("        N   x 200\n");
    printf("     Sure/N x 20 \n");
    printf("   - ____________\n");
    printf("         Puan    \n");
    printf("   Matris rastgele olusturulduysa puan '1.2' ile carpilir.\n");
    printf("\n-> Oyun sadece manuel modda oynanmaktadir.\n");
}
