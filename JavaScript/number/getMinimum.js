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
//this function will get the minimum number in an array
const getMax = (array) => {
  // first, check if the input is an array, if not then return 'not an array'
  if (!Array.isArray(array)) {
    return "not an array";
  }
  let arrCopy = [...array];
  arrCopy.forEach((el, index) => {
    if (typeof el !== "number") {
      arrCopy.splice(index, 1);
    }
  });
  let sortedArray = arrCopy.sort((a, b) => a - b);
  return sortedArray[0];
};
console.log(getMax([2, 3, "koddi", 5, 6, 7, 8, 9, 1]));
