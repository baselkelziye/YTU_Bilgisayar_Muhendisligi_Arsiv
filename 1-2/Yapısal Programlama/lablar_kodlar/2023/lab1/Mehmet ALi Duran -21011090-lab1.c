#include<stdio.h>
#define MAX 50

void get_values(int dizi[], int N);
void sort_and_print(int dizi[], int N);
void swap(int dizi[], int index);


int main() {
	
	int N, i;
	int notlar[MAX];
	do{
		printf("Lutfen kac adet not girisi olacagini girin: ");
		scanf("%d", &N);
		if(N<6){
			printf("Lutfen 6 dan buyuk gecerli bir deger girin\n");
		}
	}while(N<6);
	
	get_values(notlar, N);
	sort_and_print(notlar, N);
	
	return 0;
}

void sort_and_print(int dizi[], int N){
	int i, j;
	for(i=0; i<N-1;i++){
		for(j=0; j< N - i -1;j++){
			if(dizi[j]>dizi[j+1]){
				swap(dizi, j);
			}
		}
	}
	
	printf("en basarili 3: %d, %d, %d\n", dizi[N-1], dizi[N-2], dizi[N-3]);
	printf("en basarili 3 toplami: %d\n", dizi[N-1] + dizi[N-2] + dizi[N-3]);
	printf("en basarisiz 3: %d, %d, %d\n", dizi[0],  dizi[1],  dizi[2]);
	printf("en basarisiz 3 toplami: %d\n", dizi[0] + dizi[1] + dizi[2]);
	
}

void get_values(int dizi[], int N){
	int i;
	for(i=0; i<N; i++){
		printf("%d. not:", i+1);
		scanf("%d", &dizi[i]);
	}
}

void swap(int dizi[], int index){
	int temp;
	temp = dizi[index];
	dizi[index] =dizi[index+1];
	dizi[index+1] = temp;

}

