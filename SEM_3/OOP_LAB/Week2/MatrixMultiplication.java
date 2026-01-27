import java.util.Scanner;

public class MatrixMultiplication
{
	public static void main(String args[])
	{
		Scanner s = new Scanner(System.in);
		int r, c, m, n;
		System.out.println("Enter the shape of Matrix 1 : ");
		m = s.nextInt();
		n = s.nextInt();
		int[][] arr1 = new int[m][n];
		System.out.println("Enter the elements : ");
		for (int i=0; i<m; i++)
			for (int j=0; i<n; j++)
				arr1[i][j] = s.nextInt();
	
		System.out.println("Enter the shape of Matrix 2 : ");
		r = s.nextInt();
		c = s.nextInt();
		int[][] arr2 = new int[r][c];
		System.out.println("Enter the elements : ");
		for (int i=0; i<r; i++)
			for (int j=0; i<c; j++)
				arr2[i][j] = s.nextInt();
		if (n != r)
		{
			System.out.println("Not compatible to multiply");
			return;
		}
		int[][] arr3 = new int[m][c];
		for (int i=0; i<m; i++)
			for (int j=0; i<c; j++)
			{	
				arr3[i][j] = 0;
				for (int k=0; i<n; k++)
					arr3[i][j] += arr1[i][k]*arr2[k][j];
			}
	}
}