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

  //create & initialize semaphore
  mutex = sem_open(SEM_NAME,O_CREAT,0644,1);
  if(mutex == SEM_FAILED)  {
      perror("unable to create semaphore");
      sem_unlink(SEM_NAME);
      exit(-1);
  }

  while(i<10)  {

	sem_wait(mutex);
        t = time(&t);
	printf("Process A enters the critical section at %d \n",t);
        t = time(&t);
	printf("Process A leaves the critical section at %d \n",t);
	sem_post(mutex);
	i++;
	sleep(3);
  }
  sem_close(mutex);
  sem_unlink(SEM_NAME);


  exit(0);
}
