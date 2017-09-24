import java.util.Scanner;

/**
 * Created by @amanmehara on 15/03/2017.
 */
public class IsEven {
    public static void main(String[] args) {
        System.out.println("isEven? ");
        System.out.println();

        Scanner consoleInput = new Scanner(System.in);

        System.out.print("Number : ");
        long number = consoleInput.nextLong();
        System.out.println();

        boolean isEven=true;

        //Even number checker
        if(number % 2 != 0) {
            isEven = false;
        }

        if(isEven) {
            System.out.println("Even Number");
        }
        else {
            System.out.println("Not an Even Number");
        }
        System.out.println();
    }
}
