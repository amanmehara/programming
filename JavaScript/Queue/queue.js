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

let Queue = function () {

    let collection = [];

    // prints the queue
    this.print = function(){
        console.log(collection)
    }

    // pushes an item to the queue
    this.enqueue = function(element){
        collection.push(element);
    }

    // remove an item from the queue, in queue the first item is removed ie in FIFO
    this.dequeue = function(){
        collection.shift(); // shift method removes the first item of an array
    }

    // returning the size of the queue
    this.size = function(){
        return collection.length
    }

    //printing the first item of the queue
    this.front = function(){
        return collection[0];
    }

    // checking if the queue is empty or not
    this.isEmpty = function(){
        return (collection.length === 0)
    }
}


// Running the program

let q = new Queue();

// Adding an element to the tail of the queue
q.enqueue("a");
q.enqueue("b");
q.enqueue("c");

q.print();

// Removing an element from the queue
q.dequeue();

console.log(q.front());

q.print();
