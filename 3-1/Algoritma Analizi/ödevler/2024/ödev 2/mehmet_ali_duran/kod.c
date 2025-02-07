#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

typedef struct {
    int value;         // Min-heap icindeki elemanin degeri
    int arrayIndex;    // Bu elemanin geldigi dizinin indeksi
    int nextIndex;     // Dizi icindeki bir sonraki elemanin indeksi
} MinHeapNode;

typedef struct {
    MinHeapNode *data; // Heap dugumlerinin tutuldugu dizi
    int size;          // Min-heap'in mevcut boyutu
    int capacity;      // Min-heap'in maksimum kapasitesi
} MinHeap;

void createRandomNumbers(int arr[], int N);
int* createArray(int N);
void releaseArray(int* arr);
void shuffle(int arr[], int N);
int* kWayMergeSort(int *arr, int n, int k);
int* mergeKSortedArrays(int **arr, int *sizes, int k, int *mergedSize);
MinHeapNode extractMin(MinHeap *minHeap);
void insertMinHeap(MinHeap *minHeap, MinHeapNode node);
void minHeapify(MinHeap *minHeap, int idx);
void swap(MinHeapNode *x, MinHeapNode *y);
MinHeap* createMinHeap(int capacity);
void swapNormal(int *a, int *b);

int main(){
    srand(time(NULL)); // Rastgele sayi uretimi icin seed degeri
    clock_t start, end; // Calisma suresini olcmek icin degiskenler
    int N, i, j, k; 
    int* arr;       
    int* sortedArr; 
    double timeElapsed; 
    
    
    //Sureleri dosyaya kaydetmek icin dosya
//	FILE *file = fopen("calisma_sureleri.txt", "a");
//	
//	if (file == NULL) {
//        printf("Dosya açýlamadý.\n");
//        return 1;  // Hata kodu ile çýk
//    }
    
	printf("N degerini giriniz: ");
	scanf("%d", &N);
	printf("k degerini giriniz: ");
	scanf("%d", &k);
	arr= createArray(N);
	createRandomNumbers(arr, N);
	printf("\nDizi siralanmadan once: \n");
	for(i=0;i<N;i++){
		printf("%d ", arr[i]);
	}
    start = clock();          
    printf("\nN = %d k = %d\n", N, k);
    sortedArr = kWayMergeSort(arr, N, k); 
    end = clock();            
    timeElapsed = ((double) end - start) / CLOCKS_PER_SEC; 
    printf("\nDizi siralandiktan sonra: \n");
	for(i=0;i<N;i++){
		printf("%d ", sortedArr[i]);
	}
    printf("\nk = %d icin calisma suresi: %f saniye\n", k, timeElapsed);
	releaseArray(arr); 	

////Test için gerekli kisimlar
//    for (N = 100; N < 10000001; N *= 10){ // Farkli dizi boyutlari icin dongu
//        for(i = 0; i < 10; i++){ // Her test 3 kere calistirilir
//            printf("N  = %d icin %d. calisma\n", N, i+1);
//            arr = createArray(N);         // N boyutunda dizi ayirma
//            createRandomNumbers(arr, N);  // Diziye rastgele sayilar atama
//            for(k=2; k<=10; k++){
//                start = clock();          // Baslangic zamanini kaydetme
//                printf("N = %d k = %d\n", N, k);
//                sortedArr = kWayMergeSort(arr, N, k); // k-way merge sort ile siralama
//                end = clock();            // Bitis zamanini kaydetme
//                timeElapsed = ((double) end - start) / CLOCKS_PER_SEC; // Calisma suresini hesaplama
//                fprintf(file, "N= %d k = %d icin calisma suresi: %f saniye\n", N, k, timeElapsed);
//                //printf("k = %d icin calisma suresi: %f saniye\n", k, timeElapsed);
//            }
//            releaseArray(arr); // Dizi icin ayrilan bellekteki alan bosaltilir
//        }
//    }
//    fclose(file);
    return 0;
}

/**
 * @brief Rastgele sayilar uretir ve diziye atar.
 * @param arr Sayilarin yerlestirilecegi dizi.
 * @param N Dizinin boyutu.
 */
void createRandomNumbers(int arr[], int N){
    int i;
    for(i = 0; i < N; i++){
        arr[i] = i + 1; 
    }
    shuffle(arr, N);
}

/**
 * @brief Belirtilen boyutta bir tamsayi dizisi icin bellek ayirir.
 * @param N Dizinin boyutu.
 * @return Ayrilan dizinin pointer'i.
 */
int* createArray(int N){
    int* arr;
    arr = (int*) malloc(N * sizeof(int));
    if(arr == NULL){
        printf("\nBellek ayrilamadi.\n");
        return NULL;
    } else {
        printf("\nBellek malloc ile basariyla ayrildi.\n");
    }
    return arr;
}

/**
 * @brief Bellekte ayrilan bir diziyi bosaltir.
 * @param arr Bosaltilacak dizinin pointer'i.
 */
void releaseArray(int* arr){
    free(arr);
}

/**
 * @brief Iki tamsayiyi takas eder.
 * @param a Ilk tamsayinin pointer'i.
 * @param b Ikinci tamsayinin pointer'i.
 */
void swapNormal(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Bir diziyi rastgele siraya dizir.
 * @param arr Rastgele siraya dizilecek dizi.
 * @param N Dizinin boyutu.
 */
void shuffle(int arr[], int N) {
    int i, j;
    for (i = N - 1; i > 0; i--) {
        j = rand() % (i + 1);  
        swapNormal(&arr[i], &arr[j]);
    }
}

/**
 * @brief Belirtilen kapasiteye sahip bir min-heap olusturur.
 * @param capacity Min-heap kapasitesi.
 * @return Olusturulan min-heap'in pointer'i.
 */
MinHeap* createMinHeap(int capacity) {
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
    minHeap->data = (MinHeapNode *)malloc(capacity * sizeof(MinHeapNode));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    return minHeap;
}

/**
 * @brief Iki MinHeapNode elemanini takas eder.
 * @param x Ilk dugumun pointer'i.
 * @param y Ikinci dugumun pointer'i.
 */
void swap(MinHeapNode *x, MinHeapNode *y) {
    MinHeapNode temp = *x;
    *x = *y;
    *y = temp;
}

/**
 * @brief Verilen bir indeks icin min-heap ozelligini korur.
 * @param minHeap Min-heap'in pointer'i.
 * @param idx Heapify isleminin uygulanacagi indeks.
 */
void minHeapify(MinHeap *minHeap, int idx) {
    int smallest = idx;    // En kucuk olarak koku baslatir
    int left = 2 * idx + 1; // Sol cocuk indeksi
    int right = 2 * idx + 2; // Sag cocuk indeksi

    if (left < minHeap->size && minHeap->data[left].value < minHeap->data[smallest].value) {
        smallest = left;
    }
    if (right < minHeap->size && minHeap->data[right].value < minHeap->data[smallest].value) {
        smallest = right;
    }
    if (smallest != idx) {
        swap(&minHeap->data[smallest], &minHeap->data[idx]); // Eger kok en kucuk degilse takas et
        minHeapify(minHeap, smallest); // Alt agaci tekrar heapify et
    }
}

/**
 * @brief Min-heap'e yeni bir dugum ekler.
 * @param minHeap Min-heap'in pointer'i.
 * @param node Eklenecek dugum.
 */
void insertMinHeap(MinHeap *minHeap, MinHeapNode node) {
    int i;
    if (minHeap->size == minHeap->capacity) {
        printf("Heap kapasitesi dolu\n");
        return;
    }
    minHeap->size++;
    i = minHeap->size - 1;
    minHeap->data[i] = node;

    while (i && minHeap->data[(i - 1) / 2].value > minHeap->data[i].value) {
        swap(&minHeap->data[i], &minHeap->data[(i - 1) / 2]); // Yukari dogru tasima islemi
        i = (i - 1) / 2;
    }
}

/**
 * @brief Min-heap'ten en kucuk elemani cikarir.
 * @param minHeap Min-heap'in pointer'i.
 * @return Min-heap'in kok dugumu.
 */
MinHeapNode extractMin(MinHeap *minHeap) {
    MinHeapNode root;
    if (minHeap->size <= 0) {
        root.value = INT_MAX;
        root.arrayIndex = -1;
        root.nextIndex = -1;
        return root;
    }
    if (minHeap->size == 1) {
        minHeap->size--;
        return minHeap->data[0];
    }

    root = minHeap->data[0];
    minHeap->data[0] = minHeap->data[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);

    return root;
}

/**
 * @brief k tane sirali diziyi tek bir sirali diziye birlestirir.
 * @param arr Sirali dizilerin pointer'larini tutan dizi.
 * @param sizes Her sirali dizinin boyutunu iceren dizi.
 * @param k Sirali dizi sayisi.
 * @param mergedSize Birlesik dizinin boyutunu saklamak icin kullanilan pointer.
 * @return Birlesik sirali dizinin pointer'i.
 */
int* mergeKSortedArrays(int **arr, int *sizes, int k, int *mergedSize) {
    MinHeap *minHeap = createMinHeap(k); // k elemani yonetmek icin min-heap olustur
    int totalSize = 0;
    int i, idx;

    for (i = 0; i < k; i++) {
        if (sizes[i] > 0) {
            MinHeapNode node = {arr[i][0], i, 1}; // Min-heap'i her dizinin ilk elemani ile baslat
            insertMinHeap(minHeap, node);
            totalSize += sizes[i]; // Birlesik dizi icin toplam boyutu hesapla
        }
    }

    int *mergedArray = (int *)malloc(totalSize * sizeof(int));
    idx = 0;

    while (minHeap->size > 0) {
        MinHeapNode root = extractMin(minHeap);
        mergedArray[idx++] = root.value;

        if (root.nextIndex < sizes[root.arrayIndex]) {
            root.value = arr[root.arrayIndex][root.nextIndex++]; // Koku dizideki bir sonraki elemanla degistir
            insertMinHeap(minHeap, root); // Guncellenmis koku tekrar heap'e ekle
        }
    }

    *mergedSize = totalSize;
    free(minHeap->data);
    free(minHeap);
    return mergedArray;
}

/**
 * @brief Diziyi k-way merge sort algoritmasiyla siralar.
 * @param arr Siralanacak dizi.
 * @param n Dizinin boyutu.
 * @param k Diziyi parcalara ayirma sayisi.
 * @return Siralanmis dizinin pointer'i.
 */
int* kWayMergeSort(int *arr, int n, int k) {
    int **chunks;      // Ana diziyi parcalara ayirip saklayan dizi
    int *sizes;        // Her parcadaki eleman sayisini tutan dizi
    int chunkSize;     // Her bir parcadaki eleman sayisi
    int i, j, start, end, mergedSize, *result;

    if (n <= 1) {
        result = (int *)malloc(n * sizeof(int));
        if (n == 1) {
            result[0] = arr[0];
        }
        return result;
    }

    chunks = (int **)malloc(k * sizeof(int *));
    sizes = (int *)malloc(k * sizeof(int));
    chunkSize = (n + k - 1) / k; // Her parca icin eleman sayisini hesaplar

    for (i = 0; i < k; i++) {
        start = i * chunkSize; // Her parcadaki baslangic indeksi
        end = (start + chunkSize < n) ? start + chunkSize : n; // Her parcadaki bitis indeksi
        sizes[i] = end - start; // Her parcadaki eleman sayisi
        chunks[i] = (int *)malloc(sizes[i] * sizeof(int));

        for (j = 0; j < sizes[i]; j++) {
            chunks[i][j] = arr[start + j]; // Elemanlari parcaya kopyala
        }

        for (j = 0; j < sizes[i] - 1; j++) { // Her parcayi kendi icinde sirala
            int m, temp;
            for (m = j + 1; m < sizes[i]; m++) {
                if (chunks[i][j] > chunks[i][m]) {
                    temp = chunks[i][j];
                    chunks[i][j] = chunks[i][m];
                    chunks[i][m] = temp;
                }
            }
        }
    }

    result = mergeKSortedArrays(chunks, sizes, k, &mergedSize); // Sirali parcalari tek bir diziye birlestir

    for (i = 0; i < k; i++) {
        free(chunks[i]); // Birlesme tamamlandiktan sonra parcalari bosalt
    }
    free(chunks);
    free(sizes);

    return result;
}

