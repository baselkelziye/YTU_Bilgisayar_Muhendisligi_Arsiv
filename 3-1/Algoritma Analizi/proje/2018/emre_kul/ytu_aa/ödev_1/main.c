#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define STR_SIZE 128

struct Travel //Sefer bilgilerinin tutulduğu yapı
{
	char cityName[STR_SIZE];//Sefer ismi olarak kullanılacak
	int hour;//Sefer saati olarak kullanılacak 
	int minute;//Sefer dakikası olarak kullanılacak	
};

typedef struct Travel Travel;

/*
	void copyTravelData(Travel*,Travel*);
		2 farklı sefer bilgisini alır ve 2.sefer bilgisinin içeriğini 1. ye kopyalar.
	@1(Travel*) : Hedef sefer bilgisi, buraya diğer sefer bilgisi verisi kopyalanır.
	@2(Travel*) : Kaynak sefer bilgisi, buradaki sefer bilgisi diğerine kopyalanır.
*/
void copyTravelData(Travel*,Travel*);
/*
	void mergeSort(Travel*,int,int,char (*compare)(Travel*,Travel*));
		mergeSort sıralama algoritmasının uygulandığı fonksiyondur.
	@1(Travel*) : Sıralanacak sefer bilgileri
	@2(int) : Sıralanacak sefer bilgilerinin başlangıç adresi (left)
	@3(int) : Sıralanacak sefer bilgilerinin bitiş adresi (right)
	@4(char(*) (Travel*,Travel)) : Karşılaştırma işleminin yapılacağı callback fonksiyonu.
*/
void mergeSort(Travel*,int,int,char (*compare)(Travel*,Travel*));
/*
	void merge(Travel*,int,int,int,char (*compare)(Travel*,Travel*));
		Merge Sort algoritmasında kullanılan sıralı 2 diziyi birleştiren fonksiyondur.
	@1(Travel*) : Birleştirme işleminin yapılacağı dizi.
	@2(int) : Sol dizinin başlangıç değeri (left)
	@3(int) : Sol dizinin bitiş adresi sağ izinin başlangıç adresi (mid)
	@4(int) : Sağ dizinin bitiş adresi(right)
	@5(char(*) (Travel*,Travel)) : Karşılaştırma işleminin yapılacağı callback fonksiyonu.
*/
void merge(Travel*,int,int,int,char (*compare)(Travel*,Travel*));
/*
	void printTravels(char*,Travel*,int);
		Sefer bilgilerin tutulduğu diziyi ekrana yazdıran fonksiyon.
	@1(char*) : Başlık olarak ekrana yazılacak stringi tutan parametre.
	@2(Travel*) : Ekrana yazılacak sefer bilgileri dizisi
	@3(int) : Sefer bilgilerinin tutulduğu dizinin boyutu
*/
void printTravels(char*,Travel*,int);
/*
	char compareByTravelName(Travel*,Travel*);
		2 sefer bilgisini isme göre karşılaştırır.	
	@1(Travel*) : Karşılaştırılacak sefer bilgilerinden 1'i.
	@2(Travel*) : Karşılaştırılacak sefer bilgilerinden 1'i.
	@return (char) : 1. sefer şehir ismi alfabatik olarak 2.den önce ise 1 döner.
*/
char compareByTravelName(Travel*,Travel*);
/*
	char compareByTravelTime(Travel*,Travel*);
		2 sefer bilgisini zamana göre karşılaştırır.
	@1(Travel*) : Karşılaştırılacak sefer bilgilerinden 1'i.
	@2(Travel*) : Karşılaştırılacak sefer bilgilerinden 1'i.
	@return (char) : 1. sefer bilgisi zaman olarak 2. den öndeyse (1) değerini döndürür.
*/
char compareByTravelTime(Travel*,Travel*);
/*
	void mainSort(Travel*,int);
		Ana sıralama işleminin yapıldığı bölüm.
	@1(Travel*) : sefer bilgilerinin bulunduğu dizi.
	@2(int) : sefer bilgilerinin bulunduğu dizinin boyutu.
*/
void mainSort(Travel*,int);

int main(){
	FILE *file = fopen("inputs","r");//Input işlemleri için kullanılacak dosya.
	Travel *travels;//Sefer bilgileri dizisi.
	int i = 0;//Genel amaçlı itterasyon değişkeni
	int travelSize;//Kaç adet sefer bilgisi olduğu bilgisini tutar
	fscanf(file,"%d",&travelSize);
	travels = (Travel*)malloc(travelSize*sizeof(Travel));
	while(i < travelSize){
		fscanf(file,"%s %d:%d",travels[i].cityName,&(travels[i].hour),&(travels[i].minute));
		i++;
	}
	mainSort(travels,travelSize);
	return 0;
}
void mainSort(Travel *travels,int travelSize){
	char tmpCityName[STR_SIZE];//Aynı şehirleri kendi içinde saatlere göre dizmeden önce start ve end noktalarını bulmak için kullanılacak geçici şehir ismi.
	int tmpStartIndex = 0;//Geçici şehir isminin başlangıç indexi.
	int i;//Genel amaçlı iterasyon deişkeni.

	printTravels("Travels Before Sorting : ",travels,travelSize);
	mergeSort(travels,0,travelSize-1,compareByTravelName);
	printTravels("Travels After First Sorting : ",travels,travelSize);
	strcpy(tmpCityName,travels[0].cityName);
	for(i = 1;i < travelSize;i++){
		if(strcmp(tmpCityName,travels[i].cityName) != 0){
			mergeSort(travels,tmpStartIndex,i-1,compareByTravelTime);
			tmpStartIndex = i;
			strcpy(tmpCityName,travels[i].cityName);
		}
	}
	mergeSort(travels,tmpStartIndex,travelSize-1,compareByTravelTime);
	printTravels("Travels After Second Sorting : ",travels,travelSize);
}
void mergeSort(Travel* travels,int l,int r,char (*compare)(Travel*,Travel*)){
	int m = (l+r)/2;//Mid indexi
	if(r > l){
		mergeSort(travels,m+1,r,compare);
		mergeSort(travels,l,m,compare);
		merge(travels,l,m,r,compare);
	}
}
void merge(Travel *travels,int l,int m,int r,char (*compare)(Travel*,Travel*)){
	int leftMax = m+1;//Sol dizinin maximum adresi
	int leftIndex = l;//Sol dizinin başlangıç adresi
	int rightMax = r+1;//Sağ dizinin maximum adresi
	int rightIndex = m+1;//sağ dizinin başlangıç değeri
	int tmpIndex = 0;//Kopya dizinin adres bilgisini tutan değişken.
	int i;//Genel amaçlı iterasyon değişkeni
	Travel *tmpTravel = (Travel*)malloc( (r-l+1) * sizeof(Travel) ); 
	while(leftIndex < leftMax && rightIndex < rightMax){
		if(compare(&travels[leftIndex],&travels[rightIndex])){
			copyTravelData(&tmpTravel[tmpIndex],&travels[leftIndex]);
			leftIndex++;
		}
		else{
			copyTravelData(&tmpTravel[tmpIndex],&travels[rightIndex]);
			rightIndex++;	
		}
		tmpIndex++;
	}

	while(leftIndex < leftMax){
		copyTravelData(&tmpTravel[tmpIndex],&travels[leftIndex]);
		leftIndex++;	
		tmpIndex++;
	}
	
	while(rightIndex < rightMax){
		copyTravelData(&tmpTravel[tmpIndex],&travels[rightIndex]);
		rightIndex++;
		tmpIndex++;
	}

	for(i = 0;i < tmpIndex;i++){
		copyTravelData( &travels[l],  &tmpTravel[i] );
		l++; 
	}
	
	free(tmpTravel);
}
void copyTravelData(Travel *target,Travel *source){
	target->hour = source->hour;
	target->minute = source->minute;
	strcpy(target->cityName,source->cityName);	
}

void printTravels(char *title,Travel *travels,int travelSize){
	int i;//iterasyon değişkeni
	printf("%s\n",title);
	for(i = 0;i < travelSize;i++){
		printf("%s --------> %d:%d\n",travels[i].cityName,travels[i].hour,travels[i].minute);
	}
	printf("\n");
}

char compareByTravelName(Travel *t1,Travel *t2){
	return strcmp(t1->cityName,t2->cityName) < 0;
}
char compareByTravelTime(Travel *t1,Travel *t2){
	return (t1->hour < t2->hour) || (t1->hour == t2->hour && t1->minute < t2->minute); 
}