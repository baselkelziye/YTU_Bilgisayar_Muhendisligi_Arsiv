#include <stdio.h>
#include <stdlib.h>

float** initialize_matrix(int nRow, int nColumn)
{
	int i;
	float **matrix;
	
	matrix = (float**) malloc(sizeof(float*) * nRow); // Bellek tahsisi yapilir veya NULL degeri doner.
	
	// Matris olusturuldu.
	
	// NULL olup olmadiginin kontrolu yapilir.
	
	if(matrix == NULL){
		printf("Bellek ayrilamadi...");
		exit(-1);
	}
	
	for(i=0; i<nRow; i++){
		matrix[i] = (float*) calloc(nColumn, sizeof(float));
		
		/*
		 Bellek tahsisi yapildiktan sonra satir sayisi kadar alan sifirlanarak doldurulur.
		 Matrisin ilk adresi, matrix[i] adresinde saklanir.
		*/
		
		matrix[i][0] = i + 3;
	}

	return matrix;
}

// Olasiliklar tek tek hesaplanip matrise yazilir.
void calc_prob(float **matrix)
{
	int i, j, k, sum;
	
	for(i=1; i<=6; i++){
		
		for(j=1; j<=6; j++){
			
			for(k=1; k<=6; k++){
				sum = i + j + k;
				matrix[sum-3][1] += (float) 1 / (6*6*6);
			}
		}
	}
	
	// return matrix;
}

void print_probs(float **matrix, int nRow)
{
	int i;
	
	printf("Toplam Olasilik:\n\n");
	
	for(i=0; i<nRow; i++){
		printf("%f\t%f\n", matrix[i][0], matrix[i][1]);
	}
}

// Bellegin gereksiz kullanimini engellemek icin bellekte kullanilan alan bosaltilir.
void free_matrix(float **matrix, int nRow)
{
	int i;
	
	for(i=0; i<nRow; i++){ 
		free(matrix[i]);
	}
	
	free(matrix); // Matrisin hepsini tutan pointerin bellekteki yeri bosaltilir.
}

int main()
{
	float **matrix;
	int nRow = 16, nColumn = 2;
	
	matrix = initialize_matrix(nRow, nColumn);

	calc_prob(matrix);
	
	print_probs(matrix, nRow);
	
	free_matrix(matrix, nRow);
	
	getch();
	
	return 0;
}

