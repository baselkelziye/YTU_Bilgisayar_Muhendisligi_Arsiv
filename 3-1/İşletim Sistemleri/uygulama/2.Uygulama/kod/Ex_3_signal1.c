#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void ouch( int );

int main (void)  {

	struct sigaction act;

	act.sa_handler = ouch;

	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;

	sigaction(SIGINT, &act, 0);

	while(1)  {
		printf("Hello world\n");
		sleep(1);
	}
	exit (0);
}

void ouch( int sigNo ) {

	printf("received SIGINT...\n");
}
