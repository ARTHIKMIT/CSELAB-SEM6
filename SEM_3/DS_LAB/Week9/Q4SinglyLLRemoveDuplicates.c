/*
Q4 You're given the pointer to the head node of a sorted singly linked list, where the data
in the nodes is in ascending order. Delete as few nodes as possible so that the list does
not contain any value more than once (deleting duplicates). The given head pointer
may be null indicating that the list is empty.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int ele; 
	struct Node* next;
} Node;

void insert(Node **head, int ele){
	Node *newNode = calloc(1, sizeof(Node));
	newNode->ele = ele;
	newNode->next = NULL;
	if (*head == NULL){
		*head = newNode;
		return;
	}
	Node *i, *prev = NULL;
	for (i = *head; i->ele <= ele && i->next!=NULL; i=i->next)
		prev = i;
	if (prev == NULL && i->ele >= ele){ //before head node
		prev = *head;
		*head = newNode;
		(*head)->next = prev;
	}
	else if (i->next == NULL && i->ele<=ele ) //Afer last node
		i->next = newNode;
	else {
		prev->next = newNode; //Between 2 Nodes
		newNode->next = i;
	}
}

void deleteDuplicates(Node **head){
	if (*head == NULL){
		printf("Empty Queue!");
		return;
	}
	if ((*head)->next == NULL){
		printf("Only 1 element. ");
		return;
	}

	Node *i = *head;
	do {
		if (i->ele == i->next->ele){
			if (i->next->next != NULL)
				i->next = i->next->next;
			else i->next = NULL;
			//free(i->next);
		}
		else i = i->next;
	} while(i->next!=NULL);

	printf("Removed duplicates.");
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
		printf("\n1. Insert, 2. Delete Duplicates, 3. Display, 4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the Element:");
				scanf("%d",&ele);
				insert(&head,ele);
				break;
			case 2:
				deleteDuplicates(&head);
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