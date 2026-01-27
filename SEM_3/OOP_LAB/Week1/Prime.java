import java.util.Scanner;

public class Prime
{
	public static int isPrime(int a)
	{
		if (a == 1 || a == 2)
			return 1;
		for(int i=2; i<=a/2; i++)
			if (a%i == 0)
				return 0;
		return 1;
	}

	public static void main(String[] Args)
	{
		int a;
		Scanner s = new Scanner(System.in);
		a = s.nextInt();
		if (isPrime(a)==1)
			System.out.println("Prime");
		else System.out.println("Prime");	
		int n = s.nextInt();
		for (int i=1; i<n; i++)
			if (isPrime(i) == 1)
				System.out.println(i);
	}
}