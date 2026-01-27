/* Q3 Samuel wants to store the data of his employees, which includes the following fields:
(i) Name of the employee 
(ii) Date of birth which is a collection of {day, month, year}
(iii) Address which is a collection of {house number, zip code and state}. 
Write a 'C' program to read and display the data of 
N employees using pointers to array of structures.*/

#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int day;
	int month;
	int year;
}DOB;

typedef struct{
	int houseNumeber;
	int zip;
	char state[20];
}Address;

typedef struct
{
	char name[20];
	DOB dob;
	Address address;
}Employee;

void read(Employee *a)
{
	printf("\nName : ");
	scanf("%s", a->name);
	printf("Date of birth (D M Y) : \n");
	scanf("%d %d %d", &a->dob.day, &a->dob.month, &a->dob.year);
	printf("Address : \n");
	printf("House Number : ");
	scanf("%d", &a->address.houseNumeber);
	printf("ZIP Code : ");
	scanf("%d", &a->address.zip);
	printf("State : ");
	scanf("%s", a->address.state);
}

void display(Employee *a)
{
	printf("Name : %s ", a->name);
	printf("Date of birth : %d %d %d\n", a->dob.day, a->dob.month, a->dob.year);
	printf("Address : \n");
	printf("House Number : %d \n", a->address.houseNumeber);
	printf("ZIP Code : %d \n",a->address.zip);
	printf("State : %s \n", a->address.state);
}

int main()
{
	Employee *em;
	int n;
	printf("Number of Employees : ");
	scanf("%d",&n);
	em = calloc(n,sizeof(Employee));
	for (int i=0; i<n; i++)
	{
		printf("\nEmployee %d\n",i+1);
		read(em+i);
	}	

	printf("\nEmployees : \n");
	for (int i=0; i<n; i++)
	{
		printf("\nEmployee %d\n",i+1);
		display(em+i);
	}	
}