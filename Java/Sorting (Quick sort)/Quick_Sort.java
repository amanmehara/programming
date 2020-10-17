/*
Copyright 2020 Sakshi Khachane
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

class Quick_Sort
{
    // Conquer
    public static int Parition(int[] array, int left, int right)
    {
        int pivot = array[left];
        int index = right;
        int temp;

        for(int j = right; j > left; j--)
        {
            if(array[j] > pivot)
            {
                temp = array[j];
                array[j] = array[index];
                array[index] = temp;
                index--;
            }
        }

        array[left] = array[index];
        array[index] = pivot;
        return index;
    }

    // Divide array into halves
    public static void Quick(int[] array, int left, int right)
    {
        if(left < right)
        {
            int pivot = Parition(array, left, right);

            Quick(array, left, pivot - 1);
            Quick(array, pivot + 1, right);
        }
    }

    public static void QuickSort(int array[], int size)
    {
        Quick(array, 0, size - 1);
    }

    // function ro print array
    public static void Print_Array(int[] array, int size)
    {
        for(int i = 0; i < size; i++)
            System.out.print(array[i] + " ");

        System.out.println();
    }

    public static void main(String[] args)
    {
        int[] array = {2, 4, 3, 1, 6, 8, 4};
        QuickSort(array, 7);
        Print_Array(array, 7);
    }
}

// Output
// 1 2 3 4 4 6 8
