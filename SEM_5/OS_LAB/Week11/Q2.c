/* 
2. Write a multithreaded program that implements the banker's algorithm. Create n threads that request and release resources from the bank. The banker will grant the request only if it leaves the system in a safe state. You may write this program using pthreads. It is important that shared data be safe from concurrent access. To ensure safe access to shared data, you can use mutex locks, which are available in the pthreads libraries.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define P 5  // Number of processes (threads)
#define R 3  // Number of resource types

// Global shared data
int available[R] = {10, 5, 7};  // Total available resources
int maximum[P][R] = {
    {7, 5, 3},
    {3, 2, 2},
    {9, 0, 2},
    {2, 2, 2},
    {4, 3, 3}
};
int allocation[P][R] = {
    {0, 1, 0},
    {2, 0, 0},
    {3, 0, 2},
    {2, 1, 1},
    {0, 0, 2}
};
int need[P][R];

pthread_mutex_t lock; // Mutex for shared data protection

// Function to calculate Need matrix
void calc_need() {
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = maximum[i][j] - allocation[i][j];
}

// Function to check system safety and get safe sequence
int is_safe() {
    int work[R];
    int finish[P] = {0};
    int safeSeq[P];
    int count = 0;

    for (int i = 0; i < R; i++)
        work[i] = available[i];

    while (count < P) {
        int found = 0;
        for (int i = 0; i < P; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < R; j++)
                    if (need[i][j] > work[j])
                        break;

                if (j == R) {
                    for (int k = 0; k < R; k++)
                        work[k] += allocation[i][k];
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found)
            return 0; // Unsafe state
    }

    printf("Safe sequence: ");
    for (int i = 0; i < P; i++)
        printf("P%d ", safeSeq[i]);
    printf("\n");

    return 1;
}

// Function to request resources
int request_resources(int pid, int req[]) {
    pthread_mutex_lock(&lock);

    printf("\nProcess P%d requesting: ", pid);
    for (int i = 0; i < R; i++) printf("%d ", req[i]);
    printf("\n");

    // Check if request exceeds need or available
    for (int i = 0; i < R; i++) {
        if (req[i] > need[pid][i]) {
            printf("Error: P%d requested more than its maximum need!\n", pid);
            pthread_mutex_unlock(&lock);
            return 0;
        }
        if (req[i] > available[i]) {
            printf("P%d must wait. Not enough resources available.\n", pid);
            pthread_mutex_unlock(&lock);
            return 0;
        }
    }

    // Tentatively allocate resources
    for (int i = 0; i < R; i++) {
        available[i] -= req[i];
        allocation[pid][i] += req[i];
        need[pid][i] -= req[i];
    }

    // Check if system remains safe
    if (is_safe()) {
        printf("Request by P%d granted. System is safe.\n", pid);
        pthread_mutex_unlock(&lock);
        return 1;
    } else {
        // Rollback
        for (int i = 0; i < R; i++) {
            available[i] += req[i];
            allocation[pid][i] -= req[i];
            need[pid][i] += req[i];
        }
        printf("Request by P%d denied. System would be unsafe.\n", pid);
        pthread_mutex_unlock(&lock);
        return 0;
    }
}

// Function to release resources
void release_resources(int pid, int rel[]) {
    pthread_mutex_lock(&lock);
    printf("Process P%d releasing: ", pid);
    for (int i = 0; i < R; i++) printf("%d ", rel[i]);
    printf("\n");

    for (int i = 0; i < R; i++) {
        allocation[pid][i] -= rel[i];
        available[i] += rel[i];
        need[pid][i] += rel[i];
    }
    pthread_mutex_unlock(&lock);
}

// Thread function for each process
void *process_thread(void *pid_ptr) {
    int pid = *(int *)pid_ptr;
    sleep(rand() % 3 + 1); // Random delay to simulate concurrency

    while (1) {
        int req[R];
        int rel[R];

        pthread_mutex_lock(&lock);
        int done = 1;
        for (int i = 0; i < R; i++) {
            if (need[pid][i] > 0) {
                done = 0;
                break;
            }
        }
        pthread_mutex_unlock(&lock);
        if (done) break; // Process finished

        // Generate random request within remaining need
        for (int i = 0; i < R; i++)
            req[i] = rand() % (need[pid][i] + 1);

        if (request_resources(pid, req)) {
            sleep(rand() % 2 + 1); // Simulate resource use

            // Generate random release (up to allocated)
            for (int i = 0; i < R; i++)
                rel[i] = rand() % (allocation[pid][i] + 1);
            release_resources(pid, rel);
        } else {
            sleep(1); // Wait before retrying
        }
    }

    printf("Process P%d has finished execution.\n", pid);
    return NULL;
}

int main() {
    pthread_t threads[P];
    int pids[P];

    pthread_mutex_init(&lock, NULL);
    calc_need();

    printf("Initial Available Resources: ");
    for (int i = 0; i < R; i++) printf("%d ", available[i]);
    printf("\n");

    // Create process threads
    for (int i = 0; i < P; i++) {
        pids[i] = i;
        pthread_create(&threads[i], NULL, process_thread, &pids[i]);
    }

    // Wait for all processes to finish
    for (int i = 0; i < P; i++)
        pthread_join(threads[i], NULL);

    pthread_mutex_destroy(&lock);

    printf("\nAll processes have completed. Final Available Resources: ");
    for (int i = 0; i < R; i++) printf("%d ", available[i]);
    printf("\n");

    return 0;
}
