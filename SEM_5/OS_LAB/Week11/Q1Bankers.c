/* 1. Consider the following snapshot of the system. Write C program to implement Banker’s algorithm for deadlock avoidance. The program has to accept all inputs from the user. Assume the total number of instances of A,B and C are 10,5 and 7 respectively. 
(a) What is the content of the matrix Need? 
(b) Is the system in a safe state? 
(c) If a request from process P1 arrives for (1, 0, 2), can the request be granted immediately? Display the updated Allocation, Need and Available matrices. 
(d) If a request from process P4 arrives for (3, 3, 0), can the request be granted immediately? 
(e) If a request from process P0 arrives for (0, 2, 0), can the request be granted immediately? 
*/

#include <stdio.h>
#define P 5   // Number of processes
#define R 3   // Number of resources

int alloc[P][R] = {
    {0, 1, 0},
    {2, 0, 0},
    {3, 0, 2},
    {2, 1, 1},
    {0, 0, 2}
};

int max[P][R] = {
    {7, 5, 3},
    {3, 2, 2},
    {9, 0, 2},
    {2, 2, 2},
    {4, 3, 3}
};

int avail[R] = {3, 3, 2};
int need[P][R];
int safeSeq[P]; // To store the safe sequence

void calc_need() {
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = max[i][j] - alloc[i][j];
}

void print_safe_seq(int seq[], int n) {
    printf("\nSafe Sequence: ");
    for (int i = 0; i < n; i++) {
        printf("P%d", seq[i]);
        if (i != n - 1)
            printf(" -> ");
    }
    printf("\n");
}

int check_safe() {
    int work[R];
    int finish[P] = {0};
    int count = 0;

    for (int i = 0; i < R; i++)
        work[i] = avail[i];

    while (count < P) {
        int found = 0;
        for (int i = 0; i < P; i++) {
            if (finish[i] == 0) {
                int j;
                for (j = 0; j < R; j++)
                    if (need[i][j] > work[j])
                        break;
                if (j == R) {
                    for (int k = 0; k < R; k++)
                        work[k] += alloc[i][k];
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found)
            return 0; // Not safe
    }

    // Print the safe sequence if safe
    print_safe_seq(safeSeq, P);
    return 1; // Safe
}

int request_resources(int p, int req[]) {
    for (int j = 0; j < R; j++) {
        if (req[j] > need[p][j]) {
            printf("Error: Process requested more than its maximum need.\n");
            return 0;
        }
        if (req[j] > avail[j]) {
            printf("Resources not available. Process must wait.\n");
            return 0;
        }
    }

    // Pretend to allocate resources
    for (int j = 0; j < R; j++) {
        avail[j] -= req[j];
        alloc[p][j] += req[j];
        need[p][j] -= req[j];
    }

    if (check_safe()) {
        printf("Request granted. System remains safe.\n");
        return 1;
    } else {
        // Rollback
        for (int j = 0; j < R; j++) {
            avail[j] += req[j];
            alloc[p][j] -= req[j];
            need[p][j] += req[j];
        }
        printf("Request denied. System would be unsafe.\n");
        return 0;
    }
}

int main() {
    calc_need();

    printf("Need Matrix:\n   A\tB\tC\n");
    for (int i = 0; i < P; i++) {
        printf("P%d ", i);
        for (int j = 0; j < R; j++)
            printf("%d\t", need[i][j]);
        printf("\n");
    }

    // Check initial safety
    printf("\nChecking initial system safety...\n");
    if (check_safe())
        printf("System is in a safe state.\n");
    else
        printf("System is NOT in a safe state.\n");

    while (1) {
        int p;
        int req[R];
        printf("\nEnter process number (0-%d) or -1 to exit: ", P - 1);
        scanf("%d", &p);
        if (p == -1)
            break;

        printf("Enter request for %d resources: ", R);
        for (int i = 0; i < R; i++)
            scanf("%d", &req[i]);

        request_resources(p, req);
    }

    return 0;
}

