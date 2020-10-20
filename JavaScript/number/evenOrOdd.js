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
//  this algorithm will check if the number is even or not
const CheckEvenOdd = (num) => {
  //  this will check if the input is a number or not
  if (typeof num !== "number") {
    return "Not a Number";
  }
  //    this will check if the input number is a whole number or not
  if (num !== Math.floor(num)) {
    return "Not a Whole Number";
  }
  //if the input number is a whole number
  //we're gonna use modulo operator to know if the number is even or not
  //modulo operator - arithmetic operator produced the reminder of an integer division
  //if the reminder of num % 2 is equal to zero the number is even else it is odd
  return num % 2 === 0 ? "Even" : "Odd";
};
console.log(CheckEvenOdd(2.2));
console.log(CheckEvenOdd("even"));
console.log(CheckEvenOdd(100));
console.log(CheckEvenOdd(9));
console.log(CheckEvenOdd(0));
