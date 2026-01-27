import java.util.Scanner;

public class Factorial
{
	public int fact(int a)
	{
		int fact = 1;
		for(int i = a; i>1; i--)
			fact *= i;
		return fact;
	}

	public float nCr(int n, int r)
	{
		Factorial f = new Factorial();
		return f.fact(n)/(f.fact(r)*f.fact(n-r));
	}

	public static void main(String[] Args)
	{
		int a, n, r;
		Scanner s = new Scanner(System.in);
		Factorial f = new Factorial();
		a = s.nextInt();
		System.out.println("Factorial = " + f.fact(a));
		n = s.nextInt();
		r = s.nextInt();
		System.out.println("nCr = " + f.nCr(n, r));
	}
}