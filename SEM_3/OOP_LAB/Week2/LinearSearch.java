import java.util.Scanner;

public class LinearSearch
{
	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		int n, i, ele;
		System.out.println("Enter the number of elements in the array: ");
		n = s.nextInt();
		int[] arr = new int[n];
		System.out.println("Enter the elements of the array: ");
		for(i=0; i<n; i++)
			arr[i] = s.nextInt();

		System.out.println("Enter the element to be found : ");
		ele = s.nextInt();

		for(i=0; i<n; i++)
			if (arr[i] == ele)
			{
				System.out.println("Position : " + (i+1));
				System.out.println("Index : " + i);
			}
	}
}