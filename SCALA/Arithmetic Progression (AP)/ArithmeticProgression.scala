object ArithmeticProgression {

  def arithmeticProgression(terms: Int): (Double, Double) => List[BigDecimal] = {
    (firstTerm, commonDifference) => {
      (1 to terms).map(term => firstTerm + (term - 1) * BigDecimal(commonDifference)).toList
    }
  }

}