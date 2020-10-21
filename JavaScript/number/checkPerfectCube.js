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
// this will check if the input number is a perfect cube or not
const checkPerfectSquare = (num) =>{
    // first, check if the input is a number, if not then return 'not a number'
    if(typeof num !== 'number'){
        return 'not a number'
    }
    // in this function we use the Math.cbrt() to get the cube root of num
    //and then we get its rounded value using Math.round()
    // to complete the comparison we use strict equal operator to compare the non-rounded to the rounded cube root  
    // after the comparison if the two values are equal we return true and if not we return false 
    return Math.cbrt(num) === Math.round(Math.cbrt(num));
} 
console.log(checkPerfectSquare(2197));
console.log(checkPerfectSquare(2));
console.log(checkPerfectSquare(8));
console.log(checkPerfectSquare(-8));