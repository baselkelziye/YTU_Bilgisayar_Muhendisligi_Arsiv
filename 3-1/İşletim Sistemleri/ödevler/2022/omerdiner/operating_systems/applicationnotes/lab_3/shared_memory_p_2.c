#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    int shmid;
    key_t key = ftok("shared_memory_key", 65); // Same key as p1.c

    int dataProcessed = 0;  // Flag to track whether data has been processed

    while (!dataProcessed) { // Continue until data is available and processed
        // Get the shared memory segment
        shmid = shmget(key, sizeof(int), 0666);
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

        if (*shared_number != 0) {
            // Data is available in shared memory
            int result = (*shared_number) * (*shared_number);
            printf("Square of the integer: %d\n", result);

            // Detach shared memory
            shmdt(shared_number);

            // Set the flag to indicate data has been processed
            dataProcessed = 1;

            // Remove shared memory segment (optional, depending on your use case)
            shmctl(shmid, IPC_RMID, NULL);
        }

        // Detach shared memory
        shmdt(shared_number);

        // Optional: Sleep for a short duration to avoid busy-waiting
        // sleep(1);
    }

    return 0;
}

