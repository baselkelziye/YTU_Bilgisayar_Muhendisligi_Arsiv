#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSG_KEY 1234

// Define a message structure
struct message {
    long mtype; // Message type (must be greater than 0)
    int data;   // Integer data
};

int main() {
    int msgid;
    struct message msg;

    // Create a message queue (or get the ID if it already exists)
    msgid = msgget(MSG_KEY, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    printf("Process 1 (p1): Enter an integer: ");
    scanf("%d", &msg.data);

    // Set the message type to 1
    msg.mtype = 1;

    // Send the message to the message queue
    if (msgsnd(msgid, &msg, sizeof(msg.data), 0) == -1) {
        perror("msgsnd");
        exit(EXIT_FAILURE);
    }

    printf("Process 1 (p1): Integer sent to process 2 (p2)\n");

    return 0;
}

