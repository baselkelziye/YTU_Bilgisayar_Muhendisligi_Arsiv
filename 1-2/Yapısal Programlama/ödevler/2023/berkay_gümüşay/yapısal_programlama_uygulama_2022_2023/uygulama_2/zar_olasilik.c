#include<stdio.h>
#include<stdlib.h>

float** initialize_mat(int nrow, int ncolumn) //DÝNAMÝK 2 BOYUTLU MATRÝS için hafýzada yer ayýrýyor
{
	int i;
	float **mat;
	mat=(float**) malloc(nrow*sizeof(float*)); //ya hafýzada yer ayýracak (adres verecek) ya da NULL dönecek
	//matrisi oluþturduk
	if(mat==NULL){ // NULL olup olmadýðýnýn kontrolü yapýlýyor
		printf("Bellek Ayrilamadi");
		exit(-1);
	}
	for(i=0;i<nrow;i++){
		mat[i]=(float*)calloc(ncolumn,sizeof(float)); // Bellek alanýný ayýrdýktan sonra satýr sayýsý kadar alaný sýfýrlayarak doldurduk. Matrisin ilk adresini mat[i]. adresinde saklýyoruz.
		mat[i][0]=i+3;
	}

	return mat;
}

void calc_prob(float **mat)  //tek tek olasýlýklarý hesaplýyýp matrise yazýyor
{
	int i,j,k,top;
	for(i=1;i<=6;i++){
		for(j=1;j<=6;j++){
			for(k=1;k<=6;k++){
				top=i+j+k;
				mat[top-3][1] += (float) 1/(6*6*6);
			}
		}
	}
	// return mat;
}

void print_probs(float **mat, int nrow) //matrisi yazdýrýyor
{
	int i;
	printf("Toplam Olasilik: \n");
	for(i=0;i<nrow;i++){
		printf("%f\t%f\t%f\n",mat[i][0],mat[i][1]);
	}
}

void free_mat(float **mat, int nrow)// Belleðin gereksiz kullanýmýný engellemek için hafýzadaki yeri boþaltýyor
{
	int i;
	for(i=0;i<nrow;i++){ //satýr satýr belleði boþalttýk (önce aldýðýmýz dizileri serbest býrakýyoruz)
		free(mat[i]); //matrisin i. deðerini free yap
		
	}
	free(mat);// hepsini tutan pointerý boþalttýk
}

int main() {
	float **mat;
	int nrow = 16, ncolumn = 2;
	mat = initialize_mat(nrow, ncolumn);
	print_probs(mat,nrow);
	calc_prob(mat);
	print_probs(mat,nrow);
	free_mat(mat, nrow);
	return 0;
}
