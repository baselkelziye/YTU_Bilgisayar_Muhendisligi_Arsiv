#include <stdio.h>
int main(){
	int N,i,nn,ns,k,n;
	printf("lutfen dizinin boyutunu giriniz \n");
	scanf("%d",&n);
	
	int A[n];
	i=1;
	nn=n;
	if(n%2==0){
		ns=n/2;
	}
	else{
		ns=n/2+1;
	}
	for(k=0;k<ns;k++){
		A[nn-k-1]=i+1;
		A[k]=i;
		i=i+2;
	}
	for(k=0;k<n;k++){
		printf("%d\n",A[k]);
	}
	return 0;
}
//kod calýsýyor
//herhangi bir N sayisina göre 1 3 5....N......4 2 dizisini olusturan algoritma ve programi.
//sayfa 24
//1.soru

