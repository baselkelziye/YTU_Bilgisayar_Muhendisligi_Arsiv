#include <stdio.h>
int main(){
	int N,i,j,top,ort,x,k,l,m;
	printf("lutfen dizinin boyutunu giriniz\n");
	scanf("%d",&N);
	
	printf("bir x degeri giriniz\n");
	scanf("%d",&x);
	
	int B[N];
	int A[N];
	j=1;
	top=0;
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	for(i=0;i<N;i++){
		top=top+A[i];
		
		B[j]=ort;
		j=j+1;
	}
	ort=top/i;
	i=1;
	while((i<=N) && (x>A[i])){
		i=i+1;
	}
	k=A[i]-x;
	l=A[i-1]-x;
	
	if(k<l){
		m=i;
	}
	else{
		m=i+1;
		
	}
	printf("%d",m);
}





//kucukten buyuge sirali bir A(N) dizisinin elemanlari toplanarak ortalama degerleri alýnýyor.
//ortalama belli bir x degerine yakin olana dek devam ediliyor.kac elemanýn ortalamaya girdigini bulan algoritma ve programi
//sayfa 33
//1.soru
//kod calýsmýyor
