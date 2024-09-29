#include <stdio.h>
int main(){
	int i,j;
	char input,alfabe='A';
	printf("hangi harfe kadar gitmek istiyorsunuz\n");
	scanf("%c",&input);
	for(i=1;i<=(input-'A'+1);i++){
		for(j=1;j<=i;j++){
			printf("%c",alfabe);
		}
		printf("\n");
		alfabe++;
	}
	return 0;
}
//Example 3: Half Pyramid of Alphabets
