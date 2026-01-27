import java.util.Scanner;

class PushException extends Exception{
	PushException(){
		super();
	}
	PushException(String m){
		super(m);
	}
}

class PopException extends Exception{
	PopException(){
		super();
	}
	PopException(String m){
		super(m);
	}
}


public class Stack {
	int n = 3;
	int[] elements = new int[n];
	int tos = -1;
	Stack(){
	}
	void push(int ele) throws PushException{
		if (tos == n-1)
			throw new PushException("Overflow.");
		elements[++tos] = ele;
	}
	int pop() throws PopException{
		if (tos == -1)
			throw new PopException("Underflow.");
		return elements[tos--];
	}
	void display(){
		System.out.println("The Stack is : ");
		for(int i=0; i<=tos;i++)
			System.out.print(elements[i] + " ");
	}

	public static void main(String args[]){
		Stack stack = new Stack();
		Scanner s = new Scanner(System.in);
		System.out.println("Enter 1. Push, 2. Pop, 3. Display, 4. Exit");
		int ch = 0;
		do{
			System.out.println("Choice : ");
			ch = s.nextInt();
			switch(ch){
				case 1:
					System.out.println("Enter element : ");
					int ele = s.nextInt();
					try{
						stack.push(ele);
					}
					catch(PushException e){
						System.out.println(e.getMessage());
					}
					break;

				case 2:
					try{
						System.out.println("Element Popped : "+stack.pop());
					}
					catch(PopException e){
						System.out.println(e.getMessage());
					}
					break;

				case 3:
					stack.display();
					break;
			
				case 4:
					break;
			}
		}while(ch!=4);
	}
}