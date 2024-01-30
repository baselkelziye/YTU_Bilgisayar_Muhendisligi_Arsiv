#include <stdio.h>
#include <math.h>

int* KupAlDiziY(int*, int);
void KupAlDiziD(int*, int*, int);

int main(){
	int i, n = 9, dizi[10], dizi2[10];
	
	printf("Diziyi giriniz...\n");
	for(i = 0; i < n; i++){
		printf("dizi[%d]: ", i+1);
		scanf("%d", &dizi[i]);
	}
	
	//*dizi2 = KupAlDiziY(&dizi[0], n);
	//KupAlDiziD(&dizi[0], dizi2, n);
	DiziArtiBir(dizi, dizi2, n);
	
	/*printf("\n\n");
	for(i = 0; i < n; i++)
		printf("%d ", dizi[i]);
	printf("\n");
	for(i = 0; i < n; i++)
		printf("%d ", dizi2[i]);*/
	
	return 0;
}

void KupAlDiziD(int* dizi, int* array, int n){
	int i;
	for(i = 0; i < n; i++)
		array[i] = pow(dizi[i], 3);
}

void DiziArtiBir(int* dizi, int* array, int n){
	int i;
	printf("dizi %d\n", dizi);
	printf("*dizi %d\n", *dizi);
	printf("dizi++ %d\n", dizi++);
	printf("++dizi %d\n", ++dizi);
	printf("*dizi++ %d\n", *dizi++);
	printf("*++dizi %d\n", *++dizi);
	printf("++*(++dizi) %d\n", ++*(++dizi));
}

int* KupAlDiziY(int* dizi, int n){
	int array[10], i;
	for(i = 0; i < n; i++)
		array[i] = pow(dizi[i], 3);
	return array;
}







