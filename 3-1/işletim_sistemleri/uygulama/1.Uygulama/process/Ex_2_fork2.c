#include <stdio.h>
#include <unistd.h>

int main ( void )  {

	int forkResult;
	
	printf("process id : %i\n",getpid());
	forkResult = fork();
	printf("process id : %i - result : %d\n",getpid(), forkResult);

	return 0;
}

