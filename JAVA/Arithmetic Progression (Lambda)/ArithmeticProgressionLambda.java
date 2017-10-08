import java.util.List;
import java.util.function.BiFunction;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class ArithmeticProgressionLambda {

    public static final Function<Integer, BiFunction<Integer, Integer, List<Integer>>> ARITHMETIC_PROGRESSION
            = terms -> (firstTerm, commonDifference) -> IntStream
            .range(0, terms)
            .boxed()
            .map(operand -> firstTerm + operand * commonDifference)
            .collect(Collectors.toList());

}