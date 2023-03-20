#include <stdio.h>

int main() {
    int n, i;
    float avgWaitingTime = 0, avgTurnaroundTime = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int pid[n], burstTime[n], waitingTime[n], turnaroundTime[n];

    for(i = 0; i < n; i++) {
        printf("Enter Process ID: ");
        scanf("%d", &pid[i]);

        printf("Enter CPU Burst Time: ");
        scanf("%d", &burstTime[i]);
    }

    waitingTime[0] = 0;
    turnaroundTime[0] = burstTime[0];
    for(i = 1; i < n; i++) {
        waitingTime[i] = 0;
        for(int j = 0; j < i; j++) {
            waitingTime[i] += burstTime[j];
        }
        turnaroundTime[i] = waitingTime[i] + burstTime[i];
    }

    
    for(i = 0; i < n; i++) {
        avgWaitingTime += waitingTime[i];
        avgTurnaroundTime += turnaroundTime[i];
    }
    avgWaitingTime /= n;
    avgTurnaroundTime /= n;

    
    printf("\nGantt Chart:\n");
    for(i = 1; i <= n; i++) {
        printf(" | \tP%d\t ", i);
    }

    printf("|\n");

    for(i = 0; i <n; i++) {
        printf(" %d\t\t", waitingTime[i]);
    }
    printf(" %d\n", turnaroundTime[i-1]);

    printf("\nProcess\t Burst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("%d\t   %d\t\t %d\t\t %d\n", pid[i], burstTime[i], waitingTime[i], turnaroundTime[i]);
    }
    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);

    return 0;
}