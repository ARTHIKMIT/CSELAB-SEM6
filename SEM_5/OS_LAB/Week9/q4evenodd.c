#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int nums=0, oddSum=0, evenSum=0;
int *a = NULL;

void* addOdd(void* param){
    printf("Start thread 0\n");
    int ds = 0;
    for(int i=0; i<nums; i++)
        if(a[i]%2 == 1)
            ds += a[i];
    
    *(int*)param = ds;
	printf("Thread 0 complete!\n");
	return NULL;
}

void* addEven( void * param ){
	printf("Start thread 1\n");
    int es = 0;
    for(int i=0; i<nums; i++)
        if(a[i]%2 == 0)
            es += a[i];

    *(int*)param = es;
    printf("Thread 1 complete!\n");
	return NULL;
}

int main(int argc, char* argv[]) {
	pthread_t t1, t2;
	if(argc<2)
        exit(1);
	nums = atoi(argv[1]);
    
    a = calloc(nums, sizeof(int));
    printf("Enter nums:\n");
    for(int i=0; i<nums; i++)
        scanf("%d", &a[i]);
    
    pthread_create( &t1, 0, &addEven, (void*)&evenSum);
    pthread_create( &t2, 0, &addOdd, (void*)&oddSum);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

	printf("Odd sum is: %d\n", oddSum);
    printf("Even sum is: %d\n", evenSum);
	free(a);	
	return 0;
}
