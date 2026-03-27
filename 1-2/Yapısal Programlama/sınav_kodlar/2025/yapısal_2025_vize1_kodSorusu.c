//yapýsal 2025 ilk vize sorusu 2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 70 puanlýk, 3 sayfalýk bir kod sorusu vardý. 
// 3 sayfa boyunca içi boþ, sadece adý yazýlmýþ blok blok fonksiyonlar ve main yerleþtirilmiþ, içlerini doldurmanýz isteniyordu
// tüm soru için çalýþan örnek kod burada.

// örn: pointer mantýðýyla çift boyutlu diziyi ekrana yazdýran fonksiyonu yazýnýz (10p):
void printMatrix(int **matrix, int M){
	int i,j;
	for(i=0;i<M;i++){
		for(j=0;j<M;j++){
			printf("%2d",*(*(matrix+i)+j));	
		}
		printf("\n");
	}
	printf("\n");
}

// çift boyutlu diziyi dinamik bellek tahsisiyle ve rastgele elemanlarla oluþturan fonksiyon yazýnýz.
// kare matris olmalýdýr (M: boyut için MxM) ve rastgele sayýlar 1-N arasý sayýlardan oluþmalýdýr. 
// rastgele fonksiyonu için kod baþýna srand(time(NULL)) yazýp rand() fonksiyonuyla rastgele sayý üretebilirsiniz
// kütüphane: time.h

int **createMatrix(int M){
	srand(time(NULL));
	int i,j;
	int **matrix;
	matrix = (int**)malloc(M*sizeof(int*));
	//no need to check for null in the exam, teacher said in class
	for(i=0;i<M;i++){
		*(matrix+i) = (int*)malloc(M*sizeof(int)); 
	}
	for(i=0;i<M;i++){
		for(j=0;j<M;j++){
			*(*(matrix+i)+j) = rand() % M + 1;		
		}
	}
	return matrix;
}

// matriste herhangi bir verilen satýrda en büyük elemanýn konumunu bulan findMax fonksiyonunu yazýnýz. 
// kullanýcýdan parametre olarak matris satýrýný almalý ve KESÝNLÝKLE satýrdaki en büyük elemanýn adresini döndürmelidir.
// adres döndürmeyen koda puan verilmeyecektir (10p?)
int *findMax(int *matrix, int M){
	int i,max=0;
	for(i=0;i<M;i++){
		if(*(matrix+i)>*(matrix+max)){
			max = i;
		}
	}
	return (matrix+max);
}

// matrisin tüm satýrlarýndaki en büyük sayýyý diagonellere koyan fonksiyonu yazýnýz.
// A bir N boyutlu kare matris olmak üzere diagonel A[0][0], A[1][1], ... , A[N-1][N-1] hücrelerinden oluþur.
// fonksiyon büyük elemaný findMax() fonksiyonunu kullanarak bulmalýdýr. (20p)

void replaceMaxAndDiagonal(int **matrix, int M){
	int i,j;
	int *p;
	int temp;
	for(i=0;i<M;i++){
		p = findMax(*(matrix+i), M);
	    temp = *p;
	    *p = *(*(matrix+i)+i);
	    *(*(matrix+i)+i) = temp;
	}
}

// main fonksiyonu içinde bir matris tanýmlayýn. 
// Boyutunu kullanýcýdan alýn
// createMatrix fonksiyonu ile matris için bellek tahsisi yapýn ve elemanlarýný doldurun
// oluþturulan matrisi ekrana printMatrix fonksiyonu ile yazýn.
// replaceMaxAndDiagonal() fonksiyonunu kullanarak tüm satýrlarýn maximum deðerli elemanlarýný matris diagoneline yerleþtirin.
// oluþturulan çift boyutlu matris için kullanýlan bellek alanýný temizleyin.

int main(){
	int i,M;
	int **matrix;
	printf("enter the matrix size:");
	scanf("%d",&M);
	matrix = createMatrix(M);
	printMatrix(matrix, M);
	replaceMaxAndDiagonal(matrix,M);
	printMatrix(matrix, M);
	for(i=0;i<M;i++){
		free(*(matrix+i));
	}
	free(matrix);
}
