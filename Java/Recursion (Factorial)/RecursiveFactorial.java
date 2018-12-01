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

import java.math.BigInteger;

/*

 The factorial n! is defined for a positive integer n as:
 n!=n(n-1)...2·1.

 The value of 0! is 1, according to the convention for an empty product.

 */

public class RecursiveFactorial {

    public BigInteger factorial(Integer number) {
        return factorial(number, BigInteger.ONE);
    }

    private BigInteger factorial(Integer number, BigInteger accumulator) {
        return number > 0 ? factorial(number - 1, accumulator.multiply(BigInteger.valueOf(number))) : accumulator;
    }

}