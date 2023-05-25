#include <stdio.h>

// Structure to represent a process
typedef struct {
    int processID;
    int burstTime;
    int priority;
} Process;

// Function to perform First-Come, First-Served (FCFS) scheduling
void performFCFS(Process processes[], int n, int waitingTime[], int turnaroundTime[]) {
    waitingTime[0] = 0;
    turnaroundTime[0] = processes[0].burstTime;
    
    for (int i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i - 1] + processes[i - 1].burstTime;
        turnaroundTime[i] = waitingTime[i] + processes[i].burstTime;
    }
}

// Function to perform Shortest Job First (SJF) scheduling
void performSJF(Process processes[], int n, int waitingTime[], int turnaroundTime[]) {
    // Sort the processes based on burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burstTime > processes[j + 1].burstTime) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
    
    waitingTime[0] = 0;
    turnaroundTime[0] = processes[0].burstTime;
    
    for (int i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i - 1] + processes[i - 1].burstTime;
        turnaroundTime[i] = waitingTime[i] + processes[i].burstTime;
    }
}

// Function to perform Priority Scheduling
void performPriority(Process processes[], int n, int waitingTime[], int turnaroundTime[]) {
    // Sort the processes based on priority
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
    
    waitingTime[0] = 0;
    turnaroundTime[0] = processes[0].burstTime;
    
    for (int i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i - 1] + processes[i - 1].burstTime;
        turnaroundTime[i] = waitingTime[i] + processes[i].burstTime;
    }
}

// Function to generate the comparison table
void generateComparisonTable(Process processes[], int n) {
    int waitingTime[n][3];      // Array to store waiting time for each process and scheduling algorithm
    int turnaroundTime[n][3];   // Array to store turnaround time for each process and scheduling algorithm
    
    performFCFS(processes, n, waitingTime[0], turnaroundTime[0]);
    performSJF(processes, n, waitingTime[1], turnaroundTime[1]);
    performPriority(processes, n, waitingTime[2], turnaroundTime[2]);
    
    printf("\n-- CPU Scheduling Comparison Table --\n");
    printf("Process ID\tFCFS\t\tSJF\t\tPriority\n");
    
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d/%d\t\t%d/%d\t\t%d/%d\n", processes[i].processID, waitingTime[0][i], turnaroundTime[0][i],
               waitingTime[1][i], turnaroundTime[1][i], waitingTime[2][i], turnaroundTime[2][i]);
    }
}

int main() {
    int n;
    printf("Enter the total number of processes: ");
    scanf("%d", &n);
    
    Process processes[n];
    
    for (int i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
        printf("Enter Process ID: ");
        scanf("%d", &processes[i].processID);
        printf("Enter Burst Time: ");
        scanf("%d", &processes[i].burstTime);
        printf("Enter Priority: ");
        scanf("%d", &processes[i].priority);
    }
    
    generateComparisonTable(processes, n);
    
    return 0;
}

/*

Enter the total number of processes: 4

Process 1
Enter Process ID: 1
Enter Burst Time: 8
Enter Priority: 2

Process 2
Enter Process ID: 2
Enter Burst Time: 6
Enter Priority: 1

Process 3
Enter Process ID: 3
Enter Burst Time: 10
Enter Priority: 3

Process 4
Enter Process ID: 4
Enter Burst Time: 4
Enter Priority: 2

-- CPU Scheduling Comparison Table --
Process ID  FCFS        SJF         Priority
1           0/8         0/8         0/8
2           8/14        8/14        8/14
3           14/24       14/24       14/24
4           24/28       24/28       24/28


comparison table showing the waiting time and turnaround time for each process and each scheduling algorithm


*/
