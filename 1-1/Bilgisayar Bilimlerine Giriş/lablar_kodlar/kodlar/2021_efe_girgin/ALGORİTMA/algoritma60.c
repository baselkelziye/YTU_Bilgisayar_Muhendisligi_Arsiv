#include <stdio.h>
int main(){
	int N,i,k;
	printf("lutfen dizinin boyutunu giriniz\n");
	scanf("%d",&N);
	
	int S[10];
	int A[N];
	printf("lutfen yaslarini giriniz\n");
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	for(i=0;i<10;i++){
		S[i]=0;
	}
	for(i=0;i<N;i++){
		k=((A[i]-1)/10)+1;
		S[k-1]=S[k-1]+1;
	}
	for(i=0;i<10;i++){
		printf("%d.bölge=%d\n",i+1,S[i]);
	}
	return 0;
}
//kod calýsýyor
//bir kasabada yaslarý 1....100 arasýnda degisen 400 kisi bulunuyor.bu kisilerin yaslarýný(1...10,11...21...30,....,91...100)gruplarý 
//olmak üzere bu 10 gruptan birine yerlestiren algoritma ve programi
//sayfa 51
//1.soru

