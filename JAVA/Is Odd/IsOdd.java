import java.util.Scanner;

public class IsOdd {

    public static void main(String[] args) {

        System.out.println("isOdd? ");
        System.out.println();

        Scanner consoleInput = new Scanner(System.in);

        System.out.print("Number: ");
        long number = consoleInput.nextLong();
        System.out.println();

        boolean isOdd = true;

        //Odd number checker
        if (number % 2 == 0) {
            isOdd = false;
        }

        if (isOdd) {
            System.out.println("Odd Number");
        } else {
            System.out.println("Not an Odd Number");
        }
        System.out.println();

    }

}