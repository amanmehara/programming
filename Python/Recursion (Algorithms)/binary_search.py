'''
Copyright 2020 Bryan
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

# A recursive implementation of Binary Search that prints true or false if an item has been found.
# If you are new to algorithms, read up here: https://www.khanacademy.org/computing/computer-science/algorithms
def recursive_binary_search(target, the_values, first, last):
    # If the sequence of values cannot be subdivided further,
    # we are done
    if first > last: # Base Case
        return False
    else: # Recursive Case
        # Find the midpoint of the sequence
        mid = (first + last) // 2
        
        # Does the element at the midpoint contain the target?
        if the_values[mid] == target:
            return True # BASE CASE #2
        
        # or does the target precede the element at the midpoint?
        elif target < the_values[mid]:
            return recursive_binary_search(target, the_values, first, mid - 1)

        # or does the target follows the element at the midpoint?
        else:
            return recursive_binary_search(target, the_values, mid + 1, last)


if __name__ == "__main__":
    # sample sequence
    sequence = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    
    # returns a boolean (true or false) that indicates if a number has been found in the sequence.
    number_found = recursive_binary_search(1, seq, 0, len(seq) - 1)
    
    print(number_found)