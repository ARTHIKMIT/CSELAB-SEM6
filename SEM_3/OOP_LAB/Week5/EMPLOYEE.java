// Q1

import java.util.Scanner;

public class EMPLOYEE
{
	String ename, email;

	EMPLOYEE(String ename){
		this.ename = ename;
	}

	public void formatEmployeeName(){
		String[] temp = ename.split(" ");
		this.ename = "";
		for (int i=0; i<temp.length; i++)
			this.ename += temp[i].substring(0, 1).toUpperCase() + temp[i].substring(1).toLowerCase() + " "; 
		System.out.println(ename);
	}

	public String generateEmail(){
		String[] temp = ename.split(" ");
		email = temp[0].substring(0, 1).toLowerCase() + temp[1].toLowerCase() +"@example.com";
		return email;
	}

	public static void main(String Args[]){
		Scanner s = new Scanner(System.in);

		System.out.println("Name : ");
		String ename = s.nextLine();
		EMPLOYEE em = new EMPLOYEE(ename);
		em.formatEmployeeName();
		String email = em.generateEmail();
		System.out.println(email);
	}
}