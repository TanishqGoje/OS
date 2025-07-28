#include <stdio.h>
void main()
{
   int p[20], bt[20], wt[20], tat[20], at[20], ct[20], i, j, n, temp;
   float wtavg = 0, tatavg = 0;
   printf("\nEnter the number of process: ");
   scanf("%d", &n);
   for (i = 0; i < n; i++)
   {
      p[i] = i;
      printf("\nEnter the burst time for process %d: ", i);
      scanf("%d", &bt[i]);
   }
   for (i = 0; i < n; i++)
   {
      printf("\nEnter the arrival time for process %d: ", i);
      scanf("%d", &at[i]);
   }
   for (i = 0; i < n; i++)
   {
      for (j = i + 1; j < n; j++)
      {
         if (bt[i] > bt[j])
         {
            temp = bt[i];
            bt[i] = bt[j];
            bt[j] = temp;
            temp = p[i];
            p[i] = p[j];
            p[j] = temp;
         }
      }
   }
   wt[0] = 0;
   tat[0] = bt[0];
   ct[0] = at[0] + bt[0];
   for (i = 1; i < n; i++)
   {
      ct[i] = ct[i - 1] + bt[i];
   }
   for (i = 1; i <= n; i++)
   {
      tat[i] = ct[i] - at[i];
      wt[i] = tat[i] - bt[i];
   }
   for (i = 0; i < n; i++)
   {
      wtavg = wtavg + wt[i];
      tatavg = tatavg + tat[i];
   }
   printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time\n");
   for (i = 0; i < n; i++)
      printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
   printf("\nAverage Waiting Time %f", wtavg / n);
   printf("\nAverage Turn Around Time %f", tatavg / n);
}