#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Create a FIFO (named pipe)
    mkfifo("myfifo", 0666);

    // Open the FIFO for reading
    int fd = open("myfifo", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Read the number from the FIFO
    int num;
    read(fd, &num, sizeof(int));

    // Calculate the square
    int square = num * num;

    // Print the result
    printf("Square of %d is %d\n", num, square);

    // Close the FIFO
    close(fd);

    // Remove the FIFO
    unlink("myfifo");

    return 0;
}

