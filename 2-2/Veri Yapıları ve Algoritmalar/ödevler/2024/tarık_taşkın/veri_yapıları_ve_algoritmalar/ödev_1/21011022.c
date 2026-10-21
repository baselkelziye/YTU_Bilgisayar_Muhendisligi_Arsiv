#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256 //stringBuffer'in maksimum buyuklugu

//Double Linked List yapisi icin kullanilan struct
struct NODE{
	char* address;
	int count;
	struct NODE* prev;
	struct NODE* next;
};

//Programda kullanilan fonksiyonlar. Detaylari main fonksiyonun altindadir.
void getAddressesFromUser();
void getAddressesFromFile();
void getBounds(int *T, int *L);
void addList(struct NODE** cacheBuffer, char* address, int T, int L, int *nodeCount);
struct NODE* createNode(char* address);
int searchAddress(struct NODE** cacheBuffer, char* address, int T);
void deleteLastNode(struct NODE** cacheBuffer);
void printList(struct NODE* cacheBuffer);
void clearList(struct NODE** cacheBuffer);

int main(){
	int choice; //Kullanicinin adresleri nasil girmek istedigini tutan degisken
	
	do{
		printf("1- Enter Addresses\n");
		printf("2- Enter Addresses From File\n");
		printf("3- Exit\n");
		printf("Choice: ");
		scanf("%d",&choice);
		
		if(choice == 1){ //Secimin 1 olmasiyla adresler kullanici tarafindan alinir.
			getAddressesFromUser();
		}else if(choice == 2){ //Secimin 2 olmasiyla adresler dosyadan alinir.
			getAddressesFromFile();
		}else if(choice == 3){ //Secimin 3 olmasiyla programdan cikis yapilir.
			printf("Exiting...");
		}else{ //Bu secimler disinda yapilan secimler hatalidir. 
			printf("You made a wrong choice!\n\n");
		}				
	}while(choice!=1 && choice!=2 && choice!=3); //Hatali secim yapilmasi sonucunda while dongusuyle birlikte yapilacak secimler tekrar gosterilir.
	
	return 0;
}

/*
@brief Cache Buffer'a eklenmek uzere adresleri kullanicidan alir.

@return
*/
void getAddressesFromUser(){
	struct NODE* cacheBuffer = NULL; //Cache Buffer'i temsil eder. (HEAD)
	char stopCondition[] = "exit"; //stopCondition'un tuslanmasiyla birlikte adres girme islemi sonlanir.
	char stringBuffer[MAX]; //Kullanicidan alinan adresi gecici olarak saklar.
	int nodeCount = 0; //Cache Buffer'da bulunan eleman sayisini tutar.
	int stop = 1; //Dongunun devam etme kosulu
	int T; //Bir adresin esik degeri.
	int L; //Cache Buffer'in kapasitesi.
	
	getBounds(&T,&L); //Kullanicidan esik degeri ve kapasiteyi alinir.
	printf("For exit, type 'exit'.\n");
	do{
		printf("Address: "); //Kullanicidan adres bilgisi alinir.
		scanf("%s", stringBuffer);
		
		if(strcmp(stringBuffer, stopCondition)){ //Kullanicidan alinan adres stopCondition ile ayni olup olmadigi kontrol edilir.
			addList(&cacheBuffer, stringBuffer, T, L, &nodeCount); //Kullanicidan alinan adresi gerekli kosullari saglamasi durumunda Cache Buffer'a ekler.
			printList(cacheBuffer); //Cache Buffer'da bulunan elemanlari yazdirir.
		}else{ //Kullanicidan alinan adres stopCondition ile eger ayniysa stop degeri 0 yapilarak dongu sonlandirilir.
			stop = 0;
		}		
	}while(stop);
	
	clearList(&cacheBuffer); //Kullanicinin karariyla Cache Buffer'i temizler.
}

/*
@brief Cache Buffer'a eklenmek uzere adresleri dosyadan alir.

@return
*/
void getAddressesFromFile(){
	struct NODE* cacheBuffer = NULL; //Cache Buffer'i temsil eder. (HEAD)
	char fileName[MAX]; //Adreslerin okunacagi dosyanin adi
	char stringBuffer[MAX]; //Dosyadan alinan adresi gecici olarak saklar.
	int nodeCount = 0; //Cache Buffer'da bulunan eleman sayisini tutar.
	int T; //Bir adresin esik degeri.
	int L; //Cache Buffer'in kapasitesi.
	
	printf("\nEnter file name: ");
	scanf("%s",fileName); //Kullanicidan dosya ismi alinir.
	FILE* file = fopen(fileName, "r");
	
	if(file == NULL){ //Dosyanin acilamamasi durumunda programi sonlandirir.
		printf("File cannot open!");
		return;
	}	
	
	getBounds(&T,&L); //Kullanicidan esik degeri ve kapasiteyi alinir.
	
	while(!feof(file) && fscanf(file,"%s\n",stringBuffer)){ //Dosyanin sonuna kadar her satirdaki adres bilgisi okunur.
		printf("Address: %s\n", stringBuffer); //Cache Buffer'i rahat takip edebilmek icin dosyadan okunan adres degeri ekrana yazdirilir.
		addList(&cacheBuffer, stringBuffer, T, L, &nodeCount); //Dosyadan alinan adresi gerekli kosullari saglamasi durumunda Cache Buffer'a ekler.
		printList(cacheBuffer); //Cache Buffer'da bulunan elemanlari yazdirir.
	}
	
	clearList(&cacheBuffer); //Kullanicinin karariyla Cache Buffer'i temizler.
	fclose(file);
}

/*
@brief Cache Buffer'in kapasitesini ve adres sayacinin esik degerini kullanicidan alir.

@param T, esik degerini tutan degiskenin adresi
@param L, Cache Buffer'in kapasitesini tutan degiskenin adresi

@return
*/
void getBounds(int *T, int *L){
	printf("\n");	
	do{
		printf("T (T>0): ");
		scanf("%d",T);
	}while(*T<1); //T degerini kullanicidan T>=1 olacak sekilde alir.
	
	do{
		printf("L (L>0): ");
		scanf("%d",L);
	}while(*L<1); //L degerini kullanicidan L>=1 olacak sekilde alir.
	
	printf("\n");
}

/*
@brief Adresi gerekli kosullarin saglanmasi durumunda Cache Buffer'a ekler ya da adresin sayacini arttirir.

@param cacheBuffer, Double Linked List yapisinin Head degeri.
@param address, Cache Buffer'a eklenecek adres.
@param T, esik degerini tutan degisken
@param L, Cache Buffer'in kapasitesini tutan degisken
@param nodeCount, Cache Buffer'da bulunan eleman sayisinin adresi

@return
*/
void addList(struct NODE** cacheBuffer, char* address, int T, int L, int *nodeCount){
	if((*cacheBuffer) == NULL){ //Head'in NULL olmasi durumunda yeni bir node olusturarak verilen adresi bu node'a ekler.
		*cacheBuffer = createNode(address);
		(*nodeCount)++; //Cache Buffer'a yeni node eklendigi icin node sayisini arttirir.
	}else{ 
		if(!searchAddress(cacheBuffer, address, T)){ //Head'in NULL olmamasi durumunda verilen adresi Cache Buffer'da arar, yoksa yeni bir node olusturur.
			struct NODE* temp = createNode(address); //Yeni bir node olusturur.
			(*cacheBuffer)->prev = temp; //Yeni node, basa eklenecegi icin eski node'un onceki degeri yeni node olarak tanimlanir.
			temp->next = *cacheBuffer; //Yeni node'un sonraki degeri, eski head olarak ayarlanir.
			*cacheBuffer = temp; //Head'i gunceller.
			(*nodeCount)++; //Cache Buffer'a yeni node eklendigi icin node sayisini arttirir.
		}			
	}
	
	if((*nodeCount) > L){ //Yeni node eklenmesiyle node sayisi eger Cache Buffer'in kapasitesini geciyorsa sondaki node silinir.
		deleteLastNode(cacheBuffer); //Kosulun saglanmasiyla sondaki node'u siler.
		(*nodeCount)--; //Cache Buffer'dan node silindigi icin node sayisini azaltir.
	}
}

/*
@brief Cache Buffer'a eklenmek uzere yeni node olusturur.

@param address, Node'a eklenecek adres.

@return Olusturulan yeni node'un adresi dondurulur.
*/
struct NODE* createNode(char* address){
	struct NODE* newNode = (struct NODE*) malloc(sizeof(struct NODE)); //Yeni node olusturulur.
	newNode->address = (char *) malloc((strlen(address)+1)*sizeof(char)); //Node'un adresine kaydedilecek adresin boyutunda yer acilir.
	strcpy(newNode->address, address); //Node'un adresine adres kopyalanir. Ayrica yandaki kod ile ustteki satira gerek kalmadan da bu kopyalama islemi yapilabilir. newNode->address = strdup(address);	
	newNode->count = 1; //Guncel olarak node'da adrese ait 1 tane sayfa oldugundan sayaci 1 yapilir.
	newNode->prev = NULL; //onceki ve sonraki node'lar NULL olarak atanir,
	newNode->next = NULL; //degistirilmesi gerekiyorsa diger fonksiyonlarda gerceklestirilir.
}

/*
@brief Verilen adresin Cache Buffer'da olup olmadigini kontrol eder, varsa sayacini arttirir ve esik degerini gecmesi durumunda Cache Buffer'in basina tasir.

@param cacheBuffer, Double Linked List yapisinin Head degeri
@param address, Cache Buffer'da aranacak olan adres.
@param T, esik degerini tutan degisken

@return Adresin Cache Buffer'da bulunmasi durumunda 1, diger durumlardaysa 0 dondurur.
*/
int searchAddress(struct NODE** cacheBuffer, char* address, int T){
	struct NODE* temp = *cacheBuffer; //Cache Buffer uzerinde gezinme yapilacagindan head'i kaybetmemsi icin gecici degiskene atanir.
	
	while(temp != NULL){ //Cache Buffer'daki elemanlar bitene kadar listeyi gezer.
		if(!strcmp(temp->address, address)){ //Verilen adresin Cache Buffer'da bulunmasi durumunda sayacini arttirir.
			temp->count = temp->count + 1;
			if(temp != (*cacheBuffer) && temp->count > T){ //Adresin bulundugu node head'den farkliysa ve esik degerinin ustundeyse node'u head'e tasir.
				if(temp->next != NULL){ //Adresin bulundugu node Cache Buffer'da en son sirada degilse alttaki islemi gerceklestirir.
					temp->next->prev = temp->prev;
				}
				temp->prev->next = temp->next; //Adresin bulundugu node'u head'e tasir.				
				(*cacheBuffer)->prev = temp;
				temp->prev = NULL;
				temp->next = (*cacheBuffer);
				(*cacheBuffer) = temp;
			}
			return 1;
		}else{
			temp = temp->next;
		}
	}
	return 0;
}

/*
@brief Cache Buffer'daki son node'u temizler.

@param cacheBuffer, Double Linked List yapisinin Head degeri

@return
*/
void deleteLastNode(struct NODE** cacheBuffer){
	struct NODE* temp = *cacheBuffer;

	while(temp->next!=NULL){ //Son node'u bulur.
		temp = temp->next;
	}
	temp->prev->next = NULL; //Sondan bir onceki node'un sonraki degerini NULL yapar.
	free(temp); //Sondaki node'y siler.
}

/*
@brief Cache Buffer'daki elemanlari ekrana yazdirir.

@param cacheBuffer, Double Linked List yapisinin Head degeri

@return
*/
void printList(struct NODE* cacheBuffer){
	struct NODE* temp = cacheBuffer;
	while(temp != NULL){
		printf("%s,%d ", temp->address, temp->count);
		temp = temp->next;
	}
	printf("\n");
}

/*
@brief Cache Buffer'daki elemanlari kullanici karariyla temizler.

@param cacheBuffer, Double Linked List yapisinin Head degeri

@return
*/
void clearList(struct NODE** cacheBuffer){
	char choice;
	if((*cacheBuffer) != NULL){ //Cache Buffer'in bos olmasi durumunda herhangi bir sey yapmaz.
		printf("\nDo you want to clear the cache? (Y/N): ");
		scanf(" %c",&choice);
		
		if(choice == 'Y' || choice == 'y'){
			struct NODE* temp;
			while((*cacheBuffer) != NULL){ //Cache Buffer'daki elemanlari temizler.
				temp = *cacheBuffer;
				(*cacheBuffer) = (*cacheBuffer)->next;
				free(temp);
			}
			printf("Cache has been cleared.");
		}else{
			printf("Cache has not been cleared.");
		}
	}	
}
