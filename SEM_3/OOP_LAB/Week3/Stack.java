//Q4
import java.util.Scanner;

class Stack
{
	int MAX_SIZE = 10;
	int[] stack = new int[MAX_SIZE];
	int tos = -1;
	public void push(int a)
	{
		if (tos >= MAX_SIZE-1)
			System.out.println("Overflow has occured. Stack is full.");
		else
			stack[++tos] = a;
	}
	public int pop()
	{
		if (tos == -1)
		{
			System.out.println("Underflow has occured. Stack is empty.");
			return 0;
		}
		else return stack[tos--];
	}
	public void display()
	{
		System.out.println("Stack : ");
		for (int i=0; i<=tos; i++)
			System.out.println(stack[i]);
	}
	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		System.out.println("Enter number of elements in the stack : ");
		int n = s.nextInt();
		Stack s1 = new Stack();
		System.out.println("Enter Stack elements : ");
		for (int i =0; i<n; i++)
			s1.push(s.nextInt());
		int ele = s1.pop();
		System.out.println("Popped element : "+ele);
		s1.push(7);
		s1.push(10);
		s1.display();
	}
}
