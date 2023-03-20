#include <pthread.h> //thread library
#include<stdlib.h>
#include<stdio.h>
#include <unistd.h> //for sleep() function

#define MAX_THREADS 50

pthread_t thread_id[MAX_THREADS];

void* PrintHello(void* data){
    printf("\nHello from thread %u - I was created in iteration %d !", pthread_self(), (int)data);
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    int rc; 
    if (argc < 2){
        printf("Please add the number of threads to the command line\n");
        exit(1);
    }

    int n = atoi(argv[1]);
    if (n > MAX_THREADS) n = MAX_THREADS;

    for(int i = 0; i< n; i++){
        rc = pthread_create(&thread_id[i], NULL, PrintHello, (void*) i);
        if(rc < 0){
            printf("\n ERROR: return code from pthread_create is %d \n", rc);
            exit(1);
        }
        printf("\n I am thread %u. Created new thread (%u) in iteration %d ...\n", (int)pthread_self(), (int)thread_id[i], i);
        //if(i%5 == 0) sleep(1);
    }

    pthread_exit(NULL);
    return 0;
}
