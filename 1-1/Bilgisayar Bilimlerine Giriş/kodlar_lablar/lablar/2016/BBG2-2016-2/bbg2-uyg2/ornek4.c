#include <stdio.h>
#include <stdbool.h>

int main(){
	int i, n, dizi[100];
	bool kont;

	printf("n degerini giriniz: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++){
		printf("dizi[%d]: ", i+1);
		scanf("%d", &dizi[i]);
	}

	kont = true;
	i = 0;

	while ((kont) && (i < n-1)){
		if(dizi[i] > dizi[i+++1]){
			kont = false;
		}
		//i++;
	}






	if(kont){
		printf("Dizi siralidir \n");
	}else{
		printf("Dizi sirasizdir \n");
	}


	

	return 0;
}
