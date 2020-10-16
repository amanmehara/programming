/*Copyright 2020 Denis Lituev
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
package main

import "fmt"

// MergeSort initiates Merge Sort in Go
func MergeSort(arr []int) {
	size := len(arr)
	tempArray := make([]int, size)
	mergeSrt(arr, tempArray, 0, size-1)
}

func mergeSrt(arr []int, tempArray []int, lowerIndex int, upperIndex int) {
	if lowerIndex >= upperIndex {
		return
	}
	middleIndex := (lowerIndex + upperIndex) / 2
	mergeSrt(arr, tempArray, lowerIndex, middleIndex)
	mergeSrt(arr, tempArray, middleIndex+1, upperIndex)
	merge(arr, tempArray, lowerIndex, middleIndex, upperIndex)
}

func merge(arr []int, tempArray []int, lowerIndex int, middleIndex int, upperIndex int) {
	lowerStart := lowerIndex
	lowerStop := middleIndex
	upperStart := middleIndex + 1
	upperStop := upperIndex
	count := lowerIndex
	for lowerStart <= lowerStop && upperStart <= upperStop {
		if !(arr[lowerStart] > arr[upperStart]) {
			tempArray[count] = arr[lowerStart]
			lowerStart++
		} else {
			tempArray[count] = arr[upperStart]
			upperStart++
		}
		count++
	}
	for lowerStart <= lowerStop {
		tempArray[count] = arr[lowerStart]
		count++
		lowerStart++
	}
	for upperStart <= upperStop {
		tempArray[count] = arr[upperStart]
		count++
		upperStart++
	}
	for i := lowerIndex; i <= upperIndex; i++ {
		arr[i] = tempArray[i]
	}
}

func main() {
	data := []int{9, 1, 8, 2, 7, 3, 6, 4, 5}
	MergeSort(data)
	fmt.Println(data)
}
