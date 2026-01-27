import java.util.Scanner;

class Stack <T extends Person>{
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
	static void displayStack(Stack<? extends Person> stack) {
        System.out.println("Displaying Stack:");
        for (int i = 0; i <= stack.tos; i++) {
            System.out.print(stack.elements[i].getName() + " ");
        }
        System.out.println();
    }
}

interface Person {
	void create(Scanner s);
	String getName();
}

class Student implements Person {
	String name;
	int roll;
	public void create(Scanner s){
		System.out.print("Name : ");
		name = s.next();
		System.out.print("Roll : ");
		roll = s.nextInt();
	}
	public String getName(){ return name; }
}

class Employee implements Person {
	String name;
	int id;
	public void create(Scanner s){
		System.out.print("Name : ");
		name = s.next();
		System.out.print("ID : ");
		id = s.nextInt();
	}
	public String getName(){ return name; }
}
	
public class Q3WildCard {
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
					Stack.displayStack(stackStd);
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
					Stack.displayStack(stackEmp);
					break;
				case 7: break;
				default : System.out.println("Wrong Choice. ");
			}
		}while(ch!=7);
	}
}