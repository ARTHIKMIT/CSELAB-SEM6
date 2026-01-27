#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if(argc < 2) exit(1);
    for(int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if(!fp) continue;
        int count = 0;
        char line[1024];
        while(fgets(line, sizeof(line), fp)) {
            printf("%s", line);
            count++;
            if(count % 20 == 0) {
                getchar();
            }
        }
        fclose(fp);
    }
    return 0;
}
