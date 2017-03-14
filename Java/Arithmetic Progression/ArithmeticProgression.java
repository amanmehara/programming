/**
 * Created by @amanmehara on 15/03/2017.
 */
public class ArithmeticProgression {
    public static void main(String[] args) {
        System.out.println("Arithmetic Progression :");
        System.out.println();

        double firstTerm = 24;
        double commonDifference = 7.5;
        int numberOfTerms = 15;

        System.out.println("first term : " + firstTerm);
        System.out.println("common difference : " + commonDifference);
        System.out.println("number of terms : " + numberOfTerms);
        System.out.println();

        //Arithmetic Progression
        System.out.println("Arithmetic Progression : ");
        for (int i = 0 ; i < numberOfTerms ; i++) {
            double ithTerm = firstTerm + i * commonDifference;
            System.out.println(ithTerm);
        }
    }
}