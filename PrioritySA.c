#include <stdio.h>
#include <stdlib.h>

//Defining the process
typedef struct process{
    int priority;
    int pid;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
} Process;


int main(int argc, char const *argv[])
{
    int n, i, j;
    float avgWaitingTime = 0, avgTurnaroundTime = 0;

    printf("Enter the number of process: ");
    scanf("%d", &n);

    Process *processes = (Process *) malloc(n * sizeof(Process));

    for (i = 0; i < n; i++) {
        printf("Enter process %d ID: ", i + 1);
        scanf("%d", &processes[i].pid);
        printf("Enter process %d priority: ", i + 1);
        scanf("%d", &processes[i].priority);
        printf("Enter process %d CPU burst time: ", i + 1);
        scanf("%d", &processes[i].burstTime);
    }

    //Swap for sorting according to priority.
    for(i = 0; i< n-1; i++){
        // printf("Process[%d]: %d", i, processes[i].priority);
        for(j = i+1; j < n; j++){
            if(processes[i].priority > processes[j].priority){
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
            // printf("Process[%d]: %d", i, processes[i].priority);
        }
        printf("\n");
    }
    // printf("TEST ENDS\n");

    // Waiting and turnaround time:
    processes[0].waitingTime = 0;
    processes[0].turnaroundTime = processes[0].burstTime;
    for (i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i-1].waitingTime + processes[i-1].burstTime;
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
    }

    for (i = 0; i < n; i++) {
        avgWaitingTime += processes[i].waitingTime;
        avgTurnaroundTime += processes[i].turnaroundTime;
    }
    avgWaitingTime /= n;
    avgTurnaroundTime /= n;

    // print Gantt chart...
    printf("\nGantt Chart:\n");
    for(i = 0; i < n; i++) {
        printf(" | \tP%d\t ", processes[i].pid);
    }

    printf("|\n");

    for(i = 0; i <n; i++) {
        printf(" %d\t\t", processes[i].waitingTime);
    }
    printf(" %d\n", processes[i-1].turnaroundTime);

    //Print the data table...
    printf("\nProcess\t Burst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("%d\t   %d\t\t %d\t\t %d\n", processes[i].pid, processes[i].burstTime, processes[i].waitingTime, processes[i].turnaroundTime);
    }
    
    printf("\n");
    printf("Average Waiting Time: %0.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %0.2f\n", avgTurnaroundTime);

    // delete process C++ -->in C.... 
    free(processes);

    return 0;
}
