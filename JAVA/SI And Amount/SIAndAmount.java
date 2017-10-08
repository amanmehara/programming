public class SIAndAmount {

    public static void main(String[] args) {

        System.out.println("Simple Interest & Amount");
        System.out.println();

        double principal = 10000;
        double rate = 8.5;
        double time = 4;

        System.out.println("Principal: " + principal);
        System.out.println("Rate: " + rate);
        System.out.println("Time: " + time);
        System.out.println();

        double SimpleInterest = principal * rate * time / 100;
        System.out.println("Simple Interest = " + SimpleInterest);
        double amount = principal + SimpleInterest;
        System.out.println("Amount = " + amount);
        System.out.println();

    }

}
