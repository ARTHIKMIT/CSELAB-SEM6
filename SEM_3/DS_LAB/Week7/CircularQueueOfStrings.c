/*Implement a circular queue of Strings using structures. Include functions insertcq,
deletecq and displaycq.*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define size 10

// Empty -> f, r = -1
// Full -> f-1 = r


typedef struct {
    char str[10];
} String;

typedef struct {
    String s[size];
    int front,rear;
} Queue;

bool isFull(Queue q) {
    if ((q.front == q.rear + 1) || (q.front == 0 && q.rear == size - 1)) 
        return true;
    return false;
}

bool isEmpty(Queue q) {
    if (q.front == -1) 
        return true;
    return false;
}

void insertcq(Queue * q,char string[10]) {
    if(isFull(*q)) {
        printf("Error. Queue is full");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear = (q->rear + 1) % size;
    strcpy((q->s[q->rear]).str,string);
}

void deletecq(Queue * q) {
    if(isEmpty(*q)) {
        printf("Error. Queue is empty");
        return;
    }
    char string[10];
    strcpy(string,(q->s[q->front]).str);
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    else 
        q->front = (q->front + 1) % size;
    printf("Deleted string: %s",string);
}

void displaycq(Queue q) {
    int i;
    if(isEmpty(q)) {
        printf("Empty queue");
        return;
    }
    printf("\nThe Queue is:\n");
    for(i=q.front;i<=q.rear;i=(i+1)%size)
        printf("%s ",q.s[i].str);
    //printf("%s",q.s[i].str);
}

int main(){
	int inp;
    char temp[10];
    Queue q;
    q.front = -1;
    q.rear = -1;
    printf("\n1. Insert, 2. Delete, 3. Display, 4. Exit");
    do {
        printf("\nEnter choice. ");
        scanf("%d",&inp);
        switch(inp){
            case 1:
				printf("Enter string to insert ");
                scanf("%s",temp);
                insertcq(&q,temp);
				break;
			case 2:
				deletecq(&q);
				break;
			case 3:
				displaycq(q);
				break;
			case 4:
				inp=-1;
				break;
			default:
				printf("\nWrong choice!!! Try Again.\n");
        }
    } while(inp != -1);
}
