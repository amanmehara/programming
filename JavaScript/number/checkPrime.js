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
// this function will check if the number is a prime number or not
// WHAT IS PRIME NUMBER? An integer greater than one is called a prime number if its only positive divisors (factors) are one and itself. 
const CheckPrime = (num) => {
  // first, check if the input is a number, if not then return 'not a number'
  if (typeof num !== "number") {
    return "Not a Number";
  }
  // remove the numbers 1 and below because they can't be prime
  // and remove all the even number except 2 because 2 is the only even number and is a prime.
  if(num < 2 || num % 2 == 0 && num !== 2){
    return "not a prime";
  }
  //get the nearest and greatest whole number of the squareroot of num and asign it to squareRootOfNum
  let squareRootOfNum = Math.ceil(Math.sqrt(num));
  /* make a for loop that extends until the squareRootOfNum
   to check if the num is divisible by any other odd number that is less than or equal to squareRootOfNum */
  for(let divisor = 3; divisor <= squareRootOfNum; divisor += 2){
    //if it is divisible this means its not a prime and we return 'not a prime'
    if(num % divisor == 0){
      return "not a prime";
    }
  }
  //if the looping ends this mean than the num is a prime so we return 'prime'
  return "prime";
};
console.log(CheckPrime(1049));
