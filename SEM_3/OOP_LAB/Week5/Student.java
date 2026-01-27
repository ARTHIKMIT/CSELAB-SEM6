import java.util.Scanner;
import java.util.GregorianCalendar;
import java.util.Calendar;

public class Student{
	int reg_no, sem;
	String name;
	GregorianCalendar doj;
	float gpa, cgpa;
	static int s_num=0;

	Student(){
		name = "XYZ";
		doj = new GregorianCalendar();
		s_num += 1;
	}

	Student(String name, int year, int month, int day, int sem, float gpa, float cgpa){
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
	public static void sort_sem(Student[] s){
		int i, j, n=s.length;
		for(i=0; i<n; i++)
			for(j=0; j<n-i-1; j++)
				if(s[j].sem > s[j + 1].sem){
					Student temp = s[j];
					s[j] = s[j+1];
					s[j+1] = temp;
				}
	}

	public static void sort_cgpa(Student[] s){
		int i, j, n=s.length;
		for(i=0; i<n; i++)
			for(j=0; j<n-i-1; j++)
				if(s[j].cgpa > s[j + 1].cgpa){
					Student temp = s[j];
					s[j] = s[j+1];
					s[j+1] = temp;
				}
	}

	public static void sort_name(Student[] s){
		int i, j, n=s.length;
		for(i=0; i<n; i++)
			for(j=0; j<n-i-1; j++)
				if(s[j].name.compareTo(s[j+1].name) > 0){
					Student temp = s[j];
					s[j] = s[j+1];
					s[j+1] = temp;
				}
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
        System.out.println("\nSem Wise : ");
	    sort_sem(s);
        for(i=0; i<n; i++)
			s[i].display();
    
        System.out.println("\nCGPA Wise : ");
	    sort_sem(s);
		for(i=0; i<n; i++)
			s[i].display();
    
        System.out.println("\nName Wise : ");
		sort_sem(s);
		for(i=0; i<n; i++)
			s[i].display();
    }
}
