#include <stdio.h>

int main()
{
    int buffer[10], bufsize = 10, in = 0, out = 0, produce, consume, choice = 0;

    while (choice != 3)
    {
        printf("\n1. Produce\t2. Consume\t3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if ((in + 1) % bufsize == out)
                printf("\nBuffer is Full");
            else
            {
                printf("\nEnter the value: ");
                scanf("%d", &produce);
                buffer[in] = produce;
                in = (in + 1) % bufsize;
            }
            break;

        case 2:
            if (in == out)
                printf("\nBuffer is Empty");
            else
            {
                consume = buffer[out];
                printf("\nThe consumed value is %d", consume);
                out = (out + 1) % bufsize;
            }
            break;

        case 3:
            // Added case 3 for exit
            printf("\nExiting the program");
            break;

        default:
            // Added default case for invalid choices
            printf("\nInvalid choice");
            break;
        }
    }

    return 0;
}

/*

1. Produce    2. Consume    3. Exit
Enter your choice: 1

Enter the value: 5

1. Produce    2. Consume    3. Exit
Enter your choice: 1

Enter the value: 8

1. Produce    2. Consume    3. Exit
Enter your choice: 2

The consumed value is 5

1. Produce    2. Consume    3. Exit
Enter your choice: 2

The consumed value is 8

1. Produce    2. Consume    3. Exit
Enter your choice: 2

Buffer is Empty

1. Produce    2. Consume    3. Exit
Enter your choice: 3

Exiting the program


*/