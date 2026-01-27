/* Q4 Given an array arr with n elements and a number k, k<n. 
The task is to delete k elements which are smaller than next element 
(i.e., we delete arr[i] if arr[i] < arr[i+1]) or become smaller than next because next element is deleted. 
Example:
Input: arr[] = {20, 10, 25, 30, 40}, k = 2
Output: 25 30 40.*/

#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct
{
	int element;
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

void Push(Stack *s, int *tos, int n, int element)
{
	if (IsFull(tos, n))
		printf("Cannot push. Stack is Full. Overflow.");
	else s[++(*tos)].element = element;
}

int Pop(Stack *s, int *tos)
{
	if (IsEmpty(tos))
	{
		printf("Cannot Pop. Stack is Empty. Underflow.");
		return '\0';
	}
	else return s[(*tos)--].element;
}

int Peek(Stack *s, int *tos)
{
	if (IsEmpty(tos))
	{
		printf("Cannot Peek. Stack is Empty.");
		return '\0';
	}
	else return s[(*tos)].element;
}

void main()
{
	Stack *s;
	int tos = -1, n, k;


	printf("Stack size : ");
	scanf("%d",&n);
	s = calloc(n,sizeof(Stack));
	
	printf("k : ");
	scanf("%d",&k);

	for (int i = 0; i<n; i++)
	{
		int element;
		scanf("\n%d",&element);
		
		if (k>0 && i!=0)
		{
			if (element > Peek(s, &tos))
			{
				Pop(s, &tos);
			    k--;
			}
		}
	    Push(s, &tos, n, element);
	}
	
	for (int i = 0; i<=tos; i++)
		printf("%d\t", s[i]);
}
