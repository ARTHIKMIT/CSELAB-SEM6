#include <stdio.h>
#include <ctype.h>
#include <string.h>

FILE *fp;
int row = 1, col = 0;

/* ---------- Keyword Check ---------- */
int isKeyword(char *str) {
    char *keywords[] = {
        "int","float","double","char","if","else",
        "while","for","return","void","main"
    };
    int n = 11;
    for (int i = 0; i < n; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

/* ---------- Get Next Token ---------- */
void getNextToken() {
    char ch, buffer[50];
    int i;

    while ((ch = fgetc(fp)) != EOF) {
        col++;

        /* New line */
        if (ch == '\n') {
            row++;
            col = 0;
            continue;
        }

        /* Skip spaces and tabs */
        if (isspace(ch))
            continue;

        /* Identifiers / Keywords */
        if (isalpha(ch) || ch == '_') {
            i = 0;
            buffer[i++] = ch;
            int startCol = col;

            while (isalnum(ch = fgetc(fp)) || ch == '_') {
                buffer[i++] = ch;
                col++;
            }
            buffer[i] = '\0';
            ungetc(ch, fp);

            if (isKeyword(buffer))
                printf("<%s,%d,%d>\n", buffer, row, startCol);
            else
                printf("<id,%d,%d>\n", row, startCol);
        }

        /* Numbers */
        else if (isdigit(ch)) {
            i = 0;
            buffer[i++] = ch;
            int startCol = col;

            while (isdigit(ch = fgetc(fp))) {
                buffer[i++] = ch;
                col++;
            }
            buffer[i] = '\0';
            ungetc(ch, fp);

            printf("<num,%d,%d>\n", row, startCol);
        }

        /* Operators */
        else if (ch == '=' || ch == '<' || ch == '>' || ch == '+' || ch == '-') {
            int startCol = col;
            char next = fgetc(fp);

            if ((ch == '=' && next == '=') ||
                (ch == '<' && next == '=') ||
                (ch == '>' && next == '=')) {
                col++;
                printf("<%c%c,%d,%d>\n", ch, next, row, startCol);
            } else {
                ungetc(next, fp);
                printf("<%c,%d,%d>\n", ch, row, startCol);
            }
        }

        /* Special Symbols */
        else if (ch == ';' || ch == ',' || ch == '(' || ch == ')' ||
                 ch == '{' || ch == '}') {
            printf("<%c,%d,%d>\n", ch, row, col);
        }
    }
}

/* ---------- Main ---------- */
int main() {
    fp = fopen("input.c", "r");
    if (fp == NULL) {
        printf("Cannot open file\n");
        return 1;
    }

    getNextToken();
    fclose(fp);
    return 0;
}
