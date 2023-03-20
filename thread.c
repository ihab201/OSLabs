#include <pthread.h> //thread library
#include<stdlib.h>
#include<stdio.h>
#include <unistd.h> //for sleep() function

void *printHello(void* data){
    pthread_t tid = (pthread_t)data; //modifying from int to pthread_t

    //sleep(1); //for activity 3: adding sleep(1);
    printf("\n Hello from new thread %u - got %u !\n", pthread_self(), tid);
    pthread_exit(NULL);
}

int main()
{
    int rc;
    pthread_t thread_id;
    pthread_t tid;  // adding pid
    tid = pthread_self();

    int t = 11;

    rc = pthread_create(&thread_id,NULL, printHello,(void *) tid);
    if(rc){
        printf("\n ERROR: return code from pthread_create is %d \n", rc);
        exit(1);
    }
    pthread_join(thread_id, NULL); /*activity 4: wait for thread tid, this line of code changed from main to thread function to see the difference*/ 
    sleep(1);
    printf("\nI am thread %u. Created new thread (%u)... \n", tid,thread_id);
    //activity 3: commenting last line of code pthread_exit(NULL)...
    pthread_exit(NULL);
    return 0;
}
