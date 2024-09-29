#include <stdio.h>
int main(){
	char c,lowercase,uppercase;
	printf("lutfen bir harf giriniz\n");
	scanf("%c",&c);
	
	lowercase=(c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
	uppercase=(c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
	
	if(lowercase||uppercase){
		printf("%c harfi unlu bir harftir\n",c);
		
	}
	else{
		printf("%c harfi unsuz bir harftir\n",c);
	}
	return 0;
}
//Program to Check Vowel or consonant
