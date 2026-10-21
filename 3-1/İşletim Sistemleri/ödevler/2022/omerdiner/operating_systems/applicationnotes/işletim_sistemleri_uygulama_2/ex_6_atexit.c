#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void parentCleaner ( void );

int main ( void )  {

	if(fork())  { // parent process
		atexit(parentCleaner);
		printf("this is parent %i\n",getpid());
	} else  {     // child process
		printf("this is child %i\n",getpid());
	}
	exit(0);
}

void parentCleaner ( void )  {

	printf("cleaning up parent...\n");

}

