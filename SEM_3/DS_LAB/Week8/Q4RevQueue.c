/*
Q4 Given a queue of integers, write a program to reverse the queue, 
using only the
following operations:
i. enqueue(x): Add an item x to rear of queue.
ii. dequeue() : Remove an item from front of queue.
iii. empty() : Checks if a queue is empty or not
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *items;
    int front,rear;
} Queue;

void enqueue(Queue * q,int x) {
    if (q->rear == -1) 
        q->front = 0;
    q->items[++(q->rear)] = x;
}

int empty(Queue *q) {
    return ((q->front == -1) || (q->front > q->rear));
}

int dequeue(Queue * q) {
    int x = q->items[q->front];
    int ind=q->front;
    for(int i=q->front+1;i<=q->rear;i++) 
        q->items[ind++] = q->items[i];
    q->rear--;
    return x;
}

int main() {
    int n,i,j,t;
    printf("Enter size of queue ");
    scanf("%d",&n);
    Queue q;
    q.rear = -1;
    q.front = -1;

    q.items = (int *) malloc(n * sizeof(int));
    for(i=0;i<n;i++) {
        printf("Enter number to insert ");
        scanf("%d",&t);
        enqueue(&q,t);
    }

    for(i=0;i<n-1;i++) {
        // 1 2 3
        // 1 2
        for(j=0;j<n-1-i;j++) {
            // Requeues all except last one
            t = dequeue(&q);
            enqueue(&q,t);
        } // 3 1 2
        // 2 1
        //to keep the reversed elements in place
        q.front=i+1;
        // queue -> 2 1
        // 1
        // => 3 2 1
    }

    printf("Reversed queue is: ");
    for(i=0;i<n;i++) 
        printf("%d ",q.items[i]);
}
