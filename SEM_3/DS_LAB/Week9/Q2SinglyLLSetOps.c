/*
Q2 Perform UNION and INTERSECTION set operations on singly linked lists with
and without header node.
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


int delete(Node **head){
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

Node * Union(Node **h1, Node **h2){
	Node *t1 = *h1, *t2 = *h2;
	Node *u = NULL;
	while (t1->next!=NULL && t2->next!=NULL){
		if (t1->ele == u->ele){
			t1 = t1->next;
			continue;
		}
		if (t2->ele == u->ele){
			t2 = t2->next;
			continue;
		}
		if (t1->ele > t2->ele){
			insert(&u, t2->ele);
			t2 = t2->next;
		}
		if (t1->ele < t2->ele){
			insert(&u, t1->ele);
			t1=t1->next;
		}
		if (t1->ele == t2->ele){
			insert(&u, t1->ele);
			t1 = t1->next;
			t2 = t2->next;
		}
	}
	while (t1->next != NULL){
		if (t1->ele == u->ele){
			t1 = t1->next;
			continue;
		}
		insert(&u,t1->ele);
	}
	while (t2->next != NULL){
		if (t2->ele == u->ele){
			t2 = t2->next;
			continue;
		}
		insert(&u,t2->ele);
	}
	return u;
}

int main(){
	int n1, n2, ele;
	
	Node *l1 = NULL;
	printf("Enter the number of elements in list 1 : ");
	scanf("%d",&n1);
	for(int i=0; i<n1; i++){
		scanf("%d",&ele);
		insert(&l1,ele);
	}

	Node *l2 = NULL;
	printf("Enter the number of elements in list 2 : ");
	scanf("%d",&n2);
	for(int i=0; i<n2; i++){
		scanf("%d",&ele);
		insert(&l2,ele);
	}

	Node *u = Union(&l1 ,&l2);
	display(&u);
	return 0;
}