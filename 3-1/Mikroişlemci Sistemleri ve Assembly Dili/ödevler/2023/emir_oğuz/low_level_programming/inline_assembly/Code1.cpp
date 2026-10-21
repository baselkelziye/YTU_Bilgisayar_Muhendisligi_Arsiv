#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	short n = 6, x = 5, T = 1;

	__asm
	{
		MOV CX, n
		MOV SI, x
		MOV BX, T
		MOV AX, SI
		MOV DI, 1
		MOV DX, 0
		L1: PUSH AX
		DIV DI
		ADD BX, AX
		POP AX
		MUL SI
		INC DI
		LOOP L1
		MOV T, BX
	}

	printf("Result = %d\n\n", T);

	system("PAUSE");

	return 0;
}

