#include <stdio.h>
#define N 3    // Number of frames
#define REF 12 // Number of references

typedef struct {
    int page;
    int ref;
} Frame;

int main() {
    int refStr[REF] = {1, 2, 3, 2, 4, 1, 5, 2, 4, 5, 3, 2};
    Frame frames[N];
    int i, j;
    int pointer = 0;
    int faults = 0;
    int hits = 0;

    // Initialize frames with page = -1 and ref = 0
    for (i = 0; i < N; i++) {
        frames[i].page = -1;
        frames[i].ref = 0;
    }

    for (i = 0; i < REF; i++) {
        int found = 0;
        for (j = 0; j < N; j++) {
            if (frames[j].page == refStr[i]) {
                found = 1;
                frames[j].ref = 1;  // Give second chance
                hits++;
                break;
            }
        }
        if (found) continue;  // Page Hit

        // Second chance algorithm to find a frame to replace
        while (frames[pointer].ref) {
            frames[pointer].ref = 0;
            pointer = (pointer + 1) % N;
        }
        // Replace page
        frames[pointer].page = refStr[i];
        frames[pointer].ref = 1;
        pointer = (pointer + 1) % N;
        faults++;
    }

    printf("Page faults: %d\n", faults);
    printf("Hit ratio: %.2f\n", (float)hits / REF);

    return 0;
}

