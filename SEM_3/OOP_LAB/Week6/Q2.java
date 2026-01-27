// Q2
import java.util.Scanner;

class EMPLOYEE
{
	String ename;
	int eid;
	double basic, da, net_sal, gross_sal, it;

	public void read(){
		Scanner s = new Scanner(System.in);
		System.out.println("Name : ");
		this.ename = s.next();
		System.out.println("E ID : ");
		this.eid = s.nextInt();
		System.out.println("Basic Salary : ");
		this.basic = s.nextFloat();
	}
	public void display(){
		System.out.println("Employee details : ");
		System.out.println("Name : "+this.ename);
		System.out.println("E ID : "+this.eid);
		System.out.println("Net salary : "+this.net_sal);
	}
	public void compute(){
		this.da = 0.52*this.basic;
		this.gross_sal = basic + this.da;
		this.it = 0.3 * this.gross_sal;
		this.net_sal = this.gross_sal - this.it;
	}
}

class FullTimeEmp extends EMPLOYEE{
	double bonus, deducations;

	FullTimeEmp(double bonus, double deducations){
		this.bonus = bonus;
		this.deducations = deducations;
	}

	public void compute(){
		super.compute();
		this.net_sal += bonus - deducations;
	}
	public void display(){
		super.display();
		System.out.println("Bonus : "+bonus);
		System.out.println("Deductions : "+deducations);
		//System.out.println("Finaly Net salary : "+net_sal);
	}
}

class PartTimeEmp extends EMPLOYEE{
	int hoursWorked;
	static final double hourlyRate = 10;

	PartTimeEmp(int hoursWorked){
		this.hoursWorked = hoursWorked;
	}

	public void compute(){
		this.net_sal = hoursWorked * hourlyRate;
	}
	public void display(){
		super.display();
		System.out.println("Hours Worked : " + hoursWorked);
		System.out.println("Hourly Rate : " + hourlyRate);
	}
}

public class Q2 {
	public static void main(String Args[])
	{
		Scanner s = new Scanner(System.in);
		System.out.println("Employee : ");
		EMPLOYEE em = new EMPLOYEE();
		em.read();
		em.compute();
		em.display();
		
		System.out.println("Full time Employee : ");
		System.out.println("Bonus : ");
		double bonus = s.nextDouble();
		System.out.println("Deductions : ");
		double deducations = s.nextDouble();
		FullTimeEmp emF = new FullTimeEmp(bonus, deducations);
		emF.read();
		emF.compute();
		emF.display();
		
		System.out.println("Part time Employee : ");
		System.out.println("Number of hours worked : ");
		int hoursWorked = s.nextInt();
		PartTimeEmp emP = new PartTimeEmp(hoursWorked);
		emP.read();
		emP.compute();
		emP.display();

		s.close();
	}
}
