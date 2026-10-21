#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    int shmid;
    key_t key = ftok("shared_memory_key", 65); // Create a unique key

    // Create shared memory segment
    shmid = shmget(key, sizeof(int), 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory
    int *shared_number = (int *)shmat(shmid, (void *)0, 0);
    if (*shared_number == -1) {
        perror("shmat");
        exit(1);
    }

    printf("Enter an integer: ");
    scanf("%d", shared_number);

    // Detach shared memory
    shmdt(shared_number);

    return 0;
}

