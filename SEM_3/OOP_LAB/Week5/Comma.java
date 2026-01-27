import java.util.Scanner;

public class Comma {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a number string: ");
        String numberString = sc.nextLine();

        String formattedNumber = addCommas(numberString);

        System.out.println("Formatted number: " + formattedNumber);
        
        sc.close();
    }

    public static String addCommas(String numberString) {
        int length = numberString.length();
        String result = "";

        int count = 0;

        for (int i = length - 1; i >= 0; i--) {
            result = numberString.charAt(i) + result;
            count++;

            if (count % 3 == 0 && i != 0)
                result = ',' + result;
        }

        return result;
    }
}
