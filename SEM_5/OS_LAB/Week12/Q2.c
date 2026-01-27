#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void printdir(char *dir, int depth) {
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    char filepath[1024];

    if ((dp = opendir(dir)) == NULL) {
        fprintf(stderr, "cannot open directory: %s\n", dir);
        return;
    }
    
    chdir(dir);
    
    while ((entry = readdir(dp)) != NULL) {
        lstat(entry->d_name, &statbuf);
        if (S_ISDIR(statbuf.st_mode)) {
            if (strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name) == 0)
                continue;
            printf("dir : %s \n", entry->d_name);
                
            printdir(entry->d_name, depth + 4);
        } else {
            printf("file: %s in Directory %s\n", entry->d_name, dir);
        }
    }
    
    chdir("..");
    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr,"Usage: %s <directory>\n", argv[0]);
        return 1;
    }
    printdir(argv[1], 0);
    return 0;
}

