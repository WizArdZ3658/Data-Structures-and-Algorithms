#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main() {
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    off_t offset = 0; // Start reading from the 10th byte
    ssize_t bytesRead;

    off_t move_by_6 = lseek(fd, 6, SEEK_CUR);

    bytesRead = pread(fd, buffer, BUFFER_SIZE, offset);
    if (bytesRead == -1) {
        perror("pread");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Write the read data to stdout
    if (write(STDOUT_FILENO, buffer, bytesRead) == -1) {
        perror("write");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("\nValue of buffer: %s\n", buffer);

    close(fd);
    return 0;
}
