#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int request[100], st, cylinders, n;

void randomize() {
    int i;
    for (i = 0; i < n; i++) {
        request[i] = rand() % cylinders + 1;
    }
}

void display() {
    int i;
    printf("\nThe requests are:\n");
    for (i = 0; i < n; i++) {
        printf(" %d ", request[i]);
    }
    printf("\n");
}

void fcfs() {
    int total = 0, i;
    display();
    printf("\n\nThe traversal is shown below:\n\n%d", st);
    for (i = 0; i < n; i++) {
        printf("-->%d", request[i]);
        total += abs(request[i] - st);
        st = request[i];
    }
    printf("\n\nNo. of cylinders traversed: %d\n", total);
}

void scan() {
    int total = 0, i, j, temp;
    display();
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (request[j] > request[j + 1]) {
                temp = request[j];
                request[j] = request[j + 1];
                request[j + 1] = temp;
            }
        }
    }
    display();
    printf("\nThe traversal is shown below:\n\n%d", st);
    if (st < request[0]) {
        for (i = 0; i < n; i++) {
            printf("-->%d", request[i]);
            total += abs(request[i] - st);
            st = request[i];
        }
    } else {
        i = 0;
        temp = 0;
        while (st > request[i++]) {
            temp++;
        }
        for (i = temp; i < n; i++) {
            printf("-->%d", request[i]);
            total += abs(request[i] - st);
            st = request[i];
            if (i == n - 1) {
                total = total + 2 * cylinders - request[i];
                st = 0;
                i = 0;
                n = temp;
                if (st != cylinders) {
                    printf("-->%d", cylinders);
                    printf("-->%d", 1);
                }
            }
        }
    }
    printf("\nTotal cylinders traversed: %d\n", total);
}

int main() {
    int choice;
    printf("Enter the number of cylinders in the hard disk and the starting cylinder: ");
    scanf("%d %d", &cylinders, &st);
    printf("\nPress 0 to generate random disk requests or any other number to give your own requests: ");
    scanf("%d", &choice);
    if (choice == 0) {
        printf("\nEnter the number of requests to generate randomly: ");
        scanf("%d", &n);
        srand(time(NULL));
        randomize();
    } else {
        printf("\nEnter the cylinders requested (0 to break):\n");
        while (1) {
            scanf("%d", &request[n]);
            if (request[n] == 0 || n == 100) {
                n--;
                break;
            }
            n++;
        }
    }
    printf("\nEnter the scheduling algorithm that you want to implement (0: FCFS, 1: Scan): ");
    scanf("%d", &choice);
    switch (choice) {
        case 0:
            fcfs();
            break;
        case 1:
            scan();
            break;
        default:
            break;
    }
    return 0;
}
/*
Enter the number of cylinders in the hard disk and the starting cylinder: 200 50

Press 0 to generate random disk requests or any other number to give your own requests: 0

Enter the number of requests to generate randomly: 8

The requests are:
 95  180  43  35  75  64  90  157

Enter the scheduling algorithm that you want to implement (0: FCFS, 1: Scan): 0

The requests are:
 95  180  43  35  75  64  90  157

The traversal is shown below:
50-->95-->180-->43-->35-->75-->64-->90-->157

No. of cylinders traversed: 646



*/