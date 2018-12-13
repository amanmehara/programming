// Copyright 2018 Aman Mehara
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef MEHARA_LINKED_QUEUE_H_
#define MEHARA_LINKED_QUEUE_H_

#include "queue.h"

#include <stdexcept>

template <class T>
class linked_queue : public queue<T> {
  public:
    linked_queue();

    void enqueue(T element) override;

    T dequeue() override;

    bool empty() override;

    int size() override;

    ~linked_queue() override;

  private:
    struct node {
        T element;
        node* next;
    };

    node* head_;
    node* tail_;
    int size_;
};

template <class T>
linked_queue<T>::linked_queue() {
    tail_ = nullptr;
    head_ = tail_;
    size_ = 0;
}

template <class T>
void linked_queue<T>::enqueue(T element) {
    node* current = new node();
    current->element = element;

    if (size_ == 0) {
        tail_ = current;
        head_ = tail_;
    } else {
        tail_->next = current;
        tail_ = current;
    }

    size_++;
}

template <class T>
T linked_queue<T>::dequeue() {
    if (size_ == 0) {
        throw std::underflow_error("Queue is already empty.");
    }

    node* current = head_;
    head_ = head_->next;
    T element = current->element;
    delete current;
    size_--;

    if (size_ == 0) {
        tail_ = nullptr;
    }

    return element;
}

template <class T>
bool linked_queue<T>::empty() {
    return size_ == 0;
}

template <class T>
int linked_queue<T>::size() {
    return size_;
}

template <class T>
linked_queue<T>::~linked_queue() {
    while (head_) {
        node* current = head_;
        head_ = head_->next;
        delete current;
        size_--;
    }
    tail_ = head_;
}

#endif // MEHARA_LINKED_QUEUE_H_