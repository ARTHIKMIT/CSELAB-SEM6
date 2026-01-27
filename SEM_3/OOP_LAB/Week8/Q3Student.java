import java.util.Scanner;
import java.util.GregorianCalendar;
import java.util.Calendar;

class SeatsFilledExc extends Exception {
    SeatsFilledExc(String m) {
        super(m);
    }
}

public class Q3Student{
	int reg_no, sem;
	String name;
	GregorianCalendar doj;
	float gpa, cgpa;
	static int s_num=0;

	Q3Student(){
		name = "XYZ";
		doj = new GregorianCalendar();
		s_num += 1;
	}

	Q3Student(String name, int year, int month, int day, int sem, float gpa, float cgpa) throws SeatsFilledExc {
		if (s_num > 25)
		    throw new SeatsFilledExc("Seats filled.");
		this.reg_no = (year % 100)*100 + s_num + 1;
		this.name = name;
		doj = new GregorianCalendar(year, month, day);
		this.sem = sem;
		this.gpa = gpa;
		this.cgpa = cgpa;
		s_num += 1;
	}

	public void display(){
		System.out.println("Registration number : " + reg_no);
		System.out.println("Name : " + name);
		System.out.println("Date of Joining : " + doj.get(Calendar.DATE) + doj.get(Calendar.MONTH) + doj.get(Calendar.YEAR));
		System.out.println("Semester : " + sem);
		System.out.println("GPA : " + gpa);
		System.out.println("CGPA : " + cgpa);
	}

	public static void main(String[] args) {
	    Scanner sc = new Scanner(System.in);
		
		System.out.println("Number of Students : ");
		int n = sc.nextInt();
		Student[] s = new Student[n];
		String name;
		int sem, year, month, day, i;
		float gpa, cgpa;
		for(i=0; i<n; i++){
		    System.out.println("Student "+(i+1));
			System.out.print("Name : ");
			name = sc.next();
			System.out.print("Sem : ");
			sem = sc.nextInt();
			System.out.println("Date of Joining - Y M D : ");
			year = sc.nextInt();
			month = sc.nextInt();
			day = sc.nextInt();
			System.out.print("GPA : ");
			gpa = sc.nextFloat();
			System.out.print("CGPA : ");
			cgpa = sc.nextFloat();
			s[i] = new Student(name, year, month, day, sem, gpa, cgpa);
		}
    }
}
