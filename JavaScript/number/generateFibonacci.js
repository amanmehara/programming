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
const generateFibonacci = (num) => {
  // first, check if the input is a number, if not then return 'not a number'
  if (typeof num !== "number") {
    return "Not a Number";
  }
  //then check if the num is truthy
  if (num) {
    //make an array. this will be the container of our fibonacci number
    /* initialize its index value to 1, beacause if the inserted num is 1
    we're just just gonna return this array */
    let fibArray = [1];
    let a = 1,
      b,
      sum;
    //if the inserted num is greater than 1 proceed to this for loop that extends until the i reaches the num
    for (let i = 1; i < num; i++) {
      //to get the second value of fibonacci series which is also 1
      if (i === 1) {
        fibArray.push(i);
        b = i;
      }
      /* the formula of fibonacci is An + An-1
      so the idea in this algorithm is first get the sum of a and b
      then set the value of b to the value of a and the value of a to the value of sum
      then pushing the value of sum to the fibArray */
      else {
        sum = a + b;
        b = a;
        a = sum;
        fibArray.push(sum);
      }
    }
    //if the length of fibArray is equal to inserted num we just return the fibArray
    return fibArray;
  }
  //if the inserted num is falsy we're just gonna return undefined
  return undefined;
};
console.log(generateFibonacci(20));
