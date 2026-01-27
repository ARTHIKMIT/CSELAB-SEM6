/* 
Implement a queue with two stacks without transferring the elements of the second
stack back to stack one. 
(use stack1 as an input stack and stack2 as an output stack)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *st;
    int tos, size;
} Stack;

void push(Stack *s,int x) {
    (s->st)[++(s->tos)] = x; 
}

int pop(Stack *s) {
    return s->st[(s->tos)--];
}

int main() {
    printf("Enter Size : ");
    int n, ch, t;
    scanf("%d", &n);
    Stack s1, s2;
    s1.tos = -1;
    s2.tos = -1;
    s1.st = calloc(n, sizeof(int));
    s2.st = calloc(n, sizeof(int));
    //Enqueue -> insert to queue
    printf("\n1. Enqueue, 2. Dequeue, -1. Exit\n");
    do {
        printf("\nEnter choice ");
        scanf("%d",&ch);
        if (ch == 1) {
            printf("Enter number to enqueue ");
            scanf("%d",&t);
            push(&s1,t);
        }
        else if (ch == 2) {
            if (s2.tos == -1) 
                while (s1.tos != -1) 
                    push(&s2,pop(&s1));
            if (s2.tos != -1)
                printf("Number dequeued: %d",pop(&s2));
            else
                printf("Queue is empty");
        }
        else printf("Wrong choice.");
    } while (ch != -1);
}
