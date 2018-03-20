/*
 * Copyright 2018 Aman Mehara
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
object GeometricProgressionSumFormula {

  def geometricProgressionSumFormula(terms: Int): (Double, Double) => Option[BigDecimal] = {
    (firstTerm, commonRatio) => {
      commonRatio match {
        case 0 => None
        case 1 => Option(terms * firstTerm)
        case _ => Option(firstTerm * (1 - BigDecimal(commonRatio).pow(terms))./(1 - BigDecimal(commonRatio)))
      }
    }
  }

}