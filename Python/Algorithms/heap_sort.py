'''
Copyright [2020] [Timothy Chua]
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


def find_maximum(my_heap): #A function to find the maximum in a given list and returns the index of the element and the element.

  maximum = my_heap[0]
  maximum_idx = 0
  for a in range(1, len(my_heap)):
    if(my_heap[a] > maximum):
      maximum = my_heap[a]
      maximum_idx = a

  return maximum, maximum_idx


def max_heapify(my_heap, n, root_index):

  left_index = root_index*2+1
  right_index = root_index*2+2


  if((root_index*2)+2 < n): #There exists a right child
    maximum, maximum_idx = find_maximum([my_heap[root_index], my_heap[left_index], my_heap[right_index]])
  else: #No right child
    maximum, maximum_idx = find_maximum([my_heap[root_index], my_heap[left_index]])

  if(my_heap[root_index] != maximum):
    if(maximum_idx == 1): #Left child has maximum value
      maximum_idx = left_index #The maximum index is assigned the left index

    elif(maximum_idx == 2): #Right child has maximum value
      maximum_idx = right_index #The maximum index is assigned the right index

    #We swap the values of the maximum value and the root
    placeholder = my_heap[root_index]
    my_heap[root_index] = my_heap[maximum_idx]
    my_heap[maximum_idx] = placeholder

    if(maximum_idx < (n//2)-1): #This means it is its own subtree
      max_heapify(my_heap, n, maximum_idx)


  return my_heap


def build_heap_tree(my_heap, n, i):

  bottom_sub_tree = (n//2)-1
  while(bottom_sub_tree >= 0): #We iterate through all of the parent nodes given by the formula in the previous line.

    max_heapify(my_heap, n, bottom_sub_tree)
    bottom_sub_tree -= 1

  return my_heap




if __name__ == "__main__":

  #For a heap sort algorithm, we will treat this array as a max-heap tree.
  #if the index of an element is i then its children will be 2i+1 for the left child and 2i+2 for the right child.
  #The parent of that index is lowerbound (i-1)/2
  input = [1, 12, 9, 5, 6, 10]
  a = 0
  heapified_list = input.copy()
  sorted_list = []

  while(a < len(input)):
    heapified_list = build_heap_tree(heapified_list, len(heapified_list), 0)
    #Now the sorted_list contains the tree which satisfies Max-Heap property

    placeholder = heapified_list[-1]
    heapified_list[-1] = heapified_list[0]
    heapified_list[0] = placeholder
    sorted_list.insert(0, heapified_list.pop())
    a += 1

  print("Answer:", sorted_list)
