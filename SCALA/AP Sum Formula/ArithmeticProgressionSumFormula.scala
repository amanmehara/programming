object ArithmeticProgressionSumFormula {

  def arithmeticProgressionSumFormula(terms: Int): (Double, Double) => BigDecimal = {
    (firstTerm, commonDifference) => {
      terms / BigDecimal(2) * (2 * BigDecimal(firstTerm) + (terms - 1) * BigDecimal(commonDifference))
    }
  }

}