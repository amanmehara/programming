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

class Queue {

	struct Node {
		int data;
		Node *next;
	};

	Node *head_;
	Node *tail_;
	int size_;

public:

	Queue() {
		tail_ = NULL;
		head_ = tail_;
		size_ = 0;
	}

	void Enqueue(int data) {

		Node *current = new Node();
		current->data = data;

		if (size_ == 0) {
			tail_ = current;
			head_ = tail_;
		}
		else {
			tail_->next = current;
			tail_ = current;
		}

		size_++;

	}

	int Dequeue() {

		if (size_ == 0) {
			throw underflow_error("Queue is already empty.");
		}

		Node *current = head_;
		head_ = head_->next;
		int data = current->data;
		delete(current);
		size_--;

		if (size_ == 0) {
			tail_ = NULL;
		}

		return data;

	}

	bool IsEmpty() {
		return size_ == 0;
	}

	int Size() {
		return size_;
	}

};