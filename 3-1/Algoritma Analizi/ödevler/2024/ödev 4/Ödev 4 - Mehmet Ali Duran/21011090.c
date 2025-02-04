#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int getNumberOfRowAndColumn();
void bruteforce(int **board, int queens, int n, int *solutionCount);
void optimized_1(int** matrix, int roww, int N, int* solutionCount);
void optimized_2(int** matrix, int roww, int N, int* solutionCount);
void backtracking(int** board, int row, int n, int* solutionCount);
void allMethods(int** matrix, int N, int* solutionCount);
void printTable(int** matrix, int N);
void resetTable(int** matrix, int N);
int** createTable(int N);
void destroyTable(int** matrix, int N);
void executeAndMeasureTime(void (*function)(int**, int, int, int*), int** matrix, int row, int N, int* solutionCount);



int main(){
	
	int N, choice, i, j, solutionCount = 0;
	N = getNumberOfRowAndColumn();
	int** matrix = createTable(N);
	
	do{
		printf("1 - Solve with BRUTE FORCE\n");
		printf("2 - Solve with OPTIMIZED-1\n");
		printf("3 - Solve with OPTIMIZED-2\n");
		printf("4 - Solve with BACKTRACKING\n");
		printf("5 - Solve with ALL METHODS\n");	
		printf("6 - Enter new table size\n");
		printf("7 - Quit  ");
		resetTable(matrix, N);
		scanf("%d", &choice);
		printf("\n\n");
		//system("cls");
		switch(choice){
			case 1:
				solutionCount = 0;
				executeAndMeasureTime(bruteforce, matrix, 0, N, &solutionCount);
				printf("solutionCount for bruteForce = %d\n", solutionCount);
				break;
			case 2:
				solutionCount = 0;
				executeAndMeasureTime(optimized_1, matrix, 0, N, &solutionCount);
				printf("solutionCount for optimized_1 = %d\n", solutionCount);
				break;
			case 3:
				solutionCount = 0;
				executeAndMeasureTime(optimized_2, matrix, 0, N, &solutionCount);
				printf("solutionCount for optimized_2 = %d\n", solutionCount);
				break;
			case 4:
				solutionCount = 0;
				executeAndMeasureTime(backtracking, matrix, 0, N, &solutionCount);
				printf("solutionCount for backtracking = %d\n", solutionCount);
				break;
			case 5:
				
				allMethods(matrix, N, &solutionCount);
				break;
			case 6:
				destroyTable(matrix, N);  // Mevcut tabloyu serbest býrak
			    N = getNumberOfRowAndColumn();
			    matrix = createTable(N); // Yeni tablo oluþtur
			    printf("New table size: %d\n", N);
				break;
		}
	}while(choice!=7);

	destroyTable(matrix, N);
	return 0;
}

/**
 * @brief Kullanýcýdan NxN satranç tahtasýnýn boyutunu alýr.
 * @return Satranç tahtasýnýn boyutu (N), minimum 4 olmalýdýr.
 */
int getNumberOfRowAndColumn(){
	int N;
	
	do{
		printf("Please enter the size of table (it should be minimum 4): ");
		scanf("%d",&N);	
	}while(N < 4);
	
	return N;
}

/**
 * @brief N vezir problemini optimize edilmiþ bir yöntemle çözer.
 *        Sadece sütun çakýþmalarýný kontrol eder.
 * @param matrix NxN satranç tahtasý.
 * @param execute fonksiyonun uymasý icin koydum bir etkisi yok
 * @param N Satranç tahtasýnýn boyutu.
 * @param solutionCount Çözüm sayýsýný saklayan iþaretçi.
 */
void optimized_1(int** matrix, int row, int N, int* solutionCount) {
    int col, i;
    bool safe;

    if (row == N) {
        /* Tüm satýrlar doldurulduysa, çözümü kontrol et */
        if (isValidForBruteForce(matrix, N)) {
            (*solutionCount)++;
            printf("Solution %d:\n", *solutionCount);
            printTable(matrix, N);
        }
        return;
    }

    /* Her satýr için tüm sütunlarý dene */
    for (col = 0; col < N; col++) {
        safe = true;
        
        /* Sadece önceki satýrlarda ayný sütunda vezir var mý kontrol et */
        for (i = 0; i < row; i++) {
            if (matrix[i][col] == 1) {
                safe = false;
                break;
            }
        }

        if (safe) {
            matrix[row][col] = 1;
            optimized_1(matrix, row + 1, N, solutionCount);
            matrix[row][col] = 0;  /* backtrack */
        }
    }
}

/**
 * @brief N vezir problemini optimize edilmiþ bir yöntemle çözer.
 *        Sadece sütun çakýþmalarýný kontrol eder.
 * @param matrix NxN satranç tahtasý.
 * @param execute fonksiyonun uymasý icin koydum bir etkisi yok
 * @param N Satranç tahtasýnýn boyutu.
 * @param solutionCount Çözüm sayýsýný saklayan iþaretçi.
 */
void optimized_2(int** matrix, int row, int N, int* solutionCount) {
    int i, j, k, col;
    bool isValid, safe;

    if (row == N) {
        /* Sadece çapraz kontrolleri yap çünkü satýr ve sütun kontrolleri zaten yapýldý */
        isValid = true;
        for (i = 0; i < N && isValid; i++) {
            for (j = 0; j < N; j++) {
                if (matrix[i][j] == 1) {
                    /* Çapraz kontroller */
                    for (k = 1; k < N; k++) {
                        /* Sol üst çapraz */
                        if (i-k >= 0 && j-k >= 0 && matrix[i-k][j-k] == 1) {
                            isValid = false;
                            break;
                        }
                        /* Sað üst çapraz */
                        if (i-k >= 0 && j+k < N && matrix[i-k][j+k] == 1) {
                            isValid = false;
                            break;
                        }
                    }
                }
            }
        }
        
        if (isValid) {
            (*solutionCount)++;
            printf("Solution %d:\n", *solutionCount);
            printTable(matrix, N);
        }
        return;
    }

    /* Her satýr için tüm sütunlarý dene */
    for (col = 0; col < N; col++) {
        safe = true;
        
        /* Satýr ve sütun kontrolü */
        for (i = 0; i < row; i++) {
            if (matrix[i][col] == 1) {  /* Sütun kontrolü */
                safe = false;
                break;
            }
        }

        if (safe) {
            matrix[row][col] = 1;
            optimized_2(matrix, row + 1, N, solutionCount);
            matrix[row][col] = 0;  /* backtrack */
        }
    }
}

/**
 * @brief Backtracking yöntemiyle vezir yerleþtirmenin güvenli olup olmadýðýný kontrol eder.
 * @param board NxN satranç tahtasý.
 * @param row Vezir yerleþtirilecek satýr.
 * @param col Vezir yerleþtirilecek sütun.
 * @param N Satranç tahtasýnýn boyutu.
 * @return Güvenli ise true, deðilse false döner.
 */
bool isSafeBacktracking(int** board, int row, int col, int N) {
	int i, j;
    for (i = 0; i < row; i++) {
        if (board[i][col] == 1) return false; // Ayný sütun
    }
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false; // Sol üst çapraz
    }
    for (i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) return false; // Sað üst çapraz
    }
    return true;
}

/**
 * @brief Backtracking yöntemiyle N vezir problemine çözüm arar.
 * @param board NxN satranç tahtasý.
 * @param row Vezir yerleþtirilecek satýr.
 * @param N Satranç tahtasýnýn boyutu.
 * @param solutionCount Çözüm sayýsýný saklayan iþaretçi.
 */
void backtracking(int** board, int row, int N, int* solutionCount) {
	int col;
    if (row == N) {
        (*solutionCount)++;
        printf("Solution %d:\n", *solutionCount);
        printTable(board, N);
        return;
    }
    for (col = 0; col < N; col++) {
        if (isSafeBacktracking(board, row, col, N)) {
            board[row][col] = 1; // Veziri yerleþtir
            backtracking(board, row + 1, N, solutionCount);
            board[row][col] = 0; // Backtracking
        }
    }
}

/**
 * @brief Brute force yöntemiyle tahtanýn geçerli olup olmadýðýný kontrol eder.
 * @param board NxN satranç tahtasý.
 * @param n Satranç tahtasýnýn boyutu.
 * @return Geçerli ise 1, deðilse 0 döner.
 */
int isValidForBruteForce(int **board, int n) {
    int row, col, i, j, k;
    for (row = 0; row < n; row++) {
        for (col = 0; col < n; col++) {
            if (board[row][col] == 1) {
                // Ayný satýrda baþka bir vezir var mý?
                for (k = 0; k < n; k++) {
                    if (k != col && board[row][k] == 1)
                        return 0;
                }
                // Ayný sütunda baþka bir vezir var mý?
                for (k = 0; k < n; k++) {
                    if (k != row && board[k][col] == 1)
                        return 0;
                }
                // Sol üst çapraz
                for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
                    if (board[i][j] == 1)
                        return 0;
                }
                // Sað üst çapraz
                for (i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
                    if (board[i][j] == 1)
                        return 0;
                }
                // Sol alt çapraz
                for (i = row + 1, j = col - 1; i < n && j >= 0; i++, j--) {
                    if (board[i][j] == 1)
                        return 0;
                }
                // Sað alt çapraz
                for (i = row + 1, j = col + 1; i < n && j < n; i++, j++) {
                    if (board[i][j] == 1)
                        return 0;
                }
            }
        }
    }
    return 1;
}

void bruteforce(int **board, int queens, int n, int *solutionCount) {
    int totalCells = n * n; // Toplam hücre sayýsý
    int totalCombinations = 1 << totalCells; // 2^(n*n) kombinasyon
	int comb, i, j, cell, row, col;
    for (comb = 0; comb < totalCombinations; comb++) {
        // Matris sýfýrla
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                board[i][j] = 0;
            }
        }

        // Kombinasyonu tahtaya yerleþtir
        int queensPlaced = 0;
        for (cell = 0; cell < totalCells; cell++) {
            if (comb & (1 << cell)) { // Bu hücreye vezir yerleþtir
                row = cell / n;
                col = cell % n;
                board[row][col] = 1;
                queensPlaced++;
            }
        }

        // Eðer tam olarak n vezir yerleþtirildiyse, geçerli mi kontrol et
        if (queensPlaced == n && isValidForBruteForce(board, n)) {
            (*solutionCount)++;
			printf("Solution %d:\n", *solutionCount);
			printTable(board, n);
        }
    }
}

/**
 * @brief Verilen tüm yöntemleri sýrayla çalýþtýrýr.
 * @param matrix NxN satranç tahtasý.
 * @param N Satranç tahtasýnýn boyutu.
 */
void allMethods(int** matrix, int N, int* solutionCount){
	
	*solutionCount = 0;
	executeAndMeasureTime(bruteforce, matrix, 0, N, solutionCount);
	printf("solutionCount for bruteForce = %d\n\n***********\n\n", *solutionCount);
	
	*solutionCount = 0;
	executeAndMeasureTime(optimized_1, matrix, 0, N, solutionCount);
	printf("solutionCount for optimized_1 = %d\n\n***********\n\n", *solutionCount);
	
	*solutionCount = 0;
	executeAndMeasureTime(optimized_2, matrix, 0, N, solutionCount);
	printf("solutionCount for optimized_2 = %d\n\n***********\n\n", *solutionCount);
	
	*solutionCount = 0;
	executeAndMeasureTime(backtracking, matrix, 0, N, solutionCount);
	printf("solutionCount for backtracking = %d\n\n***********\n\n", *solutionCount);
}

/**
 * @brief NxN satranç tahtasýný ekrana basar.
  * @param matrix NxN satranç tahtasý.
 * @param N Satranç tahtasýnýn boyutu.
 */
void printTable(int** matrix, int N){
	int i, j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%2d", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
}

/**
 * @brief NxN satranç tahtasýný oluþturur.
 * @param N Satranç tahtasýnýn boyutu.
 * @return Oluþturulan satranç tahtasýna iþaretçi döner.
 */
int** createTable(int N){
	int i;
	int** matrix = (int**) malloc(N * sizeof(int*));
	 
	for(i=0;i<N;i++)
		matrix[i] = (int*) malloc(N * sizeof(int));
	return matrix;
}

/**
 * @brief Satranç tahtasýný sýfýrlar.
 * @param matrix NxN satranç tahtasý.
 * @param N Satranç tahtasýnýn boyutu.
 */
void resetTable(int** matrix, int N){
	int i, j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			matrix[i][j] = 0;
		}
	}
}	

/**
 * @brief NxN satranç tahtasýný bellekten siler.
 * @param matrix NxN satranç tahtasý.
 * @param N Satranç tahtasýnýn boyutu.
 */
void destroyTable(int** matrix, int N){
	int i;
	for(i=0;i<N;i++)
		free(matrix[i]);
	free(matrix);
}

/**
 * @brief Belirtilen fonksiyonun çalýþma süresini ölçer ve sonuçlarý yazdýrýr.
 * @param function Çalýþtýrýlacak fonksiyon.
 * @param matrix NxN satranç tahtasý.
 * @param row Vezir yerleþtirilecek satýr.
 * @param N Satranç tahtasýnýn boyutu.
 * @param solutionCount Çözüm sayýsýný saklayan iþaretçi.
 */
void executeAndMeasureTime(void (*function)(int**, int, int, int*), int** matrix, int row, int N, int* solutionCount) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    function(matrix, row, N, solutionCount);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time elapsed %.2f sn\n", cpu_time_used);
}
