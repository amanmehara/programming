public class NumberReversal {

    public static void main(String[] args) {

        System.out.println("Number Reversal");
        System.out.println();

        int number = 975;
        int remainder;
        int reverse = 0;

        System.out.println("Number: " + number);
        System.out.println();

        //Number Reversal
        while (number > 0) {
            remainder = number % 10;
            reverse = reverse * 10 + remainder;
            number /= 10;
        }

        System.out.println("Reverse: " + reverse);
        System.out.println();

    }

}
