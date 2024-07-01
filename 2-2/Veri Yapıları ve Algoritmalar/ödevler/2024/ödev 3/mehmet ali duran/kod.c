#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int** createMatrix(int N, int M);
void freeMatrix(int** matrix, int N);
void printMatrix(int** matrix, int N, int M);
int** fillMatrixWithRandomNumbers(int** matrix, int* lengthOfEachQueue, int N, int M);
void build_max_heap(int* arr, int n);
void max_heapify(int* arr, int n, int i);
void swap(int *a, int *b);
int allIsFinished(int** matrix, int N);


int main(){
	
	int N, M, i, max, resultOrder=0;
	int* lengthOfEachQueue;
	int* result;
	
	//N ve M degerleri en az 1x1 olacak sekilde alinir
	printf("Please enter the number of rows N and columns M values(N M): ");
	do{
		scanf("%d %d",&N ,&M);
		if((N < 1) || (M < 1)){
			printf("Please enter valid values(N M): ");
		}
	}while((N < 1) || (M < 1));
	
	
	int** matrix = createMatrix(N, M);
	
	result = (int*)malloc(N*sizeof(int));
	
	//her kuyruktaki eleman sayisi alinir
	lengthOfEachQueue = (int*)malloc(N*sizeof(int));
	printf("Enter the length of the queue in each line\n");
	for(i=0;i < N; i++){
		do{
			printf("length of %dth row: ",i+1);
			scanf("%d", &lengthOfEachQueue[i]);
			if((lengthOfEachQueue[i] < 1) || (lengthOfEachQueue[i] > N)){
				printf("Please enter a number in the valid range");
			}
		}while((lengthOfEachQueue[i] < 1) || (lengthOfEachQueue[i] > N));
		
	}
	//matris rastgele sayilar ile doldurulur
	matrix = fillMatrixWithRandomNumbers(matrix, lengthOfEachQueue, N, M);
	printf("Matrix filled with random numbers:\n");
	printMatrix(matrix, N, M);
	
	//matrisin satirlari heap tree ozelligi gosterecek sekilde duzenlenir
	for(i=0; i < N; i++){
		build_max_heap(matrix[i], lengthOfEachQueue[i]);
	}
	printf("Matrix constructed as heap tree:\n");
	printMatrix(matrix, N, M);
	printf("\n");
	
	//kuyruklardaki butun elemenlar bosalana kadar devam eden dongu
	while(!allIsFinished(matrix, N)){
		max = 0;
		//o turdaki en oncelikli elemani bul
		for(i=0; i < N; i++){
			if(matrix[i][0] > matrix[max][0])
				max = i;
		}
		matrix[max][0] = -1; //kuyruktan cikar
		max_heapify(matrix[max], lengthOfEachQueue[max], 0);//eleman cikinca tekrar heap ozelligi kazandirilir
		if(matrix[max][0] == -1){
			result[resultOrder] = max + 1;//eger dizi bosaldiysa sonuc dizisine koyar ve indisi bir arttirir
			resultOrder++;
		}
		lengthOfEachQueue[i] -= 1;//gereksiz kontrolleri onlemek icin boyut bir azaltililr
		printMatrix(matrix, N, M);//ekrana basilir
		printf("\n");
	}
	
	printf("Finished order: ");//istenen asil cikti olan bitme sirasi ekrana basilir
	for(i = 0; i<N; i++){
		printf("%d ", result[i]);
	}
	
	freeMatrix(matrix, N);//matris bellekten serbest birakilir
	
	return 0;
}

/**
 * @brief NxM boyutlarinda bir matris olusturur ve döndürür.
 * @params N: Matrisin satir sayisi, M: Matrisin sutun sayisi
 * @return Olusturulan matrisin adresi
 */
int** createMatrix(int N, int M){
	int i, j;
	int** matrix = (int**)malloc(sizeof(int*)*N);
	for(i = 0; i < N; i++){
		matrix[i] = (int*)malloc(sizeof(int)*M);
		for (j = 0; j < M; j++) {
            matrix[i][j] = -1;
        }
	}
	return matrix;
}

/**
 * @brief Dinamik olarak ayrilan matrisin hafizasini serbest birakir.
 * @params matrix: Serbest birakilacak matrisin adresi, N: Matrisin satir sayisi
 */
void freeMatrix(int** matrix, int N){
	int i;
	for(i=0;i<N;i++){
		free(matrix[i]);
	}
	free(matrix);
}

/**
 * @brief Matrisin icerigini ekrana basar.
 * @params matrix: Ekrana basýlacak matrisin adresi, N: Matrisin satir sayisi, M: Matrisin sutun sayisi
 */
void printMatrix(int** matrix, int N, int M){
	int i, j;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			printf("%4d",matrix[i][j]);
		}
		printf("\n");
	}
}

/**
 * @brief Matrisi rastgele sayilar ile doldurur.
 * @params matrix: Doldurulacak matris, lengthOfEachQueue: Her satirdaki bos olmayan eleman sayisi, N: Matrisin satir sayisi, M: Matrisin sutun sayisi
 * @return Doldurulmuþ matris
 */
int** fillMatrixWithRandomNumbers(int** matrix, int* lengthOfEachQueue, int N, int M){
	srand(time(NULL));
	int *uniqueNumbers;
	int i, j, K, temp, numPlaced = 0;
	//burada rastgele sayi uretmenin mantigi sayilar 0'dan K'ya kadar bir diziye atanir
	//bu dizideki sayilarin rastgele kendi icinde yerleri degistirilir bu sekilde essiz sayialrdan
	//olusan rastgele sayilar dizisi olusturulur
	K = N * M;
	uniqueNumbers = (int*)malloc(K * sizeof(int));
	for (i = 0; i < K; i++) {
        uniqueNumbers[i] = i;
    }
    
	for(i=K-1;i>=0;i--){
		j = rand() % (i + 1);
		temp = uniqueNumbers[i];
        uniqueNumbers[i] = uniqueNumbers[j];
        uniqueNumbers[j] = temp;
	}
	
	//bu sayilar her bir kuyruga kac eleman gerekiyorsa o kadar eleman sirayla konulur boylece 
	//kuyruklarda birbirinin ayni olmayan sayilar olur
    for (i = 0; i < N; i++) {
        for (j = 0; j < lengthOfEachQueue[i]; j++) {
            matrix[i][j] = uniqueNumbers[numPlaced++];
        }
    }
	
	free(uniqueNumbers);
	return matrix;
}

/**
 * @brief Iki tam sayinin degerlerini degistirir.
 * @params a: Degistirilecek ilk degerin adresi, b: Degistirilecek ikinci degerin adresi
 */
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/**
 * @brief Belirli bir dizide max-heap özelligini koruyacak sekilde elemanlari düzenler.
 * @params arr: Düzenlenecek dizi, n: Dizinin eleman sayisi, i: Düzenlemeye baslanacak indis
 */
void max_heapify(int* arr, int n, int i) {
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        max_heapify(arr, n, largest);
    }
}

/**
 * @brief Verilen diziyi maksimum yigin (max-heap) haline getirir.
 * @params arr: Yigin haline getirilecek dizi, n: Dizinin eleman sayisi
 */
void build_max_heap(int arr[], int n) {
	int i;
    for (i = n / 2 - 1; i >= 0; i--) {
        max_heapify(arr, n, i);
    }
}

/**
 * @brief Tum satirlarin ilk elemaninin -1 olup olmadigini kontrol eder.
 * @params matrix: Kontrol edilecek matris, N: Matrisin satir sayisi
 * @return Eger tum satirlarin ilk elemani -1 ise 1, degilse 0 döndürür.
 */
int allIsFinished(int** matrix, int N){
	int allIsFinished = 1;
	int i;
	for(i=0; i < N; i++){
		if(matrix[i][0] != -1){
			allIsFinished = 0;
			return allIsFinished;
		}
	}
	return allIsFinished;
}
