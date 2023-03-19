#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_LINE 80

#define FIFO1 "/tmp/fifo.1"
#define FIFO2 "/tmp/fifo.2"
#define FIFO_MODE (S_IRWXU | S_IRWXG | S_IRWXO)

void server(int, int );

int main (int argc, char *argv[])  {

	int readfd, writefd;

	if((mkfifo(FIFO1, FIFO_MODE )<0)&&(errno != EEXIST))  {
		printf("can not open %s\n",FIFO1);
		exit(-1);
	}

	if((mkfifo(FIFO2, FIFO_MODE )<0)&&(errno!= EEXIST))  {
		printf("can not open %s\n",FIFO2);
		exit(-1);
	}

	readfd  = open(FIFO1, O_RDONLY);
	writefd = open(FIFO2, O_WRONLY);

	server(readfd, writefd);

	exit(0);
}

void server(int readfd, int writefd)  {

	int fd;
	size_t n;
	char buff[MAX_LINE+1];

	//read path from IPC channel
	if((n = read(readfd, buff, MAX_LINE)) == 0)  {
		write(writefd, "EOF while reading path...\n", 26);
		exit(0);
	}
	buff[n] = '\0';
	printf("received file name (%s)\n", buff);

	if((fd=open(buff, O_RDONLY))<0)  {

		snprintf(buff+n, sizeof(buff)-n, ": can't open, %s\n", strerror(errno));
		n = strlen(buff);
		write(writefd, buff, n);
	} else  {
		printf("sending contents of the file back to client...\n");
		while((n=read(fd, buff, MAX_LINE))>0)
			write(writefd, buff, n);
		close(fd);
	}
}

