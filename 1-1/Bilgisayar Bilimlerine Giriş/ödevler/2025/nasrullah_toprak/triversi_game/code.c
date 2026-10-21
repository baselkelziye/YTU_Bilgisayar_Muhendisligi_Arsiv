#include <stdio.h>

int main() {
	
	/*
	N: matrisin satir & sutun sayisi
	i,j,m,n,p,q: donguler icin kullilacak degiskenker.
	x ve y: kullanici (oyunucu) tarafindan girilecek koordinatlar ([1-N] arasi).
	v ve w: A matrisin indisleri [0,N-1] oldugu icin v=x-1 ve w=y-1 olacak sekilde: A[v][w].
	orta1 ve orta2: Oyuna basliyacak olan ilk oyuncunun oyunun ortasindan baslamsi icin kullanilan degisken.
	ctrl: while dongusunden cikmak icin kullanilacak degisken (flag).
	sayac = N*N: sayacin hedefi oyunu sona varildigini anlamak.
	kirmizisayac, sarisayac, mavisayac: oyun tamamlandiginda her bir oyuncunun kac tane tasinin oldugunu saymak.
	renk: Sirasiyla her bir oyuncunun rengi (K->S->M->K->S->M->..) ve renge bagli yatay/dikey/capraz kontroller.
	*/
	int N,i,j,x,y,v,w,m,n,p,q;
	int orta1, orta2, ctrl=0, renk_degisim=0;
	int sayac, kirmizisayac=0, sarisayac=0, mavisayac=0;
	char A[23][23], renk;
	
	//Kullanicidan Matrisin Satir/Sutun talebi (Eger N<=0 veya N>23 tekrar kullanicidan talebi)
	printf("1. Oyuncu -> Kirmizi (K)\n2. Oyuncu -> Sari (S)\n3. Oyuncu -> Mavi (M)\n\n");
	printf("Triversi oyunu icin kare tahtanin satir/sutun sayisini giriniz: ");
	scanf("%d", &N);
	
	while (N<3 || N>23){
		printf("Kare tahtanin boyutu 3-23 arasinda olmalidir. Tekrar kare tahtanin satir sayisini giriniz: ");
		scanf("%d",&N);
	}
	
	//Bos kare tahtayi (N*N) yazdirma
	printf("\nBaslangic Kare Tahtasi: \n");
	for (i=0;i<N;i++){
		for(j=0;j<N;j++){
			A[i][j]='-';
			printf("%c ",A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	//ilk oyuncu oyunu ortadan basliyacak (Eger N tek ise sadece oyun karenin sadece 1 tane ortasi var... N cift ise oyun karenin birden fazla orta yeri var)
	i=0;
	printf("%d. Oyuncu (K) rengi icin hamlenizi yapiniz: \nx ve y koordinatlari tahtanin ortasinda olacak sekilde giriniz: ",(i%3)+1);
	scanf("%d %d",&x,&y);
	if (N%2!=0){
		orta1=(N/2)+1;
		orta2=orta1;
	}
	else{
		orta1=(N/2);
		orta2=(N/2)+1;
	}
	
	while (x<orta1 || x>orta2 || y<orta1 || y>orta2){
		printf("x ve/veya y degerleri hatali tekrar giriniz: ");
		scanf("%d %d",&x, &y);
	}  
	
	A[x-1][y-1]='K';
	
	printf("\nOlusan matris:\n");
	for (p=0;p<N;p++){
		for (q=0;q<N;q++){
			printf("%c ",A[p][q]);
		}
		printf("\n");
	}
	printf("\n");
	i++;
	
	sayac=N*N; //Girilen degerler sayac oldugu anda donguden cikmasina yardimici olur.
	
	while (i<sayac){
		renk_degisim=0;
		//(i%3)+1: Hangi oyuncunun sirasi oldugunu belirtmek ve hangi renk (K,S,M) oldugunu belirtmek.
		//Belirtilen oyuncudan tasin koordinatlarini istemek.
		//x ve y koordinatlari negatif, N'den buyuk, yada baska bir tasin oldugu yere olursa tekrardan x ve y'yi kullanicidan istemek.
		//x ve y [1-N] arasinda ama c dilinde indisler [0,N-1] arasinda. Kullanici x ve y giriyor ama matriste v ve w indislerine A[v][w] yaziliyor (v=x-1 & w=y-1).
		//Yatay/dik/capraz kontrolleri icin m ve n degiskenleri kullanilacak (v ve w degerleri sabit kalmalari icin).
		//Kullanicinin girdigi rengi (K, S, M) matrise yazdirmak
		
		// Sirali olarak oyunculardan x ve y koordinatlar talebi
		if (i%3==0) renk = 'K';       // 1. oyuncu renk kirmizi
		else if (i%3==1) renk = 'S';  // 2. oyuncu renk sari
		else if (i%3==2) renk = 'M';  // 3. oyuncu renk mavi
		
		printf("%d. Oyuncu (%c) rengi icin hamlenizi yapiniz: \nx ve y koordinatlari giriniz: ",(i%3)+1,renk);
		scanf("%d %d",&x,&y);
		
		v=x-1;
		w=y-1;
		while (x <= 0 || x > N || y <= 0 || y > N || A[v][w] != '-' || // Kullanicinin degerleri [1-N] arasinda oldugunu kontrol et ve o konumda baska bir tasin olup olmadigi
        	/*
			Tasin butun komsularini kontrol etmek (ortalarda olan tasin komsuluklari 8.. Kenarda olan taslarin komsuluklari ortakilerden daha az ona gore kontrol)
			Eger tasin butun komsuluklarinda '-' var ise o zaman etrafi bostur ve kurallara gore en az 1 tane komsusu olmasi gerektigi x ve y tekrar kullanicidan istemek
			*/
			((v - 1 < 0 || w - 1 < 0 || A[v - 1][w - 1] == '-') &&
            (v - 1 < 0 || A[v - 1][w] == '-') &&
            (v - 1 < 0 || w + 1 >= N || A[v - 1][w + 1] == '-') &&
            (w - 1 < 0 || A[v][w - 1] == '-') &&
            (w + 1 >= N || A[v][w + 1] == '-') &&
            (v + 1 >= N || w - 1 < 0 || A[v + 1][w - 1] == '-') &&
            (v + 1 >= N || A[v + 1][w] == '-') &&
            (v + 1 >= N || w + 1 >= N || A[v + 1][w + 1] == '-'))) {
			//x ve y hatali olma durumda tekrar istemek
			printf("x ve/veya y degerleri hatali tekrar giriniz: ");
			scanf("%d %d",&x, &y);
			v=x-1;
			w=y-1;
		}
				
		A[v][w]=renk;
		
		printf("\nOlusan matris:\n");
		for (m=0;m<N;m++){
			for (n=0;n<N;n++){
				printf("%c ",A[m][n]);
			}
			printf("\n");
		}
		printf("\n");
		
		// Yatay olarak bir hamle olup olmadigi kontrol:
		//Yatay sol kontrol (satir sayisi (v) sabit ama sutun sayisi (n) bir bir azalacak)
		m=v;
		n=w-2;
		if (A[m][n+1]!='-' && A[m][n+1]!=renk){
			while (n>=0 && ctrl==0 && A[m][n]!='-'){
				if (A[m][n]==renk){
					for (p=n;p<w;p++){
						A[m][p] = renk;
					}
					ctrl=1;
					renk_degisim=1;
				}	
				n--;
			}
		}
		ctrl=0;
		
		//Yatay sag kontrol (satir sayisi (v) sabit ama sutun sayisi (n) bir bir artacak)
		m=v;
		n=w+2;
		if (A[m][n-1]!='-' && A[m][n-1]!=renk){
			while (n<N && ctrl == 0 && A[m][n]!='-'){
				if (A[m][n]==renk){
					for (p=n;p>w;p--){
						A[m][p] = renk;
					}
					ctrl=1;
					renk_degisim=1;
				}
				n++;
			}
		}
		ctrl=0;
		
		//Dik kontroller
		//Dik yukari kontrol (sutun (w) sayisi sabit ama satir sayisi degisiyor)
		m=v-2;
		n=w;
		if (A[m+1][n]!='-' && A[m+1][n]!=renk){
			while (m>=0 && ctrl==0 && A[m][n]!='-'){
				if (A[m][n]==renk){
					for (p=m;p<v;p++){
						A[p][n]=renk;
					}
					ctrl=1;
					renk_degisim=1;
				}				
				m--;
			}
		}
		ctrl=0;
		
		//Dik asagi kontrol (sutun (w) sayisi sabit ama satir sayisi degisiyor )
		m=v+2;
		n=w;
		if (A[m-1][n]!='-' && A[m-1][n]!=renk){
			while (m<N && ctrl==0 && A[m][n]!='-'){
				if (A[m][n]==renk){
					for (p=m;p>v;p--){
						A[p][n]=renk;
					}
					ctrl=1;
					renk_degisim=1;
				}	
				m++;
			}
		}
		ctrl=0;
		
		//Sag Yukrai capraz kontrolu:
		m=v-2;
		n=w+2;
		if (A[m+1][n-1]!='-' && A[m+1][n-1]!=renk){
			while (m>=0 && n<N && ctrl==0 && A[m][n]!='-'){
				if (A[m][n]==renk){
					p=m;
					q=n;
					while (p<v && q>w){
						A[p][q]=renk;
						p++;
						q--;
					}
					ctrl=1;
					renk_degisim=1;	
				}
				m--;
				n++;
			}
		}
		ctrl=0;
		
		//Sol Asagi capraz kontrolu:
		m=v+2;
		n=w-2;
		if (A[m-1][n+1]!='-' && A[m-1][n+1]!=renk){
			while (m<N && n>=0 && ctrl==0 && A[m][n]!='-'){
				if (A[m][n]==renk){
					p=m;
					q=n;
					while (p>v && q<w){
						A[p][q]=renk;
						p--;
						q++;
					}
					ctrl=1;
					renk_degisim=1;	
				}
				m++;
				n--;
			}
		}
		ctrl=0;
		
		//Sol Yukari capraz kontrolu:
		m=v-2;
		n=w-2;
		if (A[m+1][n+1]!='-' && A[m+1][n+1]!=renk){
			while (m>=0 && n>=0 && ctrl==0 && A[m][n]!='-'){
				if (A[m][n]==renk){
					p=m;
					q=n;
					while (p<v && q<w){
						A[p][q]=renk;
						p++;
						q++;
					}
					ctrl=1;
					renk_degisim=1;
				}
				m--;
				n--;
			}
		}
		ctrl=0;
		
		//Sag Asagi capraz kontrolu:
		m=v+2;
		n=w+2;
		if (A[m-1][n-1]!='-' && A[m-1][n-1]!=renk){
			while (m<N && n<N && ctrl==0 && A[m][n]!='-'){
				if (A[m][n]==renk){
					p=m;
					q=n;
					while (p>v && q>w){
						A[p][q]=renk;
						p--;
						q--;
					}
					ctrl=1;
					renk_degisim=1;	
				}
				m++;
				n++;
			}
		}
		ctrl=0;
		
		//Eger renk degisimi oldu ise yeni tahtayi yazdirma:
		if (renk_degisim==1){
			printf("RENK DEGISIMI:\n");
						for (p=0;p<N;p++){
							for (q=0;q<N;q++){
								printf("%c ",A[p][q]);	
							}
							printf("\n");
						}
						printf("\n");	
		}
			
		
		
		i++;
	} //while bitti (kullanici girdileri ve her biri icin kontrol)

	//Tahtada kac tane renk oldugunu  bulmak ve renk sayisini yazdirmak
	for (i=0;i<N;i++){
		for (j=0;j<N;j++){
			if (A[i][j]=='K') kirmizisayac++;
			else if (A[i][j]=='S') sarisayac++;
			else if (A[i][j]='M') mavisayac++;
		}
	}
	
	printf("Kirmizi Taslar Sayisi: %d\nSari Taslar Sayisi: %d\nMavi Taslar Sayisi: %d\n\n",kirmizisayac,sarisayac,mavisayac);
	
	//En cok renge sahip olan oyuncu oyunu kazanir:
	if (kirmizisayac > sarisayac && kirmizisayac>mavisayac)
		printf("1. OYUNCU KAZANDI");
	else if (sarisayac>kirmizisayac && sarisayac >mavisayac)
		printf("2. OYUNCU KAZANDI");
	else if (mavisayac> kirmizisayac && mavisayac>sarisayac)
		printf("3. OYUNCU KAZANDI");
	else printf("BERABERLIK");
	
	return 0;
}
