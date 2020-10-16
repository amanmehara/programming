'''Copyright [2020] [Aakash Deep]

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.'''


# Program to implement merge sort algorithm in Python3 language.
l=[4,5,9,8,7,6,2,3]

''' Function which performs merge sort recursively by calling itself
 again and again, dividing the list in half everytime it calls itself
 until the base case arises which is when the length of list becomes 1.
 And then merge the lists back together in sorted form'''

def merge_sort(l,s,e):
	if s==e:
		return [l[s]]
	m=(e+s)//2
	p1=merge_sort(l,s,m)
	p2=merge_sort(l,m+1,e)
	return merge(p1,p2)

# "merge" function performs the main action of merging together the elements of two list together in sorted order.

def merge(p1,p2):
	i=0
	j=0
	sorted_list=[]

	while i < len(p1) and j < len(p2):
		if p1[i]<=p2[j]:
			sorted_list.append(p1[i])
			i+=1
		elif p1[i]>p2[j]:
			sorted_list.append(p2[j])
			j+=1
	while i < len(p1):
		sorted_list.append(p1[i])
		i+=1
	while j < len(p2):
		sorted_list.append(p2[j])
		j+=1
	return sorted_list

# Calling the function merge_sort

l=merge_sort(l,0,len(l)-1)
print(l)