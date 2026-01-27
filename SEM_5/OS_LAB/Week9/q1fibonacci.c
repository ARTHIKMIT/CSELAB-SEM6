#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int* a=NULL;
int numOfRows, turn=0;

void* child_thread( void * param ) {
	int* p = (int*) param;
	
	if(p==NULL)
		printf("p is NULL!\n");
	
	a = calloc(sizeof(int), *p);
	
	printf( "Start thread %d\n", *p);
	
	a[0]=0;
	a[1]=1;

	for(int i=2; i<(*p); i++)
		a[i]=a[i-1]+a[i-2];
	
	turn =1;
	return NULL;
}

int main(int argc, char* argv[]) {
	pthread_t thread;
	if(argc<2)
		exit(1);
	
	int numOfRows = atoi(argv[1]);
	
	pthread_create( &thread, 0, &child_thread, (void*)&numOfRows );
	
	while(turn==0);
	
	printf("Series is:\n");
	for(int i=0; i<numOfRows; i++)
		printf("%d\n", a[i]);	
	free(a);	
	return 0;
}
