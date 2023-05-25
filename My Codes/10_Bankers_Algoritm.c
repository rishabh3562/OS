#include <stdio.h>

int main() {
    int processes, resources, i, j, k;

    printf("Enter the number of processes: ");
    scanf("%d", &processes);

    printf("Enter the number of resources: ");
    scanf("%d", &resources);

    int allocation[processes][resources];
    int max[processes][resources];
    int available[resources];
    int need[processes][resources];
    int finish[processes];
    int safeSequence[processes];
    int work[resources];

    // Input allocation matrix
    printf("\nEnter the allocation matrix:\n");
    for (i = 0; i < processes; i++) {
        printf("Process %d: ", i + 1);
        for (j = 0; j < resources; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    // Input maximum matrix
    printf("\nEnter the maximum matrix:\n");
    for (i = 0; i < processes; i++) {
        printf("Process %d: ", i + 1);
        for (j = 0; j < resources; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Input available resources
    printf("\nEnter the available resources:\n");
    for (i = 0; i < resources; i++) {
        printf("Resource %d: ", i + 1);
        scanf("%d", &available[i]);
    }

    // Calculate need matrix
    for (i = 0; i < processes; i++) {
        for (j = 0; j < resources; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Initialize finish array
    for (i = 0; i < processes; i++) {
        finish[i] = 0;
    }

    // Initialize work array
    for (i = 0; i < resources; i++) {
        work[i] = available[i];
    }

    // Banker's Algorithm
    int count = 0;
    while (count < processes) {
        int found = 0;
        for (i = 0; i < processes; i++) {
            if (finish[i] == 0) {
                int safe = 1;
                for (j = 0; j < resources; j++) {
                    if (need[i][j] > work[j]) {
                        safe = 0;
                        break;
                    }
                }
                if (safe) {
                    safeSequence[count] = i;
                    count++;
                    finish[i] = 1;
                    found = 1;
                    for (j = 0; j < resources; j++) {
                        work[j] += allocation[i][j];
                    }
                    break;
                }
            }
        }
        if (!found) {
            break; // Deadlock detected
        }
    }

    if (count == processes) {
        printf("\nSystem is in a safe state.\nSafe sequence: ");
        for (i = 0; i < processes; i++) {
            printf("%d ", safeSequence[i]);
        }
        printf("\n");
    } else {
        printf("\nDeadlock detected. System is not in a safe state.\n");
    }

    return 0;
}


/*

Enter the number of processes: 5
Enter the number of resources: 3

Enter the allocation matrix:
Process 1: 0 1 0
Process 2: 2 0 0
Process 3: 3 0 2
Process 4: 2 1 1
Process 5: 0 0 2

Enter the maximum matrix:
Process 1: 7 5 3
Process 2: 3 2 2
Process 3: 9 0 2
Process 4: 2 2 2
Process 5: 4 3 3

Enter the available resources:
Resource 1: 3
Resource 2: 3
Resource 3: 2

System is in a safe state.
Safe sequence: 1 3 4 2 0


*/