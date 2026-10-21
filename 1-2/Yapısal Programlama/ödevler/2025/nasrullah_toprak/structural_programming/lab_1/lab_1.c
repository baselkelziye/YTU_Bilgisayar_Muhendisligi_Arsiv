#include <stdio.h>
#define MAX 100

void matrisgirisi(int A[2][MAX], int N){
	int i, j;
	printf("Matrisin elemanlarini Giriniz: ");
	for (i=0;i<2;i++){
		for (j=0;j<N;j++){
			scanf("%d",&A[i][j]);
		}
	}
}

int matriskontrolu(int A[2][MAX], int N){
	int i,j, flag=0;
	for (i=0;i<N-1;i++) {
		for (j=i+1;j<N;j++) {
			if (*(*(A+0)+i) == *(*(A+0)+j)) {
				flag=1;
			}
		}
	}
	return flag;
}

int main() {
		
	int i, j, N, M, flag1=0, flag2=0;
	int A[2][MAX], B[2][MAX];
	
	printf("Ilk matris (2xN) icin N degerini giriniz: ");
	scanf("%d",&N);

	matrisgirisi(A, N);
	
	do{
	if (flag1==1){
		printf("Matrisin ilk satirinda ayni rakam olmamalidir, tekrar matrisinizi giriniz: ");
		matrisgirisi(A, N);
	}
	flag1 = matriskontrolu(A, N);
	}while(flag1==1);

	printf("Ikinci matris (2xM) icin N degerini giriniz: ");
	scanf("%d",&M);

	matrisgirisi(B, M);
	do{
	if (flag2==1){
		printf("Matrisin ilk satirinda ayni rakam olmamalidir, tekrar matrisinizi giriniz: ");
		matrisgirisi(B, M);
	}
	flag2 = matriskontrolu(B, M);
	}while(flag2==1);
	
	for (i=0;i<N;i++) {
        for (j=0;j<M;j++) {
            if (*(*(A+0)+i) == *(*(B+0)+j)) {
                printf("Ortak Sayi & Toplami: %d -> %d + %d = %d\n", *(*(A+0)+i),*(*(A+1)+i),*(*(B+1)+j),*(*(A+1)+i) + *(*(B+1)+j));
            }
        }
    }
	
	return 0;
}

