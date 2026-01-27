/*
1) Write a program to create the AVL tree by iterative insertion.
*/

#include "AVLTree.h"

int main() {
    int n,i,x;
    Node * tree = (Node *) malloc(sizeof(Node));
    tree = NULL;
    printf("Enter number of elements ");
    scanf("%d",&n);
    printf("Enter elements:\n");
    for (i=0;i<n;i++) {
        printf("Enter element ");
        scanf("%d",&x);
        insertBST(&tree,x);
    }
    printf("Inorder traversal: ");
    InOrder(tree);
}