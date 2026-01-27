/*
2). Write a C program to find Closest Common Ancestor (CCA) in a Binary Tree. 
The CCA of n1 and n2 in T is the shared ancestor of n1 and n2 that is located farthest from the root 
[i.e., closest to n1 and n2].    
For Example: Consider the following BT
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Node* findCCA(Node* root, int n1, int n2) {
    // Base case: if root is NULL or root is one of the nodes
    if (root == NULL || root->data == n1 || root->data == n2)
        return root;

    Node* left = findCCA(root->left, n1, n2);
    Node* right = findCCA(root->right, n1, n2);

    if (left != NULL && right != NULL)
        return root;

    return (left != NULL) ? left : right;
}

void printCCA(Node* root, int n1, int n2) {
    Node* ancestor = findCCA(root, n1, n2);
    if (ancestor != NULL)
        printf("The Closest Common Ancestor of %d and %d is %d\n", n1, n2, ancestor->data);
    else
        printf("No Common Ancestor found.\n");
}

int main() {
    Node* root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right->right = newNode(25);

    int n1 = 10, n2 = 14;
    printCCA(root, n1, n2);  // Output: The Closest Common Ancestor of 10 and 14 is 12

    n1 = 4, n2 = 14;
    printCCA(root, n1, n2);  // Output: The Closest Common Ancestor of 4 and 14 is 8

    n1 = 8, n2 = 25;
    printCCA(root, n1, n2);  // Output: The Closest Common Ancestor of 8 and 25 is 20

    return 0;
}
