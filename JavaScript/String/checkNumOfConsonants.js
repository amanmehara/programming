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
//this function will return the number of consonants in your string
 const checkNumOfConsonants = (string) => {
     //firts check if the input value is string
     if(typeof string === 'string'){
     // next create a regex(regular expression) that says everthing except aeiou,spaces,digits and expresions
     // we also use global and ignore case flag 
     let regEx = /[^aeiou\s\W\d]/gi;
     // then we return the length of matched letter which is vowels using str.match(regex)
     return string.match(regEx).length;
    }
    // if the input value is not a string return this
    return "not a string";
 }

 console.log(checkNumOfConsonants("heLl!!!!!o world"));
 console.log(checkNumOfConsonants("heLl!!!!!o world12345"));
 console.log(checkNumOfConsonants("heLlo world"));
 console.log(checkNumOfConsonants(null));
 console.log(checkNumOfConsonants(100));