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

    // Get the message queue ID
    msgid = msgget(MSG_KEY, 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    // Receive the message from the message queue
    while (msgrcv(msgid, &msg, sizeof(msg.data), 1, 0) == -1) {
        perror("msgrcv");
        exit(EXIT_FAILURE);
    }

    int result = msg.data * msg.data;
    printf("Process 2 (p2): Square of the received integer: %d\n", result);

    return 0;
}

