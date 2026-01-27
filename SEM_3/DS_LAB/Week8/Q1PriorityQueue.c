/*
Q1 Implement an ascending priority queue.
Note: An ascending priority queue is a collection of items into which items can be
inserted arbitrarily and from which only the smallest item can be removed. If apq is
an ascending priority queue, the operation pqinsert(apq,x) inserts element x into apq
and pqmindelete(apq) removes the minimum element from apq and returns its value.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
	int * items;
	int front;
	int rear;
	int size;
}PriorityQueue;

bool isFull(PriorityQueue q){
	if (q.rear == q.size-1)
		return true;
	else return false;
}

bool isEmpty(PriorityQueue q){
	if (q.rear == -1)
		return true;
	else return false;
}

void insert(PriorityQueue *q, int item){
	if (isFull(*q)){
		printf("Queue is Full.");
		return;
	}
	if (isEmpty(*q))
		q->front = 0;
	q->items[++(q->rear)] = item;
	//printf("  %d %d %d  ", q->rear, q->front, item);
}

int delete(PriorityQueue *q){
	if (isEmpty(*q)){
		printf("Empty Queue. ");
		return -1;
	}
	int smallestInd = q->front;
	for (int i=q->front; i<=q->rear; i++)
		if (q->items[i]<q->items[smallestInd])
			smallestInd = i;

	int ele = q->items[smallestInd];
	
	for (int i=smallestInd; i<=q->rear-1; i++)
		q->items[i] = q->items[i+1];
	q->rear--;
	return ele;
}

void display(PriorityQueue q){
	printf("The Queue is : \n");
	if (isEmpty(q)){
		printf("Empty ");
		return;
	}
	for (int i=q.front; i<=q.rear; i++)
		printf("%d ", q.items[i]);
}

int main(){
	int n, ch, x;
	printf("Enter Size : ");
	scanf("%d", &n);
	PriorityQueue q;
	q.items = (int *) malloc(n*sizeof(int));
	q.rear = q.front = -1;
	q.size = n;
	printf("1. Insert Queue, 2. Delete Queue, 3. Display Queue, 4. Exit\n");
	do {
		
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the Element:");
				scanf("%d",&x);
				insert(&q,x);
				break;
			case 2:
				x=delete(&q);
				printf("\nRemoved %d from the Queue\n",x);
				break;
			case 3:
				display(q);
				break;
			case 4:
				break;
			default:
				printf("\nWrong choice!!! Try Again.\n");
		}
	} while (ch!=4);
	return 0;
}