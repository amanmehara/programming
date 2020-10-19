
// Java Program to swap two numbers  without
// using temporary variable
import java.*;
 
class Swap {
 
    public static void main(String a[])
    {
        Scanner scan = new.Scanner(System.in);
        System.out.print("Enter X Value: ");
        int x = scan.nextInt();
        System.out.print("Enter Y Value: ");
        int y = scan.nextInt();
        x = x + y;
        y = x - y;
        x = x - y;
        System.out.println("After swaping:"
                           + " x = " + x + ", y = " + y);
    }
}
