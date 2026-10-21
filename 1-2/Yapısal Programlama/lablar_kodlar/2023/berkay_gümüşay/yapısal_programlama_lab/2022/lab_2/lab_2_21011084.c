#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	srand(time(NULL));
	int *sepet;
	int run=1;
	int i = 0;
	int valueSize;
	int sepetSize = 3;
	sepet = (int*)malloc(3*sizeof(int));  // 3 Elemanlýk Dizi Açma
	sepet[0] = g();
	i++;
	while(run){
		sepet[i] = g();
		if((sepet[i] == 6) && (sepet[i-1] == 6)){  // 6 - 6  Kontrolü
			run = 0;
		}
		else{
			if((i+1)%3 == 0){
				sepetSize = sepetSize +3;  // Eðer Dizi Sona Geldiyse Boyutunu 3 Arttýrma
				sepet = realloc(sepet,sepetSize*sizeof(int));
			}
		}
		i++;
	}
	valueSize = i;
	printf("Dizinin Boyutu = %d | Dizinin Eleman Sayisi = %d\n\nDizi:\n",sepetSize,valueSize);
	
	for(i=0;i<valueSize;i++){
		printf("%d  ",sepet[i]);
	}
	return 0;
}
int g(){
	int value;
	value = (rand()%6) +1;
	return value;
}
