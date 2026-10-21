#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct cark{
	int number;
	struct cark *next;
	struct cark *prev;
}Cark;

void carkUret(Cark **cark, int N);
void carkDuzenle(Cark **cark, int ortakSayi, int ortakIndex, int M, int N);
void carklariKiyasla(Cark **cark1, Cark **cark2, Cark **cark3, int ortakSayi, int ortakIndex, int M, int N);
void ortakSayiBul(Cark **cark1, Cark **cark2, Cark **cark3, int M);
int* donecekMiktar(Cark **cark2, Cark **cark3, int ortakSayi, int ortakIndex, int M);
void carklariDondur(Cark **cark2, Cark **cark3, int *donmeMiktarlari);
void carkYazdir(Cark* cark, int M);
int main(){
	srand(time(NULL));
	
	Cark *cark1 = NULL;
	Cark *cark2 = NULL;
	Cark *cark3 = NULL;
	
	int N,M,i;
	int *donmeMiktarlari;
	printf("Enter N and M: ");
	scanf("%d%d",&N,&M);
	while(N < 4 || N > 20 || M > 15 || M < 3 || N - M <= 0 ){
		printf("Enter N and M again: ");
		scanf("%d%d",&N,&M);
	}
	int ortakSayi = rand() % N + 1; //ortak sayýyý ürettik
	int ortakIndex[3];
	for(i = 0; i < M; i++){ //çarklar M adet 1-N arasýndaki rastgele elemanlarla dolduruldu
		carkUret(&cark1,N);
		carkUret(&cark2,N);
		carkUret(&cark3,N);
	}
	
	ortakIndex[0] = rand() % M; //ortak sayýnýn ilk çarkta nerede oluþacaðýný belirlemek için
	ortakIndex[1] = rand() % M;
	ortakIndex[2] = rand() % M;
	while( ( ortakIndex[0] == ortakIndex[1] ) || (ortakIndex[1] == ortakIndex[2]) || (ortakIndex[0] == ortakIndex[2]) ){
	ortakIndex[1] = rand() % M;
	ortakIndex[2] = rand() % M;
	} //ortak sayýnýn çarklarda farklý konumlarda üretilmesi saðlandý
	printf("Ortak Sayi: %d, index: %d\n",ortakSayi,ortakIndex[0]);
	
	carkDuzenle(&cark1,ortakSayi,ortakIndex[0], M, N);
	carkDuzenle(&cark2,ortakSayi,ortakIndex[1], M, N);
	carkDuzenle(&cark3,ortakSayi,ortakIndex[2], M, N);
	
	carklariKiyasla(&cark1,&cark2,&cark3,ortakSayi,ortakIndex[0],M,N);
	ortakSayiBul(&cark1,&cark2,&cark3,M);
	carkYazdir(cark1,M);
	
	donmeMiktarlari = donecekMiktar(&cark2,&cark3,ortakSayi,ortakIndex[0], M);
	carklariDondur(&cark2,&cark3,donmeMiktarlari);
	carkYazdir(cark1,M);
	carkYazdir(cark2,M);
	carkYazdir(cark3,M);
	
	return 0;
}

void carkUret(Cark **cark, int N){
	Cark *carkNode = (Cark*) malloc(sizeof(Cark));
	if(carkNode == NULL){
		printf("Yer ayrilamadi..\n");
		return;
	}
	carkNode->next = NULL;
	carkNode->prev = NULL;
	carkNode->number = rand() % N;
	if(*cark == NULL){ //liste boþsa
		*cark = carkNode;
	} else{ //çarka eleman ekliyoruz
	(*cark)->prev = carkNode;
	carkNode->next = *cark;
	*cark = carkNode;
	}
	return;
}

void carkDuzenle(Cark **cark, int ortakSayi, int ortakIndex, int M, int N){ //ortak sayýyý çarka koyar
	Cark *tmp = *cark;
	int i, j = 0, counter = 0;
	int *ortaklar = (int*) malloc(sizeof(int) * M);
	for(i = 0; i < M; i++) // listede ortak sayýnýn olduðu indisler ortaklar dizisinde tutulacak
		ortaklar[i] = -1;
	for(i = 0; i < ortakIndex; i++)
		tmp = tmp->next;
	tmp->number = ortakSayi; // artýk belirlenen indisde ortak sayý kesinlikle bulunacak, baþka indislerde ortak sayý varsa onlarý deðiþtirmek lazým
	tmp = *cark;

	for(i = 0; i < M; i++){
		if(tmp->number == ortakSayi) {//ortak sayýnýn çarkta bir kere bulunmasý için
			ortaklar[i] = counter; //ortak sayýnýn listede nerelerde olduðu bilgisi ortaklar dizisinde tutuluyor
		}
		counter++;
		tmp = tmp->next;
	}

	// baþka indislerde ortak sayý varsa onlarý deðiþtirmek için
	tmp = *cark;
	int random;
	for(i = 0; i < M; i++){
		if(ortaklar[i] != -1 && ortaklar[i] != ortakIndex){ //listenin elemaný ortak sayý ise ve indisi ortak indis deðilse o sayýnýn deðiþmesi lazým
			do{
				random = rand() % N + 1;
			}while(random == ortakSayi);
			tmp->number = random;
		}
		tmp = tmp->next;
	}
	return;
}	//artýk ortak sayý sadece bir node da var, sýra üretilen baþka bir sayýnýn üç çarkta da bulunmasýna izin verilmemesine geldi

void carklariKiyasla(Cark **cark1, Cark **cark2, Cark **cark3, int ortakSayi, int ortakIndex, int M, int N){
	Cark *tmp1 = *cark1;
	Cark *tmp2 = *cark2;
	Cark *tmp3 = *cark3;
	int i,j, arananEleman; //aranan eleman ilk listenin elemaný oluyor
	
	for(i = 0; i < M; i++){ //ilk listeyi gezmek için
		if(i == ortakIndex){ //ortak sayýnýn olduðu indise bakmaya gerek yok
			i++;
			tmp1 = tmp1->next;
		} else{
		arananEleman = tmp1->number;
		while(tmp2 != NULL && tmp2->number != arananEleman){ //ikinci listeyi gezmek için
			tmp2 = tmp2->next;
		}
		if(tmp2 != NULL){
			for(j = 0; j < M; j++){ //üçüncü listeyi gezmek için
				if(tmp3->number == arananEleman){
					tmp3->number = rand() % N + 1;
					while(tmp3->number == arananEleman)
						tmp3->number = rand() % N + 1;
				}
				tmp3 = tmp3->next;
			}
			tmp3 = *cark3;
		}
		tmp2 = *cark2;
		tmp1 = tmp1->next;
		}
	}
}

void ortakSayiBul(Cark **cark1, Cark **cark2, Cark **cark3, int M){
	Cark *tmp1 = *cark1;
	Cark *tmp2 = *cark2;
	Cark *tmp3 = *cark3;
	int index1 = 0, index2 = 0, index3 = 0, ortakSayi, number,i,yaziKontrolu = 0;
	
	for(i = 0; i < M; i++){ // ilk listeyi gezmek için
		number = tmp1->number;
		while(tmp2 != NULL && tmp2->number != number){ //ikinci listeyi gezmek için
			tmp2 = tmp2->next;
			index2++;
		}
		if(tmp2 != NULL){
			while(tmp3 != NULL && tmp3->number != number){ //üçüncü listeyi gezmek için
			tmp3 = tmp3->next;
			index3++;
			}
			if(tmp3 != NULL){
				ortakSayi = number;
				index1 = i;
				do{
				printf("Ortak Sayi: %d, ilk carkta %d ikincide %d ucuncude %d de bulunur.\n",ortakSayi, index1, index2, index3);
				}
				while(yaziKontrolu > 0);
			}
			tmp3 = *cark3;
			index3 = 0;
		}
		tmp2 = *cark2;
		index2 = 0;
		tmp1 = tmp1->next;
	}
}

int* donecekMiktar(Cark **cark2, Cark **cark3, int ortakSayi, int ortakIndex, int M){
	Cark *tmp2 = *cark2;
	Cark *tmp3 = *cark3;
	carkYazdir(tmp2,M);
	carkYazdir(tmp3,M);
	int miktar2,miktar3, indis2 = 0, indis3 = 0;
	int *donmeMiktarlari = (int*) malloc(sizeof(int) * 2);
	//ortak sayýnýn bulunduðu indislere ulaþmak için;
	while(tmp2->number != ortakSayi){
		tmp2 = tmp2->next;
		indis2++;
	}
	while(tmp3->number != ortakSayi){
		tmp3 = tmp3->next;
		indis3++;
	}
	
	/* 
	
	M = 9											M = 9

	5 	4	1 	3	12 	6 	8 	9 	7				5 	8	1 	3	12 	6 	4 	9 	7
	10	3	25	15	20	11	18	8	6				10	3	25	15	20	11	18	8	6
	25	8	11	30	22	32	52	72	1				8	25	11	30	22	32	52	72	1

	*/
	
	miktar2 = ortakIndex - indis2;
	if(abs(miktar2) > M/2){
		if(miktar2 > 0){
			miktar2 = (M - miktar2) * (-1);
		}
		else{
			miktar2 = M - abs(miktar2);
		}
	}
	
	miktar3 = ortakIndex - indis3;
	if(abs(miktar3) > M/2){
		if(miktar3 > 0){
			miktar3 = (M - miktar3) * (-1);
		}
		else{
			miktar3 = M - abs(miktar3);
		}
	}
	
	if(miktar2 >= 0){
		printf("2. cark saat yonunde %d adim cevrilmeli\n",miktar2);
		donmeMiktarlari[0] = miktar2;
	}
	else{
		printf("2. cark saat yonunun tersinde %d adim cevrilmeli\n",abs(miktar2));
		donmeMiktarlari[0] = miktar2;
	}
	
	if(miktar3 >= 0){
		printf("3. cark saat yonunde %d adim cevrilmeli\n",miktar3);
		donmeMiktarlari[1] = miktar3;
	}	
	else{
		printf("3. cark saat yonunun tersinde %d adim cevrilmeli\n",abs(miktar3));
		donmeMiktarlari[1] = miktar3;
	}
	return donmeMiktarlari;
}

void carklariDondur(Cark **cark2, Cark **cark3, int *donmeMiktarlari){
	Cark *tmp2 = *cark2;
	Cark *tmp3 = *cark3;
	//çarklar double linked list idi, circular double linked list haline getirilmeliler;
	while(tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = *cark2;
	(*cark2)->prev = tmp2;
	tmp2 = *cark2;
	while(tmp3->next != NULL)
		tmp3 = tmp3->next;
	tmp3->next = *cark3;
	(*cark3)->prev = tmp3;
	tmp3 = *cark3;
	
	int i,n;
	
	n = donmeMiktarlari[0];
	if(n > 0){
		for(i = 0; i < n; i++){
			*cark2 = (*cark2)->prev;
		}
	}	
	else{
		for(i = 0; i < abs(n); i++){
			*cark2 = (*cark2)->next;
		}
	}
	
	n = donmeMiktarlari[1];
	if(n > 0){
		for(i = 0; i < n; i++){
			*cark3 = (*cark3)->prev;
		}
	}	
	else{
		for(i = 0; i < abs(n); i++){
			*cark3 = (*cark3)->next;
		}
	}
}

void carkYazdir(Cark* cark, int M){
	Cark *tmp = cark;
	int i;
	for(i = 0; i < M; i++){
		printf("%d\t",tmp->number);
		tmp = tmp->next;
	}
	printf("\n");
}
