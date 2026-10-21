#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct user{
	int userId;
	struct user* next;
}USER;


void hash(int t,int m,int k,USER** table,int* iterationPtr,USER* user);
USER* createUser(int id);
void hashTableInsertSeparateChaining(USER* user,int index,USER** hashTable);
void hashTableInsertLinearProbing(USER* user,int index,USER** hashTable);
int isPrime(int n);
int getNearestPrime(int n);
void calculateAndPrintIterationInfos(int* iterationArray,int n);
void freeHashTable(USER** hashTable, int n);

int main(){
	FILE *fp = fopen("ID-1_5M.txt", "r");
    if (!fp) {
        printf("Cannot open file.\n");
        return 1;
    }
    
    int i,j,id,placed;
	int k,n,tableSize;
    USER* tmpUser;
    
    fscanf(fp, "%d", &n);//kullanici sayisinin dosyadan okunmasi
	
	tableSize=getNearestPrime(n/10);//hesap sayisinin 10’a bolumune en yakin olan asal sayý
	
	USER** hashTable=(USER**)calloc(tableSize,sizeof(USER*));//hashtable olusturulmasi
	if(hashTable==NULL){
		printf("Memory allocation for hashTable unsucceeded\n");
	}
	
	
	int* iterationArray=(int*)malloc(n*sizeof(int));//her bir sayinin kac iterasyonda yerlestigi yazilacak dizi
	if(iterationArray==NULL){
		printf("Memory allocation for iterationArray unsucceeded\n");
	}
	
	
	printf("Lutfen k sayisini girin: ");
	scanf("%d",&k);
	
	
	//dosyadan tek tek elemanlarin okunmasi
	for(i=0;i<n;i++){
		if(fscanf(fp,"%d",&id)==1){//her bir idnin dosyadan okunmasi
			tmpUser=createUser(id);//user olusturulmasi
			hash(id,tableSize,k,hashTable,&iterationArray[i],tmpUser);//userin hash tablosuna eklenmesi
		}
	}
	
	calculateAndPrintIterationInfos(iterationArray,n);
	
	//free
	freeHashTable(hashTable,tableSize);
	free(iterationArray);
	return 0;
}


//----------------------------------FONKSIYONLAR----------------------------------------------------------
/*
@brief Verilen kullaniciyi linear probing ya da separate chaining ile hash tablosuna ekler.
@param t Hashlenecek id
@param m Hash tablosunun boyutu
@param k Linear probing icin maksimum deneme sayisi
@param table hash tablosu
@param iterationPtr Ekleme islemi sirasindaki iterasyon sayisini diziye yazmak icin kullanilan pointer
@param user Eklenecek olan kullanici yapisi
@return
*/
void hash(int t,int m,int k,USER** table,int* iterationPtr,USER* user){//h(t) = t mod m
	int i=0,index,firstIndex;
	firstIndex=t%m;
	
	if(table[firstIndex]==NULL) {//eger hash fonksiyonunun sonucu olan ilk adres bossa yerlestirilmesi
		*iterationPtr=1;
		hashTableInsertLinearProbing(user,firstIndex,table);
		return;
	}
	//linear probing section
	for(i=1;i<k;i++){//hash fonksiyonunun sonucu olan ilk bos adres bulunana kadar veya max iterasyon sinirina ulasana kadar dongu
		index=(firstIndex+i)%m;
		
		if(table[index]==NULL){//hash fonksiyonunun sonucu olan bos bir adrese yerlestirilmesi
			*iterationPtr=i+1;
			hashTableInsertLinearProbing(user,index,table);
			return;
		}
	}
	//lineer probing icin max iterasyon sayisina ulasýlmýssa seperate chaining ile tabloya eklenmesi
	*iterationPtr=k+1;
	hashTableInsertSeparateChaining(user,firstIndex,table);
}
/*
@brief verilen id ile yeni user olusturur.
@param id olusturulacak yeni userin idsi
@return olusturulan yeni useri dondurur.
*/
USER* createUser(int id){
	USER* newUser=(USER*)malloc(sizeof(USER));
	newUser->userId=id;
	newUser->next=NULL;
	return newUser;
}
/*
@brief Maksimum denemeye ulasilinca elemani ilk indexteki linkli listenin basina ekler.(separate chaining)
@param user Eklenecek kullanici
@param index Ekleme yapilacak tablo indexi
@param hashTable hash tablosu
@return
*/
void hashTableInsertSeparateChaining(USER* user,int index,USER** hashTable){
	if(hashTable[index]==NULL){
		hashTable[index]=user;
	}else{
		user->next=hashTable[index];
		hashTable[index]=user;
	}
}
/*
@brief Linear probing ile bulunan bos bir hucreye kullaniciyi yerlestirir.
@param user Eklenecek kullanici
@param index Ekleme yapilacak tablo indexi
@param hashTable hash tablosu
@return
*/
void hashTableInsertLinearProbing(USER* user,int index,USER** hashTable){
	if(hashTable[index]==NULL){
		hashTable[index]=user;
	}
}
/*
@brief verilen sayiyi asal sayiysa 1 degilse 0 donduren fonksiyon
@param n asalligi kontrol edilecek sayi
@return asal sayiysa 1 degilse 0 dondurur.
*/
int isPrime(int n){
	int i,sqrtn,prime=-1;
	if(n<2) return 0;
	if(n==2) return 1;
	if(n%2 == 0) return 0;
	
	sqrtn=sqrt(n);
	i=3;
	while(i<=sqrtn && prime<0){
		if(n%i == 0){
			prime=0;
		}
		i+=2;
	}
	if(prime==0){
		return 0;
	}else{
		return 1;
	}
}
/*
@brief verilen sayiyi asal sayiya en yakýn asal sayiyi donduren fonksiyon
@param n en yakin asal sayisi buluncacak sayi
@return en yakin asal sayiyi dondurur
*/
int getNearestPrime(int n){
	if(isPrime(n)) return n;
	
	int left=n-1,right=n+1,result=0;
	while(result==0){
		if(isPrime(right)) result=right;
		if(isPrime(left)) result=left;
		
		left--;
		right++;
	}
	return result;
}
/*
@brief Iterasyon dizisindeki verileri analiz ederek toplam ve ortalama iterasyon sayilarini yazdirir.
@param iterationArray Yapilan hash islemlerindeki iterasyon sayilarini tutan dizi
@param n Dizinin boyutu
@return
*/
void calculateAndPrintIterationInfos(int* iterationArray,int n){
	int i,totalIterations=0;
    float averageIterations;
    for (i = 0; i < n; i++) {
        totalIterations+=iterationArray[i];
    }
	averageIterations=(float)totalIterations/n;
	printf("\nTotal iterations: %d\n", totalIterations);
    printf("Average iterations per test: %.2f\n", averageIterations);
}
/*
@brief Hash tablosunu ve her bir indisteki linkli listeleri bellekten serbest birakir.
@param hashTable Temizlenecek hash tablosu
@param n Tablonun boyutu
@return
*/
void freeHashTable(USER** hashTable, int n){
	int i;
	USER* temp;
    for (i = 0; i < n; i++) {
        USER* current = hashTable[i];
        while (current != NULL) {
            temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(hashTable);
}
