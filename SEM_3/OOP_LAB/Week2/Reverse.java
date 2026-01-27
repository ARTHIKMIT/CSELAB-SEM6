import java.util.Scanner;

public class Reverse
{
	public static int[] reverse(int[] arr, int n)
	{
		int temp, i;
		for(i=0; i<n/2; i++)
		{
			temp = arr[i];
			arr[i] = arr[n-i-1];
			arr[n-i-1] = temp;
		}
		return arr;
	}

	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		int n, i;
		System.out.println("Enter the number of elements in the array: ");
		n = s.nextInt();
		int[] arr = new int[n];
		System.out.println("Enter the elements of the array: ");
		for(i=0; i<n; i++)
			arr[i] = s.nextInt();
		arr = reverse(arr, n);
		for(i=0; i<n; i++)
			System.out.println(arr[i]);
	}
}