import java.util.Scanner;

class Customer {
	int purchase;
	static int prem_limit = 550;
	String name;
	
	Customer(){
	}

	Customer(String n, int p){
		name = n;
		purchase = p;
	}

	boolean isPremiumCustomer(){
		if (purchase>=prem_limit)
			return true;
		else return false;
	}
	void display(){
		System.out.println("Name : "+name);
		System.out.println("Purchase : "+purchase);
	}
}

class PremiumCustomer extends Customer{
	double rating;
	PremiumCustomer(){
	}
	PremiumCustomer(String name, int purchase, double r){
		super(name, purchase);
		rating = r;
	}
}

class Item {
	private static String[] item_list = new String[5];
	private static int[] item_rating = new int[5];
	Item(){
	}
	Item(String[] items, int[] ratings){
		item_list = items;
		item_rating = ratings;
	}
	void getItems(Customer c){
		for (int i=0; i<item_list.length; i++){
			//System.out.println(c.isPremiumCustomer());
			//System.out.println(item_list[i] + " " + item_rating[i]);
			if (c.isPremiumCustomer()){
				if(item_rating[i] > 4)
					System.out.println(item_list[i]);
			}
			else System.out.println(item_list[i]);
		}
	}
}

public class Demo1 {
	public static void main(String args[]){
		System.out.println("Enter the number of items : ");
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();

		System.out.println("Enter Items : ");
		String[] items = new String[n];
		for(int i=0; i<n; i++)
			items[i] = s.next();
		
		System.out.println("Enter Ratings : ");
		int[] ratings = new int[n];
		for(int i=0; i<n; i++)
			ratings[i] = s.nextInt();

		Item itemObj = new Item(items, ratings);
		//Item itemObj = new Item();
		//itemObj.item_list = items;
		//itemObj.item_rating = ratings;

		System.out.println("Number of Customers : ");
		int num = s.nextInt();

		Customer[] c = new Customer[num];
		for(int i=0; i<num; i++){
			System.out.println("Name : ");
			String name = s.next();
			System.out.println("Purchase : ");
			int purchase = s.nextInt();
			if (purchase > Customer.prem_limit){
				System.out.println("Rating : ");
				int ratingC = s.nextInt();
				c[i] = new PremiumCustomer(name, purchase, ratingC);
			}
			else c[i] = new Customer(name, purchase);
			itemObj.getItems(c[i]);
		}
		
	}
}