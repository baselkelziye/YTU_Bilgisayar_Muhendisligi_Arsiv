#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Bolunen dizilerin baslangic ve bitis indislerini tutan struct.
struct ArrInfo{
	int left;
	int right;
};

//Heap yapisinda bulunan her bir dugum.
struct HeapNode{
	int value; //Dugumun degeri.
	int arrIndex; //Degerin bulundugu dizinin indisi.
};

void swap(int* x, int* y);
int* createArray(int N);
void printArray(int* array, int N);
void insertionSort(int* array, int left, int right);
void selectionSort(int *array, int left, int right);
void heapifyBackwards(struct HeapNode* minHeap, int i);
void insert(struct HeapNode* minHeap, int* N, int value, int arrIndex);
void heapify(struct HeapNode* minHeap, int N, int i);
struct HeapNode pop(struct HeapNode* minHeap, int *N);
void kWayMergeSort(int* array, int left, int right, int k);
void kWayMerge(int* array, struct ArrInfo* subArrays, int size, int k);
void test();
void manual();

int main(){
	int choice;
	
	srand(time(NULL));
	
	do{
		printf("1- Manuel Giris\n");
		printf("2- Test\n");
		printf("3- Cikis\n");
		printf("Seciminiz: ");
		scanf("%d", &choice);
		
		if(choice == 1)
			manual();
		else if(choice == 2)
			test();
		else if(choice == 3)
			printf("Cikis yapiliyor...");
		else
			printf("Hatali giris yaptiniz!\n");
	}while(choice != 3);
	
	return 0;
}

/*
@brief Verilen iki sayinin degerini degistirir.

@param x, ilk degerin adresi.
@param y, ikinci degerin adresi.

@return
*/
void swap(int* x, int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

/*
@brief [1,N] araligindaki sayilari karisik iceren diziyi olusturur.

@param N, dizinin eleman sayisi.

@return Olusturulan diziyi dondurur.
*/
int* createArray(int N){
	int* array = (int*) malloc(N*sizeof(int));
	int i, index, temp;
	
	//Diziye [1,N] araligindaki elemanlar sirayla yerlestirilir.
	for(i=0; i<N; i++){
		array[i] = i+1;
	}
	
	//Sondan baslanarak rastgele indis secilir ve sondaki eleman ile secilen
	//indisdeki eleman yer degistirir. Boylece dizi, O(N) karmasikliginda olusturulur.
	for(i=N-1; i>0; i--){
		index = rand()%(i+1);
		swap(&array[i], &array[index]);
	}
	
	return array;
}

/*
@brief Verilen N elemanli diziyi ekrana yazdirir.

@param array, yazdirilacak dizi.
@param N, dizinin eleman sayisi.

@return
*/
void printArray(int* array, int N){
	int i;
	for(i=0;i<N;i++){
		printf("%d ",array[i]);
	}
	printf("\n");
}

/*
@brief Verilen dizinin ilgili kismini siralar.

@param array, ilgili kismi siralanacak dizi.
@param left, siralanacak kismin baslangic indisi.
@param right, siralanacak kismin son indisi.

@return
*/
void selectionSort(int *array, int left, int right){
	int i,j;
	int min;
	for(i=left;i<right-1;i++){
		min = i;
		for(j=i+1;j<right;j++){
			if(array[j] < array[min]){
				min = j;
			}
		}
		if(min != i){
			swap(&array[i], &array[min]);
		}
	}
}

/*
@brief Verilen dizinin ilgili kismini siralar.

@param array, ilgili kismi siralanacak dizi.
@param left, siralanacak kismin baslangic indisi.
@param right, siralanacak kismin son indisi.

@return
*/
void insertionSort(int* array, int left, int right){
	int i,j;
	for(i=left+1;i<right;i++){
		j = i;
		while(j>left && array[j]<array[j-1]){
			swap(&array[j], &array[j-1]);
			j--;
		}
	}
}

/*
@brief Verilen heap yapisini i. indisden geriye dogru heapify islemini gerceklestirir.

@param minHeap, heap yapisi.
@param i, heapify islemi yapilacak indis.

@return
*/
void heapifyBackwards(struct HeapNode* minHeap, int i){
	int parent = (i-1) / 2;
	
	if(parent>=0 && (minHeap[i].value < minHeap[parent].value)){
		swap(&minHeap[i].value, &minHeap[parent].value);
		swap(&minHeap[i].arrIndex, &minHeap[parent].arrIndex);
		heapifyBackwards(minHeap, parent);
	}
}

/*
@brief Verilen heap yapisina verilen degerleri ekler.

@param minHeap, heap yapisi.
@param N, heap boyutu.
@param value, heap'e eklenecek deger.
@param arrIndex, degerin bulundugu dizinin indisi.

@return
*/
void insert(struct HeapNode* minHeap, int* N, int value, int arrIndex){
	minHeap[*N].value = value;
	minHeap[*N].arrIndex = arrIndex;
	*N = *N + 1;
	heapifyBackwards(minHeap, *N-1);
}

/*
@brief Verilen heap yapisini i. indisden baslayarak heapify islemini gerceklestirir.

@param minHeap, heap yapisi.
@param N, heap boyutu.
@param i, heapify islemi yapilacak indis.

@return
*/
void heapify(struct HeapNode* minHeap, int N, int i){
	int min = i;
	int left = 2*i + 1;
	int right = 2*i + 2;
	
	if(left<N && minHeap[left].value < minHeap[min].value){
		min = left;
	}
	
	if(right<N && minHeap[right].value < minHeap[min].value){
		min = right;
	}
	
	if(min != i){
		swap(&minHeap[min].value, &minHeap[i].value);
		swap(&minHeap[min].arrIndex, &minHeap[i].arrIndex);
		heapify(minHeap, N, min);
	}
}

/*
@brief Verilen heap yapisindan en kucuk degeri cikartir ve cikartilan degeri dondurur.

@param minHeap, heap yapisi.
@param N, heap boyutu.

@return Heap'de bulunan en kucuk degere ait HeapNode dugumu dondurulur.
*/
struct HeapNode pop(struct HeapNode* minHeap, int *N){
	struct HeapNode popped;
	popped.value = minHeap[0].value;
	popped.arrIndex = minHeap[0].arrIndex;
	minHeap[0].value = minHeap[*N - 1].value;
	minHeap[0].arrIndex = minHeap[*N - 1].arrIndex;
	*N = *N - 1;
	heapify(minHeap, *N, 0);
	return popped;	
}

/*
@brief Sinirlari verilen dizinin ilgili bolumunu k parcaya bolerek siralama islemini gerceklestirir.

@param array, siralanacak dizi.
@param left, dizinin baslangic siniri.
@param right, dizinin bitis siniri.
@param k, dizinin kac parcaya bolunecegi.

@return 
*/
void kWayMergeSort(int* array, int left, int right, int k){
	int size = right - left;

	if(size < k){ //Egerki dizinin boyutu bolunecek k sayisindan kucukse dizi, insertion sort ile siralanir.
		insertionSort(array, left, right);
//		selectionSort(array, left, right); //neredeyse insertionSort ile ayni		
//		kWayMergeSort(array, left, right, size); //diger iki siralamadan daha yavas	
		return;
	}
	
	int subArraySize = size / k, i;
	struct ArrInfo* subArrays = (struct ArrInfo*) malloc(k*sizeof(struct ArrInfo));
	
	//Her parcanin baslangic ve bitis indisleri ArrInfo struct yapisinda saklanir.
	for(i=0; i<k-1; i++){
		subArrays[i].left = subArraySize*i + left;
		subArrays[i].right = subArraySize*(i+1) + left;
		
		kWayMergeSort(array, subArrays[i].left, subArrays[i].right, k); //Bolunen dizi de k parcaya ayrilir.
	}
	subArrays[i].left = subArraySize*i + left;
	subArrays[i].right = right; //Dizi k'ya her zaman tam bolunemecegi icin son parcanin bitis indisi verilen bitis indisi olarak tanimlanir.
	kWayMergeSort(array, subArrays[i].left, right, k); //Son parcada k parcaya ayrilir.
	
	kWayMerge(array, subArrays, size, k); //Bolunen sirali parcalari sirali bir sekilde birlestirir.
	
	free(subArrays);
}

/*
@brief Verilen dizinin k adet bolunmus kismini sirali bir bicimde birlestirir.

@param array, degerlerin bulundugu dizi.
@param subArrays, bolunen dizilerin baslangic ve bitis indislerini tutan struct.
@param size, birlestirilecek toplam eleman sayisi.
@param k, bolunmus dizi sayisi.

@return 
*/
void kWayMerge(int* array, struct ArrInfo* subArrays, int size, int k){
	int index = 0, start = subArrays[0].left, minHeapSize = 0, i;
	int* sortedArray = (int*) malloc(size*sizeof(int));
	struct HeapNode* minHeap = (struct HeapNode*) malloc(k*sizeof(struct HeapNode));
	
	//k sirali dizinin en kucuk elemanlarini heap yapisina ekler.
	for(i=0; i<k; i++){
		insert(minHeap, &minHeapSize, array[subArrays[i].left++], i);
	}
	
	//Heap'de bulunan en kucuk elemani alir, sirali diziye ekler.
	//Alinan degerin bulundugu parcada eleman kaldiysa kalan en kucuk elemani heap'e ekler.
	//Bolunmus dizilerde eleman kalmayana kadar bu islem devam eder.
	while(minHeapSize != 0){
		struct HeapNode popped = pop(minHeap, &minHeapSize);
		sortedArray[index++] = popped.value;
		if(subArrays[popped.arrIndex].left != subArrays[popped.arrIndex].right){
			insert(minHeap, &minHeapSize, array[subArrays[popped.arrIndex].left++], popped.arrIndex);
		}
	}	
	
	//Sirali dizideki elemanlari verilen diziye baslangic indisinden itibaren yerlestirir.
	for(i=0; i<size; i++){
		array[start++] = sortedArray[i];
	}

	free(minHeap);
	free(sortedArray);
}

/*
@brief Kullanicidan alinan N ve k degerine gore karisik dizi olusturur ve siralar.

@return 
*/
void manual(){
	int i, N, k;
	
	do{
		printf("\nDizinin boyutunu giriniz: ");
		scanf("%d", &N);
		if(N<1){
			printf("Dizinin boyutunu yanlis girdiniz! (N>0)\n");
		}
	}while(N<1);
	
	do{
		printf("      k degerini giriniz: ");
		scanf("%d", &k);
		if(k<2){
			printf("k degerini yanlis girdiniz! (k>1)\n\n");
		}
	}while(k<2);
	
	
	int* array = createArray(N);
	
	if(N<=1000){
		printf("\nSirasiz Dizi: ");
		printArray(array, N);
	}
	
	clock_t start = clock();
	kWayMergeSort(array, 0, N, k);
	clock_t end = clock();
	
	if(N<=1000){
		printf(" Sirali Dizi: ");
		printArray(array, N);
	}
	
	for(i=0; i<N; i++){
		if(array[i] != i+1){
			printf("Siralama islemi basarisiz!");
			exit(0);
		}
	}
	printf("Siralama islemi %lf saniyede tamamlandi!\n\n", ((double) (end - start) / CLOCKS_PER_SEC));
	
	free(array);
}

/*
@brief Istenilen degerler icin programi calistirir.

@return 
*/
void test(){
	int N, k, i;
	
	printf("\n");
	for(N=100; N<10000001; N*=10){
		int** arrays = (int**) malloc(10*sizeof(int*));
		int* temp = (int*) malloc(N*sizeof(int));
		
		for(i=0; i<10; i++){
			arrays[i] = createArray(N);
		}
		
		for(k=2; k<11; k++){
			double time = 0;
			for(i=0; i<10; i++){
				memcpy(temp, arrays[i], N*sizeof(int));
				clock_t start = clock();
				kWayMergeSort(temp, 0, N, k);
				clock_t end = clock();
				time += ((double) (end - start) / CLOCKS_PER_SEC);
			}
			printf("N: %d, k: %2d, sure: %lf saniye\n", N, k, time/10);
		}
		
		for(i=0; i<10; i++){
			free(arrays[i]);
		}
		free(arrays);
		free(temp);
	}
	printf("\n");
}
