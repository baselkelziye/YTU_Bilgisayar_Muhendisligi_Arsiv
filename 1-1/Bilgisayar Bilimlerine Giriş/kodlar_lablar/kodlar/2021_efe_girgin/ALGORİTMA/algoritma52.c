#include <stdio.h>
int main(){
	int N,top=0,i;
	printf("lutfen dizinin boyutunu giriniz \n");
	scanf("%d",&N);
	int A[N];
	
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	for(i=0;i<N;i++){
		top=top+A[i];
	}
	printf("toplam=%d",top);
	return 0;
}


//deneme ve compile yapildi
//bir dizinin elemanlarinin toplamlarini bulan algoritma ve programi
//sayfa 45
//1.soru
//kod calýsýyor
