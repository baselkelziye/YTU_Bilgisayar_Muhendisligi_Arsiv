#include <stdio.h>

int main(){
	char paragraph [1000];
	int char_val ['z'-'a'];
	int index = 0;
	int word_ctr,sentence_ctr,character_ctr;
	printf("Enter the paragraph: ");
	fgets(paragraph, sizeof(paragraph), stdin);
	
	for (int i = 0 ; i<('z'-'a'); i++){
        char_val[i] = 0;
    }
    
    while(paragraph[index] != '\0'){
    	if(paragraph[index] == ' ')
    		word_ctr++ ;
		else if (paragraph[index] == '.')
			sentence_ctr++ ;
		
		else if(paragraph[index] >= 'a' && paragraph[index] <= 'z'){
			
			char_val[paragraph[index]-'a']++ ;
			character_ctr++;
		}
		
		else if(paragraph[index] >= 'A' && paragraph[index] <= 'Z'){
			
			char_val[paragraph[index]-'A']++ ;
			character_ctr++;
		}
		
		// printf("%d",index);
		index++;
	}
	
	printf("sentence count: %d\n",sentence_ctr);
	printf("word count: %d\n",word_ctr);	
	printf("character count: %d\n",character_ctr);
	
	for (int i = 0 ; i<('z'-'a'); i++){
        printf("%c - %d\t|",i + 'a',char_val[i]);
        for (int j = 0; j < char_val[i];j++){
        	printf("*");
		}
		printf("\n");
    }
	
	printf("\n");
	
	printf("%s \n",paragraph);
	
	//for (int i =0; 'z'-'a' ;i++){
	//	printf("%d,\n",char_val[i]);
	//}
	
	return 0;
}
