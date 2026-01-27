//To check whether a given String is Palindrome or not, using Recursion
#include <stdio.h>
#include<string.h>

void isPalindrome(char a[], int n)
{
	int static i = 0;
	if (i>(n-i-1))
	{
		printf("Is a Palindrome. ");
		return;
	}

	if (a[i] != a[n-1-i])
	{
		printf("Not a Palindrome. ");
		return;
	}

	else 
	{
		i++;
		isPalindrome(a, n);
	}
}

void main()
{
	char a[10], b[10];
	printf("Enter the string :\n");
	scanf("%s", a);
	int n = strlen(a);
	isPalindrome(a, n);
	puts(b);
}