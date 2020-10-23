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
// this algorithm will do a number factorial
const factorial = (num) => {
    //since factorial can't perform in any other data types except number , let us check if the inputed value has data type of number.
    //if number lets check if it is greater than zero because factorial can't perform in negative numbers also
    //if the inputed value is either negative number or other data type we're just gonna return an error message
    if(typeof num !== 'number' || num < 0){
        return `sorry we can't do factorial in ${num}`;
    }
    // if inputed value is greater than or equal to zero we're gonna proceed here
    // first create a variable for product and initialize the valueas equal to 1
    let product = 1;
    // if num is truthy means its greather than zero we're gonno execute this recursize if statement
    if(num){
        product = num*factorial(num-1)
    }
    //if not, we're just gonna return the product and not execute the recursive if statement
    //this will return the product(factorial of num)
    return product
}
console.log(factorial(-10));
console.log(factorial(1));
console.log(factorial(10));
console.log(factorial('hello world'));