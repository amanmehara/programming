/**
  * Created by @amanmehara on 24-09-2017.
  */
object ArithmeticProgressionSum {

  def arithmeticProgressionSum (terms: Int): (Double, Double) => BigDecimal = {
    (firstTerm, commonDifference) => {
      arithmeticProgression(terms)(firstTerm,commonDifference).sum
    }
  }

  def arithmeticProgression (terms: Int): (Double, Double) => List[BigDecimal] = {
    (firstTerm, commonDifference) => {
      (1 to terms).map(term => firstTerm + (term - 1) * BigDecimal(commonDifference)).toList
    }
  }

}
