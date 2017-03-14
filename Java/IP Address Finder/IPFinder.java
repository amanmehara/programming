import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.Scanner;

/**
 * Created by @amanmehara on 15/03/2017.
 */
public class IPFinder {
    public static void main(String[] args) {
        String host;
        Scanner input = new Scanner(System.in);
        InetAddress address;

        System.out.print("Enter Host Name: ");
        host = input.next();

        try {
            address = InetAddress.getByName(host);
            System.out.println(address);
        } catch (UnknownHostException e) {
            System.out.println(e);
        }
    }
}
