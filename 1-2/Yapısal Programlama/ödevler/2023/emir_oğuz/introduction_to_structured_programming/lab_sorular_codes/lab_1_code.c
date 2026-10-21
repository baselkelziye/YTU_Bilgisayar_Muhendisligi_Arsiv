#include <stdio.h>
#define N 50

int main()
{
	int i, j, k;
	int counter = 1, flag = 0, isOne = 0, size;
	int array1[N], array2[N];
	
	printf("Dizinin boyutunu giriniz: ");
	scanf("%d", &size);
	
	while(size <= 0){
		system("cls");
		printf("Uygun olmayan bir sayi girdiniz!\n");
		printf("Lutfen dizi boyutu icin pozitif bir tam sayi giriniz: ");
		scanf("%d", &size);
	}
	
	printf("\nLutfen dizinizin elemanlarini, pozitif bir tam sayi olacak sekilde giriniz...\n");
	
	for(i=0; i<size; i++){
		scanf("%d", &array1[i]);
	}
	
	printf("\nOlusturdugunuz dizi:\n");
	
	printf("{");
	
	for(i=0; i<size; i++){
		printf("%d, ", array1[i]);
	}
	
	printf("\b\b}\n\n");
	
	k = 0;
	
	if(size > 1){
		
		for(i=0; i<size-1; i++){
			
			for(j=i+1; j<size; j++){
				
				if(array1[i] == 1 && isOne == 0){
					isOne = 1;
				}
				
				if(array1[i] == array1[j]){
					counter++;
					array1[j] = 0;
				}
			}
		
			if(counter == array1[i]){
				array2[k] = array1[i];
				k++;
				flag++;
			}
			
			counter = 1;
		}
		
		if(isOne == 0 && array1[size - 1] == 1){
			array2[k] = array1[i];
			k++;
			flag++;
		}
	}
	else if(size == 1 && array1[0] == 1){
		printf("Girdiginiz dizide, kendi degeri kadar tekrar eden elemanlar:\n{1}\n");
	}
	else if(size == 1 && array1[0] != 1){
		printf("Girdiginiz dizide, kendi degeri kadar tekrar eden bir eleman bulunmamaktadir.\n");
	}
	
	if(flag != 0){
		printf("Girdiginiz dizide, kendi degeri kadar tekrar eden elemanlar:\n");
	
		printf("{");
	
		for(i=0; i<k; i++){
			printf("%d, ", array2[i]);
		}
	
		printf("\b\b}\n");
	}
	else if(flag == 0 && size > 1){
		printf("Girdiginiz dizide, kendi degeri kadar tekrar eden bir eleman bulunmamaktadir.\n");
	}
	
	getch();
	
	return 0;
}

