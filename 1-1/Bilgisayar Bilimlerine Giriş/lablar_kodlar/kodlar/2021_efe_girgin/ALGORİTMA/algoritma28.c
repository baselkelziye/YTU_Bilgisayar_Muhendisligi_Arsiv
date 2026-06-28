#include <stdio.h>

int main(){
	int N,alt,ust,orta,x,i;
	printf("lutfen dizinin boyutunu giriniz\n");
	scanf("%d",&N);
	
	int A[N];
	
	printf("Dizinin elemanlarini giriniz:\n");
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	printf("lutfen aramak istediginiz sayiyi giriniz=\n");
	scanf("%d",&x);
	
	alt=1;
	ust=N;
	orta=(alt+ust)/2;
	
	while(alt<ust){
		if(x==A[orta]){
			alt=ust;
		}
		else if(x>A[orta]){
			alt=orta+1;
			orta=(alt+ust)/2;
		}
		else{
			ust=orta-1;
			orta=(alt+ust)/2;
		}
	}
	if(x==A[orta]){
		printf("Sayinin indisi:%d Sayi:%d",orta,A[orta]);
	}
	else{
		printf("aranan sayi yoktur\n");
		
	}
}
//kod calýsýyor
//sirali bir dizide herhangi bir x sayisinin olup olmadigini daha kisa yoldan arastýran algoritma ve programi(binary search)
//sayfa 21
//1.soru

