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
// this function will reverse an array using Array.reverse()
const reverseArray = (array) => {
  // first, check if the input is an array, if not then return 'not an array'
  if (!Array.isArray(array)) {
    return "not an array";
  }
  //use the .reverse() method a build-in method in javascript that reverses an array
  return array.reverse();
};

// this function will reverse an array using an algorithm
const reverseArrayAlgorithm = (array) => {
  // first, check if the input is an array, if not then return 'not an array'
  if (!Array.isArray(array)) {
    return "not an array";
  }
  //create a new array where we will place the reversed array
  let reverseArr = [];
  //get the length of input array, we will use it to iterating all the elements of array using for-loop
  let length = array.length;
  //create a for-loop that iterates the element of an array starting from the highest index to the lowest
  for (let i = length - 1; i >= 0; i--) {
    // push each element to the new array that we created
    reverseArr.push(array[i]);
  }
  //return the reversed array
  return reverseArr;
};

console.log(reverseArray([4, "koddi", 5, "angelo", 1, 2]));
console.log(reverseArrayAlgorithm([4, "koddi", 5, "angelo", 1, 2]));
