// Q2
import java.util.Scanner;

public class EMPLOYEE
{
	String ename;
	int eid;
	double basic, da, net_sal, gross_sal, it;

	public void read()
	{
		Scanner s = new Scanner(System.in);
		System.out.println("Name : ");
		this.ename = s.next();
		System.out.println("E ID : ");
		this.eid = s.nextInt();
		System.out.println("Basic Salary : ");
		this.basic = s.nextFloat();
	}
	public void display()
	{
		System.out.println("Employee details : ");
		System.out.println("Name : "+this.ename);
		System.out.println("E ID : "+this.eid);
		System.out.println("Net salary : "+this.net_sal);

	}
	public void compute_net_sal()
	{
		this.da = 0.52*this.basic;
		this.gross_sal = basic + this.da;
		this.it = 0.3 * this.gross_sal;
		this.net_sal = this.gross_sal - this.it;
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
