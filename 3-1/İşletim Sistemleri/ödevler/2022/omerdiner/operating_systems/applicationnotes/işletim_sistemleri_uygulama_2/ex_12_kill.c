#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void childProcess() {
    printf("Child process (PID: %d) is running.\n", getpid());
    sleep(2); // Child process 2 saniye uyusun
    printf("Child process (PID: %d) has finished.\n", getpid());
}

int main() {
    pid_t childPid;

    // Child process oluştur
    if ((childPid = fork()) == 0) {
        // Child process
        childProcess();
    } else if (childPid > 0) {
        // Parent process
        printf("Parent process (PID: %d) created child process (PID: %d).\n", getpid(), childPid);

        // Parent, child process'i öldür
        sleep(2); // Ölmeden önce biraz bekleyelim
        if (kill(childPid, SIGTERM) == 0) {
            printf("Parent process killed child process (PID: %d).\n", childPid);
        } else {
            perror("kill");
        }
    } else {
        perror("fork");
        exit(1);
    }

    return 0;
}
