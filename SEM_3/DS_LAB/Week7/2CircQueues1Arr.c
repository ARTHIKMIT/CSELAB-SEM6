
// Circular Queue
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define HalfSize 10

typedef struct{
    int * items;
    int front1, front2, rear1, rear2;
}Queue;

bool isEmpty1(Queue q) {
    if (q.front1==-1)
        return true;
    else return false;
}

bool isFull1(Queue q){
    if ((q.front1 == q.rear1 + 1) || (q.front1 == 0 && q.rear1 == HalfSize - 1)) 
        return true;
    else return false;
}

bool isEmpty2(Queue q) {
    if (q.front2 == HalfSize - 1)
        return true;
    else return false;
}

bool isFull2(Queue q){
    if ((q.front2 == q.rear2 + 1) || (q.front2 == HalfSize && q.rear2 == (HalfSize* 2) - 1)) 
        return true;
    else return false;
}

void insertcq1(Queue * q,int x) {
    if(isFull1(*q)) {
        printf("Error. Queue is full");
        return;
    }
    if (q->front1 == -1)
        q->front1 = 0;
    q->rear1 = (q->rear1 + 1) % HalfSize;
    q->items[q->rear1] = x;
}

void insertcq2(Queue * q,int x) {
    if(isFull2(*q)) {
        printf("Error. Queue is full");
        return;
    }
    if (q->front2 == HalfSize-1)
        q->front2 = HalfSize;
    q->rear2 = ((q->rear2 + 1) % HalfSize)+HalfSize;
    q->items[q->rear2] = x;
}

int deletecq1(Queue * q) {
    if(isEmpty1(*q)) {
        printf("Error. Queue is empty");
        return -5;
    }
    int item = q->items[q->front1];
    if (q->front1 == q->rear1) {
        q->front1 = -1;
        q->rear1 = -1;
    }
    else 
        q->front1 = (q->front1 + 1) % HalfSize;
    return item;
}

int deletecq2(Queue * q) {
    if(isEmpty2(*q)) {
        printf("Error. Queue is empty");
        return -5;
    }
    int item = q->items[q->front2];
    if (q->front2 == q->rear2) {
        q->front2 = HalfSize-1;
        q->rear2 = HalfSize-1;
    }
    else
        q->front2 = ((q->front2 + 1) % HalfSize) + HalfSize;
    return item;
}

void displaycq(Queue q) {
    int i;
    printf("\nQueue 1: ");
    if(isEmpty1(q)) {
        printf("Empty queue");
    }
    else {

        for(i=q.front1;i!=q.rear1;i=(i+1)%HalfSize) {
            printf("%d ",q.items[i]);
        }
        printf("%d",q.items[i]);
    }
    printf("\nQueue 2: ");
    if(isEmpty2(q)) {
        printf("Empty queue");
    }
    else {

        for(i=q.front2;i!=q.rear2;i=((i+1)%(HalfSize * 2))+HalfSize) {
            printf("%d ",q.items[i]);
        }
        printf("%d",q.items[i]);
    }
}

int main() {
    int temp,ch;
    Queue q;
    q.items = (int *) malloc(2*HalfSize*sizeof(int));
    q.front1 = -1;
    q.rear1 = -1;
    q.front2 = HalfSize - 1;
    q.rear2 = HalfSize - 1;
    printf("\n1. Insert1, 2. Insert2, 3. Delete1, 4. Delete2, 5. Display, 6. Exit");
    do {
        printf("\nEnter choice. ");
        scanf("%d",&ch);
        switch(ch){
            case 1: 
                printf("Enter number to insert ");
                scanf("%d",&temp);
                insertcq1(&q,temp);
                break;
            case 2:
                printf("Enter number to insert ");
                scanf("%d",&temp);
                insertcq2(&q,temp);
                break;
            case 3:
                printf("Element deleted is: %d",deletecq1(&q));
                break;
            case 4:
                printf("Element deleted is: %d",deletecq2(&q));
                break;
            case 5:
                displaycq(q);
                break;
        }
    } while(ch!=6);
}
