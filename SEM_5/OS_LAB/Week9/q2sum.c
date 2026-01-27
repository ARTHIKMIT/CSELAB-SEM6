#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int *a = NULL;
int nos = 0, sum = 0;

void* child_thread(void* param) {
    int* arr = (int*) param;

    printf("Start thread\n");
    for (int i = 0; i < nos; i++)
        sum += arr[i];

    return NULL;
}

int main(int argc, char* argv[]) {
    pthread_t thread;

    if (argc >= 2)
		exit(1);
	
	nos = atoi(argv[1]);

    printf("Enter %d numbers:\n", nos);

    a = calloc(nos, sizeof(int));

    for (int i = 0; i < nos; i++) {
        scanf("%d", &a[i]);
        if (a[i] < 0) {
            printf("Invalid input!\n");
            free(a);
            exit(1);
        }
    }

    pthread_create(&thread, NULL, &child_thread, (void*)a);
    pthread_join(thread, NULL);

    printf("Sum is: %d\n", sum);
    free(a);
    return 0;
}
