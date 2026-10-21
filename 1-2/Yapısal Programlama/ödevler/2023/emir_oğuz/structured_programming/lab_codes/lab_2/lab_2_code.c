#include <stdio.h>
#include <stdlib.h>

int function(int number)
{
	if(number % 2 == 1){
		number = 3 * number + 1;
	}
	else if(number % 2 == 0){
		number = number / 2;
	}	
	
	return number;
}

int main()
{
	int N, i = 0, j, check = 0, size = 2;
	int *array;
	int *ptr;
	
	printf("Dizinin baslangic sayisini giriniz: ");
	scanf("%d", &N);
	
	array = (int*) malloc(size * sizeof(int));
	
	array[0] = N;
	
	while(check == 0){
		N = function(array[i]);
		
		i++;
		
		if(i == size){
			size *= 2;
			
			array = realloc(array, size * sizeof(int));
		}
		
		array[i] = N;
		
		if(N == 1){
			check = 1;
		}
	}
	
	printf("\nDizinin son hali:\n{");
	
	i = 0;
	
	while(array[i] != 1){
		printf("%d, ", array[i]);
		i++;
	}
	
	printf("%d}\n", array[i]);
	
	printf("\nDizinin eleman sayisi: %d\n", i + 1);
	
	printf("\nDizinin kapladigi alan: [(%d) x 4] byte\n", size);
	
	printf("\nDizinin elemanlarinin adresi:\n");
	
	j = 0;
	
	for(ptr=array; ptr!=array+(i+1); ptr++){
		printf("%d. indeksin adresi ---> %#X\n", j, ptr);
		j++;
	}
	
	free(array);
	
	getch();
	
	return 0;
}

