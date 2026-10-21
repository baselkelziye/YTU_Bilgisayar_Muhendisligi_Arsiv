#include <stdio.h>
#define M 50
#define N 50
#define R 50

int main()
{
	int i, j, r;
	int flag;
	int row, column;
	int matrix[M][N] = {0}, route[R] = {0};
	
	printf("Olusturmak istediginiz matrisin ebatlarini giriniz...\n");
	printf("Satir: ");
	scanf("%d", &row);
	printf("Sutun: ");
	scanf("%d", &column);
	printf("\n");
	
	while(row <= 0 || column <= 0){
		system("cls");
		printf("Uygun olmayan bir sayi girdiniz!\n");
		printf("Lutfen matris ebatlari icin pozitif bir tam sayi giriniz: ");
		printf("Satir: ");
		scanf("%d", &row);
		printf("Sutun: ");
		scanf("%d", &column);
		printf("\n");
	}
	
	printf("Ebatlarini girdiginiz matrisin degerlerini sadece 0 ve 1'lerden olusacak sekilde giriniz...\n\n");
	
	for(i=0; i<row; i++){
		
		for(j=0; j<column; j++){
			printf("Eleman[%d][%d] = ", i + 1, j + 1);
			scanf("%d", &matrix[i][j]);
		}
		
		printf("\n");
	}
	
	printf("\nOlusturdugunuz matris:\n\n");
	
	for(i=0; i<row; i++){
		
		for(j=0; j<column; j++){
			printf("%4d", matrix[i][j]);
		}
		
		printf("\n\n");
	}
	
	i = 0, j = 0, r = 0;
	
	while(matrix[i][j+1] != 0 || matrix[i+1][j] != 0){
		flag = 1;
			
		if(matrix[i][j+1] == 1 && j < column){
			route[r] = 1;
			j++;
			r++;
		}
		else if(matrix[i+1][j] == 1 && i < row){
			route[r] = 2;
			i++;
			r++;
		}
	}
	
	if(flag == 1){
		
		printf("Girdiginiz matristeki bir rota: ");
		
		for(i=0; i<r; i++){
			printf("%d ", route[i]);
		}
	}	
	else{
		printf("Bir rota bulunamamistir.");
	}
	
	printf("\n");
	
	getch();
	
	return 0;
}

