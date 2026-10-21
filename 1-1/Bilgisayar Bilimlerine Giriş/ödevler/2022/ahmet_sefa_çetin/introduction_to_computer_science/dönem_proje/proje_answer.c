#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
		
	int tahta[100][100], N, M, i, j, yemSayisi, a, b, yilanX, yilanY, toplamYenen = 0, hamleSayisi = 0, kuyrugaCarpma = 0;
	char yon;
	
	srand(time(NULL)); // rand() fonksiyonu farkli degerler dondurmesi icin yazilmasi gerekiyor 
	
	// kullanicidan oyun tahtasinin boyutlarini alma
	printf("oyun tahtasinin boyunu giriniz: ");
	scanf("%d", &N);
	printf("oyun alaninin enini giriniz: ");
	scanf("%d", &M);
	
	// oyun tahtasindaki tum elemanlari -1 yapma
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			tahta[i][j] = -1;
		}
	}	
	
	// kullanicidan yem sayisi alma
	printf("yem sayisi giriniz: ");
	scanf("%d", &yemSayisi);	
	
	// yem sayisi tahtaya uygun degilse kullanicidan tekrar yem sayisi alma 
	while (yemSayisi >= N * M || yemSayisi <= 0) {
		printf("hatali yem sayisi, tekrar yem sayisi giriniz: ");
		scanf("%d", &yemSayisi);
	}
	
	// yemleri rastgele oyun tahtasina yerlestirme
	i = 0;
	while (i < yemSayisi) {
		a = rand() % N + 1;
		b = rand() % M + 1;
		if (tahta[a][b] != 0){
			tahta[a][b] = 0;
			i++; 
		}
	}
	
	// yilanin bulundugu konumu rastgele oyun tahtasina yerlestirme
	while (tahta[yilanX][yilanY] != 1) {
		a = rand() % N + 1;
		b = rand() % M + 1;
		if (tahta[a][b] != 0){
			tahta[a][b] = 1; 
			yilanX = a;
			yilanY = b;
		} 
	}
	
	// kullanicidan yilanin hangi yone gidecegi bilgisini alma ve yilani o yone kaydirma
	while (yilanX <= N && yilanY <= M && yilanX >= 1 && yilanY >= 1 && toplamYenen != yemSayisi && kuyrugaCarpma != 1) {
				
		// oyun tahtasini ekrana yazdirma, -1 ler bosluk karakteri olarak gozukecek
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= M; j++) {
				if (tahta[i][j] == -1) {
					printf("  |");
				}
				else if (tahta[i][j] >= 10) {
					printf("%d|", tahta[i][j]);
				}
				else {
					printf(" %d|", tahta[i][j]);
				}			
			}
			printf("\n");
		}
		
		// yilanin kuyrugunu olusturup ilerletme
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= M; j++) {
				if (tahta[i][j] != -1 && tahta[i][j] != 0) {
					tahta[i][j]++;
				}
				if (tahta[i][j] >= toplamYenen + 2) {
					tahta[i][j] = -1;
				}		
			}
		}		
		
		// kullanicidan yilanin gidecegi yon bilgisini alma
		printf("yilan hangi yone gitsin: ");
		scanf(" %c", &yon);
		
		//UP
		if (yon == 'u' || yon == 'U') {				
			yilanX--;
		}
		
		//DOWN
		else if (yon == 'd' || yon == 'D') {				
			yilanX++;
		}
		
		//RIGHT
		else if (yon == 'r' || yon == 'R') {
			yilanY++;
		}
		
		//LEFT
		else if (yon == 'l' || yon == 'L') {	
			yilanY--;
		}
		
		// toplam yenen yem sayisini arttirma
		if (tahta[yilanX][yilanY] == 0) {
				toplamYenen++;
		}
		// yilanin kendi kuyruguna carpmasini kontrol etme
		else if (tahta[yilanX][yilanY] >= 2 && tahta[yilanX][yilanY] <= toplamYenen + 2) {
			kuyrugaCarpma = 1;
		}
					
		tahta[yilanX][yilanY] = 1;
		
		// her hamlede hamle sayisini arttirma ve ekrana yazdýrma
		hamleSayisi++;
		printf("Hamle sayisi: %d\n", hamleSayisi);
	}
	
	// oyun bitiminde oyun tahtasini ekrana yazdirma
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			if (tahta[i][j] == -1) {
				printf("  |");
			}
			else if (tahta[i][j] >= 10) {
				printf("%d|", tahta[i][j]);
			}
			else {
				printf(" %d|", tahta[i][j]);
			}			
		}
		printf("\n");
	}
	
	// yilan tum yemleri yedi mi
	if (toplamYenen == yemSayisi) {
		printf("Tebrikler tum yemleri yediniz!\n");
		printf("Toplam hamle sayiniz: %d", hamleSayisi);
	}
	// yilan kendi kuyruguna carpti mi
	else if (kuyrugaCarpma == 1) {
		printf("yilan kendi kuyruguna carpti\n");
		printf("Toplam hamle sayiniz: %d\n", hamleSayisi);
		printf("Yilanin buyuklugu: %d\n", toplamYenen + 1);
		printf("Kalan yemek sayisi: %d", yemSayisi - toplamYenen);
	}
	// yilan oyun alaninin disina mi cikti	
	else {
		printf("yilan oyun tahtasinin disina cikti\n");
		printf("Toplam hamle sayiniz: %d\n", hamleSayisi);
		printf("Yilanin buyuklugu: %d\n", toplamYenen);
		printf("Kalan yemek sayisi: %d", yemSayisi - toplamYenen + 1);
	}
		
	return  0;
}
