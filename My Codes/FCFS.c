#include <stdio.h>

struct process
{
    int pid;
    int bt;
    int wt, tt;
} p[10];

int main()
{
    int i, n, totwt = 0, tottt = 0, avg1, avg2;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    for (i = 1; i <= n; i++)
    {
        p[i].pid = i;
        printf("Enter the burst time for process %d: ", i);
        scanf("%d", &p[i].bt);
    }

    p[1].wt = 0;
    p[1].tt = p[1].bt + p[1].wt;

    // Fixing the while loop conditions
    for (i = 2; i <= n; i++)
    {
        p[i].wt = p[i - 1].bt + p[i - 1].wt;
        p[i].tt = p[i].bt + p[i].wt;
    }

    printf("\nProcess ID \tBurst Time \tWaiting Time \tTurnaround Time\n");
    
    for (i = 1; i <= n; i++)
    {
        printf("\n\t%d \t\t%d \t\t%d \t\t%d", p[i].pid, p[i].bt, p[i].wt, p[i].tt);
        totwt += p[i].wt; // Accumulating waiting time
        tottt += p[i].tt; // Accumulating turnaround time
    }
    
    avg1 = totwt / n;
    avg2 = tottt / n;
    
    printf("\n\nAverage Waiting Time: %d \t Average Turnaround Time: %d\n", avg1, avg2);
    
    return 0;
}



/*
Enter the number of processes: 3
Enter the burst time for process 1: 10
Enter the burst time for process 2: 5
Enter the burst time for process 3: 8

Process ID   Burst Time   Waiting Time   Turnaround Time

    1           10             0             10
    2           5              10            15
    3           8              15            23

Average Waiting Time: 8    Average Turnaround Time: 16



*/