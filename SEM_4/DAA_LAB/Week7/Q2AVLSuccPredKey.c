/*
Q2) Using the AVL created in question 1, 
display the successor (next greater key) and predecessor (next smaller key) of a given key.
*/

#include "AVLTree.h"

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

Node* maxValueNode(Node* node) {
    Node* current = node;
    while (current && current->right != NULL)
        current = current->right;
    return current;
}

Node* findSuccessor(Node* root, int key) {
    Node* current = root;
    Node* successor = NULL;

    // Find the node with the given key
    while (current != NULL && current->key != key) {
        if (key < current->key) {
            successor = current;
            current = current->left;
        } else current = current->right;
    }

    // If the node has a right child, the successor is the minimum node in the right subtree
    if (current && current->right)
        return minValueNode(current->right);

    return successor;
}

Node* findPredecessor(Node* root, int key) {
    Node* current = root;
    Node* predecessor = NULL;

    // Find the node with the given key
    while (current != NULL && current->key != key) {
        if (key > current->key) {
            predecessor = current;
            current = current->right;
        } else current = current->left;
    }

    // If the node has a left child, the predecessor is the maximum node in the left subtree
    if (current && current->left)
        return maxValueNode(current->left);

    return predecessor;
}

int main() {
    int n,x, key;
    
    Node *tree = calloc(1, sizeof(Node));
    tree = NULL;
    
    printf("Enter number of elements : ");
    scanf("%d",&n);

    printf("Enter elements:\n");
    for (int i=0;i<n;i++) {
        printf("Enter element ");
        scanf("%d",&x);
        insertBST(&tree,x);
    }
    
    printf("Inorder traversal: ");
    InOrder(tree);

    printf("Enter key : ");
    scanf("%d",&key);

    Node* successor = findSuccessor(tree, key);
    Node* predecessor = findPredecessor(tree, key);

    printf("\nSuccessor of %d: %d\n", key, successor ? successor->key : -1);
    printf("Predecessor of %d: %d\n", key, predecessor ? predecessor->key : -1);

    return 0;
}