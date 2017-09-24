/**
  * Created by @amanmehara on 24-09-2017.
  */
object GeometricProgressionSumFormula {

  def geometricProgressionSumFormula (terms: Int): (Double, Double) => Option[BigDecimal] = {
    (firstTerm, commonRatio) => {
      commonRatio match {
        case 0 => None
        case 1 => Option(terms * firstTerm)
        case _ => Option(firstTerm * (1 - BigDecimal(commonRatio).pow(terms))./(1 - BigDecimal(commonRatio)))
      }
    }
  }

}
