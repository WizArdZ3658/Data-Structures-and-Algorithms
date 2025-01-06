#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main() {
    int fd = open("example.txt", O_RDONLY); // Open file for reading
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    off_t move_by_5 = lseek(fd, 5, SEEK_CUR);

    while ((bytesRead = read(fd, buffer, BUFFER_SIZE)) > 0) {
        // Write the data to stdout
        if (write(STDOUT_FILENO, buffer, bytesRead) == -1) {
            perror("write");
            close(fd);
            exit(EXIT_FAILURE);
        }
    }

    if (bytesRead == -1) {
        perror("read");
    }

    printf("\nValue of buffer: %s\n", buffer);

    close(fd);
    return 0;
}
