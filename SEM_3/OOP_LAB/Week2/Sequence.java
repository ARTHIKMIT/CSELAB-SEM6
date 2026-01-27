//
import java.util.Scanner;
public class Sequence
{
	public static void main(String args[])
	{
		int n;
		Scanner s = new Scanner(System.in);
		System.out.println("Enter N: ");
		n = s.nextInt();
		int[] arr = new int[n];
		for (int i=0; i<n; i++)
			arr[i] = i+1;
		
		for(int i : arr)
			System.out.println(i);

	}
}