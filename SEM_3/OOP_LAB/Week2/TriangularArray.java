import java.util.Scanner;

public class TriangularArray
{
	public static void main(String[] args)
	{

		int[][] A = new int[10][];
		for (int i=0; i<10; i++)
			A[i] = new int[i+1];
		
		for (int i=0; i<10; i++)
			for (int j=0; j<=i; j++)
				A[i][j] = i+j;

		for (int i=0; i<10; i++)
		{
			for (int j=0; j<=i; j++)
				System.out.print(A[i][j]+"\t");
			System.out.println();
		}
	}
}