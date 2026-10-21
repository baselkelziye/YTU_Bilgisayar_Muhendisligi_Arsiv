#include<stdio.h>
#define max 50

void fonk1(int matrix[][3], int n){
	int i = 0, j, control;
	while(i < n){
		printf("\n%d. is: ", i+1);
		scanf("  %c", &matrix[i][0]);
		control = 0;
		j = i - 1;
		while(control == 0 && j >= 0){
			if((char) matrix[i][0] == (char) matrix[j][0]){
				control = 1;
				i--;
			}
			j--;
		}
		i++;
	}
	i = 0;
	while(i<n){
		printf("\n%d. is suresi: ", i+1);
		scanf("%d", &matrix[i][1]);
		if(matrix[i][1] > 0) i++; 
	}
}

void fonk2(int matrix[][3], int n, int head){
	int i, j;
	i=head;
	while(i != -1){
		for(j=0;j<matrix[i][1];j++){
			printf("%c", matrix[i][0]);
		}
		i=matrix[i][2];
	}
}

int main(){
	int matrix[max][3], head, n, i;

	printf("is sayisi: ");
	scanf("%d", &n);
	
	fonk1(matrix, n);
	
	printf("\nhead: ");
	scanf("%d", &head);
	
	for(i=0;i<n;i++){
		printf("\n%c isinin tuttugu link: ", matrix[i][0]);
		scanf("%d", &matrix[i][2]);
	}
	
	fonk2(matrix, n, head);
	return 0;
}
