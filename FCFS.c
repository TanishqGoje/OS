#include <stdio.h>

int main()
{
    int i, n, bt[10], wt[10], tt[10]; // i: loop index, n: number of processes, bt: burst times, wt: waiting times, tt: turnaround times
    int w1 = 0, t1 = 0;               // w1: total waiting time, t1: total turnaround time
    float aw, at;                     // aw: average waiting time, at: average turnaround time

    printf("Enter number of processes:\n");
    scanf("%d", &n); // Input number of processes

    printf("Enter the burst time of the processes:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]); // Input burst time for each process
    }

    wt[0] = 0;     // First process has zero waiting time
    tt[0] = bt[0]; // Turnaround time for first process is its burst time
    w1 = wt[0];    // Initialize total waiting time
    t1 = tt[0];    // Initialize total turnaround time

    // Calculate waiting time and turnaround time for each process
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1]; // Waiting time: sum of burst times of previous processes
        tt[i] = tt[i - 1] + bt[i];     // Turnaround time: previous turnaround + current burst time
        w1 += wt[i];                   // Accumulate total waiting time
        t1 += tt[i];                   // Accumulate total turnaround time
    }

    aw = (float)w1 / n; // Calculate average waiting time
    at = (float)t1 / n; // Calculate average turnaround time

    printf("\nProcess\tBT\tWT\tTT\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\n", i, bt[i], wt[i], tt[i]); // Print process info
    }
    printf("Average Waiting Time = %.2f\n", aw);    // Print average waiting time
    printf("Average Turnaround Time = %.2f\n", at); // Print average turnaround time

    return 0;
}
