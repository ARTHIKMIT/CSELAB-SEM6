// Q1 - 
import java.util.Scanner;

public class STUDENT
{
	String sname; //= new String[20];
	int total;
	float avg;
	int[] marks_array = new int[5];

	public void assign(String sname, int[] marks_array)
	{
		this.sname = sname;
		this.marks_array = marks_array;
	}
	public void display()
	{
		System.out.println("Student details : ");
		System.out.println("Name : "+this.sname);
		System.out.println("Marks : ");
		for (int i =0; i<5; i++)
			System.out.println("Subject "+(i+1)+" "+this.marks_array[i]);
		System.out.println("Total : "+this.total);
		System.out.println("Average : "+this.avg);

	}
	public void compute()
	{
		this.avg = 0;
		this.total = 0;
		for (int i =0; i<5; i++)
			this.total += marks_array[i];
		this.avg = this.total/5;
	}
	public static void main(String Args[])
	{
		String sname; //= new String[20];
		int[] marks = new int[5];
		Scanner s = new Scanner(System.in);
		System.out.println("Enter Student details : ");
		System.out.println("Name : ");
		sname = s.next();
		System.out.println("Marks : ");
		for (int i =0; i<5; i++)
			marks[i] = s.nextInt();
		STUDENT std = new STUDENT();
		std.assign(sname, marks);
		std.compute();
		std.display();
	}
}