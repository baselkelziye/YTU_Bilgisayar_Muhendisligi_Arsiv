/*
cd /Users/zeyneb/Desktop/DERSLER/BLM2031_YapisalProg_20191/hafta11_codes
cc hafta11_ex4.c -o test -lpthread
*/

#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[2];
int ret1,ret2;

void* doSomeThing(void *arg)
{
    unsigned long i = 0;
    pthread_t id = pthread_self();

    for(i=0; i<(0xFFFFFFFF);i++);

    if(pthread_equal(id,tid[0]))
    {
        printf("\n First thread processing done\n");
        ret1  = 100;
        pthread_exit(&ret1);
    }
    else
    {
        printf("\n Second thread processing done\n");
        ret2  = 200;
        pthread_exit(&ret2);
    }

    return NULL;
}

int main(void)
{
    int i = 0;  
    int err;
    int *ptr[2];

    while(i < 2)
    {
        err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        else
            printf("\n Thread created successfully\n");

        i++;
    }

    pthread_join(tid[0], (void**)&(ptr[0]));
    pthread_join(tid[1], (void**)&(ptr[1]));

    printf("\n return value from first thread is %d\n", *ptr[0]);
    printf("\n return value from second thread is %d\n", *ptr[1]);

    return 0;
}
