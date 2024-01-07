#include <stdio.h>

int main(void){
	int n, dizi[100], max, i;
	printf("n: ");
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		printf("dizi[%d]: ", i + 1);
		scanf("%d", &dizi[i]);
	}
	max = dizi[0];
	for(i = 1; i < n; i++){
		if(dizi[i] > max)
			max = dizi[i];
	}
	printf("Maks: %d\n", max);
	return 0;
}
