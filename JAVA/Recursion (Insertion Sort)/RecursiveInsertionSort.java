/*

 Copyright 2017 Aman Mehara

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

public class RecursiveInsertionSort {

    public Integer[] sort(Integer[] array, boolean optimize) {
        return optimize ? optimizedSort(array, array.length - 1) : sort(array, array.length - 1);
    }

    private Integer[] sort(Integer[] array, int n) {
        if (n > 0) {

            // recursion
            sort(array, n - 1);

            int j = n;
            while (j > 0 && array[j - 1] > array[j]) {

                // Swap (array[j - 1], array[j])
                int temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;

                j = j - 1;
            }
        }
        return array;
    }

    private Integer[] optimizedSort(Integer[] array, int n) {
        if (n > 0) {

            // recursion
            optimizedSort(array, n - 1);

            int x = array[n];
            int j = n - 1;
            while (j >= 0 && array[j] > x) {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = x;
        }
        return array;
    }

}