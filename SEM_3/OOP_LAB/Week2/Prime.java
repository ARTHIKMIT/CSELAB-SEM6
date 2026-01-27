import java.util.*;

public class Prime
{
	public static boolean IsPrime(int n)
	{
		if (n==2)
			return true;
		if (n==1 | n==0)
			return false;
		for(int i=2; i<=Math.sqrt(n); i++)
			if (n%i == 0)
				return false;
		return true;
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
		for(i=0; i<n; i++)
			if (IsPrime(arr[i]))
				System.out.println(arr[i]);
	}
}