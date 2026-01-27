import java.util.Scanner;

class Stack <T>{
	int n = 15;
	T[] elements;
	int tos = -1;
	Stack(T[] el){
		elements = el;
	}
	void push(T ele){
		if (tos == n-1)
			System.out.println("Full.");
		else elements[++tos] = ele;
	}
	T pop(){
		if (tos == -1){
			System.out.println("Empty.");
			return null;
		}
		return elements[tos--];
	}
}

class Student {
	String name;
	int roll;
	void create(Scanner s){
		System.out.print("Name : ");
		name = s.next();
		System.out.print("Roll : ");
		roll = s.nextInt();
	}
}

class Employee {
	String name;
	int id;
	void create(Scanner s){
		System.out.print("Name : ");
		name = s.next();
		System.out.print("ID : ");
		id = s.nextInt();
	}
}
	
public class Q2GenericStack {
	public static void main(String args[]){
		int n = 15;
		Scanner s = new Scanner(System.in);
		Stack<Student> stackStd = new Stack<Student>(new Student[n]);
		Stack<Employee> stackEmp = new Stack<Employee>(new Employee[n]);
		System.out.println("Enter 1. Push Student, 2. Pop Student, 3. Display Student");
		System.out.println("4. Push Employee, 5. Pop Employee, 6. Display Employee, 7. Exit");

		int ch = 0;
		do{
			System.out.println("Choice : ");
			ch = s.nextInt();
			switch(ch){
				case 1:
					System.out.println("Enter Student Details : ");
					Student std = new Student();
					std.create(s);
					stackStd.push(std);
					break;

				case 2:
					System.out.println("Student Popped : "+stackStd.pop().name);
					break;
				case 3:
					System.out.println("The Stack is : ");
					for(int i=0; i<=stackStd.tos;i++)
						System.out.print(stackStd.elements[i].name + " ");
					System.out.println();
					break;
				case 4:
					System.out.println("Enter Employee Details : ");
					Employee em = new Employee();
					em.create(s);
					stackEmp.push(em);
					break;
				case 5:
					System.out.println("Employee Popped : "+stackEmp.pop().name);
					break;
				case 6: 
					System.out.println("The Stack is : ");
					for(int i=0; i<=stackEmp.tos;i++)
						System.out.print(stackEmp.elements[i].name + " ");
					System.out.println();
					break;
				case 7: break;
				default : System.out.println("Wrong Choice. ");
			}
		}while(ch!=7);
	}
}