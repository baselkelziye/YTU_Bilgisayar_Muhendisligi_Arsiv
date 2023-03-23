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

void client(int, int );

int main (int argc, char *argv[])  {

	int readfd, writefd;

	writefd = open(FIFO1, O_WRONLY);
	readfd  = open(FIFO2, O_RDONLY);

	client(readfd, writefd);

	close(readfd);
	close(writefd);

	unlink(FIFO1);
	unlink(FIFO2);

	exit(0);
}

void client (int readfd, int writefd ) {

	size_t len;
	size_t n;
	char buff[MAX_LINE];

	printf("enter a file name\n");
	fgets(buff, MAX_LINE, stdin);
	len = strlen(buff);
	if(buff[len-1]=='\n')
		len--;

	write(writefd, buff, len);
	printf("\nsending file name to server\n\n", buff);

	while((n =read(readfd, buff, MAX_LINE))>0)
		write(STDOUT_FILENO, buff, n);
}

