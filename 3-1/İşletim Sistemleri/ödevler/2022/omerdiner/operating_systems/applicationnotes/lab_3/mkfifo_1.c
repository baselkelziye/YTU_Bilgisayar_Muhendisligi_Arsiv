#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Create a FIFO (named pipe)
    mkfifo("myfifo", 0666);

    // Open the FIFO for writing
    int fd = open("myfifo", O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Get input from the user
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    // Write the number to the FIFO
    write(fd, &num, sizeof(int));

    // Close the FIFO
    close(fd);

    return 0;
}

