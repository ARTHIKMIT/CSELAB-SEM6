#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int coeff, exp;
    struct node *next;
} Node;

void insertNode(Node *prev, int coeff, int exp) {
    Node *newNode = calloc(1, sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = prev->next;
    prev->next = newNode;
}

void inputCirc(Node **list, int n) {
    Node *head = calloc(1, sizeof(Node)); // Header node
    head->next = head; // Initialize circular link
    *list = head;

    for (int i = 0; i < n; i++) {
        int coeff, exp;
        printf("Enter Coefficient: ");
        scanf("%d", &coeff);
        printf("Enter Exponent: ");
        scanf("%d", &exp);
        insertNode(head, coeff, exp); // Insert after the header
        head = head->next; // Move head to the new node
    }
}

void displayCirc(Node *list) {
    Node *temp = list->next;
    printf("The expression is: ");
    while (temp != list) {
        printf("(%dx^%d) ", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp != list) printf("+ ");
    }
    printf("\n");
}

int getCoeff(Node *list, int exp) {
    Node *temp = list->next;
    while (temp != list) {
        if (temp->exp == exp) {
            return temp->coeff;
        }
        temp = temp->next;
    }
    return 0; // Coefficient is 0 if exponent not found
}

void sub(Node *list1, Node *list2, Node **list3) {
    Node *head3 = calloc(1, sizeof(Node)); // Header for result list
    head3->next = head3; // Initialize circular link
    *list3 = head3;

    Node *iter1 = list1->next;

    // Subtract terms from list1
    while (iter1 != list1) {
        int coeff2 = getCoeff(list2, iter1->exp);
        int newCoeff = iter1->coeff - coeff2;
        if (newCoeff != 0) {
            insertNode(head3, newCoeff, iter1->exp);
            head3 = head3->next; // Move head to the new node
        }
        iter1 = iter1->next;
    }

    // Handle remaining terms from list2 not in list1
    Node *iter2 = list2->next;
    while (iter2 != list2) {
        int coeff1 = getCoeff(*list3, iter2->exp);
        if (coeff1 == 0) {
            insertNode(head3, -iter2->coeff, iter2->exp);
            head3 = head3->next; // Move head to the new node
        }
        iter2 = iter2->next;
    }
}

void mult(Node *list1, Node *list2, Node **list4) {
    Node *head4 = calloc(1, sizeof(Node)); // Header for result list
    head4->next = head4; // Initialize circular link
    *list4 = head4;

    Node *iter1 = list1->next;
    while (iter1 != list1) {
        Node *iter2 = list2->next;
        while (iter2 != list2) {
            int newCoeff = iter1->coeff * iter2->coeff;
            int newExp = iter1->exp + iter2->exp;

            // Combine like terms
            int existingCoeff = getCoeff(head4, newExp);
            if (existingCoeff != 0) {
                // Update the coefficient
                existingCoeff += newCoeff;
                // Remove the existing node
                Node *temp = head4->next;
                Node *prev = head4;
                while (temp != head4) {
                    if (temp->exp == newExp) {
                        prev->next = temp->next; // Remove it
                        free(temp);
                        break;
                    }
                    prev = temp;
                    temp = temp->next;
                }
                newCoeff = existingCoeff; // Set new coefficient
            }

            insertNode(head4, newCoeff, newExp); // Add the term
            head4 = head4->next; // Move head to the new node
            iter2 = iter2->next;
        }
        iter1 = iter1->next;
    }
}

int main() {
    int n1, n2;
    Node *list1 = NULL, *list2 = NULL, *list3 = NULL, *list4 = NULL;

    printf("Enter number of terms in the first polynomial: ");
    scanf("%d", &n1);
    inputCirc(&list1, n1);
    displayCirc(list1);

    printf("Enter number of terms in the second polynomial: ");
    scanf("%d", &n2);
    inputCirc(&list2, n2);
    displayCirc(list2);

    printf("Expression after subtraction: ");
    sub(list1, list2, &list3);
    displayCirc(list3);

    printf("Expression after multiplication: ");
    mult(list1, list2, &list4);
    displayCirc(list4);

    return 0;
}
