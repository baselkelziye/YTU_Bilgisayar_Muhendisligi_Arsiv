#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	short array[5] = { 1, 2, 3, 4, 5 };

	__asm
	{
		XOR ESI, ESI
		MOV CX, 5
		L1: PUSH array[ESI]
		ADD ESI, 2
		LOOP L1

		XOR ESI, ESI
		MOV CX, 5
		L2 : POP array[ESI]
		ADD ESI, 2
		LOOP L2
	}

	printf("The new version of the array: {");

	for (int i = 0; i < 5; i++) {
		printf("%d, ", array[i]);
	}

	printf("\b\b}\n\n");

	system("PAUSE");

	return 0;
}
