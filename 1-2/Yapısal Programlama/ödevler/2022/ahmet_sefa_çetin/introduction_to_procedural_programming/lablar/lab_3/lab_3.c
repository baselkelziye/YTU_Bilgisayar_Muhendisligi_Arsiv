#include <stdio.h>

#define MAX 100

void matrisOku(int matris[MAX][MAX], int n);
void matrisYaz(int matris[MAX][MAX], int n);
int gidilebilecekYollar(int matris[MAX][MAX], int yollar[MAX][2], int n, int row, int column, int index);
void guzergahYaz(int yollar[MAX][2], int n);

int main() {
	int n, matris[MAX][MAX], yollar[MAX][2], yolSayisi;
	
	printf("matrisin boyutunu gir: ");
	scanf("%d", &n);
	
	matrisOku(matris, n);
	matrisYaz(matris, n);
	
	yolSayisi = gidilebilecekYollar(matris, yollar, n, 0, 0, 0);
			
	printf("yol sayisi = %d", yolSayisi);
	
	return 0;
}

void matrisOku(int matris[MAX][MAX], int n) {
	int i, j;
	
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			printf("matrisin (%d, %d) elemanini gir: ", i, j);
			scanf("%d", &matris[i][j]);
		}
}

void matrisYaz(int matris[MAX][MAX], int n) {
	int i, j;
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%d\t", matris[i][j]);
		printf("\n");
	}
}

int gidilebilecekYollar(int matris[MAX][MAX], int yollar[MAX][2], int n, int row, int column, int index) {
	
	if (row == n - 1 && column == n - 1) {
		guzergahYaz(yollar, n);
		return 1;
	}
	if (!matris[row][column]) return 0;
	
	yollar[index][0] = row;
	yollar[index][1] = column;
	index++;
	
	return gidilebilecekYollar(matris, yollar, n, row + 1, column, index) + gidilebilecekYollar(matris, yollar, n, row, column + 1, index);
}

void guzergahYaz(int yollar[MAX][2], int n) {
	int i;
	
	for (i = 0; i < 2 * n - 2; i++) {
		printf("(%d, %d) ", yollar[i][0], yollar[i][1]);
	}
	printf("(%d, %d) ", n - 1, n - 1);
	printf("\n");
}
