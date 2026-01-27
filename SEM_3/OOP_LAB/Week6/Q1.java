// Q2

import java.util.Scanner;

class STUDENT
{
	String name;
	int[] marks = new int[10];
	int total;
	float avg;

	STUDENT(){
	}

	STUDENT(String name){
		this.name = name;
	}

	public void display()
	{
		System.out.println("Student details : ");
		System.out.println("Name : "+this.name);
		System.out.println("Marks : ");
		for (int i =0; i<5; i++)
			System.out.println("Subject "+(i+1)+" "+this.marks[i]);
		System.out.println("Total : "+this.total);
		System.out.println("Average : "+this.avg);

	}
    public void compute()
	{
		this.avg = 0;
		this.total = 0;
		for (int i =0; i<5; i++)
			this.total += marks[i];
		this.avg = (float) this.total/5;
	}

}

class ScienceStudent extends STUDENT{
    private int practicalMarks;
    ScienceStudent(String name, int m){
        super(name);
        practicalMarks = m;
    }
    public void compute(){
        this.avg = 0;
		this.total = 0;
        int n = this.marks.length;
		for (int i =0; i<n; i++)
			this.total += marks[i];
        this.total += practicalMarks;
        this.avg = (float) this.total/(n+1);
    }
    public void displayPracticalMarks(){
        System.out.println("Practical Marks : "+ practicalMarks);
    }
}

class ArtsStudent extends STUDENT{
    private String electiveSubject;
    ArtsStudent(String name, String sub){
        super(name);
        electiveSubject = sub;
    }   
}

public class Q1{

	public static void main(String Args[])
	{
		String sname;
		int[] marks = new int[5];
		Scanner s = new Scanner(System.in);
		System.out.println("Enter Student details : ");
		System.out.println("Name : ");
		sname = s.next();
		System.out.println("Marks : ");
		for (int i =0; i<5; i++)
			marks[i] = s.nextInt();
		STUDENT std = new STUDENT(sname);
        std.marks = marks;
		std.compute();
		std.display();

        System.out.println("Enter Science Student details : ");
		System.out.println("Name : ");
		sname = s.next();
        System.out.println("Practical Marks : ");
		int pMarks = s.nextInt();
		System.out.println("Marks : ");
		for (int i =0; i<5; i++)
			marks[i] = s.nextInt();
        ScienceStudent sciStd = new ScienceStudent(sname, pMarks);
        sciStd.marks = marks;
		sciStd.compute();
		sciStd.display();

        System.out.println("Enter Arts Student details : ");
		System.out.println("Name : ");
		sname = s.next();
		System.out.println("Elective Subject : ");
		String eSubject = s.next();
		System.out.println("Marks : ");
		for (int i =0; i<5; i++)
			marks[i] = s.nextInt();
        ArtsStudent artStd = new ArtsStudent(sname, eSubject);
        artStd.marks = marks;
		artStd.compute();
		artStd.display();
        

		s.close();
	}

}