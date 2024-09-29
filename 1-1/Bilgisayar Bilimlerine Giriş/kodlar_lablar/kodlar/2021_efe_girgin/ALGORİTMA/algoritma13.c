#include <stdio.h>
int main(){
	int N,byk,kck,yerk,yerb,i;
	printf("lütfen dizinin boyutunu giriniz \n");
	scanf("%d",&N);
	int A[N];

	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	
	byk=A[0];
	yerb=1;
	kck=A[0];
	yerk=1;
	
	for(i=1;i<N;i++){
		if(A[i]>byk){
			byk=A[i];
			yerb=i+1;
		}
		else if(A[i]<kck){
			kck=A[i];
			yerk=i+1;
		}
	}
	printf("buyuk sayimiz =%d yeri=%d kucuk sayimiz =%d yeri=%d",byk,yerb,kck,yerk);
	return 0;
}


//denendi ve compile yapildi
//bir dizinin en buyuk ve en kucuk elemanlarini ve yerini bulan algoritma ve programi
//sayfa 12
//kod calýsýyor
