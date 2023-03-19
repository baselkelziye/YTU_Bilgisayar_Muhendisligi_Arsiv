#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "ptypes.h"
#include "watchdog.h"

// global variables
S32 activeClient   = 0;
S32 signalReceived = 0;

PRO_INFO process[NUM_OF_PROCESSES] = { 
		{"./print", "", 0, DEAD}
//		, {"/opt/csr/bin/mainudp", "", 0, DEAD} 
//		, {"/opt/csr/bin/print", "", 0, DEAD}
//		, {"/opt/csr/bin/status", "", 0, DEAD}
		};

// local function prototypes
void heartBeat( S32, siginfo_t *, void * );
void startClients( void );
void checkClientStatus( S32 );

// functions
// ************************************************************************************************
//	main wathcdog entry
//	returns 	-	return code
// ************************************************************************************************
S32 main (void)  {

	S32 i;
	
	struct sigaction act;
 
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = heartBeat; 

	sigaction(SIGUSR2, &act, 0);

	startClients();

	// TODO log start status to syslog

	while (1==1)  {

		for (i = 0; i < NUM_OF_PROCESSES; i++) {
			checkClientStatus(i);
		}

		// TODO log status to syslog
		
		sleep(SLEEP_TIME);
	}

	return 0;
}

// ************************************************************************************************
//	checks the status of clients	
//	clientID	-	id of the client process to check status
//	returns 	-
// ************************************************************************************************
void checkClientStatus (S32 clientID)  {

	pid_t 	pid;
	pid_t 	wpid;
	S32 	clientStatus;

	signalReceived 	= 0;
	activeClient 	= clientID;
	
	if (process[clientID].pid != 0) {
		kill(process[clientID].pid, SIGUSR1);
		
		sleep(SLEEP_TIME);
		
		if (signalReceived) {
			process[clientID].status = ALIVE;
		} else {
			process[clientID].status = DEAD;
			process[clientID].pid    = 0;	
			wpid = wait(&clientStatus);	
		}
	} else {
		pid = fork();
		if (pid == 0) {
			execl(process[clientID].pName, process[clientID].pName, process[clientID].pParams, NULL);
			exit(0);
		} else {
			process[clientID].pid = pid;
		}		
	}
}

// ************************************************************************************************
//	starts registered client processes
//	returns -
// ************************************************************************************************
void startClients ( void )  {

	S32 	i;
	pid_t 	pid;

	for (i = 0; i < NUM_OF_PROCESSES; i++) {
		if (process[i].pid == 0) {
			pid = fork();
			if (pid == 0)  {
				execl(process[i].pName, process[i].pName, process[i].pParams, NULL);
				exit(0);
			} else {
				process[i].pid = pid;
				process[i].status = ALIVE;
			}
		}
	}
}


// ************************************************************************************************
//	handles heartbeat responses received from registered clients
//	sigNo	-	look man pages
//	sigInfo	-	look man pages
//	context	-	look man pages
//	returns -
// ************************************************************************************************
void heartBeat ( S32 sigNo, siginfo_t *sigInfo, void *context ) {

	if (sigInfo->si_pid == process[activeClient].pid) {
		signalReceived = 1;
	}
}


