#include<stdio.h>

struct process {
    int pid;        // process ID
    int burst_time; // burst time of process
    int remaining_time; // remaining time of process
    int arrival_time; // arrival time of process
    int completion_time; // completion time of process
    int waiting_time; // waiting time of process
    int turnaround_time; // turnaround time of process
};

int main() {
    int n, quantum, total_time = 0, i, j;
    float avg_waiting_time = 0, avg_turnaround_time = 0;

    // accept the number of processes and time slice
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter time slice: ");
    scanf("%d", &quantum);

    struct process p[n];

    // accept the burst time for each process
    for(i = 0; i < n; i++) {
        printf("Enter the burst time for process %d: ", i+1);
        scanf("%d", &p[i].burst_time);
        p[i].remaining_time = p[i].burst_time;
        p[i].pid = i+1;
    }

    // calculate the number of time slices required for each process
    for(i = 0; i < n; i++) {
        if(p[i].burst_time % quantum == 0)
            p[i].completion_time = p[i].burst_time / quantum;
        else
            p[i].completion_time = (p[i].burst_time / quantum) + 1;
    }

    // perform Round Robin scheduling
    int time = 0, flag = 0;
    printf("\nGantt Chart\n");
    printf("0");
    while(1) {
        flag = 0;
        for(i = 0; i < n; i++) {
            if(p[i].remaining_time > 0) {
                flag = 1;
                if(p[i].remaining_time > quantum) {
                    printf(" | P%d | %d ", p[i].pid, time + quantum);
                    time += quantum;
                    p[i].remaining_time -= quantum;
                }
                else {
                    printf(" | P%d | %d ", p[i].pid, time + p[i].remaining_time);
                    time += p[i].remaining_time;
                    p[i].completion_time = time;
                    p[i].remaining_time = 0;
                }
            }
        }
        if(flag == 0)
            break;
    }
    printf("\n");

    // calculate waiting time and turnaround time
    for(i = 0; i < n; i++) {
        p[i].turnaround_time = p[i].completion_time - p[i].burst_time;
        p[i].waiting_time = p[i].turnaround_time - (p[i].completion_time - p[i].arrival_time);
        avg_waiting_time += p[i].waiting_time;
        avg_turnaround_time += p[i].turnaround_time;
    }

    // calculate the average waiting time and turnaround time
    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    // print the total waiting time, turnaround time, and average waiting time and turnaround time
    printf("\nProcess\t\tBurst Time\tCompletion Time\t\tTurnaround Time\t\tWaiting Time\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n", p[i].pid, p[i].burst_time, p[i].completion_time, p[i].turnaround_time, p[i].waiting_time);
}
printf("\nTotal Waiting Time = %.2f\n", avg_waiting_time);
printf("Total Turnaround Time = %.2f\n", avg_turnaround_time);
