/*
Copyright 2020 Marin Kovac
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
 */

/*
QuickSort functioning:
1. Find pivot
2. Start left pointer at first element
3. Start right pointer at last element
4. Compare element[left pointer] and if less than pivot, left pointer++. Continue this until element[left pointer] is greater or equal to pivot
5. Compare element[right pointer] and if greater than pivot, right pointer--. Continue this until element[right pointer] is less or equal to pivot
6. Check if left pointer is less or equal to right pointer, then swap the elements in locations of these pointers
7. Left pointer++ and Right pointer--
8. If left pointer is still less than right pointer, repeat the loop block, else return left pointer
*/

function swap(items, left, right){    // defines swap function
    let temp = items[left]            //stores left to temporary
    items[left] = items[right]        //sets left to right value
    items[right] = temp               //sets right to left value (temporary)
}

function partition(items, left, right) {               // defines partition function
    let pivot = items[Math.floor((right + left) / 2)]  // gets middle element
    let i = left                                       //left pointer
    let j = right                                      //right pointer
    while (i <= j) {                                   //loops while left pointer is less or equal to right
        while (items[i] < pivot) {                     //goes for all element[left pointer] less than pivot
            i++                                        //increments left pointer
        }
        while (items[j] > pivot) {                     //goes for all element[right pointer] greater than pivot
            j--                                        //decrement right pointer
        }
        if (i <= j) {                                  //check if left pointer is less or equal to right pointer
            swap(items, i, j)                          //swaps two values
            i++                                        //increments left pointer
            j--                                        //decrement right pointer
        }
    }
    return i                                           //return left pointer
}

function quickSort(items, left = 0, right = items.length - 1) {  //defines main function of quicksort
    let index                                                    // defines index
    if (items.length > 1) {                                      //checks if array is bigger than 1, else just return array
        index = partition(items, left, right)                    //index returned from partition func (left pointer)
        if (left < index - 1) {                                  //checks if more elements are on left side of pivot
            quickSort(items, left, index - 1)                    //recursion
        }
        if (index < right) {                                     //checks if more elements are on right side of pivot
            quickSort(items, index, right)                       //recursion
        }
    }
    return items                                                 //returns sorted array
}

// Usage: quickSort([1, 3, -2, 7, 8, 4, 5, -1])

// Input: [1, 3, -2, 7, 8, 4, 5, -1]
// Output: [-2, -1, 1, 3, 4, 5, 7, 8]