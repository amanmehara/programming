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

public class BubbleSort {

    public Integer[] sort(Integer[] array, boolean optimize) {
        return optimize ? optimizedSort(array) : sort(array);
    }

    private Integer[] sort(Integer[] array) {
        boolean isSwapped;
        int n = array.length;
        do {
            isSwapped = false;
            for (int index = 0; index < n - 1; index++) {
                if (array[index] > array[index + 1]) {

                    // Swap (array[index], array[index + 1])
                    int temp = array[index];
                    array[index] = array[index + 1];
                    array[index + 1] = temp;

                    isSwapped = true;
                }
            }
        } while (isSwapped);
        return array;
    }

    private Integer[] optimizedSort(Integer[] array) {
        boolean isSwapped;
        int n = array.length;
        do {
            isSwapped = false;
            for (int index = 0; index < n - 1; index++) {
                if (array[index] > array[index + 1]) {

                    // Swap (array[index], array[index + 1])
                    int temp = array[index];
                    array[index] = array[index + 1];
                    array[index + 1] = temp;

                    isSwapped = true;
                }
            }
            n = n - 1;
        } while (isSwapped);
        return array;
    }

}