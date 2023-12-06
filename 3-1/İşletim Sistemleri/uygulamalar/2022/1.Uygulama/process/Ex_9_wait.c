#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define numOfChilds 5
int main ( void )  {

	int i;
	int child_status;
	pid_t pid[numOfChilds];
	pid_t wpid;

	for (i = 0; i < numOfChilds; i++)  {
		if ((pid[i] = fork()) == 0)  {
       			exit(100+i);            // create & exit child
		}
	}

	for (i = 0; i < numOfChilds; i++) {
   		wpid = wait(&child_status);     // wait for child 
   		if (WIFEXITED(child_status))  { // check exit status
       			printf("Child %d terminated with exit status %d\n",wpid, WEXITSTATUS(child_status));
		} else {
     			printf("Child %d terminate abnormally\n", wpid);
		}
	}
	exit(0);
}

 
