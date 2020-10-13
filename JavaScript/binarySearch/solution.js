function binarySearch(array, target){
    let startIndex = 0
    let endIndex = array.length - 1

    while(startIndex <= endIndex){
        const middleIndex = Math.floor((startIndex + endIndex) / 2)

        if(array[middleIndex] === target){
            return middleIndex
        } else if(target < array[middleIndex]){
            endIndex = middleIndex
        } else if(target > array[middleIndex]){
            startIndex = middleIndex
        }
    }
}

let array = [1,2,3,4,5,6,7]
console.log(binarySearch(array, 8))