/**
 * Created by NafisaBarlaskar on 14-10-2017.
 */
public class IsNumberPalindrome {

    public static boolean isPalindromeNumber(int inputNumber) {

        String inputString = String.valueOf(inputNumber);
        int length = inputString.length();

        for (int i = length - 1, j = 0; i >= 0 && j < inputString.length() && i != j; i--, j++) {
            if (inputString.charAt(i) != inputString.charAt(j)) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        System.out.println(isPalindromeNumber(123421));
    }

}
