/**
  * Created by @amanmehara on 24-09-2017.
  */
object GeometricProgressionInfiniteSumFormula {

  def geometricProgressionInfiniteSumFormula (firstTerm: Double, commonRatio: Double) : Option[BigDecimal] = {
    commonRatio match {
      case x if x > -1 && x < 1 && x != 0 => Option(BigDecimal(firstTerm)./(1 - BigDecimal(commonRatio)))
      case _ => None
    }
  }

}
