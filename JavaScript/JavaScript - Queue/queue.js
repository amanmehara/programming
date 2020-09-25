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
q.enqueue("a");
q.enqueue("b");
q.enqueue("c");
q.print();
q.dequeue();
console.log(q.front());
q.print();