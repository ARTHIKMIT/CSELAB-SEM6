/*
Q1 - Write a menu driven program to do the following using iterative functions:
i. To create a BST for a given set of integer numbers
ii. To delete a given element from BST .
Note: Replace the element to be deleted with the largest element in the LST (Left
Sub Tree) ) when the node to be deleted has both LST (Left Sub Tree) and RST
(Right Sub Tree).
iii. To display the elements using in-order traversal.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct btree {
	int ele;
	struct btree *rchild, *lchild;
} btree;

btree *createNode(int ele){
	btree *newNode = calloc(1, sizeof(btree));
	newNode->ele = ele;
	newNode->rchild = newNode->lchild = NULL;
	return newNode;
}

void create(btree **root, int ele){
	if (!(*root)){
		*root = createNode(ele);
		return;
	}
	if (ele < (*root)->ele)
		create(&((*root)->lchild), ele);
	else if (ele > (*root)->ele)
		create(&((*root)->rchild), ele);
	else printf("Don't enter duplicate values!");
}

void delete(btree **root, btree **Node, int ele){
	if (!(*Node)){
		printf("Empty Tree or Value not in tree!");
		return;
	}
	if (ele < (*Node)->ele)
		delete(root,&((*Node)->lchild), ele);
	else if (ele > (*Node)->ele)
		delete(root,&((*Node)->rchild), ele);
	else {
		//Temp -> largest ele in Left subtree
		btree *prev = *root;
		btree *temp = (*root)->lchild;		
		while(temp->rchild!=NULL){
			prev = temp;
			temp = temp->rchild;
		}
		if((*root)->lchild ==NULL){
			btree *t = temp->lchild;
			temp->lchild = (*root)->lchild;
			temp->rchild = (*root)->rchild;
			free(*root);
			(*root) = temp;
			prev->rchild = t;
		}

	}
}

void inorder(btree *root){
	if(root){
		inorder(root->lchild);
		printf("%d ", root->ele);
		inorder(root->rchild);
	}
}

int main() {
	int x,ch,i;
	btree *root = NULL;
	printf(" 1. Add Node, 2. Display Tree, 3. Delete, 4.Exit\n");
	do {
		printf("Choice:");
		scanf("%d",&ch);
		switch(ch) {
			case 1:
				printf("Enter node value:\n");
				scanf("%d",&x);
				create(&root,x);
				break;
			case 2: 
				printf("indorder : ");
				inorder(root);
				printf("\n");
				break;
			case 3:
				printf("Enter value to Delete :\n");
				scanf("%d",&x);
				delete(&root, &root,x);
				break;
			case 4: break;
			default : printf("Enter a Valid Choice.");
		}
	} while(ch!=4);
	return 0;
}
