#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char *word)
{
    char *keywords[] = {
        "int","float","char","if","else","for","while","return","void","break","continue"
    };

    for (int i = 0; i < 11; i++)
    {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

void toUpper(char *word)
{
    for (int i = 0; word[i]; i++)
        word[i] = toupper(word[i]);
}

int main()
{
    FILE *fp;
    char word[50];

    fp = fopen("input.c", "r");
    if (fp == NULL)
    {
        printf("File not found\n");
        exit(0);
    }

    printf("Keywords in uppercase:\n");

    while (fscanf(fp, "%s", word) != EOF)
    {
        if (isKeyword(word))
        {
            toUpper(word);
            printf("%s\n", word);
        }
    }

    fclose(fp);
    return 0;
}
