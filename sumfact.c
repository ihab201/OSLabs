#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    
    int N1 =  atoi(argv[1]);

    if (N1 <= 0) {
        fprintf(stderr, "N1 must be a positive integer\n");
        return 1;
    }
    int pid1 = fork();
    if (pid1 < 0) {
        printf("error creating fork1");
        exit(0);
    } else if (pid1 == 0) {
        // First child process: compute sum of integers up to N1
        int sum = 0;
        for (int i = 1; i <= N1; i++) {
            sum += i;
        }
        printf("[ID = %d] Sum of positive integers up to %d is %d\n", getpid(),N1, sum);
        exit(0);
    }
    int pid2 = fork();
    if (pid2 < 0) {
        printf("error creating fork2");
        exit(0);
    } else if (pid2 == 0) {
        int fact = 1;
        for (int i = 1; i <= N1; i++) {
            fact *= i;
        }
        printf("[ID = %d] Factorial of %d is %d\n", getpid(),N1, fact);
        exit(0);
    }
    int status;
    wait(NULL);
    wait(NULL);
    printf("[ID = %d] Done\n", getpid());
    return 0;
}