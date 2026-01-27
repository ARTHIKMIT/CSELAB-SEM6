#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int start, finish, n = 0;

int checkPrime(int p){
    if(p < 2)
        return 0;
    if(p == 2)
        return 1;
    for(int i=2; i<p; i++)
        if(p%i==0)
            return 0;
    return 1;
}

void* countPrime(void* param){
    printf("Start thread 0\n");
    int count = 0;
    for(int i=start; i<=finish; i++)
        if(checkPrime(i))
            count++;
    *(int*) param = count;
    printf("Thread 0 complete!\n");
    return NULL;
}

void* child_thread( void * param ) { 
	printf( "Start thread 1\n");
    int *arr = (int*)param;
    int t = 0;
    for(int i = start; i <= finish; i++)
        if(checkPrime(i))
            arr[t++]=i;

    printf("Thread 1 complete!\n");
	return NULL;
}

int main(int argc, char* argv[]) {
    if (argc < 3)
        exit(1);
    start = atoi(argv[1]);
    finish = atoi(argv[2]);

    pthread_t t0, t1;

    pthread_create(&t0, NULL, countPrime, &n);
    pthread_join(t0, NULL);

    int  *arr = calloc(n, sizeof(int));

    pthread_create(&t1, NULL, child_thread, arr);
    pthread_join(t1, NULL);

    printf("Primes are:\n");
    for (int i = 0; i < n; i++)
        printf("%d\n", arr[i]);

    free(a);
    return 0;
}