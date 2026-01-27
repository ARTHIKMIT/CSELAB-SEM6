/* Q1 Implement a menu driven program to define a stack of characters. 
Include push, pop and display functions. Also include functions for checking error conditionssuch
as underflow and overflow (ref. figure 1) by defining isEmpty and isFull functions.
Use these function in push, pop and display functions appropriately. Use type defined
structure to define a STACK containing a character array and an integer top. Do not
use global variables. */

#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct
{
	char element;
}Stack;

bool IsFull(int *tos, int n)
{
	if (*tos==n-1)
		return true;
	else return false;
}

bool IsEmpty(int *tos)
{
	if (*tos==-1)
		return true;
	else return false;
}

void Push(Stack *s, int *tos, int n, char element)
{
	if (IsFull(tos, n))
		printf("Cannot push. Stack is Full. Overflow.");
	else s[++(*tos)].element = element;
}

char Pop(Stack *s, int *tos)
{
	if (IsEmpty(tos))
	{
		printf("Cannot Pop. Stack is Empty. Underflow.");
		return '\0';
	}
	else return s[(*tos)--].element;
}

void main()
{
	Stack *s;
	int tos = -1, n;

	printf("Stack size : ");
	scanf("%d",&n);
	s = calloc(n,sizeof(Stack));
	
	for (int i = 0; i<n; i++)
	{
		char element;
		scanf("\n%c",&element);
		Push(s, &tos, n, element);
	}

	printf("\nCurrent Stack : \n");
	for (int i = 0; i<=tos; i++)
		printf("%c\n",s[i].element);
	printf("TOP OF STACK %d\n", tos);

	printf("\nUpon popping : ");
	char element = Pop(s, &tos);
	
	printf("\nElement popped : %c\n", element);
	for (int i = 0; i<=tos; i++)
		printf("%c\n",s[i].element);
	printf("TOP OF STACK %d\n", tos);

}