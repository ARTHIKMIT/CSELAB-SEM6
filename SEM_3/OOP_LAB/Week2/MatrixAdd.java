import java.util.Scanner;

public class MatrixAdd
{
	public static void main(String args[])
	{
		Scanner s = new Scanner(System.in);
		int m, n;

		System.out.println("Enter the shape of Matrices  : ");
		m = s.nextInt();
		n = s.nextInt();
		
		int[][] arr1 = new int[m][n];
		System.out.println("Enter the elements : ");
		for (int i=0; i<m; i++)
			for (int j=0; j<n; j++)
				arr1[i][j] = s.nextInt();
	
		int[][] arr2 = new int[m][n];
		System.out.println("Enter the elements : ");
		for (int i=0; i<m; i++)
			for (int j=0; j<n; j++)
				arr2[i][j] = s.nextInt();

		int[][] arr3 = new int[m][n];
		for (int i=0; i<m; i++)
			for (int j=0; j<n; j++)
				arr3[i][j] = arr1[i][j] + arr2[i][j];

		System.out.println();
		for (int i=0; i<m; i++)
			{
			for (int j=0; j<n; j++)
				//System.out.printf("%d\t",arr3[i][j]);
				System.out.print(arr3[i][j]+"\t");
			System.out.println();
			}


	}
}