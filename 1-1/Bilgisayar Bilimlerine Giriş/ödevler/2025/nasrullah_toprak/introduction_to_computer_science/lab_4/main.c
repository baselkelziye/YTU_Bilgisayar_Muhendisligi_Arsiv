#include <stdio.h>

int main() {
	int N, M, i, j;
	int A[100][100];
	int yeni_i, yeni_j, yol_no, sayac, bitis=0;

    printf("Matrisin satir sayisini giriniz: ");
    scanf("%d",&N);
    printf("Matrisin sutun sayisini giriniz: ");
	scanf("%d",&M);
	
	printf("Matrisi giriniz: \n");
	for (i=0;i<N;i++){
		for (j=0;j<M;j++){
			scanf("%d",&A[i][j]);
		}
	}	
	printf("\n");
	i=0;
	while (i<N){
		if (A[i][0] !=0){
			sayac = 1;
			yol_no = A[i][0];
			yeni_i=i;
			yeni_j=0;
			while (yeni_i<N && yeni_i>=0 && yeni_j<M && yeni_j>=0 && bitis==0){
				A[yeni_i][yeni_j]=0;
				if(yeni_j+1<M && A[yeni_i][yeni_j+1]==yol_no){
					sayac++;
					yeni_j++;
				}
				else if (yeni_j-1>=0 && A[yeni_i][yeni_j-1]==yol_no) {
					sayac++;
					yeni_j--;
				}
				else if (yeni_i-1>=0 && A[yeni_i-1][yeni_j]==yol_no) {
					sayac++;
					yeni_i--;
				}
				else if (yeni_i+1<N && A[yeni_i+1][yeni_j]==yol_no) {
					sayac++;
					yeni_i++;
				}
				else if (yeni_i-1>=0 && yeni_j+1<M && A[yeni_i-1][yeni_j+1]==yol_no) {
					sayac++;
					yeni_i--;
					yeni_j++;
				}
				else if (yeni_i+1<N && yeni_j+1<M && A[yeni_i+1][yeni_j+1]==yol_no){
					sayac++;
					yeni_i++;
					yeni_j++;
				}
				else if (yeni_i-1>=0 && yeni_j-1>=0 && A[yeni_i-1][yeni_j-1]==yol_no)  {
					sayac++; 
					yeni_i--;
					yeni_j--;
				}
				else if (yeni_i+1<N && yeni_j-1>=0 && A[yeni_i+1][yeni_j-1]==yol_no){
					sayac++;
					yeni_i++;
					yeni_j--;
				}
				else {
					bitis=1;
				}	
			}
			if (bitis!=0 && sayac>0 && yeni_j==M-1){
				printf("Yol %d -> Uzunluk %d\n",yol_no,sayac);
			}
		}
		i++;
		bitis=0;
	}
	
	return 0;
}
