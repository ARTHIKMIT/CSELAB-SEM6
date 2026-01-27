import java.util.Scanner;

public class LargestOfThree
{
	public static int max(int a, int b, int c)
	{
		if (a>b && a>c)
			return a;
		else if (b>c)
			return b;
		else return c;
	}

	public static int maxNestedIf(int a, int b, int c)
	{
		if (a>b)
		{
			if (a>c)
				return a;
			else return c;
		}
		else if (b>c)
			return b;
		else return c;
	}

	public static void main(String[] Args)
	{
		int a, b, c;
		Scanner s = new Scanner(System.in);
		a = s.nextInt();
		b = s.nextInt();
		c = s.nextInt();
		System.out.println("Else If ladder max : " + max(a, b, c));
		System.out.println("Nested If max : " + maxNestedIf(a, b, c));
	}
}