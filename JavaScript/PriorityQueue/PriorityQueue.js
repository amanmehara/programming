class QElement { 
    constructor(priority, element) 
    { 
        this.priority = priority; 
        this.element = element; 
    } 
} 

class PriorityQueue {
    constructor() 
    { 
        this.items = []; 
    } 

    enqueue(priority, element) 
    { 
        var qElement = new QElement(priority, element); 
        var contain = false; 
    
        for (var i = 0; i < this.items.length; i++) { 
            if (this.items[i].priority >= qElement.priority) { 
                this.items.splice(i, 0, qElement); 
                contain = true; 
                break; 
            } 
        } 
    
        if (!contain) { 
            this.items.push(qElement); 
        } 
    }

    
    dequeue() 
    { 
        if (this.isEmpty()) 
            return "Underflow"; 
        return this.items.shift(); 
    } 


    front() 
    { 
        if (this.isEmpty()) 
            return "No elements in Queue"; 
        return this.items[0]; 
    } 

    rear() 
    { 
        if (this.isEmpty()) 
            return "No elements in Queue"; 
        return this.items[this.items.length - 1]; 
    } 

    isEmpty() 
    { 
        return this.items.length === 0; 
    } 

    printPQueue() 
    { 
        var str = ""; 
        for (var i = 0; i < this.items.length; i++) 
            str += this.items[i].element + " "; 
        return str; 
    } 

    includes(element){
        var isIncluded = false;
        for (var i = 0; i < this.items.length; i++) 
            if(String(this.items[i].element) === String(element)) isIncluded = true;
        return isIncluded; 
    }
} 


var pq = new PriorityQueue();


pq.enqueue(1, 4);
pq.enqueue(2, 7);

console.log(pq.front());

console.log(pq.rear());

console.log(pq.printPQueue());
