// Q3
import java.util.Scanner;
import java.util.Arrays;

public class Mixer
{
	int[] arr = new int[10];
	public void accept(int[] arr)
	{
		this.arr = arr;
		Arrays.sort(this.arr);
		System.out.println("len : "+this.arr.length);
	}
	public void display()
	{
		System.out.println("The Array is : ");
		for (int i =0; i<this.arr.length; i++)
			System.out.println(this.arr[i]);
	}
	public Mixer mix(Mixer A)
	{

		int[] arrMix = new int[this.arr.length + A.arr.length];
		System.arraycopy(this.arr, 0, arrMix, 0, this.arr.length);
		System.arraycopy(A.arr, 0, arrMix, this.arr.length, A.arr.length);
		this.arr = arrMix;
		Arrays.sort(this.arr);
		return this;
	}
	public static void main(String Args[])
	{
		Scanner s = new Scanner(System.in);
		System.out.println("Enter number of elements in Array 1 : ");
		int n = s.nextInt();
		int[] arr = new int[n];
		System.out.println("Enter Array elements : ");
		for (int i =0; i<n; i++)
			arr[i] = s.nextInt();
		Mixer m1 = new Mixer();
		m1.accept(arr);

		System.out.println("Enter number of elements in Array 2 : ");
		int m = s.nextInt();
		int[] arr2 = new int[m];
		System.out.println("Enter Array elements : ");
		for (int i =0; i<m; i++)
			arr2[i] = s.nextInt();
		Mixer m2 = new Mixer();
		m2.accept(arr2);

		m1 = m1.mix(m2);
		m1.display();

	}
}