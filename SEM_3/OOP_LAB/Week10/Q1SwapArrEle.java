import java.util.Scanner;

//public class Q1SwapArrEle <T> {
public class Q1SwapArrEle {

	//T[] arr;
	
	// Q1SwapArrEle(T[] Arr){
	// 	arr = Arr;
	// }

	//void swap(int ind1, int ind2){
	static <T> T[] swap (T[] arr,int ind1, int ind2){

		T temp = arr[ind1];
		arr[ind1] = arr[ind2];
		arr[ind2] = temp;
		return arr;
	}

	static <T> void display (T[] arr){
		System.out.println("Elements : ");
		for (int i=0; i<arr.length; i++)
			System.out.println(arr[i]);	
	}

	public static void main (String[] args){
		Scanner s = new Scanner(System.in);
		System.out.print("Number of elements : ");
		int n = s.nextInt();
		Integer[] arr = new Integer[n];
		System.out.println("Elements : ");
		for (int i=0; i<n; i++)
			arr[i] = s.nextInt();
		//Q1SwapArrEle<Integer> ob = new Q1SwapArrEle<Integer>(arr);

		System.out.println("Indices to Swap : ");
		int ind1 = s.nextInt();
		int ind2 = s.nextInt();
		//ob.swap(ind1, ind2);
		//ob.display();
		arr = swap(arr, ind1, ind2);
		display(arr);
	}
}