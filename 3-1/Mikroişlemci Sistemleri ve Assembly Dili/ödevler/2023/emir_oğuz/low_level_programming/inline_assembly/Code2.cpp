#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	short number1 = 0, number2 = 0, result = 0;

	printf("Enter the first number: ");
	scanf_s("%hd", &number1);
	printf("\nEnter the second number: ");
	scanf_s("%hd", &number2);

	__asm
	{
		MOV AX, number1
		MOV BX, number2
		CMP AX, BX
		JAE L1
		XCHG AX, BX
		L1: XOR DX, DX
		DIV BX
		CMP DX, 0
		JE L2
		MOV AX, BX
		MOV BX, DX
		JMP L1
		L2: MOV result, BX
	}

	printf("\nResult: %hd\n\n", result);

	system("PAUSE");

	return 0;
}

