import java.util.Scanner;

public class Test{
	public static void main(String[] Args)
	{
		Scanner s = new Scanner(System.in);
		String a;
		a = s.nextLine();
		String[] temp = a.split(" ");
		for (int i=0; i<temp.length; i++)
			System.out.println(temp[i]);
		//System.out.println(temp);
	}
}