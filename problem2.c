#include <pthread.h>
#include<stdlib.h>
#include<stdio.h>

void *print_even_numbers(void *arg) {
    int *n = (int*) arg;
    for (int i = 2; i <= *n; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
    pthread_exit(NULL);
}

void *print_odd_numbers(void *arg) {
    int *n = (int*) arg;
    for (int i = 1; i <= *n; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    pthread_t tid_even, tid_odd; // thread IDs
    int rc; // return code

    if (argc < 2){
        printf("Please add the number of threads to the command line\n");
        exit(1);
    }
    int n = atoi(argv[1]); 


    
    rc = pthread_create(&tid_even, NULL, print_even_numbers, &n); //for even.
    if (rc) {
        printf("Error creating even thread\n");
        exit(1);
    }

    
    rc = pthread_create(&tid_odd, NULL, print_odd_numbers, &n); //for odd.
    if (rc) {
        printf("Error creating odd thread\n");
        exit(1);
    }

    pthread_join(tid_even, NULL);
    pthread_join(tid_odd, NULL);

    pthread_exit(NULL);

    return 0;
}


