/*
Q3 Create an expression tree for the given postfix expression and evaluate it.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

btree * createNode(int x) {
    btree * new = (btree *) malloc(sizeof(btree));
    new->ele = x;
    new->lchild = NULL;
    new->rchild = NULL;
    return new;
}

double eval(char op,double x,double y) {
    if (op == '+')  return x+y;
    if (op == '-')  return x-y;
    if (op == '*')  return x*y;
    if (op == '/')  return x/y;
}

int isOperator(char x) {
    return (x == '+' || x == '-' || x == '*' || x == '/');
}

double evaluate(btree * node) {
    if (node == NULL)
        return 0;
    if (node->rchild == NULL && node->lchild == NULL)
        return (double) (node->ele -'0');

    double x = evaluate(node->lchild);
    double y = evaluate(node->rchild);

    return eval(node->ele,x,y);
}

int main() {
    Stack nodeStack;
    nodeStack.tos = -1;
    char postfix[100];
    printf("Enter postfix expression : ");
    scanf("%s",postfix);
    int i;
    for (i=0;i<strlen(postfix);i++) {
        if (!isOperator(postfix[i]))
            push(&nodeStack,createNode(postfix[i]));
        else {
            btree * root = createNode(postfix[i]);
            root->rchild = pop(&nodeStack);
            root->lchild = pop(&nodeStack);
            push(&nodeStack,root);
        }
    }

    btree * root = pop(&nodeStack);
    printf("Ans :  %lf",evaluate(root));
}

/*
btree *postfix_build(char postfix[50]){
	Stack *s = calloc(1, sizeof(stack));
	btree *temp = calloc(1, sizeof(btree));
	temp->rchild = temp->lchild = NULL;
	char symbol;
	int i = 0;
	while(symbol = postfix[i] != '\0'){
		if ((symbol>='A' && symbol<='Z')||(symbol>='a' && symbol<='z')||(symbol>='0' && symbol<='9')){
			temp->ele = symbol;
			push(s, *temp);
		}
		else {
			btree *temp1 = calloc(1, sizeof(btree));
			btree *temp2 = calloc(1, sizeof(btree));
			*temp1 = pop(s);
			*temp2 = pop(s);
			temp->rchild = temp1;
			temp->lchild = temp2;
			push(s, *temp);
		}
		i++;
	}
	btree *temp3 = calloc(1, sizeof(btree));
	*temp3 = pop(s);
	return temp3;
}
*/
