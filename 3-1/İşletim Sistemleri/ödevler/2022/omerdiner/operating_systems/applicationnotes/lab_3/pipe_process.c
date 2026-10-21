// C program to demonstrate use of fork() and pipe()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	// We use two pipes
	// First pipe to send input string from parent
	// Second pipe to send concatenated string from child

	int fd1[2]; // Used to store two ends of first pipe
	int fd2[2]; // Used to store two ends of second pipe

	
	pid_t p;

	if (pipe(fd1) == -1) {
		fprintf(stderr, "Pipe Failed");
		return 1;
	}
	if (pipe(fd2) == -1) {
		fprintf(stderr, "Pipe Failed");
		return 1;
	}

	
	p = fork();

	if (p < 0) {
		fprintf(stderr, "fork Failed");
		return 1;
	}

	// Parent process
	else if (p > 0) {
		printf("Enter a number: ");
        	int number;
        	scanf("%d", &number);
		int square;
		// Write input string and close writing end of first
		// pipe.
		
		close(fd1[0]);
		write(fd1[1], &number, sizeof(int));
		close(fd1[1]);

		// Wait for child to send a string
		wait(NULL);
		close(fd2[1]); // Close writing end of second pipe

		// Read string from child, print it and close
		// reading end.
		read(fd2[0], &square, sizeof(int));
		
		close(fd2[0]);
	}

	// child process
	else {
		close(fd1[1]); // Close writing end of first pipe
		int number;
		// Read a string using first pipe
		
		read(fd1[0], &number, sizeof(int));

		// Concatenate a fixed string with it
		number=number*number;

		// Close both reading ends
		close(fd1[0]);
		close(fd2[0]);

		// Write concatenated string and close writing end
		write(fd2[1], &number, sizeof(int));
		close(fd2[1]);

		exit(0);
	}
	return 0;
}

