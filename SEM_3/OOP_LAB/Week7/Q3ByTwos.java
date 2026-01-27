import java.util.Scanner;

interface Series {
	int getNext();
	void reset();
	void setStart(int n);
}

public class Q3ByTwos implements Series {
	int num;

	public int getNext(){
		num += 2;
		return num;
	}
	
	public void reset(){
		num = 0;
	}

	public void setStart(int n){
		num = n;
	}

	public static void main(String[] args){
		Scanner s = new Scanner(System.in);
		Q3ByTwos series = new Q3ByTwos();
		System.out.println("Enter 1. Get next, 2. Restart, 3. Set Start, 4. Exit");
		int ch = 0;
		do{
			System.out.println("Choice : ");
			ch = s.nextInt();
			switch(ch){
				case 1:
					System.out.println("Next : "+series.getNext());
					break;

				case 2:
					series.reset();
					break;

				case 3:
					System.out.println("Enter Start : ");
					int n = s.nextInt();
					series.setStart(n);
					break;
			
				case 4:
					break;
			}
		}while(ch!=4);
	}
}