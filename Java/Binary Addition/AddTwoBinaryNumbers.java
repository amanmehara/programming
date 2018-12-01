/**
 * Created by NafisaBarlaskar on 14-10-2017.
 */
public class AddTwoBinaryNumbers {

    public static String addBinary(String firstBinary, String secondBinary){

        StringBuilder stringBuilder = new StringBuilder();

        int firstLength = firstBinary.length() - 1;

        int secondLength = secondBinary.length() - 1;

        int carry = 0;

        while (firstLength >= 0 || secondLength >= 0){

            int sum = 0;

            if(firstLength >= 0 && firstBinary.charAt(firstLength) == '1'){
                sum++;
            }
            if(secondLength >= 0 && secondBinary.charAt(secondLength) == '1'){
                sum++;
            }

            sum += carry;

            carry = sum >=2 ? 1 : 0;

            stringBuilder.insert(0, (char)((sum%2) + '0'));

            firstLength--;

            secondLength--;
        }

        if(carry == 1){
            stringBuilder.insert(0, '1');
        }

        return stringBuilder.toString();
    }

    public static void main(String[] args){

        String firstString = "111";
        System.out.println("First Binary Number : " + firstString);

        String secondString = "11";
        System.out.println("Second Binary Number: " + secondString);

        System.out.println("Sum: " + addBinary(firstString,secondString));
    }
}
