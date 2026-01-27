/*
Q3 Reverse a doubly linked list containing words in the data field.
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int ele; 
	struct Node* rlink, *llink;
} Node;

void insertr(Node **head, int ele){
	Node *newNode = calloc(1, sizeof(Node));
	newNode->ele = ele;
	newNode->rlink = newNode->llink = NULL;
	if (*head == NULL){
		*head = newNode;
		return;
	}
	Node *i;
	for (i = *head; i->rlink!=NULL; i=i->rlink);
	i->rlink = newNode;
	newNode->llink = i;
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

void rev(Node **head){	
	Node *i, *temp, *prev = *head;
	for (i = *head; i!=NULL; i=temp){
		temp = i->rlink; //The actual next node - pre rev
		i->rlink = i->llink;
		i->llink = temp;
		prev = i;
	}
	*head = prev;   
}

void shift(Node **head, int k) {
    if (head == NULL || *head == NULL || k <= 0) {
        return;
    }
    // length of the list
    Node *current = *head;
    int length = 0;
    while (current != NULL) {
        length++;
        current = current->rlink;
    }
    // Normalize k to be within list length
    k = k % length;
    if (k == 0) {
        return;
    }
    
    // Find the new head (kth node from start)
    current = *head;
    Node *prev = NULL;
    for (int i = 0; i < k && current != NULL; i++) {
        prev = current;
        current = current->rlink;
    }
    
    if (current == NULL) {
        return;  // Invalid k value
    }
    
    Node *oldHead = *head;
    
    // Find the last node
    Node *last = *head;
    while (last->rlink != NULL) {
        last = last->rlink;
    }

    if (prev != NULL) {
        prev->rlink = NULL;        // Break the link at k
        last->rlink = oldHead;     // Connect last node to old head
        oldHead->llink = last;     // Connect old head's left to last node
        current->llink = NULL;     // New head's left should be NULL
        *head = current;           // Update head to new position
    }
}

int main(){
	Node *head = NULL;
	int ch, ele;
	printf("1. Insert Rear, 2. Reverse, 3. Display, 4.Shift 5. Exit\n");
	do {
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch) {
			case 1:
				printf("Enter the Element:");
				scanf("%d",&ele);
				insertr(&head,ele);
				break;
			case 2: rev(&head); break;
			case 3: display(&head); break;
			case 4: 
			    printf("Enter k:");
				scanf("%d",&ele);
				shift(&head, ele);
			case 5: break;
			default: printf("Wrong choice.");
		}
	} while(ch!=5);
	return 0;
}
