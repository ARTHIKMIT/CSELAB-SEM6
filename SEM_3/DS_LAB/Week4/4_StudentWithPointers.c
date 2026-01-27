/* Q4 Create a structure STUDENT consisting of variables of structures:
i. DOB {day, month (use pointer ), year},
ii. STU_INFO {reg_no, name(use pointer), address},
iii. COLLEGE {college_name (use pointer), university_name}
where structure types from i to iii are declared outside the STUDENT independently.
Show how to read and display member variables of DOB type if pointer variable is created
for DOB inside STUDENT and STUDENT variable is also a pointer variable. The
program should read and display the values of all members of STUDENT structure. */

#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int day;
	int *month;
	int year;
}DOB;

typedef struct
{
	int reg;
	char *name;
	char address[20];
}STU_INFO;

typedef struct
{
	char *collegeName;
	char uniName[20];
}COLLEGE;

typedef struct
{
	DOB *dob;
	STU_INFO stdinf;
	COLLEGE college;
}Student;

void read(Student *a)
{
	a->stdinf.name = calloc(25, sizeof(char));
	printf("Name : ");
	scanf("%s", a->stdinf.name);
	printf("Reg Number : ");
	scanf("%d", &a->stdinf.reg);
	printf("address : ");
	scanf("%s", a->stdinf.address);	

	a->dob = calloc(1, sizeof(DOB));
	a->dob->month = calloc(1, sizeof(int));
	printf("Date of birth : \n");
	scanf("%d %d %d", &a->dob->day, a->dob->month, &a->dob->year);

	a->college.collegeName = calloc(25, sizeof(char));
	printf("College Name : ");
	scanf("%s", a->college.collegeName);
	printf("University Name : ");
	scanf("%s", a->college.uniName);	
}


void display(Student *a)
{
	printf("\nName : %s", a->stdinf.name);
	printf("\nReg Number : %d ", a->stdinf.reg);
	printf("\naddress : %s",a->stdinf.address);
	printf("\nDate of birth : %d %d %d",a->dob->day, *a->dob->month, a->dob->year);
	printf("\nCollege Name : %s ", a->college.collegeName);
	printf("\nUniversity Name : %s", a->college.uniName);
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
	
	for (int i=0; i<n; i++)
	{
		printf("\nStudent %d",i+1);
		display(s+i);
	}
}