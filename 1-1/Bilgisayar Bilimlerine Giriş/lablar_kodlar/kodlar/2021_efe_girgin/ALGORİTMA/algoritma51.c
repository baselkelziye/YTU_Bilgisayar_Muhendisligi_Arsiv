#include <stdio.h>
int main(){
	int N,k1,k2,k3,i;
	printf("lutfen dizinin boyutunu giriniz\n");
	scanf("%d",&N);
	
	int A[N];
	k1=0;
	k2=0;
	k3=0;
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	for(i=0;i<N;i++){
		if(A[i]<10&&A[i]>=0){
			k1++;
		}
		else if(A[i]>=10&&A[i]<100){
			k2++;
		}
		else if(A[i]>=100&&A[i]<1000){
			k3++;
		}
	}
	printf("1 basamakli %d tane 2 basamakli %d tane  3 basamakli %d tane sayi vardir",k1,k2,k3);
}
//kod calýsýyor
//tam sayilardan olusan bir dizi veriliyor.bu dizi elemanlardan kac tanesinin bir basamakli,kac tanesinin 2 basamakli,kac tanesinin de 3 basamakli oldugunu bulan algoritma ve programi
//sayfa 44
//1.soru

