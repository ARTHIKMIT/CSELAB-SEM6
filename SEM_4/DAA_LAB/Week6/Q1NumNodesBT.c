  /*
1) Find total number of nodes in a binary tree and analyze its efficiency. Obtain the
experimental result of order of growth and plot the result.
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

int numOfNodes(btree *root, int *opCount){
	*opCount+=1;
	if(root){
		printf("%c ", root->data);
		//*opCount+=1;
		return (1+numOfNodes(root->lchild, opCount)+numOfNodes(root->rchild, opCount)); 
	}
	return 0;
}

int main(){
	char data;
	printf("Root Node Data : ");
	scanf("%c",&data);
	btree *root = createRecursive(data);
	printf("Inorder : ");
	int opCount=0;
	int count = numOfNodes(root, &opCount);
	printf("\nNumber of nodes is %d \n", count);
	printf("It took %d operations. ", opCount);
	return 0;
}