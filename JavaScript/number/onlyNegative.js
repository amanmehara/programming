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
//this function will return only the negative numbers in an array
const onlyNegative = (array) => {
  // first, check if the input is an array, if not then return 'not an array'
  if (!Array.isArray(array)) {
    return "not an array";
  }
  //create an array where we will put all the negative number of input array
  let onlyNegative = [];
  //iterate the elements of array using .forEach() method
  array.forEach((el, index) => {
    // check if the type of element is number and is less than 0
    if (typeof el === "number" && el < 0) {
      // if the element satisfies the condition push it the the array that we created
      onlyNegative.push(array[index]);
    }
  });
  // return the onlyPositive array where we allocate all the negative numbers in input array
  return onlyNegative;
};

console.log(onlyNegative(["koddi", "angelo", -5, -10, 1, 2, 3, 4]));
