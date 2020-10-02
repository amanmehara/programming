'''
Copyright [2020] [Anoop Bhat]
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

def quick_sort(sequence):

    lenght = len(sequence)
    if lenght <= 1:
        return sequence
    else:
        pivot = sequence.pop()

    items_lower = []
    items_larger = []

    for item in sequence:
        if item < pivot:
            items_lower.append(item)
        else:
            items_larger.append(item)

    
    return quick_sort(items_lower) + [pivot] + quick_sort(items_larger)

print(quick_sort([5,4,2,1,7,9,3,1]))


