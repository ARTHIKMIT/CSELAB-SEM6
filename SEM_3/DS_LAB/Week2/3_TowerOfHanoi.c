//Simulate the working of Tower of Hanoi for n disks. Print the number of moves.
#include<stdio.h>

int tower(int n, char source, char temp, char dest, int i)
{
	if (n==1)
	{
		i++;
		printf("Move disk 1 from %c to %c \n", source, dest);
		return i;
	}

	i = tower(n-1, source, dest, temp, i);
	printf("Move disk %d from %c to %c \n", n, source, dest);
	i ++;
	i = tower(n-1, temp, source, dest, i);
	return i;
}

void main()
{
	int n, i = 0;
	char A = 'a', B = 'b', C='c';
	printf("Enter the number of disks : ");
	scanf("%d", &n);
	i = tower(n, A, B, C, i);
	printf("Number of steps : %d", i);
}