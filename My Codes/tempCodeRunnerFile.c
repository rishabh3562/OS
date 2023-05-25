#include <stdio.h>

struct process
{
    int pid;
    int bt;
    int wt;
    int tt;
} p[10], temp;

int main()
{
    int i, j, n, totwt = 0, tottt = 0;
    float avg1, avg2;

    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        p[i].pid = i;
        printf("Enter the burst time for process %d: ", i);
        scanf("%d", &p[i].bt);
    }

    // Sorting the processes based on burst time using bubble sort
    for (i = 1; i < n; i++)
    {
        for (j = i + 1; j <= n; j++)
        {
            if (p[i].bt > p[j].bt)
            {
                // Swapping process IDs and burst times
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    p[1].wt = 0;
    p[1].tt = p[1].bt + p[1].wt;

    // Calculating waiting time and turnaround time
    for (i = 2; i <= n; i++)
    {
        p[i].wt = p[i - 1].bt + p[i - 1].wt;
        p[i].tt = p[i].bt + p[i].wt;
    }

    printf("\nProcess ID \tBurst Time \tWaiting Time \tTurnaround Time\n");

    for (i = 1; i <= n; i++)
    {
        printf("\n\t%d \t\t%d \t\t%d \t\t%d", p[i].pid, p[i].bt, p[i].wt, p[i].tt);
        totwt += p[i].wt;
        tottt += p[i].tt;
    }

    avg1 = (float)totwt / n;
    avg2 = (float)tottt / n;

    printf("\n\nAverage Waiting Time: %.2f \tAverage Turnaround Time: %.2f\n", avg1, avg2);

    return 0;
}
