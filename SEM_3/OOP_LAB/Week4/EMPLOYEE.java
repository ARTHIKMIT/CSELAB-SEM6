// Q2
import java.util.Scanner;

public class EMPLOYEE
{
	String ename;
	int eid;

	EMPLOYEE(){
	}

	EMPLOYEE()
	{
		Scanner s = new Scanner(System.in);
		System.out.println("Name : ");
		this.ename = s.next();
		System.out.println("E ID : ");
		this.eid = s.nextInt();
	}
	public void display()
	{
		System.out.println("Employee details : ");
		System.out.println("Name : "+this.ename);
		System.out.println("E ID : "+this.eid);
	}
	public static void main(String Args[])
	{
		Scanner s = new Scanner(System.in);
		System.out.println("Number of Employees : ");
		int n = s.nextInt();
		EMPLOYEE[] em = new EMPLOYEE[n];
		for(int i=0; i<n; i++)
		{
			em[i] = new EMPLOYEE();
			System.out.println("Enter Employee "+(i+1)+" details : ");
			em[i].read();
			em[i].compute_net_sal();
		}	
		for(int i=0; i<n; i++)
			em[i].display();
	}
}
