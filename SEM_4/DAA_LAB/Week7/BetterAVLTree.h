#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key;
	struct node *right, *left;
} Node;

Node *createNode(int data){
	Node *newNode = calloc(1, sizeof(Node));
	newNode->key = data;
	newNode->right = newNode->left = NULL;
	return newNode;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int height(Node * root) {
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

int getBalance(Node* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

Node* rightRotate(Node * root) {
    Node *temp, *temp2;                             //         root       --->      temp
                                                    //         /  \                 /   \          //
    temp = root->left;                              //     temp    y               x   root
    temp2 = temp->right;                            //     /   \                       /  \        //
                                                    //    x   temp2                temp2   y
    temp->right = root;
    root->left = temp2;
    
    return temp;
}

Node* leftRotate(Node * root) {
    Node *temp, *temp2;                             //        root       --->      temp
                                                    //        /  \                 /   \         //
    temp = root->right;                             //       y  temp             root   x
    temp2 = temp -> left;                           //          /  \             /  \            //
                                                    //      temp2   x           y   temp2
    temp -> left = root;
    root->right = temp2;
    
    return temp;
}

Node* insertBST(Node* root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insertBST(root->left, key);
    else if (key > root->key)
        root->right = insertBST(root->right, key);
    else
        return root; // No duplicates allowed

    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    // Right Right Case
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    // Left Right Case
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preOrder(Node* root) {
    if (root) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void InOrder(Node* root) {
    if (root) {
        InOrder(root->left);
        printf("%d ", root->key);
        InOrder(root->right);
    }
}
