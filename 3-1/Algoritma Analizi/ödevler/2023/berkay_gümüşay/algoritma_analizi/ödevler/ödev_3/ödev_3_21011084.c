#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct HashTableNode{
	char *userName;
	int deleted;
}hashTableNode;

long int hornersMethod(char* string);
int isPrime(int n);
int findPrime(int n);
long int power(long int x, int y);
int insertUser(char* userName, hashTableNode* hashTable, int tableSize, int mode);
void searchUser(char* userName, hashTableNode* hashTable, int tableSize, int mode);
int deleteUser(char* userName, hashTableNode* hashTable, int tableSize, int mode);
void printUserList(hashTableNode* hashTable, int tableSize);
int searchUserNoMsg(char* userName, hashTableNode* hashTable, int table);
void printUserStatus(hashTableNode* hashTable, int tableSize, int userNum);
hashTableNode* rehashTable(hashTableNode* oldHashTable, int* oldTableSize, int newTableSize);


int main() {
	int mode=0,menu=0,tableSize,i;
	int N, key, userNum=0, newTableSize;
	float loadFactor;
	char string[20];
	printf("N: ");
	scanf("%d",&N);
	printf("Load Factor: ");
	scanf("%f",&loadFactor);
	tableSize = findPrime((int)(N/loadFactor));
	system("cls");
	hashTableNode* hashTable = (hashTableNode*)calloc(tableSize,sizeof(hashTableNode));
		printf("1- Normal Mode\n2- Debug Mode\n3- Exit\n   Choice: ");
		scanf("%d",&mode);
		if(mode != 3){ 
			system("cls");
			menu = 0;
			while(menu != 6){  
				if(userNum == tableSize){	// TABLO DOLULUÐU KONTROL EDÝLÝR
					printf("!! Tablo Dolu !! Duzenleme Yapmaniz Onerilir !!\n\n");
				}
				printf("1- Yeni Kullanici Ekle\n2- Kullanici Ara\n3- Kullanici Sil\n4- Tabloyu Yazdir\n5- Tabloyu Duzenle\n6- Geri\n   Secim: ");
				scanf("%d",&menu);
				system("cls");
				switch(menu){	// MENÜ SEÇÝMÝ YAPILIR
					case(1):{ 
						printf("Kullanici Adini Giriniz (Buyuk Harflerle) : ");
						scanf("%s",string);
						if(userNum == tableSize){
							printf("Tablo Dolu !");	// TABLO DOLULUÐU KONTROL EDÝLÝR
						}
						else{
							if(insertUser(string,hashTable,tableSize,mode) == 1){
								userNum++;	// TABLO DEÐÝLSE KULLANICI EKLEME ÝÞLEMÝ YAPILIP KULLANICI SAYISI 1 ARTTIRILIR
							}
						}
						
						printf("\nPress Enter");	// ANA MENÜYE DÖNÜÞ YAPILIR
						getch();
						system("cls");
						break;
					}
					case(2):{	// ARAMA ÝÞLEMÝ
						printf("Aramak Istediginiz Kullanici Adini Giriniz (Buyuk Harflerle) : ");  
						scanf("%s",string);
						searchUser(string,hashTable,tableSize,mode);	// ARAMA FONKSÝYONU
						printf("\nPress Enter");
						getch();
						system("cls");
						break;
					}
					case(3):{
						printf("Silmek Istediginiz Kullanicinin Adini Giriniz (Buyuk Harflerle) : ");
						scanf("%s",string);
						if(deleteUser(string,hashTable,tableSize,mode) == 1){	// SÝLME ÝÞLEMÝ
							userNum--;	// KULLANICI SAYISINI AZALTMA
						}
						printf("\nPress Enter");
						getch();
						system("cls");
						break;
					}
					case(4):{
						printUserList(hashTable,tableSize);	// KULLANICI LÝSTESÝNÝ YAZDIRMA
						printf("\n\nPress Enter");
						getch();
						system("cls");
						break;
					}
					case(5):{
						if(mode == 2){
							printUserStatus(hashTable,tableSize,userNum);	// KULLANICILARIN SÝLÝNÝP SÝLÝNMEDÝGÝNÝ EKRANA YAZDIRMA
							printf("\nPress Enter");
							getch();
							system("cls");
						}
						printf("Yeni Tablo Boyutunu Giriniz (Asal Sayi) : ");
						scanf("%d",&newTableSize);
						hashTable = rehashTable(hashTable,&tableSize,newTableSize);	// YENÝDEN ORGANÝZE ETME ÝÞLEMÝ (REHASH)
						printf("\n\nTablo Duzenleme Islemi Bitmistir");
						printf("\nPress Enter");
						getch();
						system("cls");
						break;
					}
					case(6):{
						system("cls");	// ÇIKIÞ ÝÞLEMÝ
						break;
					}
				}
			}
		}
		system("cls");	
		return 0;
	}
	

int isPrime(int n){	// ASALLIÐI KONTROL EDEN FONKSÝYON
	int i;
    if (n < 2) {
        return 0;
    }
    else {
        for(i = 2; i <= sqrt(n); i++){
            if (n % i == 0)
                return 0;
        }
    }
    return 1;
}
int findPrime(int num){	// num SAYISINDAN BÜYÜK EN KÜÇÜK ASAL SAYIYI BULAN FONKSÝYON
	int i = 0;
	while(!isPrime(num)){
		num++;
	}
	return num;
}
long int power(long int x, int y){	// ÜS ALMA FONKSÝYONU
    if(y == 0){
        return 1;
    }
    int i;
    long int result = 1;
    
    for(i=0; i<y; i++){
        result *= x;
    }
    return result;
}
long int hornersMethod(char* string){ // Horner YÖNTEMÝ
	int i;
	int length;
	long int key=0;
	long int R = 17;
	length = strlen(string);	// A = 65
	for(i=0 ; i<length ; i++){
		key += power(R,(length-1-i)) * ((long int)((string[i] - 65 +1)));
	}
	return key;
}
int h1(long int key, int m){ // ÖDEVDE BELÝRTÝLEN h1() FONSKÝYONU
	return (key%m);
}
int h2(long int key, int m){ // ÖDEVDE BELÝRTÝLEN h2() FONSKÝYONU
	return (1+ (key%(m-2)));
}
int doubleHashing(long int key, int i, int m){ // Double Hashing METODU
	int tmp;
	tmp = (h1(key,m) + i*h2(key,m) ) % m;
	return tmp;
}

int insertUser(char* userName, hashTableNode* hashTable, int tableSize, int mode){	// KULLANICI EKLEME FONKSÝYONU
	int key = hornersMethod(userName);	//	HORNER YÖNTEMÝ ÝLE KEY ÜRETÝMÝ
	int index = h1(key,tableSize);	//	DÝVÝSÝON METHOD ÝLE ÝLK ÝNDEXÝN ÜRETÝMÝ
	int i = 0;
	if(searchUserNoMsg(userName, hashTable, tableSize) == 1){	//	EKLENECEK KULLANICININ TABLODA MEVCUT OLUP OLMADIÐININ KONTROLÜ
		printf("Eleman tabloda mevcut oldugu icin ekleme islemi yapilmadi\n");	
		return 0;
	}
	if(mode == 2){	// DEBUG MOD KONTROLÜ
		printf("Debug Message : h1('%s') = %d\n",userName,index);
		printf("Debug Message : h2('%s') = %d\n",userName,h2(key,tableSize));
	}
	if((hashTable[index].userName == NULL) || (hashTable[index].deleted == 1)){	// ÝLK ÝNDEXÝN MÜSAÝT OLUP OLMADIÐININ KONTROLÜ
		hashTable[index].deleted = 0;
		hashTable[index].userName = strdup(userName);
		printf("%s elemani %d. adrese yerlestirildi\n",userName,index);
		return 1;
	}
	
	if(mode == 2){	// DEBUG MOD KONTROLÜ
		printf("Debug Message : %s kelimesi %d. adres dolu oldugu icin yerlestirilemedi\n",userName,index);
	}
	i++;
	index = doubleHashing(key,i,tableSize);	//	DOUBLE HASHÝNG ÝLE ADIM BÜYÜKLÜÐÜNÜN ÜRETÝMÝ
	while((hashTable[index].userName != NULL) && (index<=tableSize)){	//	HASHTABLE DA NULL ELEMAN GÖRENE KADAR DÖNÜLÜR
		if(hashTable[index].deleted == 1){	//	ÖNCEDEN SÝLÝNEN BÝR ELEMANA DENK GELÝNÝRSE ÜZERÝNE EKLEME YAPILIR
			hashTable[index].deleted = 0;
			hashTable[index].userName = strdup(userName);
			printf("%s elemani %d. adrese yerlestirildi\n",userName,index);
			return 1;
		}
		if(mode == 2){	// DEBUG MOD KONTROLÜ
			printf("Debug Message : %s kelimesi %d. adres dolu oldugu icin yerlestirilemedi\n",userName,index);
		}
		i++;
		index = doubleHashing(key,i,tableSize);	//	BOÞ YER BULUNAMADIKÇA DOUBLE HASHÝNG YAPILARAK ADIM SAYISI KADAR ÝLERLENÝR
	}
	hashTable[index].deleted = 0;
	hashTable[index].userName = strdup(userName);
	printf("%s elemani %d. adrese yerlestirildi\n",userName,index);
	return 1;
}

void searchUser(char* userName, hashTableNode* hashTable, int tableSize, int mode){	//	KULLANICI ARAMA FONKSÝYONU
	int temp = 0;
	long int key = hornersMethod(userName);
	int index = h1(key,tableSize);
	int i = 0;
	if(mode == 2){	// DEBUG MOD KONTROLÜ
		printf("Debug Message : h1('%s') = %d\n",userName,index);
		printf("Debug Message : h2('%s') = %d\n",userName,h2(key,tableSize));
	}
	if(hashTable[index].userName == NULL){	// EÐER ÝLK ÝNDEX NULL ÝSE BU ELEMAN LÝSTEYE HÝÇ EKLENMEMÝÞTÝR VE DOLAYISIYLA LÝSTEDE YOKTUR
		printf("%s isimli kullanici tabloda bulunamadi",userName);
		return;
	}
	else{
		if((strcmp(hashTable[index].userName,userName) == 0) && (hashTable[index].deleted == 0)){	//	ÝLK ÝNDEXÝN KONTROLÜ
			printf("%s isimli kullanici %d. adreste bulunmaktadir",userName,index);
			return;
		}
		if(mode == 2){	// DEBUG MOD KONTROLÜ
			printf("Debug Message : %s isimli kullanici %d. adreste bulunamadi\n",userName,index);
		}
		temp++;	//	TEMP DEÐÝÞKENÝ LÝSTEDE KONTROL EDÝLEN ÝNDEX SAYISINI TUTAR
		i++;
		index = doubleHashing(key,i,tableSize);	//	ELEMAN BULUNAMAZSA ADIM SAYISI KADAR ÝLERLENÝR
		while((index<=tableSize)&&(hashTable[index].userName != NULL)){	//	HASHTABLE DA NULL ELEMAN GÖRENE KADAR DÖNÜLÜR
			if((strcmp(hashTable[index].userName,userName) == 0) && (hashTable[index].deleted == 0)){	//	ARANAN ELAMAN BULUNURSA EKRANA YAZDIRILIP DÖNGÜDEN ÇIKILIR
				printf("%s isimli kullanici %d. adreste bulunmaktadir",userName,index);
				return;
			}
			if(mode == 2){	// DEBUG MOD KONTROLÜ
				printf("Debug Message : %s isimli kullanici %d. adreste bulunamadi\n",userName,index);
			}
			
			temp++;
			i++;
			index = doubleHashing(key,i,tableSize);	//	BULUNAMAZ ÝSE DOUBLE HASHÝNG YAPILARAK ADIM SAYISI KADAR ÝLERLENÝR
			if(temp == tableSize){	// EÐER KONTROL EDÝLEN ÝNDÝS SAYISI TABLO BOYUTUNA EÞÝTSE BU ELEMAN TABLODA YOKTUR
				printf("%s isimli kullanici tabloda bulunamadi",userName);
				return;
			}
		}
	}
	printf("%s isimli kullanici tabloda bulunamadi",userName);
	return;
}

int deleteUser(char* userName, hashTableNode* hashTable, int tableSize, int mode){	//	KULLANICI SÝLME FONKSÝYONU
	long int key = hornersMethod(userName);
	int index = h1(key,tableSize);
	int i = 0;
	int temp = 0;
	if(mode == 2){	// DEBUG MOD KONTROLÜ
		printf("Debug Message : h1('%s') = %d\n",userName,index);
		printf("Debug Message : h2('%s') = %d\n",userName,h2(key,tableSize));
	}
	if(hashTable[index].userName == NULL){	// EÐER ÝLK ÝNDEX NULL ÝSE BU ELEMAN LÝSTEYE HÝÇ EKLENMEMÝÞTÝR VE DOLAYISIYLA LÝSTEDE YOKTUR
		printf("%s elemani tabloda bulunmuyor",userName);
		return 0;
	}
	else{
		if((strcmp(hashTable[index].userName,userName) == 0) && (hashTable[index].deleted == 0)){	//	ÝLK ÝNDEXÝN KONTROLÜ	
			printf("%d adresindeki %s elemani silindi",index,userName);
			hashTable[index].deleted = 1;
			return 1;
		}
		if(mode == 2){	// DEBUG MOD KONTROLÜ
			printf("Debug Message : %s kelimesi %d. adreste bulunamadi\n",userName,index);
		}
		temp++;	//	TEMP DEÐÝÞKENÝ LÝSTEDE KONTROL EDÝLEN ÝNDEX SAYISINI TUTA
		i++;	
		index = doubleHashing(key,i,tableSize);	//	ELEMAN BULUNAMAZSA ADIM SAYISI KADAR ÝLERLENÝR
		while((index<=tableSize)&&(hashTable[index].userName != NULL)){	//	HASHTABLE DA NULL ELEMAN GÖRENE KADAR DÖNÜLÜR
			if((strcmp(hashTable[index].userName,userName) == 0) && (hashTable[index].deleted == 0)){//	ARANAN ELAMAN BULUNURSA deleted = 1 YAPILIP DÖNGÜDEN ÇIKILIR
				hashTable[index].deleted = 1;
				printf("%d adresindeki %s elemani silindi",index,userName);
				return 1;
			}
			if(mode == 2){	// DEBUG MOD KONTROLÜ
				printf("Debug Message : %s kelimesi %d. adreste bulunamadi\n",userName,index);
			}
			temp++;
			i++;
			index = doubleHashing(key,i,tableSize);	//	BULUNAMAZ ÝSE DOUBLE HASHÝNG YAPILARAK ADIM SAYISI KADAR ÝLERLENÝR
			if(temp == tableSize){
				printf("%s elemani tabloda bulunamadi",userName);	// EÐER KONTROL EDÝLEN ÝNDÝS SAYISI TABLO BOYUTUNA EÞÝTSE BU ELEMAN TABLODA YOKTUR
				return;
			}
		}
	}
	printf("%s elemani tabloda bulunmuyor",userName);
	return 0;	
}

void printUserList(hashTableNode* hashTable, int tableSize){
	int i;
	for(i=0;i<tableSize;i++){
		printf("%d- ",i);
		if((hashTable[i].userName != NULL) && (hashTable[i].deleted != 1)){	// EÐER ÝNDEXTE BÝR KULLANICI ADI VARSA EKRANA YAZDIRILIR
			printf(" %s\n",hashTable[i].userName);
		} 
		else{
			printf(" Empty\n");	//	ÝNDEXTE NULL DEÐER VEYA SÝLÝNMÝÞ BÝR KULLANICI VARSA EKRANA Empty YAZDIRILIR
		}
	}
}

void printUserStatus(hashTableNode* hashTable, int tableSize, int userNum){
	int i = 0;
	int deleted=0;
	for(i=0;i<tableSize;i++){
		if(hashTable[i].userName == NULL){
			printf("%d - NULL",i);	//	EÐER ÝNDEX NULL ÝSE EKRANA NULL YAZDIRILIR
		}
		else{
			if(hashTable[i].deleted == 1){
				printf("%d - %s (Silinmis)",i,hashTable[i].userName);	//	EÐER ÝNDEXTEKÝ ELEMAN SÝLÝNMÝÞ ÝSE EKRANA Silinmis YAZDIRILIR
			}
			else{
				printf("%d - %s (Silinmemis)",i,hashTable[i].userName);	//	EÐER ÝNDEXTEKÝ ELEMAN SÝLÝNMEMÝÞ ÝSE EKRANA Silinmemis YAZDIRILIR
			}
		}
		printf("\n");
	}
	
}

hashTableNode* rehashTable(hashTableNode* oldHashTable, int *oldTableSize, int newTableSize){	// REHASHÝNG ÝÞLEMÝ
	hashTableNode* newHashTable = (hashTableNode*)calloc(newTableSize,sizeof(hashTableNode));	// KULLANICININ GÝRDÝÐÝ TABLO BOYUTUNDA YENÝ BÝR HASHTABLE OLUÞTURULUR
	int i;
	
	for(i=0;i<(*oldTableSize);i++){	
		if((oldHashTable[i].deleted == 0) && (oldHashTable[i].userName != NULL)){	//	TABLODA OLAN SÝLÝNMEMÝÞ KULLANICI ADLARI YENÝ HASHTABLE A HASHÝNG YAPILARAK EKLENÝR
			insertUser(oldHashTable[i].userName, newHashTable, newTableSize, 1);
		}
	}
	free(oldHashTable);	//	ESKÝ TABLO SERBEST BIRAKILIR
	*oldTableSize = newTableSize;	// TABLO BOYUTU GÜNCELLENÝR
	return newHashTable;
}

int searchUserNoMsg(char* userName, hashTableNode* hashTable, int tableSize){	//	ARAMA FONKSÝYONUNUN ÇIKTI OLARAK MESAJ VERÝLMEYEN HALÝ
	int temp = 0;
	long int key = hornersMethod(userName);
	int index = h1(key,tableSize);
	int i = 0;
	if(hashTable[index].userName == NULL){
		return 0;
	}
	if((strcmp(hashTable[index].userName,userName) == 0) && (hashTable[index].deleted == 0)){
		return 1;
	}
	temp++;
	i++;
	index = doubleHashing(key, i, tableSize);
	while((index<=tableSize)&&(hashTable[index].userName != NULL)){
		if((strcmp(hashTable[index].userName,userName) == 0) && (hashTable[index].deleted == 0)){
			return 1;
		}
		temp++;
		i++;
		index = doubleHashing(key,i,tableSize);
		if(temp == tableSize){
			return 0;
		}
	}
	return 0;
}









