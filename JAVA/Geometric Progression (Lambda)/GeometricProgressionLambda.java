import java.util.List;
import java.util.function.BiFunction;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

/**
 * Created by @amanmehara on 24-09-2017.
 */
public class GeometricProgressionLambda {

    public static final Function<Integer,BiFunction<Long,Long,List<Integer>>> GEOMETRIC_PROGRESSION
            = terms -> (firstTerm, commonRatio) -> IntStream
            .range(0,terms)
            .boxed()
            .map(operand -> firstTerm * Math.pow(commonRatio , operand))
            .map(Double::intValue)
            .collect(Collectors.toList());

}