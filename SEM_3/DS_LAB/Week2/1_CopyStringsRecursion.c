//To copy one string to another using Recursion.
#include <stdio.h>

void copyStr(char a[], char b[])
{
	if (*a == '\0')
	{
		*b = '\0';
		
		return;
	}
	else 
	{
		*b = *a;
		copyStr(++a, ++b);
	}
}

void main()
{
	char a[10], b[10];
	printf("Enter the string :\n");
	scanf("%s", a);
	copyStr(a, b);
	puts(b);
}