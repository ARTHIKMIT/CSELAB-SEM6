import java.util.Scanner;

class Person {
    private String name, DOB;
    Person(){
    }
    Person(String name, String DOB){
        this.name = name;
        this.DOB = DOB;
    }
    public void displayName(){
        System.out.println("Name : "+name);
        System.out.println("Date of Birth : "+DOB);
    }
}

class CollegeGraduate extends Person{
    private float GPA;
    private int yearOfGrad;
    CollegeGraduate(){
    }
    CollegeGraduate(String name, String DOB, float GPA, int yearOfGrad){
        super(name, DOB);
        this.GPA = GPA;
        this.yearOfGrad = yearOfGrad;
    }
    public void displayDeets(){
        super.displayName();
        System.out.println("GPA : "+GPA);
        System.out.println("Graduation Year : "+yearOfGrad);
    }
}

public class Q3 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Input Person's details:\n");
        String name, DOB;
        System.out.println("Name : ");
        name = s.nextLine();
        System.out.println("Date of birth (dd/mm/yy) : ");
        DOB = s.nextLine();
        Person p1 = new Person(name, DOB);
        p1.displayName();
        System.out.println("\nAccessing College Graduates details:");
        System.out.println("Name : ");
        name = s.nextLine();
        System.out.println("Date of birth (dd/mm/yy) : ");
        DOB = s.nextLine();
        System.out.println("GPA: ");
        float gpa = s.nextFloat();
        System.out.println("Graduation Year : ");
        int yearOfGrad = s.nextInt();
        
        CollegeGraduate cg = new CollegeGraduate(name, DOB, gpa, yearOfGrad);
        cg.displayDeets();
        
    }
}