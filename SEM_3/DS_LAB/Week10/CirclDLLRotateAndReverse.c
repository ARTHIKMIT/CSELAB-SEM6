#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int ele; 
    struct Node* rlink, *llink;
} Node;

void insertr(Node **head, int ele) {
    Node *newNode = calloc(1, sizeof(Node));
    newNode->ele = ele;
    
    if (*head == NULL) {
        *head = newNode;
        newNode->rlink = newNode;
        newNode->llink = newNode;
        return;
    }
    
    Node *last = (*head)->llink;
    
    newNode->rlink = *head;
    newNode->llink = last;
    last->rlink = newNode;
    (*head)->llink = newNode;
}

void display(Node **head) {
    printf("List : ");
    if (*head == NULL) {
        printf("Empty\n");
        return;
    }
    
    Node *current = *head;
    do {
        printf("%d ", current->ele);
        current = current->rlink;
    } while (current != *head);
    printf("\n");
}

void rev(Node **head) {
    if (*head == NULL) return;
    
    Node *current = *head;
    Node *temp;
    do {
        // Swap links for current node
        temp = current->rlink;
        current->rlink = current->llink;
        current->llink = temp;
        
        // Move to next node (which is now pointed by llink due to swap)
        current = current->llink;
    } while (current != *head);
    
    // Move head one step back (as links are reversed)
    *head = (*head)->rlink;
}

void shift(Node **head, int k) {
    if (*head == NULL || k <= 0) {
        return;
    }
    
    if ((*head)->rlink == *head) {
        return;
    }
    
    Node *current = *head;
    int length = 1;
    while (current->rlink != *head) {
        length++;
        current = current->rlink;
    }
    
    k = k % length;
    if (k == 0) return; 
    
    // Shift the head pointer k positions forward
    current = *head;
    for (int i = 0; i < k; i++) {
        current = current->rlink;
    }
    *head = current;
}

int main() {
    Node *head = NULL;
    int ch, ele;
    printf("1. Insert Rear\n2. Reverse\n3. Display\n4. Shift\n5. Exit\n");
    do {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Enter the Element: ");
                scanf("%d", &ele);
                insertr(&head, ele);
                break;
            case 2: 
                rev(&head);
                break;
            case 3: 
                display(&head);
                break;
            case 4:
                printf("Enter k: ");
                scanf("%d", &ele);
                shift(&head, ele);
                break;
            case 5: 
                break;
            default: 
                printf("Wrong choice.\n");
        }
    } while(ch != 5);
    return 0;
}
