#include <stdio.h>
#include <string.h>

void readfile();
void writefile();

int a, b, i = 0;
char c[40];
char buffer[89];
char *g;
FILE *fr, *fw;

void main()
{
    printf("\n1. Read\n2. Write");
    printf("\nUSER A, enter your choice: ");
    scanf("%d", &a);
    printf("USER B, enter your choice: ");
    scanf("%d", &b);
    getchar(); // Consume the newline character from the previous input

    if (a == 1 && b == 1)
    {
        readfile();
    }
    else if (a == 1 && b == 2)
    {
        writefile();
        readfile();
    }
    else if (a == 2 && b == 1)
    {
        readfile();
        writefile();
    }
    else if (a == 2 && b == 2)
    {
        printf("Both users are not allowed to write.\n");
        return;
    }
}

void readfile()
{
    fr = fopen("filename.c", "r");
    if (fr == NULL)
    {
        printf("File could not be opened.\n");
        return;
    }

    printf("\nFile content is:\n");
    while (fgets(c, sizeof(c), fr) != NULL)
    {
        printf("%s", c);
    }

    fclose(fr);
}

void writefile()
{
    printf("Enter your content to write:\n");
    fgets(buffer, sizeof(buffer), stdin);
    fw = fopen("filename.c", "w");
    if (fw == NULL)
    {
        printf("File could not be opened.\n");
        return;
    }

    fputs(buffer, fw);
    fclose(fw);
}

/*

1. Read
2. Write
USER A, enter your choice: 1
USER B, enter your choice: 2
Enter your content to write:
This is a sample text.

File content:
This is a sample text.

*/