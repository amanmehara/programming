object GeometricProgressionSum {

  def geometricProgressionSum(terms: Int): (Double, Double) => Option[BigDecimal] = {
    (firstTerm, commonRatio) => {
      geometricProgression(terms)(firstTerm, commonRatio) match {
        case Some(s) => Option(s.sum)
        case None => None
      }
    }
  }

  def geometricProgression(terms: Int): (Double, Double) => Option[List[BigDecimal]] = {
    (firstTerm, commonRatio) => {
      commonRatio match {
        case 0 => None
        case _ => Option((1 to terms).map(term => firstTerm * BigDecimal(commonRatio).pow(term - 1)).toList)
      }
    }
  }

}