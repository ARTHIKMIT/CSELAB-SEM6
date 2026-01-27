/* Q3 Determine whether a given string is palindrome or not using stack..*/

#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<string.h>

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
	int tos = -1;

	char str[20];
	printf("Enter the Stirng to be checked : ");
	scanf("%s",str);
	
	int n = strlen(str)/2;
	
	s = calloc(n,sizeof(Stack));
	
	bool flag = true;
	for (int i =0; i<strlen(str); i++)
	{
		if ((i==n/2+1) & (strlen(str)%2 == 1))
			continue;
		if (i < n)
			Push(s, &tos, n, str[i]);
		else
		{
			if (Pop(s, &tos) != str[i])
			{
				printf("Not a Palindrome.");
				flag = false;
				break;
			}
		}
	}
	if (flag)
		printf("Is a Palindrome");
}