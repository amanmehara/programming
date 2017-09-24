/**
  * Created by @amanmehara on 24-09-2017.
  */
object GeometricProgression {

  def geometricProgression (terms: Int): (Double, Double) => Option[List[BigDecimal]] = {
    (firstTerm, commonRatio) => {
      commonRatio match {
        case 0 => None
        case _ => Option((1 to terms).map(term => firstTerm * BigDecimal(commonRatio).pow(term - 1)).toList)
      }
    }
  }

}
