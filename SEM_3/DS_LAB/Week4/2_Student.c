/* Q2 Write a C program to implement the following functions. Use pointers and
dynamic memory management functions.
i. To read one Student object where Student is a structure with name, roll
number and CGPA as the data members
ii. To display one Student object
iii. To sort an array of Student structures according to the roll number. */

#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	char name[20];
	int rollnumber;
	float CGPA;
}Student;

void read(Student *a)
{
	printf("Name : ");
	scanf("%s", a->name);
	printf("Roll Number : ");
	scanf("%d", &a->rollnumber);
	printf("CGPA : ");
	scanf("%f", &a->CGPA);	
}

void display(Student *a)
{
	printf("\nName : ");
	printf("%s", a->name);
	printf("\nRoll Number : ");
	printf("%d", a->rollnumber);
	printf("\nCGPA : ");
	printf("%f", a->CGPA);	
}

void sort(Student *s, int n)
{
	Student temp, *p = s;
	for (int i=0; i<n-1 ; i++)
	{	
		Student *minIndex = (p+i);
		for (int j=i+1; j<n ; j++)
			if ((p+j)->rollnumber < minIndex->rollnumber)
				minIndex = (p+j);
		temp = *minIndex;
		*minIndex = *(p+i);
		*(p+i) = temp;
	}
}

int main()
{
	Student *s;
	int n;
	printf("Number of Students : ");
	scanf("%d",&n);
	s = calloc(n,sizeof(Student));
	for (int i=0; i<n; i++)
	{
		printf("Student %d\n",i+1);
		read(s+i);
	}	

	sort(s, n);
	
	printf("Sorted : \n");
	for (int i=0; i<n; i++)
	{
		printf("\nStudent %d",i+1);
		display(s+i);
	}
}