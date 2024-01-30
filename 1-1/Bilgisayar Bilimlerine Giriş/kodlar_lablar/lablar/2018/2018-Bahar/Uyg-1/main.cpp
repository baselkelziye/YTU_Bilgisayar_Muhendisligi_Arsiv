#include <stdio.h>
#include <conio.h>


int main() {
	int N;printf("Lutfen bir sayi giriniz : ");scanf("%d",&N);
	
	for(int i = N; i >= 1; i--){
		for(int j = 1; j <= i; j++){
			printf("%d  ", j);
		}
		for(int k = i-1; k >= 1; k--){
			printf("%d  ", k);
		}
		printf("\n");
	}

	getch();
	return 0;
}
