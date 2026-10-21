#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isSubSeqUnique(char** sequence, int count, char* current);
void trackSubSeqs(char* stringX, char* stringY, int** lcsMatrix, char* tmpLCS, int lcsIndex, char** uniqueSubSeqs, int *uniqueLCSCount, int rows, int cols);
void findAllSubsequences(char* stringX, char* stringY, int** lcsMatrix);
void fillLcsMatrix(int** lcsMatrix, int** pickedMatrix, char* stringX, char* stringY);
void printGivenMatrix(int** matrix, char* stringX, char* stringY);
int** createMatrix(char* stringX, char* stringY);
int** createPickedMatrix(char* stringX, char* stringY);
int max(int x, int y);


int main() {
	// KULLANILACAK ÝKÝ KARAKTER DÝZÝSÝ
    char stringX[30];
	char stringY[30];
	printf("First Word: ");
    scanf("%s",stringX);
    printf("Second Word: ");
    scanf("%s",stringY);
    // LCS MATRÝSÝNÝN VE SEÇÝLEN ELEMANLARIN ÝÞARETLENDÝÐÝ MATRÝSÝN OLUÞTURUMASI
    int** lcsMatrix = createMatrix(stringX, stringY);
    int** pickedMatrix = createPickedMatrix(stringX, stringY);
    
    printf("-------------------------------------------------------------------\n");	
    // ÝKÝ MATRÝSÝ DOLDURMA ÝÞLEMÝ
    fillLcsMatrix(lcsMatrix, pickedMatrix, stringX, stringY);
    printf("Word1: %s\nWord2: %s\n",stringX,stringY);
    // EN UZUN ORTAK ÝFADELERÝ BULMA ÝÞLEMÝ
    findAllSubsequences(stringX, stringY, lcsMatrix);
    return 0;
}

/*
@brief	a function that creates an empty lcs matrix

@param	stringX		A Char array that contains first string
@param	stringY		A char array that contains second string

@return	an empty matrix
*/
int** createMatrix(char* stringX, char* stringY){
	int** matrix;
	int i,j;
	matrix = (int**)calloc((strlen(stringX)+1),(sizeof(int*)));
	for(i=0; i<strlen(stringX)+1 ; i++){
		matrix[i] = (int*)calloc((strlen(stringY)+1),(sizeof(int)));
	}
	for(i=0; i<strlen(stringX)+1; i++){
		for(j=0; j<strlen(stringY)+1; j++){
			matrix[i][j] = 0;
		}
	}
	return matrix;
}
/*
@brief	a function that creates an empty pickedMatrix

@param	stringX		A Char array that contains first string
@param	stringY		A char array that contains second string

@return	an empty matrix
*/
int** createPickedMatrix(char* stringX, char* stringY) {
    int** matrix = (int**)calloc((strlen(stringX)+1), sizeof(int*));
    int i;
    for (i = 0; i <= strlen(stringX); i++) {
        matrix[i] = (int*)calloc((strlen(stringY)+1), sizeof(int));
    }
    return matrix;
}

/*
@brief	 function that fills two given matrix using dynamic programming

@param	lcsMatrix		An empty matrix
@param	pickedMatrix	An empty matrix
@param	stringX			A Char array that contains first string
@param	stringY			A char array that contains second string

@return
*/
void fillLcsMatrix(int** lcsMatrix, int** pickedMatrix, char* stringX, char* stringY) {
	int i,j;
	
    for (i = 0; i <=strlen(stringX); i++) {
        for (j = 0; j <= strlen(stringY); j++) {
        	// ÝLK SÜTUN VE ÝLK SÜTUNUN ÝNDÝSLERÝNE '0' YERLEÞTÝRÝLÝR
            if (i == 0 || j == 0) {
                lcsMatrix[i][j] = 0;
                pickedMatrix[i][j] = 0;    
            }
			// ÝKÝ KARAKTER BÝRBÝRÝNE EÞÝTSE SOL ÜSTTEKÝ DEÐER 1 ARTTIRILARAK LCS MATRÝXÝN MEVCUT ÝNDÝSÝNE YAZILIR 
			// BU ÝNDÝSTEKÝ KARAKTER SEÇÝLDÝÐÝ ÝÇÝN DE PÝCKED MATRÝXÝN ÝNDÝSÝNE 1 YAZILIR
			else if (stringX[i - 1] == stringY[j - 1]) {
                lcsMatrix[i][j] = lcsMatrix[i - 1][j - 1] + 1;
                pickedMatrix[i][j] = 1;
            } 
            // EÐER KARAKTERLER EÞÝT DEÐÝLSE LCS MATRÝXÝN BÝR ÜST VE BÝR SOLDAKÝ ELEMANLARININ EN BÜYÜÐÜ ÝNDÝSE YAZILIR
            // BU ÝNDÝSTEKÝ KARAKTER SEÇÝLMEDÝÐÝ ÝÇÝN PÝCKED MATRÝXÝN ÝNDÝSÝNE 0 YAZILIR
			else {
            	lcsMatrix[i][j] = max(lcsMatrix[i-1][j], lcsMatrix[i][j-1]);
            	pickedMatrix[i][j] = 0;
            }
        }
        // MATRÝSLER HER ADIMDA EKRANA YAZDIRILIR
	    if(i==0){
	        printf("Matrixlerin Baslangictaki Hali\n\n");
		}
		else{
			printf("%d. Adim\n",i);
		}
			printf("LCS Matrix: \n");
		    printGivenMatrix(lcsMatrix, stringX, stringY);
		    printf("Picked Matrix: \n");
		    printGivenMatrix(pickedMatrix, stringX, stringY);
		    printf("\n-------------------------------------------------------------------\n");	
    }
}
/*
@brief	 Function that finds the max one of two given integers


@param	x			An integer
@param	y			An integer

@return	The max element
*/
int max(int x, int y) {
    if (x >= y) {
        return x;
    }
    return y;
}

/*
@brief	A function that checks whether a given string is present in the matrix

@param	seq				A char matrix that stores the all longest subsequences that found
@param	length			An integer that keeps the longest subsequence's length
@param	currentSeq		Last found subsequence

@return	If given char array is already in the seq it returns 0 else returns 1
*/
int isSubSeqUnique(char** seq, int length, char* currentSeq){
    int i=0, j=0;
    while(j==0){
    	if(i>= length){
			return 1;
		}
    	if(strcmp(seq[i], currentSeq) == 0){
    		return 0;
		}
		i++;
	}
}
/*
@brief	A recursive function using backtracking to find the longest common subsequences in an array

@param	stringX		A Char array that contains first string
@param	stringY		A char array that contains second string
@param	lcsMatrix	The lcsMatrix
@param	tmpLCS		char array that keeps the last found common subsequence
@param	lcsIndex	An integer that keeps the last looked index
@param	uniqueSubSeqs	char matrix that keeps all longest subsequences found so far
@param	subSeqCount		an integer that keeps the number of subsequences found so far
@param	rows			current index's row
@param	cols			current index's column

@return
*/
void trackSubSeqs(char* stringX, char* stringY, int** lcsMatrix, char* tmpLCS, int lcsIndex, char** uniqueSubSeqs, int *subSeqCount, int rows, int cols) {
	
	// 0. SÜTUNA VEYA SATIRA GELÝNDÝÐÝNDE EKLENECEK BÝR KARAKTER KALMADIÐI ÝÇÝN MEVCUT ÝFADE KONTROL EDÝLEREK DÝZÝYE EKLENÝR
    if (rows == 0 || cols == 0) {
        if (isSubSeqUnique(uniqueSubSeqs, *subSeqCount, tmpLCS)) {
            uniqueSubSeqs[*subSeqCount] = strdup(tmpLCS);
            (*subSeqCount)++;
        }
        return;
    }
    
    // BULUNULAN ÝNDÝSTEKÝ KARAKTERLER BÝRBÝRÝNE EÞÝTSE BU KARAKTER DÝZÝYE ATANARAK RECURSÝVE BÝR ÇAÐRI YAPILIR
    if (stringX[rows - 1] == stringY[cols - 1]) {
        tmpLCS[--lcsIndex] = stringX[rows - 1];
        trackSubSeqs(stringX, stringY, lcsMatrix, tmpLCS, lcsIndex, uniqueSubSeqs, subSeqCount, rows - 1, cols - 1);
        lcsIndex++;
    } 
    // KARAKTERLER BÝRBÝRÝNE EÞÝT DEÐÝLSE BÜYÜK OLAN ÝNDÝSE DOÐRU ÝLERLENEN BÝR RECURSÝVE ÇAÐRI YAPILIR
	else {
        if (lcsMatrix[rows - 1][cols] >= lcsMatrix[rows][cols - 1]) {
            trackSubSeqs(stringX, stringY, lcsMatrix, tmpLCS, lcsIndex, uniqueSubSeqs, subSeqCount, rows - 1, cols);
        }
        if (lcsMatrix[rows][cols - 1] >= lcsMatrix[rows - 1][cols]) {
            trackSubSeqs(stringX, stringY, lcsMatrix, tmpLCS, lcsIndex, uniqueSubSeqs, subSeqCount, rows, cols - 1);
        }
    }
}
/*
@brief	A function that finds all longest subsequences using trackSubSeqs() function and prints them

@param	stringX		A Char array that contains first string
@param	stringY		A char array that contains second string
@param	lcsMatrix	The lcsMatrix

@return
*/
void findAllSubsequences(char* stringX, char* stringY, int** lcsMatrix) {
    int i, j;
    
    // EN UZUN ORTAK ÝFADE(LER)ÝN UZUNLUÐU
    int longestSubSeqLength = lcsMatrix[strlen(stringX)][strlen(stringY)];
    
    // MEVCUT BULUNAN ORTAK ÝFEDEYÝ TUTAN BÝR KARAKTER DÝZÝSÝ
    char* lcs = (char*)calloc(longestSubSeqLength, sizeof(char));
    int lcsIndex = longestSubSeqLength;
    
	// TÜM ORTAK ÝFADELERÝ TUTAN KARAKTER MATRÝSÝ
    char** uniqueSubSeqs = (char**)calloc(100, sizeof(char*));
    for (i = 0; i < 100; i++) {
        uniqueSubSeqs[i] = (char*)calloc(100, sizeof(char));
    }
    int uniqueLCSCount = 0;

	// RECURSÝVE ÇAÐRI UYGULANIR
    trackSubSeqs(stringX, stringY, lcsMatrix, lcs, lcsIndex, uniqueSubSeqs, &uniqueLCSCount, strlen(stringX), strlen(stringY));

	// BULUNAN ORTAK ÝFADELER EKRANA YAZDIRILIR
    printf("Length of LCS: %d\n", longestSubSeqLength);
    int k;
    if(longestSubSeqLength == 0){
    	printf("!! No Common Subsequence !!");
	}
	else{
		printf("All LCS:\n");
	    for (k = 0; k < uniqueLCSCount; k++) {
	        printf("%s\n", uniqueSubSeqs[k]);
	    }
	}
	
	// free() ÝÞLEMÝ UYGULANIR
    for (i = 0; i <= strlen(stringX); i++) {
        free(lcsMatrix[i]);
    }
    free(lcsMatrix);

    free(lcs);

    for (i = 0; i < 50; i++) {
        free(uniqueSubSeqs[i]);
    }
    free(uniqueSubSeqs);
}

/*
@brief	prints the given matrix on the terminal

@param	stringX		A Char array that contains first string
@param	stringY		A char array that contains second string
@param	matrix		The given matrix

@return
*/
void printGivenMatrix(int** matrix, char* stringX, char* stringY) {
    printf("\n");
    int i,j;
    for ( i = 0; i <= strlen(stringX); i++) {
        printf("  ");
        for ( j = 0; j <= strlen(stringY); j++) {
            printf(" %d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}



