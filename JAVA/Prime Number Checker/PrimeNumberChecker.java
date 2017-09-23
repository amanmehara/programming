import java.util.Scanner;

/**
 * Created by @amanmehara on 15/03/2017.
 */
public class PrimeNumberChecker {
    public static void main(String[] args) {
        System.out.println("isPrime? ");
        System.out.println();

        Scanner consoleInput = new Scanner(System.in);

        System.out.print("Number : ");
        long number = consoleInput.nextLong();
        System.out.println();

        boolean isPrime=true;

        //Prime number checker
        for (int i=2;i<=Math.sqrt(number);i++) {
            if (number % i == 0) {
                isPrime = false;
                break;
            }
        }

        if(isPrime) {
            System.out.println("Prime Number");
        }
        else {
            System.out.println("Not a Prime Number");
        }
        System.out.println();
    }
}
