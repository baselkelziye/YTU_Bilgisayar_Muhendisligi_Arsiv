#include <pthread.h> // pthread_create(), pthread_exit(), pthread_join()
#include <stdio.h>   // printf(), sprintf(), perror()
#include <unistd.h>  // sleep(), usleep()
#include <stdlib.h>  // srand(), exit(), EXIT_FAILURE, EXIT_SUCCESS
#include <assert.h>  // assert()

#define NUM_OF_THREADS 4
#define RANDOM_USLEEP_MIN 20
#define RANDOM_USLEEP_MAX 1200

/* Makes the caller take a sleep for a random number of microseconds in the
   interval [min, max]. The sleep will be repeated weight number of times. */
void random_usleep(unsigned int *seed, unsigned int weight) {
  int n = RANDOM_USLEEP_MIN + (rand_r(seed) % (RANDOM_USLEEP_MAX - RANDOM_USLEEP_MIN + 1));
  for (int i = 0; i < weight; i++) {
    usleep(n);
  }
}


/* Pointer to pthread_create() start routine function. */
typedef void* (*callback_ptr_t)(void* arg);

/* Information abut a callback function. */
typedef struct {
  /* Callback function pointer. */
  callback_ptr_t address;
  /* Name of the callback function, used to print status messages. */
  char *name;
  /* In an attempt to affect the scheduling of the threads, before
     executing the callback function, each thread will make a random sleep.
     The larger the weight, the larger the random sleep. */
  int weight;
} callback_t;


/* Each thread will use a pointer to an instance of the below structure as the
   single argument to the generic start routine. */
typedef struct {
  /* Sequential thread number, used to identify threads in status messages. */
  int thread_nr;
  /* The function to be executed by the thread. */
  callback_t callback;
  /* Each thread must have a separate random seed. */
  unsigned int seed;
  /* String to be operated on by the thread. */
  char* string;
  /* Numeric result of the operation performed by the thread. */
  int result;
} data_t;

/* Prints a status message for a thread. */
void print_status(data_t *data, char *prefix, int print_result) {
  char result_str[64] = "";

  if (print_result)
    sprintf(result_str, "\n\tresult = %d", data -> result);

  printf("%sT%d\t%s()\n\tseed = %010d\n\tstring = \"%s\"%s\n",
         prefix,
         data -> thread_nr,
         data -> callback.name,
         data -> seed,
         data -> string,
         result_str
         );
}

/* Each thread will use this function as start routine. The generic pattern for
   each thread is to first take a random sleep, print a status message and then
   execute the designated callback. */
void* generic_start_routine(void *arg) {
  data_t *data = (data_t*) arg;

  /* Before executing the callback function, take a random sleep. */
  random_usleep(&data -> seed, data -> callback.weight);

  /* Back from random sleep, print status message. */
  print_status(data, " + ", 0);

  /* Execute the callback function */
  data -> callback.address(arg);

  return NULL;
}

/* Callbacks for the threads. */

void* length(void *arg) {
  data_t *data = (data_t*) arg;
  int i = 0;

  while (data -> string[i]) {
    i++;
  }

  data -> result = i;
  return NULL;
}

void* num_of_spaces(void *arg) {
  data_t *data = (data_t*) arg;
  int i = 0;
  int n = 0;

  while (data -> string[i]) {
    if (data -> string[i] == ' ') n++;
    i++;
  }

  data -> result = n;
  return NULL;
}

void* to_uppercase(void *arg) {
  data_t *data = (data_t*) arg;
  int i = 0;

  while (data -> string[i]) {
    /* Defer execution just a bit to get a more random thread interleaving. */
    random_usleep(&data -> seed, 1);

    if (data -> string[i] <= 'z' && data -> string[i] >= 'a') {
      data -> string[i] -= 0x20;
    }

    i++;
  }

  return NULL;
}

void* to_lowercase(void *arg) {
  data_t *data = (data_t*) arg;
  int i = 0;

  while (data -> string[i]) {
    /* Defer execution just a bit to get a more random thread interleaving. */
    random_usleep(&data -> seed, 1);

    if (data -> string[i] <= 'Z' && data -> string[i] >= 'A') {
      data -> string[i] += 0x20;
    }

    i++;
  }

  return NULL;
}


int main(int argc, char *argv[]) {
  /* A string for the threads to work on. */
  char string[] = "The string shared among the threads.";

  /* An array of thread identifiers, needed by pthread_join() later... */
  pthread_t tid[NUM_OF_THREADS];

  /* Seed the pseudo random number generator. */
  srand(time(NULL));

  /* An array with argument data for each thread. */
  data_t arg[NUM_OF_THREADS];

  /* An array of callbacks, one for each thread. Each element is a callback_t
     structure with the function pointer (address), name and weight of the
     function to be executed by the thread. Before executing the callback, each
     thread will make a random sleep. The larger the weight, the longer the
     random sleep. */
  callback_t callback[NUM_OF_THREADS] = {
    {.address = length,
     .name = "length",
     .weight = 25
    },
    {.address = num_of_spaces,
     .name = "num_of_spaces",
     .weight = 20
    },
    {.address = to_uppercase,
     .name = "to_uppercase",
     .weight = 1
    },
    {.address = to_lowercase,
     .name = "to_lowercase",
     .weight = 1
    }
  };

  /* Attributes (stack size, scheduling information) for the threads. */
  pthread_attr_t attr;

  /* Get default attributes for the threads. */
  if (pthread_attr_init(&attr) != 0) {
    perror("pthread_attr_init()");
    exit(EXIT_FAILURE);
  };

  /* Create threads, each executing the generic_start_routine function. */
  for (int i = 0; i < NUM_OF_THREADS; i++) {
    /* Create one data_t structure for each of the threads. */
    arg[i] = (data_t) {
      /* Pointer to string for the thread to operate on. Note, this makes all
         threads operate on the same shared string. */
      .string = string,
      /* Sequential thread number, used to identify threads in status messages. */
      .thread_nr = i,
      /* Each thread must have a unique random seed. */
      .seed = rand(),
      /* The callback the thread will execute. */
      .callback = callback[i]
    };

    /* Create the thread. */
    if ( pthread_create(&tid[i], &attr, generic_start_routine, &arg[i]) != 0) {
      perror("pthread_create()");
      exit(EXIT_FAILURE);
    };
  }

  /* Wait for all threads to terminate. */
  for (int i = 0; i < NUM_OF_THREADS; i++){
    if (pthread_join(tid[i], NULL) != 0) {
      perror("pthread_join()");
      exit(EXIT_FAILURE);
    };

    print_status(&arg[i], " - ", 1);
  }

  exit(EXIT_SUCCESS);
}
