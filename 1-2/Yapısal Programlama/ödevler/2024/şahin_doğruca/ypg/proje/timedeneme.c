/*******************************************************************************
*
* Program: Countdown Timer
* 
* Description: A countdown timer program using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=dG1HBSArgjM 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <time.h>
#include <pthread.h>


void * ask();
void * countdown();

int main(void)
{ 
  pthread_t thread1;
  pthread_t thread2;


  pthread_create(&thread1, NULL, countdown, NULL);
  pthread_create(&thread2, NULL, ask, NULL);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  return 0;
}



void *ask()
{
  char inp;

  printf("\nbisey gir : \n");
  scanf(" %c", &inp);

  return NULL;
}

void * countdown() {
    // Stores the total number of seconds remaining to countdown
  int seconds = 10;

  // Prompt the user for the total number of seconds to countdown and store
  // the number into the variable seconds


  // Continue the loop so long as there are seconds remaining, the loop 
  // will output the time remaining and pause for a second each time...
  while (seconds > 0)
  {
    printf("\r%04d", seconds);
    fflush(stdout);

    clock_t stop = clock() + CLOCKS_PER_SEC;
    while (clock() < stop) { }
    seconds--;
  } 
  
  // Output time's up when the timer reaches zero
  printf("\rTime's up!\n");

  return NULL;
}