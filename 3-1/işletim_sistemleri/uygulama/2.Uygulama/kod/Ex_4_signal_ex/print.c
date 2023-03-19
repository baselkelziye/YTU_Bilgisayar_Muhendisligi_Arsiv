#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <stropts.h>
#include <linux/lp.h>
#include <syslog.h>
#include <limits.h>
#include <signal.h>
#include "ptypes.h"
#include "hbeat.h"
#include "print.h"

S32 checkPrinterStatus(int, int );

int main (int argc, char *argv[])  {


    // register heartbeat handler
    registerHeartBeat();


    while(1==1) {

	sleep(PRT_DB_CHCK_INTV);
	printf("I am still alive...\n");
    }    

    return 0;
}
