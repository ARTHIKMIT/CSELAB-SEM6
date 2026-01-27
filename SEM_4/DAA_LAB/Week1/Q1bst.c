/*
1) Write a program to construct a binary tree to support the following operations. 
Assume no duplicate elements while constructing the tree.
i.Given a key, perform a search in the binary search tree. If the key is found then display “key found” else insert the key in the binary search tree.
ii.Display the tree using inorder, preorder and post order traversal methods
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *lchild, *rchild;
} node;

node * createNode(int d);

int search(node *root, int data){
    if (!root)
        return 0;
    if (root->data == data){
        printf("Key found.\n");
        return 1;
    }
    if (root->data > data){
        if (root->lchild)
           return search(root->lchild, data);
        root->lchild = createNode(data);
        return 0;
    }
    else {
        if (root->rchild)
            return search(root->rchild, data);
        root->rchild = createNode(data); 
        return 0;
    }    
}

node * createNode(int d){
    node *newNode = calloc(1, sizeof(node));
    newNode->lchild = newNode->rchild = NULL;
    newNode->data = d;
    return newNode;
}

node *insert(node *root){
    int d;
    printf("Enter -1 to stop : \n");
    do {
        printf("Data : ");
        scanf("%d", &d);
        if (d!=-1)
            search(root, d);
    } while (d != -1);
}

node* createTree(){
    int temp;
    printf("Enter the root node value : ");
    scanf("%d", &temp);
    node *root = createNode(temp);
    insert(root);
    return root;
}

void Inorder(node *root){
    if (root){
        Inorder(root->lchild);
        printf("%d\n",root->data);
        Inorder(root->rchild);
    }
}

void Preorder(node *root){
    if (root){
        printf("%d\n",root->data);
        Preorder(root->lchild);
        Preorder(root->rchild);
    }
}

void Postorder(node *root){
    if (root){
        Postorder(root->lchild);
        Postorder(root->rchild);
        printf("%d\n",root->data);
    }
}
int main() {
    node *root = createTree();
    int ch;
    printf("MENU\n1.Search/insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.exit\n");
    do {
        printf("Choice : ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                insert(root);
                break;
            case 2: 
                printf("Inorder Traversal : \n");
                Inorder(root);
                break;
            case 3: 
                printf("Preorder Traversal : \n");
                Preorder(root);
                break;
            case 4: 
                printf("Postorder Traversal : \n");
                Postorder(root);
                break;    
            case 5: break;
            default : break;
        }
    } while (ch != 5);
    return 0;
}