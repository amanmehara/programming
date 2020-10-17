'''
Copyright 2020 hyouka266@gmail.com
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
'''

def bubble_sort(array):
    """ Read more about bubble sort here https://www.geeksforgeeks.org/bubble-sort/
    >>> bubble_sort([3,2,1])
    [1, 2, 3]
    """
    length = len(array) # length of array
    for i in range(length - 1):
        for j in range(length - i - 1):
            if array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j] # swap two numbers
    return array

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    array = [100, 67, 3, 56, 23, 86, 13, 64, 890]
    sorted_array = bubble_sort(array)
    print(sorted_array)
