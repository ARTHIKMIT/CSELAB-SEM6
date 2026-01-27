/* Q1 Evaluate a given prefix expression using stack.*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct
{
	char element;
}Stack;

bool IsFull(int *tos, int n){
	if (*tos==n-1)
		return true;
	else return false;
}

bool IsEmpty(int *tos){
	if (*tos==-1)
		return true;
	else return false;
}

void Push(Stack *s, int *tos, int n, char element){
	if (IsFull(tos, n))
		printf("Cannot push. Stack is Full. Overflow.");
	else s[++(*tos)].element = element;
}

char Pop(Stack *s, int *tos){
	if (IsEmpty(tos))
	{
		printf("Cannot Pop. Stack is Empty. Underflow.");
		return '\0';
	}
	else return s[(*tos)--].element;
}


bool isDigit(char a){
	if (a < '9' && a >'0')
		return true;
	else return false;
}

int evaluate(char x,int op1,int op2){
	if(x=='+')
		return(op1+op2);
	if(x=='-')
		return(op1-op2);
	if(x=='*')
		return(op1*op2);
	if(x=='/')
		return(op1/op2);
	if(x=='%')
		return(op1%op2);
	return '\0';
}

void main(){
	Stack *s;
	int tos = -1, n;
	char preFix[50];

	printf("Prefix expression : ");
	scanf("%s",preFix);

	n = strlen(preFix);
	s = calloc(n,sizeof(Stack));
	
	for (int i = n-1; i>=0; i--){
		if (isDigit(preFix[i]))
			Push(s, &tos, n, preFix[i]-'0');
		else{
			int op1 = Pop(s, &tos);
			int op2 = Pop(s, &tos);
			int res = evaluate(preFix[i], op1, op2);
			Push(s, &tos, n, res);
		}
	}
	//-+8/632 = 8
	int result = Pop(s, &tos);
	printf(" Final : %d ", result);
}