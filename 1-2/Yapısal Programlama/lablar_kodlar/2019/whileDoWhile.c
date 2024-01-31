// this program counts the spaces within a given phrase
// the program keeps getting characters from the user until the enter key is pressed
// WRITE THE PROGRAM THAT DOES THE SAME WORK WITHOUT USING IF OR SWITCH STATEMENT
#include <stdio.h>
int main()
{
	char ch;
	int numofSpace=0;
	
	// DO - WHILE VERSION
	do
	{
		scanf("%c",&ch);	//ch=getchar(); is useful too
		if (ch==' ')
			numofSpace++;	
	}while (ch!='\n');		// '\n' is new line character
	printf("Number of spaces (do-while):%d\n",numofSpace);
	
	// WHILE - DO VERSION
	numofSpace=0;
	scanf("%c",&ch);
	while (ch!='\n')		// until the enter key is pressed
	{
		if (ch==' ')
			numofSpace++;
		scanf("%c",&ch);	
	}
	printf("Number of spaces (while-do):%d\n",numofSpace);

	return 0;
}
