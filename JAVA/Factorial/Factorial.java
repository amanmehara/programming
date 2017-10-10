import java.math.BigInteger;

public class Factorial {

    public BigInteger factorial(Integer number) {
        return factorial(number, BigInteger.ONE);
    }

    private BigInteger factorial(Integer number, BigInteger accumulator) {
        return number > 0 ? factorial(number - 1, accumulator.multiply(BigInteger.valueOf(number))) : accumulator;
    }

}