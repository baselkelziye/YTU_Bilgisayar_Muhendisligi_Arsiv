#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // tolower() fonksiyonu i�in
#include <locale.h> // t�rk�e karakter i�in

int main() {
	setlocale(LC_ALL, "turkish");
	char main_text[500] = "Ali ata bak, D�n git bir daha bak";
	char searched[500];
	int main_text_length, searched_text_length, i, j, control = 0;
	
	printf("Aramak istedi�iniz kelimeyi giriniz : ");
	gets(searched);
	
	i = 0;
	while(main_text[i] != '\0')
	{
		main_text[i] = tolower(main_text[i]);
		i++;
	}
	main_text_length = i;
	//printf("Main Text k���k harflerle : %s \n", main_text);
	
	i = 0;
	while(searched[i] != '\0')
	{
		searched[i] = tolower(searched[i]);
		i++;
	}
	searched_text_length = i;
	//printf("Searched Text k���k harflerle : %s", searched);
	
	//printf("Main Text boyut: %d \n", main_text_length);
	//printf("Searched Text boyut: %d \n", searched_text_length);
	
	for(i = 0; i < main_text_length - searched_text_length + 1; i++)
	{
		j = 0;
		while((j<searched_text_length) && (searched[j] == main_text[i + j])){
			j++;
		}
		if(j == searched_text_length){
			printf("Arad���n�z kelime %d - %d bulundu.\n", i+1, i+j);
			control++;
		}
	}
	
	if(control == 0){
		printf("Arda��n�z kelime bulunamad�. \n");
	}
	else{
		printf("Arda��n�z kelime %d ad. bulundu. \n",control);
	}
	
	return 0;
}
