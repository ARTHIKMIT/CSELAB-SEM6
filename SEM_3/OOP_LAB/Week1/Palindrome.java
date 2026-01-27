import java.util.Scanner;

public class Palindrome
{
	public static int rev(int a)
	{
		int rem, reverse = 0;
		for(int i = a; i!=0; i=i/10)
		{
			rem = i%10;
			reverse = reverse*10 + rem;
		}
		return reverse;
	}

	public static void isPalindrome(int a, int b)
	{
		System.out.println("Reverse : " + b);
		if (a==b)
			System.out.println("The given number is a Palindrome. ");
		else System.out.println("The given number is a not Palindrome. ");
	}

	public static void main(String[] Args)
	{
		int a;
		Scanner s = new Scanner(System.in);
		a = s.nextInt();
		int reverse = rev(a);
		isPalindrome(a, reverse);
	}
}