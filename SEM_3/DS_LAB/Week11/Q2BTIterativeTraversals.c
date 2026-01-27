/*
Q2 Display the elements of Binary Tree created using iterative preorder, post-order
(Use single stack), in-order and level-order traversals.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct btree {
	char ele;
	struct btree *rchild, *lchild;
} btree;

typedef struct {
    btree * nodes[100];
    int tos;
} Stack;

void push(Stack * s, btree * x) {
    s->nodes[++(s->tos)] = x;
}

btree * pop(Stack * s) {
    return (s->nodes[(s->tos)--]);
}

typedef struct {
    btree ** nodesList;
    int front,rear;
} Queue;

void insertQ(Queue *q, btree * node) {
    if (q->front == -1)
        q->front = 0;
    q->nodesList[++(q->rear)] = node;
}

btree * deleteQ(Queue *q) {
    btree * item = (btree *) malloc(sizeof(btree));
    item = q->nodesList[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    else 
        q->front++;
    return item;
}

btree *createNode(char ele){
	btree *newNode = calloc(1, sizeof(btree));
	newNode->ele = ele;
	newNode->rchild = newNode->lchild = NULL;
	return newNode;
}
void createIterative(btree **root){
	int ch = 0;
	char dir[50], data, dummy;
	
	printf("Root Node Data : ");
	scanf("%c", &data);	
	*root = createNode(data);
	do {
		int i = 0;
		btree *temp = *root;
		printf("Direction : ");
		scanf("%s", dir);
		scanf("%c", &dummy);
		printf("Data : ");
		scanf("%c", &data);
		while (dir[i] != '\0'){
			if (dir[i] == 'R' || dir[i] == 'r'){
				if (temp->rchild == NULL)
					break;
				else temp = temp->rchild; 
			}
			if (dir[i] == 'L' || dir[i] == 'l'){
				if (temp->lchild == NULL)
					break;
				else temp = temp->lchild; 
			}
			i++;
		}	
		btree *newNode = createNode(data);
		if (dir[i] == 'R' || dir[i] == 'r')
			temp->rchild = newNode;
		else temp->lchild = newNode;
		printf("Enter -1 to Stop : ");
		scanf("%d", &ch);
	} while (ch != -1);
}

void iterPreOrder(btree ** tree) {
    btree * temp = (btree *) malloc(sizeof(btree));
    Stack s;
    s.tos = -1;
    push(&s,*tree);
    while (s.tos != -1) {
        temp = pop(&s);
        printf("%d ",temp->ele);
        if (temp->rchild != NULL)
            push(&s,temp->rchild);
        if (temp->lchild != NULL)
            push(&s,temp->lchild);
    }
}

void iterPostOrder(btree **tree) {
    Stack s;
    s.tos = -1;
    btree * temp = (btree *) malloc(sizeof(btree));
    btree * temp2 = (btree *) malloc(sizeof(btree));
    temp = *tree;
    do {
        while (temp != NULL) {
            if (temp->rchild != NULL)
                push(&s,temp->rchild);
            push(&s,temp);
            temp = temp->lchild;
        }

        temp = pop(&s);
        if ((temp->rchild != NULL) && (s.nodes[s.tos] == (temp->rchild))) {
            temp2 = pop(&s);
            push(&s,temp);
            temp = temp2;
        }   
        else {
            printf("%d ", temp->ele);
            temp = NULL;
        }
    } while(s.tos != -1);
}

void iterInOrder(btree **tree) {
    Stack s;
    s.tos = -1;
    btree * temp = (btree *) malloc(sizeof(btree));
    temp = *tree;
    do {
        if (temp != NULL) {
            push(&s,temp);
            temp = temp->lchild;
        }
        else {
            if (s.tos != -1) {
                temp = pop(&s);
                printf("%d ",temp->ele);
                temp = temp->rchild;
            }
            else 
                break;
        }
    } while(1);
}

void iterLevelOrder(btree **tree) {
    Queue q;
    q.nodesList = (btree **) malloc(20 * sizeof(btree *));
    q.front = -1;
    q.rear = -1;
    btree * temp = (btree *) malloc(sizeof(btree));
    temp = *tree;
    while (temp != NULL) {
        printf("%d ",temp->ele);
        if (temp->lchild != NULL)
            insertQ(&q,temp->lchild);
        if (temp->rchild != NULL)
            insertQ(&q,temp->rchild);
        if (q.front == -1)
            temp = NULL;
        else
            temp = deleteQ(&q);
    }
}

int main() {
    btree * tree = (btree *) malloc(sizeof(btree));
    createIterative(&tree);
    printf("Pre Order : ");
    iterPreOrder(&tree);
    printf("\nPost Order : ");
    iterPostOrder(&tree);
    printf("\nInOrder : ");
    iterInOrder(&tree);
    printf("\nLevel Order : ");
    iterLevelOrder(&tree);
}
