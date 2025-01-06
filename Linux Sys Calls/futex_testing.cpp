#define _GNU_SOURCE
#include <linux/futex.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

/*less expensive way to use mutex in user space without involvement of kernel*/

// Futex helper function
int futex(int *uaddr, int futex_op, int val, const struct timespec *timeout, int *uaddr2, int val3) {
    return syscall(SYS_futex, uaddr, futex_op, val, timeout, uaddr2, val3);
}

int main() {
    int futex_var = 0;

    // Wait until futex_var == 0
    if (futex(&futex_var, FUTEX_WAIT, 0, NULL, NULL, 0) == -1) {
        if (errno != EAGAIN) {
            perror("futex_wait");
            exit(EXIT_FAILURE);
        }
    }

    // Wake up any waiting threads
    futex_var = 1;
    if (futex(&futex_var, FUTEX_WAKE, 1, NULL, NULL, 0) == -1) {
        perror("futex_wake");
        exit(EXIT_FAILURE);
    }

    printf("Futex example completed.\n");
    return 0;
}
