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

#include <stdexcept>

using namespace std;

class MinPriorityQueue {

	struct Node {
		int priority;
		Node *next;
		Node *previous;
	};

	Node *head_;
	Node *tail_;
	int size_;

public:

	MinPriorityQueue() {
		tail_ = NULL;
		head_ = tail_;
		size_ = 0;
	}

	void Insert(int priority) {

		Node *current = new Node();
		current->priority = priority;

		if (size_ == 0) {
			tail_ = current;
			head_ = tail_;
		}
		else {
			tail_->next = current;
			current->previous = tail_;
			tail_ = current;
		}

		size_++;

	}

	int ExtractMinimum() {

		if (size_ == 0) {
			throw underflow_error("Min-Priority Queue is already empty.");
		}

		Node *current = head_;
		Node *minimum = current;
		while (current != NULL) {
			if (current->priority < minimum->priority) {
				minimum = current;
			}
			current = current->next;
		}

		if (minimum->previous != NULL) {
			minimum->previous->next = minimum->next;
		}
		else {
			head_ = minimum->next;
		}

		if (minimum->next != NULL) {
			minimum->next->previous = minimum->previous;
		}
		else {
			tail_ = minimum->previous;
		}

		int priority = minimum->priority;
		delete(minimum);
		size_;

		return priority;

	}

	int Minimum() {

		if (size_ == 0) {
			throw underflow_error("Min-Priority Queue is already empty.");
		}

		Node *current = head_;
		Node *minimum = current;
		while (current != NULL) {
			if (current->priority < minimum->priority) {
				minimum = current;
			}
			current = current->next;
		}

		return minimum->priority;

	}

	void DecreasePriority(int position, int priority) {

		if (size_ <= position) {
			throw out_of_range("Out of Range.");
		}

		Node *current = head_;
		int index = 0;
		while (index < position) {
			current = current->next;
			index++;
		}

		if (current->priority < priority) {
			throw invalid_argument("New priority cannot be more than existing priority.");
		}

		current->priority = priority;

	}

};