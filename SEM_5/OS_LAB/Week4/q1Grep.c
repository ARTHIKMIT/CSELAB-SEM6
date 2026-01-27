/*
Write a program to print the lines of a file that contain a word given as the program argument (a simple version of grep UNIX utility).
*/

#include <unistd.h> // for read(), lseek(), close()
#include <sys/stat.h> // for file permission constants
#include <fcntl.h> // for open() flags
#include <stdlib.h> // for exit()
#include <stdio.h> // for printf(), perror()
#include <string.h>

int main(){
    char ch, st[100];
    int inFD, i=0, lineStart=-1, comparInd=0, subStrLen, lineNo=1;

    printf("Enter Substring to grep : ");
    scanf("%s", st);
    subStrLen = strlen(st);

    inFD = open("Text.txt", O_RDONLY);
    while (read(inFD, &ch, 1) == 1){

        if (ch=='\n'){
            lineStart = i;
            lineNo++;
        }
        else if (ch == st[comparInd]) {
            if (comparInd == subStrLen - 1) {
                int seek = lseek(inFD, lineStart + 1, SEEK_SET);
                int lineLen = 0;
                printf("LINE %d : ", lineNo);
                while (read(inFD, &ch, 1) == 1) {
                    printf("%c", ch);
                    lineLen++;
                    if (ch == '\n')
                        break;
                }
                i = lineStart + lineLen;
                lineStart = i;
                lineNo++;
                comparInd = 0;
            }
            else
                comparInd++;
        }
        else
            comparInd = 0;
        i++;

    }
}
