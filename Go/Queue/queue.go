/*Copyright 2020 Dzmitri Lituyev
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

// Code for queue used linked list in Go
package main

import "fmt"

type Node struct {
	value int
	next  *Node
}

type Queue struct {
	head *Node
	tail *Node
	size int
}

func (q *Queue) Size() int {
	return q.size
}

func (q *Queue) IsEmpty() bool {
	return q.size == 0
}

func (q *Queue) Peek() (int, bool) {
	if q.IsEmpty() {
		fmt.Println("QueueEmptyError")
		return 0, false
	}
	return q.head.value, true
}

func (q *Queue) Print() {
	temp := q.head
	for temp != nil {
		fmt.Println(temp.value, " ")
		temp = temp.next
	}
}

func (q *Queue) Add(value int) {
	temp := &Node{
		value: value,
	}

	if q.head == nil {
		q.head = temp
		q.tail = temp
	} else {
		q.tail.next = temp
		q.tail = temp
	}
	q.size++
}

func (q *Queue) Remove() (int, bool) {
	if q.IsEmpty() {
		fmt.Println("QueueEmptyError")
		return 0, false
	}

	value := q.head.value
	q.head = q.head.next
	q.size--
	return value, true
}

func main() {

	var queue Queue

	queue.Add(1)
	queue.Add(2)
	queue.Add(3)
	queue.Print()
	fmt.Println(" size: ", queue.size)

	queue.Remove()
	queue.Print()
	fmt.Println(" size: ", queue.size)
}
