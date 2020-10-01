// Copyright 2020 Rajdeep Chandra
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


var Stack = function() {
    this.count = 0;
    this.storage = {};


    // creating a function to add a value to the stack

    this.push = function(value) {
        this.storage[this.count] = value;
        this.count++;
    }


    // creating a function to remove a value from the stack

    this.pop = function(){
        if(this.count === 0){
            return undefined
        }

        this.count-- ;
        var result = this.storage[this.count];
        delete this.storage[this.count];
        return result;
    }

    // creating a function to know the vlaue of items in the stack

    this.size = function() {
        return this.count;
    }


    // creating a function to see the last element in the stack

    this.peek = function(){
        return this.storage[this.count - 1]
    }


}


var newStack = new Stack();


newStack.push(1);
newStack.push(2);

console.log(newStack.peek());

console.log(newStack.pop());

console.log(newStack.peek());
