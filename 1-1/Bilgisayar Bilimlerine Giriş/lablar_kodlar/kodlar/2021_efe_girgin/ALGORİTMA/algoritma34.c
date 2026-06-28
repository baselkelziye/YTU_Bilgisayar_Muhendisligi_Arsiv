#include <stdio.h>
int main(){
	int N,say,i,s;
	printf("lutfen dizinin boyutunu giriniz \n");
	scanf("%d",&N);
	int A[N];
	say=0;
	printf("lutfen bir sayi giriniz\n");
	scanf("%d",&s);
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	for(i=0;i<N;i++){
		if(s>A[i]){
			say=say+1;
		}
	}
	printf("%d",say);
	return 0;
	
	
}

//deneme ve compile yapildi
//bir dizide disardan girilen bir sayinin dizinin elemanlardan kac tanesinden büyük oldugunu bulan algoritma ve program
//sayfa 25
//2.soru
//kod calýsýyor
