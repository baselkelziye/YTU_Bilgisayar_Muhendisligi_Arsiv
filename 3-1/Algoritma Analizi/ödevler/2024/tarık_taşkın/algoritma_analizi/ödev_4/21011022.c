#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getDimension();
int abs(int number);
void printBoard(int** board, int N);
int check(int* rows, int row);
int isSafe(int** board, int row, int col, int N);
int isSolution(int** board, int N);
void bruteForce(int** board, int location, int count, int N, long long* attempt, int* solution);
void optimized1(int** board, int row, int N, long long* attempt, int* solution);
void optimized2(int** board, int* cols, int row, int N, long long* attempt, int* solution);
void backtracking(int** board, int* rows, int row, int N, long long* attempt, int* solution);
void solveBruteForce(int N);
void solveOptimized1(int N);
void solveOptimized2(int N);
void solveBacktracking(int N);
void solveAllModes(int N);

int main(){	
	int choice;
	
	do{
		printf("1- Brute Force\n");
		printf("2- Optimized 1\n");
		printf("3- Optimized 2\n");
		printf("4- Backtracking\n");
		printf("5- Hepsi\n");
		printf("0- Cikis\n");
		printf("Seciminiz: ");
		scanf("%d", &choice);
		
		if(choice == 1){
			solveBruteForce(getDimension());
		}else if(choice == 2){
			solveOptimized1(getDimension());
		}else if(choice == 3){
			solveOptimized2(getDimension());
		}else if(choice == 4){
			solveBacktracking(getDimension());
		}else if(choice == 5){
			solveAllModes(getDimension());
		}else if(choice == 0){
			printf("Cikis yapiliyor...");
		}else{
			printf("Hatali secim yaptiniz!\n\n");
		}		
	}while(choice != 0);
	
	return 0;
}

/*
@brief Kullanicidan matrisin boyutunu alir.

@return N, matris boyutu.
*/
int getDimension(){
	int N;
	do{
		printf("N degerini giriniz: ");
		scanf("%d", &N);
		if(N <= 0){
			printf("N degeri pozitif olmalidir!\n\n");
		}
	}while(N <= 0);
	
	return N;
}

/*
@brief Verilen sayinin mutlak degerini bulur.

@param number, programin bulundugu dosya.

@return Verilen sayinin mutlak degerini dondurur.
*/
int abs(int number){
	return number < 0 ? -1 * number : number;
}

/*
@brief Satranc tahtasini ekrana yazdirir.

@param board, satranc tahtasi.
@param N, tahta boyutu.

@return
*/
void printBoard(int** board, int N){
	int i, j;
	
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

/*
@brief Backtracking modunda vezirin ilgili konuma yerlestirilebilmesini kontrol eder.

@param rows, vezirlerin bulundugu satirlar.
@param row, ilgili satir.

@return Vezir ilgili konuma yerlestirilebiliyorsa 1, yerlestirilemiyorsa 0 dondurur.
*/
int check(int* rows, int row){
	int i;
	for(i=0; i<row; i++){
		if(rows[i] == rows[row] || abs(row-i) == abs(rows[i]-rows[row])){
			return 0;
		}
	}
	return 1;
}

/*
@brief Vezirin ilgili konuma yerlestirilebilmesini kontrol eder.

@param board, satranc tahtasi.
@param row, ilgili satir.
@param col, ilgili sutun.
@param N, tahta boyutu.

@return Vezir ilgili konuma yerlestirilebiliyorsa 1, yerlestirilemiyorsa 0 dondurur.
*/
int isSafe(int** board, int row, int col, int N){
	int i, j;

	// Ayni satira/sutuna yerlestirilebilmesi kontrol edilir.
	for(i=0; i<N; i++){
		if((i != col && board[row][i] == 1)  || (i != row && board[i][col] == 1)){
			return 0;
		}
	}
	
	i = row-1;
	j = col-1;
	// Sol ust capraza yerlestirilebilmesi kontrol edilir.
	while(i>=0 && j>=0){
		if(board[i][j] == 1){
			return 0;
		}
		i--;
		j--;
	}
	
	i = row-1;
	j = col+1;
	// Sag ust capraza yerlestirilebilmesi kontrol edilir.
	while(i>=0 && j<N){
		if(board[i][j] == 1){
			return 0;
		}
		i--;
		j++;
	}
	
	i = row+1;
	j = col-1;
	// Sol alt capraza yerlestirilebilmesi kontrol edilir.
	while(i<N && j>=0){
		if(board[i][j] == 1){
			return 0;
		}
		i++;
		j--;
	}
	
	i = row+1;
	j = col+1;
	// Sag alt capraza yerlestirilebilmesi kontrol edilir.
	while(i<N && j<N){
		if(board[i][j] == 1){
			return 0;
		}
		i++;
		j++;
	}
	
	return 1;
}

/*
@brief Vezirlerin birbirini yemeden tahtaya yerlestirilebilmesini kontrol eder.

@param board, satranc tahtasi.
@param N, tahta boyutu.

@return Vezirler birbirini yemeden tahtaya yerlestirilebiliyorsa 1, yerlestirilemiyorsa 0 dondurur.
*/
int isSolution(int** board, int N){
	int i, j;
	
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(board[i][j] == 1){
				if(!isSafe(board, i, j, N)){
					return 0;
				}
			}	
		}
	}
	
	return 1;
}

/*
@brief N-Queen problemini Brute Force ile cozer.

@param board, satranc tahtasi.
@param location, tahta konumu.
@param count, yerlestirilen vezir sayisi.
@param N, tahta boyutu.
@param attempt, farkli durum sayisi.
@param solution, farkli cozum sayisi.

@return
*/
void bruteForce(int** board, int location, int count, int N, long long* attempt, int* solution){
	if(count == N){
		(*attempt)++;		
		if(isSolution(board, N)){
			printBoard(board, N);
			(*solution)++;
		}		
		return;
	}else if(location == N*N){
		return;
	}
	
	board[location/N][location%N] = 1;
	bruteForce(board, location+1, count+1, N, attempt, solution);
	
	board[location/N][location%N] = 0;
	bruteForce(board, location+1, count, N, attempt, solution);	
}

/*
@brief N-Queen problemini ayni satira vezir yerlestirilemeyecegi bilinerek cozer.

@param board, satranc tahtasi.
@param row, vezirin yerlestirilecegi satir.
@param N, tahta boyutu.
@param attempt, farkli durum sayisi.
@param solution, farkli cozum sayisi.

@return
*/
void optimized1(int** board, int row, int N, long long* attempt, int* solution){
	if(row == N){
		(*attempt)++;	
		if(isSolution(board, N)){
			printBoard(board, N);
			(*solution)++;
		}		
		return;
	}
	int i;
	for(i=0; i<N; i++){
		board[row][i] = 1;
		optimized1(board, row+1, N, attempt, solution);
		board[row][i] = 0;
	}
}

/*
@brief N-Queen problemini ayni satira ve ayni sutuna vezir yerlestirilemeyecegi bilinerek cozer.

@param board, satranc tahtasi.
@param cols, vezirlerin bulundugu sutunlar.
@param row, vezirin yerlestirilecegi satir.
@param N, tahta boyutu.
@param attempt, farkli durum sayisi.
@param solution, farkli cozum sayisi.

@return
*/
void optimized2(int** board, int* cols, int row, int N, long long* attempt, int* solution){
	if(row == N){
		(*attempt)++;
		if(isSolution(board, N)){
			printBoard(board, N);
			(*solution)++;
		}		
		return;
	}
	int i;
	for(i=0; i<N; i++){
		if(cols[i] == -1){
			cols[i] = i;
			board[row][i] = 1;
			optimized2(board, cols, row+1, N, attempt, solution);
			cols[i] = -1;
			board[row][i] = 0;
		}		
	}		
}

/*
@brief N-Queen problemini Backtracking ile cozer.

@param board, satranc tahtasi.
@param rows, vezirlerin bulundugu satirlar.
@param row, vezirin yerlestirilecegi satir.
@param N, tahta boyutu.
@param attempt, farkli durum sayisi.
@param solution, farkli cozum sayisi.

@return
*/
void backtracking(int** board, int* rows, int row, int N, long long* attempt, int* solution){
	(*attempt)++;
	if(row == N){
		printBoard(board, N);
		(*solution)++;
		return;
	}
	int i;
	for(i=0; i<N; i++){
		rows[row] = i;
		board[row][i] = 1;
		if(check(rows, row)){			
			backtracking(board, rows, row+1, N, attempt, solution);
		}
		board[row][i] = 0;
	}		
}

/*
@brief N-Queen problemini Brute Force modu ile cozer.

@param N, tahta boyutu.

@return
*/
void solveBruteForce(int N){
	clock_t start, end;
	int i, solution = 0;
	long long attempt = 0;
	int** board = (int**) calloc(N, sizeof(int*));

	for(i=0; i<N; i++){
		board[i] = (int*) calloc(N, sizeof(int));
	}
	
	printf("\n\tBRUTE FORCE MODU\n\n");
	start = clock();
	bruteForce(board, 0, 0, N, &attempt, &solution);
	end = clock();
	printf("Brute Force modu %lld denemede, %lf saniyede %d cozum bulunarak tamamlandi.\n\n", attempt, ((double)(end - start) / CLOCKS_PER_SEC), solution);
	
	for(i=0; i<N; i++){
		free(board[i]);
	}
	free(board);
}

/*
@brief N-Queen problemini Optimized 1 modu ile cozer.

@param N, tahta boyutu.

@return
*/
void solveOptimized1(int N){
	clock_t start, end;
	int i, solution = 0;
	long long attempt = 0;	
	int** board = (int**) calloc(N, sizeof(int*));

	for(i=0; i<N; i++){
		board[i] = (int*) calloc(N, sizeof(int));
	}
	
	printf("\n\tOPTIMIZED 1 MODU\n\n");
	start = clock();
	optimized1(board, 0, N, &attempt, &solution);
	end = clock();
	printf("Optimized 1 modu %lld denemede, %lf saniyede %d cozum bulunarak tamamlandi.\n\n", attempt, ((double)(end - start) / CLOCKS_PER_SEC), solution);
	
	for(i=0; i<N; i++){
		free(board[i]);
	}
	free(board);
}

/*
@brief N-Queen problemini Optimized 2 modu ile cozer.

@param N, tahta boyutu.

@return
*/
void solveOptimized2(int N){
	clock_t start, end;
	int i, solution = 0;
	long long attempt = 0;	
	int** board = (int**) calloc(N, sizeof(int*));
	int* cols = (int*) calloc(N, sizeof(int));
	
	for(i=0; i<N; i++){
		board[i] = (int*) calloc(N, sizeof(int));
		cols[i] = -1;
	}
	
	printf("\n\tOPTIMIZED 2 MODU\n\n");
	start = clock();
	optimized2(board, cols, 0, N, &attempt, &solution);
	end = clock();
	printf("Optimized 2 modu %lld denemede, %lf saniyede %d cozum bulunarak tamamlandi.\n\n", attempt, ((double)(end - start) / CLOCKS_PER_SEC), solution);
	
	for(i=0; i<N; i++){
		free(board[i]);
	}
	free(board);
}

/*
@brief N-Queen problemini Backtracking modu ile cozer.

@param N, tahta boyutu.

@return
*/
void solveBacktracking(int N){
	clock_t start, end;
	int i, solution = 0;
	long long attempt = 0;
	int** board = (int**) calloc(N, sizeof(int*));
	int* rows = (int*) calloc(N, sizeof(int));
	
	for(i=0; i<N; i++){
		board[i] = (int*) calloc(N, sizeof(int));
	}
	
	printf("\n\tBACKTRACKING MODU\n\n");
	start = clock();
	backtracking(board, rows, 0, N, &attempt, &solution);
	end = clock();
	printf("Backtracking modu %lld denemede, %lf saniyede %d cozum bulunarak tamamlandi.\n\n", attempt, ((double)(end - start) / CLOCKS_PER_SEC), solution);
	
	for(i=0; i<N; i++){
		free(board[i]);
	}
	free(board);
	free(rows);
}

/*
@brief N-Queen problemini tum modlar ile cozer.

@param N, tahta boyutu.

@return
*/
void solveAllModes(int N){
	clock_t start, end;
	int i, solutionBT = 0, solutionOPT1 = 0, solutionOPT2 = 0, solutionBF = 0;
	long long attemptBT = 0, attemptOPT1 = 0, attemptOPT2 = 0, attemptBF = 0;
	int** board = (int**) calloc(N, sizeof(int*));
	int* rows = (int*) calloc(N, sizeof(int));
	int* cols = (int*) calloc(N, sizeof(int));
	
	for(i=0; i<N; i++){
		board[i] = (int*) calloc(N, sizeof(int));
		cols[i] = -1;
	}
	
	printf("\n\tBACKTRACKING MODU\n\n");
	start = clock();
	backtracking(board, rows, 0, N, &attemptBT, &solutionBT);
	end = clock();
	double timeBT = (double)(end - start) / CLOCKS_PER_SEC;
	
	printf("\n\tOPTIMIZED 2 MODU\n\n");
	start = clock();
	optimized2(board, cols, 0, N, &attemptOPT2, &solutionOPT2);
	end = clock();
	double timeOPT2 = (double)(end - start) / CLOCKS_PER_SEC;
	
	printf("\n\tOPTIMIZED 1 MODU\n\n");
	start = clock();
	optimized1(board, 0, N, &attemptOPT1, &solutionOPT1);
	end = clock();
	double timeOPT1 = (double)(end - start) / CLOCKS_PER_SEC;
		
	printf("\n\tBRUTE FORCE MODU\n\n");
	start = clock();
	bruteForce(board, 0, 0, N, &attemptBF, &solutionBF);
	end = clock();
	double timeBF = (double)(end - start) / CLOCKS_PER_SEC;
	
	printf("Backtracking modu %lld denemede, %lf saniyede %d cozum bulunarak tamamlandi.\n", attemptBT, timeBT, solutionBT);
	printf("Optimized 2 modu %lld denemede, %lf saniyede %d cozum bulunarak tamamlandi.\n", attemptOPT2, timeOPT2, solutionOPT2);
	printf("Optimized 1 modu %lld denemede, %lf saniyede %d cozum bulunarak tamamlandi.\n", attemptOPT1, timeOPT1, solutionOPT1);
	printf("Brute Force modu %lld denemede, %lf saniyede %d cozum bulunarak tamamlandi.\n\n", attemptBF, timeBF, solutionBF);
	
	for(i=0; i<N; i++){
		free(board[i]);
	}
	free(board);
	free(rows);
	free(cols);
}
