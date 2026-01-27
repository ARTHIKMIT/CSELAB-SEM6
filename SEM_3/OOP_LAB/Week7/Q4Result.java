import java.util.Scanner;

interface Sports {
	void putGrade();
}

class Student {
	int roll, marks;
	void getNumber(int r){
		roll = r;
	}
	void putNumber(){
		System.out.println("Roll Number : "+roll);
	}
	void getMarks(int m){
		marks = m;
	}
	void putMarks(){
		System.out.println("Marks : "+marks);
	}

}

public class Q4Result extends Student implements Sports {
	int grade;
	int res;
	public void putGrade(){
		System.out.println("Grade : "+grade);
	}
	public void genFinalResult(){
		res = grade + marks;
		System.out.println("Final Result : "+res);
	}
	public static void main(String[] args){
		Scanner s = new Scanner(System.in);
		Q4Result std = new Q4Result();
		System.out.println("Student details : ");
		System.out.println("Roll Number : ");
		std.getNumber(s.nextInt());
		System.out.println("Marks : ");
		std.getMarks(s.nextInt());
		System.out.println("Sports Grade : ");
		std.grade = s.nextInt();
		std.putNumber();
		std.putMarks();
		std.putGrade();
		std.genFinalResult();
	}
}