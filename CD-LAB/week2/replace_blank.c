#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp1, *fp2;
    char ch, prev = '\0';

    fp1 = fopen("input.c", "r");
    fp2 = fopen("output.c", "w");

    if (fp1 == NULL || fp2 == NULL)
    {
        printf("Error opening file\n");
        exit(0);
    }

    while ((ch = fgetc(fp1)) != EOF)
    {
        if (ch == ' ' || ch == '\t')
        {
            if (prev != ' ')
            {
                fputc(' ', fp2);
                prev = ' ';
            }
        }
        else
        {
            fputc(ch, fp2);
            prev = ch;
        }
    }

    fclose(fp1);
    fclose(fp2);

    printf("Spaces and tabs replaced successfully\n");
    return 0;
}
