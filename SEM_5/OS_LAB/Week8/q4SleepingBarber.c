#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cv = PTHREAD_COND_INITIALIZER;
int waiting[3];
int waiting_count = 0;
const int NUM_CHAIRS = 3;

void* barber(void* arg) {
    while (1) {
        pthread_mutex_lock(&mtx);
        while (waiting_count == 0) {
            pthread_cond_wait(&cv, &mtx);
        }
        int cust = waiting[0];
        for (int i = 0; i < waiting_count - 1; ++i) {
            waiting[i] = waiting[i + 1];
        }
        waiting_count--;
        pthread_mutex_unlock(&mtx);
        printf("Barber cutting hair of customer %d\n", cust);
        sleep(rand() % 3 + 1);
        printf("Barber finished with customer %d\n", cust);
        pthread_mutex_lock(&mtx);
        pthread_cond_signal(&cv);
    }
    return NULL;
}

void* customer(void* arg) {
    int i = *((int*)arg);
    sleep(rand() % 4 + 1);
    pthread_mutex_lock(&mtx);
    if (waiting_count < NUM_CHAIRS) {
        waiting[waiting_count++] = i;
        printf("Customer %d waiting\n", i);
        pthread_cond_signal(&cv);
        while (waiting[0] != i) {
            pthread_cond_wait(&cv, &mtx);
        }
        printf("Customer %d got haircut\n", i);
    } else {
        printf("Customer %d left (no seat)\n", i);
    }
    pthread_mutex_unlock(&mtx);
    return NULL;
}

int main() {
    pthread_t t1, t[5];
    pthread_create(&t1, NULL, barber, NULL);
    for (int i = 0; i < 5; ++i) {
        int* arg = malloc(sizeof(int));
        *arg = i;
        pthread_create(&t[i], NULL, customer, arg);
    }
    for (int i = 0; i < 5; ++i) {
        pthread_join(t[i], NULL);
    }
    pthread_join(t1, NULL);
    return 0;
}
