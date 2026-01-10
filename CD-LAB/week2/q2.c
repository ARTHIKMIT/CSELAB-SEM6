#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp1, *fp2;
    char line[200];

    fp1 = fopen("input.c", "r");
    fp2 = fopen("output.c", "w");

    if (fp1 == NULL || fp2 == NULL)
    {
        printf("Error opening file\n");
        exit(0);
    }

    while (fgets(line, sizeof(line), fp1))
    {
        if (line[0] != '#')
            fputs(line, fp2);
    }

    fclose(fp1);
    fclose(fp2);

    printf("Preprocessor directives removed\n");
    return 0;
}
