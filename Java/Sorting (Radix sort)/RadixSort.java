/*
 * Copyright 2020 Sanjana Pedada
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import java.util.*;

public class RadixSort {

    /**
     * Function to sort the arr[] list of length n using radix sort. Radix sort is
     * to do digit by digit sort starting from least significant digit to most
     * significant digit using counting sort as a subroutine to sort.
     * 
     * @param arr The array list that is to be sorted
     * @param a   The length of the array
     */
    private static void radixsort(int arr[], int a) {
        int max = arr[0];
        for (int i = 0; i < a; i++) {
            if (arr[i] > max)
                max = arr[i];
        }

        for (int j = 1; max / j > 0; j *= 10)
            countSort(arr, a, j);
    }

    /**
     * Sorts the elements of arr[] according to the digit represented by j
     * 
     * @param arr The array list
     * @param a   The length of the array
     * @param j   10^i where i is the current digit number
     */
    private static void countSort(int arr[], int a, int j) {
        int result[] = new int[a];
        int i;
        int count[] = new int[10];
        Arrays.fill(count, 0);

        for (i = 0; i < a; i++)
            count[(arr[i] / j) % 10]++;

        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (i = a - 1; i >= 0; i--) {
            result[count[(arr[i] / j) % 10] - 1] = arr[i];
            count[(arr[i] / j) % 10]--;
        }

        for (i = 0; i < a; i++)
            arr[i] = result[i];
    }

    public static void main(String[] args) {
        int arr[] = { 20, 399, 70, 9, 78, 80, 32, 500, 499 };
        int a = arr.length;
        System.out.println("Testing Radix Sort");
        System.out.println("Before Sort: " + Arrays.toString(arr));
        radixsort(arr, a);
        System.out.println("After Sort: " + Arrays.toString(arr));
    }
}


