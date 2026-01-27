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

void insertBST(Node **tree,int x) {

    Node * temp = createNode(x);
    Node *prev = NULL, *preprev = NULL, *superpre = NULL;
    Node * current = *tree;

    while (current != NULL) {
        superpre = preprev;
        preprev = prev;
        prev = current;
        if (current->key > x)
            current = current->left;
        else
            current = current->right;
    }
    if (prev == NULL) 
        *tree = temp;
    else if (x < prev->key) 
        prev->left = temp;
    else 
        prev->right = temp;

    int balance = getBalance(preprev);

    // Left Left
    if (balance > 1 && x < preprev->left->key) {
        if(preprev == *tree) 
            *tree = rightRotate(preprev);
        else {
            preprev = rightRotate(preprev);
            superpre->left = preprev;
        }
    }

    // Right Right
    else if (balance < -1 && x > preprev->right->key) {
        if(preprev == *tree)
            *tree = leftRotate(preprev);
        else {
            preprev = leftRotate(preprev);
            superpre->right = preprev;
        }
    }
 
    // Left Right
    else if (balance > 1 && x > preprev->left->key) {
        preprev->left = leftRotate(preprev->left);
        if(preprev == *tree)
            *tree = rightRotate(preprev);
        else {
            preprev = rightRotate(preprev);
            superpre->left = preprev;
        }
    }
 
    // Right Left
    else if (balance < -1 && x < preprev->right->key) {
        preprev->right = rightRotate(preprev->right);
        if(preprev == *tree)
            *tree = leftRotate(preprev);
        else {
            preprev = leftRotate(preprev);
            superpre->right = preprev;
        }
    }    
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