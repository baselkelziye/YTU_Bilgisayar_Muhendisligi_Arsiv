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
#include <sys/time.h>

#define SHMSZ 27
char SEM_NAME[]= "vik";


   
int main()  {

  int i=0;
  key_t key;
  sem_t *mutex;
  
  struct timeval t0;
  struct timeval t1;

  float elapsed;

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
        gettimeofday(&t0, 0);
	printf("Process A enters the critical section at %ld \n",(t0.tv_sec*1000+t0.tv_usec/1000)%1000000);
        gettimeofday(&t1, 0);
	printf("Process A leaves the critical section at %ld \n",(t1.tv_sec*1000+t1.tv_usec/1000)%1000000);
	sem_post(mutex);
	i++;
	sleep(3);
  }
  sem_close(mutex);
  sem_unlink(SEM_NAME);


  exit(0);
}
