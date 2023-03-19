#include <stdio.h>
#include <mqueue.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define MSGQOBJ_NAME    "/test"
#define MAX_MSG_LEN     70

int main(int argc, char *argv[]) {
    mqd_t msgq_id;
    unsigned int msgprio = 0;
    pid_t my_pid = getpid();
    char msgcontent[MAX_MSG_LEN];
    int create_queue = 0;
    char ch;            /* for getopt() */
    time_t currtime;
    
    /* accepting "-q" for "create queue", requesting "-p prio" for message priority */
    while ((ch = getopt(argc, argv, "qp:")) != -1) {
        switch (ch) {
            case 'q':   /* create the queue */
                create_queue = 1;
                break;
            case 'p':   /* specify client id */
                msgprio = (unsigned int)strtol(optarg, (char **)NULL, 10);
                printf("I (%d) will use priority %d\n", my_pid, msgprio);
                break;
            default:
                printf("Usage: %s [-q] -p msg_prio -- ch : %c\n", argv[0],ch);
                exit(1);
        }
    }
    
    /* forcing specification of "-i" argument */
    if (msgprio == 0) {
        printf("Usage: %s [-q] -p msg_prio\n", argv[0]);
        exit(1);
    }
    
    /* opening the queue        --  mq_open() */
    if (create_queue) {
        msgq_id = mq_open(MSGQOBJ_NAME, O_RDWR | O_CREAT | O_EXCL, S_IRWXU | S_IRWXG, NULL);
    } else {
        msgq_id = mq_open(MSGQOBJ_NAME, O_RDWR);
    }
    if (msgq_id == (mqd_t)-1) {
        perror("In mq_open()");
        exit(1);
    }

    /* producing the message */
    currtime = time(NULL);
    snprintf(msgcontent, MAX_MSG_LEN, "Hello from process %u (at %s).", my_pid, ctime(&currtime));
    
    /* sending the message      --  mq_send() */
    mq_send(msgq_id, msgcontent, strlen(msgcontent)+1, msgprio);
    
    /* closing the queue        -- mq_close() */
    mq_close(msgq_id);
        
    return 0;
}

