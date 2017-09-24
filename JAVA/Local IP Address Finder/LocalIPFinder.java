import java.net.InetAddress;
import java.net.UnknownHostException;

/**
 * Created by @amanmehara on 15/03/2017.
 */
public class LocalIPFinder {
    public static void main(String[] args) {
        try {
            InetAddress address = InetAddress.getLocalHost();
            System.out.println(address);
        } catch (UnknownHostException e) {
            System.out.println(e);
        }
    }
}
