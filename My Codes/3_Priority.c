#include<stdio.h>

struct process {
    int pid;
    int bt;
    int wt;
    int tt;
    int prior;
} p[10], temp;

int main() {
    int i, j, n, totwt, tottt, arg1, arg2;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        p[i].pid = i;

        printf("Enter the burst time: ");
        scanf("%d", &p[i].bt);

        printf("Enter the priority: ");
        scanf("%d", &p[i].prior);
    }

    for (i = 1; i < n; i++) {
        for (j = i + 1; j <= n; j++) {
            if (p[i].prior > p[j].prior) {
                // Swapping process attributes
                temp.pid = p[i].pid;
                p[i].pid = p[j].pid;
                p[j].pid = temp.pid;

                temp.bt = p[i].bt;
                p[i].bt = p[j].bt;
                p[j].bt = temp.bt;

                temp.prior = p[i].prior;
                p[i].prior = p[j].prior;
                p[j].prior = temp.prior;
            }
        }
    }

    p[1].wt = 0;
    p[1].tt = p[1].bt + p[1].wt;
    i = 2;
    while (i <= n) {
        p[i].wt = p[i - 1].bt + p[i - 1].wt;
        p[i].tt = p[i].bt + p[i].wt;
        i++;
    }

    totwt = tottt = 0;

    printf("\nProcess ID \tBT \tWT \tTT");
    i = 1;
    while (i <= n) {
        printf("\n%d\t\t%d\t%d\t%d", p[i].pid, p[i].bt, p[i].wt, p[i].tt);
        totwt += p[i].wt;
        tottt += p[i].tt;
        i++;
    }

    arg1 = totwt / n;
    arg2 = tottt / n;

    printf("\narg1 = %d\targ2 = %d\n", arg1, arg2);

    return 0;
}

/*
Enter the number of processes: 3
Enter the burst time for process 1: 5
Enter the priority for process 1: 2
Enter the burst time for process 2: 3
Enter the priority for process 2: 1
Enter the burst time for process 3: 4
Enter the priority for process 3: 3

Process ID   BT   WT   TT
1            5    0    5
2            3    5    8
3            4    8    12

arg1 = 4   arg2 = 8


*/