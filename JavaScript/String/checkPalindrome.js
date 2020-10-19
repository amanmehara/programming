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
const CheckPalindrome = (str) => {
  //this will check if the input is a string or not
  //if not we'll just return 'Not a number'
  if (typeof str !== "string") {
    return "Not a String";
  }
  //if the input is string we're gonna do this algorithm
  //we check if the string is empty or not
  //if the string is empty we're just gonna return 'empty string'
  if (str.length === 0) {
    return "Empty String";
  }
  //if the string is not an empty string we're gonna do this algorithm
  //set the value of the input string to new variable
  let strCopy = str;
  //we split the string into substring and turn them into array using .split method
  let strCopyArr = strCopy.split("");
  //then we reverse the elements of the strArr using .reverse method
  let strCopyArrRev = strCopyArr.reverse();
  //we concatenate value of the reverseArr using the .join method to make it string again
  let reverseStr = strCopyArrRev.join("");
  //and lastly, we use ternary operation for us to know if the reverseStr is equal to str
  //if they are equal we return true(palindrome), if not we return false(not a palindrome)
  return reverseStr === str ? true : false;
};
console.log(CheckPalindrome("hello world"));
console.log(CheckPalindrome("lol"));
