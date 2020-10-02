/*Copyright 2020 Mahima Goyal

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

// Code for Binary Search in Go

package main

import (
	"fmt"
)

func main() {
	var arr = []int{2, 4, 6, 8, 10, 12, 14, 16, 18, 20}
	fmt.Printf("Array: %v\n", arr)
	var find int
	fmt.Printf("Please enter element to be found: ")
	fmt.Scan(&find)
	result := search(arr, find)
	fmt.Printf("Result: %d", result)
}

func search(list []int, item int) int {
	low := 0
	high := len(list) - 1
	for low <= high {
		middle := (low + high) / 2
		if list[middle] == item {
			return middle
		} else if list[middle] < item {
			low = middle + 1
		} else {
			high = middle - 1
		}
	}
	return -1
}
