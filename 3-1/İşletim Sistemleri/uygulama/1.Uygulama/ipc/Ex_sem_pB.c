#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define SHMSZ 27
char SEM_NAME[]= "vik";

int main()  {

  int i=0;
  key_t key;
  sem_t *mutex;
  time_t t;

  //name the shared memory segment
  key = 1000;

  //create & initialize existing semaphore
  mutex = sem_open(SEM_NAME,0,0644,0);
  if(mutex == SEM_FAILED)  {
      perror("reader:unable to execute semaphore");
      sem_close(mutex);
      exit(-1);
  }

  while(i<10)  {

	sem_wait(mutex);
        t = time(&t);
	printf("Process B enters the critical section at %d \n",t);
        t = time(&t);
	printf("Process B leaves the critical section at %d \n",t);
	sem_post(mutex);
	i++;
	sleep(2);
  }

  sem_close(mutex);

  exit(0);
}
