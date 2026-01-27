/*
Q4 Implement recursive functions to do the following:
a) To create a copy of a BT.
b) Testing for equality of two BTs.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct btree {
	char data;
	struct btree *rchild, *lchild;
} btree;

btree *createNode(char data){
	btree *newNode = calloc(1, sizeof(btree));
	newNode->data = data;
	newNode->rchild = newNode->lchild = NULL;
	return newNode;
}

btree *createRecursive(char data){
	char dummy;
	if (data!='#'){
		btree *newNode = createNode(data);	
		printf("L Child Data : ");
		scanf("%c", &dummy);
		scanf("%c", &data);
		newNode->lchild = createRecursive(data);
		printf("R Child Data : ");
		scanf("%c", &dummy);
		scanf("%c", &data);
		newNode->rchild = createRecursive(data);
		return newNode;
	} 
	return NULL;
}

btree * copy(btree *root){
	btree *temp;
	if (root == NULL)
		return NULL;
	temp = createNode(root->data);
	temp->lchild = copy(root->lchild);
	temp->rchild = copy(root->rchild);
	return temp;
}

int isEqual(btree *A, btree *B){
	return((!A&&!B)||(A&&B&&(A->data==B->data)&&isEqual(A->lchild, B->lchild)&&isEqual(A->rchild, B->rchild)));
}

void inorder(btree *root){
	if(root){
		inorder(root->lchild);
		printf("%c ", root->data);
		inorder(root->rchild);
	}
}

int main(){
	char data;
	printf("Root Node Data : ");
	scanf("%c",&data);
	btree *root = createRecursive(data);
	printf("Inorder : ");
	inorder(root);
	printf("\n");
	btree *rootCopy = copy(root);
	if (isEqual(root, rootCopy))
		printf("Successful.");
	return 0;
}