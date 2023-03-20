#include <pthread.h> //thread library
#include<stdlib.h>
#include<stdio.h>
#include <unistd.h> //for sleep() function

#define NKIDS 50 
#define NLOOPS 100000

int tot_items = 0 ; //global variable.

struct kidrec {
    int data ;
    pthread_t id ;
};

void *kidfunc(void *p)
{
    int *ip = (int *)p;
    int tmp, n;
    tmp = tot_items;
    for (n=0; n< NLOOPS; ++n) tot_items = tmp + *ip;
    pthread_exit(NULL);
} 

int main (){
    struct kidrec kids[NKIDS];
    int m ;
    for (m=0; m<NKIDS; ++m)
    {
        // printf("\nvalue of m: %d", m);
        kids[m].data = m+1 ;
        pthread_create (&kids[m].id, NULL, kidfunc, &kids[m].data);
        //pthread_join (kids[m].id, NULL) ;
    }
    for (m=0; m< NKIDS; ++m) pthread_join (kids[m].id, NULL);
    printf ("End of Program. Grand Total = %d\n", tot_items);
    pthread_exit(NULL);
}