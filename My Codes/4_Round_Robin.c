#include <stdio.h>

struct process
{
    int pid, bt, tt, wt;
};

int main()
{
    struct process x[10], p[30];
    int i, j, k, tot = 0, m, n;
    float wttime = 0.0, tottime = 0.0, a1, a2;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input burst time for each process
    for (i = 1; i <= n; i++)
    {
        x[i].pid = i;

        printf("Enter the burst time for process %d: ", i);
        scanf("%d", &x[i].bt);

        tot += x[i].bt;
    }

    printf("Total Burst Time: %d\n", tot);

    p[0].tt = 0;
    k = 1;

    printf("Enter the time slice: ");
    scanf("%d", &m);

    // Round Robin Scheduling algorithm
    for (j = 1; j <= tot; j++)
    {
        for (i = 1; i <= n; i++)
        {
            if (x[i].bt != 0)
            {
                p[k].pid = i;

                if (x[i].bt - m < 0)
                {
                    // Process completed
                    p[k].wt = p[k - 1].tt;
                    p[k].bt = x[i].bt;
                    p[k].tt = p[k].wt + x[i].bt;
                    x[i].bt = 0;
                    k++;
                }
                else
                {
                    // Time slice expired, but process still needs more time
                    p[k].wt = p[k - 1].tt;
                    p[k].tt = p[k].wt + m;
                    x[i].bt -= m;
                    k++;
                }
            }
        }
    }

    // Output the waiting time and turnaround time for each process
    printf("\nProcess id\tWaiting Time\tTurnaround Time\n");
    for (i = 1; i < k; i++)
    {
        printf("%d\t\t%d\t\t%d\n", p[i].pid, p[i].wt, p[i].tt);
        wttime += p[i].wt;
        tottime += p[i].tt;
    }

    // Calculate and output the average waiting time and average turnaround time
    a1 = wttime / n;
    a2 = tottime / n;

    printf("\nAverage Waiting Time: %f\n", a1);
    printf("Average Turnaround Time: %f\n", a2);

    return 0;
}
/*
Enter the number of processes: 3
Enter the burst time for process 1: 7
Enter the burst time for process 2: 4
Enter the burst time for process 3: 9
Total Burst Time: 20
Enter the time slice: 3

Process id  Waiting Time    Turnaround Time
1           0               10
2           10              17
3           17              26

Average Waiting Time: 9.000000
Average Turnaround Time: 17.666666


*/