#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
    int ret;
    ret = fork();
    
    if (ret == 0) execl("fork4", "fork4", NULL);
    else {
        wait(NULL);
        printf("Only the parent gets here\n");
    }

    return 0;
}