/*
Q2 Implement a queue of strings using an output restricted dequeue (no deleteRight).
Note: An output-restricted deque is one where insertion can be made at both ends,
but deletion can be made from one end only, where as An input-restricted deque is
one where deletion can be made from both ends, but insertion can be made at one
end only.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
	char **Data;
	int front;
	int rear;
	int size;
} Queue;


void insertr(Queue *q, char *str){
	if(q->rear==q->front-1)
		printf("Queue is Full");
	else{
		q->Data[(++q->rear)] = (char*) calloc (strlen(str),sizeof(char));
		strcpy(q->Data[(q->rear)], str);
		if(q->front==-1)
			q->front=0;
	}
}

void insertf(Queue *q, char *str){
	if(q->front==0)
		printf("Queue is Full");
	else{
		if(q->front==-1){
			q->front=1; //To make front 0
			q->rear = 0; 
		}

		q->Data[(--q->front)] = calloc (strlen(str),sizeof(char));
		strcpy(q->Data[(q->front)], str);
	}
}

void delete(Queue *q, char *str){
	if(q->front==-1){
		printf("Empty Queue. ");
		str = '\0';
		//strcpy(str, '\0');
	}
	else if(q->front==q->rear){
		strcpy(str, q->Data[(q->front)]);
		q->front=q->rear=-1;
	}
	else strcpy(str, q->Data[(q->front++)]);
}

void display(Queue q){
	int i;
	if(q.front==-1)
		printf("Empty Queue. ");
	else{
		printf("\nQueue is:\n");
		for(i=q.front;i<=q.rear;i++)
			printf("%s ",q.Data[i]);
	}
}

int main(){
	int ch, n;
	printf("Enter Size : ");
	scanf("%d", &n);
	Queue q;
	q.front=-1;
	q.rear=-1;
	q.size = n;
	q.Data = (char **)malloc(n*sizeof(char *));
	char str[20];
	printf("1. Insert Rear, 2. Insert Front, 3. Delete, 4. Display, 5. Exit\n");
	do {
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the Element:");
				scanf("%s",str);
				insertr(&q,str);
				break;
			case 2:
				printf("\nEnter the Element:");
				scanf("%s",str);
				insertf(&q,str);
				break;
			case 3:
				delete(&q, str);
				printf("\nRemoved %s from the Queue\n",str);
				break;
			case 4:
				display(q);
				break;
			case 5:
				break;
			default:
				printf("\nWrong choice!!! Try Again.\n");
		}
	} while(ch!=5);
	return 0;
}