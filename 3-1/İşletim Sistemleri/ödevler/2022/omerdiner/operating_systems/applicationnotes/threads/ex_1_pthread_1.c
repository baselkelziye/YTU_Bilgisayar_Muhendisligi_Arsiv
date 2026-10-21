#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define NUM_THREADS	5

// Strings for the Hello World messages 
char *messages[NUM_THREADS];

void *PrintHello(void *threadid) {
   int *myarg;
   sleep(1);                  // Sleep for a second
   myarg = (int *) threadid;  // Get own id from the argument 
   printf("Thread %d: %s\n", *myarg, messages[*myarg]);
   pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  
  pthread_t threads[NUM_THREADS];    // Thread identifiers 
  int i, rc, *taskid[NUM_THREADS];   // Id numbers for each thread 

  // Initialize the salutations for each thread 
  messages[0] = "English: Hello World!"; 
  messages[1] = "French: Bonjour, le monde!";
  messages[2] = "Spanish: Hola al mundo";
  messages[3] = "Klingon: Nuq neH!";
  messages[4] = "German: Guten Tag, Welt!"; 
   
  for(i=0; i<NUM_THREADS; i++) {
    // Allocte an array for arguments to the threads 
    taskid[i] = (int *) malloc(sizeof(int));
    *taskid[i] = i;
    // Create a thread with its argument in taskid[i] 
    rc = pthread_create(&threads[i], NULL, PrintHello, (void *) taskid[i]);
    if (rc) { // Check for errors 
      printf("ERROR; return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
  }
  pthread_exit(0);
}
