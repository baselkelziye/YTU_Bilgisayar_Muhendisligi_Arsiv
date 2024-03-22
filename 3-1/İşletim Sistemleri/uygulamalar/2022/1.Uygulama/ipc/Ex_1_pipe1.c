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

void client(int, int );
void server(int, int );

int main (int argc, char *argv[])  {

	int pipe1[2], pipe2[2];
	pid_t childpid;

	pipe(pipe1);
	pipe(pipe2);

	if((childpid=fork())==0)  {// Child
		close(pipe1[1]);
		close(pipe2[0]);
		server(pipe1[0], pipe2[1]);
		exit(0);
	}

	close(pipe1[0]);
	close(pipe2[1]);

	client(pipe2[0], pipe1[1]);

	waitpid(childpid, NULL,0); // wait for child to terminate
	exit(0);
}

void client (int readfd, int writefd ) {

	size_t len;
	size_t n;
	char buff[MAX_LINE];

	fgets(buff, MAX_LINE, stdin);
	len = strlen(buff);
	if(buff[len-1]=='\n')
		len--;
	write(writefd, buff, len);

	while((n =read(readfd, buff, MAX_LINE))>0)
		write(STDOUT_FILENO, buff, n);
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
	if((fd=open(buff, O_RDONLY))<0)  {

		snprintf(buff+n, sizeof(buff)-n, ": can't open, %s\n", strerror(errno));
		n = strlen(buff);
		write(writefd, buff, n);
	} else  {
		while((n=read(fd, buff, MAX_LINE))>0)
			write(writefd, buff, n);
		close(fd);
	}
}

