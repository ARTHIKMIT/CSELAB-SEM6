/* Q2 Convert a given decimal number to binary using stack.*/

#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct
{
	int element;
}Stack;

bool IsFull(int tos, int n)
{
	if (tos==n-1)
		return true;
	else return false;
}

bool IsEmpty(int tos)
{
	if (tos==-1)
		return true;
	else return false;
}

void Push(Stack *s, int *tos, int n, int element)
{
	if (IsFull(*tos, n))
		printf("Cannot push. Stack is Full. Overflow.");
	else s[++(*tos)].element = element;
}

int Pop(Stack *s, int *tos)
{
	if (IsEmpty(*tos))
	{
		printf("Cannot Pop. Stack is Empty. Underflow.");
		return -1;
	}
	else return s[(*tos)--].element;
}

void main()
{
	Stack *s;
	int tos = -1, n=50;

	int dec;
	printf("Enter the Decimal number to be converted : ");
	scanf("%d",&dec);

	s = calloc(n,sizeof(Stack));
	
	int num = dec;
	while (num>0)
	{
		Push(s, &tos, n, num%2);
		num = num/2;
	}

	printf("TOP OF STACK %d\n", tos);

	printf("\nThe Binary conversion is : \n");
	int temp = tos;
	for (int i = 0; i<=temp; i++)
	{
		printf("%d",Pop(s, &tos));
	}
}
