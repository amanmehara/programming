// create a stack function with javascript to understand how stack works


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