// Copyright 2020 Nayeem Rafsan
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

import java.util.Arrays;
// this is for max heap to sort array in non decreasing order
class HeapSort {
  public static void main(String[] args) {
    int a[] ={8,9,2,5,6,1};
    heapSort(a); // O(nlogn)
    System.out.println(Arrays.toString(a));
  }
  static void heapSort(int a[]) 
    { 
        int n = a.length; 
  
        // Create a heap from array: O(n) 
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(a, n, i);  // our heap: {9,8,2,5,6,1}
        }
        // technique for heap sort:
        // take last element and swap it with first element
        // then do heapify for first element
        for (int i=n-1; i>0; i--) 
        { 
            int temp = a[0]; 
            a[0] = a[i]; 
            a[i] = temp; 
            heapify(a, i, 0); 
        } 
    } 
    // heapify or sink 
    static void heapify(int a[], int n, int parent) 
    { 
        int largest = parent; // currently this is the largest 
        int left_child = 2*parent + 1; // left child = 2*i + 1 
        int right_child = 2*parent + 2; // right child= 2*i + 2 
  
        // If left child is larger than parent
        if (left_child < n && a[left_child] > a[largest]) 
            largest = left_child; 
  
        // If right child is larger than largest so far 
        if (right_child < n && a[right_child] > a[largest]) 
            largest = right_child; 
  
        // If largest is not parent then we swap
        if (largest != parent) 
        { 
            int swap = a[parent]; 
            a[parent] = a[largest]; 
            a[largest] = swap; 
  
            // Recursively call the heapify function 
            heapify(a, n, largest); 
        } 
    } 
}