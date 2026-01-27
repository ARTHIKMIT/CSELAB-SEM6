#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int exp, coeff;
    struct Node *next;
} Node;

// Insert a new node after prev (prev should not be NULL)
void insertNode(Node **prev, int coeff, int exp) {
    Node *newNode = calloc(1, sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = (*prev)->next;
    (*prev)->next = newNode;
}

// Input polynomial in the linked list
void inputList(Node **poly, int n) {
    *poly = calloc(1, sizeof(Node)); // Create a dummy header node
    (*poly)->next = NULL; // Initialize the list as empty
    Node *head = *poly;

    for (int i = 0; i < n; i++) {
        int coeff, exp;
        printf("Enter Coefficient: ");
        scanf("%d", &coeff);
        printf("Enter Exponent: ");
        scanf("%d", &exp);
        insertNode(&head, coeff, exp); // Insert after the header
        head = head->next; // Move head to the new node
    }
}

// Display the polynomial
void displayList(Node *poly) {
    printf("The expression is: ");
    Node *temp = poly->next; // Skip the header node
    while (temp) {
        printf("(%dx^%d)", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp) printf(" + ");
    }
    printf("\n");
}

// Add two polynomials
Node *add(Node *A, Node *B) {
    Node *sum = calloc(1, sizeof(Node)); // Create a dummy header for the sum
    sum->next = NULL;
    Node *head = sum;

    while (A && B) {
        if (A->exp > B->exp) {
            insertNode(&head, A->coeff, A->exp);
            A = A->next;
        } else if (A->exp < B->exp) {
            insertNode(&head, B->coeff, B->exp);
            B = B->next;
        } else {
            int s = A->coeff + B->coeff;
            if (s != 0) insertNode(&head, s, A->exp);
            A = A->next;
            B = B->next;
        }
    }

    while (A) {
        insertNode(&head, A->coeff, A->exp);
        A = A->next;
    }

    while (B) {
        insertNode(&head, B->coeff, B->exp);
        B = B->next;
    }

    return sum; // Return the result starting from sum->next
}

// Subtract two polynomials
Node *subtract(Node *A, Node *B) {
    Node *difference = calloc(1, sizeof(Node)); // Create a dummy header for the difference
    difference->next = NULL;
    Node *head = difference;

    while (A && B) {
        if (A->exp > B->exp) {
            insertNode(&head, A->coeff, A->exp);
            A = A->next;
        } else if (A->exp < B->exp) {
            insertNode(&head, -B->coeff, B->exp); // Subtract B's coefficient
            B = B->next;
        } else {
            int d = A->coeff - B->coeff;
            if (d != 0) insertNode(&head, d, A->exp);
            A = A->next;
            B = B->next;
        }
    }

    while (A) {
        insertNode(&head, A->coeff, A->exp);
        A = A->next;
    }

    while (B) {
        insertNode(&head, -B->coeff, B->exp); // Subtract remaining B terms
        B = B->next;
    }

    return difference; // Return the result starting from difference->next
}

Node *multiply(Node *A, Node *B) {
    Node *product = calloc(1, sizeof(Node)); // Create a dummy header for the product
    product->next = NULL;
    Node *head = product;
    
    // Traverse both polynomials
    Node *tempA = A->next; // Skip the header node of A
    while (tempA) {
        Node *tempB = B->next; // Skip the header node of B
        while (tempB) {
            // Multiply the terms and insert into the product list
            int coeff = tempA->coeff * tempB->coeff;
            int exp = tempA->exp + tempB->exp;
            // Insert the term into the product list, combining like terms
            Node *prodTemp = product->next;
            int termAdded = 0;
            while (prodTemp) {
                if (prodTemp->exp == exp) {
                    // Combine the terms with the same exponent
                    prodTemp->coeff += coeff;
                    termAdded = 1;
                    break;
                }
                prodTemp = prodTemp->next;
            }
            if (!termAdded)
                // If no like term is found, insert a new term
                insertNode(&head, coeff, exp);

            tempB = tempB->next;
        }
        tempA = tempA->next;
    }
    return product; // Return the result starting from product->next
}


// Free the polynomial list
void freeList(Node *poly) {
    Node *temp;
    while (poly) {
        temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main() {
    int n1, n2;
    Node *A = NULL, *B = NULL;

    printf("Enter number of terms in the first polynomial: ");
    scanf("%d", &n1);
    inputList(&A, n1);
    displayList(A);

    printf("Enter number of terms in the second polynomial: ");
    scanf("%d", &n2);
    inputList(&B, n2);
    displayList(B);

    printf("Expression after Addition: ");
    Node *C = add(A, B);
    displayList(C);

    printf("Expression after Subtraction: ");
    Node *D = subtract(A, B);
    displayList(D);
    
    printf("Expression after Multiplication: ");
    Node *E = multiply(A, B);
    displayList(E);

    // Free memory used by the polynomials
    freeList(A);
    freeList(B);
    freeList(C);
    freeList(D);
    freeList(E);

    return 0;
}
