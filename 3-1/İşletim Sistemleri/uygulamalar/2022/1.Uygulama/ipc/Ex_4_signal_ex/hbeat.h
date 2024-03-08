#ifndef __hbeat_h__
#define __hbeat_h__

// includes
#include "ptypes.h"


// definitions

// global variables

// global functions
void registerHeartBeat(void);
void handleHeartBeat(S32, siginfo_t *, void *);

#endif