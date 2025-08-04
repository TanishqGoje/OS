#include <stdio.h>

int main()
{
    int n, i, j, p[20], temp, time = 0, smallest, count = 0;
    int at[10], bt[10], prio[10], ct[10], tat[10], wt[10], bt_left[10], completed[10], wtavg = 0, tatavg = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        p[i] = i;
        printf("enter the burst time and priority of process %d.	", i);
        scanf("%d%d", &bt[i], &prio[i]);
    }
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (prio[i] > prio[j])
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                temp = prio[i];
                prio[i] = prio[j];
                prio[j] = temp;
            }
    wtavg = wt[0] = 0;
    tatavg = tat[0] = bt[0];
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = tat[i - 1] + bt[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }
    printf("\n PROCESS\t PRIORITY\t BURST TIME\t WAITING TIME\t TURN AROUND TIME\n");
    for (i = 0; i < n; i++)
        printf("\n %d\t\t%d\t\t%d\t\t%d\t\t%d", p[i], prio[i], bt[i], wt[i], tat[i]);
    printf("\n avg waiting time is.	%f", wtavg / n);
    printf("\n avg turn around time is.	%f", tatavg / n);
}