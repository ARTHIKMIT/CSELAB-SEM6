/*
Q1 Implement a queue using singly linked list without header node.
*/

#include <stdio.h>
#include <stdlib.h>
//typedef struct Node *Next;
typedef struct Node {
	int ele; 
	struct Node* next;
} Node;

void enqueue(Node **head, int ele){
	Node *newNode = calloc(1, sizeof(Node));
	newNode->ele = ele;
	newNode->next = NULL;
	if (*head == NULL){
		*head = newNode;
		return;
	}
	Node *i;
	for (i = *head; i->next!=NULL; i=i->next);
	i->next = newNode;
}

int dequeue(Node **head){
	if (*head == NULL){
		printf("Empty Queue!");
		return -1;
	}
	Node *phead = *head;
	//for (i = *head; i->next!=NULL; i=i->next);
	int ele = (*head)->ele;
	if ((*head)->next == NULL)
		*head = NULL;
	else *head = (*head)->next;
	free(phead);
	return ele;
}

void display(Node **head){
	printf("Queue : ");
	if (*head == NULL){
		printf("Empty");
		return;
	}
	Node *i;
	for (i = *head; i->next!=NULL; i=i->next)
		printf("%d ",i->ele);
	printf("%d ",i->ele);
}

int main(){
	Node *head = NULL;
	int ch, ele;
	do {
		printf("\n1. Insert, 2. Delete, 3. Display, 4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the Element:");
				scanf("%d",&ele);
				enqueue(&head,ele);
				break;
			case 2:
				ele = dequeue(&head);
				printf("Removed %d from the Queue ",ele);
				break;
			case 3:
				display(&head);
				break;
			case 4:
				break;
			default:
				printf("\nWrong choice!!! Try Again.\n");
		}
	} while(ch!=4);
	return 0;
}