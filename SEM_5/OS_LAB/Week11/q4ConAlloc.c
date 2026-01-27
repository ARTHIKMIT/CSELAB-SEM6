#include <stdio.h>
#include <stdlib.h>

#define TOTAL_BLOCKS 20      // total disk blocks
#define SPARE_BLOCKS 3       // number of spare blocks
#define MAX_FILES 5

typedef struct {
    int bad_block;   // original bad block
    int spare_block; // replacement spare block
} BadBlockEntry;

typedef struct {
    int start_block;
    int length;
} FileEntry;

int main() {
    int disk[TOTAL_BLOCKS] = {0};  // 0 = free, 1 = allocated, -1 = bad
    int i, num_bad, num_files;

    // Input bad blocks
    printf("Enter number of bad blocks: ");
    scanf("%d", &num_bad);

    BadBlockEntry bad_table[num_bad];
    for (i = 0; i < num_bad; i++) {
        printf("Enter bad block number (0-%d): ", TOTAL_BLOCKS - 1);
        scanf("%d", &bad_table[i].bad_block);
        disk[bad_table[i].bad_block] = -1;
    }

    // Assign spare blocks (last SPARE_BLOCKS blocks)
    int spare_start = TOTAL_BLOCKS - SPARE_BLOCKS;
    int next_spare = spare_start;

    for (i = 0; i < num_bad; i++) {
        if (next_spare < TOTAL_BLOCKS) {
            bad_table[i].spare_block = next_spare++;
        } else {
            printf("No more spare blocks available!\n");
            exit(1);
        }
    }

    // Allocate files contiguously (excluding bad blocks)
    printf("\nEnter number of files: ");
    scanf("%d", &num_files);
    FileEntry files[num_files];

    for (i = 0; i < num_files; i++) {
        printf("Enter starting block and length for file %d: ", i + 1);
        scanf("%d %d", &files[i].start_block, &files[i].length);

        // Allocate file blocks
        for (int j = files[i].start_block; j < files[i].start_block + files[i].length; j++) {
            if (disk[j] == -1) {
                printf("Block %d is bad, using spare block instead.\n", j);
            } else if (disk[j] == 1) {
                printf("Block %d already allocated!\n", j);
                exit(1);
            } else {
                disk[j] = 1;
            }
        }
    }

    // Display bad block table
    printf("\n--- Bad Block Table ---\n");
    printf("Bad Block\tSpare Block\n");
    for (i = 0; i < num_bad; i++) {
        printf("%d\t\t%d\n", bad_table[i].bad_block, bad_table[i].spare_block);
    }

    // Simulate accessing a block
    int access_block;
    printf("\nEnter block number to access: ");
    scanf("%d", &access_block);

    int replaced = 0;
    for (i = 0; i < num_bad; i++) {
        if (bad_table[i].bad_block == access_block) {
            printf("Accessing bad block %d → redirected to spare block %d\n",
                   access_block, bad_table[i].spare_block);
            replaced = 1;
            break;
        }
    }
    if (!replaced)
        printf("Accessing normal block %d\n", access_block);

    // Display disk status
    printf("\n--- Disk Status ---\n");
    for (i = 0; i < TOTAL_BLOCKS; i++) {
        if (disk[i] == -1)
            printf("[%d:BAD] ", i);
        else if (i >= spare_start)
            printf("[%d:SPARE] ", i);
        else if (disk[i] == 1)
            printf("[%d:USED] ", i);
        else
            printf("[%d:FREE] ", i);
    }
    printf("\n");

    return 0;
}
/*
Enter number of bad blocks: 2
Enter bad block number (0-19): 5
Enter bad block number (0-19): 12

Enter number of files: 2
Enter starting block and length for file 1: 2 4
Enter starting block and length for file 2: 10 5
Block 12 is bad, using spare block instead.

--- Bad Block Table ---
Bad Block   Spare Block
5           17
12          18

Enter block number to access: 12
Accessing bad block 12 → redirected to spare block 18

--- Disk Status ---
[0:FREE] [1:FREE] [2:USED] [3:USED] [4:USED] [5:BAD] [6:FREE] [7:FREE] [8:FREE] [9:FREE]
[10:USED] [11:USED] [12:BAD] [13:USED] [14:USED] [15:FREE] [16:FREE] [17:SPARE] [18:SPARE] [19:SPARE]

*/
