/*
  This example demonstrates how to explicitly create a thread in a 
  detached state. This might be done to conserve some system resources
  if the thread never needs to join later. Note that we don't pass any
  results back from the threads, for that we need to synchronize the
  theads with the main program.
  Compile with 'gcc -O3 -pthread detached.c -o detached'
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUM_THREADS	4
#define ITERATIONS 1000000

void *BusyWork(void *t) {
  long int i, tid;
  double maxval, result=0.0;
  tid = (long int)t;
  printf("Thread %ld starting...\n",tid);
  for (i=0; i<ITERATIONS; i++) {
    result += (double)random()/RAND_MAX;
  }
  printf("Thread %ld done. Result = %6.2f\n",tid, result);
}

int main(int argc, char *argv[]) {
  pthread_t thread[NUM_THREADS];
  pthread_attr_t attr;
  int rc;
  long int t;
  
  // Initialize and set thread detached attribute
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
  
  for(t=0;t<NUM_THREADS;t++) {
    printf("Main: creating thread %ld\n", t);
    rc = pthread_create(&thread[t], &attr, BusyWork, (void *)t); 
    if (rc) {
      printf("ERROR; return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
  }
  
  // We're done with the attribute object, so we can destroy it
  pthread_attr_destroy(&attr);
  
  printf("Main: program completed. Exiting.\n");
  pthread_exit(NULL);
}

