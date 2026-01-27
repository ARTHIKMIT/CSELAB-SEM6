/*
Q1. Write a C program to emulate the ls -l UNIX command that prints all files in a current directory and lists access privileges, etc. DO NOT simply exec ls -l from the program.
*/

#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void print_permissions(mode_t mode, char *str) {
    str[0] = S_ISDIR(mode) ? 'd' : '-';
    str[1] = (mode & S_IRUSR) ? 'r' : '-';
    str[2] = (mode & S_IWUSR) ? 'w' : '-';
    str[3] = (mode & S_IXUSR) ? 'x' : '-';
    str[4] = (mode & S_IRGRP) ? 'r' : '-';
    str[5] = (mode & S_IWGRP) ? 'w' : '-';
    str[6] = (mode & S_IXGRP) ? 'x' : '-';
    str[7] = (mode & S_IROTH) ? 'r' : '-';
    str[8] = (mode & S_IWOTH) ? 'w' : '-';
    str[9] = (mode & S_IXOTH) ? 'x' : '-';
    str[10] = '\0';
}

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

        char perms[11];
        print_permissions(statbuf.st_mode, perms);
        
        // Get user and group names
        struct passwd *pwd = getpwuid(statbuf.st_uid);
        struct group *grp = getgrgid(statbuf.st_gid);
        
        // Format time string
        char timebuf[20];
        struct tm *tm_info = localtime(&statbuf.st_mtime);
        strftime(timebuf, sizeof(timebuf), "%b %d %H:%M", tm_info);
        
        if (S_ISDIR(statbuf.st_mode))continue;
        else {
            printf("%*s%s %2lu %s %s %6lld %s %s\n", 
                depth, "", perms, (unsigned long)statbuf.st_nlink,
                pwd ? pwd->pw_name : "unknown",
                grp ? grp->gr_name : "unknown",
                (long long)statbuf.st_size, timebuf, entry->d_name);
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
