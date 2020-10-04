'''
Copyright [2020] [Théo Dumont]
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


# recursive solution of the Tower of Hanoi
# https://en.wikipedia.org/wiki/Tower_of_Hanoi

def tower_of_hanoi(number_of_disks):

    print("Tower of Hanoi \n")
    print("S = Source tower\nI = Intermediate tower\nD = Destination tower\n")
    print(f"Total Disks in Source tower = {number_of_disks}\n")
    print(f"Solution (with minimum number of moves {2 ** number_of_disks - 1}): \n")

    recursive_tower_of_hanoi(number_of_disks, 'S', 'D', 'I')

def recursive_tower_of_hanoi(number_of_disks, source, destination, intermediate):
    if number_of_disks == 1:
        print(f"Disk {number_of_disks} moved from {source} to {destination}")
    else:
        recursive_tower_of_hanoi(number_of_disks - 1, source, intermediate, destination)
        print(f"Disk {number_of_disks} moved from {source} to {destination}")
        recursive_tower_of_hanoi(number_of_disks - 1, intermediate, destination, source)


if __name__ == "__main__":
    number_of_disks = 5
    tower_of_hanoi(number_of_disks)
