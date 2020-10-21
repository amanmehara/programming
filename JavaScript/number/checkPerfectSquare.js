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
// this will check if the input number is a perfect square or not
const checkPerfectSquare = (num) =>{
    // first, check if the input is a number, if not then return 'not a number'
    if(typeof num !== 'number'){
        return 'not a number'
    }
    // in this function we use the Math.sqrt() to get the square root of num
    // and then we use Math.pow(base, exponent) to get the base to the exponent(2) of Math.sqrt(num)
    // after that we return if that is equal to num(true) or not(false) 
    return Math.pow(Math.sqrt(num), 2) === num;
} 
console.log(checkPerfectSquare(0));
console.log(checkPerfectSquare(100));
console.log(checkPerfectSquare(6));