#include <stdio.h>
#include <unistd.h>

void fork3(){
    int pid;
    pid = fork();
    
    if (pid == 0)
        printf("[%d] Hello from child\n", getpid());
    else
        printf("[%d] Hello from parent\n",  getpid());
}

int main(void){
    fork3();
    return 0;
}