#include <stdio.h>
#include <pthread.h>

#define MAX_THREADS 4

int array[] = {4, 6, 10, 2, 7, 9, 1, 0, 3, 8, 5};
int array_size = sizeof(array) / sizeof(int);
int target = 7;
int found = 0;
int ind = 0;


void* search_array(void* data) {
    int *start = (int*)data;
    int end = *start + (array_size / MAX_THREADS);
    int i;

    for (i = *start; i < end; i++) {
        if (array[i] == target && !found) {
            found = 1;
            ind = i;
        }
    }

    pthread_exit(NULL);
}

int main() {
    int i;
    pthread_t threads[MAX_THREADS];
    int thread_start[MAX_THREADS];

    for (i = 0; i < MAX_THREADS; i++) {
        thread_start[i] = i * (array_size / MAX_THREADS);
        pthread_create(&threads[i], NULL, search_array, &thread_start[i]);
    }

    if (found) {
        printf("Element found at index: %d\n", ind);
    } else {
        printf("Element not found.\n");
    }
    return 0;
}
