import java.util.Scanner;

public class Sum
{
	public static int sum(int a)
	{
		int rem, sum = 0;
		for(int i = a; i!=0; i=i/10)
		{
			rem = i%10;
			sum += rem;
		} 
		return sum;
	}

	public static void main(String[] Args)
	{
		int a;
		Scanner s = new Scanner(System.in);
		a = s.nextInt();
		int sum = sum(a);
		System.out.println(sum);
	}
}