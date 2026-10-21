#include <stdio.h>
#include <stdlib.h>

int main()
{
	char main_text[500] = "I guess it comes down to a simple choice, really. Get busy living or get busy dying...";
	char searched[500];
	int main_text_length = 0;
	int searched_text_length = 0;
	int control = 0;
	int i = 0, j, N = 20;
	
	while(main_text[i] != '\0'){
		main_text[i] = tolower(main_text[i]);
		i++;
	}
	
	main_text_length = i;
	
	printf("Please enter the text you want to be searched: ");
	scanf("%s", searched);
	
	i = 0;
	
	while(searched[i] != '\0'){
		searched[i] = tolower(searched[i]);
		i++;
	}
	
	searched_text_length = i;
	
	printf("\n");
	printf("-> Searched Text:          %s\n",   searched);
	printf("-> Searched Text Length:   %d\n",   searched_text_length);
	printf("-> Main Text:              %s\n",   main_text);
	printf("-> Main Text Length:       %d\n\n", main_text_length);
	
	for(i=0; i<main_text_length-searched_text_length+1; i++){
		j = 0;
		
		while((j < searched_text_length) && (searched[j] == main_text[i+j])){
			j++;
		}
		
		if(j == searched_text_length){
			printf("---> Found: %d to %d   \t=>   [%d, %d)\n", i + 1, i + j + 1, i + 1, i + j + 1);
			control++;
		}
	}
	
	if(control == 0){
		printf("---> Not found.\n");
	}
	else{
		printf("\n---> Total reps: %d\n", control);
	}
	
	getch();
	
	return 0;
}

