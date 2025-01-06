#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
    int fd = open("example.txt", O_RDWR);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Move the file offset to 10 bytes from the beginning
    off_t move_by_10 = lseek(fd, 10, SEEK_CUR);
    // cout << (long long)move_by_10 << '\n';
    printf("Current file offset: %lld\n", (long long)move_by_10);
    if (move_by_10 == -1) {
        perror("lseek");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Write at the new offset
    off_t move_by_5 = write(fd, "Hello", 5);
    // cout << (long long)move_by_5 << '\n';
    // printf("Current file offset: %lld\n", (long long)move_by_5);
    if (move_by_5 == -1) {
        perror("write");
        close(fd);
        exit(EXIT_FAILURE);
    }

    close(fd);
    return 0;
}
