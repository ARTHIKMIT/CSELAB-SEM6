// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

#define MAX 3

typedef struct stack *SPTR;

struct stack {
    int ele;
    SPTR link;
};

#define isEmpty(SPTR) (!(SPTR))
#define isFull(SPTR) (!(SPTR))

void push(int d,SPTR *top){
    SPTR newnode;
    newnode = calloc(1,sizeof(struct stack));
    if (isFull(newnode)){
        printf("Stack is Full. ");
        return;
    }
    if (*top == NULL) {
        newnode->link = NULL;
        newnode->ele = d;
        *top = newnode;
    }
}

void pop(SPTR *top){
    if (isEmpty(*top)){
        printf("Bye. Empty stack lol. ");
        return;
    }
    SPTR temp = *top;
    *top = temp->link;
    int ele = temp->ele;
    free(temp);
    printf("Deleted item : %d",ele);
}

int main() {
    // Write C code here
    SPTR top[MAX];
    int x, ch, i, n;
    
    printf("1. Push, 2. Pop, 3. Display, 4. Exit\n");
	do {
		
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the Stack number :");
				scanf("%d", &n);
				if (n>3) {
				    printf("Piss off.");
				    break;
		        }
				printf("Enter the Element:");
				scanf("%d",&x);
				push(x, &top[n]);
				break;
			case 2:
			    printf("Enter the Stack number :");
				scanf("%d", &n);
				if (n>3) {
				    printf("Piss off.");
				    break;
		        }
				pop(&top[n]);
				printf("\nRemoved %d from the Queue\n",x);
				break;
			case 3:
				for (int i=0; i<MAX; i++){
				    SPTR temp;
				    for (temp=top[i]; temp!=NULL; temp=temp->link)
				        printf("%d ", temp->ele);
				    printf("\n");
				}
				break;
			case 4:
				break;
			default:
				printf("\nWrong choice!!! Try Again.\n");
		}
	} while (ch!=4);

    return 0;
}
