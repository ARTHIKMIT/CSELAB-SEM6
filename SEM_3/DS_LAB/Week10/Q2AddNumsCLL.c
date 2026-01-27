/*
Q2 Add two long positive integers represented using circular doubly linked list with header node.
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int ele; 
	struct Node *rlink, *llink;
} Node;

void insertr(Node **head, int ele){
	Node *newNode = calloc(1, sizeof(Node));
	newNode->ele = ele;
	//newNode->rlink = newNode->llink = NULL;
	if ((*head)->rlink == *head){
		(*head)->rlink = newNode;
		(*head)->llink = newNode;
		newNode->llink = *head;
		newNode->rlink = *head;
		return;
	}
	Node *i;
	for (i = (*head)->rlink; i->rlink!=*head; i=i->rlink);
	i->rlink = newNode;
	newNode->llink = i;
	newNode->rlink = *head;
	(*head)->llink = newNode;
}

void displayRev(Node *head){
	printf("Reversed List : ");
	if (head == NULL){
		printf("Empty");
		return;
	}
	Node *i;
    for (i = head->llink; i!=head; i=i->llink)
		printf("%d ",i->ele);
    printf("\n");
}

int Add (Node *A, Node *B){
    Node *C = calloc(1, sizeof(Node));
	C->ele = 0;
	C->rlink = C->llink = C; 
    int sum = 0;
    Node *i, *j;
    for(i = A; i->rlink!=A; i=i->rlink);
    for(j = B; j->rlink!=B; j=j->rlink);
    while (i!=A || j!=B){
        sum = sum*10 + i->ele+j->ele;
        i = i->llink;
        j = j->llink;
    }
    return sum;
}

int main(){
	Node *A = calloc(1, sizeof(Node));
	A->ele = 0;
	A->rlink = A->llink = A; 
	Node *B = calloc(1, sizeof(Node));
	B->ele = 0;
	B->rlink = B->llink = B;
	int num1, num2, n1=0, n2=0;
	printf("Enter Numbers to Add : \n");
	printf("Number 1 : ");
	scanf("%d",&num1);
	printf("Number 2 : ");
	scanf("%d",&num2);
	for (int i = num1; i%10 != 0; i=i/10){
	    n1++;
	    insertr(&A, i%10);
	}
	for (int i = num2; i%10 != 0; i=i/10){
	    n2++;
	    insertr(&B, i%10);
	}
	while(n1 != n2){
	    if (n1>n2){
	        insertr(&B, 0);
	        n2++;
	    }
	   else {
	       insertr(&A, 0);
	       n1++;
	   }
	}
	displayRev(A);
	displayRev(B);
	int Sum = Add(A, B);
	printf("The Sum is : %d",Sum);
	return 0;
}
