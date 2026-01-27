#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure for Disk Scheduling Algorithm (DSA)
struct DSA {
    int request_id;
    int arrival_time_stamp;
    int cylinder;
    int address;
    int process_id;
};

// Function to implement FCFS Disk Scheduling
void FCFS(struct DSA req[], int n, int head) {
    int total_seek_time = 0;
    printf("\n--- FCFS Disk Scheduling ---\n");
    printf("Sequence of requests served:\n");

    for (int i = 0; i < n; i++) {
        int distance = abs(req[i].cylinder - head);
        total_seek_time += distance;
        printf("Request ID: %d (Cylinder: %d) -> Seek Distance: %d\n",
               req[i].request_id, req[i].cylinder, distance);
        head = req[i].cylinder;
    }

    printf("Total Seek Time: %d\n", total_seek_time);
    printf("Average Seek Time: %.2f\n", (float)total_seek_time / n);
}

// Function to implement SSTF Disk Scheduling
void SSTF(struct DSA req[], int n, int head) {
    int total_seek_time = 0;
    int completed[n];
    for (int i = 0; i < n; i++) completed[i] = 0;

    printf("\n--- SSTF Disk Scheduling ---\n");
    printf("Sequence of requests served:\n");

    for (int count = 0; count < n; count++) {
        int min_dist = INT_MAX, index = -1;

        for (int i = 0; i < n; i++) {
            if (!completed[i]) {
                int distance = abs(req[i].cylinder - head);
                if (distance < min_dist) {
                    min_dist = distance;
                    index = i;
                }
            }
        }

        completed[index] = 1;
        total_seek_time += min_dist;
        printf("Request ID: %d (Cylinder: %d) -> Seek Distance: %d\n",
               req[index].request_id, req[index].cylinder, min_dist);
        head = req[index].cylinder;
    }

    printf("Total Seek Time: %d\n", total_seek_time);
    printf("Average Seek Time: %.2f\n", (float)total_seek_time / n);
}

// Main function
int main() {
    int n, head;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    struct DSA req[n];

    printf("Enter details for each request:\n");
    for (int i = 0; i < n; i++) {
        req[i].request_id = i + 1;
        printf("\nRequest %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &req[i].arrival_time_stamp);
        printf("Cylinder Number: ");
        scanf("%d", &req[i].cylinder);
        printf("Address: ");
        scanf("%d", &req[i].address);
        printf("Process ID: ");
        scanf("%d", &req[i].process_id);
    }

    printf("\nEnter initial head position: ");
    scanf("%d", &head);

    // Run both algorithms
    FCFS(req, n, head);
    SSTF(req, n, head);

    return 0;
}
/*
Enter number of disk requests: 4

Request 1:
Arrival Time: 0
Cylinder Number: 82
Address: 100
Process ID: 1

Request 2:
Arrival Time: 1
Cylinder Number: 170
Address: 200
Process ID: 2

Request 3:
Arrival Time: 2
Cylinder Number: 43
Address: 300
Process ID: 3

Request 4:
Arrival Time: 3
Cylinder Number: 140
Address: 400
Process ID: 4

Enter initial head position: 50
*/
