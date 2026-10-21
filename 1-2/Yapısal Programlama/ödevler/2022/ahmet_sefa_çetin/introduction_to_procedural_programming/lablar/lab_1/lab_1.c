#include <stdio.h>

int main() {
	
	char kelime[100], devam, temp;
	int i, j, kelimeBoyut;
	
	do {
		printf("kelime giriniz: ");
		scanf("%s", kelime);
		
		kelimeBoyut = 0;	
		do {
			kelimeBoyut++;
		} while (kelime[kelimeBoyut] != '\0');
		
		j = 0;
		do {
			
			i = 0;
			temp = kelime[0];
			do {			
				kelime[i] = kelime[i + 1];
				i++;
			} while(i < kelimeBoyut);
			
			kelime[i - 1] = temp;
			printf("%s\n", kelime);
			
			j++;
		} while (j < kelimeBoyut);			
		
		printf("\ndevam etmek icin 'E' veya 'e' giriniz. Bitirmek icin baska bir sey giriniz: ");
		scanf(" %c", &devam);
		
	} while(devam == 'e' || devam == 'E');
	
	return 0;
}
