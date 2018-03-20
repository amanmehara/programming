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
object GeometricProgression {

  def geometricProgression(terms: Int): (Double, Double) => Option[List[BigDecimal]] = {
    (firstTerm, commonRatio) => {
      commonRatio match {
        case 0 => None
        case _ => Option((1 to terms).map(term => firstTerm * BigDecimal(commonRatio).pow(term - 1)).toList)
      }
    }
  }

}