/*
Q1 Write a menu driven program to implement doubly linked list without header node
to insert into and delete from both the sides.
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int ele; 
	struct Node* rlink, *llink;
} Node;

Node *createNode (int ele){
	Node *newNode = calloc(1, sizeof(Node));
	newNode->ele = ele;
	newNode->rlink = newNode->llink = NULL;
	return newNode;
}

void insertr(Node **head, int ele){
	Node *newNode = createNode(ele);
	if (*head == NULL){
		*head = newNode;
		return;
	}
	Node *i;
	for (i = *head; i->rlink!=NULL; i=i->rlink);
	i->rlink = newNode;
	newNode->llink = i;
}

void insertf(Node **head, int ele){
	Node *newNode = createNode(ele);
	if (*head == NULL){
		*head = newNode;
		return;
	}
	(*head)->llink = newNode;
	newNode->rlink = *head;
	*head = newNode;
}

int deleter(Node **head){
	if (*head == NULL){
		printf("Empty Queue!");
		return -1;
	}
	Node *i;
	for (i = *head; i->rlink!=NULL; i=i->rlink);
	int ele = i->ele;
	
	if (i->llink != NULL)
		i->llink->rlink = NULL;
	else (*head) = NULL;
	free(i);
	return ele;
}

int deletef(Node **head){
	if (*head == NULL){
		printf("Empty!");
		return -1;
	}
	int ele = (*head)->ele;
	if ((*head)->rlink != NULL){
		*head = (*head)->rlink;
		free((*head)->llink);
		(*head)->llink = NULL;	
	}
	else{
		free(*head);
		*head = NULL;
	} 
	return ele;
}

void display(Node **head){
	printf("List : ");
	if (*head == NULL){
		printf("Empty");
		return;
	}
	Node *i;
	for (i = *head; i->rlink!=NULL; i=i->rlink)
		printf("%d ",i->ele);
	printf("%d ",i->ele);
}

int main(){
	Node *head = NULL;
	int ch, ele;
	printf("1. Insert Rear, 2. Insert Front, 3. Delete Rear, 4. Delete Front, 5. Display, 6. Exit");
	do {
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the Element:");
				scanf("%d",&ele);
				insertr(&head,ele);
				break;
			case 2:
				printf("Enter the Element:");
				scanf("%d",&ele);
				insertf(&head,ele);
				break;
			case 3:
				ele = deleter(&head);
				printf("Removed %d from the Queue ",ele);
				break;
			case 4:
				ele = deletef(&head);
				printf("Removed %d from the Queue ",ele);
				break;
			case 5:
				display(&head);
				break;
			case 6:
				break;
			default:
				printf("Wrong choice.");
		}
	} while(ch!=6);
	return 0;
}