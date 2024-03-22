#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "ptypes.h"
#include "hbeat.h"

// global variables

// local function prototypes

// functions
// ************************************************************************************************
//	registers the heartbeat handler
//	returns -
// ************************************************************************************************
void registerHeartBeat(void) {
    
    struct sigaction act;
    
    sigemptyset(&act.sa_mask);
    act.sa_flags     = SA_SIGINFO | SA_RESTART;
    act.sa_sigaction = handleHeartBeat;
    
    sigaction(SIGUSR1, &act, 0);    
}

// ************************************************************************************************
//	responds to a received heartbeat (SIGUSR1) signal with SIGUSR2 signal
//	returns -
// ************************************************************************************************
void handleHeartBeat(S32 sigNo, siginfo_t *sigInfo, void *context) {
	
    kill(sigInfo->si_pid, SIGUSR2);	
}
