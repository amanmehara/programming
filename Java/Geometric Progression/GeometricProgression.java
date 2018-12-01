public class GeometricProgression {

    public static void main(String[] args) {

        System.out.println("Geometric Progression");
        System.out.println();

        double firstTerm = 7;
        double commonRatio = 2;
        int numberOfTerms = 9;

        System.out.println("first term: " + firstTerm);
        System.out.println("common ratio: " + commonRatio);
        System.out.println("number of terms: " + numberOfTerms);
        System.out.println();

        //Geometric Progression
        System.out.println("Geometric Progression: ");
        for (int i = 0; i < numberOfTerms; i++) {
            double ithTerm = firstTerm * Math.pow(commonRatio, i);
            System.out.println(ithTerm);
        }

    }

}