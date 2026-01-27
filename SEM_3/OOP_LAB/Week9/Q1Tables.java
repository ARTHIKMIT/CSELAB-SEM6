import java.util.Scanner;

class thread extends Thread {
	int num;
	thread(int n){
		super();
		num = n;
	}
	public void run () {
		for (int i=1; i<=10; i++)
			System.out.println(num+" x "+i+" = "+num*i);
		System.out.println();
	}
}

public class Q1Tables {
	public static void main(String[] args){
		
		thread t1 = new thread(5);
		t1.start();
		try {
			//Join waits for the thread to die before continuing
			t1.join();
		}
		catch (InterruptedException e) {
				System.out.println(e);
		}

		thread t2 = new thread(7);
		t2.start();
		try {
			t2.join();
		}
		catch (InterruptedException e) {
				System.out.println(e);
		}
	
	}
}