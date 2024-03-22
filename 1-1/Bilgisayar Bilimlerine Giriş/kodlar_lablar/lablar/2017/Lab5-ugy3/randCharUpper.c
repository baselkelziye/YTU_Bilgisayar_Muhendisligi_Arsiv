#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rastgeleBuyuk(char* cumle);
const char cev = 5;

int main(){
	char cumle[100];
	printf("Cumle: ");
	scanf("%[^\n]s", &cumle);
	
	printf("\n\n%s\n", cumle);
	rastgeleBuyuk(cumle);
	printf("%s\n\n\n", cumle);
	
	system("PAUSE");	
	return 0;
}

void rastgeleBuyuk(char* cumle){
	srand(time(NULL));
	
	int boy = 0, i = 0, r_ind;
	
	while(cumle[boy++] != '\0');
	
	while(i < cev){
		r_ind = rand()%boy;
		if(cumle[r_ind] >= 97){
			cumle[r_ind] -= 32;
			i++;
		}
		
	}
}
