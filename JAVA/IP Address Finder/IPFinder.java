import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.Scanner;

public class IPFinder {

    public static void main(String[] args) throws UnknownHostException {

        String host;
        Scanner input = new Scanner(System.in);
        InetAddress address;

        System.out.print("Host Name: ");
        host = input.next();

        address = InetAddress.getByName(host);
        System.out.println(address);

    }

}
