#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void priorityQueue();
int** getMatrix(int *N, int *M, int **capacity);
void shuffle(int* array, int N);
void printMatrix(int** matrix, int N, int M);
void heapify(int* array, int N, int i);
void swap(int* x, int* y);
void heapifyMatrix(int **matrix, int N, int *capacity);
int findMax(int **matrix, int N);
void deleteMax(int **matrix, int index, int *capacity);
void freeMatrix(int** matrix, int N);

int main(){
	int choice;
	srand(time(NULL));
	
	do{
		printf("1- Priority Queue\n");
		printf("0- Exit\n");
		printf("Choice : ");
		scanf("%d", &choice);
		
		if(choice == 1){ // Secimin 1 olmasiyla oncelikli kuyruk islemi baslatilir.
			priorityQueue();
		}else if(choice == 0){
			printf("Exiting...");
		}else{
			printf("You made a wrong choice!\n\n");
		}
	}while(choice); // Secim 0'dan farkli oldugu surece dongu devam eder.

	return 0;
}

/*
@brief Kullanicidan matris boyutlarini alarak oncelikli kuyruk yapisini gerceklestirir.

@return 
*/
void priorityQueue(){
	int N, M; // Matris boyutlari.
	int i;
	int max; // Kuyruklarin bas kisminda bulunan elemanlar arasindan en buyuk olani.	
	int count = 0; // Bosalan kuyruk sayisi.
	int *capacity;	// Kuyruklarin kapasitelerini tutan dizi.
	int **matrix = getMatrix(&N, &M, &capacity); // Matris rastgele olusturulur ve kapasite bilgileri kullanicidan alinir.
	int *emptyQueues = (int *) malloc(N*sizeof(int)); // Sirasiyla bosalan kuyruklarin matrisdeki indisleri
	
	
	printf("\n    Random Matrix\n");
	printMatrix(matrix, N, M);
	
	heapifyMatrix(matrix, N, capacity); // Rastgele sayilarla yerlestirilen matris heapify edilir.
	printf("    Heapified Matrix\n");
	printMatrix(matrix, N, M);	
	
	while(count < N){ // Kuyruklar bosalana kadar dongu devam eder.
		max = findMax(matrix, N); // Kuyruklarin bas kisminda bulunan elemanlar arasindan en buyuk olani bulunur.
		printf("Queue-%d: %d, deleted.\n", max+1, matrix[max][0]);
		deleteMax(matrix, max, capacity); // En buyuk eleman ilgili kuyruktan silinir.		
		printMatrix(matrix, N, M);
		if(capacity[max] == 0){ // Elemanin silinmesiyle ilgili kuyruk bosaliyorsa bir sonraki bosalan kuyruk sirasina kaydedilir.
			emptyQueues[count++] = max + 1;
		}
	}
	
	printf("    Queues emptied in sequence\n");
	for(i=0;i<N;i++){
		printf("%d ", emptyQueues[i]);
	}
	printf("\n\n");
	
	// Dinamik olarak tutulan diziler/matrisler temizlenir.
	freeMatrix(matrix, N); 
	free(emptyQueues);
	free(capacity);
}

/*
@brief Kullanicidan alinan matris boyutlarinda rastgele bir matris olusturur, ardindan bu matriste tutulacak olan kuyruklarin kapasitelerini
	   yine kullanicidan alir.
	   
@param N, matrisin satir sayisi.
@param M, matrisin sutun sayisi.
@param capacity, kuyruklarin kapasitelerini tutan dizi.

@return Olusturulan rastgele matris dondurulur.
*/
int** getMatrix(int *N, int *M, int **capacity){
	int n,m;
	int i = 0, k = 0, j;
	int K; // Rastgele uretilecek olan sayilarin ust siniri.
	int *capacities, *randomNumbers;
	int **matrix;
	
	printf("\n");
	do{
		printf("Enter number of rows: ");
		scanf("%d", &n);
		if(n < 1){
			printf("Number of rows must be greater than 0!\n");
		}
	}while(n < 1); // Satir sayisi 0'dan buyuk olana kadar kullanicidan alinir.
	*N = n;
	
	do{
		printf("Enter number of columns: ");
		scanf("%d", &m);
		if(m < 1){
			printf("Number of columns must be greater than 0!\n");
		}
	}while(m < 1); // Sutun sayisi 0'dan buyuk olana kadar kullanicidan alinir.
	*M = m;
	
	printf("\n");
	capacities = (int *) malloc(n*sizeof(int));
	while(i<n){ // Kuyruklarin kapasiteleri 0'dan buyuk olana kadar kullanicidan alinir.
		printf("Capacity of queue %d: ",i+1);
		scanf("%d", &capacities[i]);
		if(capacities[i]<1){
			printf("Capacity must be greater than 0!\n");
		}else if(capacities[i]>m){
			printf("Capacity must not exceed the number of columns!\n");
		}else{
			i++;
		}
	}
	*capacity = capacities;
	
	K = n*m + n + m; // K > N*M olacak sekilde rastgele olusacak olan sayilarin ust siniri belirlenir.
	randomNumbers = (int *) malloc(K*sizeof(int));
	for(i=0;i<K;i++){ // 0-K arasi sayilar dizinin ilgili indislerine yazilir.
		randomNumbers[i] = i;
	}
	shuffle(randomNumbers, K); // Dizi karistirilarak rastgele essiz sayilar elde edilir.
	
	matrix = (int **) malloc(n*sizeof(int*));
	for(i=0;i<n;i++){
		matrix[i] = (int *) malloc(m*sizeof(int));
	}
	
	for(i=0;i<n;i++){ // Matriste bulunan her kuyruga kapasitesi kadar rastgele diziden eleman eklenir.
		for(j=0;j<capacities[i];j++){
			matrix[i][j] = randomNumbers[k++];
		}
		for(j;j<m;j++){ // Kapasitenin sutun sayisindan kucuk olmasiyla birlikte kalan bos yerler '-1' ile doldurulur.
			matrix[i][j] = -1; 
		}
	}

	free(randomNumbers); // Rastgele olusturulan sayilar serbest birakilir.
	return matrix;
}

/*
@brief Verilen N boyutlu diziyi karistirir.

@param array, karistirilacak dizi.
@param N, karistirilacak dizinin boyutu.

@return 
*/
void shuffle(int* array, int N){
	int index, temp;		
	int i;
	
	for(i=N-1;i>0;i--){ // Dizinin sonuna dogru rastgele indisdeki eleman yerlestirilir.
		index = rand()%i;
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;
	}
}

/*
@brief Verilen NxM boyutlu matrisi yazdirir.

@param matrix, yazdirilacak matris.
@param N, yazdirilacak matrisin satir sayisi.
@param M, yazdirilacak matrisin sutun sayisi.

@return 
*/
void printMatrix(int** matrix, int N, int M){
	int i,j;
	
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){ // Yazdirma islemi duzgun gozukmesi icin %2d formatinda matris yazdirilir.
			printf("%2d ",matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

/*
@brief Verilen N boyutlu dizinin i. elemanini heapify eden ozyinemeli fonksiyon.

@param array, heapify edilecek dizi.
@param N, heapify edilecek dizinin boyutu.
@param i, dizide heapify edilecek eleman.

@return 
*/
void heapify(int* array, int N, int i){
	int largest = i;
	int left = 2*i + 1;
	int right = 2*i + 2;
	
	if(left<N && array[left] > array[largest]){ 
		largest = left;
	}
	
	if(right<N && array[right] > array[largest]){
		largest = right;
	}
	
	if(largest != i){
		swap(&array[largest], &array[i]);
		heapify(array, N, largest);
	}
} 

/*
@brief Verilen iki sayinin degerlerini degistirir.

@param x, ilk sayinin adresi.
@param y, ikinci sayinin adresi.

@return 
*/
void swap(int* x, int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

/*
@brief Verilen N satirli matristeki kuyruklarin hepsini heapify eder.

@param matrix, kuyruklarin bulundugu matris.
@param N, matrisin satir/kuyruk sayisi.
@param capacity, kuyruklarin boyutlari.

@return 
*/
void heapifyMatrix(int **matrix, int N, int *capacity){
	int i,j;
	
	for(i=0;i<N;i++){
		j = capacity[i]/2 - 1;
		for(j;j>=0;j--){
			heapify(matrix[i], capacity[i], j);
		}
	}
}

/*
@brief Verilen N satirli matristeki kuyruklarin basinda bulunan en buyuk elemani bulur.

@param matrix, kuyruklarin bulundugu matris.
@param N, matrisin satir/kuyruk sayisi.

@return Bulunan en buyuk sayinin bulundugu kuyrugun indisi dondurulur.
*/
int findMax(int **matrix, int N){
	int i;
	int max = 0;
	
	for(i=0;i<N;i++){
		if((matrix[i][0] != -1) && (matrix[max][0] < matrix[i][0])){
			max = i;
		}
	}

	return max;
}

/*
@brief Matristeki verilen indisdeki kuyruktaki en buyuk elemani kuyruktan siler.

@param matrix, kuyruklarin bulundugu matris.
@param index, en buyuk elemani silinecek olan kuyrugun indisi.
@param capacity, kuyruklarin boyutlari.

@return 
*/
void deleteMax(int **matrix, int index, int *capacity){
	capacity[index] = capacity[index] - 1; // N boyutlu kuyrugun son elemanin indisi N-1 olacagindan bu islem ilk basta gerceklestirilir.
	swap(&matrix[index][0], &matrix[index][capacity[index]]); // Basta bulunan en buyuk eleman son elemanla yer degistirir.
	matrix[index][capacity[index]] = -1; // Son eleman yani silinecek elemanin bulundugu indis '-1' olarak atanir.	
	heapify(matrix[index], capacity[index], 0); // Sondan basa gecen eleman heapify edilerek matrisin yeni maksimum degeri ilk elemana yazilir.
}

/*
@brief Verilen N satirli matrisi bellekten temizler.

@param matrix, kuyruklarin bulundugu matris.
@param N, matrisin satir/kuyruk sayisi.

@return
*/
void freeMatrix(int** matrix, int N){
	int i;
	
	for(i=0;i<N;i++){
		free(matrix[i]);
	}
	free(matrix);
}

