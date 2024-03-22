#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>

#define SHMOBJ_PATH         "/foo1423"
#define MAX_MSG_LENGTH      50
#define TYPES               8

struct msg_s {
    int type;
    char content[MAX_MSG_LENGTH];
};

int main(int argc, char *argv[]) {
    int shmfd;
    int shared_seg_size = (1 * sizeof(struct msg_s));   /* want shared segment capable of storing 1 message */
    struct msg_s *shared_msg;      /* the shared segment, and head of the messages list */
    
    /* creating the shared memory object    --  shm_open()  */
    shmfd = shm_open(SHMOBJ_PATH, O_CREAT | O_EXCL | O_RDWR, S_IRWXU | S_IRWXG);
    if (shmfd < 0) {
        perror("In shm_open()");
        exit(1);
    }
    fprintf(stderr, "Created shared memory object %s\n", SHMOBJ_PATH);
    
    /* adjusting mapped file size (make room for the whole segment to map)      --  ftruncate() */
    ftruncate(shmfd, shared_seg_size);

    /* requesting the shared segment    --  mmap() */    
    shared_msg = (struct msg_s *)mmap(NULL, shared_seg_size, PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
    if (shared_msg == NULL) {
        perror("In mmap()");
        exit(1);
    }
    fprintf(stderr, "Shared memory segment allocated correctly (%d bytes).\n", shared_seg_size);
    
    srandom(time(NULL));
    /* producing a message on the shared segment */
    shared_msg->type = random() % TYPES;
    snprintf(shared_msg->content, MAX_MSG_LENGTH, "My message, type %d, num %ld", shared_msg->type, random());
   
    /* [uncomment if you wish] requesting the removal of the shm object     --  shm_unlink() */
/*
    if (shm_unlink(SHMOBJ_PATH) != 0) {
        perror("In shm_unlink()");
        exit(1);
    }
*/
    return 0;
}
