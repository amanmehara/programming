/*

 Copyright 2017 Aman Mehara

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.

 */

object GeometricProgressionInfiniteSumFormula {

  def geometricProgressionInfiniteSumFormula(firstTerm: Double, commonRatio: Double): Option[BigDecimal] = {
    commonRatio match {
      case x if x > -1 && x < 1 && x != 0 => Option(BigDecimal(firstTerm)./(1 - BigDecimal(commonRatio)))
      case _ => None
    }
  }

}