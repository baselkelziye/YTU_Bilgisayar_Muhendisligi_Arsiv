#ifndef __watchdog_h__
#define __watchdog_h__

// includes
#include "ptypes.h"


// definitions
#define NUM_OF_PROCESSES	1

#define DEAD  				0
#define ALIVE 				1

#define	SLEEP_TIME			2

typedef struct {
	S8		*pName;
	S8		*pParams;
	pid_t   pid;
	U8 		status;
} PRO_INFO;

// global variables

// global functions
void registerHeartBeat(void);
void handleHeartBeat(S32, siginfo_t *, void *);

#endif
