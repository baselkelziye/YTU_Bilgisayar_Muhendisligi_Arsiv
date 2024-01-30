#include <stdio.h>
#include <stdlib.h>

int charBul(char c, char* cum);

int main(){
	char cumle[100], harf = 'b';
	printf("Cumle: ");
	scanf("%[^\n]s", &cumle);
	
	int hz = charBul(harf, cumle);
	
	printf("\"%s\" cumlesinde \"%c\" harfi %d kere geciyor.\n\n", cumle, harf, hz);
	
	system("PAUSE");	
	return 0;
}

int charBul(char ch, char* cum){
	int i = 0, say = 0;
	while(cum[i] != '\0')
		if(cum[i++] == ch)
			say++;
	return say;
}
