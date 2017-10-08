public class SwapUsingTempVariable {

    public static void main(String[] args) {

        int firstNumber = 48;
        int secondNumber = 36;
        int temporary;

        System.out.println("Swap");
        System.out.println();

        System.out.println("Before Swapping:");
        System.out.println("First Number = " + firstNumber);
        System.out.println("Second Number = " + secondNumber);
        System.out.println();

        //Swapping
        temporary = firstNumber;
        firstNumber = secondNumber;
        secondNumber = temporary;

        System.out.println("After Swapping:");
        System.out.println("First Number = " + firstNumber);
        System.out.println("Second Number = " + secondNumber);
        System.out.println();

    }

}