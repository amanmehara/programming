/*
 * Copyright 2020 Koddi Evangelista
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
// this function will find the absolute value of a number


// In this Example, we use Math.abs() it is a built-in function of javascript that returns the absolute value of a number
const findAbsolute = (num) => Math.abs(num);
// in this example, we use if-else statement for us to know the absolute value of a number

const findAbsoluteAlgorithm = (num) => {
    // if the inputed value is negative we multiply it to - to make it positive
    if(num<0){
        return -num;
    }
    // else we're just gonna return it
    return num;
}
console.log(findAbsoluteAlgorithm(-10));
console.log(findAbsoluteAlgorithm(10));
console.log(findAbsolute(-10));
console.log(findAbsolute(10));