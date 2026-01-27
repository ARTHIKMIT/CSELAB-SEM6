// Q1 - 
import java.util.Scanner;

public class STUDENT
{
	String sname;
	int reg;
	STUDENT(){
	}

	STUDENT(String name, int reg)
	{
		this.sname = name;
		this.reg = reg;
	}

	public void display()
	{
		System.out.println("Student details : ");
		System.out.println("Name : "+this.sname);
		System.out.println("Reg : "+this.reg);
	}
	public static void main(String Args[])
	{
		Scanner s = new Scanner(System.in);
		
		STUDENT std1 = new STUDENT();
	    	System.out.println("Enter Student 1 details : ");
		System.out.println("Name : ");
		std1.sname = s.next();
		System.out.println("Reg : ");
		std1.reg = s.nextInt();
	
	    	String sname; //= new String[20];
        	int reg;	
		System.out.println("Enter Student 2 details : ");
		System.out.println("Name : ");
		sname = s.next();
		System.out.println("Reg : ");
		reg = s.nextInt();
		STUDENT std = new STUDENT(sname, reg);
		
		std1.display();
		std.display();
	}
}
