/*
  This example demonstrates how to use pthread_join and how to pass results
  back from the treads. Threads are explicitly created as joinable
  Each thread draws one million random numbers between 0 and 1 and adds
  these together in a variable sum. This is passed back to the joining thread
  in the pthread_exit call.
  Compile with 'gcc -O3 -pthread join.c -o join'
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUM_THREADS     10
#define ITERATIONS 1000000

/* 
* This is the start routine that all threads execute. It draws 1000000
* random numbers between 0 and 1 and sums them in result
*/
void *work(void *t) {
  double *result;
  long int i, tid;  // Pointers are 64 bits so we use a long int
  result = malloc(sizeof(double));
  *result = 0.0;
  tid = (long int)t;             // Get thread number
  for (i=0; i<ITERATIONS; i++) {
    *result += (double)random()/RAND_MAX;
  }
  pthread_exit((void*) result);  // Pass the pointer to result back
}


int main(int argc, char *argv[]) {
  pthread_t thread[NUM_THREADS];
  pthread_attr_t attr;
  int rc;
  long int i;
  double res, total=0.0;
  void *status;

  // Initialize and set thread joinable attribute
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

  for(i=0;i<NUM_THREADS;i++) {
    rc = pthread_create(&thread[i], &attr, work, (void *)i);
    if (rc) {
      printf("ERROR; return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
  }

  // Free attribute and join with worker threads
  pthread_attr_destroy(&attr);
  for(i=0; i<NUM_THREADS; i++) {
    rc = pthread_join(thread[i], &status); // Join with each threrad
    if (rc) {
      printf("ERROR return code from pthread_join() is %d\n", rc);
      exit(-1);
    }
    res = *(double *)status;  // Get the result from each thread
    total += res;             // Add it to total
    printf("Joined with thread %ld, result = %6.2f\n",i,res);
  }
  printf("\nProgram completed, total = %6.2f\n", total);
  pthread_exit(NULL);
}
