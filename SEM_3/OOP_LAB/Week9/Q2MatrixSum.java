import java.util.Scanner;

class Mythread implements Runnable {
	int[] arr;
	int sum = 0;
	Mythread(int[] n){
		arr = n;
	}
	public void run () {
		for (int i=0; i<arr.length; i++)
			sum += arr[i];
	}
}

public class Q2MatrixSum {
	public static void main(String[] args){
		Scanner s = new Scanner(System.in);
		System.out.println("Matrix Size : ");
		System.out.print("Rows : ");
		int r = s.nextInt();
		System.out.print("Columns : ");
		int c = s.nextInt();

		System.out.println("Enter Values : ");
		int[][] mat = new int[r][c];
		for (int i=0; i<r; i++)
			for(int j=0; j<c; j++)
				mat[i][j] = s.nextInt();

		Thread[] threads = new Thread[r];
		Mythread[] t = new Mythread[r];
		for (int i=0; i<r; i++){
			t[i] = new Mythread(mat[i]);
			threads[i] = new Thread(t[i]);
			threads[i].start();
		}

		try {
			int sum = 0;
			for (int i=0; i<r; i++){
				//Waits for the threads to die before adding it's result
				threads[i].join();
				sum += t[i].sum;
			}
			System.out.println("SUM "+sum);
		}
		catch (InterruptedException e){
			System.out.println(e.getMessage());
		}
	}
}