#include <stdio.h>
#include <unistd.h>

int main ( void )  {

	int forkResult;
	
	printf("process id: %i - parent process id: %i\n",getpid(),getppid());
	forkResult = fork();
	printf("process id: %i - result : %d - parent process id: %i\n",getpid(),forkResult,getppid());

	return 0;
}

