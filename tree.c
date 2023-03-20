#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("[ID = %d] I am the root parent\n", getpid());
    int pid1 = fork();
    if (pid1 == 0) {
        printf("[ID = %d] My parent is [%d]\n", getpid(), getppid());
        int pid3 = fork();
        if (pid3 == 0) {
            printf("[ID = %d] My parent is [%d]\n", getpid(), getppid());
        } else {
            wait(NULL);
        }
    } else {
        int pid2 = fork();
        if (pid2 == 0) {
            printf("[ID = %d] My parent is [%d]\n", getpid(), getppid());
            int pid4 = fork();
            if (pid4 == 0) {
                printf("[ID = %d] My parent is [%d]\n", getpid(), getppid());
            } else {
                wait(NULL);
            }
        } else {
            wait(NULL);
        }
        wait(NULL);
    }
    return 0;
}
