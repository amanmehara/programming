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
const ReverseWord = (str) => {
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
  //we split the string into substring and turn them into array using .split method
  const strArr = str.split("");
  //then we reverse the elements of the strArr using .reverse method
  const reverseArr = strArr.reverse();
  //and lastly we return the concatenated value of the reverseArr using the .join method to make it string again
  return reverseArr.join("");
};
console.log(ReverseWord("koddi"));
