#include <stdio.h>

typedef struct {
    int base;
    int size;
} Segment;

Segment segTable[5] = {
    {1400, 1000},
    {6300, 400},
    {4300, 400},
    {3200, 1100},
    {4700, 1000}
};

int logicalToPhysical(int seg, int offset) {
    if (offset < segTable[seg].size)
        return segTable[seg].base + offset;
    else{
    	printf("Exceeded offset for seg%d!\n", seg);
        return -1;
    }
}

int main() {
    printf("Physical address for 53 byte of segment 2: %d\n", logicalToPhysical(2, 53));
    printf("Physical address for 852 byte of segment 3: %d\n", logicalToPhysical(3, 852));
    printf("Physical address for 1222 byte of segment 0: %d\n", logicalToPhysical(0, 1222));
    return 0;
}

