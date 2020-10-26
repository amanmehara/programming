'''

Copyright 2020 Puneet Garg

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

def insertion_sort(arr):
    length = len(arr)

    # Traverse through 1 to length of array
    for i in range(1, length):
        j = i-1;

        #Swap elements that are not in right position.
        while (j >= 0) and (arr[j] > arr[j+1]):
            temp = arr[j]
            arr[j] = arr[j+1]
            arr[j+1] = temp
            j-=1


# Driver code to test insertion sort function
arr = [12, 11, 13, 5, 6]
print("Before Sorting :", arr) # Before Sorting : [12, 11, 13, 5, 6]
insertion_sort(arr)
print("After Sorting :", arr) # After Sorting : [5, 6, 11, 12, 13]
