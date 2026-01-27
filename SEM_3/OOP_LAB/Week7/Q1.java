import java.util.Scanner;

import com.course.structure.Building;
import com.course.structure.School; 
import com.course.structure.House;


public class Q1 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        System.out.print("Enter square footage: ");
        int sq = s.nextInt();
        System.out.print("Enter stories: ");
        int st = s.nextInt();
        Building Building = new Building(sq, st);

        System.out.print("Enter number of bedrooms: ");
        int beds = s.nextInt();
        System.out.print("Enter number of baths: ");
        int baths = s.nextInt();
        House house = new House(sq, st, beds, baths);

        System.out.print("Enter number of classrooms: ");
        int c = s.nextInt();
        System.out.print("Enter grade level: ");
        int g = s.nextInt();
        School school = new School(sq, st, c, g);
        
        System.out.println("House: ");
        System.out.println("Square Footage: " + house.sq_foot);
        System.out.println("Stories: " + house.stories);
        System.out.println("Bedrooms: " + house.numberOfBedrooms);
        System.out.println("Baths: " + house.numberOfBaths);

        System.out.println("School: ");
        System.out.println("Square Footage: " + school.sq_foot);
        System.out.println("Stories: " + school.stories);
        System.out.println("Classrooms: " + school.classrooms);
        System.out.println("Grade Level: " + school.gradeLevel);

        s.close();
    }
}
