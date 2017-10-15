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

public class InsertionSort {

    public Integer[] sort(Integer[] array, boolean optimize) {
        return optimize ? optimizedSort(array) : sort(array);
    }

    private Integer[] sort(Integer[] array) {
        int i = 1;
        while (i < array.length) {
            int j = i;
            while (j > 0 && array[j - 1] > array[j]) {

                // Swap (array[j - 1], array[j])
                int temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;

                j = j - 1;
            }
            i = i + 1;
        }
        return array;
    }

    private Integer[] optimizedSort(Integer[] array) {
        int i = 1;
        while (i < array.length) {
            int x = array[i];
            int j = i - 1;
            while (j >= 0 && array[j] > x) {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = x;
            i = i + 1;
        }
        return array;
    }

}