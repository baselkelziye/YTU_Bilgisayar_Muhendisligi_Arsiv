#include<stdio.h>
#include<stdlib.h>

#define P (float)1/(6*6*6)

int main(){
	int i, j, k;
	int toplam;
	float **deger;
	
	deger = (float**)calloc(16*sizeof(float*));
	if(deger == NULL)
	{
		printf("Bellekte yer ayrilamadi!!");
		return -1;
	}
	for(i = 0; i < 16; i++)
	{
		deger[i] = (float*)calloc(2*sizeof(float));
		if(deger[i] == NULL){
			printf("Bellekte yer ayrilamadi!!");
			return -1;
		}
	}
	
	for(i = 1; i <= 6; i++){
		for(j = 1; j <= 6; j++){
			for(k = 1; k <= 6; k++){
				toplam = i + j + k;
				deger[toplam - 3][0] = toplam;
				deger[toplam - 3][1] += P;
			}
		}
	}
	
	
	for(k = 0; k < 16; k++){
		printf("%.f\t%.8f\n", deger[k][0], deger[k][1]);
	}
	
	for(k = 0; k < 16; k++){
		free(deger[k]);
	}
	free(deger);	
	
	return 0;
}
