#include <stdio.h>
#include <unistd.h>

int main ( void )  {

	printf("Message before fork\n");

	fork();

	printf("Message after fork\n");

	return 0;
}

